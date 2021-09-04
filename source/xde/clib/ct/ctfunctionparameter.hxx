/**
 **********************************************************************
 * Copyright (c) 1988-2008 $organization$
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
 *   File: ctfunctionparameter.hxx
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
#ifndef _CTFUNCTIONPARAMETER_HXX
#define _CTFUNCTIONPARAMETER_HXX

#include "cbase.hxx"

/**
 **********************************************************************
 *  Class: cTFunctionParameter
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionParameter
{
public:
    typedef cTFunctionParameter cDerives;

    const char *m_name;
    const char *m_description;

    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    inline const char *GetName() const
    {
        return m_name;
    }
    /**
     **********************************************************************
     * Function: GetDescription
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    inline const char *GetDescription() const
    {
        return m_description;
    }
};
#endif /* _CTFUNCTIONPARAMETER_HXX */
