///////////////////////////////////////////////////////////////////////
// Copyright (c) 1988-2011 $organization$
//
// This software is provided by the author and contributors ``as is'' 
// and any express or implied warranties, including, but not limited to, 
// the implied warranties of merchantability and fitness for a particular 
// purpose are disclaimed. In no event shall the author or contributors 
// be liable for any direct, indirect, incidental, special, exemplary, 
// or consequential damages (including, but not limited to, procurement 
// of substitute goods or services; loss of use, data, or profits; or 
// business interruption) however caused and on any theory of liability, 
// whether in contract, strict liability, or tort (including negligence 
// or otherwise) arising in any way out of the use of this software, 
// even if advised of the possibility of such damage.
//
//   File: cThreadMain.hpp
//
// Author: $author$
//   Date: 6/20/2011
///////////////////////////////////////////////////////////////////////
#if !defined(_CTHREADMAIN_HPP) || defined(CTHREADMAIN_MEMBERS_ONLY)
#if !defined(_CTHREADMAIN_HPP) && !defined(CTHREADMAIN_MEMBERS_ONLY)
#define _CTHREADMAIN_HPP
#endif // !defined(_CTHREADMAIN_HPP) && !defined(CTHREADMAIN_MEMBERS_ONLY) 

#if !defined(CTHREADMAIN_MEMBERS_ONLY)
#include "cOptMain.hpp"
#include "cThread.hpp"
#include "cReference.hpp"
#include "cReferenced.hpp"
#include <vector>

#if defined(c_NAMESPACE)
namespace c_NAMESPACE {
#endif // defined(c_NAMESPACE) 

///////////////////////////////////////////////////////////////////////
// Typedef: cMainThreadExtend
//
//  Author: $author$
//    Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
typedef cThread
cMainThreadExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cMainThread
//
// Author: $author$
//   Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cMainThread
: public cMainThreadExtend
{
public:
    typedef cMainThreadExtend cExtends;

    int m_number;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cMainThread
    //
    //       Author: $author$
    //         Date: 6/21/2011
    ///////////////////////////////////////////////////////////////////////
    cMainThread
    (int number=0)
    : m_number(number)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/21/2011
    ///////////////////////////////////////////////////////////////////////
    virtual eError Run()
    {
        eError error = e_ERROR_NONE;
        c_DB_ALL("() thread[" << m_number << "]...");
        return error;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: DeleteInstance
    //
    //    Author: $author$
    //      Date: 6/21/2011
    ///////////////////////////////////////////////////////////////////////
    static eError DeleteInstance
    (cMainThread* thread)
    {
        eError error = e_ERROR_NONE;
        if ((thread))
        {
            thread->Destroy();
            delete thread;
        }
        return error;
    }
};

///////////////////////////////////////////////////////////////////////
// Typedef: cMainThreadReference
//
//  Author: $author$
//    Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
typedef cReferenceT<cMainThread,cReferenced>
cMainThreadReference;

///////////////////////////////////////////////////////////////////////
// Typedef: cMainThreadVector
//
//  Author: $author$
//    Date: 6/21/2011
///////////////////////////////////////////////////////////////////////
typedef std::vector<cMainThreadReference>
cMainThreadVector;

///////////////////////////////////////////////////////////////////////
// Typedef: cThreadMainExtend
//
//  Author: $author$
//    Date: 6/20/2011
///////////////////////////////////////////////////////////////////////
typedef cOptMain
cThreadMainExtend;
///////////////////////////////////////////////////////////////////////
//  Class: cThreadMain
//
// Author: $author$
//   Date: 6/20/2011
///////////////////////////////////////////////////////////////////////
class c_INSTANCE_CLASS cThreadMain
: public cThreadMainExtend
{
public:
    typedef cThreadMainExtend cExtends;

    cMainThreadVector m_threadVector;
    unsigned int m_threads;

    ///////////////////////////////////////////////////////////////////////
    //  Constructor: cThreadMain
    //
    //       Author: $author$
    //         Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    cThreadMain
    (unsigned int threads=1)
    : m_threads(threads)
    {
    }
    ///////////////////////////////////////////////////////////////////////
    //  Destructor: ~cThreadMain
    //
    //      Author: $author$
    //        Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual ~cThreadMain()
    {
    }
#else // !defined(CTHREADMAIN_MEMBERS_ONLY) 
#endif // !defined(CTHREADMAIN_MEMBERS_ONLY) 

    ///////////////////////////////////////////////////////////////////////
    //  Function: Run
    //
    //    Author: $author$
    //      Date: 6/20/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int Run
    (int argc,
     char_t** argv,
     char_t** env)
#if defined(CTHREADMAIN_MEMBER_FUNCS_INTERFACE)
    = 0;
#else // defined(CTHREADMAIN_MEMBER_FUNCS_INTERFACE) 
    {
        int err = 0;
#if !defined(CTHREADMAIN_MEMBER_FUNCS_IMPLEMENT)
        cMainThread* thread;
        unsigned int n;
        cMainThreadVector::iterator i;

        c_DB_ALL("() starting " << m_threads << " threads...");

        for (n = 0; (n < m_threads); n++)
        {
            if ((thread = new cMainThread(n)))
            {
                if (!(thread->Create()))
                {
                    cMainThreadReference threadRef(thread);
                    m_threadVector.push_back(threadRef);
                    continue;
                }
                delete thread;
                break;
            }
        }

        c_DB_ALL("() finishing " << n << " threads...");

        for (i = m_threadVector.begin(); i != m_threadVector.end(); i++)
        {
            cMainThreadReference& threadRef = (*i);

            if ((threadRef != 0))
                threadRef->Destroy();
        }
#else // !defined(CTHREADMAIN_MEMBER_FUNCS_IMPLEMENT) 
#endif // !defined(CTHREADMAIN_MEMBER_FUNCS_IMPLEMENT) 
        return err;
    }
#endif // defined(CTHREADMAIN_MEMBER_FUNCS_INTERFACE) 

#if !defined(CTHREADMAIN_MEMBERS_ONLY)
    ///////////////////////////////////////////////////////////////////////
    //  Function: OnOption
    //
    //    Author: $author$
    //      Date: 6/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual int OnOption
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc,
     char_t** argv,
     char_t** env)
    {
        int err = 0;
        int threads;
        switch(optval)
        {
        case 't':
            if (optarg)
            if (0 < (threads = atoi(optarg)))
                m_threads = threads;
            break;

        default:
            err = cExtends::OnOption
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: OptionUsage
    //
    //    Author: $author$
    //      Date: 6/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* OptionUsage
    (const char_t*& optarg, const struct option* longopt)
    {
        const char_t* chars = "";
        switch(longopt->val)
        {
        case 't':
            optarg = "{1..n}";
            break;

        default:
            chars = cExtends::OptionUsage(optarg, longopt);
        }
        return chars;
    }
    ///////////////////////////////////////////////////////////////////////
    //  Function: Options
    //
    //    Author: $author$
    //      Date: 6/22/2011
    ///////////////////////////////////////////////////////////////////////
    virtual const char_t* Options
    (const struct option*& longopts)
    {
        static const char* chars = "t:d:h";
        static struct option optstruct[]= {
            {"threads", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 't'},
            {"debug-levels", e_MAIN_OPT_ARGUMENT_REQUIRED, 0, 'd'},
            {"help", e_MAIN_OPT_ARGUMENT_NONE, 0, 'h'},
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }
};


#if defined(c_NAMESPACE)
}
#endif // defined(c_NAMESPACE) 

#else // !defined(CTHREADMAIN_MEMBERS_ONLY) 
#endif // !defined(CTHREADMAIN_MEMBERS_ONLY) 

#endif // !defined(_CTHREADMAIN_HPP) || defined(CTHREADMAIN_MEMBERS_ONLY) 
        

