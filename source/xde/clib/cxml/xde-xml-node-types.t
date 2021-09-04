%#############################################################################
%# Copyright (c) 1988-2008 $organization$
%#
%# This software is provided by the author and contributors ``as is'' and
%# any express or implied warranties, including, but not limited to, the
%# implied warranties of merchantability and fitness for a particular purpose
%# are disclaimed.  In no event shall the author or contributors be liable
%# for any direct, indirect, incidental, special, exemplary, or consequential
%# damages (including, but not limited to, procurement of substitute goods
%# or services; loss of use, data, or profits; or business interruption)
%# however caused and on any theory of liability, whether in contract, strict
%# liability, or tort (including negligence or otherwise) arising in any way
%# out of the use of this software, even if advised of the possibility of
%# such damage.
%#
%#   File: xde-xml-node-types.t
%#
%# Author: $author$
%#   Date: 11/4/2008
%#
%#############################################################################
%apply-x(%
%%(%
%NONE:0x0
TEXT:0x1
COMMENT:0x2
ATTRIBUTE:0x4
ELEMENT:0x8
BEGIN_ELEMENT:0x10
END_ELEMENT:0x20
DATA:0x40
DOCUMENT:0x80
DOCUMENT_FRAGMENT:0x100
DOCUMENT_TYPE:0x200
CDATA:0x400
NOTATION:0x800
ENTITY:0x1000
ENTITY_REFERENCE:0x2000
PROCESSING_INSTRUCTION:0x4000
ALL:-1%
%)%)%