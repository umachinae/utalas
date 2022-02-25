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
///   Date: 2/20/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_UDTP_CLIENT_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_UDTP_CLIENT_MAIN_HPP

#include "xos/app/console/protocol/udtp/client/main_opt.hpp"

#include "xos/crypto/hash/implemented/sha256.hpp"
#include "xos/crypto/cipher/implemented/aes.hpp"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace udtp {
namespace client {

/// class maint
template 
<class TExtends = xos::app::console::protocol::udtp::client::main_opt, 
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
      plain_text_("{\"password\":{\"resource\":\"resource\",\"user\":\"user\",\"password\":\"password\"}}") {
        cipher_text_.set_length(1024*4);
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

    /// ...output_generate_client_hello_run
    virtual int output_generate_client_hello_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool verbose = this->verbose_output();
        const byte_t* bytes = 0; size_t length = 0;
        xos::protocol::tls::protocol::version protocol_version(this->protocol_version_which());

        if ((bytes = protocol_version.has_elements(length))) {
            xos::protocol::tls::gmt::unix::time gmt_unix_time(xos::protocol::tls::gmt::unix::time::now());
            
            if ((verbose)) {
                this->outln();
                this->outln("protocol_version:\\");
                this->output_hex_run(protocol_version, argc, argv, env);
                this->outln();
            }
            if ((bytes = gmt_unix_time.has_elements(length))) {
                xos::protocol::tls::pseudo::random::reader pseudo_random_reader(this->secret(), this->seed());
                xos::protocol::tls::random::bytes random_bytes(pseudo_random_reader);
                xos::protocol::tls::hello::random hello_random(pseudo_random_reader, gmt_unix_time, random_bytes);
                
                if ((verbose)) {
                    this->outln("gmt_unix_time:\\");
                    this->output_hex_run(gmt_unix_time, argc, argv, env);
                    this->outln();
                }
                if ((bytes = hello_random.has_elements(length))) {
                    xos::protocol::tls::session::identifier session_id(pseudo_random_reader);
                    
                    if ((verbose)) {
                        this->outln("hello_random:\\");
                        this->output_hex_run(hello_random, argc, argv, env);
                        this->outln();
                    }
                    if ((bytes = session_id.has_elements(length))) {
                        xos::protocol::tls::cipher::suite cipher_suite(this->cipher_suite_which(), this->cipher_suite_with());
                        xos::protocol::tls::cipher::suites cipher_suites(cipher_suite);
                        
                        if ((verbose)) {
                            this->outln("session_id:\\");
                            this->output_hex_run(session_id, argc, argv, env);
                            this->outln();
                        }
                        if ((bytes = cipher_suites.has_elements(length))) {
                            xos::protocol::tls::compression::method compression_method(this->compression_method_which());
                            xos::protocol::tls::compression::methods compression_methods(compression_method);
                            
                            if ((verbose)) {
                                this->outln("cipher_suites:\\");
                                this->output_hex_run(cipher_suites, argc, argv, env);
                                this->outln();
                            }
                            if ((bytes = compression_methods.has_elements(length))) {
                                xos::protocol::tls::client::hello client_hello
                                (protocol_version, hello_random, session_id, cipher_suites, compression_methods, pseudo_random_reader);
                                
                                if ((verbose)) {
                                    this->outln("compression_methods:\\");
                                    this->output_hex_run(compression_methods, argc, argv, env);
                                    this->outln();
                                }
                                if ((bytes = client_hello.has_elements(length))) {
                                    xos::protocol::tls::handshake::message client_hello_handshake(client_hello); 
                                    
                                    if ((verbose)) {
                                        this->outln("client_hello:\\");
                                        this->output_hex_run(client_hello, argc, argv, env);
                                        this->outln();
                                    }
                                    if ((bytes = client_hello_handshake.has_elements(length))) {
                                        xos::protocol::tls::content::type content_type(xos::protocol::tls::content::type::handshake);
                                        xos::protocol::tls::plaintext client_hello_plaintext(content_type, protocol_version, client_hello_handshake);

                                        if ((verbose)) {
                                            this->outln("client_hello_handshake:\\");
                                            this->output_hex_run(client_hello_handshake, argc, argv, env);
                                            this->outln();
                                        }
                                        if ((bytes = client_hello_handshake.has_elements(length))) {
                                            if ((verbose)) {
                                                this->outln("client_hello_plaintext:\\");
                                            }
                                            this->output_hex_run(client_hello_plaintext, argc, argv, env);
                                            if ((verbose)) {
                                                this->outln();
                                            }
                                            if (!(err = output_generate_client_key_exchange_run
                                                (protocol_version, gmt_unix_time, hello_random, pseudo_random_reader, argc, argv, env))) {
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return err;
    }

    /// ...output_generate_client_key_exchange_run
    virtual int output_generate_client_key_exchange_run
    (xos::protocol::tls::protocol::version& protocol_version, 
     xos::protocol::tls::gmt::unix::time& gmt_unix_time, 
     xos::protocol::tls::hello::random& hello_random, 
     xos::protocol::tls::pseudo::random::reader& pseudo_random_reader, 
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool verbose = this->verbose_output();
        const byte_t* bytes = 0; size_t length = 0;
        xos::protocol::tls::premaster::secret::random premaster_secret_random(pseudo_random_reader);

        if ((bytes = premaster_secret_random.has_elements(length))) {
            xos::protocol::tls::premaster::secret::message premaster_secret(protocol_version, premaster_secret_random, pseudo_random_reader);
            
            if ((verbose)) {
                this->outln("premaster_secret_random:\\");
                this->output_hex_run(premaster_secret_random, argc, argv, env);
                this->outln();
            }
            if ((bytes = premaster_secret.has_elements(length))) {
                const byte_t* modulus = 0; size_t modulus_length = 0;
                
                if ((verbose)) {
                    this->outln("premaster_secret:\\");
                    this->output_hex_run(premaster_secret, argc, argv, env);
                    this->outln();
                }
                if ((modulus = this->get_modulus(modulus_length))) {
                    xos::crypto::pseudo::random::reader random_reader(0);
                    xos::protocol::tls::pkcs1::encoded::premaster::secret encoded_premaster_secret(modulus_length, premaster_secret, random_reader);
                    
                    if ((bytes = encoded_premaster_secret.has_elements(length))) {
                        const byte_t* exponent = 0; size_t exponent_length = 0;
                        
                        if ((verbose)) {
                            this->outln("encoded_premaster_secret:\\");
                            this->output_hex_run(encoded_premaster_secret, argc, argv, env);
                            this->outln();
                        }
                        if ((exponent = this->get_exponent(exponent_length))) {
                            xos::protocol::tls::rsa::implemented::public_key public_key(modulus, modulus_length, exponent, exponent_length);
                            xos::protocol::tls::encrypted::premaster::secret encrypted_premaster_secret(public_key, encoded_premaster_secret);
                            
                            if ((bytes = encrypted_premaster_secret.has_elements(length))) {
                                xos::protocol::tls::client::key::exchange::message client_key_exchange(encrypted_premaster_secret); 
                                
                                if ((verbose)) {
                                    this->outln("encrypted_premaster_secret:\\");
                                    this->output_hex_run(encrypted_premaster_secret, argc, argv, env);
                                    this->outln();
                                }
                                if ((bytes = client_key_exchange.has_elements(length))) {
                                    xos::protocol::tls::handshake::message client_key_exchange_handshake(client_key_exchange); 
                                    
                                    if ((verbose)) {
                                        this->outln("client_key_exchange:\\");
                                        this->output_hex_run(client_key_exchange, argc, argv, env);
                                        this->outln();
                                    }
                                    if ((bytes = client_key_exchange_handshake.has_elements(length))) {
                                        xos::protocol::tls::content::type content_type(xos::protocol::tls::content::type::handshake);
                                        xos::protocol::tls::plaintext client_key_exchange_plaintext(content_type, protocol_version, client_key_exchange_handshake);

                                        if ((verbose)) {
                                            this->outln("client_key_exchange_handshake:\\");
                                            this->output_hex_run(client_key_exchange_handshake, argc, argv, env);
                                            this->outln();
                                        }
                                        if ((bytes = client_key_exchange_plaintext.has_elements(length))) {
                                            if ((verbose)) {
                                                this->outln("client_key_exchange_plaintext:\\");
                                            }
                                            this->output_hex_run(client_key_exchange_plaintext, argc, argv, env);
                                            if ((verbose)) {                                                                            
                                                this->outln();
                                            }
                                            if (!(err = output_generate_master_secret_run
                                                (hello_random, premaster_secret, argc, argv, env))) {
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return err;
    }

    /// ...output_generate_master_secret_run
    virtual int output_generate_master_secret_run
    (xos::protocol::tls::hello::random& hello_random, 
     xos::protocol::tls::premaster::secret::message& premaster_secret, 
     int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool verbose = this->verbose_output();
        const ::talas::byte_array_t& master_secret_seed = this->master_secret_seed();
        xos::protocol::tls::master::secret master_secret(premaster_secret, master_secret_seed, hello_random, hello_random);
        const byte_t* bytes = 0; size_t length = 0;

        if ((bytes = master_secret.has_elements(length))) {
            const ::talas::byte_array_t& key_expansion_seed = this->key_expansion_seed();

            if ((verbose)) {
                this->outln("master_secret:\\");
                this->output_hex_run(master_secret, argc, argv, env);
                this->outln();
            }
            if ((bytes = key_expansion_seed.has_elements(length))) {
                xos::protocol::tls::message::part hello_randoms(hello_random);
                
                hello_randoms.append(hello_random);
                if ((bytes = hello_randoms.has_elements(length))) {
                    xos::protocol::tls::pseudo::random::reader key_material(master_secret, key_expansion_seed, hello_randoms);
                    byte_t* key = 0; size_t keylen = 0, keysize = 0;
                    ::talas::byte_array_t client_write_MAC_key;
                    
                    client_write_MAC_key.set_length(keysize = xos::crypto::hash::sha256::KEYMAX);
                    if ((key = client_write_MAC_key.has_elements(keylen)) && (keysize == keylen)) {
                        ::talas::byte_array_t client_write_key;
                        
                        if (keylen == (key_material.read(key, keylen))) {
                            if ((verbose)) {
                                this->outln("client_write_MAC_key:\\");
                                this->output_hex_run(client_write_MAC_key, argc, argv, env);
                                this->outln();
                            }
                        }                        
                        client_write_key.set_length(keysize = xos::crypto::cipher::aes::KEYMAX);
                        if ((key = client_write_key.has_elements(keylen)) && (keysize == keylen)) {
                            ::talas::byte_array_t client_write_IV;
                            
                            if (keylen == (key_material.read(key, keylen))) {
                                if ((verbose)) {
                                    this->outln("client_write_key:\\");
                                    this->output_hex_run(client_write_key, argc, argv, env);
                                    this->outln();
                                }
                            }
                            client_write_IV.set_length(keysize = xos::crypto::cipher::aes::IVMAX);
                            if ((key = client_write_IV.has_elements(keylen)) && (keysize == keylen)) {

                                if (keylen == (key_material.read(key, keylen))) {
                                    if ((verbose)) {
                                        this->outln("client_write_IV:\\");
                                        this->output_hex_run(client_write_IV, argc, argv, env);
                                        this->outln();
                                    }
                                    if (!(err = output_generate_cipher_text_run
                                        (client_write_MAC_key, client_write_key, client_write_IV, argc, argv, env))) {
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return err;
    }

    /// ...output_generate_cipher_text_run
    virtual int output_generate_cipher_text_run
    (const ::talas::byte_array_t& client_write_MAC_key, const ::talas::byte_array_t& client_write_key,
     const ::talas::byte_array_t& client_write_IV, int argc, char_t** argv, char_t** env) {
        int err = 0;
        const bool verbose = this->verbose_output();
        const char_t* plain = 0; size_t plain_length = 0;

        if ((plain = plain_text(plain_length))) {
            ::talas::byte_array_t plain_array((const byte_t*)plain, plain_length);
            byte_t* cipher = 0; size_t cipher_size = 0;
            
            if ((verbose)) {
                this->outln("plain_text:\\");
                this->output_hex_run(plain_array, argc, argv, env);
                this->outln();
            }
            if ((cipher = cipher_text(cipher_size))) {
                xos::crypto::cipher::implemented::aes aes
                (client_write_key.elements(), client_write_key.length(),
                 client_write_IV.elements(), client_write_IV.length());
                size_t length = 0;

                if (0 < (length = aes.encrypt(cipher, cipher_size, plain, plain_length))) {
                    ::talas::byte_array_t cipher_array(cipher, length);

                    if ((verbose)) {
                        this->outln("cipher_text:\\");
                        this->output_hex_run(cipher_array, argc, argv, env);
                        this->outln();
                    }
                }
            }
        }
        return err;
    }

    const char_t* plain_text(size_t& length) const {
        return plain_text_.has_chars(length);
    }
    byte_t* cipher_text(size_t& length) const {
        return cipher_text_.has_elements(length);
    }

protected:
    ::talas::string_t plain_text_;
    ::talas::byte_array_t cipher_text_;
}; /// class maint
typedef maint<> main;

} /// namespace client
} /// namespace udtp
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_UDTP_CLIENT_MAIN_HPP
