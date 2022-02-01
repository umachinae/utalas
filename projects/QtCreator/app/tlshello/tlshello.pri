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
#   File: tlshello.pri
#
# Author: $author$
#   Date: 1/31/2022
#
# generic QtCreator project .pri file for framework talas executable tlshello
########################################################################

########################################################################
# tlshello

# tlshello TARGET
#
tlshello_TARGET = tlshello

# tlshello INCLUDEPATH
#
tlshello_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# tlshello DEFINES
#
tlshello_DEFINES += \
$${talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# tlshello OBJECTIVE_HEADERS
#
#tlshello_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/tlshello/main.hh \

# tlshello OBJECTIVE_SOURCES
#
#tlshello_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/tlshello/main.mm \

########################################################################
# tlshello HEADERS
#
tlshello_HEADERS += \
$${CIFRA_SRC}/xos/crypto/hash.hpp \
\
$${UTALAS_SRC}/xos/protocol/tls/message/part.hpp \
$${UTALAS_SRC}/xos/protocol/tls/protocol/version.hpp \
$${UTALAS_SRC}/xos/protocol/tls/gmt/unix/time.hpp \
$${UTALAS_SRC}/xos/protocol/tls/random/bytes.hpp \
$${UTALAS_SRC}/xos/protocol/tls/hello/random.hpp \
\
$${UTALAS_SRC}/xos/app/console/talas/crypto/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/talas/crypto/main.hpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/base/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/base/main.hpp \

# tlshello SOURCES
#
tlshello_SOURCES += \
$${CIFRA_SRC}/xos/crypto/hash.cpp \
\
$${UTALAS_SRC}/xos/protocol/tls/message/part.cpp \
$${UTALAS_SRC}/xos/protocol/tls/protocol/version.cpp \
$${UTALAS_SRC}/xos/protocol/tls/gmt/unix/time.cpp \
$${UTALAS_SRC}/xos/protocol/tls/random/bytes.cpp \
$${UTALAS_SRC}/xos/protocol/tls/hello/random.cpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/base/main_opt.cpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/base/main.cpp \

########################################################################
# tlshello FRAMEWORKS
#
tlshello_FRAMEWORKS += \
$${talas_FRAMEWORKS} \

# tlshello LIBS
#
tlshello_LIBS += \
$${talas_LIBS} \

########################################################################
# NO Qt
QT -= gui core
