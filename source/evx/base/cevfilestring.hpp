///////////////////////////////////////////////////////////////////////
//   File: cevfilestring.hpp
//
// Author: $author$
//   Date: 10/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVFILESTRING_HPP
#define _CEVFILESTRING_HPP

#include "cevstring.hpp"
#include "cevcharfile.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvFileString
//
// Author: $author$
//   Date: 10/4/2007
///////////////////////////////////////////////////////////////////////
class CEvFileString
: public CEvString
{
public:
    typedef CEvString CExtends;
    typedef CEvFileString CDerives;

    CEvCharFile m_file;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvFileString
    //
    //       Author: $author$
    //         Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvFileString
    (const char* filename=0) 
    {
        EvError error;
        LONG length;
        if (filename)
        if (0 > (length = ReadFile(filename)))
            throw(error = -length);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvFileString
    //
    //      Author: $author$
    //        Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvFileString()
    {
        EvError error;
        if ((error = m_file.Close()))
            throw(error);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFile
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadFile
    (const char* filename) 
    {
        LONG length = -EV_ERROR_FAILED;
        EvError error;
        if (!(error = m_file.Open
            (filename, EVFILE_MODE_READ)))
        {
            length = ReadLine(m_file);
            m_file.Close();
        }
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteFile
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteFile
    (const char* filename) 
    {
        LONG length = -EV_ERROR_FAILED;
        EvError error;
        if (!(error = m_file.Open
            (filename, EVFILE_MODE_WRITE)))
        {
            if (0 <= (length = WriteLine(m_file)))
                m_file.Flush();
            m_file.Close();
        }
        return length;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: ReadFileUnsigned
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG ReadFileUnsigned
    (const char* filename, LONG defaultValue=-1) 
    {
        LONG value = -EV_ERROR_FAILED;
        LONG length;
        ULONG uvalue;

        if (0 <= defaultValue)
           value = defaultValue;

        if (0 < (length = ReadFile(filename)))
        {
            uvalue = Unsigned(length);
            if (0 < length)
                value = (LONG)(uvalue);
        }
        return value;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: WriteFileUnsigned
    //
    //   Author: $author$
    //     Date: 10/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG WriteFileUnsigned
    (const char* filename, ULONG value) 
    {
        LONG length = -EV_ERROR_FAILED;
        LONG count;

        if (0 < (count = AssignUnsigned(value)))
        if (count != (length = WriteFile(filename)))
            length = -EV_ERROR_FAILED;
        return length;
    }
};
#endif // _CEVFILESTRING_HPP
