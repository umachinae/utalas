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
#   File: libtalas.pro
#
# Author: $author$
#   Date: 1/29/2022
#
# os specific QtCreator project .pro file for framework talas static library libtalas
########################################################################
#
# Debug: talas/build/os/QtCreator/Debug/lib/libtalas
# Release: talas/build/os/QtCreator/Release/lib/libtalas
# Profile: talas/build/os/QtCreator/Profile/lib/libtalas
#
include(../../../../../build/QtCreator/talas.pri)
include(../../../../QtCreator/talas.pri)
include(../../talas.pri)
include(../../../../QtCreator/lib/libtalas/libtalas.pri)

TARGET = $${libtalas_TARGET}
TEMPLATE = $${libtalas_TEMPLATE}
CONFIG += $${libtalas_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libtalas_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libtalas_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libtalas_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libtalas_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libtalas_HEADERS} \
$${libtalas_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libtalas_SOURCES} \

########################################################################

