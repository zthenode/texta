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
#   File: libevdebug.pro
#
# Author: $author$
#   Date: 9/8/2021
#
# QtCreator .pro file for evx library libevdebug
########################################################################
include(../../../../../build/QtCreator/evx.pri)
include(../../../../QtCreator/evx.pri)
include(../../evx.pri)
include(../../../../QtCreator/lib/libevdebug/libevdebug.pri)

TARGET = $${libevdebug_TARGET}
TEMPLATE = $${libevdebug_TEMPLATE}
CONFIG += $${libevdebug_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libevdebug_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libevdebug_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libevdebug_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libevdebug_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libevdebug_HEADERS} \
$${libevdebug_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libevdebug_SOURCES} \

########################################################################


