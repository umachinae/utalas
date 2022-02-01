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
///   File: random.hpp
///
/// Author: $author$
///   Date: 2/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_HELLO_RANDOM_HPP
#define XOS_PROTOCOL_TLS_HELLO_RANDOM_HPP

#include "xos/protocol/tls/message/part.hpp"
#include "xos/protocol/tls/random/bytes.hpp"
#include "xos/protocol/tls/gmt/unix/time.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace hello {

/// class randomt
template 
<class TGmtUnixTime = tls::gmt::unix::time, class TRandomBytes = tls::random::bytes, 
 class TRandomReader = tls::pseudo::random::reader, class TMessagePart = tls::message::part, 
 class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported randomt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef randomt derives; 
    
    typedef TGmtUnixTime gmt_unix_time_t;
    typedef TRandomBytes random_bytes_t;
    typedef TRandomReader random_reader_t;
    typedef TMessagePart message_part_t;

    /// constructors / destructor
    randomt
    (random_reader_t& random_reader, 
     const gmt_unix_time_t& gmt_unix_time, const random_bytes_t& random_bytes)
    : random_reader_(random_reader), 
      random_bytes_(random_bytes), gmt_unix_time_(gmt_unix_time) {
        combine();
    }
    randomt(random_reader_t& random_reader, const gmt_unix_time_t& gmt_unix_time)
    : random_reader_(random_reader), 
      random_bytes_(random_reader_), gmt_unix_time_(gmt_unix_time) {
        combine();
    }
    randomt(const randomt& copy)
    : random_reader_(copy.random_reader_), 
      random_bytes_(random_reader_), gmt_unix_time_(copy.gmt_unix_time_) {
        combine();
    }
    randomt(random_reader_t& random_reader)
    : random_reader_(random_reader), random_bytes_(random_reader_) {
        combine();
    }
    virtual ~randomt() {
    }

    /// combine / separate
    virtual bool combine() {
        bool success = false;
        const byte_t* bytes = 0;
        size_t length = 0;

        this->clear();
        if ((bytes = gmt_unix_time_.has_elements(length))) {
            this->append(bytes, length);
            if ((bytes = random_bytes_.has_elements(length))) {
                this->append(bytes, length);
                success = true;
            } else {
                this->clear();
            }
        }
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

protected:
    random_reader_t& random_reader_;
    random_bytes_t random_bytes_;
    gmt_unix_time_t gmt_unix_time_;
}; /// class randomt
typedef randomt<> random;

} /// namespace hello
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_HELLO_RANDOM_HPP
