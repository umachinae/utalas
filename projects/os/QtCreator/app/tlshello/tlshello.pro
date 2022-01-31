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
#   File: tlshello.pro
#
# Author: $author$
#   Date: 1/31/2022
#
# os specific QtCreator project .pro file for framework talas executable tlshello
########################################################################
#
# Debug: talas/build/os/QtCreator/Debug/bin/tlshello
# Release: talas/build/os/QtCreator/Release/bin/tlshello
# Profile: talas/build/os/QtCreator/Profile/bin/tlshello
#
include(../../../../../build/QtCreator/talas.pri)
include(../../../../QtCreator/talas.pri)
include(../../talas.pri)
include(../../../../QtCreator/app/tlshello/tlshello.pri)

TARGET = $${tlshello_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${tlshello_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${tlshello_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${tlshello_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${tlshello_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${tlshello_HEADERS} \
$${tlshello_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${tlshello_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${tlshello_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${tlshello_LIBS} \
$${FRAMEWORKS} \

########################################################################

