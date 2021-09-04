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
 *   File: csyntaxnodetype.hxx
 *
 * Author: $author$
 *   Date: 8/3/2008
 **********************************************************************
 */
#ifndef _CSYNTAXNODETYPE_HXX
#define _CSYNTAXNODETYPE_HXX

/**
 **********************************************************************
 *   Enum:  eSyntaxNodeType
 *
 * Author: $author$
 *   Date: 8/3/2008
 **********************************************************************
 */
typedef int
eSyntaxNodeType;
enum
{
    e_SYNTAX_NODE_TYPE_NONE = 0,

    e_SYNTAX_NODE_TYPE_IDENTIFIER,

    e_SYNTAX_NODE_TYPE_LITERAL_CHAR,
    e_SYNTAX_NODE_TYPE_LITERAL_STRING,
    e_SYNTAX_NODE_TYPE_LITERAL_INTEGER,
    e_SYNTAX_NODE_TYPE_LITERAL_REAL,

    e_SYNTAX_NODE_TYPE_OP_EQ,
    e_SYNTAX_NODE_TYPE_OP_NE,
    e_SYNTAX_NODE_TYPE_OP_LE,
    e_SYNTAX_NODE_TYPE_OP_GE,
    e_SYNTAX_NODE_TYPE_OP_LT,
    e_SYNTAX_NODE_TYPE_OP_GT,

    e_SYNTAX_NODE_TYPE_OP_LNOT,
    e_SYNTAX_NODE_TYPE_OP_NOT,
    e_SYNTAX_NODE_TYPE_OP_POS,
    e_SYNTAX_NODE_TYPE_OP_NEG,
    e_SYNTAX_NODE_TYPE_OP_POW2,
    e_SYNTAX_NODE_TYPE_OP_ROO2,
    e_SYNTAX_NODE_TYPE_OP_LOG2,
    e_SYNTAX_NODE_TYPE_OP_EX,
    e_SYNTAX_NODE_TYPE_OP_LN,

    e_SYNTAX_NODE_TYPE_OP_LOR,
    e_SYNTAX_NODE_TYPE_OP_LAND,
    e_SYNTAX_NODE_TYPE_OP_LXOR,
    e_SYNTAX_NODE_TYPE_OP_OR,
    e_SYNTAX_NODE_TYPE_OP_AND,
    e_SYNTAX_NODE_TYPE_OP_XOR,
    e_SYNTAX_NODE_TYPE_OP_SHL,
    e_SYNTAX_NODE_TYPE_OP_SHR,

    e_SYNTAX_NODE_TYPE_OP_ADD,
    e_SYNTAX_NODE_TYPE_OP_SUB,
    e_SYNTAX_NODE_TYPE_OP_MUL,
    e_SYNTAX_NODE_TYPE_OP_DIV,
    e_SYNTAX_NODE_TYPE_OP_MOD,
    e_SYNTAX_NODE_TYPE_OP_QUO,
    e_SYNTAX_NODE_TYPE_OP_POW,
    e_SYNTAX_NODE_TYPE_OP_ROO,
    e_SYNTAX_NODE_TYPE_OP_LOG,

    e_SYNTAX_NODE_TYPE_OP_LCOMP,
    e_SYNTAX_NODE_TYPE_OP_COMP,
    e_SYNTAX_NODE_TYPE_OP_INC,
    e_SYNTAX_NODE_TYPE_OP_DEC,
    e_SYNTAX_NODE_TYPE_OP_SHL1,
    e_SYNTAX_NODE_TYPE_OP_SHR1,

    e_SYNTAX_NODE_TYPE_ASSIGN_EQ,
    e_SYNTAX_NODE_TYPE_ASSIGN_LOR,
    e_SYNTAX_NODE_TYPE_ASSIGN_LAND,
    e_SYNTAX_NODE_TYPE_ASSIGN_LXOR,
    e_SYNTAX_NODE_TYPE_ASSIGN_OR,
    e_SYNTAX_NODE_TYPE_ASSIGN_AND,
    e_SYNTAX_NODE_TYPE_ASSIGN_XOR,
    e_SYNTAX_NODE_TYPE_ASSIGN_SHL,
    e_SYNTAX_NODE_TYPE_ASSIGN_SHR,
    e_SYNTAX_NODE_TYPE_ASSIGN_ADD,
    e_SYNTAX_NODE_TYPE_ASSIGN_SUB,
    e_SYNTAX_NODE_TYPE_ASSIGN_MUL,
    e_SYNTAX_NODE_TYPE_ASSIGN_DIV,
    e_SYNTAX_NODE_TYPE_ASSIGN_MOD,
    e_SYNTAX_NODE_TYPE_ASSIGN_QUO,
    e_SYNTAX_NODE_TYPE_ASSIGN_POW,
    e_SYNTAX_NODE_TYPE_ASSIGN_ROO,
    e_SYNTAX_NODE_TYPE_ASSIGN_LOG,

    e_SYNTAX_NODE_TYPE_LITERAL_NEXT,
    e_SYNTAX_NODE_TYPE_LITERAL_FIRST = e_SYNTAX_NODE_TYPE_NONE,
    e_SYNTAX_NODE_TYPE_LITERAL_LAST = e_SYNTAX_NODE_TYPE_LITERAL_NEXT-1,
    e_SYNTAX_NODE_TYPE_LITERAL_COUNT = e_SYNTAX_NODE_TYPE_LITERAL_LAST-e_SYNTAX_NODE_TYPE_LITERAL_FIRST+1
};

#define e_SYNTAX_NODE_TYPE_NAME_NONE "NONE"

#define e_SYNTAX_NODE_TYPE_NAME_IDENTIFIER "IDENTIFIER"

#define e_SYNTAX_NODE_TYPE_LITERAL_NAME_CHAR "CHAR"
#define e_SYNTAX_NODE_TYPE_LITERAL_NAME_STRING "STRING"
#define e_SYNTAX_NODE_TYPE_LITERAL_NAME_INTEGER "INTEGER"
#define e_SYNTAX_NODE_TYPE_LITERAL_NAME_REAL "REAL"

#define e_SYNTAX_NODE_TYPE_OP_NAME_EQ "EQ"
#define e_SYNTAX_NODE_TYPE_OP_NAME_NE "NE"
#define e_SYNTAX_NODE_TYPE_OP_NAME_LE "LE"
#define e_SYNTAX_NODE_TYPE_OP_NAME_GE "GE"
#define e_SYNTAX_NODE_TYPE_OP_NAME_LT "LT"
#define e_SYNTAX_NODE_TYPE_OP_NAME_GT "GT"

#define e_SYNTAX_NODE_TYPE_OP_NAME_LNOT "LNOT"
#define e_SYNTAX_NODE_TYPE_OP_NAME_NOT "NOT"
#define e_SYNTAX_NODE_TYPE_OP_NAME_POS "POS"
#define e_SYNTAX_NODE_TYPE_OP_NAME_NEG "NEG"
#define e_SYNTAX_NODE_TYPE_OP_NAME_POW2 "POW2"
#define e_SYNTAX_NODE_TYPE_OP_NAME_ROO2 "ROO2"
#define e_SYNTAX_NODE_TYPE_OP_NAME_LOG2 "LOG2"
#define e_SYNTAX_NODE_TYPE_OP_NAME_EX "EX"
#define e_SYNTAX_NODE_TYPE_OP_NAME_LN "LN"

#define e_SYNTAX_NODE_TYPE_OP_NAME_LOR "LOR"
#define e_SYNTAX_NODE_TYPE_OP_NAME_LAND "LAND"
#define e_SYNTAX_NODE_TYPE_OP_NAME_LXOR "LXOR"
#define e_SYNTAX_NODE_TYPE_OP_NAME_OR "OR"
#define e_SYNTAX_NODE_TYPE_OP_NAME_AND "AND"
#define e_SYNTAX_NODE_TYPE_OP_NAME_XOR "XOR"
#define e_SYNTAX_NODE_TYPE_OP_NAME_SHL "SHL"
#define e_SYNTAX_NODE_TYPE_OP_NAME_SHR "SHR"

#define e_SYNTAX_NODE_TYPE_OP_NAME_ADD "ADD"
#define e_SYNTAX_NODE_TYPE_OP_NAME_SUB "SUB"
#define e_SYNTAX_NODE_TYPE_OP_NAME_MUL "MUL"
#define e_SYNTAX_NODE_TYPE_OP_NAME_DIV "DIV"
#define e_SYNTAX_NODE_TYPE_OP_NAME_MOD "MOD"
#define e_SYNTAX_NODE_TYPE_OP_NAME_QUO "QUO"
#define e_SYNTAX_NODE_TYPE_OP_NAME_POW "POW"
#define e_SYNTAX_NODE_TYPE_OP_NAME_ROO "ROO"
#define e_SYNTAX_NODE_TYPE_OP_NAME_LOG "LOG"

#define e_SYNTAX_NODE_TYPE_OP_NAME_LCOMP "LCOMP"
#define e_SYNTAX_NODE_TYPE_OP_NAME_COMP "COMP"
#define e_SYNTAX_NODE_TYPE_OP_NAME_INC "INC"
#define e_SYNTAX_NODE_TYPE_OP_NAME_DEC "DEC"
#define e_SYNTAX_NODE_TYPE_OP_NAME_SHL1 "SHL1"
#define e_SYNTAX_NODE_TYPE_OP_NAME_SHR1 "SHR1"

#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_EQ "EQ"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_LOR "LOR"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_LAND "LAND"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_LXOR "LXOR"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_OR "OR"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_AND "AND"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_XOR "XOR"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_SHL "SHL"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_SHR "SHR"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_ADD "ADD"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_SUB "SUB"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_MUL "MUL"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_DIV "DIV"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_MOD "MOD"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_QUO "QUO"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_POW "POW"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_ROO "ROO"
#define e_SYNTAX_NODE_TYPE_ASSIGN_NAME_LOG "LOG"

extern const char* 
g_syntax_node_type_name[e_SYNTAX_NODE_TYPE_LITERAL_COUNT];

#endif /* _CSYNTAXNODETYPE_HXX */
