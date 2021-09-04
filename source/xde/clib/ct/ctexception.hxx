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
 *   File: ctexception.hxx
 *
 * Author: $author$
 *   Date: 5/31/2017
 **********************************************************************
 */
#ifndef _CTEXCEPTION_HXX
#define _CTEXCEPTION_HXX

#include "ctinterfacebase.hxx"

/**
 **********************************************************************
 *  Class: cTException
 *
 * Author: $author$
 *   Date: 5/31/2017
 **********************************************************************
 */
class cTException {
public:
    /**
     **********************************************************************
     * Constructor: cTException
     *
     *      Author: $author$
     *        Date: 6/9/2017
     **********************************************************************
     */
    cTException(eTError error): m_error(error) {
    }
    cTException(const cTException& copy): m_error(copy.m_error) {
    }
    virtual ~cTException() {
    }
    /**
     **********************************************************************
     * Function: Error
     *
     *   Author: $author$
     *     Date: 6/9/2017
     **********************************************************************
     */
    virtual eTError Error() const {
        eTError error = m_error;
        return error;
    }
protected:
    eTError m_error;
};

#endif /* _CTEXCEPTION_HXX */
        

