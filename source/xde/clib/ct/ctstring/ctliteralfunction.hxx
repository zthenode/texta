/**
 **********************************************************************
 * Copyright (c) 1988-2020 $organization$
 *
 * This software is provided by the author and contributors ``as is'' 
 * and any express or implied warranties, including, but not limited to, 
 * the implied warranties of merchantability and fitness for a particular 
 * purpose are disclaimed. In no event shall the author or contributors 
 * be liable for any direct, indirect, incidental, special, exemplary, 
 * or consequential damages (including, but not limited to, procurement 
 * of substitute goods or services; loss of use, data, or profits; or 
 * business interruption) however caused and on any theory of liability, 
 * whether in contract, strict liability, or tort (including negligence 
 * or otherwise) arising in any way out of the use of this software, 
 * even if advised of the possibility of such damage.
 *
 *   File: ctliteralfunction.hxx
 *
 * Author: $author$
 *   Date: 5/14/2020
 **********************************************************************
 */
#ifndef CTLITERALFUNCTION_HXX
#define CTLITERALFUNCTION_HXX

#include "ctfunction.hxx"
#include "cstring.hxx"

/**
 **********************************************************************
 * Class: cTLiteralFunction
 *
 * Author: $author$
 *   Date: 5/14/2020
 **********************************************************************
 */
class cTLiteralFunction: public cTFunction {
public:
    typedef cTFunction cExtends;
    typedef cTLiteralFunction cDerives;
 
    /**
     **********************************************************************
     * Constructor: cTLiteralFunction
     *
     * Author: $author$
     *   Date: 5/14/2020
     **********************************************************************
     */
    cTLiteralFunction(const char* name, const char* description, const char* literal): cExtends(name, description) {
        static cTFunctionParameter parameter[] = {
        {0,0}};
        this->m_parameters = ((sizeof(parameter) / sizeof(cTFunctionParameter)) - 1);
        this->m_parameter = parameter;
        if ((literal)) {
            m_literal.Assign(literal);
        }
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     * Author: $author$
     *   Date: 5/14/2020
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, const cTFunctionArgumentList& arglist) const {
        cTFunctionArgument *arg = 0;
        const char* chars = 0; TLENGTH length = 0, count = 0, amount = 0;
        if ((chars = m_literal.HasChars(length))) {
            result.Write(chars, length);
        }
        for (arg = arglist.GetFirstItem(); arg; arg = arg->GetNextItem()) {
            if ((chars = arg->GetBuffer(length)) && (0 < length)) {
                if ((0 < (amount = result.Write(chars, length)))) {
                    count += amount;
                }
            }
        }
        if ((chars = m_literal.HasChars(length)) && (0 < count)) {
            result.Write(chars, length);
        }
        return e_ERROR_NONE;
    }

protected:
    cTString m_literal;
}; /* class cTLiteralFunction */

/**
 **********************************************************************
 * Class: cTAfterLiteralFunction
 *
 * Author: $author$
 *   Date: 5/14/2020
 **********************************************************************
 */
class cTAfterLiteralFunction: public cTLiteralFunction {
public:
    typedef cTLiteralFunction cExtends;
    typedef cTAfterLiteralFunction cDerives;
    /**
     **********************************************************************
     * Constructor: cTAfterLiteralFunction
     *
     * Author: $author$
     *   Date: 5/14/2020
     **********************************************************************
     */
    cTAfterLiteralFunction
    (const char* name, const char* description, const char* literal): cExtends(name, description, literal) {
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     * Author: $author$
     *   Date: 5/14/2020
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, const cTFunctionArgumentList& arglist) const {
        cTFunctionArgument *arg = 0;
        const char* chars = 0; TLENGTH length = 0, count = 0, amount = 0;
        for (arg = arglist.GetFirstItem(); arg; arg = arg->GetNextItem()) {
            if ((chars = arg->GetBuffer(length)) && (0 < length)) {
                if ((0 < (amount = result.Write(chars, length)))) {
                    count += amount;
                }
            }
        }
        if ((chars = m_literal.HasChars(length))) {
            result.Write(chars, length);
        }
        return e_ERROR_NONE;
    }
}; /* class cTAfterLiteralFunction */

#endif /* CTLITERALFUNCTION_HXX /*/
