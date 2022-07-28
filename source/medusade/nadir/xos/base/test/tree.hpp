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
#ifndef _XOS_NADIR_XOS_BASE_TEST_TREE_HPP
#define _XOS_NADIR_XOS_BASE_TEST_TREE_HPP

#include "xos/base/getopt/main.hpp"
#include "xos/base/tree.hpp"

namespace xos {
namespace base {
namespace test {
namespace tree {

typedef getopt::main_implements main_implements;
typedef getopt::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: virtual public main_implements, public main_extends {
public:
    typedef main_implements Implements;
    typedef main_extends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    main() {
    }
    virtual ~main() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char* a2z = "ABCDEFGHIJKLMNOPQRTSUVWXYZ";
        xos::base::avl::branch b[26];
        xos::base::avl::tree t;
        size_t i, n;
        for (i = (n = xos::base::chars_t::count(a2z)); i > 0; --i) {
            xos::base::leaf& l = b[n-i].leaf();
            xos::base::leaf::what_t& w = l.what();
            w.assign(a2z + i - 1, 1);
            t.insert(b[n-i]);
        }
        for (xos::base::avl::branch* b = t.first();  b; b = t.next(*b)) {
            out(b->leaf().what().chars());
        }
        outln();
        for (i = (n = xos::base::chars_t::count(a2z)); i > 0; --i) {
            t.remove(b[n-i]);
            for (xos::base::avl::branch* b = t.first();  b; b = t.next(*b)) {
                out(b->leaf().what().chars());
            }
            outln();
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace tree 
} // namespace test 
} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_TEST_TREE_HPP 
