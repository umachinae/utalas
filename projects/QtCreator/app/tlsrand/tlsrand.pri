########################################################################
# Copyright (c) 1988-2022 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: tlsrand.pri
#
# Author: $author$
#   Date: 1/30/2022
#
# generic QtCreator project .pri file for framework talas executable tlsrand
########################################################################

########################################################################
# tlsrand

# tlsrand TARGET
#
tlsrand_TARGET = tlsrand

# tlsrand INCLUDEPATH
#
tlsrand_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# tlsrand DEFINES
#
tlsrand_DEFINES += \
$${talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# tlsrand OBJECTIVE_HEADERS
#
#tlsrand_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/tlsrand/main.hh \

# tlsrand OBJECTIVE_SOURCES
#
#tlsrand_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/tlsrand/main.mm \

########################################################################
# tlsrand HEADERS
#
tlsrand_HEADERS += \
$${CIFRA_SRC}/xos/crypto/hash.hpp \
\
$${UTALAS_SRC}/xos/protocol/tls/pseudo/random/function.hpp \
$${UTALAS_SRC}/xos/protocol/tls/pseudo/random/reader.hpp \
\
$${UTALAS_SRC}/xos/app/console/talas/crypto/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/talas/crypto/main.hpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/pseudo/random/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/pseudo/random/main.hpp \

# tlsrand SOURCES
#
tlsrand_SOURCES += \
$${CIFRA_SRC}/xos/crypto/hash.cpp \
\
$${UTALAS_SRC}/xos/protocol/tls/pseudo/random/function.cpp \
$${UTALAS_SRC}/xos/protocol/tls/pseudo/random/reader.cpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/pseudo/random/main_opt.cpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/pseudo/random/main.cpp \

########################################################################
# tlsrand FRAMEWORKS
#
tlsrand_FRAMEWORKS += \
$${talas_FRAMEWORKS} \

# tlsrand LIBS
#
tlsrand_LIBS += \
$${talas_LIBS} \

########################################################################
# NO Qt
QT -= gui core

