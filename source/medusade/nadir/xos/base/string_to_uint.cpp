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
///   File: string_to_uint.cpp
///
/// Author: $author$
///   Date: 7/14/2015
///////////////////////////////////////////////////////////////////////

#if !defined(XOS_NADIR_XOS_BASE_STRING_TO_UINT_T)
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
virtual unsigned int to_uint() const {
    unsigned int value = 0;
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_TO_UINT_T)
    const TChar c0 = (TChar)('0');
    const TChar c9 = (TChar)('9');
    size_t length, digits, count;
    const TChar* chars;
    TChar c, d;

    if (((chars = this->chars(length))) && (0 < length)) {
        for (digits = 0, count = 0; count < length; count++) {
            if (((c = chars[count]) >= c0) && (c <= c9)) {
                value = (value*10) +
#if !defined(XOS_NADIR_XOS_BASE_STRING_TO_UINT_T)
                (unsigned int)
#else // !defined(XOS_NADIR_XOS_BASE_STRING_TO_UINT_T)
                (XOS_NADIR_XOS_BASE_STRING_TO_UINT_T)
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_TO_UINT_T)
                (d = (TChar)(c - c0));
                if ((d != 0) || digits)
                    digits++;
            }
        }
    }
#if !defined(XOS_NADIR_XOS_BASE_STRING_TO_UINT_T)
    return value;
}
#endif // !defined(XOS_NADIR_XOS_BASE_STRING_TO_UINT_T)

        

