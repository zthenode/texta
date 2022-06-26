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
#   Date: 9/6/2021
#
# QtCreator .pri file for texta executable texta
########################################################################

########################################################################
# texta

# texta_exe TARGET
#
texta_exe_TARGET = texta

# texta_exe INCLUDEPATH
#
texta_exe_INCLUDEPATH += \
$${texta_xde_INCLUDEPATH} \

# texta_exe DEFINES
#
texta_exe_DEFINES += \
$${texta_xde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_APP_CONSOLE_LANGUAGE_TEXTA_MAIN_INSTANCE \

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
$${TEXTA_SRC}/xos/language/texta/processor/exception.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/implemented.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTInput.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTOutput.hpp \
\
$${TEXTA_SRC}/xos/app/console/language/texta/main_opt.hpp \
$${TEXTA_SRC}/xos/app/console/language/texta/main.hpp \
\
$${NADIR_SRC}/xos/console/main_main.hpp \

# texta_exe SOURCES
#
texta_exe_SOURCES += \
$${xde_t_function_SOURCES} \
\
$${TEXTA_SRC}/xos/language/texta/processor/exception.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/implemented.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTInput.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTOutput.cpp \
\
$${TEXTA_SRC}/xos/app/console/language/texta/main_opt.cpp \
$${TEXTA_SRC}/xos/app/console/language/texta/main.cpp \
\
$${NADIR_SRC}/xos/console/main_main.cpp \


########################################################################
# texta_exe FRAMEWORKS
#
texta_exe_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# texta_exe LIBS
#
texta_exe_LIBS += \
$${texta_LIBS} \
$${xde_LIBS} \
$${textadebug_LIBS} \

########################################################################
# NO Qt
QT -= gui core

