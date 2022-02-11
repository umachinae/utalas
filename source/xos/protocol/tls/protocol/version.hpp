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
///   File: version.hpp
///
/// Author: $author$
///   Date: 1/31/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PROTOCOL_VERSION_HPP
#define XOS_PROTOCOL_TLS_PROTOCOL_VERSION_HPP

#include "xos/protocol/tls/message/part.hpp"

#define XOS_PROTOCOL_TLS_PROTOCOL_VERSION_MAJOR 3
#define XOS_PROTOCOL_TLS_PROTOCOL_VERSION_MINOR 3

namespace xos {
namespace protocol {
namespace tls {
namespace protocol {

/// class versiont
template 
<typename TPart = uint8_t, class TMessagePart = tls::message::part,
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported versiont: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef versiont derives; 
    
    typedef TPart part_t;
    typedef TMessagePart message_part_t;
    
    /// constructors / destructor
    versiont(const versiont& copy): major_(copy.major()), minor_(copy.minor()) {
        combine();
    }
    versiont()
    : major_(XOS_PROTOCOL_TLS_PROTOCOL_VERSION_MAJOR),
      minor_(XOS_PROTOCOL_TLS_PROTOCOL_VERSION_MINOR) {
        combine();
    }
    virtual ~versiont() {
    }
    
    /// combine / separate
    virtual bool combine() {
        bool success = true;
        to_msb(major_, minor_);
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

    /// ...to_msb
    using extends::to_msb;
    virtual size_t& to_msb(const part_t& major, const part_t& minor) {
        size_t length = 0, size = 0;
        
        this->set_length(length = 0);
        if (sizeof(major_) <= (size = this->to_msb(major))) {
            length += size;
            if (sizeof(minor_) <= (size = this->to_msb(minor))) {
                length += size;
            }
        }
        return length;
    }
    
    /// ...major / minor...
    virtual part_t& major() const {
        return (part_t&)major_;
    }
    virtual part_t& minor() const {
        return (part_t&)minor_;
    }

protected:
    part_t major_, minor_;
}; /// class versiont
typedef versiont<> version;

} /// namespace protocol
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_PROTOCOL_VERSION_HPP
