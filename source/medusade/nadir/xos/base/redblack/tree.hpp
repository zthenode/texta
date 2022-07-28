///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: tree.hpp
///
/// Author: $author$
///   Date: 4/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_REDBLACK_TREE_HPP
#define _XOS_NADIR_XOS_BASE_REDBLACK_TREE_HPP

#include "xos/base/redblack/branch.hpp"
#include "xos/base/binary/tree.hpp"

#if !defined(XOS_BASE_REDBLACK_TREE_DEBUG)
#define REDBLACK_TREE_LOG_MESSAGE_DEBUG(args)
#else // !defined(XOS_BASE_REDBLACK_TREE_DEBUG)
#define REDBLACK_TREE_LOG_MESSAGE_DEBUG(args) XOS_LOG_MESSAGE_DEBUG(args)
#endif // !defined(XOS_BASE_REDBLACK_TREE_DEBUG)

namespace xos {
namespace base {
namespace redblack {

class _EXPORT_CLASS tree;
typedef xos::base::binary::tree_implements tree_implements;
typedef xos::base::binary::treet
<leaf, branch, tree, tree_implements, xos::base::treet
<leaf, branch, tree, xos::base::tree_implements, xos::base::tree_extends> > tree_extends;
///////////////////////////////////////////////////////////////////////
///  Class: treet
///////////////////////////////////////////////////////////////////////
template
<class TLeaf = leaf, class TBranch = branch, class TTree = tree,
 class TImplements = tree_implements, class TExtends = tree_extends>

class _EXPORT_CLASS treet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TTree Derives;
    typedef TBranch branch_t;
    typedef TLeaf leaf_t;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    treet(branch_t* root = 0): Extends(root) {
    }
    treet(const treet& copy): Extends(copy) {
    }
    virtual ~treet() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual branch_t* insert(branch_t& _branch) {
        TBranch *branch = &_branch, *tree = 0;

        Extends::insert(_branch);
        branch->set_red();

        while ((branch != this->root()) && (red(branch->tree()))) {
            if (branch->tree() == branch->tree()->tree()->left()) {

                tree = branch->tree()->tree()->right();

                if (red(tree)) {
                    tree->set_red(false);
                    branch->tree()->set_red(false);
                    branch->tree()->tree()->set_red();
                    branch = branch->tree()->tree();
                } else {
                    if (branch == branch->tree()->right()) {
                        branch = branch->tree();
                        left(branch);
                    }
                    branch->tree()->set_red(false);
                    branch->tree()->tree()->set_red();
                    right(branch->tree()->tree());
                }
            } else {
                tree = branch->tree()->tree()->left();

                if (red(tree)) {
                    tree->set_red(false);
                    branch->tree()->set_red(false);
                    branch->tree()->tree()->set_red();
                    branch = branch->tree()->tree();
                } else {
                    if (branch == branch->tree()->left()) {
                        branch = branch->tree();
                        right(branch);
                    }
                    branch->tree()->set_red(false);
                    branch->tree()->tree()->set_red();
                    left(branch->tree()->tree());
                }
            }
        }
        this->root()->set_red(false);
        return &_branch;
    }
    virtual branch_t* remove(branch_t& _branch) {
        TBranch *branch = &_branch, *next = 0, *moved = 0, *child = 0;

        if (!branch->left() || !branch->right()) {
            moved = branch;
        } else {
            moved = this->next(*branch);
        }

        if (!(child = moved->left())) {
            child = moved->right();
        }

        if (!moved->tree()) {
            this->set_root(child);
        } else {
            if (moved == moved->tree()->left()) {
                moved->tree()->set_left(child);
            } else {
                moved->tree()->set_right(child);
            }
        }

        if (child) {
            child->set_tree(moved->tree());
        } else {
            child = moved->tree();
        }

        if (moved != branch) {
            if ((next = moved->set_tree(branch->tree()))) {
                if (branch == next->right()) {
                    next->set_right(moved);
                } else {
                    next->set_left(moved);
                }
            }

            if ((next = moved->set_left(branch->left()))) {
                next->set_tree(moved);
            }
            if ((next = moved->set_right(branch->right()))) {
                next->set_tree(moved);
            }
            moved->set_red(branch->red());
        }

        if (child) {
            while ((child != this->root()) && (!child->red())) {
                if (child->tree()->left() == child) {
                    next = child->tree()->right();

                    if (red(next)) {
                        next->set_red(false);
                        child->tree()->set_red();
                        left(child->tree());
                        next = child->tree()->right();
                    }

                    if (!next) {
                        child = child->tree();
                    } else {
                        if ((!red(next->left()))
                             && (!red(next->right()))) {
                            next->set_red();
                            child = child->tree();
                        } else {
                            if (!red(next->right())) {
                                set_red(next->left(),false);
                                next->set_red();
                                right(next);
                                next = child->tree()->right();
                            }
                            next->set_red(child->tree()->red());
                            set_red(next->right(),false);
                            child->tree()->set_red(false);
                            left(child->tree());
                            child = this->root();
                        }
                    }
                } else {
                    next = child->tree()->left();

                    if (red(next)) {
                        next->set_red(false);
                        child->tree()->set_red();
                        right(child->tree());
                        next = child->tree()->left();
                    }

                    if (!next)
                        child = child->tree();
                    else {
                        if ((!red(next->right()))
                             && (!red(next->left()))) {
                            next->set_red();
                            child = child->tree();
                        } else {
                            if (!red(next->left()))
                            {
                                set_red(next->right(),false);
                                next->set_red();
                                left(next);
                                next = child->tree()->left();
                            }
                            next->set_red(child->tree()->red());
                            set_red(next->left(),false);
                            child->tree()->set_red(false);
                            right(child->tree());
                            child = this->root();
                        }
                    }
                }
            }
            child->set_red(false);
        }
        return &_branch;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void left(TBranch *branch) {
        TBranch *rightBranch = branch->right();

        branch->set_right(rightBranch->left());

        if (rightBranch->left()) {
            rightBranch->left()->set_tree(branch);
        }
        rightBranch->set_tree(branch->tree());

        if (!branch->tree()) {
            this->set_root(rightBranch);
        } else {
            if (branch == branch->tree()->left()) {
                branch->tree()->set_left(rightBranch);
            } else {
                branch->tree()->set_right(rightBranch);
            }
        }
        rightBranch->set_left(branch);
        branch->set_tree(rightBranch);
    }
    virtual void right(TBranch *branch) {
        TBranch *leftBranch = branch->left();

        branch->set_left(leftBranch->right());

        if (leftBranch->right()) {
            leftBranch->right()->set_tree(branch);
        }
        leftBranch->set_tree(branch->tree());

        if (!branch->tree()) {
            this->set_root(leftBranch);
        } else {
            if (branch == branch->tree()->right()) {
                branch->tree()->set_right(leftBranch);
            } else {
                branch->tree()->set_left(leftBranch);
            }
        }
        leftBranch->set_right(branch);
        branch->set_tree(leftBranch);
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_red(TBranch *branch, bool to = true) {
        if (branch) {
            return branch->set_red(to);
        }
        return false;
    }
    virtual bool red(TBranch *branch) const {
        if (branch) {
            return branch->red();
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef treet
<leaf, branch, tree, tree_implements, tree_extends> tree_extend;
///////////////////////////////////////////////////////////////////////
///  Class: tree
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS tree: public tree_extend {
public:
    typedef tree_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    tree(branch* root = 0): Extends(root) {
    }
    tree(const tree& copy): Extends(copy) {
    }
    virtual ~tree() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace redblack
} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_REDBLACK_TREE_HPP 
