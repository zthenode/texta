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
 *   File: cwinmain.hxx
 *
 * Author: $author$
 *   Date: 4/28/2008
 **********************************************************************
 */
#ifndef _CWINMAIN_HXX
#define _CWINMAIN_HXX

#include "cwin.hxx"
#include "cbase.hxx"
#include "cwininstance.hxx"

/**
 **********************************************************************
 *  Class: cWinMain
 *
 * Author: $author$
 *   Date: 4/28/2008
 **********************************************************************
 */
class cWinMain
: public cBase
{
public:
    typedef cBase cExtends;
    typedef cWinMain cDerives;

    static cWinMain* m_winMain;
    cWinMain* m_oldWinMain;

    cWinInstance m_winInstance;

    /**
     **********************************************************************
     * Constructor: cWinMain
     *
     *      Author: $author$
     *        Date: 4/28/2008
     **********************************************************************
     */
    cWinMain() 
    : m_oldWinMain(m_winMain)
    {
        m_winMain = this;
    }
    /**
     **********************************************************************
     * Destructor: cWinMain
     *
     *     Author: $author$
     *       Date: 4/28/2008
     **********************************************************************
     */
    virtual ~cWinMain()
    {
        if (this == m_winMain)
            m_winMain = m_oldWinMain;
    }
    /**
     **********************************************************************
     * Function: WinMain
     *
     *   Author: $author$
     *     Date: 4/28/2008
     **********************************************************************
     */
    virtual int WinMain
    (HINSTANCE instance, HINSTANCE previnst,
     LPCMDLINE cmdline, int cmdshow) 
    {
        int result = 0;
        int result2;
        eError error;
        if (!(error = m_winInstance.Attach(instance, true)))
        {
            if (!(result = BeforeProcessMessages
                (instance, previnst, cmdline, cmdshow)))
            {
                result = ProcessMessages
                (instance, previnst, cmdline, cmdshow);

                if ((result2 = AfterProcessMessages
                    (instance, previnst, cmdline, cmdshow))
                    && !result)
                    result = result2;
            }
            m_winInstance.Detach(instance, true);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: BeforeProcessMessages
     *
     *   Author: $author$
     *     Date: 4/28/2008
     **********************************************************************
     */
    virtual int BeforeProcessMessages
    (HINSTANCE instance, HINSTANCE previnst,
     LPCMDLINE cmdline, int cmdshow) 
    {
        int result = 0;
        return result;
    }
    /**
     **********************************************************************
     * Function: AfterProcessMessages
     *
     *   Author: $author$
     *     Date: 4/28/2008
     **********************************************************************
     */
    virtual int AfterProcessMessages
    (HINSTANCE instance, HINSTANCE previnst,
     LPCMDLINE cmdline, int cmdshow) 
    {
        int result = 0;
        return result;
    }
    /**
     **********************************************************************
     * Function: ProcessMessages
     *
     *   Author: $author$
     *     Date: 4/28/2008
     **********************************************************************
     */
    virtual int ProcessMessages
    (HINSTANCE instance, HINSTANCE previnst,
     LPCMDLINE cmdline, int cmdshow) 
    {
        int result = 0;
        MSG msg;

        while(GetMessage(&msg, NULL, NULL, NULL))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return result;
    }
    /**
     **********************************************************************
     * Function: GetWinMain
     *
     *   Author: $author$
     *     Date: 4/28/2008
     **********************************************************************
     */
    static cWinMain* GetWinMain() 
    {
        return m_winMain;
    }
};

#endif /* _CWINMAIN_HXX */
