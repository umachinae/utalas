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
#   Date: 2/18/2022
#
# generic QtCreator project .pri file for framework talas executable udty
########################################################################

########################################################################
# udty

# udty TARGET
#
udty_TARGET = udty

# udty INCLUDEPATH
#
udty_INCLUDEPATH += \
$${talas_INCLUDEPATH} \

# udty DEFINES
#
udty_DEFINES += \
$${talas_DEFINES} \

#DEFAULT_LOGGING_LEVELS_ERROR \
#XOS_CONSOLE_MAIN_MAIN \

########################################################################
# udty OBJECTIVE_HEADERS
#
#udty_OBJECTIVE_HEADERS += \
#$${TALAS_SRC}/xos/app/console/protocol/udtp/base/main.hh \

# udty OBJECTIVE_SOURCES
#
#udty_OBJECTIVE_SOURCES += \
#$${TALAS_SRC}/xos/app/console/protocol/udtp/base/main.mm \

########################################################################
# udty HEADERS
#
#udty_HEADERS += \
#$${TALAS_SRC}/xos/app/console/protocol/udtp/base/main.hpp \

# udty SOURCES
#
#udty_SOURCES += \
#$${TALAS_SRC}/xos/app/console/protocol/udtp/base/main.cpp \

########################################################################
# udty FRAMEWORKS
#
udty_FRAMEWORKS += \
$${talas_FRAMEWORKS} \

# udty LIBS
#
udty_LIBS += \
$${talas_LIBS} \

########################################################################
# NO Qt
QT -= gui core

