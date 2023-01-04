#define _CRT_SECURE_NO_WARNINGS
#include "stack.h"

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

int GetTop(SqStack S,Elemtype& e)
{//��ȡջ��Ԫ��
	int e=0;
	if (S.top == S.base) {
		return ERROR;
	}
	e = *(S.top - 1);
	return OK;
}

int Push(SqStack& S,Elemtype e)
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

int PrintStack(SqStack S,int Printtype)
{//��ӡջ�е�Ԫ��,��PrinttypeΪ1ʱ���ӵ׵�����ӡ����PrinttypeΪ0ʱ���Ӷ����״�ӡ.
 //ע��˺������int�ͣ�ע����������
	if (S.base == S.top) {//ջΪ�գ��޷���ӡ
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
{//�˺���Ϊint�ͣ�ע����������
	int x;
	printf("������ջ��Ԫ�ز���-1Ϊ������־\n");

	scanf("%d", &x);
	while (x != -1) {
		Push(S, x);
		scanf("%d", &x);
	}

	return OK;
}
