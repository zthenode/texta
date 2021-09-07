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
#   File: txtcgi.pro
#
# Author: $author$
#   Date: 9/6/2021
#
# QtCreator .pro file for texta executable txtcgi
########################################################################
include(../../../../../build/QtCreator/texta.pri)
include(../../../../QtCreator/texta.pri)
include(../../texta.pri)
include(../../../../QtCreator/app/txtcgi/txtcgi.pri)

TARGET = $${txtcgi_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${txtcgi_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${txtcgi_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${txtcgi_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${txtcgi_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${txtcgi_HEADERS} \
$${txtcgi_OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${txtcgi_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${txtcgi_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${txtcgi_LIBS} \
$${FRAMEWORKS} \


