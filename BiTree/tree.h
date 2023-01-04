#ifndef TREE_H_
#define TREE_H_
#include <stdio.h>
#include "bitree.h"

#define MAX_TREE_SIZE 100
typedef struct PTnode
{
	Telemtype data;
	int parent;
}PTnode;

typedef struct PTree
{
	PTnode nodes[MAX_TREE_SIZE];
	int r, n;//指示根的位置和个数
}PTree;
//树的双亲表示法

typedef struct CTnode
{
	int child;
	struct CTnode* next;
}*ChildPtr;
typedef struct
{
	Telemtype data;
	ChildPtr firstchild;
}CTbox;//孩子链表的头指针
typedef struct
{
	CTbox nodes[MAX_TREE_SIZE];
	int n, r;//节点数和根的位置
};
//树的孩子表示法
typedef struct CSnode
{
	PTree data;
	struct CSnode* firstchild, *nextsibling;
}CSnode,*CSTree;
//树的二叉链表法

#endif // !TREE_H

