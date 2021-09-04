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
 *   File: cmainarg.hxx
 *
 * Author: $author$
 *   Date: 1/18/2008
 **********************************************************************
 */
#ifndef _CMAINARG_HXX
#define _CMAINARG_HXX

#include "cmainarginterface.hxx"
#include "cmaininterface.hxx"
#include "cstring.hxx"
#include "clist.hxx"
#include "cdebug.h"

/**
 **********************************************************************
 *  Class: cMainArgItemT
 *
 * Author: $author$
 *   Date: 1/18/2008
 **********************************************************************
 */
template
<class TDerives,
 class TMainArg>
 
class cMainArgItemT
: public cListItemT<TDerives>
{
public:
    typedef cListItemT<TDerives> cExtends;
    typedef cMainArgItemT cDerives;

    TMainArg& m_mainArg;

    /**
     **********************************************************************
     * Constructor: cMainArgItemT
     *
     *      Author: $author$
     *        Date: 1/18/2008
     **********************************************************************
     */
    cMainArgItemT(TMainArg& mainArg)
    : m_mainArg(mainArg) 
    {
    }
    /**
     **********************************************************************
     * Function: GetMainArg
     *
     *   Author: $author$
     *     Date: 1/18/2008
     **********************************************************************
     */
    virtual TMainArg& GetMainArg() const 
    {
        return m_mainArg;
    }
};

/**
 **********************************************************************
 *  Class: cMainArgListT
 *
 * Author: $author$
 *   Date: 1/18/2008
 **********************************************************************
 */
template
<class TChar,
 class TLength,
 class TMainArg,
 class TMainArgItem,
 class TExtends=cBase>
 
class cMainArgListT
: public cStaticListT<TMainArgItem,TExtends>
{
public:
    typedef cStaticListT<TMainArgItem,TExtends> cExtends;
    typedef cMainArgListT cDerives;

    /**
     **********************************************************************
     * Constructor: cMainArgListT
     *
     *      Author: $author$
     *        Date: 1/18/2008
     **********************************************************************
     */
    cMainArgListT() 
    {
    }

    /**
     **********************************************************************
     * Function: FindFirstArgByShortName
     *
     *   Author: $author$
     *     Date: 1/19/2008
     **********************************************************************
     */
    virtual TMainArg* FindFirstArgByShortName
    (const TChar* chars,
     TLength length=-1) const 
    {
        TMainArg* arg = 0;
        TMainArgItem *argItem;
        int diff;

        for (argItem=CTHIS GetFirstItem(); 
             argItem; argItem=argItem->GetNextItem())
        {
            TMainArg& mainArg = argItem->GetMainArg();    
            if (!(diff = mainArg.CompareShortName(chars, length)))
                arg = &mainArg;
        }
        return arg;
    }
    /**
     **********************************************************************
     * Function: FindFirstArgByName
     *
     *   Author: $author$
     *     Date: 1/19/2008
     **********************************************************************
     */
    virtual TMainArg* FindFirstArgByName
    (const TChar* chars,
     TLength length=-1) const 
    {
        TMainArg* arg = 0;
        TMainArgItem *argItem;
        int diff;

        for (argItem=CTHIS GetFirstItem(); 
             argItem; argItem=argItem->GetNextItem())
        {
            TMainArg& mainArg = argItem->GetMainArg();    
            if (!(diff = mainArg.CompareName(chars, length)))
                arg = &mainArg;
        }
        return arg;
    }

    /**
     **********************************************************************
     * Function: GetFirstArg
     *
     *   Author: $author$
     *     Date: 1/19/2008
     **********************************************************************
     */
    virtual TMainArg* GetFirstArg
    (TMainArgItem*& argItem) const 
    {
        TMainArg* arg = 0;
        if ((argItem = CTHIS GetFirstItem()))
            arg = &argItem->GetMainArg();
        return arg;
    }
    /**
     **********************************************************************
     * Function: GetLastArg
     *
     *   Author: $author$
     *     Date: 1/19/2008
     **********************************************************************
     */
    virtual TMainArg* GetLastArg
    (TMainArgItem*& argItem) const 
    {
        TMainArg* arg = 0;
        if ((argItem = CTHIS GetLastItem()))
            arg = &argItem->GetMainArg();
        return arg;
    }

    /**
     **********************************************************************
     * Function: GetNextArg
     *
     *   Author: $author$
     *     Date: 1/19/2008
     **********************************************************************
     */
    virtual TMainArg* GetNextArg
    (TMainArgItem*& argItem) const 
    {
        TMainArg* arg = 0;
        if (argItem)
        if ((argItem = argItem->GetNextItem()))
            arg = &argItem->GetMainArg();
        return arg;
    }
    /**
     **********************************************************************
     * Function: GetPrevArg
     *
     *   Author: $author$
     *     Date: 1/19/2008
     **********************************************************************
     */
    virtual TMainArg* GetPrevArg
    (TMainArgItem*& argItem) const 
    {
        TMainArg* arg = 0;
        if (argItem)
        if ((argItem = argItem->GetPrevItem()))
            arg = &argItem->GetMainArg();
        return arg;
    }
};

/**
 **********************************************************************
 *  Class: cMainArgT
 *
 * Author: $author$
 *   Date: 1/19/2008
 **********************************************************************
 */
template
<class TChar,
 class TLength,
 class TString,
 class TMainArg,
 class TMainArgList,
 class TMainArgItem,
 class TMainArgImplement,
 class TExtends=cBase>
 
class cMainArgT
: virtual public TMainArgImplement,
  public TExtends
{
public:
    typedef TMainArgImplement cImplements;
    typedef TExtends cExtends;
    typedef cMainArgT cDerives;

#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    static TMainArgList m_list;
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    TMainArgItem m_item;

	TString m_shortName;
	TString m_name;
	TString m_description;
	TString m_parameters;

    /**
     **********************************************************************
     * Constructor: cMainArgT
     *
     *      Author: $author$
     *        Date: 1/19/2008
     **********************************************************************
     */
    cMainArgT
    (const TChar* shortName,
     const TChar* name,
     const TChar* description=0,
     const TChar* parameters=0) 
    : m_item((TMainArg&)(*this))
    {
        eError error;
        TLength length;

        if (shortName)
        if (0 > (length = SetShortName(shortName)))
            throw (error = -length);

        if (name)
        if (0 > (length = SetName(name)))
            throw (error = -length);

        if (description)
        if ((error = SetDescription(description)))
            throw (error);

        if (parameters)
        if ((error = SetParameters(parameters)))
            throw (error);

#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
        m_list.AddItem(m_item);
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
    /**
     **********************************************************************
     * Destructor: cMainArgT
     *
     *     Author: $author$
     *       Date: 1/19/2008
     **********************************************************************
     */
    virtual ~cMainArgT()
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
        m_list.DeleteItem(m_item);
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
    /**
     **********************************************************************
     * Function: ArgParam
     *
     *   Author: $author$
     *     Date: 2/15/2008
     **********************************************************************
     */
    virtual const TChar* ArgParam
    (int &argn, const TChar*& arg, 
     int argc, const TChar** argv) 
    {
        const TChar* argParam = arg;

        if (!argParam && (argn+1 < argc))
            argParam = argv[++argn];

        arg = 0;
        return argParam;
    }
    /**
     **********************************************************************
     * Function: SetName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual eError SetName
    (const TChar* chars,
     TLength length=-1) 
    {
        eError error = e_ERROR_FAILED;
        TLength count;
        if (0 <= (count = m_name.Assign(chars, length)))
            error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual const TChar* GetName
    (TLength& length) const 
    {
        const TChar* chars;
        TLength count;
        if ((chars = m_name.HasChars(count)))
            length = count;
        return chars;
    }
    /**
     **********************************************************************
     * Function: CompareName
     *
     *   Author: $author$
     *     Date: 2/20/2003
     **********************************************************************
     */
    virtual int CompareName
    (const TChar* toName, TLength length=-1) const
    {
        int unequal = m_name.Compare(toName, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: SetShortName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual eError SetShortName
    (const TChar* chars,
     TLength length=-1) 
    {
        eError error = e_ERROR_FAILED;
        TLength count;
        if (0 <= (count = m_shortName.Assign(chars, length)))
            error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetShortName
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual const TChar* GetShortName
    (TLength& length) const 
    {
        const TChar* chars;
        TLength count;
        if ((chars = m_shortName.HasChars(count)))
            length = count;
        return chars;
    }
    /**
     **********************************************************************
     * Function: CompareShortName
     *
     *   Author: $author$
     *     Date: 2/20/2003
     **********************************************************************
     */
    virtual int CompareShortName
    (const TChar* toName, TLength length=-1) const
    {
        int unequal = m_shortName.Compare(toName, length);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: SetDescription
     *
     *   Author: $author$
     *     Date: 2/17/2007
     **********************************************************************
     */
    virtual eError SetDescription
    (const TChar* chars,
     TLength length=-1) 
    {
        eError error = e_ERROR_FAILED;
        TLength count;
        if (0 <= (count = m_description.Assign(chars, length)))
            error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: SetParameters
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual eError SetParameters
    (const TChar* chars,
     TLength length=-1) 
    {
        eError error = e_ERROR_FAILED;
        TLength count;
        if (0 <= (count = m_parameters.Assign(chars, length)))
            error = e_ERROR_NONE;
        return error;
    }
    /**
     **********************************************************************
     * Function: GetListItem
     *
     *   Author: $author$
     *     Date: 2/20/2007
     **********************************************************************
     */
    virtual TMainArgItem& GetListItem() const
    {
        return (TMainArgItem&)(m_item);
    }
};

/**
 **********************************************************************
 *  Class: cMainArgItem
 *
 * Author: $author$
 *   Date: 1/19/2008
 **********************************************************************
 */
class cMainArgItem
: public cMainArgItemT
  <cMainArgItem, cMainArgInterface>
{
public:
    typedef cMainArgItemT
    <cMainArgItem, cMainArgInterface> cExtends;
    typedef cMainArgItem cDerives;
    /**
     **********************************************************************
     * Constructor: cMainArgItem
     *
     *      Author: $author$
     *        Date: 1/19/2008
     **********************************************************************
     */
    cMainArgItem(cMainArgInterface& mainArg)
    : cExtends(mainArg)
    {
    }
};
/**
 **********************************************************************
 *  Class: cMainArgList
 *
 * Author: $author$
 *   Date: 1/19/2008
 **********************************************************************
 */
class cMainArgList
: public cMainArgListT
  <char, int, cMainArgInterface, cMainArgItem, cBase>
{
public:
    typedef cMainArgListT
    <char, int, cMainArgInterface, cMainArgItem, cBase> cExtends;
    typedef cMainArgList cDerives;
};
/**
 **********************************************************************
 *  Class: cMainArg
 *
 * Author: $author$
 *   Date: 1/19/2008
 **********************************************************************
 */
class cMainArg
: public cMainArgT
  <char, LONG, cCharString, cMainArgInterface, 
   cMainArgList, cMainArgItem, cMainArgImplement, cBase>
{
public:
    typedef cMainArgT
    <char, LONG, cCharString, cMainArgInterface, 
     cMainArgList, cMainArgItem, cMainArgImplement, cBase> cExtends;
    typedef cMainArg cDerives;

#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
    static cMainArgList m_list;
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    /**
     **********************************************************************
     * Constructor: cMainArg
     *
     *      Author: $author$
     *        Date: 1/19/2008
     **********************************************************************
     */
    cMainArg
    (const char* shortName,
     const char* name,
     const char* description=0,
     const char* parameters=0) 
    : cExtends(shortName, name, description, parameters)
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
        m_list.AddItem(m_item);
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
    /**
     **********************************************************************
     * Destructor: cMainArg
     *
     *     Author: $author$
     *       Date: 1/19/2008
     **********************************************************************
     */
    virtual ~cMainArg()
    {
#if defined(NO_TEMPLATE_STATIC_MEMBERS) 
        m_list.DeleteItem(m_item);
#else /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
#endif /* defined(NO_TEMPLATE_STATIC_MEMBERS) */
    }
};

/**
 **********************************************************************
 *  Class: cDebugLevelsMainArg
 *
 * Author: $author$
 *   Date: 1/21/2008
 **********************************************************************
 */
class cDebugLevelsMainArg
: public cMainArg
{
public:
    typedef cMainArg cExtends;
    typedef cDebugLevelsMainArg cDerives;

    static cDebugLevelsMainArg* m_instance;
    cDebugLevelsMainArg* m_oldInstance;

    /**
     **********************************************************************
     * Constructor: cDebugLevelsMainArg
     *
     *      Author: $author$
     *        Date: 1/21/2008
     **********************************************************************
     */
    cDebugLevelsMainArg
    (const char* shortName="d",
     const char* name="debug-levels",
     const char* description="Debug levels",
     const char* parameters="levels:Debug levels") 
    : cExtends(shortName, name, description, parameters),
      m_oldInstance(m_instance)
    {
        m_instance = this;
    }
    /**
     **********************************************************************
     * Destructor: cDebugLevelsMainArg
     *
     *     Author: $author$
     *       Date: 2/15/2008
     **********************************************************************
     */
    virtual ~cDebugLevelsMainArg()
    {
        if (this == m_instance)
            m_instance = m_oldInstance;
    }
    /**
     **********************************************************************
     * Function: MainArg
     *
     *   Author: $author$
     *     Date: 1/21/2008
     **********************************************************************
     */
    virtual int MainArg
    (int args,
     int argn,
     const char* arg,
     int argc,
     const char** argv,
     const char** env) 
    {
        int argon = argn;
        cString s;
        cMainInterface *m;
        ULONG v;
        LONG n;
        if (arg)
        {
            if (arg[0])
            if (0 < (n = s.Append(arg)))
            if (0 <= (v = s.Unsigned(n)))
            {
                SET_DEBUG_LEVELS(v);
                //printf("%s: 0x%x\n", arg, GET_DEBUG_LEVELS());
            }
        }
        else 
        {
            if ((m = cMainInterface::GetMain()))
            if ((arg = GetName(n)))
            {
                //printf("%s: 0x%x\n", arg, GET_DEBUG_LEVELS());
            }
        }
        return argon;
    }
};

#endif /* _CMAINARG_HXX */
