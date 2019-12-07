#include <SmingCore.h>
#include <Debug.h>
#include "ArduinoJson.h"

#define MQTT_CONF_FILENAME "test"

Timer callFunc;

#define CONSTNUMBER 2^60

uint64_t someLongNumber = CONSTNUMBER;


void f(String arg) {
	if(someLongNumber != CONSTNUMBER) {
		debugf("ERROR ERROR ERROR");
	}
}

void f2() {
	f("someTestString");
}

void init()
{
	Serial.begin(SERIAL_BAUD_RATE, SERIAL_8N1,
				 SERIAL_FULL);		// 115200 by default, GPIO1,GPIO3, see Serial.swap(), HardwareSerial
	Serial.systemDebugOutput(true); // Debug output to serial

	Serial.commandProcessing(true); //also executes commandHandler.registerSystemCommands(); ?

	Debug.setDebug(Serial);
	Debug.initCommand();
	Debug.start();
	Debug.printf("This is the debug output\r\n");

	if(someLongNumber == CONSTNUMBER)
		debugf("So far, so good");
	callFunc.initializeMs(10, f2).start();
}
