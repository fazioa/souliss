/**************************************************************************
	Souliss - MqttHomie Communication Protocol
    Copyright (C) 2020  Tonino

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
	Originally developed by Dario Di Maio
	
***************************************************************************/
/*!
    \file 
    \ingroup

*/
/**************************************************************************/
#define HOMIE_VERSION "3.0"
#define HOMIE_ROOT "homie/souliss"


#define  HOMIE_VERSION_FEED HOMIE_ROOT  "/$homie"
#define  HOMIE_NODEID_FEED HOMIE_ROOT "/$name"
#define  HOMIE_EXTENSIONS_FEED HOMIE_ROOT "/$extensions"
#define  HOMIE_STATE_FEED HOMIE_ROOT "/$state"

#define HOMIE_EXTENSIONS ""

#define BUFFER_LENGHT_FOR_STRTOCHARARRAY_FUNC 512

String nodes="";