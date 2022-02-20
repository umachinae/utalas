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
#   File: udfy.pri
#
# Author: $author$
#   Date: 2/18/2022
#
# generic QtCreator project .pri file for framework talas executable udfy
########################################################################

########################################################################
# udfy

# udfy TARGET
#
udfy_TARGET = udfy

# udfy INCLUDEPATH
#
udfy_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# udfy DEFINES
#
udfy_DEFINES += \
$${talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# udfy OBJECTIVE_HEADERS
#
#udfy_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/protocol/udtp/base/main.hh \

# udfy OBJECTIVE_SOURCES
#
#udfy_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/protocol/udtp/base/main.mm \

########################################################################
# udfy HEADERS
#
udfy_HEADERS += \
$${UTALAS_SRC}/xos/protocol/tls/protocol/version.hpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suite.hpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suites.hpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/method.hpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/methods.hpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/udtp/base/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/protocol/udtp/base/main.hpp \

# udfy SOURCES
#
udfy_SOURCES += \
$${UTALAS_SRC}/xos/protocol/tls/protocol/version.cpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suite.cpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suites.cpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/method.cpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/methods.cpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/udtp/base/main_opt.cpp \
$${UTALAS_SRC}/xos/app/console/protocol/udtp/base/main.cpp \

########################################################################
# udfy FRAMEWORKS
#
udfy_FRAMEWORKS += \
$${talas_FRAMEWORKS} \

# udfy LIBS
#
udfy_LIBS += \
$${talas_rsa_LIBS} \

########################################################################
# NO Qt
QT -= gui core

