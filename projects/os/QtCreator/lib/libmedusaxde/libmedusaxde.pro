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
#   File: libmedusaxde.pro
#
# Author: $author$
#   Date: 9/9/2021
#
# QtCreator .pro file for medusaxde library libmedusaxde
########################################################################
include(../../../../../build/QtCreator/medusaxde.pri)
include(../../../../QtCreator/medusaxde.pri)
include(../../medusaxde.pri)
include(../../../../QtCreator/lib/libmedusaxde/libmedusaxde.pri)

TARGET = $${libmedusaxde_TARGET}
TEMPLATE = $${libmedusaxde_TEMPLATE}
CONFIG += $${libmedusaxde_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libmedusaxde_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libmedusaxde_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libmedusaxde_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libmedusaxde_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libmedusaxde_HEADERS} \
$${libmedusaxde_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libmedusaxde_SOURCES} \

########################################################################


