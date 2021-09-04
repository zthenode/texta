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
 *   File: cwsa.cxx
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */

#include "cwsa.hxx"

/**
 **********************************************************************
 *  Class: cWSA
 *
 * Author: $author$
 *   Date: 1/15/2008
 **********************************************************************
 */
cWSA* cWSA::cExtends::m_instance = 0;
cWSA g_wsa;

/**
 **********************************************************************
 *  Class: cWSAInterface
 *
 * Author: $author$
 *   Date: 2/20/2008
 **********************************************************************
 */
/**
 **********************************************************************
 * Function: cWSAInterface::GetInstance
 *
 *   Author: $author$
 *     Date: 2/20/2008
 **********************************************************************
 */
cWSAInterface* cWSAInterface::GetInstance() 
{
    cWSAInterface* m_instance = cWSA::cExtends::GetInstance();
    return m_instance;
}
