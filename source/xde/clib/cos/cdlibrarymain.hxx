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
 *   File: cdlibrarymain.hxx
 *
 * Author: $author$
 *   Date: 5/24/2008
 **********************************************************************
 */
#ifndef _CDLIBRARYMAIN_HXX
#define _CDLIBRARYMAIN_HXX

#include "cdlibrarymaininterface.hxx"
#include "cbase.hxx"

typedef cBase 
cDLibraryMainExtends;

/**
 **********************************************************************
 *  Class: cDLibraryMain
 *
 * Author: $author$
 *   Date: 5/24/2008
 **********************************************************************
 */
class cDLibraryMain
: virtual public cDLibraryMainImplement,
  public cDLibraryMainExtends
{
public:
    typedef cDLibraryMainImplement cImplements;
    typedef cDLibraryMainExtends cExtends;
    typedef cDLibraryMain cDerives;

    static cDLibraryMainInterface* m_theInstance;
    cDLibraryMainInterface* m_oldInstance;

    /**
     **********************************************************************
     * Constructor: cDLibraryMain
     *
     *      Author: $author$
     *        Date: 5/24/2008
     **********************************************************************
     */
    cDLibraryMain() 
    : m_oldInstance(m_theInstance)
    {
        m_theInstance = this;
    }
    /**
     **********************************************************************
     * Destructor: ~cDLibraryMain
     *
     *     Author: $author$
     *       Date: 5/24/2008
     **********************************************************************
     */
    virtual ~cDLibraryMain()
    {
        if (this == m_theInstance)
            m_theInstance = m_oldInstance;
    }
};

#endif /* _CDLIBRARYMAIN_HXX */
