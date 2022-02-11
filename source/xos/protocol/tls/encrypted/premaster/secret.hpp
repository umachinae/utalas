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
///   File: secret.hpp
///
/// Author: $author$
///   Date: 2/11/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_ENCRYPTED_PREMASTER_SECRET_HPP
#define XOS_PROTOCOL_TLS_ENCRYPTED_PREMASTER_SECRET_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/pkcs1/encoded/premaster/secret.hpp"
#include "xos/protocol/tls/rsa/key.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace encrypted {
namespace premaster {

/// class secrett
template 
<class TRsaKey = tls::rsa::key, 
 class TEncodedPremasterSecret = tls::pkcs1::encoded::premaster::secret,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported secrett: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef secrett derives; 
    
    typedef TRsaKey rsa_key_t;
    typedef TEncodedPremasterSecret encoded_premaster_secret_t;
    
    /// constructors / destructor
    secrett(const secrett& copy): extends(copy) {
    }
    secrett(rsa_key_t& rsa_key, const encoded_premaster_secret_t& encoded_premaster_secret) {
        combine(rsa_key, encoded_premaster_secret);
    }
    secrett() {
    }
    virtual ~secrett() {
    }

    /// combine / separate
    virtual bool combine(rsa_key_t& rsa_key, const encoded_premaster_secret_t& encoded_premaster_secret) {
        bool success = false;
        const byte_t* secret_bytes = 0; size_t secret_length = 0;

        if ((secret_bytes = encoded_premaster_secret.has_elements(secret_length)) 
            && (secret_length == rsa_key.modulus_size())) {
            byte_t* bytes = 0; size_t length = 0;

            this->set_length(secret_length);
            if ((bytes = this->has_elements(length)) && (length == secret_length)) {
                if (length == (rsa_key(bytes, length, secret_bytes, secret_length))) {
                    success = true;
                }
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

}; /// class secrett
typedef secrett<> secret;

} /// namespace premaster
} /// namespace encrypted
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_ENCRYPTED_PREMASTER_SECRET_HPP
