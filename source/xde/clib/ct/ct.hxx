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
 *   File: ct.hxx
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
#ifndef _CT_HXX
#define _CT_HXX

#include "ctinterface.hxx"
#include "ctfunctiontree.hxx"
#include "ctfunctionargument.hxx"
#include "ctfunction.hxx"
#include "ctvariable.hxx"
#include "ctexception.hxx"
#include "cbuffer.hxx"
#include "cbase.hxx"

#define DEFAULT_T_MARK_CHAR '%'

/**
 **********************************************************************
 *  Class: cT
 *
 * Author: $author$
 *   Date: 4/1/2008
 **********************************************************************
 */
class cT
: virtual public cTImplement,
  public cBase
{
public:
    typedef cTImplement cImplements;
    typedef cBase cExtends;
    typedef cT cDerives;

    char m_mark;
    int m_depth;

    cTFunctionItem *m_finalize;
    cTFunctionBranch *m_function_branch;
    cTFunctionTree m_function_tree;

    cTVariableTree m_variable_tree;

    cCharBuffer m_name;

    /**
     **********************************************************************
     * Constructor: cT
     *
     *      Author: $author$
     *        Date: 4/1/2008
     **********************************************************************
     */
    cT(char mark=DEFAULT_T_MARK_CHAR)
    : m_mark(mark),
      m_depth(0),
      m_finalize(0),
      m_function_branch(0) 
    {
    }
    /**
     **********************************************************************
     * Destructor: cT
     *
     *     Author: $author$
     *       Date: 4/1/2008
     **********************************************************************
     */
    virtual ~cT()
    {
    }

    /**
     **********************************************************************
     * Function: Initialize
     *
     *   Author: $author$
     *     Date: 4/2/2008
     **********************************************************************
     */
    virtual eError Initialize()
    {
        eError error;
        cTFunctionItem* functionItem;

        for (functionItem = m_function_list.GetFirstItem(); 
             functionItem; functionItem = functionItem->GetNextItem())
        {
            cTFunctionInterface& function = functionItem->GetFunction();

            if ((error = function.Initialize((*this))))
                return e_ERROR_FAILED;

            m_finalize = functionItem;
            m_function_tree.Add(function);
        }
        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: Finalize
     *
     *   Author: $author$
     *     Date: 4/2/2008
     **********************************************************************
     */
    virtual eError Finalize()
    {
        eError error = e_ERROR_NONE;
        eError error2;
        cTFunctionItem* functionItem;

        for (functionItem = m_finalize; functionItem; 
             functionItem = functionItem->GetPrevItem())
        {
            cTFunctionInterface& function = functionItem->GetFunction();

            if ((error2 = function.Finalize((*this))))
                error = e_ERROR_FAILED;
        }

        m_finalize = 0;
        return error;
    }

    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    virtual eError Expand
    (cCharStreamInterface &out, cCharStreamInterface &in)
    {
        eError error = e_ERROR_NOT_IMPLEMENTED;
        int count;
        int depth;
        char c;

        if ((count = Get(in,c)) < 0)

        if (count != -e_ERROR_ENDOF)
            return e_ERROR_GET;

        else return e_ERROR_NONE;

        depth=m_depth;
        m_depth=0;

        if ((error = Expand(c,out,in,c)))
            error = e_ERROR_EXPAND;

        m_depth=depth;
        return error;
    }
    /**
     **********************************************************************
     * Function: Expand
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    virtual eError Expand
    (char &nextchar, cCharStreamInterface& out, 
     cCharStreamInterface& in, char c)
    {
        enum eState
        {
            e_STATE_LOOK,
            e_STATE_MARK, 
            e_STATE_NAME, 
            e_STATE_COMMENTLN, 
            e_STATE_COMMENT, 
            e_STATE_COMMENT_END, 
            e_STATE_LITERAL,
            e_STATE_LITERAL_MARK,
            e_STATE_LITERAL_NEST, 
            e_STATE_LITERAL_UNNEST, 
            e_STATE_UNNEST,            
        };

        eState oldState = e_STATE_LOOK;
        eState state = e_STATE_LOOK;
        eError error = e_ERROR_NONE;
        eError result = e_ERROR_NONE;
        unsigned nest = 0;
        int count;

        do
        {
            switch(state)
            {
            case e_STATE_LOOK:
                switch(c)
                {
                case ',':
                    if (m_depth>0)
                    {
                        nextchar = c;
                        return result;
                    }
                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                    break;

                case ')':
                    if (m_depth>0)
                        state = e_STATE_UNNEST;
                    else 
                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                    break;

                default:
                    if (c == m_mark)
                        state = e_STATE_MARK;
                    else 
                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_MARK:
                switch(c)
                {
                case '#':
                case '\\':
                    oldState = e_STATE_LOOK;
                    state = e_STATE_COMMENTLN;
                    break;

                case '/':
                    oldState = e_STATE_LOOK;
                    state = e_STATE_COMMENT;
                    break;

                case '(':
                    state = e_STATE_LITERAL;
                    break;

                default:
                    if (c == m_mark)
                    {
                        if ((count = out.Put(c)) < 1)
                            return e_ERROR_PUT;

                        state = e_STATE_LOOK;
                    }
                    else
                    {
                        if ((count = m_name.Clear()) < 0)
                            return e_ERROR_CLEAR;

                        if ((count = m_name.Put(c)) < 1)
                           return e_ERROR_PUT;

                        state = e_STATE_NAME;
                    }
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_LITERAL:
                // '%' '(' .* ?
                switch(c)
                {
                case ')':
                    // '%' '(' .* ')'
                    state = e_STATE_LITERAL_UNNEST;
                    break;

                default:
                    if (c == m_mark)
                        // '%' '(' .* '%'
                        state = e_STATE_LITERAL_MARK;
                    else
                    // '%' '(' .* ?
                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_LITERAL_MARK:
                // '%' '(' .* '%' ?
                switch(c)
                {
                case '#':
                case '\\':
                    // '%' '(' .* '%' ('#' | '\\')
                    oldState = e_STATE_LITERAL;
                    state = e_STATE_COMMENTLN;
                    break;

                case '/':
                    // '%' '(' .* '%' '/'
                    oldState = e_STATE_LITERAL;
                    state = e_STATE_COMMENT;
                    break;

                case '(':
                    // '%' '(' .* '%' '('
                    if ((count = out.Put(m_mark)) < 1)
                        return e_ERROR_PUT;

                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;

                    nest++;
                    state = e_STATE_LITERAL;
                    break;

                case ')':
                    // '%' '(' .* '%' ')'
                    if ((count = out.Put(m_mark)) < 1)
                        return e_ERROR_PUT;

                    state = e_STATE_LITERAL_UNNEST;
                    break;

                default:
                    if (c == m_mark)
                        // '%' '(' .* '%' '%'
                        state = e_STATE_LITERAL;
                    else
                    // '%' '(' .* '%' ?
                    state = e_STATE_LITERAL_NEST;

                    if ((count = out.Put(m_mark)) < 1)
                        return e_ERROR_PUT;

                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_LITERAL_NEST:
                // '%' '(' .* '%' .+ ?
                switch(c)
                {
                case '(':
                    // '%' '(' .* '%' .+ '('
                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;

                    nest++;
                    state = e_STATE_LITERAL;
                    break;

                case ')':
                    // '%' '(' .* '%' .+ ')'
                    state = e_STATE_LITERAL_UNNEST;
                    break;

                default:
                    if (c == m_mark)
                        // '%' '(' .* '%' .+ '%'
                        state = e_STATE_LITERAL;

                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_LITERAL_UNNEST:
                // '%' '(' .+ ')' ?
                if (c == m_mark)
                // '%' '(' .+ ')' '%'
                if (nest > 0)
                    --nest;
                else
                {
                    state = e_STATE_LOOK;

                    if ((count = Get(in,c)) < 1)
                        error = e_ERROR_GET;
                    break;
                }

                if ((count = out.Put(')')) < 1)
                     return e_ERROR_PUT;

                if (c != ')')
                {
                    // '%' '(' .+ ')' ?
                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;

                    state = e_STATE_LITERAL;
                }

                if ((count = Get(in,c)) < 1)
                     error = e_ERROR_GET;
                break;

            case e_STATE_COMMENTLN:
                switch(c)
                {
                case '\n':
                    state = oldState;
                    break;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_COMMENT:
                switch(c)
                {
                case '/':
                    state = e_STATE_COMMENT_END;
                    break;
                }
                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_COMMENT_END:
                if (c == m_mark)
                    state = oldState;
                else
                if (c != '/')
                    state = e_STATE_COMMENT;

                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            case e_STATE_NAME:
                switch(c)
                {
                case '(':
                    state = e_STATE_LOOK;

                    if ((error = ExpandArguments(c,out,in)))
                    if (error == e_ERROR_BREAK)
                    {
                        nextchar = c;
                        return error;
                    }
                    break;

                default:
                    if (c == m_mark)
                    {
                        state = e_STATE_LOOK;
                        error = ExpandReference(c,out,in);
                    }
                    else
                    {
                        if ((count = m_name.Put(c)) < 1)
                            return e_ERROR_PUT;

                        else if ((count = Get(in,c)) < 1)
                                error = e_ERROR_GET;
                    }
                }
                break;

            case e_STATE_UNNEST:
                if (c == m_mark)
                {
                    nextchar = c;
                    return error;
                }

                if ((count = out.Put(')')) < 1)
                     return e_ERROR_PUT;

                else if (c != ')')
                {
                    state = e_STATE_LOOK;

                    if ((count = out.Put(c)) < 1)
                        return e_ERROR_PUT;
                }

                if ((count = Get(in,c)) < 1)
                    error = e_ERROR_GET;
                break;

            default:
                return e_ERROR_EXPAND;
            }
        }
        while(!error);

        nextchar = c;

        return result;
    }
    /**
     **********************************************************************
     * Function: ExpandArguments
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError ExpandArguments
    (char &nextchar, cCharStreamInterface& out, cCharStreamInterface& in)
    {
        eError error;
        eError result;
        cCharBuffer function;
        cTFunctionArgumentList args;
        cTFunctionArgument* arg;
        const char* name;
        int count;

        result = e_ERROR_NONE;

        if (1 > (count = Get(in,nextchar)))
            return e_ERROR_GET;

        if (!(name = m_name.GetBuffer()))
            return e_ERROR_GET_BUFFER;

        if (0 > (count = function.Write(name)))
            return e_ERROR_WRITE;

        if (!(name = function.GetBuffer()))
            return e_ERROR_GET_BUFFER;

        m_depth++;

        do
        {
            if (!(arg = new cTFunctionArgument))
                break;

            args.AddItem(*arg);

            if ((error = Expand(nextchar, *arg, in, nextchar)))
            {
                if (error != e_ERROR_BREAK)
                    break;

                error = e_ERROR_NONE;
            }

            if ((count = arg->Seek(0)) < 0)
            {
                error = e_ERROR_SEEK;
                break;
            }

            if (nextchar == m_mark)
                break;

            if ((count = Get(in,nextchar)) < 1)
            {
                error = e_ERROR_GET;
                break;
            }
        }
        while(!error);

        --m_depth;

        if (error)
            result=error;

        else
        {
            if ((error = ExpandFunction(out,args,name)))
            if (error != e_ERROR_BREAK)
                 error = e_ERROR_EXPAND;
            else
            {
                error = e_ERROR_NONE;
                result = e_ERROR_BREAK;
            }

            if (!error)
            if ((count = Get(in,nextchar)) < 1)
                error = e_ERROR_GET;
        }

        if ((error = args.Clear()))
            result = e_ERROR_CLEAR;

        return result;
    }
    /**
     **********************************************************************
     * Function: ExpandReference
     *
     *   Author: $author$
     *     Date: 7/7/2003
     **********************************************************************
     */
    virtual eError ExpandReference
    (char &nextchar, cCharStreamInterface& out, cCharStreamInterface& in)
    {
        eError error;
        int count;
        const char* name;

        if (!(name = m_name.GetBuffer()))
            return e_ERROR_GET_BUFFER;

        if ((error = ExpandVariable(out, name)))
            return error;

        if (0 > (count = Get(in,nextchar)))
            error = e_ERROR_GET;

        return error;
    }
    /**
     **********************************************************************
     * Function: ExpandFunction
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError ExpandFunction
    (cCharStreamInterface &out, 
     const cTFunctionArgumentList& args, const char* name)
    {
        cTFunctionInterface *function;

        if ((function = FindFunction(name)))
            return function->Expand(out, (*this), args);

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: ExpandVariable
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual eError ExpandVariable
    (cCharStreamInterface& out, const char* name)
    {
        cTVariableInterface *variable;
        const char* value;
        int count;

        if ((variable = FindVariable(name)))
        if ((value = variable->GetValue()))
        if (0 > (count = out.Write(value)))
            return e_ERROR_WRITE;

        return e_ERROR_NONE;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual cTVariableInterface *SetVariable
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1)
    {
        eError error;
        cTVariable *variable;

        if (!(variable = m_variable_tree.Find(name, namelen)))
        if ((error = m_variable_tree.AddNew
            (variable, name, namelen, value, valuelen)))
            return 0;

        if ((error = variable->SetValue(value, valuelen)))
            return 0;

        return variable;
    }
    /**
     **********************************************************************
     * Function: 
     *
     *   Author: $author$
     *     Date: 8/4/2003
     **********************************************************************
     */
    virtual cTVariableInterface* GetVariable
    (const char *name, int namelen=-1,
     const char *value=0, int valuelen=-1)
    {
        eError error;
        cTVariable *variable;

        if (!(variable = m_variable_tree.Find(name, namelen)))
        if ((error = m_variable_tree.AddNew
            (variable, name, namelen, value, valuelen)))
            return 0;

        return variable;
    }
    /**
     **********************************************************************
     * Function: FindVariable
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    inline cTVariableInterface*
    FindVariable(const char* name, int namelen=-1) const
    {
        return m_variable_tree.Find(name, namelen);
    }
    /**
     **********************************************************************
     * Function: FindFunction
     *
     *   Author: $author$
     *     Date: 8/3/2003
     **********************************************************************
     */
    virtual cTFunctionInterface*
    FindFunction(const char *name, int namelen=-1) const
    {
        return m_function_tree.Find(name, namelen);
    }
    /**
     **********************************************************************
     * Function: GetFirstFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cTFunctionInterface* GetFirstFunction()
    {
        cTFunctionInterface* function = 0;
        cTFunctionBranch* branch;
        
        if ((m_function_branch = (branch = m_function_tree.GetFirst())))
            function = &branch->m_function;

        return function;
    }
    /**
     **********************************************************************
     * Function: GetNextFunction
     *
     *   Author: $author$
     *     Date: 8/3/2005
     **********************************************************************
     */
    virtual cTFunctionInterface* GetNextFunction()
    {
        cTFunctionInterface* function = 0;
        cTFunctionBranch* branch;
        
        if (m_function_branch)
        if ((m_function_branch = (branch = m_function_tree.GetNext(m_function_branch))))
            function = &branch->m_function;

        return function;
    }
    /**
     **********************************************************************
     * Function: Get
     *
     *   Author: $author$
     *     Date: 9/26/2005
     **********************************************************************
     */
    virtual int Get
    (cCharStreamInterface &in, char &c) const
    {
        int count = in.Get(c);
        //printf("%c", c);
        return count;
    }
};

#endif /* _CT_HXX */
