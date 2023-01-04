#ifndef _BITREE_H
#define _BITREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_SIZE 100
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define INFEASIBLE	-1
#define OVERFLOW	-2

#define MAX_NODE	100
#define STACK_INIT_SIZE 100
#define STACKINCREMENT	10

typedef char Telemtype;

typedef Telemtype SqBiTree[MAX_TREE_SIZE];//适用于完全二叉树，0号元素存储根节点

typedef struct BiTnode {
	Telemtype data;
	struct BiTnode * lchild, * rchild;
}BiTnode,*BiTree;//二叉链表

typedef enum PointerTag{Link,Thread};

typedef struct BiThrnode {
	Telemtype data;
	struct BiThrnode* lchild, * rchild;
	PointerTag Ltag, Rtag;
}BiThrnode,*BiThrTree;

typedef BiTree Elemtype;

typedef struct {
	Elemtype* base;
	Elemtype* top;
	int stacksize;
}SqStack;

int InitBiTree(BiTree& T);
int CreateBiTree(BiTree& T);
int DestroyTree(BiTree& T);
int BiTreeEmpty(BiTree& T);
int PrintTelemtype(Telemtype e);
int PreOrderTraverse(BiTree T, int (*visit)(Telemtype e));
int PreOrderTraverse_1(BiTree T, int (*visit)(Telemtype e));
int InOrderTraverse(BiTree T, int (*visit)(Telemtype e));
int InOrderTraverse_1(BiTree T, int (*visit)(Telemtype e));
int InOrderTraverse_2(BiTree S, int (*visit)(Telemtype));
int PostOrderTraverse(BiTree T, int (*visit)(Telemtype e));
int PostOrderTraverse_1(BiTree T, int (*visit)(Telemtype e));
int CountNodeNum(BiTree T);
int CountLeafNum(BiTree T);
int GetTreeDepth(BiTree& T);
int GetPosDepth(BiTree& T, Telemtype e);

int  CreateCTree(BiTree& BT);
int PrintTnode(Telemtype e);
int SwapChild(BiTree T);
void  LevelOrderTraverse(BiTree T, int (*visit)(Telemtype e));

int CreateBiThrTree(BiThrTree& T);
int DestroyThrTree(BiThrTree& T);
int InOrderTraverse_Thr(BiThrTree T, int (*visit)(Telemtype));
int InThreading(BiThrTree p, BiThrTree& pre);
int InoOrderThreading(BiThrTree& Thrt, BiThrTree T);

int InitStack(SqStack& S);
int DestroyStack(SqStack& S);
int GetTop(SqStack S, Elemtype& e);
int Push(SqStack& S, Elemtype e);
int Pop(SqStack& S, Elemtype& e);
int StackEmpty(SqStack S);

#endif 

