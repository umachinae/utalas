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
///   File: part.hpp
///
/// Author: $author$
///   Date: 2/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_MESSAGE_PART_HPP
#define XOS_PROTOCOL_TLS_MESSAGE_PART_HPP

#include "talas/base/array.hpp"
#include "xos/base/logged.hpp"
#include "xos/base/logger.hpp"
#include "xos/io/sequence.hpp"
#include "xos/io/seeker.hpp"
#include "xos/io/reader.hpp"
#include "xos/io/writer.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace message {

/// class partt
template 
<class TByteArray = ::talas::byte_array_t, 
 class TExtends = TByteArray, class TImplements = typename TExtends::implements>

class exported partt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef partt derives; 
    
    typedef TByteArray byte_array_t;

    /// constructors / destructor
    partt(const byte_array_t& bytes): extends(bytes), is_combined_(true) {
    }
    partt(const byte_t* bytes, size_t length): extends(bytes, length), is_combined_(true) {
    }
    partt(const partt& copy): extends(copy), is_combined_(copy.is_combined()) {
    }
    partt(): is_combined_(true) {
    }
    virtual ~partt() {
    }

    /// clear / ...set
    virtual size_t clear() {
        return extends::clear();
    }
    virtual size_t set(const partt& to) {
        return set(to);
    }
    virtual size_t set(const byte_array_t& to) {
        const byte_t* bytes = 0; size_t length = 0;
        if ((bytes = to.has_elements(length))) {
            this->assign(bytes, length);
        } else {
            clear();
        }
        separate();
        return length;
    }
    virtual size_t set(const byte_t* to, size_t length) {
        this->assign(to, length);
        separate();
        return length;
    }
    virtual bool is_set(const byte_array_t& to) {
        bool success = false;
        const byte_t* bytes = 0; size_t length = 0;
        if ((bytes = to.has_elements(length))) {
            this->assign(bytes, length);
        } else {
            clear();
        }
        success = separate();
        return success;
    }
    virtual bool is_set(const byte_t* to, size_t length) {
        bool success = false;
        this->assign(to, length);
        success = separate();
        return success;
    }

    /// append
    using extends::append;
    virtual size_t append(const byte_array_t& to) {
        const byte_t* bytes = 0; size_t length = 0;
        if ((bytes = to.has_elements(length))) {
            this->append(bytes, length);
            return length;
        }
        return 0;
    }

    /// combine / separate
    virtual bool combine() {
        bool success = false;
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

    /// set_default...
    virtual derives& set_default() {
        this->clear();
        set_defaults();
        return *this;
    }
    virtual derives& set_defaults() {
        return *this;
    }

    /// ...is_combined
    virtual bool set_is_combined(bool to = true) {
        is_combined_ = to;
        return is_combined_;
    }
    virtual bool is_combined() const {
        return is_combined_;
    }

    /// ...is_logged
    virtual bool set_is_logged(bool to = true) {
        return logged_.set_is_logged(to);
    }
    virtual bool is_logged() const {
        return logged_.is_logged();
    }

    /// ...to_msb
    template <typename part_t>
    size_t& set_to_msb(const part_t& part) {
        size_t size = sizeof(part);
        return set_to_msb(part, size);
    }
    template <typename part_t>
    size_t& to_msb(const part_t& part) {
        size_t size = sizeof(part);
        return to_msb(part, size);
    }
    template <typename part_t>
    size_t& set_to_msb(const part_t& part, size_t size) {
        this->set_length(0);
        return to_msb(part, size);
    }
    template <typename part_t>
    size_t& to_msb(const part_t& part, size_t size) {
        size_t remain = 0;
        part_t lsb = 0, msb = 0;

        for (msb = 0, lsb = part, remain = size; remain; --remain, lsb >>= 8) {
            ((msb <<= 8)) |= (lsb & 0xFF);
        }
        for (remain = size; remain; --remain, msb >>= 8) {
            byte_t byte = (msb & 0xFF);
            this->append(&byte, 1);
        }
        return size;
    }

protected:
    bool is_combined_;
    xos::extended::logged logged_;
}; /// class partt
typedef partt<> part;

} /// namespace message
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_MESSAGE_PART_HPP
