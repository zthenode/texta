///////////////////////////////////////////////////////////////////////
//   File: cevbmpmain.hpp
//
// Author: $author$
//   Date: 4/21/2009
///////////////////////////////////////////////////////////////////////

#ifndef _CEVBMPMAIN_HPP
#define _CEVBMPMAIN_HPP

#include "cevmain.hpp"
#include "cevcharfile.hpp"

#define DEFAULT_INPUT_FILENAME "medusade-boot-background.bmp"
#define DEFAULT_OUTPUT_FILENAME "medusa-boot.bmp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvBmpMain
//
// Author: $author$
//   Date: 4/21/2009
///////////////////////////////////////////////////////////////////////
class CEvBmpMain
: public CEvMain
{
public:
    typedef CEvMain CExtends;
    typedef CEvBmpMain CDerives;
    
    const char* m_inFileName,* m_outFileName;
    CEvCharFile m_inFile, m_outFile;
    
    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvBmpMain
    //
    //       Author: $author$
    //         Date: 4/21/2009
    ///////////////////////////////////////////////////////////////////////
    CEvBmpMain()
    : m_inFileName(DEFAULT_INPUT_FILENAME),
      m_outFileName(DEFAULT_OUTPUT_FILENAME)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: Run
    //
    //    Author: $author$
    //      Date: 4/21/2009
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc, const char** argv, const char** env) 
    {
        int err = 0;
        LONG curr, begin, end, length;
        EvError error;
        unsigned char byte, hi, lo;
        if (!(error = m_inFile.Open(m_inFileName,"rb")))
        {
            if (!(err = fseek(m_inFile.m_attached, 0, SEEK_END)))
            if (0 < (end = ftell(m_inFile.m_attached)))
            if (0 < (begin = (end - (640*480)/2)))
            if (!(err = fseek(m_inFile.m_attached, 0, SEEK_SET)))
            if (!(error = m_outFile.Open(m_outFileName,"wb")))
            {
                for (curr = 0; curr < begin; curr++)
                {
                    if (0 < (length = m_inFile.Read((char*)&byte, 1)))
                    if (0 < (length = m_outFile.Write((char*)&byte, 1)))
                        continue;
                    break;
                }
                for (curr = begin; curr < end; curr++)
                {
                    if (0 < (length = m_inFile.Read((char*)&byte, 1)))
                    {
                        //byte += 9;
                        if (3 > (hi = byte >> 4))
                            hi += 9;
                        if (3 > (lo = byte & 15))
                            lo += 9;
                        byte = (hi << 4) | lo;
                        if (0 < (length = m_outFile.Write((char*)&byte, 1)))
                            continue;
                    }
                    break;
                }
                m_outFile.Close();
            }
            m_inFile.Close();
        }
        return err;
    }
};

#endif // _CEVBMPMAIN_HPP
