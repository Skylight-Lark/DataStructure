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
{//初始化链表
	L = (LinkList)malloc(sizeof(LNode));
	if (!L) exit(OVERFLOW);
	L->next = NULL;
	L->data = '\0';
}

int ListLength_Link(LinkList plist)
{//求单链表的长度
	LNode* p = NULL;
	int i = 0;
	p = plist->next;
	while (p) {
		p = p->next;
		i++;
	}
	printf("\n单链表的长度：%d", i);
	return i;
}
int InserTail_Link(LinkList& L, Elemtype e)
{//尾插法
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
{//输出第x个元素
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
	printf("\n单链表中第%d元素：%c", x, p->data);
	return OK;
}

int PrintPosL_Link(LinkList L, Elemtype e)
{//输出元素e的位置
	LinkList p = L->next;
	int i = 1;
	while (p) {
		if (p->data == e) {
			printf("\n元素%c的位置：%d", e, i);
			return i;
		}
		p = p->next;
		i++;
	}
	printf("\n不存在这样的元素");
	return ERROR;
}

int InserPos_Link(LinkList& L, int x, Elemtype e)
{//在第x个位置上插入元素e
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
{//删除第x个位置，并用e返回其值
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
{//删除整个链表
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
{//判断单链表是否为空，空输出TRUE，非空输出FALSE
	if (L->next == NULL)
	{
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int Print_Link(LinkList L)
{//输出单链表
	if (Empty_Link(L)) {
		printf("链表为空！\n");
		return ERROR;
	}
	LinkList p = L->next;
	printf("单链表为：\n");
	while (p)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int Reverse_Link(LinkList& L)
{//逆置单链表
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

/*---------------------单链表的查找静态查找和动态查找--------------------*/
int Search_Seq(LinkList& L, Elemtype key)
{//静态查找：在单链表中查找关键字等于key的元素，如果没有找到则返回0，否则返回该元素的位置
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
{//动态查找：在单链表中查找，在链表末尾插入不存在的记录，或从查找表中删除已存在的记录
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