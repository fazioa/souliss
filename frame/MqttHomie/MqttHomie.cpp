/**************************************************************************
	Souliss - MaCaco Communication Protocol
    Copyright (C) 2011  Tonino

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
#ifndef HOMIE_H
#define HOMIE_H

#include "frame/MqttHomie/MqttHomie.h"

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_PORT, HOSTNAME, MQTT_USERNAME, MQTT_PASSWORD);

Adafruit_MQTT_Publish MQTTversion = Adafruit_MQTT_Publish(&mqtt, HOMIE_VERSION_FEED);
Adafruit_MQTT_Publish MQTTname = Adafruit_MQTT_Publish(&mqtt, HOMIE_NODEID_FEED);
Adafruit_MQTT_Publish MQTTnodes = Adafruit_MQTT_Publish(&mqtt, HOMIE_NODES_FEED);
Adafruit_MQTT_Publish MQTTextensions = Adafruit_MQTT_Publish(&mqtt, HOMIE_EXTENSIONS_FEED);
Adafruit_MQTT_Publish MQTTstate = Adafruit_MQTT_Publish(&mqtt, HOMIE_STATE_FEED);

Adafruit_MQTT_Publish MQTTnodename = Adafruit_MQTT_Publish(&mqtt, HOMIE_NODENAME_FEED);
Adafruit_MQTT_Publish MQTTnodetype = Adafruit_MQTT_Publish(&mqtt, HOMIE_NODETYPE_FEED);
Adafruit_MQTT_Publish MQTTnodeproperties = Adafruit_MQTT_Publish(&mqtt, HOMIE_NODEPROPERTIES_FEED);
Adafruit_MQTT_Publish MQTTpropertiesunit = Adafruit_MQTT_Publish(&mqtt, HOMIE_PROPERTIESUNIT_FEED);


Adafruit_MQTT_Publish MQTTsendTemp = Adafruit_MQTT_Publish(&mqtt, HOMIE_NODEROOT "/temp");
/**************************************************************************/
/*!
    Build frame and write to destination device, it use the oFrame structure
*/
/**************************************************************************/
// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
  Serial.print("Connecting to MQTT... ");

  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection...");
    mqtt.disconnect();
  }
  Serial.println("MQTT Connected!");
}

void Homie_init()
{
MQTT_connect();
MQTTstate.publish("init");

MQTTversion.publish(HOMIE_VERSION);
MQTTname.publish(HOMIE_NODEID);
MQTTnodes.publish(HOMIE_NODES);
MQTTextensions.publish(HOMIE_EXTENSIONS);
}

void Homie_announce()
{
	MQTTnodename.publish(HOMIE_NODENAME);
MQTTnodetype.publish(HOMIE_NODETYPE);
MQTTnodeproperties.publish(HOMIE_NODEPROPERTIES);
MQTTpropertiesunit.publish(HOMIE_PROPERTIESUNIT);
MQTTstate.publish("ready");
}