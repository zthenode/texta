/**
 **********************************************************************
 * Copyright (c) 1988-2017 $organization$
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
 *   File: ctconditionalfunctions.cxx
 *
 * Author: $author$
 *   Date: 5/31/2017
 **********************************************************************
 */
#include "ctconditionalfunctions.hxx"
#include "ctexception.hxx"

/**
 **********************************************************************
 *  Class: cExitTFunction
 *
 * Author: $author$
 *   Date: 5/31/2017
 **********************************************************************
 */
class cExitTFunction: public cTFunction {
public:
   typedef cTFunction cExtends;

   /**
    **********************************************************************
    * Constructor: cExitTFunction
    *
    *      Author: $author$
    *        Date: 5/31/2017
    **********************************************************************
    */
   cExitTFunction(const char* name, const char* description)
   : cExtends(name, description) {
       static cTFunctionParameter parameter[]
       = {{"...",""},
          {0,0}};
       m_parameters = (sizeof(parameter)/sizeof(cTFunctionParameter))-1;
       m_parameter = parameter;
   }
   /**
    **********************************************************************
    * Function: Expand
    *
    *   Author: $author$
    *     Date: 5/31/2017
    **********************************************************************
    */
   virtual eError Expand
   (cCharStreamInterface &result, cTInterface &t,
    const cTFunctionArgumentList& arglist) const {
       cTException e(e_ERROR_EXIT);
       DBT("()...throwing cTException e(e_ERROR_EXIT)...\n");
       throw (e);
       return e_ERROR_NONE;
   }
} g_cExitTFunction
 ("exit","exit(...)");
