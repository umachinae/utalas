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
#   File: tlsd.pri
#
# Author: $author$
#   Date: 2/14/2022
#
# generic QtCreator project .pri file for framework talas executable tlsd
########################################################################

########################################################################
# tlsd

# tlsd TARGET
#
tlsd_TARGET = tlsd

# tlsd INCLUDEPATH
#
tlsd_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# tlsd DEFINES
#
tlsd_DEFINES += \
$${talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# tlsd OBJECTIVE_HEADERS
#
#tlsd_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/tlsd/main.hh \

# tlsd OBJECTIVE_SOURCES
#
#tlsd_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/tlsd/main.mm \

########################################################################
# tlsd HEADERS
#
tlsd_HEADERS += \
$${CIFRA_SRC}/xos/crypto/hash.hpp \
\
$${UTALAS_SRC}/xos/protocol/tls/message/part.hpp \
$${UTALAS_SRC}/xos/protocol/tls/pseudo/random/reader.hpp \
$${UTALAS_SRC}/xos/protocol/tls/protocol/version.hpp \
$${UTALAS_SRC}/xos/protocol/tls/gmt/unix/time.hpp \
$${UTALAS_SRC}/xos/protocol/tls/random/bytes.hpp \
$${UTALAS_SRC}/xos/protocol/tls/hello/random.hpp \
$${UTALAS_SRC}/xos/protocol/tls/handshake/type/which.hpp \
$${UTALAS_SRC}/xos/protocol/tls/uinteger.hpp \
$${UTALAS_SRC}/xos/protocol/tls/vector.hpp \
$${UTALAS_SRC}/xos/protocol/tls/session/identifier.hpp \
$${UTALAS_SRC}/xos/protocol/tls/handshake/message.hpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suite.hpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suites.hpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/method.hpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/methods.hpp \
$${UTALAS_SRC}/xos/protocol/tls/client/hello.hpp \
$${UTALAS_SRC}/xos/protocol/tls/premaster/secret/random.hpp \
$${UTALAS_SRC}/xos/protocol/tls/premaster/secret/message.hpp \
$${UTALAS_SRC}/xos/protocol/tls/pkcs1/encoded/message.hpp \
$${UTALAS_SRC}/xos/protocol/tls/pkcs1/encoded/premaster/secret.hpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/key.hpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/public_key.hpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/bn/public_key.hpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/gmp/public_key.hpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/implemented/public_key.hpp \
$${UTALAS_SRC}/xos/protocol/tls/encrypted/premaster/secret.hpp \
$${UTALAS_SRC}/xos/protocol/tls/client/key/exchange/message.hpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/private_key.hpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/bn/private_key.hpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/gmp/private_key.hpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/implemented/private_key.hpp \
$${UTALAS_SRC}/xos/protocol/tls/decrypted/premaster/secret.hpp \
$${UTALAS_SRC}/xos/protocol/tls/pkcs1/decoded/message.hpp \
$${UTALAS_SRC}/xos/protocol/tls/pkcs1/decoded/premaster/secret.hpp \
$${UTALAS_SRC}/xos/protocol/tls/master/secret.hpp \
\
$${UTALAS_SRC}/xos/app/console/talas/crypto/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/talas/crypto/main.hpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/base/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/base/main.hpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/server/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/server/main.hpp \

# tlsd SOURCES
#
tlsd_SOURCES += \
$${CIFRA_SRC}/xos/crypto/hash.cpp \
\
$${UTALAS_SRC}/xos/protocol/tls/message/part.cpp \
$${UTALAS_SRC}/xos/protocol/tls/protocol/version.cpp \
$${UTALAS_SRC}/xos/protocol/tls/gmt/unix/time.cpp \
$${UTALAS_SRC}/xos/protocol/tls/random/bytes.cpp \
$${UTALAS_SRC}/xos/protocol/tls/hello/random.cpp \
$${UTALAS_SRC}/xos/protocol/tls/handshake/type/which.cpp \
$${UTALAS_SRC}/xos/protocol/tls/uinteger.cpp \
$${UTALAS_SRC}/xos/protocol/tls/vector.cpp \
$${UTALAS_SRC}/xos/protocol/tls/session/identifier.cpp \
$${UTALAS_SRC}/xos/protocol/tls/handshake/message.cpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suite.cpp \
$${UTALAS_SRC}/xos/protocol/tls/cipher/suites.cpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/method.cpp \
$${UTALAS_SRC}/xos/protocol/tls/compression/methods.cpp \
$${UTALAS_SRC}/xos/protocol/tls/client/hello.cpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/key.cpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/implemented/public_key.cpp \
$${UTALAS_SRC}/xos/protocol/tls/rsa/implemented/private_key.cpp \
$${UTALAS_SRC}/xos/protocol/tls/master/secret.cpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/server/main_opt.cpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/server/main.cpp \

########################################################################
# tlsd FRAMEWORKS
#
tlsd_FRAMEWORKS += \
$${talas_FRAMEWORKS} \

# tlsd LIBS
#
tlsd_LIBS += \
$${talas_rsa_LIBS} \

########################################################################
# NO Qt
QT -= gui core

