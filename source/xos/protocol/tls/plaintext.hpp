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
///   File: plaintext.hpp
///
/// Author: $author$
///   Date: 2/25/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PLAINTEXT_HPP
#define XOS_PROTOCOL_TLS_PLAINTEXT_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/protocol/version.hpp"
#include "xos/protocol/tls/content/type.hpp"
#include "xos/protocol/tls/uinteger.hpp"

namespace xos {
namespace protocol {
namespace tls {

/// class plaintextt
template 
<class TContentType = tls::content::type, 
 class TProtocolVersion = tls::protocol::version, 
 class TUInteger16 = tls::uintegert<uint16_t>,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported plaintextt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef plaintextt derives; 
    
    typedef TContentType type_t;
    typedef TProtocolVersion version_t;
    typedef TUInteger16 length_t;
    typedef TMessagePart fragment_t;
    
    /// constructors / destructor
    plaintextt(const plaintextt& copy): extends(copy) {
    }
    plaintextt(const type_t& type, const version_t& version, const fragment_t& fragment) {
        combine(type, version, fragment);
    }
    plaintextt() {
    }
    virtual ~plaintextt() {
    }

    /// combine / separate
    virtual bool combine(const type_t& type, const version_t& version, const fragment_t& fragment) {
        bool success = false;
        length_t fragment_length(fragment.length());
        const byte_t* bytes = 0; size_t length = 0;
        
        this->set_length(0);
        if ((bytes = fragment_length.has_elements(length))) {

            if ((bytes = version.has_elements(length))) {

                if ((bytes = type.has_elements(length))) {

                    this->append(type);
                    this->append(version);
                    this->append(fragment_length);
                    if (0 < (fragment_length.value())) {

                        this->append(fragment);
                    }
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

}; /// class plaintextt

typedef plaintextt<> plaintext;
typedef plaintext ciphertext;

} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_PLAINTEXT_HPP
