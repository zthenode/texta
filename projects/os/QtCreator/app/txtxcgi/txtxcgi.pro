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
#   File: txtxcgi.pro
#
# Author: $author$
#   Date: 6/26/2022
#
# os specific QtCreator project .pro file for framework texta executable txtxcgi
########################################################################
#
# Debug: texta/build/os/QtCreator/Debug/bin/txtxcgi
# Release: texta/build/os/QtCreator/Release/bin/txtxcgi
# Profile: texta/build/os/QtCreator/Profile/bin/txtxcgi
#
include(../../../../../build/QtCreator/texta.pri)
include(../../../../QtCreator/texta.pri)
include(../../texta.pri)
include(../../../../QtCreator/app/txtxcgi/txtxcgi.pri)

TARGET = $${txtxcgi_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${txtxcgi_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${txtxcgi_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${txtxcgi_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${txtxcgi_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${txtxcgi_HEADERS} \
$${txtxcgi_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${txtxcgi_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${txtxcgi_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${txtxcgi_LIBS} \
$${FRAMEWORKS} \

########################################################################

