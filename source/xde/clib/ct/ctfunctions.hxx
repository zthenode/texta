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
 *   File: ctfunctions.hxx
 *
 * Author: $author$
 *   Date: 4/6/2008
 **********************************************************************
 */
#ifndef _CTFUNCTIONS_HXX
#define _CTFUNCTIONS_HXX

#include "cplatform_path.h"
#include "ct.hxx"
#include "ctfunction.hxx"
#include "cfile.hxx"
#include "cbuffer.hxx"
#include "csplitter.hxx"

/**
 **********************************************************************
 *  Class: cStringTFunction
 *
 * Author: $author$
 *   Date: 4/3/2008
 **********************************************************************
 */
class cStringTFunction
: public cTFunction
{
public:
    typedef cTFunction cExtends;

    /**
     **********************************************************************
     * Constructor: cStringTFunction
     *
     *      Author: $author$
     *        Date: 4/3/2008
     **********************************************************************
     */
    cStringTFunction(const char* name, const char* description)
    : cExtends(name, description)
    {
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/3/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const cTFunctionArgumentList& arglist) const
    {
        TLENGTH length;
        const char *buffer;
        cTFunctionArgument *arg;
        cCharBuffer string;

        if ((arg = arglist.GetFirstItem()))
        do
        {
            if ((buffer = arg->GetBuffer(length)))
            if (length>0)
            if (0 > (length = string.Write(buffer, length)))
                return e_ERROR_WRITE;
        }
        while((arg = arg->GetNextItem()));

        if ((buffer = string.GetBuffer(length)))
        if (length>0)
            return Expand(result, t, buffer, length);

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 4/3/2008
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &result, cTInterface &t, 
     const char* buffer, TLENGTH length) const
    {
        return e_ERROR_NONE;
    }
};

#endif /* _CTFUNCTIONS_HXX */
