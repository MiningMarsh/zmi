#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include "globalvars.h"
#include "log.h"


// TODO: function names may need re-factoring.
// TODO: stop returning 0 on the 0 object, should be handled by the opcodes, not the object manipulators.

// The address of the object table. While this is in the header, 
// I am pretty sure this address can be dynamically modified. 
uint16_t objectTable() { return getWord(0x0a); }

// Get the memory address of an object
uint32_t getObjectAddress(uint16_t Object) {

	// Revision 3 and down only have 255 objects.
	if(getZRev() < 4 && Object > 255) {
		char Message[256];
		sprintf(
			Message, 
			"Getting address of bad object %u."
			"Only 255 objects supported in revision 3 and below.",
			Object
		);
		logMessage(MFatal, "getObjectAddress()", Message);
		exit(1);
	}
	// Revision 4 and later have 16**4 objects, so no check needed.

	// The address we are going to return.
	uint32_t Address = objectTable();
	if(getZRev() > 3)
		// Revisions <= 4 have a 63 word object defaults table, and each 
		// object after that is 14 bytes.
		Address += 63*2 + 14*(Object - 1);
	else
		// Revisions > 4 have a 31 word object defaults table, and each 
		// object after that is 9 bytes.
		Address += 31*2 + 9*(Object - 1);
	return Address;
}

// Get a flag off an object
uint16_t getObjectFlag(uint16_t Object, uint16_t Flag) {
	if((getZRev() < 4 && Flag > 31) || (getZRev() >= 4 && Flag > 47)) {
		// An invalid flag has been chosen.
		char Message[256];
		sprintf(
			Message,
			"An invalid flag number of %u was read.\n",
			"There are %u flags.",
			Flag,
			getZRev() >= 4 ? 48:32
		);
		logMessage(MFatal, "getObjectFlag()", Message);
	}

	// Get the address of the object.
	uint32_t ObjectAddress = getObjectAddress(Object);
	// The flags are a series of bytes at the beggining of the object in
	// the format 7.6.5.4.3.2.1.0 15.14.13.12.11.10.9.8 ...
	uint8_t Address = getByte(ObjectAddress+(Flag/8)); //calculate the flag byte.
	return ((Address>>(Flag - (Flag/8)*8))&1);
}

// Set a flag on an object.
void setObjectFlagValue(uint16_t Object, uint16_t Flag, uint16_t Value) {
	if((getZRev() < 4 && Flag > 31) || (getZRev() >= 4 && Flag > 47)) {
		// An invalid flag has been chosen.
		char Message[256];
		sprintf(
			Message,
			"An invalid flag number of %u was set.\n",
			"There are %u flags.",
			Flag,
			getZRev() >= 4 ? 48:32
		);
		logMessage(MFatal, "setObjectFlag()", Message);
	}
	// See getObjectFlag.
	uint32_t ObjectAddress = getObjectAddress(Object);
	uint8_t Address = ObjectAddress+Flag/8;
	uint8_t Mask = 1<<(Flag - (Flag/8)*8);
	setByte(Address, getByte(Address)&Mask);
}

uint16_t getPSC(uint16_t Object, uint16_t PSC) {

	// Get the object address and skip over the flags.
	uint32_t Address = getObjectAddress(Object) + 4;

	if(getZRev() > 3) { // Revision 4 and higher have an extra two bytes of flags.
		Address += 2;
		// Revision 4 and higher have 2 bytes for location properties.
		return getWord(Address + 2*PSC); 
	} else {
		// Revision 3 and lower have 1 bytes for location properties.
		return getByte(Address + PSC); 
	}
}

void setPSC(uint16_t Object, uint16_t Value, uint16_t PSC) {
	
	// Get the object address and skip over the flags.
	uint32_t Address = getObjectAddress(Object) + 4;
	if(getZRev() > 3) { // Revision 4 and higher have an extra two bytes of flags.
		// Check if a bad value was passed.
		if(Value > 0xFFFF) {
			char Message[256];
			sprintf(
				Message,
				"Tried to set parent, child, sibling to invalid object %u.",
				Value
			);
			logMessage(MFatal, "setPSC()", Message);
		}
		Address += 2;
		// Revision 4 and higher have 2 bytes for location properties.
		setWord(Address + 2*PSC, Value);
	} else {
		// Revision 3 and lower have 1 bytes for location properties.
		setByte(Address + PSC,Value&0xFF);
	}
}

// Wrapper functions for setpsc. These remove some duplicated code.
// Set the parent of an object.
void setParent(uint16_t Object, uint16_t Value) {
	setPSC(Object, Value, 0); // Set ID 0 (parent).
}

void setChild(uint16_t Object, uint16_t Value) {
	setPSC(Object, Value, 2); // Set ID 2 (child).
}

void setSibling(uint16_t Object, uint16_t Value) {
	setPSC(Object, Value, 1); // Set ID 1 (sibling);
}

uint16_t getParent(uint16_t Object) {
	return getPSC(Object, 0); // Get ID 0 (parent)
}

uint16_t getChild(uint16_t Object) {
	return getPSC(Object, 2); // Get ID 2 (child).
}
uint16_t getSibling(uint16_t Object) {
	return getPSC(Object, 1); // Get ID 1 (sibling).
}

// Get the property table address of an object.
uint16_t getPropertyTableAdr(uint16_t Object)
{
	uint32_t adr = getObjectAddress(Object);
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
