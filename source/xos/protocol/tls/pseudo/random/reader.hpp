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
///   File: reader.hpp
///
/// Author: $author$
///   Date: 1/30/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PSEUDO_RANDOM_READER_HPP
#define XOS_PROTOCOL_TLS_PSEUDO_RANDOM_READER_HPP

#include "xos/protocol/tls/pseudo/random/function.hpp"
#include "talas/io/reader.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace pseudo {
namespace random {

typedef ::talas::io::byte_reader byte_reader_t;

/// class readert
template 
<class THash = sha256_t, 
 class TByteArray = byte_array_t, 
 class TByteReader = byte_reader_t, 
 class TFunction = functiont<THash, TByteArray>,  
 class TExtends = extend, class TImplements = byte_reader_t>
class exported readert: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef readert derives; 
    
    typedef THash hash_t;
    typedef TByteArray byte_array_t;
    typedef TFunction function_t;
    
    typedef typename implements::what_t what_t;
    typedef typename implements::sized_t sized_t;

    /// constructors / destructor
    readert(const readert& copy)
    : function_(copy.function()), length_(0), tell_(0) {
    }
    readert
    (const byte_array_t& secret, const byte_array_t& seed)
    : function_(secret, seed), length_(0), tell_(0) {
    }
    readert() {
    }
    virtual ~readert() {
    }

    /// read
    virtual ssize_t read(what_t* what, size_t size) {
        function_t& function = this->function();
        byte_array_t& array = this->array();
        size_t &length = this->length_, &tell = this->tell_;
        const byte_t* bytes = 0; sized_t* sized = 0;

        if (!(bytes = array.has_elements(length))) {
            if (!(bytes = function.iterate_begin(length))) {
                return -1;
            }
            array.assign(bytes, length);
            if (!(bytes = array.has_elements(length))) {
                return -1;
            }
            tell = 0;
        }
        if ((sized = ((sized_t*)what)) && (size) && (length >= (tell))) {
            ssize_t count = 0;

            if (length < (tell + size)) {
                size_t read_size = size;
                if (1 > (size = length - tell)) {
                    if (!(bytes = function.iterate(length))) {
                        return -1;
                    }
                    array.assign(bytes, length);
                    if (!(bytes = array.has_elements(length))) {
                        return -1;
                    }
                    size = read_size;
                    tell = 0;
                    if (length < (tell + size)) {
                        if (1 > (size = length - tell)) {
                            return -1;
                        }
                    }
                }
            }
            if ((sizeof(sized_t) != sizeof(byte_t))) {
                return -1;
            } else {
                for (bytes += tell; size; --size, ++bytes, ++sized, ++count) {
                    *sized = *(((const sized_t*)bytes));
                }
            }
            tell += count;
            return count;
        }
        return 0;
    }

    /// function...
    virtual function_t& function() const {
        return (function_t&)function_;
    }
    virtual ssize_t length() const {
        return (ssize_t)length_;
    }
    virtual ssize_t tell() const {
        return (ssize_t)tell_;
    }
    virtual byte_array_t& array() const {
        return (byte_array_t&)array_;
    }

protected:
    function_t function_;
    size_t length_, tell_;
    byte_array_t array_;
}; /// class readert
typedef readert<> reader;

} /// namespace random
} /// namespace pseudo
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_PSEUDO_RANDOM_READER_HPP
