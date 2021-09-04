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
#   File: tflex.pri
#
# Author: $author$
#   Date: 9/4/2021
#
# QtCreator .pri file for texta executable tflex
########################################################################

########################################################################
# tflex

# tflex TARGET
#
tflex_TARGET = tflex

# tflex INCLUDEPATH
#
tflex_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# tflex DEFINES
#
tflex_DEFINES += \
$${texta_DEFINES} \

#DEFAULT_LOGGING_LEVELS_ERROR \
#TEXTA_APP_CONSOLE_TFLEX_MAIN_INSTANCE \

########################################################################
# tflex OBJECTIVE_HEADERS
#
#tflex_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/tflex/main.hh \

# tflex OBJECTIVE_SOURCES
#
#tflex_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/tflex/main.mm \

########################################################################
# tflex HEADERS
#
#tflex_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/tflex/main.hpp \

# tflex SOURCES
#
#tflex_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/tflex/main.cpp \

########################################################################
# tflex FRAMEWORKS
#
tflex_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# tflex LIBS
#
tflex_LIBS += \
$${texta_LIBS} \


