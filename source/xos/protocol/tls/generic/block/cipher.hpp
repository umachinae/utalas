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
///   File: cipher.hpp
///
/// Author: $author$
///   Date: 2/25/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_GENERIC_BLOCK_CIPHER_HPP
#define XOS_PROTOCOL_TLS_GENERIC_BLOCK_CIPHER_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/security/parameters.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace generic {
namespace block {

/// class ciphert
template 
<class TOpaque = tls::message::part,
 class TPadding = tls::message::part,
 class TUinteger8 = tls::uintegert<uint8_t>,
 class TMessagePart = tls::message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported ciphert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef ciphert derives; 
    
    typedef TOpaque opaque_t;
    typedef TPadding padding_t;
    typedef TUinteger8 uinteger8_t;
    
    /// constructors / destructor
    ciphert(const ciphert& copy): extends(copy) {
    }
    ciphert(const opaque_t& IV, const opaque_t& content) {
        combine(IV, content);
    }
    ciphert() {
    }
    virtual ~ciphert() {
    }

    /// combine / separate
    virtual bool combine(const opaque_t& IV, const opaque_t& content) {
        bool success = false;
        const byte_t* bytes = 0; size_t length = 0;
        
        this->set_length(0);
        if ((bytes = IV.has_elements(length))) {
            
            this->append(IV);
            if ((bytes = content.has_elements(length))) {
                const uint8_t padding_length_value = 0;
                uinteger8_t padding_length(padding_length_value);
                
                this->append(content);
                this->append(padding_length);
                success = true;
            } else {
                this->set_length(0);
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

}; /// class ciphert
typedef ciphert<> cipher;

} /// namespace block
} /// namespace generic
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_GENERIC_BLOCK_CIPHER_HPP
