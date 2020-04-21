/**************************************************************************
	Souliss - MaCaco Communication Protocol
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
#include "frame/MqttHomie/MqttHomie.h"


// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
 Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_PORT, HOSTNAME, MQTT_USERNAME, MQTT_PASSWORD);


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
	Adafruit_MQTT_Publish(&mqtt, HOMIE_VERSION_FEED).publish(HOMIE_VERSION);
	Adafruit_MQTT_Publish(&mqtt, HOMIE_NODEID_FEED).publish(HOMIE_NODEID);
	Adafruit_MQTT_Publish(&mqtt, HOMIE_STATE_FEED).publish("init");
	Adafruit_MQTT_Publish(&mqtt, HOMIE_EXTENSIONS_FEED).publish(HOMIE_EXTENSIONS);
}



void Homie_device_ready()
{
	Adafruit_MQTT_Publish(&mqtt, HOMIE_STATE_FEED).publish("ready");
}

void Homie_declare_nodes()
{
	String nodes_feed = String(HOMIE_ROOT) + "/$nodes" ;
	Adafruit_MQTT_Publish(&mqtt, strToCharArray(nodes_feed)).publish(nodes.c_str());
}

void Homie_declare_nodes(String sNodes)
{
	String nodes_feed = String(HOMIE_ROOT) + "/$nodes" ;
	Adafruit_MQTT_Publish(&mqtt, strToCharArray(nodes_feed)).publish(sNodes.c_str());
}