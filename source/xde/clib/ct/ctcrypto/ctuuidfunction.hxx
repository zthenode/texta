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
 *   File: ctuuidfunction.hxx
 *
 * Author: $author$
 *   Date: 2/12/2020
 **********************************************************************
 */
#ifndef CTUUIDFUNCTION_HXX
#define CTUUIDFUNCTION_HXX

#include "ctfunction.hxx"
#include "cuuid.hxx"

/**
 **********************************************************************
 *  Class: cTUuidFunction
 *
 * Author: $author$
 *   Date: 2/12/2020
 **********************************************************************
 */
class cTUuidFunction: public cTFunction {
public:
    typedef cTFunction cExtends;
    typedef cTUuidFunction cDerives;
    /**
     **********************************************************************
     * Constructor: cTUuidFunction
     *
     *      Author: $author$
     *        Date: 2/12/2020
     **********************************************************************
     */
    cTUuidFunction(const char* name, const char* description): cExtends(name, description) {
        static cTFunctionParameter parameter[] = {
        {0,0}};
        this->m_parameters = ((sizeof(parameter) / sizeof(cTFunctionParameter)) - 1);
        this->m_parameter = parameter;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 2/12/2020
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, const cTFunctionArgumentList& arglist) const {
        const char* chars = 0; TLENGTH length = 0; cString string; cUuid uuid;
        if ((uuid.Generate(string))) {
            if ((chars = string.HasChars(length))) {
                result.Write(chars, length);
            }
        }
        return e_ERROR_NONE;
    }
}; /* class cTUuidFunction */

#endif /* CTUUIDFUNCTION_HXX /*/
