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
///   File: list.hpp
///
/// Author: $author$
///   Date: 3/18/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_NADIR_XOS_BASE_LIST_HPP
#define _XOS_NADIR_XOS_BASE_LIST_HPP

#include "xos/base/item.hpp"

namespace xos {
namespace base {

class _EXPORT_CLASS list;
typedef implement_base list_implements;
typedef base list_extends;
///////////////////////////////////////////////////////////////////////
///  Class: listt
///////////////////////////////////////////////////////////////////////
template
<class TList = list, class TItem = item,
 class TImplements = list_implements, class TExtends = list_extends>

class _EXPORT_CLASS listt: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;
    typedef TList Derives;
    typedef TItem Item;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    listt(TItem* first = 0, TItem* last = 0)
    : first_(first), last_(last) {
    }
    listt(const listt& copy)
    : first_(0), last_(0) {
    }
    virtual ~listt() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void clear() {
        first_ = last_ = 0;
    }
    virtual TItem* remove() {
        TItem* memberItem = first_;
        first_ = last_ = 0;
        return memberItem;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TItem* push(TItem& item) {
        item.set_prev(0);

        if ((item.set_next(first_)))
            first_->set_prev(&item);
        else last_ = &item;

        first_ = &item;
        return &item;
    }
    virtual TItem* pop() {
        TItem* item = 0;

        if ((item = first_)) {
            TItem* next = 0;

            if ((next = item->next()))
                next->set_prev(0);
            else last_ = 0;

            first_ = next;
            item->set_next(0);
            item->set_prev(0);
        }
        return item;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TItem* queue(TItem& item) {
        item.set_next(0);

        if ((item.set_prev(last_)))
            last_->set_next(&item);
        else first_ = &item;

        last_ = &item;
        return &item;
    }
    virtual TItem* pull() {
        TItem* item = 0;

        if ((item = last_)) {
            TItem* prev = 0;

            if ((prev = item->prev()))
                prev->set_next(0);
            else first_ = 0;

            last_ = prev;
            item->set_next(0);
            item->set_prev(0);
        }
        return item;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TItem* insert_before(TItem& otherItem, TItem& item) {
        if ((item.set_prev(otherItem.prev())))
            otherItem.prev()->set_next(&item);
        else first_ = &item;

        item.set_next(&otherItem);
        otherItem.set_prev(&item);
        return &item;
    }
    virtual TItem* insert_after(TItem& otherItem, TItem& item) {
        if ((item.set_next(otherItem.next())))
            otherItem.next()->set_prev(&item);
        else last_ = &item;

        item.set_prev(&otherItem);
        otherItem.set_next(&item);
        return &item;
    }
    virtual TItem* remove(TItem& item) {
        if (item.next())
            item.next()->set_prev(item.prev());
        else last_ = item.prev();

        if (item.prev())
            item.prev()->set_next(item.next());
        else first_ = item.next();

        item.set_next(0);
        item.set_prev(0);
        return &item;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TItem* push(TItem& firstItem, TItem& lastItem) {
        firstItem.set_prev(0);

        if ((lastItem.set_next(first_)))
            first_->set_prev(&lastItem);
        else last_ = &lastItem;

        first_ = &firstItem;
        return &firstItem;
    }
    virtual TItem* queue(TItem& firstItem, TItem& lastItem) {
        lastItem.set_next(0);

        if ((firstItem.set_prev(last_)))
            last_->set_next(&firstItem);
        else first_ = &firstItem;

        last_ = &lastItem;
        return &firstItem;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TItem* insert_before
    (TItem& otherItem, TItem& firstItem, TItem& lastItem) {
        if ((firstItem.set_prev(otherItem.prev())))
            otherItem.prev()->set_next(&firstItem);
        else first_ = &firstItem;

        lastItem.set_next(&otherItem);
        otherItem.set_prev(&lastItem);
        return &firstItem;
    }
    virtual TItem* insert_after
    (TItem& otherItem, TItem& firstItem, TItem& lastItem) {
        if ((lastItem.set_next(otherItem.next())))
            otherItem.next()->set_prev(&lastItem);
        else last_ = &lastItem;

        firstItem.set_prev(&otherItem);
        otherItem.set_next(&firstItem);
        return &otherItem;
    }
    virtual TItem* remove(TItem& firstItem, TItem& lastItem) {
        if (lastItem.next())
            lastItem.next()->set_prev(firstItem.prev());
        else last_ = firstItem.prev();

        if (firstItem.prev())
            firstItem.prev()->set_next(lastItem.next());
        else first_ = lastItem.next();

        lastItem.set_next(0);
        firstItem.set_prev(0);
        return &firstItem;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual TItem* set_first(TItem* to) {
        first_ = to;
        return first_;
    }
    virtual TItem* first() const {
        return first_;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual TItem* set_last(TItem* to) {
        last_ = to;
        return last_;
    }
    virtual TItem* last() const {
        return last_;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    TItem *first_, *last_;
};

} // namespace base 
} // namespace xos 

#endif // _XOS_NADIR_XOS_BASE_LIST_HPP 
