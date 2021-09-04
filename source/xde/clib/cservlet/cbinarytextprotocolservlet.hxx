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
 *   File: cbinarytextprotocolservlet.hxx
 *
 * Author: $author$
 *   Date: 2/29/2008
 **********************************************************************
 */
#ifndef _CBINARYTEXTPROTOCOLSERVLET_HXX
#define _CBINARYTEXTPROTOCOLSERVLET_HXX

#include "cservlet.hxx"

/**
 **********************************************************************
 *  Class: cBinaryTextProtocolServlet
 *
 * Author: $author$
 *   Date: 2/29/2008
 **********************************************************************
 */
class cBinaryTextProtocolServlet
: public cServlet
{
public:
    typedef cServlet cExtends;
    typedef cBinaryTextProtocolServlet cDerives;
    /**
     **********************************************************************
     * Constructor: cBinaryTextProtocolServlet
     *
     *      Author: $author$
     *        Date: 2/29/2008
     **********************************************************************
     */
    cBinaryTextProtocolServlet() 
    {
    }
    /**
     **********************************************************************
     * Destructor: cBinaryTextProtocolServlet
     *
     *     Author: $author$
     *       Date: 2/29/2008
     **********************************************************************
     */
    virtual ~cBinaryTextProtocolServlet()
    {
    }
    /**
     **********************************************************************
     * Function: Service
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError Service
    (cServletRequestInterface& request,
     cServletResponseInterface& response) 
    {
        cReaderInterface& reader = request.Reader();
        eError error = e_ERROR_NONE;
        TLENGTH length;
        CHAR c;
        do
        {
            if (0 >= (length = reader.Look(&c, 1)))
                break;

            switch(c)
            {
            case '\r':
            case '\n':
                return ServiceText(request, response);

            default:
                if ((c < 32) || (c > 127))
                    return ServiceBinary(request, response);
            }
        }
        while(0 < length);
        return error;
    }
    /**
     **********************************************************************
     * Function: ServiceBinary
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError ServiceBinary
    (cServletRequestInterface& request,
     cServletResponseInterface& response) 
    {
        eError error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: ServiceText
     *
     *   Author: $author$
     *     Date: 2/24/2008
     **********************************************************************
     */
    virtual eError ServiceText
    (cServletRequestInterface& request,
     cServletResponseInterface& response) 
    {
        eError error = e_ERROR_NONE;
        cReaderInterface& reader = request.Reader();
        const CHAR* chars;
        TLENGTH length;
        if ((chars = reader.See(length)))
        DBT("() see \"%s\"\n", chars);
        return error;
    }
};
#endif /* _CBINARYTEXTPROTOCOLSERVLET_HXX */
