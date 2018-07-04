/*
*  FRAM read examples
*  @miniqiang
*  2016.11.17
*  2018.7.4 修订
*/
#include <MB85RC16V.h>

MB85RC16V EEPROM;   //将其初始化成EEPRM
void setup() {
  // put your setup code here, to run once:
	
	EEPROM.begin();   //从这里以后，完全和EEPROM代码兼容
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