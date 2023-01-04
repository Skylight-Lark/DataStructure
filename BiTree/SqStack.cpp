#define _CRT_SECURE_NO_WARNINGS
#include "bitree.h"

int InitStack(SqStack& S)
{//初始化栈
	S.base = (Elemtype*)malloc(STACK_INIT_SIZE * sizeof(Elemtype));
	if (!S.base) {
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

int DestroyStack(SqStack& S)
{//摧毁整个栈
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
{//获取栈顶元素
	if (S.top == S.base) {
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}

int Push(SqStack& S, Elemtype e)
{//插入元素e为新的栈顶元素
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
{//删除栈顶元素，用e返回其值
	if (S.top == S.base) {//判断是否为空
		return ERROR;
	}
	e = *--S.top;
	return OK;
}

int StackEmpty(SqStack S)
{//判断栈是否为空，若为空则返回TRUE，否则返回FALSE
	if (S.base == S.top) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}