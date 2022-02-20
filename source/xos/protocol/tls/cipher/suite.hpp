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
///   File: suite.hpp
///
/// Author: $author$
///   Date: 2/8/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CIPHER_SUITE_HPP
#define XOS_PROTOCOL_TLS_CIPHER_SUITE_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace cipher {

typedef uint8_t suite_which_t;
typedef uint8_t suite_with_t;
enum {
    RSA = 0x00
};
enum {
    WITH_AES_256_CBC_SHA256 = 0x3D
};

/// class suitet
template 
<typename TWhich = suite_which_t, TWhich VWhich = RSA, 
 typename TWith = suite_with_t, TWith VWith = WITH_AES_256_CBC_SHA256,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported suitet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef suitet derives; 
    
    typedef TWhich which_t;
    enum { which = VWhich };

    typedef TWith with_t;
    enum { with = VWith };
    
    /// constructors / destructor
    suitet(const suitet& copy): which_(copy.which_), with_(copy.which_) {
        combine();
    }
    suitet(const which_t& which, const which_t& with): which_(which), with_(with) {
        combine();
    }
    suitet(): which_(which), with_(with) {
        combine();
    }
    virtual ~suitet() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = false;
        if ((this->set_to_msb(which_))) {
            if ((this->to_msb(with_))) {
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
    which_t which_;
    with_t with_;
}; /// class suitet
typedef suitet<> suite;

} /// namespace cipher
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_CIPHER_SUITE_HPP
