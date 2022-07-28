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
///   File: function_tree.hpp
///
/// Author: $author$
///   Date: 3/21/2016
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_FUNCTION_TREE_HPP
#define _TEXTA_T_FUNCTION_TREE_HPP

#include "texta/t/function_branch.hpp"
#include "texta/t/function_named.hpp"
#include "xos/base/avl/tree.hpp"

namespace texta {
namespace t {

class _EXPORT_CLASS function_tree;
typedef avl::treet
<function_leaf, function_branch, function_tree,
 avl::tree_implements, binary::treet
 <function_leaf, function_branch, function_tree,
  binary::tree_implements, treet
  <function_leaf, function_branch, function_tree,
   tree_implements, tree_extends> > > function_tree_extends;
///////////////////////////////////////////////////////////////////////
///  Class: function_tree
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS function_tree: public function_tree_extends {
public:
    typedef function_tree_extends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    function_tree() {
    }
    virtual ~function_tree() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual function* find_function(const string& name) const {
        function_named named(name);
        function* f = 0;
        function_branch* b = 0;
        if ((b = this->find(named))) {
            f = &b->leaf();
        }
        return f;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace t 
} // namespace texta 

#endif // _TEXTA_T_FUNCTION_TREE_HPP 
        

