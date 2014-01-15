/*------------------------------------------------------------------------------
This is example to calculate MODBUS CRC.
Reference from http://www.nongnu.org/avr-libc/user-manual/group__util__crc.html
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdint.h>

/* Function to calculate MODBUS CRC. */
uint16_t crc16_update(uint16_t crc, uint8_t a) {
	int i;

	crc ^= (uint16_t)a;
	for (i = 0; i < 8; ++i) {
		if (crc & 1)
			crc = (crc >> 1) ^ 0xA001;
		else
			crc = (crc >> 1);
	}

	return crc;
}

int main(void) {
	uint16_t crc;
	int i;
	uint8_t str[] = "123456789";

	/* MODBUS CRC initial value is 0xFFFF. */
	crc = 0xFFFF;
	for(i = 0; i < 9; i++)
		crc = crc16_update(crc, str[i]);
	printf("%X\n", (int)crc);
	
	crc = 0xFFFF;
	for(i = 0; i < 9; i++)
		crc = crc16_update(crc, str[8-i]);
	printf("%X\n", (int)crc);

}
