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
///   Date: 3/1/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_UDTTP_BASE_MAIN_HPP
#define XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_UDTTP_BASE_MAIN_HPP

#include "xos/app/console/network/sockets/protocol/udttp/base/main_opt.hpp"
#include "xos/protocol/udtp/client/output.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace sockets {
namespace protocol {
namespace udttp {
namespace base {

/// class maint
template 
<class TExtends = xos::app::console::network::sockets::protocol::udttp::base::main_opt, 
 class TConsoleOutput = xos::protocol::udtp::client::console::output,
 class TImplements = typename TExtends::implements>

class exported maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef TConsoleOutput console_output_t;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    maint(): run_(0), connect_port_(8448) {
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

    /// ...output_generate_client_hello_run
    virtual int output_generate_client_hello_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        console_output_.output_generate_client_hello();
        return err;
    }

    /// ...output_private_key_run
    virtual int default_output_private_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        console_output_.output_private_key();
        return err;
    }
    virtual int default_output_public_key_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        console_output_.output_public_key();
        return err;
    }

    /// ...output_pseudo_random_secret_run
    virtual int default_output_pseudo_random_secret_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        console_output_.output_pseudo_random_secret();
        return err;
    }
    virtual int default_output_pseudo_random_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        console_output_.output_pseudo_random_seed();
        return err;
    }
    virtual int default_output_master_secret_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        console_output_.output_master_secret_seed();
        return err;
    }
    virtual int default_output_key_expansion_seed_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        console_output_.output_key_expansion_seed();
        return err;
    }

    /// console_output
    virtual console_output_t& console_output() const {
        return (console_output_t&)console_output_;
    }

    /// connect_port
    virtual short& connect_port() const {
        return (short&)connect_port_;
    }
protected:
    console_output_t console_output_;
    short connect_port_;
}; /// class maint
typedef maint<> main;

} /// namespace base
} /// namespace udttp
} /// namespace protocol
} /// namespace sockets
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_SOCKETS_PROTOCOL_UDTTP_BASE_MAIN_HPP
