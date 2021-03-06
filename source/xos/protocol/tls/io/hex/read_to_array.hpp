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
///   File: read_to_array.hpp
///
/// Author: $author$
///   Date: 5/2/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_IO_HEX_READ_TO_ARRAY_HPP
#define XOS_PROTOCOL_TLS_IO_HEX_READ_TO_ARRAY_HPP

#include "xos/protocol/tls/io/hex/reader.hpp"
#include "xos/protocol/tls/io/logger.hpp"
#include "xos/protocol/tls/array.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace io {
namespace hex {

/// class read_to_arrayt
template 
<class TArray = tls::byte_array_t, 
 class TReaderEvents = tls::io::hex::reader_events, 
 class TImplements = TReaderEvents, class TExtends = extend>

class exported read_to_arrayt: virtual public TImplements {
public:
    typedef TImplements Implements, implements;
    typedef TExtends Extends, extends;
    typedef read_to_arrayt Derives, derives; 
    
    typedef TArray array_t;
    typedef typename array_t::what_t element_t;
    typedef TReaderEvents reader_events_t;
    typedef typename reader_events_t::what_t what_t;
    typedef typename reader_events_t::sized_t sized_t;

    /// constructors / destructor
    read_to_arrayt(array_t &array): array_(array), byte_(0), nibble_(0) {
    }
    read_to_arrayt(): array_(this_array_), byte_(0), nibble_(0) {
    }
    virtual ~read_to_arrayt() {
    }
private:
    read_to_arrayt(const read_to_arrayt& copy): array_(this_array_), byte_(0), nibble_(0) {
    }
public:

    /// on_...
    virtual ssize_t on_begin(what_t* what, size_t size) {
        array_.set_length(0);
        byte_ = nibble_ = 0;
        return size;
    }
    virtual ssize_t on_end(what_t* what, size_t size) {
        return size;
    }
    virtual ssize_t on_hex_digit(unsigned d, what_t* what, size_t size) {
        byte_t n = ((byte_t)(d & 15)); 
        byte_ = ((byte_ << 4) | n);
        if ((nibble_++)) {
            element_t e = ((element_t)byte_);
            array_.append(&e, 1);
            byte_ = nibble_ = 0;
         }
        return size;
    }

protected:
    array_t this_array_, &array_;
    byte_t byte_, nibble_;
}; /// class read_to_arrayt
typedef read_to_arrayt<> read_to_array;

typedef read_to_arrayt<tls::byte_array_t> read_to_byte_array;

} /// namespace hex
} /// namespace io
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_TLS_IO_HEX_READ_TO_ARRAY_HPP
