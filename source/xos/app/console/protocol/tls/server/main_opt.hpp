///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2022 $organization$
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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 2/15/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPT_HPP

#include "xos/app/console/protocol/tls/base/main.hpp"

#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPT "master-secret"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTARG "string"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTUSE "master secret"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTVAL_S "a:"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTVAL_C 'a'
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPT "client-hello-random"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTARG "string"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTUSE "client hello random"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTVAL_S "n:"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTVAL_C 'n'
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPT "decrypted-secret"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTARG "string"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTUSE "decrypted premaster secret"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTVAL_S "d:"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPT "encrypted-secret"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTARG "string"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTUSE "encrypted premaster secret"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTVAL_S "c:"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTVAL_C 'c'
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTION \
   {XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPT, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTARG_RESULT, \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTVAL_C}, \

#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTVAL_S \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTVAL_S \
   XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTVAL_S \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTVAL_S \

#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTION \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTION \
   XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTION \
    XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTION \

#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPTIONS_CHARS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPTIONS_OPTIONS_EXTEND \
    XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ARGS 0
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace tls {
namespace server {

/// class main_optt
template 
<class TExtends = xos::app::console::protocol::tls::base::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...output_master_secret_run
    virtual int output_master_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_master_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_master_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_master_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_master_secret_run(argc, argv, env))) {
            int err2 = 0;
            err = output_master_secret_run(argc, argv, env);
            if ((err2 = after_output_master_secret_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_master_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_master_secret_run;
        return err;
    }

    /// ...output_client_hello_random_run
    virtual int output_client_hello_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_client_hello_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_client_hello_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_client_hello_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_client_hello_random_run(argc, argv, env))) {
            int err2 = 0;
            err = output_client_hello_random_run(argc, argv, env);
            if ((err2 = after_output_client_hello_random_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_client_hello_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_client_hello_random_run;
        return err;
    }

    /// ...output_decrypted_premaster_secret_run
    virtual int output_decrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_decrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_decrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_decrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_decrypted_premaster_secret_run(argc, argv, env))) {
            int err2 = 0;
            err = output_decrypted_premaster_secret_run(argc, argv, env);
            if ((err2 = after_output_decrypted_premaster_secret_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_decrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_decrypted_premaster_secret_run;
        return err;
    }

    /// ...output_encrypted_premaster_secret_run
    virtual int output_encrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_encrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_encrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_encrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_encrypted_premaster_secret_run(argc, argv, env))) {
            int err2 = 0;
            err = output_encrypted_premaster_secret_run(argc, argv, env);
            if ((err2 = after_output_encrypted_premaster_secret_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_encrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_encrypted_premaster_secret_run;
        return err;
    }

    /// ...option...
    virtual int on_set_client_hello_random_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_master_secret_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_client_hello_random_option(optarg, optind, argc, argv, env))) {
                if (!(err = set_output_master_secret_run(argc, argv, env))) {
                }
            }
        } else {
        }
        return err;
    }
    virtual const char_t* master_secret_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTARG;
        return chars;
    }
    virtual int on_client_hello_random_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_client_hello_random_option(optarg, optind, argc, argv, env))) {
                if (!(err = set_output_client_hello_random_run(argc, argv, env))) {
                }
            }
        } else {
        }
        return err;
    }
    virtual const char_t* client_hello_random_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTARG;
        return chars;
    }
    virtual int on_set_encrypted_secret_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int on_decrypted_secret_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_encrypted_secret_option(optarg, optind, argc, argv, env))) {
                if (!(err = set_output_decrypted_premaster_secret_run(argc, argv, env))) {
                }
            }
        } else {
        }
        return err;
    }
    virtual const char_t* decrypted_secret_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTARG;
        return chars;
    }
    virtual int on_encrypted_secret_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if (!(err = on_set_encrypted_secret_option(optarg, optind, argc, argv, env))) {
                if (!(err = set_output_encrypted_premaster_secret_run(argc, argv, env))) {
                }
            }
        } else {
        }
        return err;
    }
    virtual const char_t* encrypted_secret_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTUSE;
        optarg = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTARG;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTVAL_C:
            err = this->on_master_secret_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTVAL_C:
            err = this->on_client_hello_random_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTVAL_C:
            err = this->on_decrypted_secret_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTVAL_C:
            err = this->on_encrypted_secret_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_MASTER_SECRET_OPTVAL_C:
            chars = this->master_secret_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_CLIENT_HELLO_RANDOM_OPTVAL_C:
            chars = this->client_hello_random_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_DECRYPTED_SECRET_OPTVAL_C:
            chars = this->decrypted_secret_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ENCRYPTED_SECRET_OPTVAL_C:
            chars = this->encrypted_secret_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace server
} /// namespace tls
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_OPT_HPP
