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
 *   File: cbinarytree.hxx
 *
 * Author: $author$
 *   Date: 3/28/2008
 **********************************************************************
 */
#ifndef _CBINARYTREE_HXX
#define _CBINARYTREE_HXX

#include "cbase.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cBinaryTreeBranchT"
/**
 **********************************************************************
 *  Class: cBinaryTreeBranchT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template 
<class TLeaf,
 class TBranch,
 class TExtends=cBase>

class cBinaryTreeBranchT
: public TExtends
{
public:
    typedef TExtends cExtends;

    typedef TBranch tBranch;
    typedef TLeaf tLeaf;

    TBranch *m_tree,*m_leftBranch,*m_rightBranch;

    /**
     **********************************************************************
     * Constructor: cBinaryTreeBranchT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cBinaryTreeBranchT
    (TBranch *tree=0, TBranch *leftBranch=0, TBranch *rightBranch=0) 
    : m_tree(tree),
      m_leftBranch(leftBranch),
      m_rightBranch(rightBranch)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cBinaryTreeBranchT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cBinaryTreeBranchT()
    {
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const TBranch& toBranch) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const TLeaf& toLeaf) const = 0;
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const TLeaf& toLeaf, int length) const = 0;
    /**
     **********************************************************************
     * Function: SetTree
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *SetTree(TBranch *tree)
    {
        return m_tree=tree;
    }
    /**
     **********************************************************************
     * Function: GetTree
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *GetTree() const
    {
        return m_tree;
    }
    /**
     **********************************************************************
     * Function: SetLeftBranch
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *SetLeftBranch(TBranch *leftBranch)
    {
        return m_leftBranch=leftBranch;
    }
    /**
     **********************************************************************
     * Function: GetLeftBranch
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *GetLeftBranch() const
    {
        return m_leftBranch;
    }
    /**
     **********************************************************************
     * Function: SetRightBranch
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *SetRightBranch(TBranch *rightBranch)
    {
        return m_rightBranch=rightBranch;
    }
    /**
     **********************************************************************
     * Function: GetRightBranch
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *GetRightBranch() const
    {
        return m_rightBranch;
    }
};
#undef CDB_CLASS

#undef CDB_CLASS
#define CDB_CLASS "cBinaryTreeT"
/**
 **********************************************************************
 *  Class: cBinaryTreeT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template 
<class TLeaf,
 class TBranch,
 class TDerives,
 class TExtends=cBase>

class cBinaryTreeT
: public TExtends
{
public:
    typedef TExtends cExtends;

    TBranch *m_root;

    /**
     **********************************************************************
     * Constructor: cBinaryTreeT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cBinaryTreeT(TBranch *root=0) 
    : m_root(root) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cBinaryTreeT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cBinaryTreeT()
    {
    }
    /**
     **********************************************************************
     * Function: Clear
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Clear()
    {
        m_root=0;
    }
    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Insert(TBranch *branch)
    {
        TBranch *next, *tree;
        int unequal;

        if (!(next=GetRoot()))
            SetRoot(branch);

        else
        {
            do
            {
                tree=next;

                if ((unequal = branch->Compare(*tree)) < 0)
                {
                    if (!(next=tree->GetLeftBranch()))
                        tree->SetLeftBranch(branch);
                }
                else
                {
                    if (!(next=tree->GetRightBranch()))
                        tree->SetRightBranch(branch);
                }
            }
            while(next);

            branch->SetTree(tree);
        }
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    void Delete(TBranch *branch)
    {
        TBranch *next, *moved;

        if (!branch->GetLeftBranch() || !branch->GetRightBranch())
            moved = branch;

        else moved = GetNext(branch);

        if (!(next = moved->GetLeftBranch()))
            next = moved->GetRightBranch();

        if (next)
            next->SetTree(moved->GetTree());

        if (!moved->GetTree())
            SetRoot(next);

        else
        {
            if (moved == moved->GetTree()->GetLeftBranch())
                moved->GetTree()->SetLeftBranch(next);

            else moved->GetTree()->SetRightBranch(next);
        }

        if (moved != branch)
        {
            if ((next = moved->SetTree(branch->GetTree())))
                if (branch == next->GetRightBranch())
                    next->SetRightBranch(moved);
                else next->SetLeftBranch(moved);

            if ((next = moved->SetLeftBranch(branch->GetLeftBranch())))
                next->SetTree(moved);

            if ((next = moved->SetRightBranch(branch->GetRightBranch())))
                next->SetTree(moved);
        }
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *Find(unsigned &compares, const TLeaf &leaf) const
    {
        TBranch *branch;
        int unequal;
        unsigned count=0;

        if ((branch=GetRoot()))
        do
        {
            count++;

            if ((unequal = branch->Compare(leaf)) < 0)
                branch = branch->GetRightBranch();

            else if (unequal > 0)
                    branch = branch->GetLeftBranch();

            else break;
        }
        while(branch);

        compares = count;
        return branch;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *Find(const TLeaf &leaf) const
    {
        TBranch *branch;
        int unequal;

        if ((branch=GetRoot()))
        do
        {
            if ((unequal = branch->Compare(leaf)) < 0)
                branch = branch->GetRightBranch();

            else if (unequal > 0)
                    branch = branch->GetLeftBranch();

            else break;
        }
        while(branch);

        return branch;
    }
    /**
     **********************************************************************
     * Function: Find
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *Find(const TLeaf &leaf, int length) const
    {
        TBranch *branch;
        int unequal;

        if ((branch=GetRoot()))
        do
        {
            if ((unequal = branch->Compare(leaf, length)) < 0)
                branch = branch->GetRightBranch();

            else if (unequal > 0)
                    branch = branch->GetLeftBranch();

            else break;
        }
        while(branch);

        return branch;
    }
    /**
     **********************************************************************
     * Function: GetFirst
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetFirst() const
    {
        return GetFirstOf(GetRoot());
    }
    /**
     **********************************************************************
     * Function: GetLast
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetLast() const
    {
        return GetLastOf(GetRoot());
    }
    /**
     **********************************************************************
     * Function: GetNext
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetNext(TBranch *branch) const
    {
        TBranch *tree;

        if ((tree=branch->GetRightBranch()))
            return GetFirstOf(tree);

        if ((tree = branch->GetTree()))
        do
        {
            if (branch != tree->GetRightBranch())
                break;

            branch = tree;
            tree = tree->GetTree();
        }
        while(tree);

        return tree;
    }
    /**
     **********************************************************************
     * Function: GetPrevious
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetPrevious(TBranch *branch) const
    {
        TBranch *tree;

        if ((tree=branch->GetLeftBranch()))
            return GetLastOf(tree);

        if ((tree = branch->GetTree()))
        do
        {
            if (branch != tree->GetLeftBranch())
                break;

            branch = tree;
            tree = tree->GetTree();
        }
        while(tree);

        return tree;
    }
    /**
     **********************************************************************
     * Function: SetRoot
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *SetRoot(TBranch *root)
    {
        return m_root=root;
    }
    /**
     **********************************************************************
     * Function: GetRoot
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    inline TBranch *GetRoot() const
    {
        return m_root;
    }

protected:

    /**
     **********************************************************************
     * Function: GetFirstOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetFirstOf(TBranch *branch) const
    {
        TBranch *next;

        while ((next=branch->GetLeftBranch()))
            branch=next;
        return branch;
    }
    /**
     **********************************************************************
     * Function: GetLastOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetLastOf(TBranch *branch) const
    {
        TBranch *next;

        while ((next=branch->GetRightBranch()))
            branch=next;
        return branch;
    }
    /**
     **********************************************************************
     * Function: GetLeftOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetLeftOf(TBranch *branch) const
    {
        if (branch)
            return branch->GetLeftBranch();
        return 0;
    }
    /**
     **********************************************************************
     * Function: GetRightOf
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    TBranch *GetRightOf(TBranch *branch) const
    {
        if (branch)
            return branch->GetRightBranch();
        return 0;
    }
};
#undef CDB_CLASS

#endif /* _CBINARYTREE_HXX */
