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
///   File: message.hpp
///
/// Author: $author$
///   Date: 2/2/2022
///
/// The TLS Handshake Protocol is one of the defined higher-level clients
/// of the TLS Record Protocol.  This protocol is used to negotiate the
/// secure attributes of a session.  Handshake messages are supplied to
/// the TLS record layer, where they are encapsulated within one or more
/// TLSPlaintext structures, which are processed and transmitted as
/// specified by the current active session state.
///
///    enum {
///        hello_request(0), client_hello(1), server_hello(2),
///        certificate(11), server_key_exchange (12),
///        certificate_request(13), server_hello_done(14),
///        certificate_verify(15), client_key_exchange(16),
///        finished(20), (255)
///    } HandshakeType;
///
///    struct {
///        HandshakeType msg_type;    /// handshake type 
///        uint24 length;             /// bytes in message 
///        select (HandshakeType) {
///            case hello_request:       HelloRequest;
///            case client_hello:        ClientHello;
///            case server_hello:        ServerHello;
///            case certificate:         Certificate;
///            case server_key_exchange: ServerKeyExchange;
///            case certificate_request: CertificateRequest;
///            case server_hello_done:   ServerHelloDone;
///            case certificate_verify:  CertificateVerify;
///            case client_key_exchange: ClientKeyExchange;
///            case finished:            Finished;
///        } body;
///    } Handshake;
///
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_HANDSHAKE_MESSAGE_HPP
#define XOS_PROTOCOL_TLS_HANDSHAKE_MESSAGE_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/uinteger.hpp"
#include "xos/protocol/tls/handshake/type/which.hpp"
#include "xos/protocol/tls/client/hello.hpp"
#include "xos/protocol/tls/client/key/exchange/message.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace handshake {

/// class messaget
template 
<typename TType = tls::handshake::type::which, 
 TType VTypeNone = tls::handshake::type::none, 
 TType VTypeClientHello = tls::handshake::type::client_hello, 
 class TClientHello = tls::client::hello,
 TType VTypeClientKeyExchange = tls::handshake::type::client_key_exchange, 
 class TClientKeyExchange = tls::client::key::exchange::message,
 typename TUInt24 = tls::uint24, class TRandomReader = tls::pseudo::random::reader,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives; 
    
    typedef TRandomReader random_reader_t;
    typedef TMessagePart message_part_t;
    typedef TUInt24 uint24_t;
    typedef TType type_t;
    enum { 
        type_none = VTypeNone, 
        type_client_hello = VTypeClientHello,
        type_client_key_exchange = VTypeClientKeyExchange
    };
    typedef TClientHello client_hello_t;
    typedef TClientKeyExchange client_key_exchange_t;

    /// constructors / destructor
    messaget(const messaget& copy)
    : extends(copy), type_(copy.type_), length_(copy.length_) {
    }
    messaget(const client_hello_t& client_hello)
    : type_(type_client_hello), 
      length_(client_hello.length()) {
        combine(client_hello);
    }
    messaget(const client_key_exchange_t& client_key_exchange)
    : type_(type_client_key_exchange), 
      length_(client_key_exchange.length()) {
        combine(client_key_exchange);
    }
    messaget()
    : type_(type_none), length_(0) {
        combine();
    }
    virtual ~messaget() {
    }
    
    /// combine / separate
    virtual bool combine(const client_key_exchange_t& client_key_exchange) {
        bool success = false;
        const byte_t* bytes = 0; size_t length = 0;
        if ((bytes = client_key_exchange.has_elements(length))) {
            if ((combine())) {
                this->append(bytes, length);
                success = true;
            }
        }
        return success;
    }
    virtual bool combine(const client_hello_t& client_hello) {
        bool success = false;
        const byte_t* bytes = 0; size_t length = 0;
        if ((bytes = client_hello.has_elements(length))) {
            if ((combine())) {
                this->append(bytes, length);
                success = true;
            }
        }
        return success;
    }
    virtual bool combine() {
        bool success = false;
        if (0 < (this->set_to_msb(type_))) {
            if (0 < (this->append(length_))) {
                success = true;
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

protected:
    type_t type_;
    uint24_t length_;
}; /// class messaget
typedef messaget<> message;

} /// namespace handshake
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_HANDSHAKE_MESSAGE_HPP
