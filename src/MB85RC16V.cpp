/**************************************************************************/
/*!
Address for MB85RC16V : 1010+A2+A1+A0	(2K x 8)
Size of Address :11 bit 
Sum : A2+A1+A0+11 bit  = 16K
*/
/**************************************************************************/

#include "MB85RC16V.h"

MB85RC16V::MB85RC16V(void) 
{
}


void MB85RC16V::begin() 
{
	Wire.begin();
}

/**************************************************************************/
/*!
    @brief  Writes a byte at the specific FRAM address
    
    @params[in] i2cAddr
                The I2C address of the FRAM memory chip (1010+A2+A1+A0)
    @params[in] framAddr
                The 11-bit address to write to in FRAM memory
    @params[in] i2cAddr
                The 8-bit value to write at framAddr
*/
/**************************************************************************/
void MB85RC16V::write(uint16_t framAddr, uint8_t value)
{
  Wire.beginTransmission(_i2c_addr);
  Wire.write(framAddr&0x7ff);
  Wire.write(value);
  Wire.endTransmission();
}
//continuous 
void MB85RC16V::write(uint16_t framAddr,uint8_t length, uint8_t *data)
{
  uint16_t addr = framAddr;
  for(int i=0;i<length;i++)
  {
    Wire.beginTransmission(_i2c_addr);
    Wire.write(addr&0x7ff);
	Wire.write(data[i]);
	Wire.endTransmission();
	addr+=1;
  }
}


void MB85RC16V::update(uint16_t framAddr, uint8_t value)
{
  Wire.beginTransmission(_i2c_addr);
  Wire.write(framAddr&0x7ff);
  Wire.write(value);
  Wire.endTransmission();
}
//continuous 
void MB85RC16V::update(uint16_t framAddr,uint8_t length, uint8_t *data)
{
  uint16_t addr = framAddr;
  for(int i=0;i<length;i++)
  {
    Wire.beginTransmission(_i2c_addr);
    Wire.write(addr&0x7ff);
	Wire.write(data[i]);
	Wire.endTransmission();
	addr+=1;
  }
}

/**************************************************************************/
/*!
    @brief  Reads an 8 bit value from the specified FRAM address

    @params[in] i2cAddr
                The I2C address of the FRAM memory chip (1010+A2+A1+A0)
    @params[in] framAddr
                The 11-bit address to read from in FRAM memory

    @returns    The 8-bit value retrieved at framAddr
*/
/**************************************************************************/
uint8_t MB85RC16V::read(uint16_t framAddr)
{
  Wire.beginTransmission(_i2c_addr);
  Wire.write(framAddr&0x7ff);
  Wire.endTransmission();

  Wire.requestFrom(_i2c_addr, (uint8_t)1);
  while(Wire.available()>0)
  {
	return Wire.read();
  }
}
void MB85RC16V::read(uint16_t framAddr,uint8_t num,uint8_t *data)
{
  Wire.beginTransmission(_i2c_addr);
  Wire.write(framAddr&0x7ff);
  Wire.endTransmission();

  Wire.requestFrom(_i2c_addr, (uint8_t)num);
  for(uint8_t i=0;Wire.available()>0;i++)
  {
	data[i]=Wire.read(); 
  }
}

