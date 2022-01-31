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
///   Date: 1/30/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPT_HPP

#include "xos/app/console/talas/crypto/main.hpp"

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPT "secret"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTARG "[string]"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTUSE "pseudo random secret"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTVAL_S "s::"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTVAL_C 's'
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTION \
   {XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTARG_RESULT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTVAL_C}, \

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPT "seed"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTARG "[string]"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTUSE "pseudo random seed"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTVAL_S "e::"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTVAL_C 'e'
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTION \
   {XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTARG_RESULT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTVAL_C}, \

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPT "bytes"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTARG "[number]"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTUSE "pseudo random bytes"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTVAL_S "b::"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTVAL_C 'b'
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTION \
   {XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTARG_RESULT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTVAL_C}, \

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPT "output-file"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_OPTIONAL
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTARG "[string]"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTUSE "pseudo random output file"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTVAL_S "o::"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTVAL_C 'o'
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTION \
   {XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTARG_RESULT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTVAL_C}, \

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPT "file-input"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTARG ""
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTUSE "input from file"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTVAL_S "f"
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTVAL_C 'f'
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTION \
   {XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTARG_RESULT, \
    XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTVAL_C}, \

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTVAL_S \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTVAL_S \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTVAL_S \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTVAL_S \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTVAL_S \

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTION \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTION \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTION \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTION \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTION \

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPTIONS_CHARS \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPTIONS_CHARS_EXTEND \
   XOS_APP_CONSOLE_TALAS_CRYPTO_MAIN_OPTIONS_CHARS

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPTIONS_OPTIONS \
   XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPTIONS_OPTIONS_EXTEND \
   XOS_APP_CONSOLE_TALAS_CRYPTO_MAIN_OPTIONS_OPTIONS

#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_ARGS 0
#define XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_ARGV 0,

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace tls {
namespace pseudo {
namespace random {

/// class main_optt
template 
<class TExtends = xos::app::console::talas::crypto::main, 
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

    /// ...output_secret_run
    virtual int output_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_secret_run(argc, argv, env))) {
            int err2 = 0;
            err = output_secret_run(argc, argv, env);
            if ((err2 = after_output_secret_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_secret_run;
        return err;
    }
 
    /// ...output_seed_run
    virtual int output_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_seed_run(argc, argv, env))) {
            int err2 = 0;
            err = output_seed_run(argc, argv, env);
            if ((err2 = after_output_seed_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_seed_run;
        return err;
    }

    /// ...output_bytes_run
    virtual int output_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int before_output_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int after_output_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        return err;
    }
    virtual int all_output_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = before_output_bytes_run(argc, argv, env))) {
            int err2 = 0;
            err = output_bytes_run(argc, argv, env);
            if ((err2 = after_output_bytes_run(argc, argv, env))) {
                if (!(err)) err = err2;
            }
        }
        return err;
    }
    virtual int set_output_bytes_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        run_ = &derives::all_output_bytes_run;
        return err;
    }

    /// ...option...
    virtual int on_secret_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            err = set_output_secret_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* secret_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTUSE;
        optarg = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTARG;
        return chars;
    }
    virtual int on_seed_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            err = set_output_seed_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* seed_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTUSE;
        optarg = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTARG;
        return chars;
    }
    virtual int on_bytes_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
            err = set_output_bytes_run(argc, argv, env);
        }
        return err;
    }
    virtual const char_t* bytes_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTUSE;
        optarg = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTARG;
        return chars;
    }
    virtual int on_output_file_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual const char_t* output_file_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTUSE;
        optarg = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTARG;
        return chars;
    }
    virtual int on_file_input_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        } else {
        }
        return err;
    }
    virtual const char_t* file_input_option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTUSE;
        optarg = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTARG;
        return chars;
    }
    virtual int on_option
    (int optval, const char_t* optarg, const char_t* optname,
     int optind, int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTVAL_C:
            err = this->on_secret_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTVAL_C:
            err = this->on_seed_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTVAL_C:
            err = this->on_bytes_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTVAL_C:
            err = this->on_output_file_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTVAL_C:
            err = this->on_file_input_option(optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option(optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage(const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SECRET_OPTVAL_C:
            chars = this->secret_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_SEED_OPTVAL_C:
            chars = this->seed_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_BYTES_OPTVAL_C:
            chars = this->bytes_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OUTPUT_FILE_OPTVAL_C:
            chars = this->output_file_option_usage(optarg, longopt);
            break;
        case XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_FILE_INPUT_OPTVAL_C:
            chars = this->file_input_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
            break;
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        static const char_t* chars = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    /// ...argument...
    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_TALAS_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace random
} /// namespace pseudo
} /// namespace tls
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_TLS_PSEUDO_RANDOM_MAIN_OPT_HPP
