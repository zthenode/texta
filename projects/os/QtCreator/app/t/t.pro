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
#   File: t.pro
#
# Author: $author$
#   Date: 9/4/2021
#
# QtCreator .pro file for xde executable t
########################################################################
include(../../../../../build/QtCreator/xde.pri)
include(../../../../QtCreator/xde.pri)
include(../../xde.pri)
include(../../../../QtCreator/app/t/t.pri)

TARGET = $${t_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${t_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${t_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${t_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${t_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${t_HEADERS} \
$${t_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${t_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${t_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${t_LIBS} \
$${FRAMEWORKS} \


