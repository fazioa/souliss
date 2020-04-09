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
#define  HOMIE_NODES_FEED HOMIE_ROOT "/$nodes"
#define  HOMIE_EXTENSIONS_FEED HOMIE_ROOT "/$extensions"
#define  HOMIE_STATE_FEED HOMIE_ROOT "/$state"

//#define  HOMIE_PROPERTIESUNIT_FEED HOMIE_NODEROOT "/" HOMIE_NODEPROPERTIES "/$unit"



#define HOMIE_EXTENSIONS ""


	#define HOMIE_NODENAME "lucedivano"
		#define HOMIE_NODEDESC "Luce Divano"
		#define HOMIE_NODETYPE "switch"
		#define HOMIE_SWITCHPROPERTYNAME "power"
		#define HOMIE_SWITCHPROPERTYDESC "Power"
		#define HOMIE_SWITCHSETTABLE "true"
		#define HOMIE_SWITCHFORMAT "ON,OFF"
		#define HOMIE_SWITCHRETAINED "true"
		#define HOMIE_SWITCHDATATYPE "boolean"
		
		#define HOMIE_NODE_ROOT_FEED HOMIE_ROOT "/" HOMIE_NODENAME
		#define  HOMIE_NODE_NAME_FEED HOMIE_NODE_ROOT_FEED  "/$name"
		#define  HOMIE_NODE_PROPERTIES_FEED HOMIE_NODE_ROOT_FEED "/$properties"
		#define  HOMIE_NODE_TYPE_FEED HOMIE_NODE_ROOT_FEED "/&type"

		#define  HOMIE_NODE_PROPERTIES_FUNC_FEED HOMIE_NODE_ROOT_FEED "/" HOMIE_SWITCHPROPERTYNAME
		#define  HOMIE_NODE_PROPERTIES_NAME_FEED HOMIE_NODE_PROPERTIES_FUNC_FEED  "/$name"
		#define  HOMIE_NODE_PROPERTIES_SETTABLE_FEED HOMIE_NODE_PROPERTIES_FUNC_FEED  "/$settable"
		#define  HOMIE_NODE_PROPERTIES_FORMAT_FEED HOMIE_NODE_PROPERTIES_FUNC_FEED  "/$format"
		#define  HOMIE_NODE_PROPERTIES_RETAINED_FEED HOMIE_NODE_PROPERTIES_FUNC_FEED  "/$retained"
		#define  HOMIE_NODE_PROPERTIES_DATATYPE_FEED HOMIE_NODE_PROPERTIES_FUNC_FEED  "/$datatype"
