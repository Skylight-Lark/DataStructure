#define _CRT_SECURE_NO_WARNINGS
#include "bitree.h"

int InitStack(SqStack& S)
{//��ʼ��ջ
	S.base = (Elemtype*)malloc(STACK_INIT_SIZE * sizeof(Elemtype));
	if (!S.base) {
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

int DestroyStack(SqStack& S)
{//�ݻ�����ջ
	if (S.base == NULL) {
		return ERROR;
	}
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize = 0;
	return OK;
}

int GetTop(SqStack S, Elemtype& e)
{//��ȡջ��Ԫ��
	if (S.top == S.base) {
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}

int Push(SqStack& S, Elemtype e)
{//����Ԫ��eΪ�µ�ջ��Ԫ��
	if (S.top - S.base >= S.stacksize) {
		S.base = (Elemtype*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(Elemtype));
		if (!S.base) {
			exit(ERROR);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

int Pop(SqStack& S, Elemtype& e)
{//ɾ��ջ��Ԫ�أ���e������ֵ
	if (S.top == S.base) {//�ж��Ƿ�Ϊ��
		return ERROR;
	}
	e = *--S.top;
	return OK;
}

int StackEmpty(SqStack S)
{//�ж�ջ�Ƿ�Ϊ�գ���Ϊ���򷵻�TRUE�����򷵻�FALSE
	if (S.base == S.top) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}