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
 *   File: cavltree.cxx
 *
 * Author: $author$
 *   Date: 3/28/2008
 **********************************************************************
 */
#include "cavltree.hxx"

//#define CAVLTREE_TEST

/**
 **********************************************************************
 *  Class: cAVLTree
 *
 * Author: $author$
 *   Date: 3/29/2008
 **********************************************************************
 */
#if defined(CAVLTREE_TEST) 
/* test cAVLTree
 */
cAVLTreeBranch g_avlA('A');
cAVLTreeBranch g_avlB('B');
cAVLTreeBranch g_avlC('C');
cAVLTree g_avlT;
#endif /* defined(CAVLTREE_TEST) */
/**
 **********************************************************************
 * Constructor: cAVLTree::cAVLTree
 *
 *      Author: $author$
 *        Date: 3/29/2008
 **********************************************************************
 */
cAVLTree::cAVLTree() 
{
#if defined(CAVLTREE_TEST) 
/* test cAVLTree
 */
    Insert(&g_avlA);
    Insert(&g_avlB);
    Insert(&g_avlC);
#endif /* defined(CAVLTREE_TEST) */
}
/**
 **********************************************************************
 * Destructor: cAVLTree::~cAVLTree
 *
 *     Author: $author$
 *       Date: 3/29/2008
 **********************************************************************
 */
cAVLTree::~cAVLTree()
{
#if defined(CAVLTREE_TEST) 
/* test cAVLTree
 */
    Delete(&g_avlA);
    Delete(&g_avlB);
    Delete(&g_avlC);
#endif /* defined(CAVLTREE_TEST) */
}
