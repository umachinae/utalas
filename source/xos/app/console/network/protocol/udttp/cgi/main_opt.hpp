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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 3/2/2022
///////////////////////////////////////////////////////////////////////
#ifndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_UDTTP_CGI_MAIN_OPT_HPP
#define XOS_APP_CONSOLE_NETWORK_PROTOCOL_UDTTP_CGI_MAIN_OPT_HPP

#include "xos/app/console/network/protocol/http/cgi/main.hpp"
#include "xos/protocol/http/text/plain/content/type.hpp"
#include "xos/protocol/http/text/content.hpp"

namespace xos {
namespace app {
namespace console {
namespace network {
namespace protocol {
namespace udttp {
namespace cgi {

/// class main_optt
template 
<class TExtends = xos::app::console::network::protocol::http::cgi::main, 
 class TImplements = typename TExtends::implements>

class exported main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef main_optt derives;

    typedef typename extends::char_t char_t;
    typedef typename extends::end_char_t end_char_t;
    enum { end_char = extends::end_char };
    typedef typename extends::string_t string_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;
    typedef typename extends::file_t file_t;

    /// constructor / destructor
    main_optt(): run_(0) {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt& copy) {
        throw exception(exception_unexpected);
    }

protected:
    typedef typename extends::in_reader_t in_reader_t;
    typedef typename extends::out_writer_t out_writer_t;
    typedef typename extends::err_writer_t err_writer_t;

    typedef typename extends::reader this_reader_t;
    typedef typename extends::writer this_writer_t;

    typedef xos::protocol::http::text::content text_content_t;
    typedef xos::protocol::http::text::plain::content::type text_content_type_t;
    typedef typename extends::content_reader_t content_reader_t;
    typedef typename extends::environment_value_t environment_value_t;
    enum {
        CONTENT_LENGTH = extends::CONTENT_LENGTH,
        CONTENT_TYPE = extends::CONTENT_TYPE
    };
    
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

protected:
}; /// class main_optt
typedef main_optt<> main_opt;

} /// namespace cgi
} /// namespace udttp
} /// namespace protocol
} /// namespace network
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// ndef XOS_APP_CONSOLE_NETWORK_PROTOCOL_UDTTP_CGI_MAIN_OPT_HPP
