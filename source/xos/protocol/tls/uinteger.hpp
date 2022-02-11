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
///   File: uinteger.hpp
///
/// Author: $author$
///   Date: 2/2/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_UINTEGER_HPP
#define XOS_PROTOCOL_TLS_UINTEGER_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {

/// class uintegert
template 
<typename TUinteger = unsigned, size_t VSizeOf = sizeof (TUinteger), 
 class TMessagePart = tls::message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported uintegert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef uintegert derives; 
    
    typedef TUinteger uinteger_t;
    enum {size_of = VSizeOf};
    
    /// constructors / destructor
    uintegert(const uintegert& copy): value_(copy.value_) {
        combine();
    }
    uintegert(const uinteger_t& value): value_(value) {
        combine();
    }
    uintegert(): value_(0) {
        combine();
    }
    virtual ~uintegert() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = false;
        if ((this->to_msb(value_, size_of))) {
            success = true;
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

    /// ...value
    virtual const uinteger_t& set_value(const uinteger_t& to) {
        value_ = to;
        combine();
        return value_;
    }
    virtual const uinteger_t& value() const {
        return value_;
    }

protected:
    uinteger_t value_;
}; /// class uintegert
typedef uintegert<> uinteger;

typedef uintegert<uint8_t> uint8;
typedef uintegert<uint16_t> uint16;
typedef uintegert<uint32_t, 3> uint24;
typedef uintegert<uint32_t> uint32;
typedef uintegert<uint64_t> uint64;

} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_UINTEGER_HPP
