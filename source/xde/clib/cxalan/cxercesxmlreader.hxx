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
 *   File: cxercesxmlreader.hxx
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
#ifndef _CXERCESXMLREADER_HXX
#define _CXERCESXMLREADER_HXX

#include "cxmlreader.hxx"
#include "cxercesdomparser.hxx"
#include "cxercesinitializer.hxx"

/**
 **********************************************************************
 *  Class: cXercesXMLReader
 *
 * Author: $author$
 *   Date: 3/15/2008
 **********************************************************************
 */
class cXercesXMLReader
: public cXMLReader
{
public:
    typedef cXMLReader cExtends;
    typedef cXercesXMLReader cDerives;

    cXercesInitializer* m_xercesInitializer;
    cXercesDOMParser* m_xercesDOMParser;

    /**
     **********************************************************************
     * Constructor: cXercesXMLReader
     *
     *      Author: $author$
     *        Date: 3/15/2008
     **********************************************************************
     */
    cXercesXMLReader
    (bool isStaticInstance=true)
    : cExtends(isStaticInstance),
      m_xercesInitializer(0),
      m_xercesDOMParser(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: cXercesXMLReader
     *
     *     Author: $author$
     *       Date: 3/15/2008
     **********************************************************************
     */
    virtual ~cXercesXMLReader()
    {
        eError error;
        if (m_xercesInitializer)
        if ((error = Finalize()))
            throw(error);
    }
    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Initialize()
    {
        eError error = e_ERROR_NONE;
        if (m_xercesInitializer)
            error = e_ERROR_ALREADY_INITIALIZED;
        else 
        m_xercesInitializer = cXercesInitializer::GetInstance(error);
        return error;
    }    
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Finalize()
    {
        eError error = e_ERROR_NONE;
        eError error2;

        if (m_xercesInitializer)
        {
            if (m_xercesDOMParser)
                error = Close();

            if ((error2 = m_xercesInitializer->FreeInstance()))
            if (!error)
                error = error2;

            m_xercesInitializer = 0;
        }
        else error = e_ERROR_NOT_INITIALIZED;
        return error;
    }    
    /**
     **********************************************************************
     * Function: OpenFile
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError OpenFile
    (cCharWriterInterface& errors,
     const char* filename) 
    {
        eError error = e_ERROR_NOT_INITIALIZED;
        cXercesDOMParser* xercesDOMParser;
        if ((xercesDOMParser = NewXercesDOMParser(error)))
        if ((error = m_xercesDOMParser->ParseFile(errors, filename)))
            Close();
        return error;
    }
    /**
     **********************************************************************
     * Function: Open
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Open
    (cCharWriterInterface& errors,
     cCharReaderInterface& input) 
    {
        eError error = e_ERROR_NOT_INITIALIZED;
        cXercesDOMParser* xercesDOMParser;
        if ((xercesDOMParser = NewXercesDOMParser(error)))
        if ((error = m_xercesDOMParser->Parse(errors, input)))
            Close();
        return error;
    }
    /**
     **********************************************************************
     * Function: NewXercesDOMParser
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual cXercesDOMParser* 
    NewXercesDOMParser(eError& error) 
    {
        cXercesDOMParser* xercesDOMParser = 0;
        if (m_xercesInitializer)
        {
            if (m_xercesDOMParser)
            if ((error = Close()))
                return 0;

            if ((xercesDOMParser = new cXercesDOMParser()))
            {
                m_xercesDOMParser = xercesDOMParser;
                error = e_ERROR_NONE;
            }
            else error = e_ERROR_NEW;
        }
        else error = e_ERROR_NOT_INITIALIZED;
        return xercesDOMParser;
    }
    /**
     **********************************************************************
     * Function: Close
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError Close() 
    {
        eError error = e_ERROR_NOT_INITIALIZED;
        if (m_xercesDOMParser)
        {
            delete m_xercesDOMParser;
            m_xercesDOMParser = 0;
            error = e_ERROR_NONE;
        }
        else 
        if (m_xercesInitializer)
            error = e_ERROR_NOT_OPEN;
        return error;
    }
    /**
     **********************************************************************
     * Function: DeleteThis
     *
     *   Author: $author$
     *     Date: 3/15/2008
     **********************************************************************
     */
    virtual eError DeleteThis()
    {
        eError error = e_ERROR_NONE;
        bool isStaticInstance;
        if ((isStaticInstance = GetIsStaticInstance()))
            return e_ERROR_STATIC_INSTANCE;
        delete this;
        return error;
    }
};
#endif /* _CXERCESXMLREADER_HXX */
