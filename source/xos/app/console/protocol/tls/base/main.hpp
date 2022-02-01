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
///   File: main.hpp
///
/// Author: $author$
///   Date: 1/31/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_HPP

#include "xos/app/console/protocol/tls/base/main_opt.hpp"
#include "xos/protocol/tls/pseudo/random/reader.hpp"
#include "xos/protocol/tls/protocol/version.hpp"
#include "xos/protocol/tls/gmt/unix/time.hpp"
#include "xos/protocol/tls/random/bytes.hpp"
#include "xos/protocol/tls/hello/random.hpp"

#define XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_PSEUDO_RANDOM_SECRET "E5B62E66-8349-11EC-8C95-7F8924CBD8A2"
#define XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_PSEUDO_RANDOM_SEED "ECBD992E-8349-11EC-9EC2-259E551AB68D"

namespace xos {
namespace app {
namespace console {
namespace protocol {
namespace tls {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::protocol::tls::base::main_opt, 
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint()
    : run_(0), 
      secret_string_(XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_PSEUDO_RANDOM_SECRET), 
      seed_string_(XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_PSEUDO_RANDOM_SEED) {
        set_secret(secret_string());
        set_seed(seed_string());
    }
    virtual ~maint() {
    }
private:
    maint(const maint& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    /// ...run
    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = extends::run(argc, argv, env);
        }
        return err;
    }

    /// ...output_protocol_version_run
    virtual int output_protocol_version_run(int argc, char_t** argv, char_t** env) {
        ::xos::protocol::tls::pseudo::random::reader random_reader(secret_, seed_);
        ::xos::protocol::tls::random::bytes random_bytes(random_reader);
        ::xos::protocol::tls::gmt::unix::time gmt_unix_time;
        ::xos::protocol::tls::hello::random hello_random(random_reader, gmt_unix_time, random_bytes);
        int err = 0;
        this->output_hex_run(protocol_version_, argc, argv, env);
        this->output_hex_run(gmt_unix_time, argc, argv, env);
        this->output_hex_run(random_bytes, argc, argv, env);
        this->output_hex_run(hello_random, argc, argv, env);
        return err;
    }

    /// ...secret...
    virtual ::talas::string_t& set_secret_string(const char_t* to) {
        if ((to) && (to[0])) {
            secret_string_.assign(to);
        }
        return (::talas::string_t&)secret_string_;
    }
    virtual ::talas::string_t& secret_string() const {
        return (::talas::string_t&)secret_string_;
    }
    virtual ::talas::byte_array_t& set_secret(::talas::string_t& to) {
        const char_t* chars = 0; size_t length = 0;
        if ((chars = to.has_chars(length))) {
            set_secret(chars, length);
        }
        return (::talas::byte_array_t&)secret_;
    }
    virtual ::talas::byte_array_t& set_secret(const char_t* to, size_t length) {
        const byte_t* bytes = 0;
        if ((bytes = (const byte_t*)to) && (length)) {
         secret_.assign(bytes, length);
        }
        return (::talas::byte_array_t&)secret_;
    }
    virtual ::talas::byte_array_t& secret() const {
        return (::talas::byte_array_t&)secret_;
    }

    /// ...seed...
    virtual ::talas::string_t& set_seed_string(const char_t* to) {
        if ((to) && (to[0])) {
            seed_string_.assign(to);
        }
        return (::talas::string_t&)seed_string_;
    }
    virtual ::talas::string_t& seed_string() const {
        return (::talas::string_t&)seed_string_;
    }
    virtual ::talas::byte_array_t& set_seed(::talas::string_t& to) {
        const char_t* chars = 0; size_t length = 0;
        if ((chars = to.has_chars(length))) {
            set_seed(chars, length);
        }
        return (::talas::byte_array_t&)seed_;
    }
    virtual ::talas::byte_array_t& set_seed(const char_t* to, size_t length) {
        const byte_t* bytes = 0;
        if ((bytes = (const byte_t*)to) && (length)) {
         seed_.assign(bytes, length);
        }
        return (::talas::byte_array_t&)seed_;
    }
    virtual ::talas::byte_array_t& seed() const {
        return (::talas::byte_array_t&)seed_;
    }

protected:
    ::talas::string_t secret_string_, seed_string_;
    ::talas::byte_array_t secret_, seed_;
    xos::protocol::tls::protocol::version protocol_version_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace tls
} /// namespace protocol
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_PROTOCOL_TLS_BASE_MAIN_HPP
