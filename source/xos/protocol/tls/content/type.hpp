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
///   File: type.hpp
///
/// Author: $author$
///   Date: 2/25/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CONTENT_TYPE_HPP
#define XOS_PROTOCOL_TLS_CONTENT_TYPE_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace content {

typedef uint8_t type_which_t;
enum { 
    type_change_cipher_spec = 20, 
    type_alert = 21, 
    type_handshake = 22,
    type_application_data = 23,
    type_none = 255
};

/// class typet
template 
<typename TWhich = type_which_t, 
 TWhich VHandshake = type_handshake, TWhich VApplicationData = type_application_data, TWhich VWhich = type_none,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported typet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef typet derives; 
    
    typedef TWhich which_t;
    enum  { 
        handshake = VHandshake,
        application_data = VApplicationData,
        which = VWhich 
    };

    /// constructors / destructor
    typet(const typet& copy): which_(copy.which_) {
        this->to_msb(which_);
    }
    typet(const which_t& which): which_(which) {
        this->to_msb(which_);
    }
    typet(): which_(which) {
        this->to_msb(which_);
    }
    virtual ~typet() {
    }

    /// ...is
    virtual const which_t& is() const {
        return which_;
    }

protected:
    which_t which_;
}; /// class typet
typedef typet<> type;

} /// namespace content
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_CONTENT_TYPE_HPP
