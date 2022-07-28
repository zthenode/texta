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
///   Date: 3/7/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_TREE_HPP
#define _XOS_NADIR_XOS_BASE_TREE_HPP

#include "xos/base/branch.hpp"
#include "xos/base/leaf.hpp"

namespace xos {
namespace base {

class _EXPORT_CLASS tree;
typedef implement_base tree_implements;
typedef base tree_extends;
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
    treet(branch_t *root = 0): root_(root) {
    }
    treet(const treet& copy): root_(0) {
    }
    virtual ~treet() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual branch_t* insert(branch_t& branch) {
        branch_t* b = 0;
        return b;
    }
    virtual branch_t* remove(branch_t& branch) {
        branch_t* b = 0;
        return b;
    }
    virtual branch_t* remove() {
        branch_t* b = root();
        clear();
        return b;
    }
    virtual void clear() {
        root_ = 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual branch_t* find(const leaf_t& leaf) const {
        branch_t* b = 0;
        return b;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual branch_t* next(TBranch& branch) const {
        TBranch* b = 0;
        return b;
    }
    virtual TBranch* prev(TBranch& branch) const {
        TBranch* b = 0;
        return b;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TBranch* first(TBranch& branch) const {
        TBranch* b = 0;
        return b;
    }
    virtual TBranch* last(TBranch& branch) const {
        TBranch* b = 0;
        return b;
    }
    virtual TBranch* first() const {
        TBranch* b = 0;
        if ((b = root())) {
            b = first(*b);
        }
        return b;
    }
    virtual TBranch* last() const {
        TBranch* b = 0;
        if ((b = root())) {
            b = last(*b);
        }
        return b;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TBranch* least(TBranch& branch) const {
        TBranch* b = first(branch);
        return b;
    }
    virtual TBranch* greatest(TBranch& branch) const {
        TBranch* b = last(branch);
        return b;
    }
    virtual TBranch* least() const {
        TBranch* b = first();
        return b;
    }
    virtual TBranch* greatest() const {
        TBranch* b = last();
        return b;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TBranch* set_root(TBranch* to) {
        root_ = to;
        return root_;
    }
    virtual TBranch* root() const {
        return root_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TBranch* root_;
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
    tree(branch *root = 0): Extends(root) {
    }
    tree(const tree& copy): Extends(copy) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

/*namespace binary {
class _EXPORT_CLASS branch;
} //namespace binary
typedef implement_base leaf_implements;
typedef base leaf_extends;
///////////////////////////////////////////////////////////////////////
///  Class: leaft
///////////////////////////////////////////////////////////////////////
template
<typename TWhat = char_t, class TBranch = binary::branch,
 class TImplements = leaf_implements, class TExtends = leaf_extends>

class _EXPORT_CLASS leaft: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TWhat what_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    leaft(const what_t& what): what_(what_) {
    }
    leaft(const leaft& copy): what_(copy.what_) {
    }
    leaft() {
    }
    virtual ~leaft() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const leaft& to) {
        int unequal = compare(to.what_);
        return unequal;
    }
    virtual int compare(const what_t& to) {
        int unequal = 0;
        if (what_ < to) {
            unequal = -1;
        } else {
            if (what_ > to) {
                unequal = 1;
            }
        }
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual what_t& set_what(const what_t& to) {
        what_ = to;
        return what_;
    }
    virtual what_t& what() const {
        return (what_t&)what_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual what_t& operator () () const {
        return (what_t&)what_;
    }
    virtual operator what_t& () const {
        return (what_t&)what_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    what_t what_;
};
typedef leaft<> leaf;

namespace binary {
typedef implement_base branch_implements;
typedef base branch_extends;
///////////////////////////////////////////////////////////////////////
///  Class: brancht
///////////////////////////////////////////////////////////////////////
template
<class TLeaf = leaf, class TBranch = branch,
 class TImplements = branch_implements, class TExtends = branch_extends>

class _EXPORT_CLASS brancht: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TBranch branch_t;
    typedef TLeaf leaf_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    brancht
    (const leaf_t& leaf,
     branch_t* tree = 0, branch_t* left = 0, branch_t* right = 0)
    : tree_(tree), left_(left), right_(right), leaf_(leaf) {
    }
    brancht(const brancht& copy)
    : tree_(0), left_(0), right_(0), leaf_(copy.leaf_) {
    }
    brancht(): tree_(0), left_(0), right_(0) {
    }
    virtual ~brancht() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const branch_t& to) {
        int unequal = leaf_.compare(to.leaf_);
        return unequal;
    }
    virtual int compare(const leaf_t& to) {
        int unequal = leaf_.compare(to);
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual branch_t* set_tree(branch_t* to) {
        tree_ = to;
        return tree_;
    }
    virtual branch_t* tree() const {
        return (branch_t*)tree_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual branch_t* set_left(branch_t* to) {
        left_ = to;
        return left_;
    }
    virtual branch_t* left() const {
        return (branch_t*)left_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual branch_t* set_right(branch_t* to) {
        right_ = to;
        return right_;
    }
    virtual branch_t* right() const {
        return (branch_t*)right_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual leaf_t& set_leaf(const leaf_t& to) {
        leaf_ = to;
        return leaf_;
    }
    virtual leaf_t& leaf() const {
        return (leaf_t&)leaf_;
    }
    virtual operator leaf_t& () const {
        return (leaf_t&)leaf_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    branch_t *tree_, *left_, *right_;
    leaf_t leaf_;
};
///////////////////////////////////////////////////////////////////////
///  Class: branch
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS branch: virtual public branch_implements, public brancht<> {
public:
    typedef branch_implements Implements;
    typedef brancht<> Extends;
};

} // namespace binary*/

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_TREE_HPP 
