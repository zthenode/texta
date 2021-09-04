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
 *   File: csyntaxnodetype.cxx
 *
 * Author: $author$
 *   Date: 8/3/2008
 **********************************************************************
 */
#include "csyntaxnodetype.hxx"
/**
 **********************************************************************
 *   Enum:  eSyntaxNodeType
 *
 * Author: $author$
 *   Date: 8/3/2008
 **********************************************************************
 */
const char* g_syntax_node_type_name[e_SYNTAX_NODE_TYPE_LITERAL_COUNT] = 
{
    e_SYNTAX_NODE_TYPE_NAME_NONE,

    e_SYNTAX_NODE_TYPE_NAME_IDENTIFIER,

    e_SYNTAX_NODE_TYPE_LITERAL_NAME_CHAR,
    e_SYNTAX_NODE_TYPE_LITERAL_NAME_STRING,
    e_SYNTAX_NODE_TYPE_LITERAL_NAME_INTEGER,
    e_SYNTAX_NODE_TYPE_LITERAL_NAME_REAL,

    e_SYNTAX_NODE_TYPE_OP_NAME_EQ,
    e_SYNTAX_NODE_TYPE_OP_NAME_NE,
    e_SYNTAX_NODE_TYPE_OP_NAME_LE,
    e_SYNTAX_NODE_TYPE_OP_NAME_GE,
    e_SYNTAX_NODE_TYPE_OP_NAME_LT,
    e_SYNTAX_NODE_TYPE_OP_NAME_GT,

    e_SYNTAX_NODE_TYPE_OP_NAME_LNOT,
    e_SYNTAX_NODE_TYPE_OP_NAME_NOT,
    e_SYNTAX_NODE_TYPE_OP_NAME_POS,
    e_SYNTAX_NODE_TYPE_OP_NAME_NEG,
    e_SYNTAX_NODE_TYPE_OP_NAME_POW2,
    e_SYNTAX_NODE_TYPE_OP_NAME_ROO2,
    e_SYNTAX_NODE_TYPE_OP_NAME_LOG2,
    e_SYNTAX_NODE_TYPE_OP_NAME_EX,
    e_SYNTAX_NODE_TYPE_OP_NAME_LN,

    e_SYNTAX_NODE_TYPE_OP_NAME_LOR,
    e_SYNTAX_NODE_TYPE_OP_NAME_LAND,
    e_SYNTAX_NODE_TYPE_OP_NAME_LXOR,
    e_SYNTAX_NODE_TYPE_OP_NAME_OR,
    e_SYNTAX_NODE_TYPE_OP_NAME_AND,
    e_SYNTAX_NODE_TYPE_OP_NAME_XOR,
    e_SYNTAX_NODE_TYPE_OP_NAME_SHL,
    e_SYNTAX_NODE_TYPE_OP_NAME_SHR,

    e_SYNTAX_NODE_TYPE_OP_NAME_ADD,
    e_SYNTAX_NODE_TYPE_OP_NAME_SUB,
    e_SYNTAX_NODE_TYPE_OP_NAME_MUL,
    e_SYNTAX_NODE_TYPE_OP_NAME_DIV,
    e_SYNTAX_NODE_TYPE_OP_NAME_MOD,
    e_SYNTAX_NODE_TYPE_OP_NAME_QUO,
    e_SYNTAX_NODE_TYPE_OP_NAME_POW,
    e_SYNTAX_NODE_TYPE_OP_NAME_ROO,
    e_SYNTAX_NODE_TYPE_OP_NAME_LOG,

    e_SYNTAX_NODE_TYPE_OP_NAME_LCOMP,
    e_SYNTAX_NODE_TYPE_OP_NAME_COMP,
    e_SYNTAX_NODE_TYPE_OP_NAME_INC,
    e_SYNTAX_NODE_TYPE_OP_NAME_DEC,
    e_SYNTAX_NODE_TYPE_OP_NAME_SHL1,
    e_SYNTAX_NODE_TYPE_OP_NAME_SHR1,

    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_EQ,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_LOR,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_LAND,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_LXOR,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_OR,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_AND,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_XOR
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_SHL,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_SHR,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_ADD,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_SUB,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_MUL,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_DIV,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_MOD,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_QUO,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_POW,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_ROO,
    e_SYNTAX_NODE_TYPE_ASSIGN_NAME_LOG
};
