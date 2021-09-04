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
 *   File: clexersource.hxx
 *
 * Author: $author$
 *   Date: 5/2/2008
 **********************************************************************
 */
#ifndef _CLEXERSOURCE_HXX
#define _CLEXERSOURCE_HXX

#include "clist.hxx"
#include "cfile.hxx"

    /**
     **********************************************************************
     *  Class: cLexerSource
     *
     * Author: $author$
     *   Date: 3/3/2004
     **********************************************************************
     */
    class cLexerSource
    {
    public:
        /**
         **********************************************************************
         * Function: OpenFile
         *
         *   Author: $author$
         *     Date: 3/3/2004
         **********************************************************************
         */
        virtual cCharStreamInterface* OpenFile
        (eError &error, const char *filename)
        {
            error=e_ERROR_NOT_IMPLEMENTED;
            return 0;
        }
        /**
         **********************************************************************
         * Function: OpenURI
         *
         *   Author: $author$
         *     Date: 3/3/2004
         **********************************************************************
         */
        virtual cCharStreamInterface* OpenURI
        (eError &error, const char *uri)
        {
            error=e_ERROR_NOT_IMPLEMENTED;
            return 0;
        }
        /**
         **********************************************************************
         * Function: Close
         *
         *   Author: $author$
         *     Date: 3/3/2004
         **********************************************************************
         */
        virtual eError Close(cCharStreamInterface& stream)
        {
            eError error=e_ERROR_NOT_IMPLEMENTED;
            return error;
        }
    };

    /**
     **********************************************************************
     *  Class: cLexerInclude
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cLexerInclude
    : public cDynamicListItemT<cLexerInclude>
    {
    public:
        typedef cDynamicListItemT<cLexerInclude> cExtends;

        cLexerSource &m_source;
        cCharStreamInterface& m_stream;
        void *m_state;

        /**
         **********************************************************************
         * Constructor: cLexerInclude
         *
         *      Author: $author$
         *        Date: 8/25/2003
         **********************************************************************
         */
        cLexerInclude
        (cLexerSource &source, cCharStreamInterface& stream)
        : m_source(source),
          m_stream(stream)
        {
        }
        /**
         **********************************************************************
         * Destructor: ~cLexerInclude
         *
         *     Author: $author$
         *       Date: 3/3/2004
         **********************************************************************
         */
        virtual ~cLexerInclude()
        {
            eError error;

            if ((error = m_source.Close(m_stream)))
                throw(error);
        }
    };

    /**
     **********************************************************************
     *  Class: cLexerIncludes
     *
     * Author: $author$
     *   Date: 8/25/2003
     **********************************************************************
     */
    class cLexerIncludes
    : public cDynamicListT<cLexerInclude>
    {
    public:
        typedef cDynamicListT<cLexerInclude> cExtends;
    };

#endif /* _CLEXERSOURCE_HXX */
