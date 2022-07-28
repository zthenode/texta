///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
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
///   File: base.hpp
///
/// Author: $author$
///   Date: 5/22/2017
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_XOS_BASE_BASE_HPP
#define _TEXTA_XOS_BASE_BASE_HPP

#include "xos/os/time.hpp"
#include "xos/fs/path.hpp"
#include "xos/io/write/file.hpp"
#include "xos/io/file/writer.hpp"
#include "xos/io/writer.hpp"
#include "xos/io/read/file.hpp"
#include "xos/io/file/reader.hpp"
#include "xos/io/reader.hpp"
#include "xos/base/avl/branch.hpp"
#include "xos/base/avl/tree.hpp"
#include "xos/base/list.hpp"
#include "xos/base/item.hpp"
#include "xos/base/to_string.hpp"
#include "xos/base/string.hpp"
#include "xos/base/types.hpp"
#include "xos/base/base.hpp"
#include <list>

namespace texta {

typedef xos::base::implement_base implement_base;
typedef xos::base::base base;
typedef xos::base::chars_t chars_t;
typedef xos::base::string string;
typedef xos::base::pointer_to_string pointer_to_string;
typedef xos::base::chars_to_string chars_to_string;
typedef xos::base::char_to_string char_to_string;

typedef xos::base::item_implements item_implements;
typedef xos::base::item_extends item_extends;
///////////////////////////////////////////////////////////////////////
///  Class: itemt
///////////////////////////////////////////////////////////////////////
template
<typename TWhat, class TItem,
 class TItemImplements = item_implements,
 class TItemExtends = item_extends,
 class TImplements = TItemImplements,
 class TExtends = xos::base::itemt<TWhat, TItem, TImplements, TItemExtends> >
class _EXPORT_CLASS itemt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TItem Derives;
    typedef TWhat what_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    itemt(const what_t& what, Derives* prev = 0, Derives* next = 0)
    : Extends(what, prev, next) {}
    itemt(const itemt& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef xos::base::list_implements list_implements;
typedef xos::base::list_extends list_extends;
///////////////////////////////////////////////////////////////////////
///  Class: listt
///////////////////////////////////////////////////////////////////////
template
<class TList, class TItem,
 class TListImplements = list_implements,
 class TListExtends = list_extends,
 class TImplements = TListImplements,
 class TExtends = xos::base::listt
 <TList, TItem, TImplements, TListExtends> >
class _EXPORT_CLASS listt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TList Derives;
    typedef TItem Item;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    listt(TItem* first = 0, TItem* last = 0): Extends(first, last) {}
    listt(const listt& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef xos::base::branch_implements branch_implements;
typedef xos::base::branch_extends branch_extends;
///////////////////////////////////////////////////////////////////////
///  Class: brancht
///////////////////////////////////////////////////////////////////////
template
<class TLeaf, class TBranch,
 class TBranchImplements, class TBranchExtends,
 class TImplements = TBranchImplements,
 class TExtends = xos::base::brancht
 <TLeaf, TBranch, TImplements, TBranchExtends> >
class _EXPORT_CLASS brancht: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TBranch branch_t;
    typedef TLeaf leaf_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    brancht(const leaf_t& leaf, branch_t* tree = 0): Extends(leaf, tree) {}
    brancht(const brancht& copy): Extends(copy) {}
    brancht() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef xos::base::tree_implements tree_implements;
typedef xos::base::tree_extends tree_extends;
///////////////////////////////////////////////////////////////////////
///  Class: treet
///////////////////////////////////////////////////////////////////////
template
<class TLeaf, class TBranch, class TTree,
 class TTreeImplements, class TTreeExtends,
 class TImplements = TTreeImplements,
 class TExtends = xos::base::treet
 <TLeaf, TBranch, TTree, TImplements, TTreeExtends> >

class _EXPORT_CLASS treet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TTree Derives;
    typedef TBranch branch_t;
    typedef TLeaf leaf_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    treet(branch_t *root = 0): Extends(root) {}
    treet(const treet& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

namespace binary {

typedef xos::base::binary::branch_implements branch_implements;
///////////////////////////////////////////////////////////////////////
///  Class: brancht
///////////////////////////////////////////////////////////////////////
template
<class TLeaf, class TBranch,
 class TBranchImplements, class TBranchExtends,
 class TImplements = TBranchImplements,
 class TExtends = xos::base::binary::brancht
 <TLeaf, TBranch, TImplements, TBranchExtends> >
class _EXPORT_CLASS brancht: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TBranch branch_t;
    typedef TLeaf leaf_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    brancht
    (const leaf_t& leaf, branch_t* tree = 0,
     branch_t* left = 0, branch_t* right = 0)
    : Extends(leaf, tree, left, right) {}
    brancht(const brancht& copy): Extends(copy) {}
    brancht() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef xos::base::binary::tree_implements tree_implements;
///////////////////////////////////////////////////////////////////////
///  Class: treet
///////////////////////////////////////////////////////////////////////
template
<class TLeaf, class TBranch, class TTree,
 class TTreeImplements, class TTreeExtends,
 class TImplements = TTreeImplements,
 class TExtends = xos::base::binary::treet
 <TLeaf, TBranch, TTree, TImplements, TTreeExtends> >
class _EXPORT_CLASS treet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TTree Derives;
    typedef TBranch branch_t;
    typedef TLeaf leaf_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    treet(branch_t* root = 0): Extends(root) {}
    treet(const treet& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace binary

namespace avl {

typedef xos::base::avl::branch_implements branch_implements;
///////////////////////////////////////////////////////////////////////
///  Class: brancht
///////////////////////////////////////////////////////////////////////
template
<class TLeaf, class TBranch,
 class TBranchImplements, class TBranchExtends,
 class TImplements = TBranchImplements,
 class TExtends = xos::base::avl::brancht
 <TLeaf, TBranch, TImplements, TBranchExtends> >
class _EXPORT_CLASS brancht: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TBranch branch_t;
    typedef TLeaf leaf_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    brancht
    (const leaf_t& leaf,  int depth = 1,
     branch_t* tree = 0, branch_t* left = 0, branch_t* right = 0)
    : Extends(leaf, depth, tree, left, right) {}
    brancht(const brancht& copy): Extends(copy) {}
    brancht() {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef xos::base::avl::tree_implements tree_implements;
///////////////////////////////////////////////////////////////////////
///  Class: treet
///////////////////////////////////////////////////////////////////////
template
<class TLeaf, class TBranch, class TTree,
 class TTreeImplements, class TTreeExtends,
 class TImplements = TTreeImplements,
 class TExtends = xos::base::avl::treet
 <TLeaf, TBranch, TTree, TImplements, TTreeExtends> >
class _EXPORT_CLASS treet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TTree Derives;
    typedef TBranch branch_t;
    typedef TLeaf leaf_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    treet(branch_t* root  = 0): Extends(root) {}
    treet(const treet& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace avl

namespace io {

typedef xos::io::char_reader reader;
typedef xos::io::char_writer writer;

namespace file {

typedef xos::io::file::attacher attacher;
typedef xos::io::file::opened_implemnents opened_implements;
typedef xos::io::file::opened opened;
///////////////////////////////////////////////////////////////////////
///  Class: readert
///////////////////////////////////////////////////////////////////////
template
<class TReader,
 class TImplements = xos::io::file::readert<TReader, char, char> >
class _EXPORT_CLASS readert: virtual public TImplements {
public:
    typedef TImplements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace file

namespace read {

///////////////////////////////////////////////////////////////////////
///  Class: filet
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>
class _EXPORT_CLASS filet: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    filet(FILE* attached = 0, bool is_open = false)
    : Extends(attached, is_open) {
    }
    virtual ~filet() {
        if (!(this->closed())) {
            xos::base::opener_exception e = xos::base::failed_to_close;
            throw (e);
        }
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    using Extends::open;
    virtual bool open(const wchar_t* name) {
        const char* mode = this->mode_read_binary();
        if ((this->open(name, mode))) {
            return true;
        }
        return false;
    }
    virtual bool open(const char* name) {
        const char* mode = this->mode_read_binary();
        if ((this->open(name, mode))) {
            return true;
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace read

} // namespace io

namespace fs {

typedef xos::fs::path path;

} // namespace fs

namespace os {
namespace current {

typedef xos::os::current::time time;

} // namespace current
} // namespace os

} // namespace texta

#endif // _TEXTA_XOS_BASE_BASE_HPP
