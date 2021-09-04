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
#   File: tcgi.pri
#
# Author: $author$
#   Date: 9/4/2021
#
# QtCreator .pri file for xde executable tcgi
########################################################################

########################################################################
# tcgi

# tcgi TARGET
#
tcgi_TARGET = tcgi

# tcgi INCLUDEPATH
#
tcgi_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

# tcgi DEFINES
#
tcgi_DEFINES += \
$${xde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# tcgi OBJECTIVE_HEADERS
#
#tcgi_OBJECTIVE_HEADERS += \
#$${XDE_SRC}/xde/app/console/tcgi/main.hh \

# tcgi OBJECTIVE_SOURCES
#
#tcgi_OBJECTIVE_SOURCES += \
#$${XDE_SRC}/xde/app/console/tcgi/main.mm \

########################################################################
# tcgi HEADERS
#
tcgi_HEADERS += \
$${XDE_SRC}/clib/ccgi/cgi.hxx \
$${XDE_SRC}/clib/ct/ctcgi.hxx \

# tcgi SOURCES
#
tcgi_SOURCES += \
$${XDE_SRC}/clib/ccgi/cgi.cxx \
$${XDE_SRC}/clib/ct/ctcgi.cxx \
$${xde_t_function_SOURCES} \

########################################################################
# tcgi FRAMEWORKS
#
tcgi_FRAMEWORKS += \
$${xde_FRAMEWORKS} \

# tcgi LIBS
#
tcgi_LIBS += \
$${xde_LIBS} \


