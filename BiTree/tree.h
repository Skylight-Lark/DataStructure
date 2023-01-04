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
	int r, n;//ָʾ����λ�ú͸���
}PTree;
//����˫�ױ�ʾ��

typedef struct CTnode
{
	int child;
	struct CTnode* next;
}*ChildPtr;
typedef struct
{
	Telemtype data;
	ChildPtr firstchild;
}CTbox;//���������ͷָ��
typedef struct
{
	CTbox nodes[MAX_TREE_SIZE];
	int n, r;//�ڵ����͸���λ��
};
//���ĺ��ӱ�ʾ��
typedef struct CSnode
{
	PTree data;
	struct CSnode* firstchild, *nextsibling;
}CSnode,*CSTree;
//���Ķ�������

#endif // !TREE_H

