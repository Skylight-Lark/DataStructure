#ifndef LINK_H_
#define LINK_H_

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define INFEASIBLE	-1
#define OVERFLOW	-2

#define LIST_INIT_SIZE 100
#define LISTINCREMENT	10

#define LT(a,b) ((a)<(b))

typedef char Elemtype;

typedef struct {
	Elemtype* elem;
	int length;
	int listsize;
}SqList;

typedef int KeyType;
typedef char InfoType;
typedef RedType Elemtype;
typedef struct {
	KeyType key;
	InfoType otherinfo;
}RedType;

typedef struct LNode {
	Elemtype data;
	struct LNode* next;
}LNode, * LinkList;

int InitList_Sq(SqList& L);
int InserTail_Sq(SqList& L, Elemtype e);
int PrintList_Sq(SqList L);
int Lengh_Sq(SqList L);
int EmptyList_Sq(SqList L);
int PrintPosE_Sq(SqList L, int i);
int PrintPosL_Sq(SqList L, Elemtype e);
int ListInser_Sq(SqList& L, int x, Elemtype e);
int ListDelete_Sq(SqList& L, int x, Elemtype e);
int DestroyList_Sq(SqList& L);
int Create_String(SqList& L);
int IsPalindrome(SqList L);

void InitLink(LinkList& L);
void Destroy_Link(LinkList L);
int Empty_Link(LinkList L);
int Print_Link(LinkList L);
int ListLength_Link(LinkList plist);
int InserTail_Link(LinkList& L, Elemtype e);
int PrintPosE_Link(LinkList L, int x);
int PrintPosL_Link(LinkList L, Elemtype e);
int InserPos_Link(LinkList& L, int x, Elemtype e);
int DeletePos_Link(LinkList& L, int x, Elemtype e);
int Reverse_Link(LinkList& L);
int Search_Seq(LinkList& L, Elemtype key);
void Search_Dym(LinkList& L, Elemtype key);
void InsertSort(SqList& L);
#endif // !LINK_H_

