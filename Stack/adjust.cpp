#include "stack.h"

int AdjustStack(SqStack& T)
{//调整软硬座，令硬座H用1表示，软座用0表示
	int d;
	SqStack H,S;
	InitStack(H);
	InitStack(S);
	if (S.base == S.top) {
		return ERROR;//栈为空
	}
	while (T.top != T.base) {
		if (*(T.top - 1) == 1) {
			Pop(T, d);
			Push(H, d);
		}
		else if (*(T.top - 1) == 0) {
			Pop(T, d);
			Push(S, d);
		}
	}
	while (H.top != H.base) {
		Pop(H, d);
		Push(T, d);
	}
	while (S.top != S.base) {
		Pop(S, d);
		Push(T, d);
	}
	DestroyStack(H);
	DestroyStack(S);
	return OK;
}