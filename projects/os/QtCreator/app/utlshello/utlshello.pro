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
#   File: utlshello.pro
#
# Author: $author$
#   Date: 3/9/2022
#
# os specific QtCreator project .pro file for framework utalas executable utlshello
########################################################################
#
# Debug: utalas/build/os/QtCreator/Debug/bin/utlshello
# Release: utalas/build/os/QtCreator/Release/bin/utlshello
# Profile: utalas/build/os/QtCreator/Profile/bin/utlshello
#
include(../../../../../build/QtCreator/utalas.pri)
include(../../../../QtCreator/utalas.pri)
include(../../utalas.pri)
include(../../../../QtCreator/app/utlshello/utlshello.pri)

TARGET = $${utlshello_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${utlshello_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${utlshello_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${utlshello_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${utlshello_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${utlshello_HEADERS} \
$${utlshello_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${utlshello_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${utlshello_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${utlshello_LIBS} \
$${FRAMEWORKS} \

########################################################################

