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
#   File: evls.pro
#
# Author: $author$
#   Date: 9/8/2021
#
# QtCreator .pro file for evx executable evls
########################################################################
include(../../../../../build/QtCreator/evx.pri)
include(../../../../QtCreator/evx.pri)
include(../../evx.pri)
include(../../../../QtCreator/app/evls/evls.pri)

TARGET = $${evls_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${evls_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${evls_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${evls_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${evls_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${evls_HEADERS} \
$${evls_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${evls_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${evls_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${evls_LIBS} \
$${FRAMEWORKS} \


