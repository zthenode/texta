/**
 **********************************************************************
 * Copyright (c) $year$ $author$
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
 *   File: cprimereaderevents.hxx
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
#ifndef _CPRIMEREADEREVENTS_HXX
#define _CPRIMEREADEREVENTS_HXX

#include "primereaderevents.hxx"
#include "crsakey.hxx"

/**
 **********************************************************************
 *  Class: CPrimeReaderEvents
 *
 * Author: $author$
 *   Date: $date$
 **********************************************************************
 */
class CPrimeReaderEvents
: virtual public PrimeReaderEvents,
  public CBase
{
public:
    typedef PrimeReaderEvents CImplements;
    typedef CBase CExtends;
    typedef CPrimeReaderEvents CDerives;

    PrimeReaderEvents* m_events;

    /**
     **********************************************************************
     * Constructor: CPrimeReaderEvents
     *
     *      Author: $author$
     *        Date: $date$
     **********************************************************************
     */
    CPrimeReaderEvents
    (PrimeReaderEvents* events=0) 
    : m_events(events)
    {
    }
    /**
     **********************************************************************
     * Function: OnReadPrime
     *
     *   Author: $author$
     *     Date: $date$
     **********************************************************************
     */
    virtual Error OnReadPrime
    (BIGPRIME *n, unsigned bytes) 
    {
        Error error = _ERROR_NONE;
        if (m_events)
            error = m_events->OnReadPrime(n, bytes);
        return error;
    }
};
#endif /* _CPRIMEREADEREVENTS_HXX */
