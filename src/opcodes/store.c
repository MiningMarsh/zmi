#include "command.h"
#include "memory.h"

/***********************************
 * 2OP:13 D store (variable) value *
 *************************************************************************
 * Set the VARiable referenced by the operand to value.                  *
 *************************************************************************/
 
void opStore() {
	setZVar(Operand[0], Operand[1]);
}
