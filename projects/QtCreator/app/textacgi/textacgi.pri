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
#   File: textacgi.pri
#
# Author: $author$
#   Date: 9/6/2021, 7/27/2022
#
# QtCreator .pri file for texta executable textacgi
########################################################################

########################################################################
# textacgi
TEXTACGI_IMPLEMENTED = medusade

# textacgi TARGET
#
textacgi_TARGET = textacgi

# textacgi INCLUDEPATH
#
textacgi_INCLUDEPATH += \

# textacgi DEFINES
#
textacgi_DEFINES += \

########################################################################
# textacgi OBJECTIVE_HEADERS
#
#textacgi_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/textacgi/main.hh \

# textacgi OBJECTIVE_SOURCES
#
#textacgi_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/textacgi/main.mm \

########################################################################
# textacgi INCLUDEPATH
#
textacgi_xde_implemented_INCLUDEPATH += \
$${texta_xde_INCLUDEPATH} \

# textacgi DEFINES
#
textacgi_xde_implemented_DEFINES += \
$${texta_xde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_NETWORK_PROTOCOL_HTTP_CGI_LANGUAGE_TEXTA_MAIN_INSTANCE \

# textacgi HEADERS
#
textacgi_xde_implemented_HEADERS += \
$${texta_xde_implemented_HEADERS} \
$${TEXTA_SRC}/xos/app/console/network/protocol/http/cgi/language/texta/main_opt.hpp \
$${TEXTA_SRC}/xos/app/console/network/protocol/http/cgi/language/texta/main.hpp \

# textacgi SOURCES
#
textacgi_xde_implemented_SOURCES += \
$${texta_xde_implemented_SOURCES} \
$${TEXTA_SRC}/xos/app/console/network/protocol/http/cgi/language/texta/main_opt.cpp \
$${TEXTA_SRC}/xos/app/console/network/protocol/http/cgi/language/texta/main.cpp \

# textacgi FRAMEWORKS
#
textacgi_xde_implemented_FRAMEWORKS += \

# textacgi LIBS
#
textacgi_xde_implemented_LIBS += \
$${texta_LIBS} \
$${xde_LIBS} \
$${textadebug_LIBS} \

########################################################################
# textacgi INCLUDEPATH
#
textacgi_medusade_INCLUDEPATH += \
$${texta_medusade_INCLUDEPATH} \

# textacgi DEFINES
#
textacgi_medusade_DEFINES += \
$${texta_medusade_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

# textacgi HEADERS
#
textacgi_medusade_HEADERS += \
$${medusade_texta_HEADERS} \
$${MEDUSADE_TEXTA_SRC}/texta/app/cgi/texta/main.hpp \

# textacgi SOURCES
#
textacgi_medusade_SOURCES += \
$${medusade_texta_SOURCES} \
$${MEDUSADE_TEXTA_SRC}/texta/app/cgi/texta/main.cpp \

# textacgi FRAMEWORKS
#
textacgi_medusade_FRAMEWORKS += \

# textacgi LIBS
#
textacgi_medusade_LIBS += \

########################################################################

contains(TEXTACGI_IMPLEMENTED,medusade) {
textacgi_INCLUDEPATH += $${textacgi_medusade_INCLUDEPATH}
textacgi_DEFINES += $${textacgi_medusade_DEFINES}
textacgi_HEADERS += $${textacgi_medusade_HEADERS}
textacgi_SOURCES += $${textacgi_medusade_SOURCES}
textacgi_FRAMEWORKS += $${textacgi_medusade_FRAMEWORKS}
textacgi_LIBS += $${textacgi_medusade_LIBS}
} else {
contains(TEXTACGI_IMPLEMENTED,xde) {
textacgi_INCLUDEPATH += $${textacgi_xde_implemented_INCLUDEPATH}
textacgi_DEFINES += $${textacgi_xde_implemented_DEFINES}
textacgi_HEADERS += $${textacgi_xde_implemented_HEADERS}
textacgi_SOURCES += $${textacgi_xde_implemented_SOURCES}
textacgi_FRAMEWORKS += $${textacgi_xde_implemented_FRAMEWORKS}
textacgi_LIBS += $${textacgi_xde_implemented_LIBS}
} else {
textacgi_INCLUDEPATH += $${textacgi_implemented_INCLUDEPATH}
textacgi_DEFINES += $${textacgi_implemented_DEFINES}
textacgi_HEADERS += $${textacgi_implemented_HEADERS}
textacgi_SOURCES += $${textacgi_implemented_SOURCES}
textacgi_FRAMEWORKS += $${textacgi_implemented_FRAMEWORKS}
textacgi_LIBS += $${textacgi_implemented_LIBS}
} # contains(TEXTACGI_IMPLEMENTED,xde)
} # contains(TEXTACGI_IMPLEMENTED,medusade)

########################################################################
# NO Qt
QT -= gui core
