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
///   Date: 2/15/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_HPP

#include "xos/app/console/protocol/tls/server/main_opt.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace tls {
namespace server {

/// class maint
template 
<class TExtends = xos::app::console::protocol::tls::server::main_opt, 
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

    /// ...output_master_secret_run
    virtual int output_master_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::protocol::tls::hello::random* p_client_hello_random = 0;

        if ((p_client_hello_random = this->get_client_hello_random())) {
            const xos::protocol::tls::hello::random& client_hello_random = *p_client_hello_random;
            const byte_t* client_hello_random_bytes = 0; size_t client_hello_random_length = 0;

            ///this->output_hex_run(client_hello_random, argc, argv, env);
            ///this->outln();
            if ((client_hello_random_bytes = client_hello_random.has_elements(client_hello_random_length))) {
                ///const ::talas::byte_array_t& master_secret_seed = this->master_secret_seed();
                ///xos::protocol::tls::pseudo::random::reader reader(client_hello_random, master_secret_seed);
                const xos::protocol::tls::encrypted::premaster::secret* p_encrypted_premaster_secret = 0;

                if ((p_encrypted_premaster_secret = this->get_encrypted_premaster_secret())) {
                    const xos::protocol::tls::encrypted::premaster::secret& encrypted_premaster_secret = *p_encrypted_premaster_secret;
                    const byte_t *encrypted_premaster_secret_bytes = 0; size_t encrypted_premaster_secret_length = 0;

                    if ((encrypted_premaster_secret_bytes 
                        = encrypted_premaster_secret.has_elements(encrypted_premaster_secret_length))) {
                        const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0; size_t p_length = 0;
                        
                        if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length))) {
                            xos::protocol::tls::rsa::implemented::private_key private_key(p, q, dmp1, dmq1, iqmp, p_length);
                            xos::protocol::tls::decrypted::premaster::secret decrypted_premaster_secret(private_key, encrypted_premaster_secret);
                            const byte_t* decrypted_premaster_secret_bytes = 0; size_t decrypted_premaster_secret_length = 0;

                            ///this->output_hex_run(decrypted_premaster_secret, argc, argv, env);
                            ///this->outln();
                            if ((decrypted_premaster_secret_bytes 
                                 = decrypted_premaster_secret.has_elements(decrypted_premaster_secret_length))) {
                                 xos::protocol::tls::pkcs1::encoded::premaster::secret encoded_premaster_secret(decrypted_premaster_secret);
                                 xos::protocol::tls::pkcs1::decoded::premaster::secret decoded_premaster_secret(encoded_premaster_secret);

                                this->output_hex_run(decoded_premaster_secret, argc, argv, env);
                            }
                        }
                    }
                }
            }
        }
        return err;
    }

    /// ...output_client_hello_random_run
    virtual int output_client_hello_random_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::protocol::tls::hello::random* p_client_hello_random = 0;

        if ((p_client_hello_random = this->get_client_hello_random())) {
            const xos::protocol::tls::hello::random& client_hello_random = *p_client_hello_random;

            this->output_hex_run(client_hello_random, argc, argv, env);
        }
        return err;
    }

    /// ...output_decrypted_premaster_secret_run
    virtual int output_decrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::protocol::tls::encrypted::premaster::secret* p_encrypted_premaster_secret = 0;

        if ((p_encrypted_premaster_secret = this->get_encrypted_premaster_secret())) {
            const xos::protocol::tls::encrypted::premaster::secret& encrypted_premaster_secret = *p_encrypted_premaster_secret;
            const byte_t *encrypted_premaster_secret_bytes = 0; size_t encrypted_premaster_secret_length = 0;

            if ((encrypted_premaster_secret_bytes 
                = encrypted_premaster_secret.has_elements(encrypted_premaster_secret_length))) {
                const byte_t *p = 0, *q = 0, *dmp1 = 0, *dmq1 = 0, *iqmp = 0; size_t p_length = 0;
                
                if ((p = this->get_p(q, dmp1, dmq1, iqmp, p_length))) {
                    xos::protocol::tls::rsa::implemented::private_key private_key(p, q, dmp1, dmq1, iqmp, p_length);
                    xos::protocol::tls::decrypted::premaster::secret decrypted_premaster_secret(private_key, encrypted_premaster_secret);

                    this->output_hex_run(decrypted_premaster_secret, argc, argv, env);
                }
            }
        }
        return err;
    }
    /// ...output_encrypted_premaster_secret_run
    virtual int output_encrypted_premaster_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const xos::protocol::tls::encrypted::premaster::secret* p_encrypted_premaster_secret = 0;

        if ((p_encrypted_premaster_secret = this->get_encrypted_premaster_secret())) {
            const xos::protocol::tls::encrypted::premaster::secret& encrypted_premaster_secret = *p_encrypted_premaster_secret;

            this->output_hex_run(encrypted_premaster_secret, argc, argv, env);
        }
        return err;
    }

    /// on_set_client_hello_random_option
    virtual int on_set_client_hello_random_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        client_hello_random_string_.assign(optarg);
        if (!(err = this->on_set_hex_literal
            (client_hello_random_, client_hello_random_string_, argc, argv, env))) {
        }
        return err;
    }

    /// on_set_encrypted_secret_option
    virtual int on_set_encrypted_secret_option
    (const char_t* optarg, int optind, int argc, char_t** argv, char_t** env) {
        int err = 0;
        encrypted_premaster_secret_string_.assign(optarg);
        if (!(err = this->on_set_hex_literal
            (encrypted_premaster_secret_, encrypted_premaster_secret_string_, argc, argv, env))) {
        }
        return err;
    }

    /// get_client_hello_random
    const xos::protocol::tls::hello::random* get_client_hello_random() const {
        const xos::protocol::tls::hello::random& client_hello_random = client_hello_random_;
        if ((client_hello_random.has_elements())) {
            return &client_hello_random;
        }
        return 0;
    }

    /// get_encrypted_premaster_secret
    const xos::protocol::tls::encrypted::premaster::secret* get_encrypted_premaster_secret() const {
        const xos::protocol::tls::encrypted::premaster::secret& encrypted_premaster_secret = encrypted_premaster_secret_;
        if ((encrypted_premaster_secret.has_elements())) {
            return &encrypted_premaster_secret;
        }
        return 0;
    }

protected:
    ::talas::string_t client_hello_random_string_;
    xos::protocol::tls::hello::random client_hello_random_;

    ::talas::string_t encrypted_premaster_secret_string_;
    xos::protocol::tls::encrypted::premaster::secret encrypted_premaster_secret_;
}; /// class maint
typedef maint<> main;

} /// namespace server
} /// namespace tls
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_TLS_SERVER_MAIN_HPP
