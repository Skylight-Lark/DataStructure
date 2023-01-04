#define _CRT_SECURE_NO_WARNINGS
#include "link.h"

//int main()
//{
//	LinkList L;
//	Elemtype e = '\0';
//	InitLink(L);
//	InserTail_Link(L, 'a');
//	InserTail_Link(L, 'b');
//	InserTail_Link(L, 'c');
//	InserTail_Link(L, 'd');
//	InserTail_Link(L, 'e');
//	Print_Link(L);
//	ListLength_Link(L);
//	Empty_Link(L);
//	PrintPosE_Link(L, 3);
//	PrintPosL_Link(L, 'a');
//	InserPos_Link(L, 4,'f');
//	Print_Link(L);
//	DeletePos_Link(L, 3, e);
//	Print_Link(L);
//	Reverse_Link(L);
//	Print_Link(L);
//	Destroy_Link(L);
//	return OK;
//}

void InitLink(LinkList& L)
{//��ʼ������
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) exit(OVERFLOW);
	L->next = NULL;
	L->data = '\0';
}

int ListLength_Link(LinkList plist)
{//������ĳ���
	LNode* p = NULL;
	int i = 0;
	p = plist->next;
	while (p) {
		p = p->next;
		i++;
	}
	printf("\n������ĳ��ȣ�%d", i);
	return i;
}
int InserTail_Link(LinkList& L, Elemtype e)
{//β�巨
	LinkList p = L->next;
	LinkList q = L;
	LinkList tem = (LinkList)malloc(sizeof(LNode));
	tem->data = e;
	tem->next = NULL;
	while (p)
	{
		q = p;
		p = p->next;
	}
	q->next = tem;
	return OK;
}

int PrintPosE_Link(LinkList L, int x)
{//�����x��Ԫ��
	LinkList p = L->next;
	if (Empty_Link(L)) {
		return ERROR;
	}
	for (int i = 1; i < x; i++)
	{
		if (!p) {
			return ERROR;
		}
		p = p->next;
	}
	printf("\n�������е�%dԪ�أ�%c", x, p->data);
	return OK;
}

int PrintPosL_Link(LinkList L, Elemtype e)
{//���Ԫ��e��λ��
	LinkList p = L->next;
	int i = 1;
	while (p) {
		if (p->data == e) {
			printf("\nԪ��%c��λ�ã�%d", e, i);
			return i;
		}
		p = p->next;
		i++;
	}
	printf("\n������������Ԫ��");
	return ERROR;
}

int InserPos_Link(LinkList& L, int x, Elemtype e)
{//�ڵ�x��λ���ϲ���Ԫ��e
	LinkList p = L->next;
	LinkList q = L;
	if (Empty_Link(L)) {
		return ERROR;
	}
	for (int i = 1; i < x; i++) {
		if (!p) {
			return ERROR;
		}
		q = p;
		p = p->next;
	}
	LinkList tem = (LinkList)malloc(sizeof(LNode));
	tem->data = e;
	q->next = tem;
	tem->next = p;
	return OK;
}

int DeletePos_Link(LinkList& L, int x, Elemtype e)
{//ɾ����x��λ�ã�����e������ֵ
	LinkList p = L->next;
	LinkList q = L;
	if (Empty_Link(L)) {
		return ERROR;
	}
	for (int i = 1; i < x; i++)
	{
		if (!p) {
			return ERROR;
		}
		q = p;
		p = p->next;
	}
	q->next = p->next;
	free(p);
	p = NULL;
	return OK;
}

void Destroy_Link(LinkList L)
{//ɾ����������
	LinkList p = NULL;
	LinkList q = NULL;
	p = L->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	free(L);
	L = NULL;
	p = NULL;
	q = NULL;
}

int Empty_Link(LinkList L)
{//�жϵ������Ƿ�Ϊ�գ������TRUE���ǿ����FALSE
	if (L->next == NULL)
	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int Print_Link(LinkList L)
{//���������
	if (Empty_Link(L)) {
		printf("����Ϊ�գ�\n");
		return ERROR;
	}
	LinkList p = L->next;
	printf("������Ϊ��\n");
	while (p)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int Reverse_Link(LinkList& L)
{//���õ�����
	LinkList head=L->next;
	LinkList begin = head->next;
	LinkList tem = begin;
	if (Empty_Link(L))
	{
		return ERROR;
	}
	head->next = NULL;
	while (begin) {
		begin = begin->next;
		tem->next = L->next;
		L->next = tem;
		tem = begin;
	}
	return OK;
}

/*---------------------������Ĳ��Ҿ�̬���ҺͶ�̬����--------------------*/
int Search_Seq(LinkList& L, Elemtype key)
{//��̬���ң��ڵ������в��ҹؼ��ֵ���key��Ԫ�أ����û���ҵ��򷵻�0�����򷵻ظ�Ԫ�ص�λ��
	int i = 0;
	LinkList temp = NULL;
	temp = L->next;
	while (temp)
	{
		i++;
		if (temp->data == key)
		{
			return i;
		}
		else
		{
			temp = temp->next;
		}
	}
	return 0;
}

void Search_Dym(LinkList& L, Elemtype key)
{//��̬���ң��ڵ������в��ң�������ĩβ���벻���ڵļ�¼����Ӳ��ұ���ɾ���Ѵ��ڵļ�¼
	LinkList temp = NULL, front = NULL;
	temp = L->next;
	front = L;
	int flag = 0;
	while (temp)
	{
		if (temp->data == key)
		{
			front->next = temp->next;
			free(temp);
			temp = NULL;
			temp = front->next;
			flag = 1;
		}
		else {
			front = temp;
			temp = temp->next;
		}
	}
	if (flag == 0)
	{
		temp = (LinkList)malloc(sizeof(LNode));
		if (!temp)
		{
			printf("out of space!\n");
			exit(1);
		}
		temp->data = key;
		temp->next = NULL;
		front->next = temp;
	}
}