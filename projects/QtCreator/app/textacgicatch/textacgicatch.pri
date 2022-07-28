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
#   File: textacgicatch.pri
#
# Author: $author$
#   Date: 7/28/2022
#
# generic QtCreator project .pri file for framework texta executable textacgicatch
########################################################################

########################################################################
# textacgicatch
TEXTACGICATCH_IMPLEMENTED = medusade

# textacgicatch TARGET
#
textacgicatch_TARGET = textacgicatch

########################################################################
# textacgicatch medusade 

# textacgicatch medusade INCLUDEPATH
#
textacgicatch_medusade_INCLUDEPATH += \
$${medusade_INCLUDEPATH} \

# textacgicatch medusade DEFINES
#
textacgicatch_medusade_DEFINES += \
$${medusade_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# textacgicatch medusade OBJECTIVE_HEADERS
#
#textacgicatch_medusade_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/xos/app/console/textacgicatch/main.hh \

# textacgicatch medusade OBJECTIVE_SOURCES
#
#textacgicatch_medusade_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/xos/app/console/textacgicatch/main.mm \

########################################################################
# textacgicatch medusade HEADERS
#
textacgicatch_medusade_HEADERS += \
$${medusade_HEADERS} \
$${MEDUSADE_CORAL_SRC}/coral/app/cgi/catcher/main.hpp \

# textacgicatch medusade SOURCES
#
textacgicatch_medusade_SOURCES += \
$${medusade_SOURCES} \
$${MEDUSADE_CORAL_SRC}/coral/app/cgi/catcher/main.cpp \

########################################################################
# textacgicatch medusade FRAMEWORKS
#
textacgicatch_medusade_FRAMEWORKS += \

# textacgicatch medusade LIBS
#
textacgicatch_medusade_LIBS += \

########################################################################

contains(TEXTACGICATCH_IMPLEMENTED,medusade) {
textacgicatch_INCLUDEPATH += $${textacgicatch_medusade_INCLUDEPATH}
textacgicatch_DEFINES += $${textacgicatch_medusade_DEFINES}
textacgicatch_HEADERS += $${textacgicatch_medusade_HEADERS}
textacgicatch_SOURCES += $${textacgicatch_medusade_SOURCES}
textacgicatch_FRAMEWORKS += $${textacgicatch_medusade_FRAMEWORKS}
textacgicatch_LIBS += $${textacgicatch_medusade_LIBS}
} else {
contains(TEXTACGICATCH_IMPLEMENTED,xde) {
textacgicatch_INCLUDEPATH += $${textacgicatch_xde_implemented_INCLUDEPATH}
textacgicatch_DEFINES += $${textacgicatch_xde_implemented_DEFINES}
textacgicatch_HEADERS += $${textacgicatch_xde_implemented_HEADERS}
textacgicatch_SOURCES += $${textacgicatch_xde_implemented_SOURCES}
textacgicatch_FRAMEWORKS += $${textacgicatch_xde_implemented_FRAMEWORKS}
textacgicatch_LIBS += $${textacgicatch_xde_implemented_LIBS}
} else {
textacgicatch_INCLUDEPATH += $${textacgicatch_implemented_INCLUDEPATH}
textacgicatch_DEFINES += $${textacgicatch_implemented_DEFINES}
textacgicatch_HEADERS += $${textacgicatch_implemented_HEADERS}
textacgicatch_SOURCES += $${textacgicatch_implemented_SOURCES}
textacgicatch_FRAMEWORKS += $${textacgicatch_implemented_FRAMEWORKS}
textacgicatch_LIBS += $${textacgicatch_implemented_LIBS}
} # contains(TEXTACGICATCH_IMPLEMENTED,xde)
} # contains(TEXTACGICATCH_IMPLEMENTED,medusade)

########################################################################
# NO Qt
QT -= gui core

