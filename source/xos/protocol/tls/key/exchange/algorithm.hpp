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
///   File: algorithm.hpp
///
/// Author: $author$
///   Date: 2/9/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_KEY_EXCHANGE_ALGORITHM_HPP
#define XOS_PROTOCOL_TLS_KEY_EXCHANGE_ALGORITHM_HPP

#include "xos/protocol/tls/message/part.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace key {
namespace exchange {

/// enum algorithm
typedef uint8_t algorithm;
enum {
    dhe_dss, 
    dhe_rsa, 
    dh_anon, 
    rsa,
    dh_dss, 
    dh_rsa,
    rsa_plain,
    none
}; /// enum algorithm

} /// namespace exchange
} /// namespace key
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_KEY_EXCHANGE_ALGORITHM_HPP
