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
 *   File: credblacktree.hxx
 *
 * Author: $author$
 *   Date: 3/28/2008
 **********************************************************************
 */
#ifndef _CREDBLACKTREE_HXX
#define _CREDBLACKTREE_HXX

#include "cbinarytree.hxx"

/**
 **********************************************************************
 *  Class: cRedBlackTreeBranchT
 *
 * Author: $author$
 *   Date: 7/8/2003
 **********************************************************************
 */
template 
<class TLeaf,
 class TDerives,
 class TExtends=cBase>

class cRedBlackTreeBranchT
: public cBinaryTreeBranchT<TLeaf,TDerives,TExtends>
{
public:
    typedef cBinaryTreeBranchT<TLeaf,TDerives,TExtends> cExtends;

    bool m_isRed;

    /**
     **********************************************************************
     * Constructor: cRedBlackTreeBranchT
     *
     *      Author: $author$
     *        Date: 7/8/2003
     **********************************************************************
     */
    cRedBlackTreeBranchT
    (bool isRed=false, TDerives *tree=0, 
     TDerives *leftBranch=0, TDerives *rightBranch=0) 
    : cExtends(tree,leftBranch,rightBranch),
      m_isRed(isRed)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cRedBlackTreeBranchT
     *
     *     Author: $author$
     *       Date: 7/8/2003
     **********************************************************************
     */
    virtual ~cRedBlackTreeBranchT()
    {
    }
    /**
     **********************************************************************
     * Function: SetIsRed
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    inline bool SetIsRed(bool isRed=true)
    {
        return m_isRed=isRed;
    }
    /**
     **********************************************************************
     * Function: GetIsRed
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    inline bool GetIsRed() const
    {
        return m_isRed;
    }
};

/**
 **********************************************************************
 *  Class: cRedBlackTreeT
 *
 * Author: $author$
 *   Date: 7/8/2003
 **********************************************************************
 */
template 
<class TLeaf,
 class TBranch,
 class TDerives,
 class TExtends=cBase>

class cRedBlackTreeT
: public cBinaryTreeT
  <TLeaf,TBranch,TDerives,TExtends>
{
public:
    typedef cBinaryTreeT
    <TLeaf,TBranch,TDerives,TExtends> cExtends;

    /**
     **********************************************************************
     * Constructor: cRedBlackTreeT
     *
     *      Author: $author$
     *        Date: 7/8/2003
     **********************************************************************
     */
    cRedBlackTreeT(TBranch *root=0) 
    : cExtends(root) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cRedBlackTreeT
     *
     *     Author: $author$
     *       Date: 7/8/2003
     **********************************************************************
     */
    virtual ~cRedBlackTreeT()
    {
    }
    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    void Insert(TBranch *branch)
    {
        TBranch *tree;

        cExtends::Insert(branch);

        branch->SetIsRed();

        while ((branch != CTHIS GetRoot()) 
               && (GetIsRed(branch->GetTree())))
        {
            if (branch->GetTree() 
                == branch->GetTree()->GetTree()->GetLeftBranch())
             {
                tree = branch->GetTree()->GetTree()->GetRightBranch();

                if (GetIsRed(tree))
                {
                    tree->SetIsRed(false);
                    branch->GetTree()->SetIsRed(false);
                    branch->GetTree()->GetTree()->SetIsRed();
                    branch = branch->GetTree()->GetTree();
                }
                else
                {
                    if (branch == branch->GetTree()->GetRightBranch())
                    {
                        branch = branch->GetTree();
                        RotateLeft(branch);
                    }

                    branch->GetTree()->SetIsRed(false);
                    branch->GetTree()->GetTree()->SetIsRed();
                    RotateRight(branch->GetTree()->GetTree());
                }
            }
            else
            {
                tree = branch->GetTree()->GetTree()->GetLeftBranch();

                if (GetIsRed(tree))
                {
                    tree->SetIsRed(false);
                    branch->GetTree()->SetIsRed(false);
                    branch->GetTree()->GetTree()->SetIsRed();
                    branch = branch->GetTree()->GetTree();
                }
                else
                {
                    if (branch == branch->GetTree()->GetLeftBranch())
                    {
                        branch = branch->GetTree();
                        RotateRight(branch);
                    }

                    branch->GetTree()->SetIsRed(false);
                    branch->GetTree()->GetTree()->SetIsRed();
                    RotateLeft(branch->GetTree()->GetTree());
                }
            }
        }

        CTHIS GetRoot()->SetIsRed(false);
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    void Delete(TBranch *branch)
    {
        TBranch *next, *moved, *child;

        if (!branch->GetLeftBranch() || !branch->GetRightBranch())
            moved = branch;

        else moved = GetNext(branch);

        if (!(child = moved->GetLeftBranch()))
            child = moved->GetRightBranch();

        if (!moved->GetTree())
            SetRoot(child);

        else
        {
            if (moved == moved->GetTree()->GetLeftBranch())
                moved->GetTree()->SetLeftBranch(child);

            else moved->GetTree()->SetRightBranch(child);
        }

        if (child)
            child->SetTree(moved->GetTree());

        else child = moved->GetTree();

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

            moved->SetIsRed(branch->GetIsRed());
        }

        if (child)
        {
            while ((child != CTHIS GetRoot()) && (!child->GetIsRed()))
            {
                if (child->GetTree()->GetLeftBranch() == child)
                {
                    next = child->GetTree()->GetRightBranch();

                    if (GetIsRed(next))
                    {
                        next->SetIsRed(false);
                        child->GetTree()->SetIsRed();
                        RotateLeft(child->GetTree());
                        next = child->GetTree()->GetRightBranch();
                    }

                    if (!next)
                        child = child->GetTree();

                    else if ((!GetIsRed(next->GetLeftBranch()))
                             && (!GetIsRed(next->GetRightBranch())))
                    {
                        next->SetIsRed();
                        child = child->GetTree();
                    }
                    else
                    {
                        if (!GetIsRed(next->GetRightBranch()))
                        {
                            SetIsRed(next->GetLeftBranch(),false);
                            next->SetIsRed();
                            RotateRight(next);
                            next = child->GetTree()->GetRightBranch();
                        }

                        next->SetIsRed(child->GetTree()->GetIsRed());
                        SetIsRed(next->GetRightBranch(),false);
                        child->GetTree()->SetIsRed(false);
                        RotateLeft(child->GetTree());
                        child = CTHIS GetRoot();
                    }
                }
                else
                {
                    next = child->GetTree()->GetLeftBranch();

                    if (GetIsRed(next))
                    {
                        next->SetIsRed(false);
                        child->GetTree()->SetIsRed();
                        RotateRight(child->GetTree());
                        next = child->GetTree()->GetLeftBranch();
                    }

                    if (!next)
                        child = child->GetTree();

                    else if ((!GetIsRed(next->GetRightBranch()))
                             && (!GetIsRed(next->GetLeftBranch())))
                    {
                        next->SetIsRed();
                        child = child->GetTree();
                    }
                    else
                    {
                        if (!GetIsRed(next->GetLeftBranch()))
                        {
                            SetIsRed(next->GetRightBranch(),false);
                            next->SetIsRed();
                            RotateLeft(next);
                            next = child->GetTree()->GetLeftBranch();
                        }

                        next->SetIsRed(child->GetTree()->GetIsRed());
                        SetIsRed(next->GetLeftBranch(),false);
                        child->GetTree()->SetIsRed(false);
                        RotateRight(child->GetTree());
                        child = CTHIS GetRoot();
                    }
                }
            }

            child->SetIsRed(false);
        }
    }

protected:

    /**
     **********************************************************************
     * Function: RotateLeft
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    void RotateLeft(TBranch *branch)
    {
        TBranch *rightBranch = branch->GetRightBranch();

        branch->SetRightBranch(rightBranch->GetLeftBranch());

        if (rightBranch->GetLeftBranch())
            rightBranch->GetLeftBranch()->SetTree(branch);

        rightBranch->SetTree(branch->GetTree());

        if (!branch->GetTree())
            SetRoot(rightBranch);
        else
        {
            if (branch == branch->GetTree()->GetLeftBranch())
                branch->GetTree()->SetLeftBranch(rightBranch);
            else
                branch->GetTree()->SetRightBranch(rightBranch);
        }

        rightBranch->SetLeftBranch(branch);
        branch->SetTree(rightBranch);
    }
    /**
     **********************************************************************
     * Function: RotateRight
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    void RotateRight(TBranch *branch)
    {
        TBranch *leftBranch = branch->GetLeftBranch();

        branch->SetLeftBranch(leftBranch->GetRightBranch());

        if (leftBranch->GetRightBranch())
            leftBranch->GetRightBranch()->SetTree(branch);

        leftBranch->SetTree(branch->GetTree());

        if (!branch->GetTree())
            SetRoot(leftBranch);
        else
        {
            if (branch == branch->GetTree()->GetRightBranch())
                branch->GetTree()->SetRightBranch(leftBranch);
            else
                branch->GetTree()->SetLeftBranch(leftBranch);
        }

        leftBranch->SetRightBranch(branch);
        branch->SetTree(leftBranch);
    }
    /**
     **********************************************************************
     * Function: SetIsRed
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    bool SetIsRed(TBranch *branch,bool isRed=true)
    {
        if (branch)
            return branch->SetIsRed(isRed);
        return false;
    }
    /**
     **********************************************************************
     * Function: GetIsRed
     *
     *   Author: $author$
     *     Date: 7/8/2003
     **********************************************************************
     */
    bool GetIsRed(TBranch *branch) const
    {
        if (branch)
            return branch->GetIsRed();
        return false;
    }
};

/**
 **********************************************************************
 *  Class: cRedBlackTreeBranch
 *
 * Author: $author$
 *   Date: 3/29/2008
 **********************************************************************
 */
class cRedBlackTreeBranch
: public cRedBlackTreeBranchT
  <CHAR,cRedBlackTreeBranch,cBase>
{
public:
    typedef cRedBlackTreeBranchT
    <CHAR,cRedBlackTreeBranch,cBase> cExtends;
    CHAR m_leaf;
    /**
     **********************************************************************
     * Constructor: cRedBlackTreeBranch
     *
     *      Author: $author$
     *        Date: 3/29/2008
     **********************************************************************
     */
    cRedBlackTreeBranch(CHAR leaf)
    : m_leaf(leaf) 
    {}
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const tBranch& toBranch) const 
    {
        const tLeaf& toLeaf = toBranch.GetLeaf();
        int unequal = Compare(toLeaf);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const tLeaf& toLeaf) const 
    {
        const tLeaf& leaf = GetLeaf();
        int unequal = (leaf > toLeaf)?1:((leaf < toLeaf)?-1:0);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: Compare
     *
     *   Author: $author$
     *     Date: 3/28/2008
     **********************************************************************
     */
    virtual int Compare(const tLeaf& toLeaf, int length) const 
    {
        const tLeaf& leaf = GetLeaf();
        int unequal = (leaf > toLeaf)?1:((leaf < toLeaf)?-1:0);
        return unequal;
    }
    /**
     **********************************************************************
     * Function: GetLeaf
     *
     *   Author: $author$
     *     Date: 3/29/2008
     **********************************************************************
     */
    virtual CHAR& GetLeaf() const 
    { return (CHAR&)(m_leaf); }
};
/**
 **********************************************************************
 *  Class: cRedBlackTree
 *
 * Author: $author$
 *   Date: 3/29/2008
 **********************************************************************
 */
class cRedBlackTree
: public cRedBlackTreeT
  <CHAR,cRedBlackTreeBranch,cBase>
{
public:
    typedef cRedBlackTreeT
    <CHAR,cRedBlackTreeBranch,cBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cRedBlackTree
     *
     *      Author: $author$
     *        Date: 3/29/2008
     **********************************************************************
     */
    cRedBlackTree();
    /**
     **********************************************************************
     * Destructor: cRedBlackTree
     *
     *     Author: $author$
     *       Date: 3/29/2008
     **********************************************************************
     */
    virtual ~cRedBlackTree();
};
#endif /* _CREDBLACKTREE_HXX */
