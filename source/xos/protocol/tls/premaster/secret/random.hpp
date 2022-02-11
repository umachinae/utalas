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
///   Date: 2/9/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_PREMASTER_SECRET_RANDOM_HPP
#define XOS_PROTOCOL_TLS_PREMASTER_SECRET_RANDOM_HPP

#include "xos/protocol/tls/random/bytes.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace premaster {
namespace secret {

/// class randomt
template 
<class TRandomBytes = tls::random::bytest<46>, 
 class TExtends = TRandomBytes, class TImplements = typename TExtends::implements>

class exported randomt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef randomt derives; 
    
    typedef TRandomBytes random_bytes_t;
    typedef typename random_bytes_t::random_reader_t random_reader_t;

    /// constructors / destructor
    randomt(const randomt& copy): extends(copy) {
    }
    randomt(random_reader_t& random_reader): extends(random_reader) {
    }
    randomt() {
    }
    virtual ~randomt() {
    }

}; /// class randomt
typedef randomt<> random;

} /// namespace secret
} /// namespace premaster
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_PREMASTER_SECRET_RANDOM_HPP
