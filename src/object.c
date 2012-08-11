#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "memory.h"


#define getZRev() getByte(0)

// TODO: function names may need re-factoring. (Eclipse should handle this.)
// TODO: Why doesn't it resolve getZRev() in this file?
// TODO: figure out why the white mailbox object wont be displayed in zork.
// TODO: stop returning 0 on the 0 object, should be handled by the opcodes, not the object manipulators.
// TODO: include object file format in object.c
// TODO: include a zork.z* file, preferably .z3
// The address of the object table. While this is in the header, I am pretty sure this address can
// be dynamically modified. Leave in the less optimized state for now.
#define objectTable getWord(0x0a);

// Get the address of an object.
uint32_t getobjadr(uint16_t obj)
{

	if(getZRev() < 4 && obj > 255) // Version 3 and down only have 255 objects.
	{
		char str[256];
		sprintf(str, "%u", obj);
		fputs("Tried to get non-existent object ", stderr);
		fputs(str, stderr);
		fputs(".\n", stderr);
		exit(1);
	}
	uint32_t baseadr = objectTable;
	if(getZRev() > 3)
		baseadr += 63*2 + 14*(obj - 1);
	else
		baseadr += 31*2 + 9*(obj - 1);
	return baseadr;
}

// Get a flag off an object
uint16_t getObjectFlag(uint16_t obj, uint16_t flag)
{

	// The flags seem to be gotten fine, after checking a disassemble. Further bug
	// testing may be needed though.
	uint32_t objadr = getobjadr(obj);
	uint8_t adr = getByte(objadr+(flag/8)); //calculate the flag byte.
	return ((adr>>(flag - (flag/8)*8))&1); // get the flag from the flag byte.
}

// Set a flag on an object.
void setObjectFlagValue(uint16_t obj, uint16_t flag, uint16_t val)
{
	// See getobjflag.
	uint32_t objadr = getobjadr(obj);
	if(objadr != 0)
	{
		uint8_t adr = objadr+flag/8;
		uint8_t mask = 1<<(flag - (flag/8)*8);
		setByte(adr, getByte(adr)&mask);
	}
}

uint16_t getpsc(uint16_t obj, uint16_t psc)
{
	// May be the cause of mailbox bug, though bug testing seemed to show parents and sisters were being detected fine.
	// major bug testing needed here.
	uint32_t objadr = getobjadr(obj) + 4;

	if(getZRev() > 3) // Revision 4 and higher have an extra two bytes of flags.
	{
		objadr += 2;
		return getWord(objadr + 2*psc); // Revision 4 and higher have 2 bytes for location properties.
	} else
	{
		return getByte(objadr + psc); // Revision 3 and lower have 1 bytes for location properties.
	}
}

void setpsc(uint16_t obj, uint16_t val, uint16_t psc)
{
	uint32_t objadr = getobjadr(obj) + 4;
	if(getZRev() > 3) {
		objadr += 2;
		setWord(objadr + 2*psc, val&0xFFFF);
	} else {
		setByte(objadr + psc,val&0xFF);
	}
}


// Wrapper functions for setpsc. These remove some duplicated code.
// Set the parent of an object.
void setParent(uint16_t obj, uint16_t val)
{
	setpsc(obj, val, 0); // Set ID 0 (parent).
}
void setChild(uint16_t obj, uint16_t val)
{
	setpsc(obj, val, 2); // Set ID 2 (child).
}
void setSibling(uint16_t obj, uint16_t val)
{
	setpsc(obj, val, 1); // Set ID 1 (sibling).
}

uint16_t getParent(uint16_t obj)
{
	return getpsc(obj, 0); // Get ID 0 (parent)
}
uint16_t getChild(uint16_t obj)
{
	return getpsc(obj, 2); // Get ID 2 (child).
}
uint16_t getSibling(uint16_t obj)
{
	return getpsc(obj, 1); // Get ID 1 (sibling).
}

// Get the property table address of an object.
uint16_t getPropertyTableAdr(uint16_t obj)
{
	uint32_t adr = getobjadr(obj);
	adr += 7; // Add property offset.
	if(getZRev() > 3)
		adr += 5; // Property offset is larger in v4+ games.
	return getWord(adr); // Return the last word of the object (the address of its property table).
}


// Get the address of the start of an objects property.
uint16_t getPropertyAdr(uint16_t obj, uint16_t prop)
{
	uint32_t adr = getPropertyTableAdr(obj); // Get the property table address of an object.
	uint16_t size = 0; // Holds the size of the current property.
	uint8_t hdrnamesz = getByte(adr); // Get the size header.
	adr += 1+2*hdrnamesz; // Skip the header, getting to the properties.
	if(getZRev() < 4) // TODO: Currently the revision 5 z-machine is not supported in this area.
	{
		uint16_t propn = 0xFFFF;
		while(propn != prop)
		{
			adr += size; // Skip last property scanned
			uint8_t cell = getByte(adr); // Get the property size.
			propn = cell&31; // Get the property number.
			if(propn < prop) // Check if the property we are looking for doesn't seem to exist on this object.
			{
				propn = prop; // Terminate the loop.
				adr = 0; // Return 0 to signify the property does not exist.
			}
			size = ((cell>>5)&7)+2; // Get size of this property
		}
	}
	return adr; // Return pointer to the property (including size byte).
}
