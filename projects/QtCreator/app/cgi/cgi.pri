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
#   File: cgi.pri
#
# Author: $author$
#   Date: 9/4/2021
#
# QtCreator .pri file for xde executable cgi
########################################################################

########################################################################
# cgi

# cgi TARGET
#
cgi_TARGET = cgi

# cgi INCLUDEPATH
#
cgi_INCLUDEPATH += \
$${xde_INCLUDEPATH} \

# cgi DEFINES
#
cgi_DEFINES += \
$${xde_DEFINES} \
DEFAULT_LOGGING_LEVELS_ERROR \

########################################################################
# cgi OBJECTIVE_HEADERS
#
#cgi_OBJECTIVE_HEADERS += \
#$${XDE_SRC}/xde/app/console/cgi/main.hh \

# cgi OBJECTIVE_SOURCES
#
#cgi_OBJECTIVE_SOURCES += \
#$${XDE_SRC}/xde/app/console/cgi/main.mm \

########################################################################
# cgi HEADERS
#
cgi_HEADERS += \
$${XDE_SRC}/capp/ccgi/cgi/ccgimain.hxx \
$${XDE_SRC}/clib/ccgi/cgi.hxx \

# cgi SOURCES
#
cgi_SOURCES += \
$${XDE_SRC}/capp/ccgi/cgi/ccgimain.cxx \
$${XDE_SRC}/clib/ccgi/cgi.cxx \

########################################################################
# cgi FRAMEWORKS
#
cgi_FRAMEWORKS += \
$${xde_FRAMEWORKS} \

# cgi LIBS
#
cgi_LIBS += \
$${xde_LIBS} \

########################################################################
# NO Qt
QT -= gui core
