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
///   Date: 2/10/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_TLS_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_TLS_CLIENT_MAIN_HPP

#include "xos/app/console/protocol/tls/client/main_opt.hpp"

#include "talas/app/console/rsa/public_key.hpp"
#include "talas/app/console/rsa/private_key.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace tls {
namespace client {

/// class maint
template 
<class TExtends = xos::app::console::protocol::tls::client::main_opt, 
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
    maint(): run_(0) {
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

    /// ...output_client_..._run
    virtual int output_client_hello_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::protocol::tls::gmt::unix::time gmt_unix_time;
        xos::protocol::tls::pseudo::random::reader pseudo_random_reader(this->secret_, this->seed_);
        xos::protocol::tls::random::bytes random_bytes(pseudo_random_reader);
        xos::protocol::tls::hello::random hello_random(pseudo_random_reader, gmt_unix_time, random_bytes);
        xos::protocol::tls::session::identifier session_id(pseudo_random_reader);

        xos::protocol::tls::cipher::suite cipher_suite(this->cipher_suite_which_, this->cipher_suite_with_);
        xos::protocol::tls::cipher::suites cipher_suites(cipher_suite);

        xos::protocol::tls::compression::method compression_method(this->compression_method_which_);
        xos::protocol::tls::compression::methods compression_methods(compression_method);

        xos::protocol::tls::client::hello client_hello
        (this->protocol_version_, hello_random, session_id, cipher_suites, compression_methods, pseudo_random_reader);
        xos::protocol::tls::handshake::message client_hello_handshake(client_hello); 

        this->output_hex_run(client_hello_handshake, argc, argv, env);
        return err;
    }
    virtual int output_client_hello_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::protocol::tls::gmt::unix::time gmt_unix_time;
        xos::protocol::tls::pseudo::random::reader pseudo_random_reader(this->secret_, this->seed_);
        xos::protocol::tls::random::bytes random_bytes(pseudo_random_reader);
        xos::protocol::tls::hello::random hello_random(pseudo_random_reader, gmt_unix_time, random_bytes);

        this->output_hex_run(hello_random, argc, argv, env);
        return err;
    }
    virtual int output_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        xos::protocol::tls::pseudo::random::reader pseudo_random_reader(this->secret_, this->seed_);
        xos::protocol::tls::premaster::secret::random premaster_secret_random(pseudo_random_reader);
        xos::protocol::tls::premaster::secret::message premaster_secret(this->protocol_version_, premaster_secret_random, pseudo_random_reader);
        
        this->output_hex_run(premaster_secret, argc, argv, env);
        return err;
    }
    virtual int output_encoded_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* modulus = 0; size_t modulus_length = 0;
        xos::crypto::pseudo::random::reader random_reader(0);
        xos::protocol::tls::pseudo::random::reader pseudo_random_reader(this->secret_, this->seed_);
        xos::protocol::tls::premaster::secret::random premaster_secret_random(pseudo_random_reader);
        xos::protocol::tls::premaster::secret::message premaster_secret(this->protocol_version_, premaster_secret_random, pseudo_random_reader);
        
        if ((modulus = this->get_modulus(modulus_length))) {
            const byte_t* exponent = 0; size_t exponent_length = 0;
            xos::protocol::tls::pkcs1::encoded::premaster::secret encoded_premaster_secret(modulus_length, premaster_secret, random_reader);

            this->output_hex_run(encoded_premaster_secret, argc, argv, env);
        }
        return err;
    }
    virtual int output_encrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* modulus = 0; size_t modulus_length = 0;
        xos::crypto::pseudo::random::reader random_reader(0);
        xos::protocol::tls::pseudo::random::reader pseudo_random_reader(this->secret_, this->seed_);
        xos::protocol::tls::premaster::secret::random premaster_secret_random(pseudo_random_reader);
        xos::protocol::tls::premaster::secret::message premaster_secret(this->protocol_version_, premaster_secret_random, pseudo_random_reader);
        
        if ((modulus = this->get_modulus(modulus_length))) {
            const byte_t* exponent = 0; size_t exponent_length = 0;
            xos::protocol::tls::pkcs1::encoded::premaster::secret encoded_premaster_secret(modulus_length, premaster_secret, random_reader);

            if ((exponent = this->get_exponent(exponent_length))) {
                const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0; size_t p_length = 0;
                xos::protocol::tls::rsa::implemented::public_key public_key(modulus, modulus_length, exponent, exponent_length);
                xos::protocol::tls::encrypted::premaster::secret encrypted_premaster_secret(public_key, encoded_premaster_secret);

                this->output_hex_run(encrypted_premaster_secret, argc, argv, env);
            }
        }
        return err;
    }
    virtual int output_decrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* modulus = 0; size_t modulus_length = 0;
        xos::protocol::tls::pseudo::random::reader pseudo_random_reader(this->secret_, this->seed_);
        xos::protocol::tls::premaster::secret::random premaster_secret_random(pseudo_random_reader);
        xos::protocol::tls::premaster::secret::message premaster_secret(this->protocol_version_, premaster_secret_random, pseudo_random_reader);
        
        if ((modulus = this->get_modulus(modulus_length))) {
            const byte_t* exponent = 0; size_t exponent_length = 0;
            xos::protocol::tls::pkcs1::encoded::premaster::secret encoded_premaster_secret(modulus_length, premaster_secret, pseudo_random_reader);

            if ((exponent = this->get_exponent(exponent_length))) {
                const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0; size_t p_length = 0;
                xos::protocol::tls::rsa::implemented::public_key public_key(modulus, modulus_length, exponent, exponent_length);
                xos::protocol::tls::encrypted::premaster::secret encrypted_premaster_secret(public_key, encoded_premaster_secret);

                if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length))) {
                    const byte_t *encrypted_premaster_secret_bytes = 0; size_t encrypted_premaster_secret_length = 0;
                    xos::protocol::tls::rsa::implemented::private_key private_key(p, q, dmp1, dmq1, iqmp, p_length);
                    
                    if ((encrypted_premaster_secret_bytes = encrypted_premaster_secret.has_elements(encrypted_premaster_secret_length))) {
                        xos::protocol::tls::decrypted::premaster::secret decrypted_premaster_secret(private_key, encrypted_premaster_secret);
                        this->output_hex_run(decrypted_premaster_secret, argc, argv, env);
                    }
                }
            }
        }
        return err;
    }
    virtual int output_client_key_exchange_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const byte_t* modulus = 0; size_t modulus_length = 0;
        xos::protocol::tls::pseudo::random::reader pseudo_random_reader(this->secret_, this->seed_);
        xos::protocol::tls::premaster::secret::random premaster_secret_random(pseudo_random_reader);
        xos::protocol::tls::premaster::secret::message premaster_secret(this->protocol_version_, premaster_secret_random, pseudo_random_reader);
        
        if ((modulus = this->get_modulus(modulus_length))) {
            const byte_t* exponent = 0; size_t exponent_length = 0;
            xos::protocol::tls::pkcs1::encoded::premaster::secret encoded_premaster_secret(modulus_length, premaster_secret, pseudo_random_reader);

            if ((exponent = this->get_exponent(exponent_length))) {
                const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0; size_t p_length = 0;
                xos::protocol::tls::rsa::implemented::public_key public_key(modulus, modulus_length, exponent, exponent_length);
                xos::protocol::tls::encrypted::premaster::secret encrypted_premaster_secret(public_key, encoded_premaster_secret);
                xos::protocol::tls::client::key::exchange::message client_key_exchange(encrypted_premaster_secret); 
                xos::protocol::tls::handshake::message client_key_exchange_handshake(client_key_exchange); 
                
                this->output_hex_run(client_key_exchange_handshake, argc, argv, env);
            }
        }
        return err;
    }

/*    /// ...output_test_..._run
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
    virtual int default_output_test_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = default_output_test_public_exponent_run(argc, argv, env))) {
            if (!(err = default_output_test_public_modulus_run(argc, argv, env))) {
            }
        }
        return err;
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
    ::talas::byte_array_t exponent_, modulus_, p_, q_, dmp1_, dmq1_, iqmp_;
    ::talas::string_t exponent_string_, modulus_string_, public_string_, private_string_;*/
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace tls
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_TLS_CLIENT_MAIN_HPP
