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
#   File: libevx.pro
#
# Author: $author$
#   Date: 9/8/2021
#
# QtCreator .pro file for evx library libevx
########################################################################
include(../../../../../build/QtCreator/evx.pri)
include(../../../../QtCreator/evx.pri)
include(../../evx.pri)
include(../../../../QtCreator/lib/libev/libev.pri)

TARGET = $${libevx_TARGET}
TEMPLATE = $${libevx_TEMPLATE}
CONFIG += $${libevx_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libevx_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libevx_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libevx_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libevx_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libevx_HEADERS} \
$${libevx_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libevx_SOURCES} \

########################################################################


