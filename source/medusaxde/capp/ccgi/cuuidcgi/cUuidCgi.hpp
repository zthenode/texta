///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2013 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cUuidCgi.hpp
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
#ifndef _CUUIDCGI_HPP
#define _CUUIDCGI_HPP

#include "cCgi.hpp"
#include "cHtmlMacro.hpp"
#include "cUuid.hpp"

#define CUUID_INVALID_UUID_STRING_0 "00000000-0000-0000-0000-000000000000"
#define CUUID_INVALID_UUID_STRING_F "FFFFFFFF-FFFF-FFFF-FFFF-FFFFFFFFFFFF"
#define CUUID_INVALID_UUID_STRING_f "ffffffff-ffff-ffff-ffff-ffffffffffff"

#define CUUID_INVALID_UUID_STRING \
    CUUID_INVALID_UUID_STRING_0

#define CUUIDCGI_CASE_FIELD_NAME "case"
#define CUUIDCGI_CASE_FIELD_VALUE_LOWER "lower"
#define CUUIDCGI_CASE_FIELD_VALUE_UPPER "upper"

#define CUUIDCGI_INVALID_FIELD_NAME "invalid"
#define CUUIDCGI_INVALID_FIELD_VALUE_0 "0"
#define CUUIDCGI_INVALID_FIELD_VALUE_F "F"
#define CUUIDCGI_INVALID_FIELD_VALUE_f "f"

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

typedef cCgiImplement cUuidCgiImplement;
typedef cCgi cUuidCgiExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cUuidCgi
//
// Author: $author$
//   Date: 8/20/2013
///////////////////////////////////////////////////////////////////////
class c_EXPORT_CLASS cUuidCgi
: virtual public cUuidCgiImplement, public cUuidCgiExtend {
public:
    typedef cUuidCgiImplement cImplements;
    typedef cUuidCgiExtend cExtends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    cUuidCgi()
    : m_contentTypeFieldName(CCGI_CONTENT_TYPE_FIELD_NAME),
      m_caseFieldName(CUUIDCGI_CASE_FIELD_NAME),
      m_caseFieldValueLower(CUUIDCGI_CASE_FIELD_VALUE_LOWER),
      m_caseFieldValueUpper(CUUIDCGI_CASE_FIELD_VALUE_UPPER),
      m_invalidFieldName(CUUIDCGI_INVALID_FIELD_NAME),
      m_invalidFieldValue_0(CUUIDCGI_INVALID_FIELD_VALUE_0),
      m_invalidFieldValue_F(CUUIDCGI_INVALID_FIELD_VALUE_F),
      m_invalidFieldValue_f(CUUIDCGI_INVALID_FIELD_VALUE_f) {
    }
    virtual ~cUuidCgi() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int RunRequest
    (int argc, char** argv, char** env, eHttpRequestMethod method) {
        cString uuidString(CUUID_INVALID_UUID_STRING);
        cUuid uuid;
        cHttpFormFieldInterface* field;

        //
        // Set content type
        //
        if ((field = FindFirstFormField(m_contentTypeFieldName))) {
            cString fieldValue(field->GetValue());
            if (0 < (fieldValue.Length()))
                SetContentType(fieldValue);
        }

        //
        // Init UUID string to invalid
        //
        if ((field = FindFirstFormField(m_invalidFieldName))) {
            cString fieldValue(field->GetValue());
            int unequal;
            if (!(unequal = (fieldValue.compare(m_invalidFieldValue_0))))
                uuidString.Assign(CUUID_INVALID_UUID_STRING_0);
            else
            if (!(unequal = (fieldValue.compare(m_invalidFieldValue_F))))
                uuidString.Assign(CUUID_INVALID_UUID_STRING_F);
            else
            if (!(unequal = (fieldValue.compare(m_invalidFieldValue_f))))
                uuidString.Assign(CUUID_INVALID_UUID_STRING_f);
        }

        if ((uuid.Generate())) {
        }

        //
        // Convert UUID string case
        //
        if ((field = FindFirstFormField(m_caseFieldName))) {
            cString fieldValue(field->GetValue());
            int unequal;
            if (!(unequal = (fieldValue.compare(m_caseFieldValueLower))))
                uuidString.ToLower();
            else
            if (!(unequal = (fieldValue.compare(m_caseFieldValueUpper))))
                uuidString.ToUpper();
        }

        //
        // Output UUID string
        //
        OutputContentL
        (HTML_, BODY_, B_, uuidString.c_str(), _B, _HTML, _BODY, 0);
        return 0;
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    const char* m_contentTypeFieldName;
    const char* m_caseFieldName;
    const char* m_caseFieldValueLower;
    const char* m_caseFieldValueUpper;
    const char* m_invalidFieldName;
    const char* m_invalidFieldValue_0;
    const char* m_invalidFieldValue_F;
    const char* m_invalidFieldValue_f;
};

#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#endif // _CUUIDCGI_HPP 
        

