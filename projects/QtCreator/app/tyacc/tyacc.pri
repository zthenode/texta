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
#   File: tyacc.pri
#
# Author: $author$
#   Date: 9/4/2021
#
# QtCreator .pri file for texta executable tyacc
########################################################################

########################################################################
# tyacc

# tyacc TARGET
#
tyacc_TARGET = tyacc

# tyacc INCLUDEPATH
#
tyacc_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# tyacc DEFINES
#
tyacc_DEFINES += \
$${texta_DEFINES} \

#DEFAULT_LOGGING_LEVELS_ERROR \
#TEXTA_APP_CONSOLE_TYACC_MAIN_INSTANCE \

########################################################################
# tyacc OBJECTIVE_HEADERS
#
#tyacc_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/tyacc/main.hh \

# tyacc OBJECTIVE_SOURCES
#
#tyacc_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/tyacc/main.mm \

########################################################################
# tyacc HEADERS
#
#tyacc_HEADERS += \
#$${TEXTA_SRC}/texta/app/console/tyacc/main.hpp \

# tyacc SOURCES
#
#tyacc_SOURCES += \
#$${TEXTA_SRC}/texta/app/console/tyacc/main.cpp \

########################################################################
# tyacc FRAMEWORKS
#
tyacc_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# tyacc LIBS
#
tyacc_LIBS += \
$${texta_LIBS} \


