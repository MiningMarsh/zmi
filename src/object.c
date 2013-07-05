#include <stdlib.h>
#include <stdio.h>
#include "memory.h"
#include "globalvars.h"
#include "log.h"
#include "object.h"

// The address of the object table. While this is in the header, 
// I am pretty sure this address can be dynamically modified. 
zaddress objectTable() { return getWord(0x0a); }

// Get the memory address of an object
zaddress getObjectAddress(uzword Object) {

	// Revision 3 and down only have 255 objects.
	if(getZRev() < 4 && Object > 255) {
		logMessage(
			MFatal, 
			"getObjectAddress()",
			"Getting address of bad object %u.\n"
			"Only 255 objects supported in\n"
			"revision 3 and below.",
			Object
		);
		exit(1);
	}
	// Revision 4 and later have 2^16-1 objects, so no check needed.

	// The address we are going to return.
	zaddress Address = objectTable();
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
bool getObjectFlag(uzword Object, uzword Flag) {
	if((getZRev() < 4 && Flag > 31) || (getZRev() >= 4 && Flag > 47)) {
		// An invalid flag has been chosen.
		logMessage(
			MFatal, 
			"getObjectFlag()", 
			"An invalid flag number of %u was read.\n"
			"There are %u flags.",
			Flag,
			getZRev() >= 4 ? 48:32
		);
	}

	// Get the address of the object.
	zaddress ObjectAddress = getObjectAddress(Object);
	// The flags are a series of bytes at the beggining of the object in
	// the format 0.1.2.3.4 ...
	zaddress ByteAddress = getByte(ObjectAddress+(Flag/8)); //calculate the flag byte.
	return (ByteAddress>> (7 - (Flag%8)) )&1;
}

// Set a flag on an object.
void setObjectFlagValue(uzword Object, uzword Flag, bool Value) {
	if((getZRev() < 4 && Flag > 31) || (getZRev() >= 4 && Flag > 47)) {
		// An invalid flag has been chosen.
		logMessage(
			MFatal, 
			"setObjectFlag()",
			"An invalid flag number of %u was set.\n"
			"There are %u flags.",
			Flag,
			getZRev() >= 4 ? 48:32
		);
	}
	// Get the address of the object.
	zaddress ObjectAddress = getObjectAddress(Object);
	// The flags are a series of bytes at the beggining of the object in
	// the format 0.1.2.3.4 ...
	zaddress Address = ObjectAddress+(Flag/8); //calculate the flag byte.
	uzbyte Mask = ~(1<<(7 - (Flag%8)));
	uzbyte CurrentFlags = getByte(Address) & Mask;
	CurrentFlags |= Value << (7 - (Flag%8));
	setByte(Address, CurrentFlags);
}

uzword getPSC(uzword Object, int PSC) {

	// Get the object address and skip over the flags.
	zaddress Address = getObjectAddress(Object) + 4;

	if(getZRev() > 3) { // Revision 4 and higher have an extra two bytes of flags.
		Address += 2;
		// Revision 4 and higher have 2 bytes for location properties.
		return getWord(Address + 2*PSC); 
	} else {
		// Revision 3 and lower have 1 bytes for location properties.
		return getByte(Address + PSC); 
	}
}

void setPSC(uzword Object, uzword Value, int PSC) {
	
	// Get the object address and skip over the flags.
	zaddress Address = getObjectAddress(Object) + 4;
	if(getZRev() > 3) { // Revision 4 and higher have an extra two bytes of flags.
		Address += 2;
		// Revision 4 and higher have 2 bytes for location properties.
		setWord(Address + 2*PSC, Value);
	} else {
		// Check if a bad value was passed.
		if(Value > 0xFF) {
			logMessage(
				MFatal, 
				"setPSC()", 
				"Tried to set parent, child, sibling to invalid object %u.",
				Value
			);
		}
		// Revision 3 and lower have 1 bytes for location properties.
		setByte(Address + PSC,Value&0xFF);
	}
}

// Wrapper functions for setpsc. These remove some duplicated code.
// Set the parent of an object.
void setParent(uzword Object, uzword Value) {
	setPSC(Object, Value, 0); // Set ID 0 (parent).
}

void setChild(uzword Object, uzword Value) {
	setPSC(Object, Value, 2); // Set ID 2 (child).
}

void setSibling(uzword Object, uzword Value) {
	setPSC(Object, Value, 1); // Set ID 1 (sibling);
}

uzword getParent(uzword Object) {
	return getPSC(Object, 0); // Get ID 0 (parent)
}

uzword getChild(uzword Object) {
	return getPSC(Object, 2); // Get ID 2 (child).
}
uzword getSibling(uzword Object) {
	return getPSC(Object, 1); // Get ID 1 (sibling).
}

// Get the property table address of an object.
zaddress getPropertyTableAddress(uzword Object) {
	zaddress Address = getObjectAddress(Object);
	Address += (getZRev() < 4 ? 7 : 12); // Add property offset.
	return getWord(Address); // Return the last word of the object (the address of its property table).
}

zaddress propertyAddress(uzword Object, uzword Property) {
	if(!Property) {
		logMessage(MFatal, "propertyAddress()", "Tried to get property address of property 0.");
		exit(1);
	}
	zaddress Address = getPropertyTableAddress(Object); // Get the property table address of an object.	
	uzword Size = 0; // Holds the size of the current property.
	uzbyte HeaderTextSize = getByte(Address); // Get the size header.
	Address += 1+2*HeaderTextSize; // Skip the header, getting to the properties.
	uzword PropertyNumber;
	if(getZRev() < 4) {
		PropertyNumber = 0;
		while(PropertyNumber != Property) {
			Address += Size; // Skip last property scanned
			uzbyte Cell = getByte(Address); // Get the property size.
			PropertyNumber = Cell&31; // Get the property number.
			if(PropertyNumber < Property) { // Check if the property we are looking for doesn't seem to exist on this object.
				PropertyNumber = Property; // Terminate the loop.
				Address = 0; // Return 0 to signify the property does not exist.
			}
			Size = (Cell>>5)+2; // Get size of this property
		}
	} else {
		PropertyNumber = 0;
		while(PropertyNumber != Property) {
			Address += Size;
			uzword PropertyData = getByte(Address);
			PropertyNumber = PropertyData&63;
			if(Address>>7) {
				Size = (getByte(++Address)&63)+2;
				if(Size == 2)
					Size = 66;
			} else {
				Size = ((PropertyData>>6)&1)+2;
			}
			if(PropertyNumber < Property) { // Check if the property we are looking for doesn't seem to exist on this object.
				PropertyNumber = Property; // Terminate the loop.
				Address = 0; // Return 0 to signify the property does not exist.
			}
		}
	}
	return Address;
}

// A small wrapper meant to error out if an object doesn't exist instead of returning 0.
zaddress getPropertyAddress(uzword Object, uzword Property) {
	zaddress Address = propertyAddress(Object, Property);
	if(!Address) {
		logMessage(MFatal, "getPropertyAddress()", "Tried to get property address of nonexisting property.");
		exit(1);
	}
	return Address;
}

bool propertyExists(uzword Object, uzword Property) {
	return propertyAddress(Object, Property);
}

uzword getPropertySize(uzword Object, uzword Property) {
	zaddress Address = propertyAddress(Object, Property);
	if(!Address) {
		logMessage(MFatal, "getPropertySize()", "Tried to get property size of nonexisting property.");
		exit(1);
	}
	if(getZRev() < 4) {
		return (getByte(Address)>>5) + 1;
	} else {
		uzword PropertyData = getByte(Address);
		if(Address>>7) {
			zword Size = getByte(++Address)&63;
			if(!Size)
				Size = 64;
			return Size;
		} else {
			return ((PropertyData>>6)&1)+1;
		}
	}
}

zaddress getPropertyValueAddress(uzword Object, uzword Property) {
	zaddress Address = propertyAddress(Object, Property);
	if(!Address) {
		logMessage(MFatal, "getPropertyValueAddress()", "Tried to get property value address of nonexisting property.");
		exit(1);
	}
	if(getZRev() < 4)
		return Address + 1;
	if(getByte(Address)>>7)
		return Address + 2;
	return Address + 1;
}

uzword getDefaultPropertyValue(uzword Property) {
	// Each default property is 2 bytes long, and index by 1.
	return getWord(objectTable() + (2*(Property - 1)));
}
