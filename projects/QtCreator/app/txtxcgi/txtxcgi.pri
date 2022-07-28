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
#   File: txtxcgi.pri
#
# Author: $author$
#   Date: 6/26/2022
#
# generic QtCreator project .pri file for framework texta executable txtxcgi
########################################################################

########################################################################
# txtxcgi

# txtxcgi TARGET
#
txtxcgi_TARGET = txtxcgi

# txtxcgi INCLUDEPATH
#
txtxcgi_INCLUDEPATH += \
$${texta_INCLUDEPATH} \

# txtxcgi DEFINES
#
txtxcgi_DEFINES += \
$${texta_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \
XOS_CONSOLE_MAIN_MAIN \

########################################################################
# txtxcgi OBJECTIVE_HEADERS
#
#txtxcgi_OBJECTIVE_HEADERS += \
#$${TEXTA_SRC}/xos/app/console/txtxcgi/main.hh \

# txtxcgi OBJECTIVE_SOURCES
#
#txtxcgi_OBJECTIVE_SOURCES += \
#$${TEXTA_SRC}/xos/app/console/txtxcgi/main.mm \

########################################################################
# txtxcgi HEADERS
#
txtxcgi_HEADERS += \
$${NADIR_SRC}/xos/console/main_main.hpp \
\
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main_opt.hpp \
$${STARA_SRC}/xos/app/console/network/protocol/http/cgi/main.hpp \
\
$${TEXTA_SRC}/xos/language/texta/processor/exception.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.hpp \
\
$${TEXTA_SRC}/xos/app/console/network/protocol/http/cgi/language/texta/main_opt.hpp \
$${TEXTA_SRC}/xos/app/console/network/protocol/http/cgi/language/texta/main.hpp \

txtxcgi_HEADERS += \
$${TEXTA_SRC}/xos/language/texta/processor/xde/implemented.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTInput.hpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTOutput.hpp \

# txtxcgi SOURCES
#
txtxcgi_SOURCES += \
$${NADIR_SRC}/xos/console/main_main.cpp \
\
$${TEXTA_SRC}/xos/language/texta/processor/exception.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/observer.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/implement.cpp \
\
$${TEXTA_SRC}/xos/app/console/network/protocol/http/cgi/language/texta/main_opt.cpp \
$${TEXTA_SRC}/xos/app/console/network/protocol/http/cgi/language/texta/main.cpp \

txtxcgi_SOURCES += \
$${xde_t_function_SOURCES} \
\
$${TEXTA_SRC}/xos/language/texta/processor/xde/implemented.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTInput.cpp \
$${TEXTA_SRC}/xos/language/texta/processor/xde/cTOutput.cpp \

########################################################################
# txtxcgi FRAMEWORKS
#
txtxcgi_FRAMEWORKS += \
$${texta_FRAMEWORKS} \

# txtxcgi LIBS
#
txtxcgi_LIBS += \
$${texta_LIBS} \
$${textadebug_LIBS} \

txtxcgi_LIBS += \
$${xde_LIBS} \

########################################################################
# NO Qt
QT -= gui core

