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
#   File: txtx.pri
#
# Author: $author$
#   Date: 6/26/2022
#
# generic QtCreator project .pri file for framework texta executable txtx
########################################################################

########################################################################
# txtx

# txtx TARGET
#
txtx_TARGET = txtx

# txtx INCLUDEPATH
#
txtx_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# txtx DEFINES
#
txtx_DEFINES += \
$${texta_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# txtx OBJECTIVE_HEADERS
#
#txtx_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/xos/app/console/txtx/main.hh \

# txtx OBJECTIVE_SOURCES
#
#txtx_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/xos/app/console/txtx/main.mm \

########################################################################
# txtx HEADERS
#
txtx_HEADERS += \
$${NADIR_SRC}/xos/console/main_main.hpp \
\
$${TEXTA_SRC}/xos/language/texta/processor/exception.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.hpp \
\
$${TEXTA_SRC}/xos/app/console/language/texta/main_opt.hpp \
$${TEXTA_SRC}/xos/app/console/language/texta/main.hpp \

txtx_HEADERS += \
$${TEXTA_SRC}/xos/language/texta/processor/xde/implemented.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTInput.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTOutput.hpp \

# txtx SOURCES
#
txtx_SOURCES += \
$${NADIR_SRC}/xos/console/main_main.cpp \
\
$${TEXTA_SRC}/xos/language/texta/processor/exception.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.cpp \
\
$${TEXTA_SRC}/xos/app/console/language/texta/main_opt.cpp \
$${TEXTA_SRC}/xos/app/console/language/texta/main.cpp \

txtx_SOURCES += \
$${xde_t_function_SOURCES} \
\
$${TEXTA_SRC}/xos/language/texta/processor/xde/implemented.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTInput.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTOutput.cpp \

########################################################################
# txtx FRAMEWORKS
#
txtx_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# txtx LIBS
#
txtx_LIBS += \
$${texta_LIBS} \
$${textadebug_LIBS} \

txtx_LIBS += \
$${xde_LIBS} \

########################################################################
# NO Qt
QT -= gui core

