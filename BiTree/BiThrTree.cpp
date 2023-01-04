#define _CRT_SECURE_NO_WARNINGS
#include "bitree.h"

int CreateBiThrTree(BiThrTree& T)
{//按照先序遍历创建二叉树
	Telemtype	e;
	scanf("%d", &e);
	if (e == -1)
	{
		T = NULL;
	}
	else
	{
		T = (BiThrTree)malloc(sizeof(BiThrnode));
		if (!T) {
			exit(OVERFLOW);
		}
		T->data = e;
		T->Ltag = Link;
		T->Rtag = Link;
		CreateBiThrTree(T->lchild);
		CreateBiThrTree(T->rchild);
	}
	return OK;
}

int DestroyThrTree(BiThrTree& T)
{//摧毁整个线索树
	if (T != NULL) {
		DestroyThrTree(T->lchild);
		DestroyThrTree(T->rchild);
		free(T);
		T->lchild = NULL;
		T->rchild = NULL;
		T->Ltag = Link;
		T->Rtag = Link;
		T = NULL;
	}
	return OK;
}

int InOrderTraverse_Thr(BiThrTree T, int (*visit)(Telemtype))
{//中序遍历二叉线索树非递归算法，，T指向头节点
	BiThrTree p=T->lchild;//p指向根节点
	while (p!=T)
	{
		while (p->Ltag == Link ) {
			p = p->lchild;
		}
		if (!visit(p->data)) {
			return ERROR;
		}
		while (p->Rtag == Thread && p->rchild != T) {
			p = p->rchild;
			visit(p->data);
		}
		p = p->rchild;
	}
}

int InThreading(BiThrTree p, BiThrTree& pre)
{//
	if (p) {
		InThreading(p->lchild,pre);//左树线索化
		if (!p->lchild) {
			p->Ltag = Thread;
			p->lchild = pre;
		}//前驱线索
		if (!pre->rchild) {
			pre->Rtag = Thread;
			pre->rchild = p;
		}//后继线索
		pre = p;
		InThreading(p->rchild,pre);//右树线索化
	}
	return OK;
}

int InoOrderThreading(BiThrTree& Thrt, BiThrTree T)
{//中序遍历二叉树T，并将其中序线索化，Thrt指向其头节点
	BiThrTree pre;
	if (!(Thrt = (BiThrTree)malloc(sizeof(BiThrnode)))) {
		exit(OVERFLOW);
	}
	Thrt->Ltag = Link;
	Thrt->Rtag = Thread;
	Thrt->rchild = Thrt;
	
	if (!T) {
		Thrt->lchild = Thrt;
	}
	else {
		Thrt->lchild = T;
		pre = Thrt;
		InThreading(T, pre);
		pre->rchild = Thrt;
		pre->Rtag = Thread;
		Thrt->rchild = pre;
	}
	return OK;
}