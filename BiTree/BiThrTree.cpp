#define _CRT_SECURE_NO_WARNINGS
#include "bitree.h"

int CreateBiThrTree(BiThrTree& T)
{//���������������������
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
{//�ݻ�����������
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
{//������������������ǵݹ��㷨����Tָ��ͷ�ڵ�
	BiThrTree p=T->lchild;//pָ����ڵ�
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
		InThreading(p->lchild,pre);//����������
		if (!p->lchild) {
			p->Ltag = Thread;
			p->lchild = pre;
		}//ǰ������
		if (!pre->rchild) {
			pre->Rtag = Thread;
			pre->rchild = p;
		}//�������
		pre = p;
		InThreading(p->rchild,pre);//����������
	}
	return OK;
}

int InoOrderThreading(BiThrTree& Thrt, BiThrTree T)
{//�������������T��������������������Thrtָ����ͷ�ڵ�
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