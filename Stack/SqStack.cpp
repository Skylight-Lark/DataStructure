#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

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

int GetTop(SqStack S,Elemtype& e)
{//获取栈顶元素
	int e=0;
	if (S.top == S.base) {
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}

int Push(SqStack& S,Elemtype e)
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

int PrintStack(SqStack S,int Printtype)
{//打印栈中的元素,当Printtype为1时，从底到顶打印；当Printtype为0时，从顶到底打印.
 //注意此函数针对int型，注意数据类型
	if (S.base == S.top) {//栈为空，无法打印
		return ERROR;
	}
	int length = S.top - S.base;
	int i;
	if (Printtype == 1)
	{
		for (i = 0; i < length; i++)
		{
			printf("%d\n", S.base[i]);
		}
	}
	else if (Printtype == 0) {
		for (i = length - 1; i >= 0; i--)
		{
			printf("%d\n", S.base[i]);
		}
	}
	return OK;
}

int CreatStack(SqStack& S)
{//此函数为int型，注意数据类型
	int x;
	printf("请输入栈的元素并以-1为结束标志\n");

	scanf("%d", &x);
	while (x != -1) {
		Push(S, x);
		scanf("%d", &x);
	}

	return OK;
}
