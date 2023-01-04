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
typedef int Elemtype;

typedef struct {
	Elemtype* base;
	Elemtype* top;
	int stacksize;
}SqStack;
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
	S.stacksize = 0;
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
	*S.top = e;
	S.top++;
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
int F(int n)
{//�ݹ��㷨
	if (n == 0) {
		return (n + 1);
	}
	else if (n > 0) {
		return n * F(n / 2);
	}
}

int F_stack(int n)
{//�����ݹ�
	SqStack S;
	InitStack(S);
	int out = 1;
	while (n > 0) {
		Push(S, n);
		n /= 2;
	}
	while (S.top != S.base) {
		Pop(S, n);
		out *= n;
	}
	return out;
}

int main()
{
	int n = 5;
	printf("%d\n", F(n));
	printf("%d\n", F_stack(n));

	return n;
}