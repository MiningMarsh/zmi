#ifndef OPCODES_H_
#define OPCODES_H_ 1

// Opcodes.
void opAdd();
void opAnd();
void opArtShift();
void opCall();
void opCallVN();
void opCatch();
void opCheckArgCount();
void opCheckUnicode();
void opClearAttr();
void opDec();
void opDecChk();
void opDiv();
void opDummy();
void opGetChild();
void opGetParent();
void opGetProp();
void opGetPropAddr();
void opGetSibling();
void opInc();
void opIncChk();
void opInsertObj();
void opJe();
void opJg();
void opJin();
void opJl();
void opJump();
void opJz();
void opLoadb();
void opLoadw();
void opLogShift();
void opMod();
void opMul();
void opNonexistant();
void opNewLine();
void opNop();
void opNot();
void opOr();
void opPiracy();
void opPrint();
void opPrintAddr();
void opPrintChar();
void opPrintNum();
void opPrintObj();
void opPrintPaddr();
void opPrintRet();
void opPull();
void opPush();
void opPutProp();
void opRandom();
void opRead();
void opRemoveObj();
void opRet();
void opRetPopped();
void opRfalse();
void opRtrue();
void opSetAttr();
void opStore();
void opStoreb();
void opStorew();
void opSub();
void opTest();
void opTestAttr();
void opThrow();

// Table of opcodes.
void (*CallOpCode[256+30])(void);

void initOpCodes();

#endif /* OPCODES_H_ */
