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
 *   File: cXslTransformer.hxx
 *
 * Author: $author$
 *   Date: 12/11/2017
 **********************************************************************
 */
#ifndef _CXSLTRANSFORMER_HXX
#define _CXSLTRANSFORMER_HXX

#include "cxsltransformerinterface.hxx"
#include "cXsltProcessorInterface.hpp"
#include "cCharWriter.hpp"
#include "cWriter.hpp"

typedef cXSLTransformerImplement cXslTransformerImplements;
typedef cXSLTransformerBase cXslTransformerExtends;
/**
 **********************************************************************
 *  Class: cXslTransformer
 *
 * Author: $author$
 *   Date: 12/11/2017
 **********************************************************************
 */
class cXslTransformer
: virtual public cXslTransformerImplements,
  public cXslTransformerExtends
{
public:
    typedef cXslTransformerImplements cImplements;
    typedef cXslTransformerExtends cExtends;

    /**
     **********************************************************************
     * Constructor: cXslTransformer
     *
     *      Author: $author$
     *        Date: 12/11/2017
     **********************************************************************
     */
    cXslTransformer(): m_xslt(0)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cXslTransformer
     *
     *     Author: $author$
     *       Date: 12/11/2017
     **********************************************************************
     */
    virtual ~cXslTransformer()
    {
        if ((m_xslt)) {
            CPPNS::cXsltProcessorInterface::FreeInstance(m_xslt);
        }
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 12/11/2017
     **********************************************************************
     */
    virtual eError Initialize()
    {
        CPPNS::cXsltProcessorInterface* xslt = 0;

        if (!(xslt = m_xslt)) {
            CPPNS::eError e = 0;

            if ((xslt = CPPNS::cXsltProcessorInterface::GetInstance(e))) {
                if (!(e = xslt->Init())) {
                    m_xslt = xslt;
                    return e_ERROR_NONE;
                }
                CPPNS::cXsltProcessorInterface::FreeInstance(m_xslt);
            }
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 12/11/2017
     **********************************************************************
     */
    virtual eError Finalize()
    {
        eError error = e_ERROR_FAILED;
        CPPNS::cXsltProcessorInterface* xslt = 0;

        if ((xslt = m_xslt)) {
            CPPNS::eError e = 0, e2 = 0;

            e = xslt->Finish();
            if ((e2 = CPPNS::cXsltProcessorInterface::FreeInstance(xslt))) {
                if (!e) e = e2;
            }
            if (!e) error = e_ERROR_NONE;
            m_xslt = 0;
        }
        return error;
    };

    /**
     **********************************************************************
     * Function: SetLiteralParameter
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual eError SetLiteralParameter
    (const char* name, const char* value, 
     const char* literalQuoteChars = 0)
    {
        CPPNS::cXsltProcessorInterface* xslt = 0;

        if ((xslt = m_xslt)) {
            CPPNS::eError e = 0;

            if ((name) && (name[0]) && (value)) {
                CPPNS::cString n(name), v(value);

                if (!(e = xslt->SetLiteralParameter(n, v))) {
                    return e_ERROR_NONE;
                }
            }
        }
        return e_ERROR_FAILED;
    }
    /**
     **********************************************************************
     * Function: SetParameter
     *
     *   Author: $author$
     *     Date: 3/14/2008
     **********************************************************************
     */
    virtual eError SetParameter
    (const char* name, const char* value)
    {
        CPPNS::cXsltProcessorInterface* xslt = 0;

        if ((xslt = m_xslt)) {
            CPPNS::eError e = 0;

            if ((name) && (name[0]) && (value)) {
                CPPNS::cString n(name), v(value);

                if (!(e = xslt->SetParameter(n, v))) {
                    return e_ERROR_NONE;
                }
            }
        }
        return e_ERROR_FAILED;
    }

protected:
    /**
     **********************************************************************
     *  Class: cCharWriter
     *
     * Author: $author$
     *   Date: 12/12/2017
     **********************************************************************
     */
    class c_INSTANCE_CLASS cCharWriter
    : public CPPNS::cCharWriter
    {
    public:
        typedef CPPNS::cCharWriter cExtends;
        enum { bufferSize = 2048 };
        cCharWriter(::cCharWriterInterface& writer)
        : m_writer(writer), 
          m_buffer((char_t*)&m_defaultBuffer), 
          m_bufferSize(bufferSize),
          m_written(0) {
        }
        virtual ~cCharWriter() {
        }
        virtual ssize_t WriteFormattedV
        (const char_t* format, va_list va) {
            ssize_t count = 0, amount = 0;

            for (size_t length = m_bufferSize-1, amount = length; 
                 (length <= amount); length = IncreaseBuffer()-1) {

                m_buffer[0] = 0;
                m_buffer[length] = 0;

                if (length > (amount = ::vsnprintf(m_buffer, length, format, va))) {
                    m_buffer[amount] = 0;
                    count = Write(m_buffer, amount);
                    break;
                }
            }
            return count;
        }
        virtual ssize_t Write
        (const char_t* what, ssize_t length=-1) {
            ssize_t count = 0;
            if (0 > (count = m_writer.Write(what, length))) {
                count = -e_ERROR_FAILED;
            }
            m_written +=  count;
            return count;
        }
        virtual ssize_t Flush() {
            ssize_t count = 0;
            /*if (0 > (count = m_writer.Flush())) {
                count = -e_ERROR_FAILED;
            }*/
            return count;
        }
        virtual size_t IncreaseBuffer() {
            size_t newSize = m_bufferSize + m_bufferSize;
            if ((m_buffer != (char_t*)&m_defaultBuffer)) {
                delete m_buffer;
            }
            m_buffer = new char_t[newSize];
            m_bufferSize = newSize;
            return newSize;
        }
        virtual void FreeBuffer() {
            if ((m_buffer != (char_t*)&m_defaultBuffer)) {
                delete m_buffer;
            }
            m_buffer = (char_t*)&m_defaultBuffer;
            m_bufferSize = bufferSize;
        }
        virtual size_t Written() const {
            return m_written;
        }
    protected:
        ::cCharWriterInterface& m_writer;
        char_t m_defaultBuffer[bufferSize], *m_buffer;
        size_t m_bufferSize, m_written;
    };
    
public:
    /**
     **********************************************************************
     * Function: TransformFile
     *
     *   Author: $author$
     *     Date: 3/13/2008
     **********************************************************************
     */
    virtual eError TransformFile
    (cCharWriterInterface& errors, cCharWriterInterface& result,
     const char* xslFilename, const char* xmlFilename)
    {
        CPPNS::cXsltProcessorInterface* xslt = 0;

        if ((xslt = m_xslt)) {
            CPPNS::eError e = 0;

            if ((xslFilename) && (xslFilename[0]) 
                && (xmlFilename) && (xmlFilename[0])) {
                CPPNS::cString xsl(xslFilename), xml(xmlFilename);
                cCharWriter ew(errors), rw(result);

                if (!(e = xslt->ProcessFiles(ew, rw, xsl, xml))) {
                    if (!(ew.Written())) {
                        return e_ERROR_NONE;
                    }
                }
            }
        }
        return e_ERROR_FAILED;
    }

protected:
    CPPNS::cXsltProcessorInterface* m_xslt;
};

#endif /* _CXSLTRANSFORMER_HXX */
