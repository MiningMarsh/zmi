#include "command.h"
#include "memory.h"

/*******************************
 * VAR:233 9 1 pull (variable) *
 * 6 pull stack -> (result)    *
 *************************************************************************
 * Pulls value off a stack. (If the stack underflows, the interpreter    *
 * should halt with a suitable error message.) In Version 6, the stack   *
 * in question may be specified as a user one: otherwise it is the game  *
 * stack.                                                                *
 *************************************************************************/
 
void opPull() {
	setZVar(Operand[0],popZStack());
}

