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
#   File: texta.pri
#
# Author: $author$
#   Date: 9/6/2021, 7/27/2022
#
# QtCreator .pri file for texta executable texta
########################################################################

########################################################################
# texta
TEXTA_IMPLEMENTED = medusade

# texta_exe TARGET
#
texta_exe_TARGET = texta

# texta_exe INCLUDEPATH
#
texta_exe_INCLUDEPATH += \

# texta_exe DEFINES
#
texta_exe_DEFINES += \

########################################################################
# texta_exe OBJECTIVE_HEADERS
#
#texta_exe_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/texta/main.hh \

# texta_exe OBJECTIVE_SOURCES
#
#texta_exe_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/texta/main.mm \

########################################################################
# texta_exe HEADERS
#
texta_exe_HEADERS += \

# texta_exe SOURCES
#
texta_exe_SOURCES += \

# texta_exe FRAMEWORKS
#
texta_exe_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# texta_exe LIBS
#
texta_exe_LIBS += \
$${texta_LIBS} \

########################################################################
# texta_exe xde implemented INCLUDEPATH
#
texta_exe_xde_implemented_INCLUDEPATH += \
$${texta_xde_INCLUDEPATH} \

# texta_exe xde implemented DEFINES
#
texta_exe_xde_implemented_DEFINES += \
$${texta_xde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_LANGUAGE_TEXTA_MAIN_INSTANCE \

# texta_exe xde implemented HEADERS
#
texta_exe_xde_implemented_HEADERS += \
$${texta_xde_implemented_HEADERS} \
$${TEXTA_SRC}/xos/app/console/language/texta/xde/main.hpp \

# texta_exe xde implemented SOURCES
#
texta_exe_xde_implemented_SOURCES += \
$${texta_xde_implemented_SOURCES} \
$${TEXTA_SRC}/xos/app/console/language/texta/xde/main.cpp \

# texta_exe xde implemented FRAMEWORKS
#
texta_exe_xde_implemented_FRAMEWORKS += \

# texta_exe xde implemented LIBS
#
texta_exe_xde_implemented_LIBS += \
$${texta_LIBS} \
$${xde_LIBS} \
$${textadebug_LIBS} \

########################################################################
# texta_exe medusade INCLUDEPATH
#
texta_exe_medusade_INCLUDEPATH += \
$${texta_medusade_INCLUDEPATH} \

# texta_exe medusade DEFINES
#
texta_exe_medusade_DEFINES += \
$${texta_medusade_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

# texta_exe medusade HEADERS
#
texta_exe_medusade_HEADERS += \
$${medusade_texta_HEADERS} \
$${MEDUSADE_TEXTA_SRC}/texta/app/console/texta/main.hpp \

# texta_exe medusade SOURCES
#
texta_exe_medusade_SOURCES += \
$${medusade_texta_SOURCES} \
$${MEDUSADE_TEXTA_SRC}/texta/app/console/texta/main.cpp \

# texta_exe medusade FRAMEWORKS
#
texta_exe_medusade_FRAMEWORKS += \

# texta_exe medusade LIBS
#
texta_exe_medusade_LIBS += \

########################################################################
# texta_exe implemented INCLUDEPATH
#
texta_exe_implemented_INCLUDEPATH += \

# texta_exe implemented DEFINES
#
texta_exe_implemented_DEFINES += \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

# texta_exe implemented HEADERS
#
texta_exe_implemented_HEADERS += \
$${texta_implemented_HEADERS} \
$${TEXTA_SRC}/xos/app/console/language/texta/main.hpp \

# texta_exe implemented SOURCES
#
texta_exe_implemented_SOURCES += \
$${texta_implemented_SOURCES} \
$${TEXTA_SRC}/xos/app/console/language/texta/main.cpp \

# texta_exe implemented FRAMEWORKS
#
texta_exe_implemented_FRAMEWORKS += \

# texta_exe implemented LIBS
#
texta_exe_implemented_LIBS += \

########################################################################

contains(TEXTA_IMPLEMENTED,medusade) {
texta_exe_INCLUDEPATH += $${texta_exe_medusade_INCLUDEPATH}
texta_exe_DEFINES += $${texta_exe_medusade_DEFINES}
texta_exe_HEADERS += $${texta_exe_medusade_HEADERS}
texta_exe_SOURCES += $${texta_exe_medusade_SOURCES}
texta_exe_FRAMEWORKS += $${texta_exe_medusade_FRAMEWORKS}
texta_exe_LIBS += $${texta_exe_medusade_LIBS}
} else {
contains(TEXTA_IMPLEMENTED,xde) {
texta_exe_INCLUDEPATH += $${texta_exe_xde_implemented_INCLUDEPATH}
texta_exe_DEFINES += $${texta_exe_xde_implemented_DEFINES}
texta_exe_HEADERS += $${texta_exe_xde_implemented_HEADERS}
texta_exe_SOURCES += $${texta_exe_xde_implemented_SOURCES}
texta_exe_FRAMEWORKS += $${texta_exe_xde_implemented_FRAMEWORKS}
texta_exe_LIBS += $${texta_exe_xde_implemented_LIBS}
} else {
texta_exe_INCLUDEPATH += $${texta_exe_implemented_INCLUDEPATH}
texta_exe_DEFINES += $${texta_exe_implemented_DEFINES}
texta_exe_HEADERS += $${texta_exe_implemented_HEADERS}
texta_exe_SOURCES += $${texta_exe_implemented_SOURCES}
texta_exe_FRAMEWORKS += $${texta_exe_implemented_FRAMEWORKS}
texta_exe_LIBS += $${texta_exe_implemented_LIBS}
} # contains(TEXTA_IMPLEMENTED,xde)
} # contains(TEXTA_IMPLEMENTED,medusade)

########################################################################
# NO Qt
QT -= gui core
