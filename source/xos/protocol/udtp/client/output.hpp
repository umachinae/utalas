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
///   File: output.hpp
///
/// Author: $author$
///   Date: 3/2/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_UDTP_CLIENT_OUTPUT_HPP
#define XOS_PROTOCOL_UDTP_CLIENT_OUTPUT_HPP

#include "xos/protocol/udtp/base/output.hpp"

#include "xos/crypto/hash/implemented/sha256.hpp"
#include "xos/crypto/cipher/implemented/aes.hpp"

namespace xos {
namespace protocol {
namespace udtp {
namespace client {

/// class outputt
template 
<class TOutput = xos::protocol::udtp::base::output, 
 class TExtends = TOutput, class TImplements = typename TExtends::implements>

class exported outputt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef outputt derives; 
    
    typedef typename extends::output_t output_t;
    typedef typename implements::string_t string_t;
    typedef typename implements::char_t char_t;
    typedef typename implements::end_char_t end_char_t;
    enum { end_char = implements::end_char };

    typedef char_t what_t;
    typedef char_t sized_t;

    /// constructors / destructor
    outputt(const outputt& copy): extends(copy) {
    }
    outputt()
    : cipher_text_size_(1024*4), 
      plain_text_("{\"password\":{\"resource\":\"resource\",\"user\":\"user\",\"password\":\"password\"}}") {
        cipher_text_.set_length(cipher_text_size_);
    }
    virtual ~outputt() {
    }

    /// ...output_generate_client_hello
    virtual int output_generate_client_hello() {
        int err = 0;
        const bool verbose = this->verbose_output();
        const byte_t* bytes = 0; size_t length = 0;
        xos::protocol::tls::protocol::version protocol_version(this->protocol_version_which());

        if ((bytes = protocol_version.has_elements(length))) {
            xos::protocol::tls::gmt::unix::time gmt_unix_time(xos::protocol::tls::gmt::unix::time::now());
            
            if ((verbose)) {
                this->outln();
                this->outln("protocol_version:\\");
                this->output_hex(protocol_version);
                this->outln();
            }
            if ((bytes = gmt_unix_time.has_elements(length))) {
                xos::protocol::tls::pseudo::random::reader pseudo_random_reader(this->pseudo_random_secret(), this->pseudo_random_seed());
                xos::protocol::tls::random::bytes random_bytes(pseudo_random_reader);
                xos::protocol::tls::hello::random hello_random(pseudo_random_reader, gmt_unix_time, random_bytes);
                
                if ((verbose)) {
                    this->outln("gmt_unix_time:\\");
                    this->output_hex(gmt_unix_time);
                    this->outln();
                }
                if ((bytes = hello_random.has_elements(length))) {
                    xos::protocol::tls::session::identifier session_id(pseudo_random_reader);
                    
                    if ((verbose)) {
                        this->outln("hello_random:\\");
                        this->output_hex(hello_random);
                        this->outln();
                    }
                    if ((bytes = session_id.has_elements(length))) {
                        xos::protocol::tls::cipher::suite cipher_suite(this->cipher_suite_which(), this->cipher_suite_with());
                        xos::protocol::tls::cipher::suites cipher_suites(cipher_suite);
                        
                        if ((verbose)) {
                            this->outln("session_id:\\");
                            this->output_hex(session_id);
                            this->outln();
                        }
                        if ((bytes = cipher_suites.has_elements(length))) {
                            xos::protocol::tls::compression::method compression_method(this->compression_method_which());
                            xos::protocol::tls::compression::methods compression_methods(compression_method);
                            
                            if ((verbose)) {
                                this->outln("cipher_suites:\\");
                                this->output_hex(cipher_suites);
                                this->outln();
                            }
                            if ((bytes = compression_methods.has_elements(length))) {
                                xos::protocol::tls::client::hello client_hello
                                (protocol_version, hello_random, session_id, cipher_suites, compression_methods, pseudo_random_reader);
                                
                                if ((verbose)) {
                                    this->outln("compression_methods:\\");
                                    this->output_hex(compression_methods);
                                    this->outln();
                                }
                                if ((bytes = client_hello.has_elements(length))) {
                                    xos::protocol::tls::handshake::message client_hello_handshake(client_hello); 
                                    
                                    if ((verbose)) {
                                        this->outln("client_hello:\\");
                                        this->output_hex(client_hello);
                                        this->outln();
                                    }
                                    if ((bytes = client_hello_handshake.has_elements(length))) {
                                        xos::protocol::tls::content::type content_type(xos::protocol::tls::content::type::handshake);
                                        xos::protocol::tls::plaintext client_hello_plaintext(content_type, protocol_version, client_hello_handshake);

                                        if ((verbose)) {
                                            this->outln("client_hello_handshake:\\");
                                            this->output_hex(client_hello_handshake);
                                            this->outln();
                                        }
                                        if ((bytes = client_hello_handshake.has_elements(length))) {
                                            if ((verbose)) {
                                                this->outln("client_hello_plaintext:\\");
                                            }
                                            this->output_hex(client_hello_plaintext);
                                            if ((verbose)) {
                                                this->outln();
                                            }
                                            if (!(err = output_generate_client_key_exchange
                                                (protocol_version, gmt_unix_time, hello_random, pseudo_random_reader))) {
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

    /// ...output_generate_client_key_exchange
    virtual int output_generate_client_key_exchange
    (xos::protocol::tls::protocol::version& protocol_version, 
     xos::protocol::tls::gmt::unix::time& gmt_unix_time, 
     xos::protocol::tls::hello::random& hello_random, 
     xos::protocol::tls::pseudo::random::reader& pseudo_random_reader) {
        int err = 0;
        const bool verbose = this->verbose_output();
        const byte_t* bytes = 0; size_t length = 0;
        xos::protocol::tls::premaster::secret::random premaster_secret_random(pseudo_random_reader);

        if ((bytes = premaster_secret_random.has_elements(length))) {
            xos::protocol::tls::premaster::secret::message premaster_secret(protocol_version, premaster_secret_random, pseudo_random_reader);
            
            if ((verbose)) {
                this->outln("premaster_secret_random:\\");
                this->output_hex(premaster_secret_random);
                this->outln();
            }
            if ((bytes = premaster_secret.has_elements(length))) {
                const byte_t* modulus = 0; size_t modulus_length = 0;
                
                if ((verbose)) {
                    this->outln("premaster_secret:\\");
                    this->output_hex(premaster_secret);
                    this->outln();
                }
                if ((modulus = this->get_modulus(modulus_length))) {
                    xos::crypto::pseudo::random::reader random_reader(0);
                    xos::protocol::tls::pkcs1::encoded::premaster::secret encoded_premaster_secret(modulus_length, premaster_secret, random_reader);
                    
                    if ((bytes = encoded_premaster_secret.has_elements(length))) {
                        const byte_t* exponent = 0; size_t exponent_length = 0;
                        
                        if ((verbose)) {
                            this->outln("encoded_premaster_secret:\\");
                            this->output_hex(encoded_premaster_secret);
                            this->outln();
                        }
                        if ((exponent = this->get_exponent(exponent_length))) {
                            xos::protocol::tls::rsa::implemented::public_key public_key(modulus, modulus_length, exponent, exponent_length);
                            xos::protocol::tls::encrypted::premaster::secret encrypted_premaster_secret(public_key, encoded_premaster_secret);
                            
                            if ((bytes = encrypted_premaster_secret.has_elements(length))) {
                                xos::protocol::tls::client::key::exchange::message client_key_exchange(encrypted_premaster_secret); 
                                
                                if ((verbose)) {
                                    this->outln("encrypted_premaster_secret:\\");
                                    this->output_hex(encrypted_premaster_secret);
                                    this->outln();
                                }
                                if ((bytes = client_key_exchange.has_elements(length))) {
                                    xos::protocol::tls::handshake::message client_key_exchange_handshake(client_key_exchange); 
                                    
                                    if ((verbose)) {
                                        this->outln("client_key_exchange:\\");
                                        this->output_hex(client_key_exchange);
                                        this->outln();
                                    }
                                    if ((bytes = client_key_exchange_handshake.has_elements(length))) {
                                        xos::protocol::tls::content::type content_type(xos::protocol::tls::content::type::handshake);
                                        xos::protocol::tls::plaintext client_key_exchange_plaintext(content_type, protocol_version, client_key_exchange_handshake);

                                        if ((verbose)) {
                                            this->outln("client_key_exchange_handshake:\\");
                                            this->output_hex(client_key_exchange_handshake);
                                            this->outln();
                                        }
                                        if ((bytes = client_key_exchange_plaintext.has_elements(length))) {
                                            if ((verbose)) {
                                                this->outln("client_key_exchange_plaintext:\\");
                                            }
                                            this->output_hex(client_key_exchange_plaintext);
                                            if ((verbose)) {                                                                            
                                                this->outln();
                                            }
                                            if (!(err = output_generate_master_secret
                                                (protocol_version, hello_random, premaster_secret))) {
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

    /// ...output_generate_master_secret
    virtual int output_generate_master_secret
    (xos::protocol::tls::protocol::version& protocol_version, 
     xos::protocol::tls::hello::random& hello_random, 
     xos::protocol::tls::premaster::secret::message& premaster_secret) {
        int err = 0;
        const bool verbose = this->verbose_output();
        const ::talas::byte_array_t& master_secret_seed = this->master_secret_seed();
        xos::protocol::tls::master::secret master_secret(premaster_secret, master_secret_seed, hello_random, hello_random);
        const byte_t* bytes = 0; size_t length = 0;

        if ((bytes = master_secret.has_elements(length))) {
            const ::talas::byte_array_t& key_expansion_seed = this->key_expansion_seed();

            if ((verbose)) {
                this->outln("master_secret:\\");
                this->output_hex(master_secret);
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
                                this->output_hex(client_write_MAC_key);
                                this->outln();
                            }
                        }                        
                        client_write_key.set_length(keysize = xos::crypto::cipher::aes::KEYMAX);
                        if ((key = client_write_key.has_elements(keylen)) && (keysize == keylen)) {
                            ::talas::byte_array_t client_write_IV;
                            
                            if (keylen == (key_material.read(key, keylen))) {
                                if ((verbose)) {
                                    this->outln("client_write_key:\\");
                                    this->output_hex(client_write_key);
                                    this->outln();
                                }
                            }
                            client_write_IV.set_length(keysize = xos::crypto::cipher::aes::IVMAX);
                            if ((key = client_write_IV.has_elements(keylen)) && (keysize == keylen)) {

                                if (keylen == (key_material.read(key, keylen))) {
                                    if ((verbose)) {
                                        this->outln("client_write_IV:\\");
                                        this->output_hex(client_write_IV);
                                        this->outln();
                                    }
                                    if (!(err = output_generate_cipher_text
                                        (protocol_version, client_write_MAC_key, client_write_key, client_write_IV))) {
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

    /// ...output_generate_cipher_text
    virtual int output_generate_cipher_text
    (xos::protocol::tls::protocol::version& protocol_version, 
     const ::talas::byte_array_t& client_write_MAC_key, const ::talas::byte_array_t& client_write_key,
     const ::talas::byte_array_t& client_write_IV) {
        int err = 0;
        const bool verbose = this->verbose_output();
        const char_t* plain = 0; size_t plain_length = 0;

        if ((plain = plain_text(plain_length))) {
            ::talas::byte_array_t plain_array((const byte_t*)plain, plain_length);
            byte_t* cipher = 0; size_t cipher_size = 0;
            
            if ((verbose)) {
                this->outln("plain_text:\\");
                this->output_hex(plain_array);
                this->outln();
            }
            if ((cipher = cipher_text(cipher_size))) {
                byte_t* client_write_key_bytes = 0; uint8_t client_write_key_length = 0;

                if ((client_write_key_bytes = client_write_key.elements()) 
                    && (client_write_key_length = client_write_key.length())) {
                    byte_t* client_write_IV_bytes = 0; uint8_t client_write_IV_length = 0;
    
                    if ((client_write_IV_bytes = client_write_IV.elements()) 
                        && (client_write_IV_length = client_write_IV.length())) {
                        xos::crypto::cipher::implemented::aes aes
                        (client_write_key_bytes, client_write_key_length, client_write_IV_bytes, client_write_IV_length);
                        size_t length = 0;
        
                        if (0 < (length = aes.encrypt(cipher, cipher_size, plain, plain_length))) {
                            ::talas::byte_array_t cipher_array(cipher, length);
                            uint8_t client_write_MAC_length = 0, client_write_MAC_key_length = 0;
                            
                            if ((verbose)) {
                                this->outln("cipher_text:\\");
                                this->output_hex(cipher_array);
                                this->outln();
                            }
                            if ((client_write_MAC_length = xos::crypto::hash::sha256::HASHSIZE) 
                                && (client_write_MAC_key_length = client_write_MAC_key.length())) {
                                xos::crypto::pseudo::random::reader::seed_t random_reader_seed = 0;
                                xos::crypto::pseudo::random::reader random_reader(random_reader_seed);
                                ::talas::byte_array_t generic_block_cipher_IV;
                                byte_t* generic_block_cipher_IV_bytes = 0; uint8_t generic_block_cipher_IV_length = 0;
                                
                                generic_block_cipher_IV.set_length(client_write_IV_length);
                                if ((generic_block_cipher_IV_bytes = generic_block_cipher_IV.has_elements()) 
                                    && (client_write_IV_length == (generic_block_cipher_IV_length = generic_block_cipher_IV.length()))) {
                                    
                                    if (client_write_IV_length == (random_reader.read(generic_block_cipher_IV_bytes, generic_block_cipher_IV_length))) {
                                        xos::protocol::tls::generic::block::cipher generic_block_cipher(generic_block_cipher_IV, cipher_array);
                                        byte_t* generic_block_cipher_bytes = 0; size_t generic_block_cipher_length = 0;
    
                                        if ((verbose)) {
                                            this->outln("cgeneric_block_cipher:\\");
                                            this->output_hex(generic_block_cipher);
                                            this->outln();
                                        }
                                        if ((generic_block_cipher_bytes = generic_block_cipher.has_elements(generic_block_cipher_length))) {
                                            xos::protocol::tls::content::type content_type(xos::protocol::tls::content::type::application_data);
                                            xos::protocol::tls::ciphertext ciphertext(content_type, protocol_version, generic_block_cipher);
                                            byte_t* ciphertext_bytes = 0; size_t ciphertext_length = 0;
                                            
                                            if ((ciphertext_bytes = ciphertext.has_elements(ciphertext_length))) {
                                                
                                                if ((verbose)) {
                                                    this->outln("cipher_text:\\");
                                                }
                                                this->output_hex(ciphertext);
                                                if ((verbose)) {
                                                    this->outln();
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
        }
        return err;
    }

    /// ...text
    const char_t* plain_text(size_t& length) const {
        return plain_text_.has_chars(length);
    }
    byte_t* cipher_text(size_t& length) const {
        return cipher_text_.has_elements(length);
    }

protected:
    size_t cipher_text_size_;
    ::talas::string_t plain_text_;
    ::talas::byte_array_t cipher_text_;
}; /// class outputt
typedef outputt<> output;

namespace console {
typedef outputt<xos::protocol::udtp::base::console::output> output;
} /// namespace console

} /// namespace client
} /// namespace udtp
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_UDTP_CLIENT_OUTPUT_HPP
