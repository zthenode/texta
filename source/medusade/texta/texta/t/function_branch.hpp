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
///   File: function_branch.hpp
///
/// Author: $author$
///   Date: 4/14/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_BRANCH_HPP
#define _TEXTA_T_FUNCTION_BRANCH_HPP

#include "texta/t/function.hpp"
//#include "xos/base/avl/branch.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS function_branch;
//typedef function& function_leaf;
typedef function_reference function_leaf;
typedef avl::branch_implements function_branch_implements;
typedef avl::brancht
<function_leaf, function_branch, function_branch_implements,
 binary::brancht
 <function_leaf, function_branch, binary::branch_implements,
  brancht<function_leaf, function_branch,
  branch_implements, branch_extends> > > function_branch_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_branch
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_branch:
virtual public function_branch_implements, public function_branch_extends {
public:
    typedef function_branch_implements Implements;
    typedef function_branch_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_branch(function_leaf f): Extends(f) {
    }
    virtual ~function_branch() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int compare(const leaf_t& to) const {
        int unequal = this->leaf().compare(to);
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t 
} // namespace texta 

#endif // _TEXTA_T_FUNCTION_BRANCH_HPP 
