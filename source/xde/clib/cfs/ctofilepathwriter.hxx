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
 *   File: ctofilepathwriter.hxx
 *
 * Author: $author$
 *   Date: 9/6/2008
 **********************************************************************
 */
#ifndef _CTOFILEPATHWRITER_HXX
#define _CTOFILEPATHWRITER_HXX

#include "cstring.hxx"
#include "cfilepatheventinterface.hxx"
#include "creaderinterface.hxx"
#include "cwriter.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cToFilePathWriterT"
/**
 **********************************************************************
 *  Class: cToFilePathWriterT
 *
 * Author: $author$
 *   Date: 9/6/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TString=cString,
 class TFilePathEventInterface=cFilePathEventInterface,
 class TExtends=cWriter>
 
class cToFilePathWriterT
: public TExtends
{
public:
    typedef TExtends cExtends;
    typedef cToFilePathWriterT cDerives;

    typedef eError (cDerives::*MFinal)();
    typedef TLength (cDerives::*MPut)(TChar c);

    TFilePathEventInterface& m_events;

    MFinal m_final;
    MPut m_put;
    MPut m_oldPut;

    TChar m_dot;
    TString m_token;
    TString m_token2;

    /**
     **********************************************************************
     * Constructor: cToFilePathWriterT
     *
     *      Author: $author$
     *        Date: 9/6/2008
     **********************************************************************
     */
    cToFilePathWriterT
    (TFilePathEventInterface& events,
     bool isDirectory=false) 
    : m_events(events),
      m_final(0),
      m_put(0),
      m_oldPut(0),
      m_dot('.')
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual eError Initialize() 
    {
        eError error = e_ERROR_NONE;
        m_final = &cDerives::InitFinal;
        m_put = &cDerives::InitPut;
        m_token.Clear();
        m_token2.Clear();
        return error;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual eError Finalize() 
    {
        eError error = e_ERROR_NONE;
        if (m_final)
            error = (this->*m_final)();
        return error;
    }
    /**
     **********************************************************************
     * Function: Put
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    virtual TLength Put(TChar c) 
    {
        TLength count = 0;
        if (m_put)
            count = (this->*m_put)(c);
        return count;
    }

    /*
     * Put
     */

    /**
     **********************************************************************
     * Function: InitPut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * A*?
     **********************************************************************
     */
    TLength InitPut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            if ((chars = m_token.HasChars(length)))
            {
                // A+'/'
                m_events.OnPathDirectory(chars, length);
                m_token.Clear();
                m_put = &cDerives::NamePut;
            }
            else 
            {
                // '/'
                m_put = &cDerives::RootPut;
                m_final = &cDerives::RootFinal;
            }
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // A+'.'
                m_oldPut = m_put;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // '.' 
                m_put = &cDerives::CurrentPut;
                m_final = &cDerives::CurrentFinal;
            }
            break;
        case ':':
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'
                m_events.OnPathVolume(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::VolumePut;
            break;
        default:
            // A
            m_token.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: VolumePut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * A+':'?
     **********************************************************************
     */
    TLength VolumePut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // A+':'A*'/'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'A+'/'
                m_events.OnPathDirectory(chars, length);
                m_token.Clear();
                m_put = &cDerives::NamePut;
            }
            else 
            {
                // A+':''/'
                m_put = &cDerives::RootPut;
                m_final = &cDerives::RootFinal;
            }
            break;
        case '.':
            // A+':'A*'.'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'A+'.'
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // A+':''.' 
                m_put = &cDerives::CurrentPut;
                m_final = &cDerives::CurrentFinal;
            }
            break;
        default:
            // A+':'A
            m_token.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: NamePut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * .+?
     **********************************************************************
     */
    TLength NamePut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            if ((chars = m_token.HasChars(length)))
            {
                // .+A+'/'
                m_events.OnPathDirectory(chars, length);
                m_token.Clear();
            }
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // .+A+'.'
                m_oldPut = m_put;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // .+'.' 
                m_put = &cDerives::CurrentPut;
                m_final = &cDerives::CurrentFinal;
            }
            break;
        default:
            // .+A
            m_token.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: RootNamePut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/'.+?
     **********************************************************************
     */
    TLength RootNamePut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            if ((chars = m_token.HasChars(length)))
            {
                // '/'.+A+'/'
                m_events.OnPathRootDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            if ((chars = m_token.HasChars(length)))
            {
                // '/'.+A+'.'
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/'.+'.' 
                m_put = &cDerives::RootCurrentPut;
                m_final = &cDerives::RootCurrentFinal;
            }
            break;
        default:
            // '/'.+A
            m_token.Append(&c, 1);
            m_final = &cDerives::RootNameFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: ExtensionPut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * A+'.'?
     **********************************************************************
     */
    TLength ExtensionPut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // A+'.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // A+'.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            if ((chars = m_token.HasChars(length)))
            {
                m_events.OnPathDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // A+'.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // A+'.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            break;
        default:
            // A+'.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::ExtensionFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: RootExtensionPut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/'A+'.'?
     **********************************************************************
     */
    TLength RootExtensionPut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/'A+'.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/'A+'.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            if ((chars = m_token.HasChars(length)))
            {
                m_events.OnPathRootDirectory(chars, length);
                m_token.Clear();
            }
            m_put = m_oldPut;
            break;
        case '.':
            // '/'A+'.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/'A+'.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
            }
            break;
        default:
            // '/'A+'.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::RootExtensionFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: HostPut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/''/'?
     **********************************************************************
     */
    TLength HostPut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/''/'A*'/'
            if ((chars = m_token.HasChars(length)))
            {
                // '/''/'A+'/'
                m_events.OnPathHost(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        default:
            // '/''/'A
            m_token.Append(&c, 1);
            m_final = &cDerives::HostFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: CurrentPut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '.'?
     **********************************************************************
     */
    TLength CurrentPut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '.''/'
                m_events.OnPathCurrentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // '.''.' 
                m_put = &cDerives::ParentPut;
                m_final = &cDerives::ParentFinal;
            }
            break;
        default:
            // '.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::CurrentFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: RootCurrentPut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/''.'?
     **********************************************************************
     */
    TLength RootCurrentPut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/''.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathRootDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '/''.''/'
                m_events.OnPathRootCurrentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '/''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/''.''.' 
                m_put = &cDerives::RootParentPut;
                m_final = &cDerives::RootParentFinal;
            }
            break;
        default:
            // '/''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::RootNameFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: ParentPut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '.''.'?
     **********************************************************************
     */
    TLength ParentPut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '.''.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.''.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '.''.''/'
                m_events.OnPathParentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '.''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '.''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::ExtensionPut;
                m_final = &cDerives::ExtensionFinal;
            }
            else
            {
                // '.''.''.' 
                m_token.Append(&m_dot, 1);
                m_put = &cDerives::NamePut;
                m_final = &cDerives::NameFinal;
            }
            break;
        default:
            // '.''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::NameFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: RootParentPut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/''.''.'?
     **********************************************************************
     */
    TLength RootParentPut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/''.''.'A*'/'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.''.'A+'/'
                m_token.Append(chars, length);
                m_token2.Clear();
                if ((chars = m_token.HasChars(length)))
                {
                    m_events.OnPathRootDirectory(chars, length);
                    m_token.Clear();
                }
            }
            else
            if ((chars = m_token.HasChars(length)))
            {
                // '/''.''.''/'
                m_events.OnPathRootParentDirectory(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::NamePut;
            break;
        case '.':
            // '/''.''.'A*'.'
            m_token.Append(&m_dot, 1);
            if ((chars = m_token2.HasChars(length)))
            {
                // '/''.''.'A+'.'
                m_token.Append(chars, length);
                m_token2.Clear();
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/''.''.''.' 
                m_token.Append(&m_dot, 1);
                m_put = &cDerives::RootNamePut;
                m_final = &cDerives::RootNameFinal;
            }
            break;
        default:
            // '/''.''.'A
            m_token2.Append(&c, 1);
            m_final = &cDerives::RootNameFinal;
        }
        return count;
    }
    /**
     **********************************************************************
     * Function: RootPut
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/'?
     **********************************************************************
     */
    TLength RootPut
    (TChar c) 
    {
        TLength count = 0;
        TLength length;
        const char* chars;
        switch(c)
        {
        case '/':
        case '\\':
            // '/'A*'/'
            if ((chars = m_token.HasChars(length)))
            {
                // '/'A+'/'
                m_events.OnPathRootDirectory(chars, length);
                m_token.Clear();
                m_put = &cDerives::NamePut;
            }
            else 
            {
                // '/''/'
                m_put = &cDerives::HostPut;
                m_final = &cDerives::HostFinal;
            }
            break;
        case '.':
            // '/'A*'.'
            if ((chars = m_token.HasChars(length)))
            {
                // '/'A+'.'
                m_oldPut = &cDerives::NamePut;
                m_put = &cDerives::RootExtensionPut;
                m_final = &cDerives::RootExtensionFinal;
            }
            else
            {
                // '/''.' 
                m_put = &cDerives::RootCurrentPut;
                m_final = &cDerives::RootCurrentFinal;
            }
            break;
        case ':':
            // '/'A*':'
            if ((chars = m_token.HasChars(length)))
            {
                // A+':'
                m_events.OnPathVolume(chars, length);
                m_token.Clear();
            }
            m_put = &cDerives::VolumePut;
            break;
        default:
            // '/'A
            m_token.Append(&c, 1);
            m_final = &cDerives::RootFinal;
        }
        return count;
    }

    /*
     * Final
     */

    /**
     **********************************************************************
     * Function: InitFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     **********************************************************************
     */
    eError InitFinal() 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: HostFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/''/'A*
     **********************************************************************
     */
    eError HostFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/''/'A+
            m_events.OnPathHost(chars, length);
            m_token.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: NameFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * A*
     **********************************************************************
     */
    eError NameFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // A+
            m_events.OnPathFileBase(chars, length);
            m_token.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: RootNameFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/'A*
     **********************************************************************
     */
    eError RootNameFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/'A+
            m_events.OnPathRootFileBase(chars, length);
            m_token.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ExtensionFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * A+'.'A*
     **********************************************************************
     */
    eError ExtensionFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // A+'.'
            m_events.OnPathFileBase(chars, length);
            m_token.Clear();
        }
        if ((chars = m_token2.HasChars(length)))
        {
            // A'.'A+
            m_events.OnPathFileExtension(chars, length);
            m_token2.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: RootExtensionFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/'A+'.'A*
     **********************************************************************
     */
    eError RootExtensionFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/'A+'.'
            m_events.OnPathRootFileBase(chars, length);
            m_token.Clear();
        }
        if ((chars = m_token2.HasChars(length)))
        {
            // '/'A'.'A+
            m_events.OnPathFileExtension(chars, length);
            m_token2.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: CurrentFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '.'
     **********************************************************************
     */
    eError CurrentFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '.'
            m_events.OnPathCurrentDirectory(chars, length);
            m_token.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: RootCurrentFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/''.'
     **********************************************************************
     */
    eError RootCurrentFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/''.'
            m_events.OnPathRootCurrentDirectory(chars, length);
            m_token.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: ParentFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '.''.'
     **********************************************************************
     */
    eError ParentFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '.''.'
            m_events.OnPathParentDirectory(chars, length);
            m_token.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: RootParentFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/''.''.'
     **********************************************************************
     */
    eError RootParentFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        if ((chars = m_token.HasChars(length)))
        {
            // '/''.''.'
            m_events.OnPathRootParentDirectory(chars, length);
            m_token.Clear();
        }
        return error;
    }
    /**
     **********************************************************************
     * Function: RootFinal
     *
     *   Author: $author$
     *     Date: 9/6/2008
     *
     * '/'
     **********************************************************************
     */
    eError RootFinal() 
    {
        eError error = e_ERROR_NONE;
        TLength length;
        const char* chars;
        chars = m_token.HasChars(length);
        m_events.OnPathRootDirectory(chars, length);
        return error;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cToFilePathWriter
 *
 *  Author: $author$
 *    Date: 9/7/2008
 **********************************************************************
 */
typedef cToFilePathWriterT<>
cToFilePathWriter;

#endif /* _CTOFILEPATHWRITER_HXX */
