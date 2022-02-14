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
#   File: tls.pro
#
# Author: $author$
#   Date: 2/14/2022
#
# os specific QtCreator project .pro file for framework talas executable tls
########################################################################
#
# Debug: talas/build/os/QtCreator/Debug/bin/tls
# Release: talas/build/os/QtCreator/Release/bin/tls
# Profile: talas/build/os/QtCreator/Profile/bin/tls
#
include(../../../../../build/QtCreator/talas.pri)
include(../../../../QtCreator/talas.pri)
include(../../talas.pri)
include(../../../../QtCreator/app/tls/tls.pri)

TARGET = $${tls_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${tls_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${tls_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${tls_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${tls_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${tls_HEADERS} \
$${tls_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${tls_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${tls_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${tls_LIBS} \
$${FRAMEWORKS} \

########################################################################

