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
#   File: rsa.pri
#
# Author: $author$
#   Date: 1/29/2022
#
# generic QtCreator project .pri file for framework talas executable rsa
########################################################################

########################################################################
# rsa

# rsa TARGET
#
rsa_TARGET = rsa

# rsa INCLUDEPATH
#
rsa_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# rsa DEFINES
#
rsa_DEFINES += \
$${talas_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# rsa OBJECTIVE_HEADERS
#
#rsa_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/rsa/main.hh \

# rsa OBJECTIVE_SOURCES
#
#rsa_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/rsa/main.mm \

########################################################################
# rsa HEADERS
#
rsa_HEADERS += \
$${TALAS_SRC}/talas/io/read/file.hpp \
$${TALAS_SRC}/talas/io/hex/reader.hpp \
$${TALAS_SRC}/talas/io/hex/read_to_array.hpp \
$${TALAS_SRC}/talas/io/hex/read_to_arrays.hpp \
\
$${TALAS_SRC}/talas/crypto/random/prime/small_primes.hpp \
$${TALAS_SRC}/talas/crypto/random/prime/bn/generator.hpp \
$${TALAS_SRC}/talas/crypto/random/prime/mp/generator.hpp \
\
$${TALAS_SRC}/talas/crypto/rsa/bn/key_generator.hpp \
$${TALAS_SRC}/talas/crypto/rsa/mp/key_generator.hpp \
\
$${TALAS_SRC}/xos/app/console/rsa/base/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/rsa/base/main.hpp \
\
$${TALAS_SRC}/xos/app/console/rsa/generate/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/rsa/generate/main.hpp \
\
$${TALAS_SRC}/xos/app/console/rsa/operate/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/rsa/operate/main.hpp \
\
$${TALAS_SRC}/xos/app/console/rsa/test/main_opt.hpp \
$${TALAS_SRC}/xos/app/console/rsa/test/main.hpp \


# rsa SOURCES
#
rsa_SOURCES += \
$${TALAS_SRC}/talas/io/read/file.cpp \
$${TALAS_SRC}/talas/io/hex/reader.cpp \
$${TALAS_SRC}/talas/io/hex/read_to_array.cpp \
$${TALAS_SRC}/talas/io/hex/read_to_arrays.cpp \
\
$${TALAS_SRC}/talas/crypto/random/prime/small_primes.cpp \
\
$${TALAS_SRC}/xos/app/console/rsa/test/main_opt.cpp \
$${TALAS_SRC}/xos/app/console/rsa/test/main.cpp \

########################################################################
# rsa FRAMEWORKS
#
rsa_FRAMEWORKS += \
$${talas_FRAMEWORKS} \

# rsa LIBS
#
rsa_LIBS += \
$${talas_rsa_LIBS} \

########################################################################
# NO Qt
QT -= gui core

