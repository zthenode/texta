///////////////////////////////////////////////////////////////////////
//   File: cevmainarg.hpp
//
// Author: $author$
//   Date: 4/4/2007
//
//    $Id$
///////////////////////////////////////////////////////////////////////

#ifndef _CEVMAINARG_HPP
#define _CEVMAINARG_HPP

#include "evmainarg.hpp"
#include "cevstring.hpp"
#include "cevbase.hpp"
#include "cevlist.hpp"

///////////////////////////////////////////////////////////////////////
//  Class: CEvMainArgItem
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
class CEvMainArgItem
: public CEvListItem<CEvMainArgItem>
{
public:
    typedef CEvListItem<CEvMainArgItem> CExtends;
    typedef CEvMainArgItem CDerives;

    EvMainArg& m_mainArg;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMainArgItem
    //
    //       Author: $author$
    //         Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvMainArgItem(EvMainArg& mainArg)
    : m_mainArg(mainArg)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetMainArg
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMainArg& GetMainArg() const 
    {
        return m_mainArg;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvMainArgList
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
class CEvMainArgList
: public CEvStaticList<CEvMainArgItem, CEvMainArgList>
{
public:
    typedef CEvStaticList<CEvMainArgItem, CEvMainArgList> CExtends;
    typedef CEvMainArgList CDerives;

    ///////////////////////////////////////////////////////////////////////
    // Function: FindFirstArgByShortName
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMainArg* FindFirstArgByShortName
    (const char* chars, int length=-1) const 
    {
        EvMainArg *arg = 0;
        CEvMainArgItem *argItem;
        int diff;

        for (argItem=GetFirstItem(); argItem; argItem=argItem->GetNextItem())
        {
            EvMainArg& mainArg = argItem->GetMainArg();    
            if (!(diff = mainArg.CompareShortName(chars, length)))
                arg = &mainArg;
        }
        return arg;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: FindFirstArgByLongName
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMainArg* FindFirstArgByLongName
    (const char* chars, int length=-1) const 
    {
        EvMainArg *arg = 0;
        CEvMainArgItem *argItem;
        int diff;

        for (argItem=GetFirstItem(); argItem; argItem=argItem->GetNextItem())
        {
            EvMainArg& mainArg = argItem->GetMainArg();    
            if (!(diff = mainArg.CompareLongName(chars, length)))
                arg = &mainArg;
        }
        return arg;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstArg
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMainArg* GetFirstArg
    (CEvMainArgItem*& argItem) const 
    {
        EvMainArg *arg = 0;
        if ((argItem=GetFirstItem()))
            arg = &argItem->GetMainArg();
        return arg;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextArg
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvMainArg* GetNextArg
    (CEvMainArgItem*& argItem) const 
    {
        EvMainArg *arg = 0;
        if (argItem)
        if ((argItem=argItem->GetNextItem()))
            arg = &argItem->GetMainArg();
        return arg;
    }
};

///////////////////////////////////////////////////////////////////////
//  Class: CEvMainArg
//
// Author: $author$
//   Date: 4/4/2007
///////////////////////////////////////////////////////////////////////
class CEvMainArg
: virtual public EvMainArg,
  public CEvBase
{
public:
    typedef EvMainArg CImplements;
    typedef CEvBase CExtends;
    typedef CEvMainArg CDerives;

    static CEvMainArgList m_list;
    CEvMainArgItem m_item;

	CEvString m_shortName;
	CEvString m_longName;
	CEvString m_description;
	CEvString m_parameters;

	mutable CEvString m_parameter;
	mutable CEvString m_parameterName;
	mutable CEvString m_parameterDescription;

    ///////////////////////////////////////////////////////////////////////
    // Constructor: CEvMainArg
    //
    //       Author: $author$
    //         Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    CEvMainArg
    (const char* shortName,
     const char* longName,
     const char* description,
     const char* parameters) 
    : m_item((EvMainArg&)(*this))
    {
        EvError error;
        LONG length;

        if (shortName)
        if (0 > (length = SetShortName(shortName)))
            throw (error = -length);

        if (longName)
        if (0 > (length = SetLongName(longName)))
            throw (error = -length);

        if (description)
        if ((error = SetDescription(description)))
            throw (error);

        if (parameters)
        if ((error = SetParameters(parameters)))
            throw (error);

        m_list.AddItem(m_item);
    }
    ///////////////////////////////////////////////////////////////////////
    // Destructor: ~CEvMainArg
    //
    //      Author: $author$
    //        Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual ~CEvMainArg()
    {
        m_list.DeleteItem(m_item);
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MainArg
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int MainArg
    (int args, int argn, const char *arg, 
     int argc, const char** argv, const char** env) 
    {
        return argn;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: MainArgParam
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* MainArgParam
    (int &argn, const char*& arg, 
     int argc, const char** argv) 
    {
        const char* argParam = arg;

        if (!argParam && (argn+1 < argc))
            argParam = argv[++argn];

        arg = 0;
        return argParam;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: CompareShortName
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareShortName
    (const char* tochars,
     int tolength=-1) 
    {
        int unequal = m_shortName.Compare(tochars, tolength);
        return unequal;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: CompareLongName
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual int CompareLongName
    (const char* tochars,
     int tolength=-1) 
    {
        int unequal = m_longName.Compare(tochars, tolength);
        return unequal;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetDescription
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetDescription
    (const char* chars,
     int length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        m_description.Assign(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetDescription
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetDescription
    (int &length) const 
    {
        const char* chars = m_description.c_str();
        length = (int)(m_description.length());
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetParameters
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetParameters
    (const char* chars,
     int length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        m_parameters.Assign(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetParameters
    //
    //   Author: $author$
    //     Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetParameters
    (int &length) const 
    {
        const char* chars = m_parameters.c_str();
        length = (int)(m_parameters.length());
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetFirstParameter
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetFirstParameter
    (const char*& nextParameter, int &length) const 
    {
        const char* chars;
        LONG llength;
        if ((chars = GetParameters(length)))
        if ((nextParameter = strchr(chars, ';')))
        {
            m_parameter.Assign(chars, (LONG)((nextParameter++)-chars));
            if ((chars = m_parameter.Chars(llength)))
                length = (int)(llength);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetNextParameter
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetNextParameter
    (const char*& nextParameter, int &length) const 
    {
        const char* chars;
        LONG llength;
        if ((chars = nextParameter))
        if (!chars[0])
            chars = 0;
        else if ((nextParameter = strchr(chars, ';')))
        {
            m_parameter.Assign(chars, (LONG)((nextParameter++)-chars));
            if ((chars = m_parameter.Chars(llength)))
                length = (int)(llength);
        }
        else length = (int)(strlen(chars));
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetParameterName
    //
    //   Author: $author$
    //     Date: 5/10/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetParameterName
    (const char* parameter, int &length) const 
    {
        const char* chars;
        LONG llength;
        if ((chars = parameter))
        if ((parameter = strchr(chars, ':')))
        {
            m_parameterName.Assign(chars, (LONG)((parameter++)-chars));
            if ((chars = m_parameterName.Chars(llength)))
                length = (int)(llength);
        }
        else length = (int)(strlen(chars));
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetShortNamei
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetShortNamei
    (const char* chars,
     int length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        m_shortName.Assign(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetShortNamei
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetShortNamei
    (int &length) const 
    {
        const char* chars = m_shortName.c_str();
        length = (int)(m_shortName.length());
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetShortName
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetShortName
    (const char* chars,
     LONG length=-1) 
    {
        length = m_shortName.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetShortName
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetShortName
    (LONG &length) const 
    {
        const char* chars = m_shortName.c_str();
        length = (int)(m_shortName.length());
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    // Function: SetLongNamei
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual EvError SetLongNamei
    (const char* chars,
     int length=-1) 
    {
        EvError error = EV_ERROR_NONE;
        m_longName.Assign(chars, length);
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetLongNamei
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetLongNamei
    (int &length) const 
    {
        const char* chars = m_longName.c_str();
        length = (int)(m_longName.length());
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: SetLongName
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual LONG SetLongName
    (const char* chars,
     LONG length=-1) 
    {
        length = m_longName.Assign(chars, length);
        return length;
    }
    ///////////////////////////////////////////////////////////////////////
    // Function: GetLongName
    //
    //    Author: $author$
    //      Date: 4/4/2007
    ///////////////////////////////////////////////////////////////////////
    virtual const char* GetLongName
    (LONG &length) const 
    {
        const char* chars = m_longName.c_str();
        length = (int)(m_longName.length());
        return chars;
    }
};
#endif // _CEVMAINARG_HPP
