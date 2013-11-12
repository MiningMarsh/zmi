#include <stdlib.h>
#include "opcodes.h"
#include "memory.h"

void (*CallOpCode[256+30])(void) = {NULL};

// If you say bloody mary three times while spinning in front of a mirror, this
// code appears.
void initOpCodes() {
	for(int I = 0; I < 256+30; I++)
		CallOpCode[I] = &opNonexistant;
	for(int I = 0; I < 7; I++) {
		CallOpCode[0+32*I] = &opNop;
		CallOpCode[1+32*I] = &opJe;
		CallOpCode[2+32*I] = &opJl;
		CallOpCode[3+32*I] = &opJg;
		CallOpCode[4+32*I] = &opDecChk;
		CallOpCode[5+32*I] = &opIncChk;
		CallOpCode[6+32*I] = &opJin;
		CallOpCode[7+32*I] = &opTest;
		CallOpCode[8+32*I] = &opOr;
		CallOpCode[9+32*I] = &opAnd;
		CallOpCode[10+32*I] = &opTestAttr;
		CallOpCode[11+32*I] = &opSetAttr;
		CallOpCode[12+32*I] = &opClearAttr;
		CallOpCode[13+32*I] = &opStore;
		CallOpCode[14+32*I] = &opInsertObj;
		CallOpCode[15+32*I] = &opLoadw;
		CallOpCode[16+32*I] = &opLoadb;
		CallOpCode[17+32*I] = &opGetProp;
		CallOpCode[18+32*I] = &opGetPropAddr;
		CallOpCode[19+32*I] = &opGetNextProp;
		CallOpCode[20+32*I] = &opAdd;
		CallOpCode[21+32*I] = &opSub;
		CallOpCode[22+32*I] = &opMul;
		CallOpCode[23+32*I] = &opDiv;
		CallOpCode[24+32*I] = &opMod;
		if(getZRev() >= 4)
			CallOpCode[25+32*I] = &opCall;
		if(getZRev() >= 5)
			CallOpCode[26+32*I] = &opCallVN;
		//if(getZRev() == 5 || getZRev() == 6)
		//	CallOpCode[28+32*I] = &opThrow;
	}
	for(int I = 0; I  < 32; I++) {
		CallOpCode[I+32*4] = &opNonexistant;
		CallOpCode[I+32*5] = &opNonexistant;
	}
	for(int I = 0; I < 3; I++) {
		CallOpCode[128+16*I] = &opJz;
		CallOpCode[129+16*I] = &opGetSibling;
		CallOpCode[130+16*I] = &opGetChild;
		CallOpCode[131+16*I] = &opGetParent;
		CallOpCode[132+16*I] = &opGetPropLen;
		CallOpCode[133+16*I] = &opInc;
		CallOpCode[134+16*I] = &opDec;
		CallOpCode[135+16*I] = &opPrintAddr;
		if(getZRev() >= 4)
			CallOpCode[136+16*I] = &opCall;
		CallOpCode[138+16*I] = &opPrintObj;
		CallOpCode[139+16*I] = &opRet;
		CallOpCode[140+16*I] = &opJump;
		CallOpCode[141+16*I] = &opPrintPaddr;
		if(getZRev() <= 4)
			CallOpCode[143+16*I] = &opNot;
		else
			CallOpCode[143+16*I] = &opCall1N;
	}
	CallOpCode[176] = &opRtrue;
	CallOpCode[177] = &opRfalse;
	CallOpCode[178] = &opPrint;
	CallOpCode[184] = &opRetPopped;
	CallOpCode[187] = &opNewLine;
	CallOpCode[224] = &opCall;
	CallOpCode[225] = &opStorew;
	CallOpCode[226] = &opStoreb;
	CallOpCode[227] = &opPutProp;
	CallOpCode[228] = &opRead;
	CallOpCode[229] = &opPrintChar;
	CallOpCode[230] = &opPrintNum;
	CallOpCode[231] = &opRandom;
	CallOpCode[232] = &opPush;
	CallOpCode[233] = &opPull;
	CallOpCode[241] = &opSetTextStyle;
	if(getZRev() > 4) {
		CallOpCode[248] = &opNot;
		CallOpCode[249] = &opCallVN;
	}
}
