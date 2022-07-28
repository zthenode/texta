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
///   File: string_find.cpp
///
/// Author: $author$
///   Date: 1/11/2016
///////////////////////////////////////////////////////////////////////

#if !defined(XOS_NADIR_XOS_BASE_STRING_COMPARE)
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual const TChar* find(const char* whatFind, size_t findLength) const {
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_COMPARE)
    const TChar* what = 0;
    size_t length = 0;
    if ((what = this->has_chars(length)) && (whatFind) && (findLength)) {
        const TChar* found = 0;
        TChar findWhat, atWhat;
        int unequal;

        if (findLength < length) {
            for (findWhat = XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(*whatFind), length -= (findLength-1);
                 (0 < length); --length, what++) {
                if (findWhat == (atWhat = XOS_NADIR_XOS_BASE_STRING_COMPARE_CASE(*what))) {
                    if (!(unequal = XOS_NADIR_XOS_BASE_STRING_COMPARE
                        (what, whatFind, findLength))) {
                        found = what;
                        break;
                    }
                }
            }
        }
        else {
            if (findLength == length) {
                if (!(unequal = XOS_NADIR_XOS_BASE_STRING_COMPARE
                    (whatFind, findLength)))
                    found = what;
            }
        }
        return found;
    }
#if !defined(XOS_NADIR_XOS_BASE_STRING_COMPARE)
    return 0;
}
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_COMPARE)
