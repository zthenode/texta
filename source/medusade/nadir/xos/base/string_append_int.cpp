///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2015 $organization$
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
///   File: string_append_int.cpp
///
/// Author: $author$
///   Date: 7/14/2015
///////////////////////////////////////////////////////////////////////

#if !defined(XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T)
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual stringt& append_int(int value) {
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T)
    TChar c = ((TChar)('0'));
    TChar s = ((TChar)('-'));
    size_t digits;
#if !defined(XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T)
    int msdValue;
#else // !defined(XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T)
    XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T msdValue;
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T)

    if (0 != value) {
        if (0 > value) {
            this->append(&s, 1);
            value = -value;
        }
        for (digits = 0, msdValue = 0;
             value; value /= 10, digits++) {
            msdValue = (msdValue*10) + (value%10);
        }
        for (; msdValue; msdValue /= 10, --digits) {
            TChar d = c + (TChar)(msdValue%10);
            this->append(&d, 1);
        }
        for (; digits; --digits)
            this->append(&c, 1);
    } else {
        this->append(&c, 1);
    }
#if !defined(XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T)
    return *this;
}
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_APPEND_INT_T)

        

