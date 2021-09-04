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
 *   File: cxmlelementnodeprocessor.hxx
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
#ifndef _CXMLELEMENTNODEPROCESSOR_HXX
#define _CXMLELEMENTNODEPROCESSOR_HXX

#include "cxmlprocessorinterface.hxx"
#include "cxmlelementprocessorlist.hxx"
#include "cxmlnodeprocessor.hxx"
#include "cxmlnodelist.hxx"
#include "cxmltextnodeinterface.hxx"
#include "cxmlstringtostring.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cXMLElementNodeProcessor
 *
 * Author: $author$
 *   Date: 12/12/2008
 **********************************************************************
 */
class cXMLElementNodeProcessor
: public cXMLNodeProcessor
{
public:
    typedef cXMLNodeProcessor cExtends;
    typedef cXMLElementNodeProcessor cDerives;

    cXMLElementProcessorItem m_item;
    cXMLString m_match;

    /**
     **********************************************************************
     * Constructor: cXMLElementNodeProcessor
     *
     *      Author: $author$
     *        Date: 12/12/2008
     **********************************************************************
     */
    cXMLElementNodeProcessor
    (const char* match=0,
     const char* mode=0,
     const char* childMode=0)
    : cExtends(mode, childMode),
      m_item(*this)
    {
        eError error;
        TLENGTH length;

        if (match)
        if (0 > (length = m_match.Appendc(match)))
            throw(error = -length);
    }
    /**
     **********************************************************************
     * Destructor: ~cXMLElementNodeProcessor
     *
     *     Author: $author$
     *       Date: 12/12/2008
     **********************************************************************
     */
    virtual ~cXMLElementNodeProcessor()
    {
    }
    /**
     **********************************************************************
     * Function: Match
     *
     *   Author: $author$
     *     Date: 12/12/2008
     **********************************************************************
     */
    virtual bool Match
    (const cXMLString& match,
     const cXMLString& mode,
     bool notMatched=false) const
    {
        cXMLStringToString matchString(match);
        cXMLStringToString m_matchString(m_match);
        bool matched = false;
        int unequal;

        DBT("() \"%s\" to \"%s\"\n", m_matchString.c_str(), matchString.c_str());

        if (!(unequal = m_mode.Compare(mode)))
        if (0 >= m_match.Length())
            return notMatched;
        else
        if (!notMatched)
            matched = !(unequal = m_match.Compare(match));
        return matched;
    }
};
#endif /* _CXMLELEMENTNODEPROCESSOR_HXX */
