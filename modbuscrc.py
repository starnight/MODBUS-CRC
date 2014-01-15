#!/usr/bin/env python
# -*- coding: utf-8 -*-

from crcmod import predefined;

def MODBUSCrc(payload):
	'''
	Have MODBUS CRC of the payload.
	Reference from http://crcmod.sourceforge.net/crcmod.predefined.html
	'''
	modbuscrc = predefined.Crc("modbus");
	modbuscrc.update(payload);
	return modbuscrc.crcValue;

if __name__ == "__main__":
	modbuscrc = predefined.Crc("modbus");
	modbuscrc.update(b"123456789");
	print(modbuscrc);

	print(hex(MODBUSCrc(b"123456789")).upper());
	print(hex(MODBUSCrc(b"987654321")).upper());
