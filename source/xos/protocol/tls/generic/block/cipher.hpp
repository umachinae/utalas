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

namespace xos {
namespace protocol {
namespace tls {
namespace generic {
namespace block {

/// class ciphert
template <class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>
class exported ciphert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef ciphert derives; 
    
    /// constructors / destructor
    ciphert(const ciphert& copy): extends(copy) {
    }
    ciphert() {
    }
    virtual ~ciphert() {
    }
}; /// class ciphert
typedef ciphert<> cipher;

} /// namespace block
} /// namespace generic
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_GENERIC_BLOCK_CIPHER_HPP
