#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

struct stack {
	void** Bottom;
	unsigned long long MemorySize;
	void** Back;
};

stack* createStack() {
	stack* ToReturn = malloc(sizeof(stack));
	if(!ToReturn) {
		return NULL;
	}
	ToReturn->MemorySize = STACK_H_DEFAULT_STACK_SIZE;
	ToReturn->Bottom = malloc(sizeof(void*)*ToReturn->MemorySize);
	if(!ToReturn->Bottom) {
		free(ToReturn);
		return NULL;
	}
	ToReturn->Back = ToReturn->Bottom - 1;
	return ToReturn;
}

void destroyStack(stack* Stack) {
	free(Stack->Bottom);
	free(Stack);
}

unsigned long long sizeStack(const stack* const Stack) {
	return Stack->Back - Stack->Bottom + 1;
}

bool setMemorySizeStack(stack* Stack, const unsigned int Size) {
	if(sizeStack(Stack) > Size) {
		return false;
	}
	void** NewBottom = realloc(Stack->Bottom, Size*sizeof(void*));
	if(!NewBottom) {
		return false;
	}
	Stack->Bottom = NewBottom;
	Stack->MemorySize = Size;
	return true;
}

bool pushStack(stack* const Stack, void* Value) {
	Stack->Back++;
	if((unsigned)(Stack->Back - Stack->Bottom + 1) >= Stack->MemorySize)
		if(!setMemorySizeStack(Stack, Stack->MemorySize * 2))
			return false;
	*(Stack->Back) = Value;
	return true;
}

void* popStack(stack* const Stack) {
	if(!sizeStack(Stack))
		return NULL;
	return *(Stack->Back--);
}

void* atStack(const stack* const Stack, unsigned long long Index) {
	if(Stack->Back - Index < Stack->Bottom)
		return NULL;
	return *(Stack->Back - Index);
}
