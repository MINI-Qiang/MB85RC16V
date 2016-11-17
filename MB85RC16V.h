/**************************************************************************/
/*! 

*/
/**************************************************************************/
#ifndef MB85RC16V_H
#define MB85RC16V_H
#include <Arduino.h>
#include <Wire.h>

class MB85RC16V{
 public:
 
  MB85RC16V(void);
  void 	   begin(uint8_t addr);
  uint8_t  read  (uint16_t framAddr);
  void 	   read (uint16_t framAddr,uint8_t num,uint8_t data[]);
  void 	   read (uint16_t framAddr,uint8_t num,char data[]);
  void     write (uint16_t framAddr, uint8_t value);
  void 	   write (uint16_t framAddr, uint8_t length,uint8_t data[]);
  void     write (uint16_t framAddr,uint8_t length, char data[]);
 private:
  uint8_t _i2c_addr;
};

#endif
