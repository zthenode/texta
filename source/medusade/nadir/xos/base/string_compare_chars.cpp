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
///   File: string_compare_chars.cpp
///
/// Author: $author$
///   Date: 1/11/2016
///////////////////////////////////////////////////////////////////////

#if !defined(XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE)
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual int compare
(const TChar* chars, const char* to_chars,
 size_t to_length, size_t length) const {
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE)
    if ((XOS_NADIR_XOS_BASE_STRING_COMPARE_END
         (chars, length, to_length))) {
        if ((to_chars)) {
            int unequal = 0;
            TChar c1, c2;
            if ((length < to_length)) {
                unequal = -1;
            } else {
                if (length > to_length) {
                    unequal = 1;
                    length = to_length;
                }
            }
            for (; length; --length) {
                if ((c1 = XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(*(chars++)))
                    < (c2 = XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(((TChar)*(to_chars++))))) {
                    return -1;
                } else {
                    if ((c1 > c2)) {
                        return 1;
                    }
                }
            }
            return XOS_NADIR_XOS_BASE_STRING_COMPARE_BEGIN(unequal);
        } else {
            return 1;
        }
    } else {
        if ((to_chars)) {
            return -1;
        }
    }
#if !defined(XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE)
    return 0;
}
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE)
