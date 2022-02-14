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
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/31/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_HPP

#include "xos/app/console/protocol/tls/base/main_opt.hpp"
#include "xos/protocol/tls/protocol/version.hpp"

#include "xos/protocol/tls/pseudo/random/reader.hpp"
#include "xos/protocol/tls/gmt/unix/time.hpp"
#include "xos/protocol/tls/random/bytes.hpp"

#include "xos/protocol/tls/hello/random.hpp"
#include "xos/protocol/tls/session/identifier.hpp"
#include "xos/protocol/tls/cipher/suite.hpp"
#include "xos/protocol/tls/cipher/suites.hpp"
#include "xos/protocol/tls/compression/method.hpp"
#include "xos/protocol/tls/compression/methods.hpp"
#include "xos/protocol/tls/client/hello.hpp"

#include "xos/protocol/tls/premaster/secret/random.hpp"
#include "xos/protocol/tls/premaster/secret/message.hpp"
#include "xos/protocol/tls/pkcs1/encoded/message.hpp"
#include "xos/protocol/tls/pkcs1/encoded/premaster/secret.hpp"

#include "xos/protocol/tls/rsa/public_key.hpp"
#include "xos/protocol/tls/rsa/bn/public_key.hpp"
#include "xos/protocol/tls/rsa/gmp/public_key.hpp"
#include "xos/protocol/tls/rsa/implemented/public_key.hpp"
#include "xos/protocol/tls/encrypted/premaster/secret.hpp"

#include "xos/protocol/tls/rsa/private_key.hpp"
#include "xos/protocol/tls/rsa/bn/private_key.hpp"
#include "xos/protocol/tls/rsa/gmp/private_key.hpp"
#include "xos/protocol/tls/rsa/implemented/private_key.hpp"
#include "xos/protocol/tls/decrypted/premaster/secret.hpp"

#include "xos/protocol/tls/key/exchange/algorithm.hpp"
#include "xos/protocol/tls/client/key/exchange/message.hpp"

#include "xos/protocol/tls/handshake/message.hpp"

#include "talas/app/console/rsa/public_key.hpp"
#include "talas/app/console/rsa/private_key.hpp"

#define XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_PSEUDO_RANDOM_SECRET \
    "E5B62E66-8349-11EC-8C95-7F8924CBD8A2"

#define XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_PSEUDO_RANDOM_SEED \
    "ECBD992E-8349-11EC-9EC2-259E551AB68D"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace tls {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::tls::base::main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint()
    : run_(0), 
      secret_string_(XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_PSEUDO_RANDOM_SECRET), 
      seed_string_(XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_PSEUDO_RANDOM_SEED),
      cipher_suite_which_(xos::protocol::tls::cipher::suite::which_default), 
      cipher_suite_with_(xos::protocol::tls::cipher::suite::with_default),
      compression_method_which_(xos::protocol::tls::compression::method::which_default) {
        set_secret(secret_string());
        set_seed(seed_string());
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
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

    /// ...output_random_..._run
    virtual int default_output_random_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        if ((chars = (const char_t*)(this->secret().has_elements(length)))) {
            this->outln(chars, length);
        }
        return err;
    }
    virtual int default_output_random_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const char_t* chars = 0; size_t length = 0;
        if ((chars = (const char_t*)(this->seed().has_elements(length)))) {
            this->outln(chars, length);
        }
        return err;
    }

    /// ...output_protocol_version_run
    virtual int output_protocol_version_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::protocol::tls::protocol::version protocol_version = this->protocol_version();
        this->output_hex_run(protocol_version, argc, argv, env);
        return err;
    }

    /// output_get_..._run
    virtual int default_output_get_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        const byte_t *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0;
        if ((bytes = get_p(q, dmp1, dmq1, iqmp, length)) && (length)) {
            this->output_x(bytes, length, argc, argv, env);
            this->output_x(q, length, argc, argv, env);
            this->output_x(dmp1, length, argc, argv, env);
            this->output_x(dmq1, length, argc, argv, env);
            this->output_x(iqmp, length, argc, argv, env);
        }
        return err;
    }
    virtual int default_output_get_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        if ((bytes = get_exponent(length)) && (length)) {
            this->output_x(bytes, length, argc, argv, env);
            if ((bytes = get_modulus(length)) && (length)) {
                this->output_x(bytes, length, argc, argv, env);
            }
        }
        return err;
    }
    virtual int default_output_get_public_modulus_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        if ((bytes = get_modulus(length)) && (length)) {
            this->output_x(bytes, length, argc, argv, env);
        }
        return err;
    }
    virtual int default_output_get_public_exponent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        size_t length = 0;
        const byte_t *bytes = 0;
        if ((bytes = get_exponent(length)) && (length)) {
            this->output_x(bytes, length, argc, argv, env);
        }
        return err;
    }

    /// ...output_test_..._run
    virtual int default_output_test_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->output_x
        (::talas::app::console::rsa::rsa_private_p, 
         sizeof(::talas::app::console::rsa::rsa_private_p), argc, argv, env);
        this->output_x
        (::talas::app::console::rsa::rsa_private_q, 
         sizeof(::talas::app::console::rsa::rsa_private_q), argc, argv, env);
        this->output_x
        (::talas::app::console::rsa::rsa_private_dmp1, 
         sizeof(::talas::app::console::rsa::rsa_private_dmp1), argc, argv, env);
        this->output_x
        (::talas::app::console::rsa::rsa_private_dmq1, 
         sizeof(::talas::app::console::rsa::rsa_private_dmq1), argc, argv, env);
        this->output_x
        (::talas::app::console::rsa::rsa_private_iqmp, 
         sizeof(::talas::app::console::rsa::rsa_private_iqmp), argc, argv, env);
        return err;
    }
    virtual int default_output_test_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = default_output_test_public_exponent_run(argc, argv, env))) {
            if (!(err = default_output_test_public_modulus_run(argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int default_output_test_public_exponent_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->output_x
        (::talas::app::console::rsa::rsa_public_exponent, 
         sizeof(::talas::app::console::rsa::rsa_public_exponent), argc, argv, env);
        return err;
    }
    virtual int default_output_test_public_modulus_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        this->output_x
        (::talas::app::console::rsa::rsa_public_modulus, 
         sizeof(::talas::app::console::rsa::rsa_public_modulus), argc, argv, env);
        return err;
    }

    /// ...option...
    virtual int on_set_random_secret_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            ::talas::string_t& secret_string = this->set_secret_string(optarg);
            ::talas::byte_array_t& secret = this->secret();
            if (!(err = this->on_set_text_literal(secret, secret_string, argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int on_set_random_seed_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            ::talas::string_t& seed_string = this->set_seed_string(optarg);
            ::talas::byte_array_t& seed = this->seed();
            if (!(err = this->on_set_text_literal(seed, seed_string, argc, argv, env))) {
            }
        }
        return err;
    }
    virtual int on_set_private_key_option(const char_t* private_key, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        private_string_.assign(private_key);
        err = this->on_set_hex_literals(p_, q_, dmp1_, dmq1_, iqmp_, private_string_, argc, argv, env);
        err = this->set_get_literal_p(argc, argv, env);
        return err;
    }
    virtual int on_set_public_key_option(const char_t* public_key, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        public_string_.assign(public_key);
        err = this->on_set_hex_literals(exponent_, modulus_, public_string_, argc, argv, env);
        err = this->set_get_literal_exponent(argc, argv, env);
        err = this->set_get_literal_modulus(argc, argv, env);
        return err;
    }
    virtual int on_set_modulus_option(const char_t* modulus, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        modulus_string_.assign(modulus);
        err = this->on_set_hex_literal(modulus_, modulus_string_, argc, argv, env);
        err = this->set_get_literal_modulus(argc, argv, env);
        return err;
    }
    virtual int on_set_exponent_option(const char_t* exponent, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        exponent_string_.assign(exponent);
        err = this->on_set_hex_literal(exponent_, exponent_string_, argc, argv, env);
        err = this->set_get_literal_exponent(argc, argv, env);
        return err;
    }

    /// ...secret...
    virtual ::talas::string_t& set_secret_string(const char_t* to) {
        if ((to) && (to[0])) {
            secret_string_.assign(to);
        }
        return (::talas::string_t&)secret_string_;
    }
    virtual ::talas::string_t& secret_string() const {
        return (::talas::string_t&)secret_string_;
    }
    virtual ::talas::byte_array_t& set_secret(::talas::string_t& to) {
        const char_t* chars = 0; size_t length = 0;
        if ((chars = to.has_chars(length))) {
            set_secret(chars, length);
        }
        return (::talas::byte_array_t&)secret_;
    }
    virtual ::talas::byte_array_t& set_secret(const char_t* to, size_t length) {
        const byte_t* bytes = 0;
        if ((bytes = (const byte_t*)to) && (length)) {
            secret_.assign(bytes, length);
        }
        return (::talas::byte_array_t&)secret_;
    }
    virtual ::talas::byte_array_t& secret() const {
        return (::talas::byte_array_t&)secret_;
    }

    /// ...seed...
    virtual ::talas::string_t& set_seed_string(const char_t* to) {
        if ((to) && (to[0])) {
            seed_string_.assign(to);
        }
        return (::talas::string_t&)seed_string_;
    }
    virtual ::talas::string_t& seed_string() const {
        return (::talas::string_t&)seed_string_;
    }
    virtual ::talas::byte_array_t& set_seed(::talas::string_t& to) {
        const char_t* chars = 0; size_t length = 0;
        if ((chars = to.has_chars(length))) {
            set_seed(chars, length);
        }
        return (::talas::byte_array_t&)seed_;
    }
    virtual ::talas::byte_array_t& set_seed(const char_t* to, size_t length) {
        const byte_t* bytes = 0;
        if ((bytes = (const byte_t*)to) && (length)) {
            seed_.assign(bytes, length);
        }
        return (::talas::byte_array_t&)seed_;
    }
    virtual ::talas::byte_array_t& seed() const {
        return (::talas::byte_array_t&)seed_;
    }

    /// ...
    virtual xos::protocol::tls::protocol::version protocol_version() const {
        return (xos::protocol::tls::protocol::version&)protocol_version_;
    }
    virtual xos::protocol::tls::cipher::suite::which_t cipher_suite_which() const {
        return (xos::protocol::tls::cipher::suite::which_t&)cipher_suite_which_;
    }
    virtual xos::protocol::tls::cipher::suite::with_t cipher_suite_with() const {
        return (xos::protocol::tls::cipher::suite::with_t&)cipher_suite_with_;
    }
    virtual xos::protocol::tls::compression::method::which_t compression_method_which() const {
        return (xos::protocol::tls::compression::method::which_t&)compression_method_which_;
    }

    /// ...get_exponent
    const byte_t* (derives::*get_exponent_)(size_t &length);
    virtual const byte_t* get_exponent(size_t &length) {
        const byte_t* bytes = 0;
        if (get_exponent_) {
            bytes = (this->*get_exponent_)(length);
        } else {
            bytes = get_test_exponent(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_exponent(size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::talas::app::console::rsa::rsa_public_exponent);
        bytes = ::talas::app::console::rsa::rsa_public_exponent;
        return bytes;
    }
    virtual const byte_t* get_literal_exponent(size_t &length) {
        const byte_t* bytes = 0;
        length = exponent_.length();
        bytes = exponent_.elements();
        return bytes;
    }
    virtual int set_get_test_exponent(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_exponent_ = &derives::get_literal_exponent;
        return err;
    }
    virtual int set_get_literal_exponent(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_exponent_ = &derives::get_literal_exponent;
        return err;
    }

    /// ...get_modulus
    const byte_t* (derives::*get_modulus_)(size_t &length);
    virtual const byte_t* get_modulus(size_t &length) {
        const byte_t* bytes = 0;
        if (get_modulus_) {
            bytes = (this->*get_modulus_)(length);
        } else {
            bytes = get_test_modulus(length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_modulus(size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::talas::app::console::rsa::rsa_public_modulus);
        bytes = ::talas::app::console::rsa::rsa_public_modulus;
        return bytes;
    }
    virtual const byte_t* get_literal_modulus(size_t &length) {
        const byte_t* bytes = 0;
        length = modulus_.length();
        bytes = modulus_.elements();
        return bytes;;
    }
    virtual int set_get_test_modulus(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_modulus_ = &derives::get_test_modulus;
        return err;
    }
    virtual int set_get_literal_modulus(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_modulus_ = &derives::get_literal_modulus;
        return err;
    }

    /// ...get_p
    const byte_t* (derives::*get_p_)
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length);
    virtual const byte_t* get_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        if (get_p_) {
            bytes = (this->*get_p_)(q, dmp1, dmq1, iqmp, length);
        } else {
            bytes = get_test_p(q, dmp1, dmq1, iqmp, length);
        }
        return bytes;
    }
    virtual const byte_t* get_test_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        length = sizeof(::talas::app::console::rsa::rsa_private_p);
        bytes = ::talas::app::console::rsa::rsa_private_p;
        q = ::talas::app::console::rsa::rsa_private_q;
        dmp1 = ::talas::app::console::rsa::rsa_private_dmp1;
        dmq1 = ::talas::app::console::rsa::rsa_private_dmq1;
        iqmp = ::talas::app::console::rsa::rsa_private_iqmp;
        return bytes;
    }
    virtual const byte_t* get_literal_p
    (const byte_t *&q, const byte_t *&dmp1, 
     const byte_t *&dmq1, const byte_t *&iqmp, size_t &length) {
        const byte_t* bytes = 0;
        length = p_.length();
        bytes = p_.elements();
        q = q_.elements();
        dmp1 = dmp1_.elements();
        dmq1 = dmq1_.elements();
        iqmp = iqmp_.elements();
        return bytes;;
    }
    virtual int set_get_test_p(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_p_ = &derives::get_test_p;
        return err;
    }
    virtual int set_get_literal_p(int argc, char_t** argv, char_t** env) {
        int err = 0;
        get_p_ = &derives::get_literal_p;
        return err;
    }

protected:
    ::talas::string_t secret_string_, seed_string_;
    ::talas::byte_array_t secret_, seed_;
    xos::protocol::tls::protocol::version protocol_version_;
    xos::protocol::tls::cipher::suite::which_t cipher_suite_which_;
    xos::protocol::tls::cipher::suite::with_t cipher_suite_with_;
    xos::protocol::tls::compression::method::which_t compression_method_which_;
    ::talas::byte_array_t exponent_, modulus_, p_, q_, dmp1_, dmq1_, iqmp_;
    ::talas::string_t exponent_string_, modulus_string_, public_string_, private_string_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace tls
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_HPP
