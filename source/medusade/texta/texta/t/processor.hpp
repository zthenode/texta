///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: processor.hpp
///
/// Author: $author$
///   Date: 4/14/2016, 7/22/2022
///////////////////////////////////////////////////////////////////////
#ifndef _TEXTA_T_PROCESSOR_HPP
#define _TEXTA_T_PROCESSOR_HPP

#include "texta/t/function.hpp"
#include "texta/t/function_tree.hpp"
#include "texta/t/function_list.hpp"
#include "texta/t/function_argument.hpp"
#include "texta/t/function_argument_list.hpp"
#include "texta/t/variable.hpp"
#include "texta/t/variable_tree.hpp"
#include "texta/t/variable_list.hpp"
#include "texta/io/logger.hpp"
#include "texta/io/writer.hpp"
#include "texta/io/reader.hpp"

#define TEXTA_T_PROCESSOR_MARK '%'

namespace texta {
namespace t {

typedef variable parameter;
typedef variable_list parameter_list;
typedef variable_branch parameter_branch;
typedef variable_tree parameter_tree;

class _EXPORT_CLASS processor;
typedef texta::implement_base processor_observer_implements;
///////////////////////////////////////////////////////////////////////
///  Class: processor_observer
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS processor_observer: virtual public processor_observer_implements {
public:
    typedef processor_observer_implements Implements;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    enum exception {
        exception_none = 0,
        exception_failed,
        exception_exit
    };
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual void on_processor_exception(processor& p, const exception& e) {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef processor_observer processor_implements;
typedef texta::base processor_extends;
///////////////////////////////////////////////////////////////////////
///  Class: processor
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS processor
: virtual public processor_implements, public processor_extends {
public:
    typedef processor_implements Implements;
    typedef processor_extends Extends;
    typedef processor Derives;

    typedef t::parameter parameter;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    processor(processor_observer& observer)
    : mark_(TEXTA_T_PROCESSOR_MARK),
      depth_(0),
      observer_(observer) {
    }
    processor()
    : mark_(TEXTA_T_PROCESSOR_MARK),
      depth_(0),
      observer_(*this) {
    }
    virtual ~processor() {
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand(output& out, input& in) {
        bool success = true;
        try {
            size_t count = 0;
            char c = 0;

            if (0 > (count = in.read(&c, 1))) {
                return false;
            } else {
                if (0 < (count)) {
                    size_t depth = depth_;
                    depth_ = 0;
                    success = expand(c, out, in, c);
                    depth_ = depth;
                }
            }
        } catch (const exception& e) {
            TEXTA_LOG_MESSAGE_DEBUG("...caught exception e = " << e);
            observer_.on_processor_exception(*this, e);
        }
        return success;
    }
    virtual bool exit() {
        exception e = exception_exit;
        TEXTA_LOG_MESSAGE_DEBUG("...throwing exception e = exception_exit...");
        throw (e);
        return true;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand(char& nextchar, output& out, input& in, char c) {
        enum state_t {
            STATE_LOOK,
            STATE_MARK,
            STATE_NAME,
            STATE_COMMENTLN,
            STATE_COMMENT,
            STATE_COMMENT_END,
            STATE_LITERAL,
            STATE_LITERAL_MARK,
            STATE_LITERAL_NEST,
            STATE_LITERAL_UNNEST,
            STATE_UNNEST,
        };
        state_t oldState = STATE_LOOK;
        state_t state = STATE_LOOK;
        bool success = true;
        bool result = true;
        size_t nest = 0;
        size_t count = 0;

        do {
            switch(state) {
            case STATE_LOOK:
                switch(c) {
                case ',':
                    if (depth_ > 0) {
                        nextchar = c;
                        return result;
                    }
                    if ((count = out.write(&c, 1)) < 1)
                        return false;
                    break;

                case ')':
                    if (depth_ > 0) {
                        state = STATE_UNNEST;
                    } else {
                        if ((count = out.write(&c, 1)) < 1)
                            return false;
                    }
                    break;

                default:
                    if (c == mark_) {
                        state = STATE_MARK;
                    } else {
                        if ((count = out.write(&c, 1)) < 1)
                            return false;
                    }
                }
                if ((count = in.read(&c, 1)) < 1)
                    success = false;
                break;

            case STATE_MARK:
                switch(c) {
                case '#':
                case '\\':
                    oldState = STATE_LOOK;
                    state = STATE_COMMENTLN;
                    break;

                case '/':
                    oldState = STATE_LOOK;
                    state = STATE_COMMENT;
                    break;

                case '(':
                    state = STATE_LITERAL;
                    break;

                default:
                    if (c == mark_) {
                        if ((count = out.write(&c, 1)) < 1)
                            return false;
                        state = STATE_LOOK;
                    } else {
                        name_.assign(&c, 1);
                        state = STATE_NAME;
                    }
                }
                if ((count = in.read(&c, 1)) < 1)
                    success = false;
                break;

            case STATE_LITERAL:
                // '%' '(' .* ?
                switch(c) {
                case ')':
                    // '%' '(' .* ')'
                    state = STATE_LITERAL_UNNEST;
                    break;

                default:
                    if (c == mark_) {
                        // '%' '(' .* '%'
                        state = STATE_LITERAL_MARK;
                    } else {
                    // '%' '(' .* ?
                    if ((count = out.write(&c, 1)) < 1)
                        return false;
                    }
                }
                if ((count = in.read(&c, 1)) < 1)
                    success = false;
                break;

            case STATE_LITERAL_MARK:
                // '%' '(' .* '%' ?
                switch(c) {
                case '#':
                case '\\':
                    // '%' '(' .* '%' ('#' | '\\')
                    oldState = STATE_LITERAL;
                    state = STATE_COMMENTLN;
                    break;

                case '/':
                    // '%' '(' .* '%' '/'
                    oldState = STATE_LITERAL;
                    state = STATE_COMMENT;
                    break;

                case '(':
                    // '%' '(' .* '%' '('
                    if ((count = out.write(&mark_, 1)) < 1)
                        return false;
                    if ((count = out.write(&c, 1)) < 1)
                        return false;
                    nest++;
                    state = STATE_LITERAL;
                    break;

                case ')':
                    // '%' '(' .* '%' ')'
                    if ((count = out.write(&mark_, 1)) < 1)
                        return false;
                    state = STATE_LITERAL_UNNEST;
                    break;

                default:
                    if (c == mark_) {
                        // '%' '(' .* '%' '%'
                        state = STATE_LITERAL;
                    } else {
                    // '%' '(' .* '%' ?
                    state = STATE_LITERAL_NEST;
                    }
                    if ((count = out.write(&mark_, 1)) < 1)
                        return false;
                    if ((count = out.write(&c, 1)) < 1)
                        return false;
                }
                if ((count = in.read(&c, 1)) < 1)
                    success = false;
                break;

            case STATE_LITERAL_NEST:
                // '%' '(' .* '%' .+ ?
                switch(c) {
                case '(':
                    // '%' '(' .* '%' .+ '('
                    if ((count = out.write(&c, 1)) < 1)
                        return false;
                    nest++;
                    state = STATE_LITERAL;
                    break;

                case ')':
                    // '%' '(' .* '%' .+ ')'
                    state = STATE_LITERAL_UNNEST;
                    break;

                default:
                    if (c == mark_) {
                        // '%' '(' .* '%' .+ '%'
                        state = STATE_LITERAL;
                    }
                    if ((count = out.write(&c, 1)) < 1)
                        return false;
                }
                if ((count = in.read(&c, 1)) < 1)
                    success = false;
                break;

            case STATE_LITERAL_UNNEST:
                // '%' '(' .+ ')' ?
                if (c == mark_) {
                    // '%' '(' .+ ')' '%'
                    if (nest > 0) {
                        --nest;
                    } else {
                        state = STATE_LOOK;

                        if ((count = in.read(&c, 1)) < 1)
                            success = false;
                        break;
                    }
                }

                if ((count = put(out, ')')) < 1)
                     return false;

                if (c != ')') {
                    // '%' '(' .+ ')' ?
                    if ((count = out.write(&c, 1)) < 1)
                        return false;

                    state = STATE_LITERAL;
                }

                if ((count = in.read(&c, 1)) < 1)
                     success = false;
                break;

            case STATE_COMMENTLN:
                switch(c) {
                case '\n':
                    state = oldState;
                    break;
                }
                if ((count = in.read(&c, 1)) < 1)
                    success = false;
                break;

            case STATE_COMMENT:
                switch(c) {
                case '/':
                    state = STATE_COMMENT_END;
                    break;
                }
                if ((count = in.read(&c, 1)) < 1)
                    success = false;
                break;

            case STATE_COMMENT_END:
                if (c == mark_) {
                    state = oldState;
                } else {
                    if (c != '/')
                        state = STATE_COMMENT;
                }
                if ((count = in.read(&c, 1)) < 1)
                    success = false;
                break;

            case STATE_NAME:
                switch(c) {
                case '(': {
                    string name(name_);
                    bool failed = false;
                    state = STATE_LOOK;
                    TEXTA_LOG_MESSAGE_DEBUG("expand_arguments(c, out, in, name = \"" << name << "\")...");
                    if ((success = expand_arguments(failed, c, out, in, name))) {
                        TEXTA_LOG_MESSAGE_DEBUG("...expand_arguments(c, out, in, name = \"" << name << "\")");
                    } else {
                        if ((failed)) {
                            TEXTA_LOG_ERROR("...failed on expand_arguments(c, out, in, name = \"" << name << "\")");
                        } else {
                            TEXTA_LOG_MESSAGE_DEBUG("...expand_arguments(c, out, in, name = \"" << name << "\")");
                        }
                    }
                    break; }

                default:
                    if (c == mark_) {
                        bool failed = false;
                        state = STATE_LOOK;
                        TEXTA_LOG_MESSAGE_DEBUG("expand_reference(c, out, in, name_ = \"" << name_ << "\")...");
                        if ((success = expand_reference(failed, c, out, in, name_))) {
                            TEXTA_LOG_MESSAGE_DEBUG("...expand_reference(c, out, in, name_ = \"" << name_ << "\")");
                        } else {
                            if ((failed)) {
                                TEXTA_LOG_ERROR("...failed on expand_reference(c, out, in, name_ = \"" << name_ << "\")");
                            } else {
                                TEXTA_LOG_MESSAGE_DEBUG("...expand_reference(c, out, in, name_ = \"" << name_ << "\")");
                            }
                        }
                    } else {
                        name_.append(&c, 1);
                        if ((count = in.read(&c, 1)) < 1)
                            success = false;
                    }
                }
                break;

            case STATE_UNNEST:
                if (c == mark_) {
                    nextchar = c;
                    return success;
                }

                if ((count = put(out, ')')) < 1)
                     return false;

                if (c != ')') {
                    state = STATE_LOOK;
                    if ((count = out.write(&c, 1)) < 1)
                        return false;
                }

                if ((count = in.read(&c, 1)) < 1)
                    success = false;
                break;

            default:
                return false;
            }
        } while(success);

        nextchar = c;
        return result;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand_arguments
    (bool& failed, char& nextchar, output& out, input& in, const string& name) {
        bool success = true;
        size_t count = 0;
        failed = true;
        if (1 > (count = in.read(&nextchar, 1))) {
            success = false;
        } else {
            function_argument_list args;
            ++depth_;
            do {
                function_argument* arg = 0;
                if ((arg = new function_argument)) {
                    args.queue(arg->item());
                    if (!(success = expand(nextchar, *arg, in, nextchar)))
                        break;
                    TEXTA_LOG_MESSAGE_DEBUG("...arg = \"" << *arg << "\"");
                    if (nextchar == mark_)
                        break;
                    if (1 > (count = in.read(&nextchar, 1))) {
                        success = false;
                    }
                } else {
                    success = false;
                }
            } while (success);
            --depth_;
            if (success) {
                TEXTA_LOG_MESSAGE_DEBUG("expand_function(out, args, name = \"" << name << "\")...");
                if ((success = expand_function(out, args, name))) {
                    TEXTA_LOG_MESSAGE_DEBUG("...expand_function(out, args, name = \"" << name << "\")");
                } else {
                    TEXTA_LOG_ERROR("...failed on expand_function(out, args, name = \"" << name << "\")...");
                }
                if (1 > (count = in.read(&nextchar, 1))) {
                    failed = (0 > count);
                    success = false;
                }
            }
        }
        return success;
    }
    virtual bool expand_reference
    (bool& failed, char& nextchar, output& out, input& in, const string& name) {
        bool success = true;
        size_t count = 0;
        failed = true;
        TEXTA_LOG_MESSAGE_DEBUG("expand_variable(out, name = \"" << name << "\")...");
        if ((success = expand_variable(out, name))) {
            TEXTA_LOG_MESSAGE_DEBUG("...expand_variable(out, name = \"" << name << "\")");
        } else {
            TEXTA_LOG_ERROR("...failed on expand_variable(out, name = \"" << name << "\")...");
        }
        if (1 > (count = in.read(&nextchar, 1))) {
            failed = (0 > count);
            success = false;
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool expand_function
    (output& out, const function_argument_list& args, const string& name) {
        bool result = true;
        function* f = 0;
        TEXTA_LOG_MESSAGE_DEBUG("functions_.find(name = \"" << name << "\")...");
        if ((f = functions_.find_function(name))) {
            TEXTA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(f) << " = functions_.find(name = \"" << name << "\")");

            TEXTA_LOG_MESSAGE_DEBUG(pointer_to_string(f) << "->expand(out, *this, args)...");
            if ((f->expand(out, *this, args))) {
                TEXTA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(f) << "->expand(out, *this, args)");
            } else {
                TEXTA_LOG_ERROR("...failed on " << pointer_to_string(f) << "->expand(out, *this, args)");
            }
        } else {
            TEXTA_LOG_MESSAGE_DEBUG("...failed 0 on functions_.find(name = \"" << name << "\")");
        }
        return result;
    }
    virtual bool expand_variable(output& out, const string& name) {
        bool result = true;
        variable* v = 0;
        TEXTA_LOG_MESSAGE_DEBUG("variables_.get_variable(name = \"" << name << "\")...");
        if ((v = variables_.get_variable(name))) {
            TEXTA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(v) << " = variables_.get_variable(name = \"" << name << "\")");
            out.write(v->value());
        } else {
            TEXTA_LOG_ERROR("...failed 0 = variables_.get_variable(name = \"" << name << "\")");
        }
        return result;
    }

public:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool push_variable_expand(const string& name, input& in) {
        variable_value* v = 0;
        TEXTA_LOG_MESSAGE_DEBUG("new variable_value()...");
        if ((v = new variable_value())) {
            TEXTA_LOG_MESSAGE_DEBUG("..." << pointer_to_string(v) << " = new variable_value()");
            if ((expand(*v, in))) {
                if ((variables_.push_value(name, *v))) {
                    return true;
                }
                TEXTA_LOG_MESSAGE_DEBUG("delete " << pointer_to_string(v) << "...");
                delete v;
                TEXTA_LOG_MESSAGE_DEBUG("...delete " << pointer_to_string(v) << "");
            }
        } else {
            TEXTA_LOG_ERROR("...failed 0 on new value()");
        }
        return false;
    }
    virtual bool push_variable(const string& name, const string& to) {
        if ((variables_.push_value(name, to))) {
            return true;
        }
        return false;
    }
    virtual bool pop_variable(const string& name) {
        if ((variables_.pop_value(name))) {
            return true;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_variable(const string& name, const string& to) {
        if ((variables_.set_value(name, to))) {
            return true;
        }
        return false;
    }
    virtual variable* find_variable(const string& name) {
        variable* v = 0;
        v = variables_.find_variable(name);
        return v;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool set_parameter(const string& name, const string& to) {
        if ((parameters_.set_value(name, to))) {
            return true;
        }
        return false;
    }
    virtual parameter* first_parameter() const {
        parameter_branch *b = 0;
        if ((b = parameters_.first())) {
            return &b->leaf().variable();
        }
        return 0;
    }
    virtual parameter* next_parameter(parameter &f) const {
        parameter_branch *b = 0;
        if ((b = parameters_.next(f.branch()))) {
            return &b->leaf().variable();
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual function* find_function(const string& name) const {
        return functions_.find_function(name);
    }
    virtual function* first_function() const {
        function_branch *b = 0;
        if ((b = functions_.first())) {
            return &b->leaf();
        }
        return 0;
    }
    virtual function* next_function(function &f) const {
        function_branch *b = 0;
        if ((b = functions_.next(f.branch()))) {
            return &b->leaf();
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init() {
        bool success = true;
        if (!(init(function_list::the_list(), functions_))) {
            success = false;
        }
        return success;
    }
    virtual bool fini() {
        bool success = true;
        if (!(fini(function_list::the_list(), functions_))) {
            success = false;
        }
        return success;
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool init(function_list& l, function_tree& t) {
        bool success = true;

        for (function_item* i = l.first(); i; i = i->next()) {
            function& f = i->what();

            TEXTA_LOG_MESSAGE_DEBUG("function(\"" << f.name() << "\")->init()...");
            if ((f.init(*this))) {
                TEXTA_LOG_MESSAGE_DEBUG("...function(\"" << f.name() << "\")->init()");
            } else {

                TEXTA_LOG_MESSAGE_ERROR("...failed on function(\"" << f.name() << "\")->init()");
                for (i = i->prev(); i; i = i->prev()) {
                    function& f = i->what();

                    TEXTA_LOG_MESSAGE_DEBUG("function(\"" << f.name() << "\")->fini()...");
                    if ((f.fini(*this))) {
                        TEXTA_LOG_MESSAGE_DEBUG("...function(\"" << f.name() << "\")->fini()");
                    } else {
                        TEXTA_LOG_MESSAGE_ERROR("...failed on function(\"" << f.name() << "\")->fini()");
                    }
                }
                success = false;
                break;
            }
        }
        if ((success)) {
            for (function_item* i = l.first(); i; i = i->next()) {
                function& f = i->what();
                t.insert(f.branch());
            }
        }
        return success;
    }
    virtual bool fini(function_list& l, function_tree& t) {
        bool success = true;

        for (function_item* i = l.last(); i; i = i->prev()) {
            function& f = i->what();

            TEXTA_LOG_MESSAGE_DEBUG("function(\"" << f.name() << "\")->fini()...");
            if ((f.fini(*this))) {
                TEXTA_LOG_MESSAGE_DEBUG("...function(\"" << f.name() << "\")->fini()");
            } else {
                TEXTA_LOG_MESSAGE_ERROR("...failed on function(\"" << f.name() << "\")->fini()");
                success = false;
            }
        }
        t.set_root(0);
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual ssize_t get(input& in, char c) {
        ssize_t count = in.read(&c, 1);
        return count;
    }
    virtual ssize_t put(output& out, char c) {
        ssize_t count = out.write(&c, 1);
        return count;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
    char mark_;
    size_t depth_;
    processor_observer& observer_;
    function_tree functions_;
    variable_tree variables_;
    parameter_tree parameters_;
    string name_;
};

} // namespace t 
} // namespace texta 

#endif // _TEXTA_T_PROCESSOR_HPP 
