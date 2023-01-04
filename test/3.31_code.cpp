#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define INFEASIBLE	-1
#define OVERFLOW	-2

#define STACK_INIT_SIZE 100
#define STACKINCREMENT	10
typedef char Elemtype;

typedef struct {
	Elemtype* base;
	Elemtype* top;
	int stacksize;
}SqStack;

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
	S.stacksize = 0;
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
	*S.top = e;
	S.top++;
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

int ReadString(SqStack& S)
{
	char p[100];
	int i = 0;
	printf("请输入字符串并以@为结束标志\n");

	scanf("%s", p);
	while ( p[i] != '@') {
		Push(S, p[i]);
		i++;
	}
	return OK;
}

int IsPalindrome(SqStack& S)
{
	char* h, * t;
	h = S.base;
	t = S.top - 1;
	while (t >= h) {
		if (*t != *h) {
			return 0;
		}
		t--;
		h++;
	}
	return 1;
}

int main()
{
	SqStack S;
	InitStack(S);
	ReadString(S);
	if (IsPalindrome(S) == 1) {
		printf("该字符串是回文序列");
	}
	else {
		printf("该字符串不是回文序列");
	}
	DestroyStack(S);
	return 0;
}