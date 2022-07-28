########################################################################
# Copyright (c) 1988-2021 $organization$
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
#   File: evuuid.pro
#
# Author: $author$
#   Date: 10/6/2021
#
# QtCreator .pro file for evx executable evuuid
########################################################################
include(../../../../../build/QtCreator/evx.pri)
include(../../../../QtCreator/evx.pri)
include(../../evx.pri)
include(../../../../QtCreator/app/evuuid/evuuid.pri)

TARGET = $${evuuid_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${evuuid_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${evuuid_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${evuuid_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${evuuid_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${evuuid_HEADERS} \
$${evuuid_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${evuuid_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${evuuid_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${evuuid_LIBS} \
$${FRAMEWORKS} \


