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
 *   File: credblacktree.cxx
 *
 * Author: $author$
 *   Date: 3/28/2008
 **********************************************************************
 */
#include "credblacktree.hxx"

//#define CREDBLACKTREE_TEST

/**
 **********************************************************************
 *  Class: cRedBlackTree
 *
 * Author: $author$
 *   Date: 3/29/2008
 **********************************************************************
 */
#if defined(CREDBLACKTREE_TEST) 
/* test cRedBlackTree
 */
cRedBlackTreeBranch g_rbA('A');
cRedBlackTreeBranch g_rbB('B');
cRedBlackTreeBranch g_rbC('C');
cRedBlackTree g_rb;
#endif /* defined(CREDBLACKTREE_TEST) */
/**
 **********************************************************************
 * Constructor: cRedBlackTree::cRedBlackTree
 *
 *      Author: $author$
 *        Date: 3/29/2008
 **********************************************************************
 */
cRedBlackTree::cRedBlackTree() 
{
#if defined(CREDBLACKTREE_TEST) 
/* test cRedBlackTree
 */
    Insert(&g_rbA);
    Insert(&g_rbB);
    Insert(&g_rbC);
#endif /* defined(CREDBLACKTREE_TEST) */
}
/**
 **********************************************************************
 * Destructor: cRedBlackTree::~cRedBlackTree
 *
 *     Author: $author$
 *       Date: 3/29/2008
 **********************************************************************
 */
cRedBlackTree::~cRedBlackTree()
{
#if defined(CREDBLACKTREE_TEST) 
/* test cRedBlackTree
 */
    Delete(&g_rbA);
    Delete(&g_rbB);
    Delete(&g_rbC);
#endif /* defined(CREDBLACKTREE_TEST) */
}
