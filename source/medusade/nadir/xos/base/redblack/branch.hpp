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
///   File: branch.hpp
///
/// Author: $author$
///   Date: 4/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_REDBLACK_BRANCH_HPP
#define _XOS_NADIR_XOS_BASE_REDBLACK_BRANCH_HPP

#include "xos/base/binary/branch.hpp"

namespace xos {
namespace base {
namespace redblack {

class _EXPORT_CLASS branch;
typedef xos::base::binary::branch_implements branch_implements;
typedef xos::base::binary::brancht
<leaf, branch, branch_implements, xos::base::brancht
<leaf, branch, xos::base::branch_implements, xos::base::branch_extends> > branch_extends;
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
    (const leaf_t& leaf, bool red = false,
     branch_t* tree = 0, branch_t* left = 0, branch_t* right = 0)
    : Extends(leaf, tree, left, right), red_(red) {
    }
    brancht(const brancht& copy)
    : Extends(copy), red_(false) {
    }
    brancht(): red_(false) {
    }
    virtual ~brancht() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_red(bool to = true) {
        red_ = to;
        return red_;
    }
    virtual bool red() const {
        return red_;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    bool red_;
};

typedef brancht
<leaf, branch, branch_implements, branch_extends> branch_extend;
///////////////////////////////////////////////////////////////////////
///  Class: branch
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS branch: public branch_extend {
public:
    typedef branch_extend Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    branch
    (const leaf_t& leaf, bool red = false,
     branch* tree = 0, branch* left = 0, branch* right = 0)
    : Extends(leaf, red, tree, left, right) {}
    branch(const branch& copy): Extends(copy) {}
    branch() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace redblack
} // namespace base 
} // namespace xos 


#endif // _XOS_NADIR_XOS_BASE_REDBLACK_BRANCH_HPP 
        

