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
 *   File: ctfunctiontree.hxx
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
#ifndef _CTFUNCTIONTREE_HXX
#define _CTFUNCTIONTREE_HXX

#include "cavltree.hxx"
#include "ctfunctioninterface.hxx"
#include "cdebug.hxx"

/**
 **********************************************************************
 *  Class: cTFunctionBranch
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionBranch
: public cAVLTreeBranchT<tTNameChars,cTFunctionBranch,cBase>
{
public:
    typedef cAVLTreeBranchT<tTNameChars,cTFunctionBranch,cBase> cExtends;
    typedef cTFunctionBranch cDerives;

    cTFunctionInterface &m_function;

    /**
     **********************************************************************
     * Constructor: cTFunctionBranch
     *
     *      Author: $author$
     *        Date: 7/8/2003
     **********************************************************************
     */
    cTFunctionBranch(cTFunctionInterface &function)
    : m_function(function) 
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    int Compare(const cTFunctionBranch &branch) const
    {
        const tTNameChars toLeaf = branch.m_function.GetName();
        return Compare(toLeaf);
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    int Compare(const tTNameChars& toLeaf) const
    {
        int unequal = m_function.CompareName(toLeaf);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    int Compare(const tTNameChars& toLeaf, int length) const
    {
        int unequal = m_function.CompareName(toLeaf, length);
        return unequal;
    }
};

/**
 **********************************************************************
 *  Class: cTFunctionTree
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cTFunctionTree
: public cAVLTreeT<tTNameChars,cTFunctionBranch,cBase>
{
public:
    typedef cAVLTreeT<tTNameChars,cTFunctionBranch,cBase> cExtends;
    typedef cTFunctionTree cDerives;
    /**
     **********************************************************************
     * Function: Add
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    void Add(cTFunctionInterface &function)
    {
        const char* name;
        if ((name = function.GetName()))
        DBT("() adding function \"%s\"\n", name);

        cExtends::Insert(&function.GetBranch());
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/15/2003
     **********************************************************************
     */
    cTFunctionInterface* Find
    (const char* name, int namelen=-1) const
    {
        cTFunctionBranch *branch;

        if (namelen<0)
        {
            if ((branch=cExtends::Find(name)))
                return &branch->m_function;
        }
        else if (namelen>0)
        {
            if ((branch=cExtends::Find(name,namelen)))
                return &branch->m_function;
        }
        return 0;
    }
};
#endif /* _CTFUNCTIONTREE_HXX */
