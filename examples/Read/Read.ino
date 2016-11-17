/*
*  FRAM read examples
*  @miniqiang
*  2016.11.17
*/

#include <MB85RC16V.h>
#include <Wire.h>
MB85RC16V EEPROM;
void setup() {
  // put your setup code here, to run once:
	Write.begin();
	EEPROM.begin(0x50);
	Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(uint16_t a = 0; a < 2048;a++)
  {
	byte data = EEPROM.read(a);
	Serial.print(data);
	Serial.print(",");
  }
  Serial.println();
	
}