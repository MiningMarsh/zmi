#ifndef STACK_H
#define STACK_H 1

#include <stdbool.h>

#define STACK_H_DEFAULT_STACK_SIZE 64

typedef struct stack stack;

stack* createStack();
void destroyStack(stack* Stack);

bool pushStack(stack* const Stack, void* Value);
void* popStack(stack* const Stack);
void* atStack(const stack* const Stack, unsigned long long Index);
bool setMemorySizeStack(stack* Stack, const unsigned int Size);
unsigned long long sizeStack(const stack* const Stack);

#endif /* STACK_H */
