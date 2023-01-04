#define _CRT_SECURE_NO_WARNINGS
#include "link.h"

//int main()
//{
//	/*SqList L;
//	Elemtype e = '\0';
//	InitList_Sq(L);
//	InserTail_Sq(L, 'a');
//	InserTail_Sq(L, 'b');
//	InserTail_Sq(L, 'c');
//	InserTail_Sq(L, 'e');
//	PrintList_Sq(L);
//	Lengh_Sq(L);
//	EmptyList_Sq(L);
//	PrintPosE_Sq(L, 3);
//	PrintPosL_Sq(L, 'a');
//	ListInser_Sq(L, 4, 'f');
//	PrintList_Sq(L);
//	ListDelete_Sq(L, 3, e);
//	PrintList_Sq(L);*/
//	
//	SqList L1;
//	InitList_Sq(L1);
//	Create_String(L1);
//	PrintList_Sq(L1);
//
//	Lengh_Sq(L1);
//	if (IsPalindrome(L1)) {
//		printf("\n�ǻ�������");
//	}
//	else {
//		printf("\n���ǻ�������");
//	}
//	DestroyList_Sq(L1);
//	return 0;
//}

int InitList_Sq(SqList& L)
{//����һ���ձ�
	L.elem = (Elemtype*)malloc(LIST_INIT_SIZE * sizeof(Elemtype));
	if (!L.elem) {
		exit(OVERFLOW);
	}
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

int Create_String(SqList& L)
{//�����ַ���
	int i = 0;
	char ch;
	printf("\n�������ַ�������@Ϊ������־��");
	scanf("%c",&ch);
	while (ch != '@') {
		if (L.length >= L.listsize)
		{
			L.elem = (Elemtype*)realloc(L.elem, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(Elemtype));
			if (!L.elem) {
				exit(OVERFLOW);
			}
			L.listsize += LISTINCREMENT;
		}
		L.elem[i] = ch;
		L.length++;
		scanf("%c", &ch);
		i++;
	}
	return OK;
}

int IsPalindrome(SqList L)
{//�ж��ַ����Ƿ�Ϊ�������У������TRUE�������FALSE��
	int h = 0;
	int r ;
	if (EmptyList_Sq(L)) {
		printf("\n����Ϊ�ձ�");
		return ERROR;
	}
	r = L.length - 1;
	for (; h <= r; h++, r--)
	{
		if (L.elem[h] != L.elem[r]) {
			return FALSE;
		}
	}
	return TRUE;
}
int InserTail_Sq(SqList& L, Elemtype e)
{//β�巨˳���
	Elemtype* newbase;
	if (L.length >= L.listsize) {
		newbase = (Elemtype*)realloc(L.elem, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(Elemtype));
		if (!newbase) {
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	L.elem[L.length] = e;
	L.length++;
	return OK;
}

int PrintList_Sq(SqList L)
{//���˳���
	if (L.length < 0)
	{
		printf("\n˳����ȴ���");
		return ERROR;
	}
	printf("\n˳���");
	for (int i = 0; i < L.length; i++)
	{
		printf("%c", L.elem[i]);
	}
	return OK;
}

int Lengh_Sq(SqList L)
{//���˳���ĳ���
	if (L.length < 0||L.length>L.listsize)
	{
		printf("\n˳����ȴ���");
		return ERROR;
	}
	printf("\n˳���ĳ��ȣ�%d", L.length);
	return OK;
}

int EmptyList_Sq(SqList L)
{//�ж�˳����Ƿ�Ϊ�գ���Ϊ�գ������1������Ϊ�գ������0
	if (L.length < 0)
	{
		printf("\n˳����ȴ���");
		return ERROR;
	}
	else if (L.length == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int PrintPosE_Sq(SqList L, int i)
{//����ض�λ��Ԫ��
	if (i<1 || i>L.length) {
		return ERROR;
	}
	printf("\n˳����%d��Ԫ�أ�%c", i, L.elem[i - 1]);
	return OK;
}

int PrintPosL_Sq(SqList L, Elemtype e)
{//����ض�Ԫ�ص�λ��
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
		{
			printf("\nԪ��%c��λ�ã�%d", e, i + 1);
			return OK;
		}
	}
	return ERROR;
}

int ListInser_Sq(SqList& L, int x, Elemtype e)
{//�ڵ�x��λ���ϲ�����Ԫ��e
	if (x<1 || x>L.length+1)
	{
		return ERROR;
	}
	Elemtype* newbase;
	if (L.length >= L.listsize) {
		newbase = (Elemtype*)realloc(L.elem, (LIST_INIT_SIZE + LISTINCREMENT) * sizeof(Elemtype));
		if (!newbase) {
			exit(OVERFLOW);
		}
		L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	for (int i = L.length; i >= x; i--)
	{
		L.elem[i] = L.elem[i - 1];
	}
	L.elem[x - 1] = e;
	L.length++;
	return OK;
}

int ListDelete_Sq(SqList& L, int x, Elemtype e)
{//ɾ����xλ�õ�Ԫ�أ�����e������ֵ
	if (x < 1 || x>L.length)
	{
		return ERROR;
	}
	e = L.elem[x - 1];
	for (int i = x - 1; i < L.length-1; i++)
	{
		L.elem[i] = L.elem[i + 1];
	}
	L.length--;
	return OK;
}

int DestroyList_Sq(SqList& L)
{//�ݻپ�̬��
	if (!L.elem) {
		return ERROR;
	}
	free(L.elem);
	L.length = 0;
	L.listsize = 0;
	return OK;
}

void InsertSort(SqList& L)
{//ֱ�Ӳ������򣬾�̬�����һλ��Ϊ�ڱ�
	int i, j;
	for ( i = L.length-2; i >= 0; --i)
	{
		if (LT(L.elem[i + 1], L.elem[i])) {
			L.elem[L.length] = L.elem[i];
		}
		for ( j = i + 1; LT(L.elem[j], L.elem[L.length]); j++)
		{
			L.elem[j - 1] = L.elem[j];
		}
		L.elem[j - 1] = L.elem[L.length];
	}
}