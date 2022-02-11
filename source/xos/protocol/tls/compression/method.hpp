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
///   File: method.hpp
///
/// Author: $author$
///   Date: 2/8/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_COMPRESSION_METHOD_HPP
#define XOS_PROTOCOL_TLS_COMPRESSION_METHOD_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace compression {

typedef uint8_t method_which_t;
enum {
    method_none = 0x00
};

/// class methodt
template 
<typename TWhich = method_which_t, TWhich VWhichDefault = method_none, 
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported methodt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef methodt derives; 
    
    typedef TWhich which_t;
    enum { which_default = VWhichDefault };
    
    /// constructors / destructor
    methodt(const methodt& copy): which_(copy.which_) {
        combine();
    }
    methodt(const which_t& which): which_(which) {
        combine();
    }
    methodt(): which_(which_default) {
        combine();
    }
    virtual ~methodt() {
    }
    
    /// combine / separate
    virtual bool combine() {
        bool success = false;
        if ((this->set_to_msb(which_))) {
            success = true;
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

protected:
    which_t which_;
}; /// class methodt
typedef methodt<> method;

} /// namespace compression
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_COMPRESSION_METHOD_HPP
