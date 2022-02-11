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
///   File: message.hpp
///
/// Author: $author$
///   Date: 2/9/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_TLS_CLIENT_KEY_EXCHANGE_MESSAGE_HPP
#define XOS_PROTOCOL_TLS_CLIENT_KEY_EXCHANGE_MESSAGE_HPP

#include "xos/protocol/tls/key/exchange/algorithm.hpp"
#include "xos/protocol/tls/premaster/secret/message.hpp"

namespace xos {
namespace protocol {
namespace tls {
namespace client {
namespace key {
namespace exchange {

/// class messaget
template 
<typename TKeyExchangeAlgorithm = tls::key::exchange::algorithm, 
 TKeyExchangeAlgorithm VKeyExchangeAlgorithmNone = tls::key::exchange::none,
 TKeyExchangeAlgorithm VKeyExchangeAlgorithmRsa = tls::key::exchange::rsa,
 TKeyExchangeAlgorithm VKeyExchangeAlgorithmRsaPlain = tls::key::exchange::rsa_plain,
 class TPreMasterSecret = tls::premaster::secret::message,
 class TMessagePart = tls::message::part, class TExtends = TMessagePart, class TImplements = typename TExtends::implements>

class exported messaget: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef messaget derives; 
    
    typedef TKeyExchangeAlgorithm key_exchange_algorithm_t;
    enum { 
        key_exchange_algorithm_none = VKeyExchangeAlgorithmNone,
        key_exchange_algorithm_rsa = VKeyExchangeAlgorithmRsa,
        key_exchange_algorithm_rsa_plain = VKeyExchangeAlgorithmRsaPlain
    };
    typedef TPreMasterSecret pre_master_secret_t;
    
    /// constructors / destructor
    messaget(const messaget& copy)
    : extends(copy), key_exchange_algorithm_(copy.key_exchange_algorithm_) {
    }
    messaget(const pre_master_secret_t& pre_master_secret)
    : key_exchange_algorithm_(key_exchange_algorithm_rsa_plain) {
        combine(pre_master_secret);
    }
    messaget(): key_exchange_algorithm_(key_exchange_algorithm_none) {
    }
    virtual ~messaget() {
    }

    /// combine / separate
    virtual bool combine(const pre_master_secret_t& pre_master_secret) {
        bool success = false;
        this->set_length(0);
        if ((this->append(pre_master_secret))) {
            success = true;
        }
        return success;
    }
    virtual bool combine() {
        bool success = false;
        return success;
    }
    virtual bool separate() {
        bool success = false;
        return success;
    }

protected:
    key_exchange_algorithm_t key_exchange_algorithm_;
}; /// class messaget
typedef messaget<> message;

} /// namespace exchange
} /// namespace key
} /// namespace client
} /// namespace tls
} /// namespace protocol
} /// namespace xos

#endif /// XOS_PROTOCOL_TLS_CLIENT_KEY_EXCHANGE_MESSAGE_HPP
