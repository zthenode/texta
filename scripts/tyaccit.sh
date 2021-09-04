#!/bin/bash
########################################################################
# Copyright (c) 1988-2020 $organization$
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
#   File: tyaccit.sh
#
# Author: $author$
#   Date: 2/5/2020
#
# script to generate script to generate parser using tyacc
########################################################################
if [ "$1" != "" ] && [ "$2" != "" ] && [ "$3" != "" ]; then
echo '#!/bin/bash'
echo tyacc -+ld -D $3.hxx -o $2.cxx $1.y
else
if [ "$1" != "" ] && [ "$2" != "" ]; then
tflex -+vLI -o$2.cxx $1.l
echo '#!/bin/bash'
echo tyacc -+ld -D $2.hxx -o $2.cxx $1.y
else
if [ "$1" != "" ]; then
echo '#!/bin/bash'
echo tyacc -+ld -D $1.hxx -o $1.cxx $1.y
else
echo usage `basename $0` source [output] [header] 
echo tyacc -+ld -D header[source.hxx] -o output[source.cxx] source.y
fi
fi
fi
