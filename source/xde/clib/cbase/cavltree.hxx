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
 *   File: cavltree.hxx
 *
 * Author: $author$
 *   Date: 3/28/2008
 **********************************************************************
 */
#ifndef _CAVLTREE_HXX
#define _CAVLTREE_HXX

#include "cbinarytree.hxx"

#undef CDB_CLASS
#define CDB_CLASS "cAVLTreeBranchT"
/**
 **********************************************************************
 *  Class: cAVLTreeBranchT
 *
 * Author: $author$
 *   Date: 7/7/2003
 **********************************************************************
 */
template 
<class TLeaf,
 class TDerives,
 class TExtends=cBase>

class cAVLTreeBranchT
: public cBinaryTreeBranchT
  <TLeaf,TDerives,TExtends>
{
public:
    typedef cBinaryTreeBranchT
    <TLeaf,TDerives,TExtends> cExtends;

    int m_depth;

    /**
     **********************************************************************
     * Constructor: cAVLTreeBranchT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cAVLTreeBranchT
    (int depth=1, TDerives *tree=0, 
     TDerives *leftBranch=0, TDerives *rightBranch=0) 
    : cExtends(tree,leftBranch,rightBranch),
      m_depth(depth)
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cAVLTreeBranchT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cAVLTreeBranchT()
    {
    }
};
#undef CDB_CLASS

#undef CDB_CLASS
#define CDB_CLASS "cAVLTreeT"
/**
 **********************************************************************
 *  Class: cAVLTreeT
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

class cAVLTreeT
: public cBinaryTreeT
  <TLeaf,TBranch,TDerives,TExtends>
{
public:
    typedef cBinaryTreeT
    <TLeaf,TBranch,TDerives,TExtends> cExtends;

    /**
     **********************************************************************
     * Constructor: cAVLTreeT
     *
     *      Author: $author$
     *        Date: 7/7/2003
     **********************************************************************
     */
    cAVLTreeT(TBranch *root=0) 
    : cExtends(root) 
    {
    }
    /**
     **********************************************************************
     * Destructor: ~cAVLTreeT
     *
     *     Author: $author$
     *       Date: 7/7/2003
     **********************************************************************
     */
    virtual ~cAVLTreeT()
    {
    }

    /**
     **********************************************************************
     * Function: Insert
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Insert an item into the tree and return the root.
     *
     **********************************************************************
     */
    TBranch *Insert(TBranch *branch)
    {
        branch->m_leftBranch=0;
        branch->m_rightBranch=0;
        return CTHIS m_root=Inserted(CTHIS m_root,branch);
    }
    /**
     **********************************************************************
     * Function: Delete
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Delete an item from the tree and return the root.
     *
     **********************************************************************
     */
    TBranch *Delete(TBranch *branch)
    {
        return CTHIS m_root=Deleted(CTHIS m_root,branch);
    }

protected:

    /**
     **********************************************************************
     * Function: Inserted
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform recursive AVL insertion of an item into the
     * current subtree. Return the new root of the subtree.
     * 
     **********************************************************************
     */
    TBranch *Inserted(TBranch *tree,TBranch *branch)
    {
        if (tree==0)
            return branch;

        if (branch!=0)
        if (branch->Compare(*tree)<0)
        {
            tree->m_leftBranch=Inserted(tree->m_leftBranch,branch);
            tree->m_leftBranch->m_tree=tree;
            if (Depth(tree->m_leftBranch)-Depth(tree->m_rightBranch)>1)
            {
                if (Depth(tree->m_leftBranch->m_rightBranch)
                    >Depth(tree->m_leftBranch->m_leftBranch))
                    tree->m_leftBranch=Left(tree->m_leftBranch);
                return Right(tree);
            }
            else tree->m_depth=tree->m_leftBranch->m_depth+1;
        }
        else
        {
            tree->m_rightBranch=Inserted(tree->m_rightBranch,branch);
            tree->m_rightBranch->m_tree=tree;
            if (Depth(tree->m_rightBranch)-Depth(tree->m_leftBranch)>1)
            {
                if (Depth(tree->m_rightBranch->m_leftBranch)
                    >Depth(tree->m_rightBranch->m_rightBranch))
                    tree->m_rightBranch=Right(tree->m_rightBranch);
                return Left(tree);
            }
            else tree->m_depth=tree->m_rightBranch->m_depth+1;
        }

        return tree;
    }
    /**
     **********************************************************************
     * Function: Deleted
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform recursive AVL deletion of an item from the
     * current subtree. Return the new root of the subtree.
     *
     **********************************************************************
     */
    TBranch *Deleted(TBranch *tree,TBranch *branch)
    {
        int c;

        if ((tree==0)||(branch==0))
            return tree;

        if ((c=branch->Compare(*tree))>0)
        {
            tree->m_rightBranch=Deleted(tree->m_rightBranch,branch);
            if (Depth(tree->m_leftBranch)-Depth(tree->m_rightBranch)>1)
            {
                if (Depth(tree->m_leftBranch->m_rightBranch)
                    >Depth(tree->m_leftBranch->m_leftBranch))
                    tree->m_leftBranch=Left(tree->m_leftBranch);
                tree=Right(tree);
            }
            else tree->m_depth=NewDepth(tree);
        }
        else if (c<0)
        {
            tree->m_leftBranch=Deleted(tree->m_leftBranch,branch);
            if (Depth(tree->m_rightBranch)-Depth(tree->m_leftBranch)>1)
            {
                if (Depth(tree->m_rightBranch->m_leftBranch)
                    >Depth(tree->m_rightBranch->m_rightBranch))
                    tree->m_rightBranch=Right(tree->m_rightBranch);
                tree=Left(tree);
            }
            else tree->m_depth=NewDepth(tree);
        }
        else if (branch->m_depth>1)
        {
            if (Depth(branch->m_rightBranch)>Depth(branch->m_leftBranch))
                tree=Least(&branch->m_rightBranch);
            else tree=Greatest(&branch->m_leftBranch);
            tree->m_depth=NewDepth(branch);
            if ((tree->m_leftBranch=branch->m_leftBranch)!=0)
                tree->m_leftBranch->m_tree=tree;
            if ((tree->m_rightBranch=branch->m_rightBranch)!=0)
                tree->m_rightBranch->m_tree=tree;
        }
        else tree=0;

        return tree;
    }
    /**
     **********************************************************************
     * Function: Least
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Recusively raise the least item in the subtree to
     * the top of the tree.
     *
     **********************************************************************
     */
    TBranch *Least(TBranch **tree)
    {
        TBranch *t;

        if ((*tree)->m_leftBranch!=0)
        {
            t=Least(&(*tree)->m_leftBranch);
            if (Depth((*tree)->m_rightBranch)-Depth((*tree)->m_leftBranch)>1)
            {
                if (Depth((*tree)->m_rightBranch->m_leftBranch)
                    >Depth((*tree)->m_rightBranch->m_rightBranch))
                    (*tree)->m_rightBranch=Right((*tree)->m_rightBranch);
                *tree=Left(*tree);
            }
            else (*tree)->m_depth=NewDepth(*tree);
        }
        else if ((*tree)->m_rightBranch!=0)
        {
            t=*tree;
            *tree=t->m_rightBranch;
        }
        else
        {
            t=*tree;
            *tree=0;
        }

        return t;
    }
    /**
     **********************************************************************
     * Function: Greatest
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Recusively raise the greatest item in the subtree to
     * the top of the tree.
     *
     **********************************************************************
     */
    TBranch *Greatest(TBranch **tree)
    {
        TBranch *t;

        if ((*tree)->m_rightBranch!=0)
        {
            t=Greatest(&(*tree)->m_rightBranch);
            if (Depth((*tree)->m_leftBranch)-Depth((*tree)->m_rightBranch)>1)
            {
                if (Depth((*tree)->m_leftBranch->m_rightBranch)
                    >Depth((*tree)->m_leftBranch->m_leftBranch))
                    (*tree)->m_leftBranch=Left((*tree)->m_leftBranch);
                *tree=Right(*tree);
            }
            else (*tree)->m_depth=NewDepth(*tree);
        }
        else if ((*tree)->m_leftBranch!=0)
        {
            t=*tree;
            *tree=t->m_leftBranch;
        }
        else
        {
            t=*tree;
            *tree=0;
        }

        return t;
    }
    /**
     **********************************************************************
     * Function: Left
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform AVL rotation left to adjust the tree.
     *
     **********************************************************************
     */
    TBranch *Left(TBranch *tree)
    {
        TBranch *rightBranch;

        if (tree)
        if ((rightBranch=tree->m_rightBranch))
        {
            if ((tree->m_rightBranch=rightBranch->m_leftBranch))
                tree->m_rightBranch->m_tree=tree;

            tree->m_depth=Depth(tree->m_leftBranch)+1;

            if (Depth(tree->m_rightBranch)>=tree->m_depth)
                tree->m_depth=tree->m_rightBranch->m_depth+1;

            rightBranch->m_depth=tree->m_depth+1;
            rightBranch->m_leftBranch=tree;
            rightBranch->m_tree=tree->m_tree;
            tree->m_tree=rightBranch;

            return rightBranch;
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: Right
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Perform AVL rotation right to adjust the tree.
     *
     **********************************************************************
     */
    TBranch *Right(TBranch *tree)
    {
        TBranch *leftBranch;

        if (tree)
        if ((leftBranch=tree->m_leftBranch))
        {
            if ((tree->m_leftBranch=leftBranch->m_rightBranch))
                tree->m_leftBranch->m_tree=tree;

            tree->m_depth=Depth(tree->m_rightBranch)+1;

            if (Depth(tree->m_leftBranch)>=tree->m_depth)
                tree->m_depth=tree->m_leftBranch->m_depth+1;

            leftBranch->m_depth=tree->m_depth+1;
            leftBranch->m_rightBranch=tree;
            leftBranch->m_tree=tree->m_tree;
            tree->m_tree=leftBranch;

            return leftBranch;
        }

        return 0;
    }
    /**
     **********************************************************************
     * Function: NewDepth
     *
     *   Author: $author$
     *     Date: 7/7/2003
     *
     * Return the new depth of tree.
     *
     **********************************************************************
     */
    int NewDepth(TBranch *tree)
    {
        int ld,gd;

        if (tree!=0)
        if ((ld=Depth(tree->m_leftBranch))
            >(gd=Depth(tree->m_rightBranch)))
            return ld+1;
        else return gd+1;

        return 0;
    }
    /**
     **********************************************************************
     * Function: Depth
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    int Depth(TBranch *tree) const
    {
        if (tree)
        if (tree->m_depth>0)
            return tree->m_depth;
        else return 1;

        return 0;
    }
};
#undef CDB_CLASS

/**
 **********************************************************************
 *  Class: cAVLTreeBranch
 *
 * Author: $author$
 *   Date: 3/28/2008
 **********************************************************************
 */
class cAVLTreeBranch
: public cAVLTreeBranchT<CHAR,cAVLTreeBranch,cBase>
{
public:
    typedef cAVLTreeBranchT<CHAR,cAVLTreeBranch,cBase> cExtends;
    CHAR m_leaf;
    /**
     **********************************************************************
     * Constructor: cAVLTreeBranch
     *
     *      Author: $author$
     *        Date: 3/29/2008
     **********************************************************************
     */
    cAVLTreeBranch(CHAR leaf)
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
    {return (CHAR&)(m_leaf);}
};

/**
 **********************************************************************
 *  Class: cAVLTree
 *
 * Author: $author$
 *   Date: 3/28/2008
 **********************************************************************
 */
class cAVLTree
: public cAVLTreeT<CHAR,cAVLTreeBranch,cBase>
{
public:
    typedef cAVLTreeT<CHAR,cAVLTreeBranch,cBase> cExtends;
    /**
     **********************************************************************
     * Constructor: cAVLTree
     *
     *      Author: $author$
     *        Date: 3/29/2008
     **********************************************************************
     */
    cAVLTree();
    /**
     **********************************************************************
     * Destructor: cAVLTree
     *
     *     Author: $author$
     *       Date: 3/29/2008
     **********************************************************************
     */
    virtual ~cAVLTree();
};
#endif /* _CAVLTREE_HXX */
