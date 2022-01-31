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
///   File: main_opt.cpp
///
/// Author: $author$
///   Date: 1/27/2022
///////////////////////////////////////////////////////////////////////
#include "xos/app/console/utalas/main_opt.hpp"

#if !defined(XOS_APP_CONSOLE_UTALAS_MAIN_OPT_INSTANCE)
///#define XOS_APP_CONSOLE_UTALAS_MAIN_OPT_INSTANCE
#endif /// !defined(XOS_APP_CONSOLE_UTALAS_MAIN_OPT_INSTANCE)

#if defined(XOS_APP_CONSOLE_UTALAS_MAIN_OPT_INSTANCE)
#if !defined(NO_XOS_CONSOLE_MAIN_MAIN)
#include "xos/console/main_main.cpp"
#endif /// !defined(NO_XOS_CONSOLE_MAIN_MAIN)
#endif /// defined(XOS_APP_CONSOLE_UTALAS_MAIN_OPT_INSTANCE)

namespace xos {
namespace app {
namespace console {
namespace utalas {

/// class main_optt
#if defined(XOS_APP_CONSOLE_UTALAS_MAIN_OPT_INSTANCE)
static main_opt the_main_opt;
#endif /// defined(XOS_APP_CONSOLE_UTALAS_MAIN_OPT_INSTANCE)

} /// namespace utalas
} /// namespace console
} /// namespace app
} /// namespace xos
