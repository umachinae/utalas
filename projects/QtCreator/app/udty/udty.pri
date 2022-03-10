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
#   File: udty.pri
#
# Author: $author$
#   Date: 3/9/2022
#
# generic QtCreator project .pri file for framework utalas executable udty
########################################################################

########################################################################
# udty

# udty TARGET
#
udty_TARGET = udty

# udty INCLUDEPATH
#
udty_INCLUDEPATH += \
$${utalas_INCLUDEPATH} \

# udty DEFINES
#
udty_DEFINES += \
$${utalas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# udty OBJECTIVE_HEADERS
#
#udty_OBJECTIVE_HEADERS += \
#$${UTALAS_SRC}/xos/app/console/udty/main.hh \

# udty OBJECTIVE_SOURCES
#
#udty_OBJECTIVE_SOURCES += \
#$${UTALAS_SRC}/xos/app/console/udty/main.mm \

########################################################################
# udty HEADERS
#
udty_HEADERS += \
$${CIFRA_SRC}/xos/crypto/hash.hpp \
\
$${UTALAS_SRC}/xos/crypto/random/generator.hpp \
$${UTALAS_SRC}/xos/crypto/pseudo/random/generator.hpp \
$${UTALAS_SRC}/xos/crypto/random/reader.hpp \
$${UTALAS_SRC}/xos/crypto/pseudo/random/reader.hpp \
\
$${UTALAS_SRC}/xos/protocol/tls/message/part.hpp \
$${UTALAS_SRC}/xos/protocol/tls/uinteger.hpp \
$${UTALAS_SRC}/xos/protocol/tls/vector.hpp \
\
$${UTALAS_SRC}/xos/protocol/tls/protocol/version.hpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suite.hpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suites.hpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/method.hpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/methods.hpp \
\
$${UTALAS_SRC}/xos/protocol/tls/gmt/unix/time.hpp \
$${UTALAS_SRC}/xos/protocol/tls/random/bytes.hpp \
$${UTALAS_SRC}/xos/protocol/tls/hello/random.hpp \
$${UTALAS_SRC}/xos/protocol/tls/session/identifier.hpp \
$${UTALAS_SRC}/xos/protocol/tls/client/hello.hpp \
$${UTALAS_SRC}/xos/protocol/tls/content/type.hpp \
$${UTALAS_SRC}/xos/protocol/tls/plaintext.hpp \
\
$${UTALAS_SRC}/xos/protocol/tls/connection/end.hpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/type.hpp \
$${UTALAS_SRC}/xos/protocol/tls/bulk/cipher/algorithm.hpp \
$${UTALAS_SRC}/xos/protocol/tls/mac/algorithm.hpp \
$${UTALAS_SRC}/xos/protocol/tls/prf/algorithm.hpp \
$${UTALAS_SRC}/xos/protocol/tls/security/parameters.hpp \
$${UTALAS_SRC}/xos/protocol/tls/generic/block/cipher.hpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/udtp/base/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/protocol/udtp/base/main.hpp \

# udty SOURCES
#
udty_SOURCES += \
$${CIFRA_SRC}/xos/crypto/hash.cpp \
\
$${UTALAS_SRC}/xos/protocol/tls/message/part.cpp \
$${UTALAS_SRC}/xos/protocol/tls/uinteger.cpp \
$${UTALAS_SRC}/xos/protocol/tls/vector.cpp \
\
$${UTALAS_SRC}/xos/protocol/tls/protocol/version.cpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suite.cpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suites.cpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/method.cpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/methods.cpp \
\
$${UTALAS_SRC}/xos/protocol/tls/gmt/unix/time.cpp \
$${UTALAS_SRC}/xos/protocol/tls/random/bytes.cpp \
$${UTALAS_SRC}/xos/protocol/tls/hello/random.cpp \
$${UTALAS_SRC}/xos/protocol/tls/session/identifier.cpp \
$${UTALAS_SRC}/xos/protocol/tls/client/hello.cpp \
$${UTALAS_SRC}/xos/protocol/tls/content/type.cpp \
$${UTALAS_SRC}/xos/protocol/tls/plaintext.cpp \
\
$${UTALAS_SRC}/xos/protocol/tls/connection/end.cpp \
$${UTALAS_SRC}/xos/protocol/tls/prf/algorithm.cpp \
$${UTALAS_SRC}/xos/protocol/tls/generic/block/cipher.cpp \
$${UTALAS_SRC}/xos/protocol/tls/security/parameters.cpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/udtp/base/main_opt.cpp \
$${UTALAS_SRC}/xos/app/console/protocol/udtp/base/main.cpp \

########################################################################
# udty FRAMEWORKS
#
udty_FRAMEWORKS += \
$${utalas_FRAMEWORKS} \

# udty LIBS
#
udty_LIBS += \
$${utalas_rsa_LIBS} \

########################################################################
# NO Qt
QT -= gui core

