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
#   File: utls.pri
#
# Author: $author$
#   Date: 3/9/2022
#
# generic QtCreator project .pri file for framework utalas executable utls
########################################################################

########################################################################
# utls

# utls TARGET
#
utls_TARGET = utls

# utls INCLUDEPATH
#
utls_INCLUDEPATH += \
$${utalas_INCLUDEPATH} \

# utls DEFINES
#
utls_DEFINES += \
$${utalas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# utls OBJECTIVE_HEADERS
#
#utls_OBJECTIVE_HEADERS += \
#$${UTALAS_SRC}/xos/app/console/utls/main.hh \

# utls OBJECTIVE_SOURCES
#
#utls_OBJECTIVE_SOURCES += \
#$${UTALAS_SRC}/xos/app/console/utls/main.mm \

########################################################################
# utls HEADERS
#
utls_HEADERS += \
$${CIFRA_SRC}/xos/crypto/hash.hpp \
\
$${UTALAS_SRC}/xos/crypto/random/generator.hpp \
$${UTALAS_SRC}/xos/crypto/pseudo/random/generator.hpp \
$${UTALAS_SRC}/xos/crypto/random/reader.hpp \
$${UTALAS_SRC}/xos/crypto/pseudo/random/reader.hpp \
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
\
$${UTALAS_SRC}/xos/app/console/talas/crypto/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/talas/crypto/main.hpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/base/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/base/main.hpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/client/main_opt.hpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/client/main.hpp \

# utls SOURCES
#
utls_SOURCES += \
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
$${UTALAS_SRC}/xos/protocol/tls/decrypted/premaster/secret.cpp \
\
$${UTALAS_SRC}/xos/app/console/protocol/tls/client/main_opt.cpp \
$${UTALAS_SRC}/xos/app/console/protocol/tls/client/main.cpp \

########################################################################
# utls FRAMEWORKS
#
utls_FRAMEWORKS += \
$${utalas_FRAMEWORKS} \

# utls LIBS
#
utls_LIBS += \
$${utalas_rsa_LIBS} \

########################################################################
# NO Qt
QT -= gui core
