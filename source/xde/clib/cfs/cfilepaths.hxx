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
 *   File: cfilepaths.hxx
 *
 * Author: $author$
 *   Date: 9/9/2008
 **********************************************************************
 */
#ifndef _CFILEPATHS_HXX
#define _CFILEPATHS_HXX

#include "cfilepathsinterface.hxx"
#include "cfilepath.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cFilePathsT"
/**
 **********************************************************************
 *  Class: cFilePathsT
 *
 * Author: $author$
 *   Date: 9/9/2008
 **********************************************************************
 */
template
<class TChar=CHAR, 
 class TSize=TSIZE,
 class TLength=TLENGTH,
 TLength VUndefinedLength=UNDEFINED_LENGTH,
 TChar VNullChar=NULL_CHAR,
 class TFilePath=cFilePath,
 class TFilePathInterface=cFilePathInterface,
 class TImplements=cFilePathsImplement,
 class TExtends=cString>
 
class cFilePathsT
: virtual public TImplements,
  public TExtends
{
public:
    typedef TImplements cImplements;
    typedef TExtends cExtends;
    typedef cFilePathsT cDerives;

    TChar m_filePathWildCardChar;
    TChar m_filePathSeparatorChar;
    const TChar* m_filePathsChars;
    TLength m_filePathsLength;
    TFilePath m_filePath;
    /**
     **********************************************************************
     * Constructor: cFilePathsT
     *
     *      Author: $author$
     *        Date: 9/9/2008
     **********************************************************************
     */
    cFilePathsT
    (const TChar* chars=0,
     TLength length=VUndefinedLength) 
    : cExtends(chars,length),
      m_filePathWildCardChar(PATH_WILDCARD_CHAR),
      m_filePathSeparatorChar(PATH_SEPARATOR_CHAR),
      m_filePathsChars(0),
      m_filePathsLength(0)
    {
    }
    /**
     **********************************************************************
     * Function: GetFirstFilePath
     *
     *   Author: $author$
     *     Date: 9/9/2008
     **********************************************************************
     */
    virtual TFilePathInterface* GetFirstFilePath
    (eError& error) 
    {
        TFilePathInterface* filePath = 0;
        error = e_ERROR_NONE;
        if ((m_filePathsChars = this->HasChars(m_filePathsLength)))
            filePath = GetNextFilePath(error);
        return filePath;
    }
    /**
     **********************************************************************
     * Function: GetNextFilePath
     *
     *   Author: $author$
     *     Date: 9/9/2008
     **********************************************************************
     */
    virtual TFilePathInterface* GetNextFilePath
    (eError& error) 
    {
        TFilePathInterface* filePath = 0;
        const TChar* chars;
        TLength length;
        TLength count;
        TChar c;

        error = e_ERROR_NONE;

        if (m_filePathsChars)
        {
            for (chars = m_filePathsChars; (c = *chars); chars++)
            {
                if (c == m_filePathSeparatorChar)
                {
                    length = (TLength)(chars-m_filePathsChars);

                    if (0 > (count = AssignFilePath
                        (m_filePathsChars, length)))
                        error = -count;
                    else filePath = &m_filePath;

                    if (1 > (m_filePathsLength -= (length+1)))
                        m_filePathsChars = 0;
                    else m_filePathsChars = chars+1;
                    return filePath;
                }
            }

            if (0 > (length = AssignFilePath
                (m_filePathsChars, m_filePathsLength)))
                error = -length;
            else filePath = &m_filePath;

            m_filePathsLength = 0;
            m_filePathsChars = 0;
        }
        return filePath;
    }
    /**
     **********************************************************************
     * Function: AssignFilePath
     *
     *   Author: $author$
     *     Date: 9/9/2008
     **********************************************************************
     */
    virtual TLength AssignFilePath
    (const TChar* chars,
     TLength length=VUndefinedLength) 
    {
        TLength count;
        if (0 > (count = m_filePath.AssignChars(chars, length)))
            return count;
        if (0 > (length = m_filePath.AppendFileName
            (&m_filePathWildCardChar, 1)))
            return length;
        count += length;
        return count;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Typedef: cFilePaths
 *
 *  Author: $author$
 *    Date: 9/9/2008
 **********************************************************************
 */
typedef cFilePathsT<>
cFilePaths;

#endif /* _CFILEPATHS_HXX */
