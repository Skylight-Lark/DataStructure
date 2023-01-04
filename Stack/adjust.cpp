#include "stack.h"

int AdjustStack(SqStack& T)
{//������Ӳ������Ӳ��H��1��ʾ��������0��ʾ
	int d;
	SqStack H,S;
	InitStack(H);
	InitStack(S);
	if (S.base == S.top) {
		return ERROR;//ջΪ��
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