#define _CRT_SECURE_NO_WARNINGS
#include "bitree.h"


int main()
{
	BiTree T=NULL;
	CreateBiTree(T);
	printf("��α�����ȫ��������");
	LevelOrderTraverse(T, &PrintTnode);
	printf("\n");
	GetPosDepth(T, 'a');
	/*printf("��α�����ȫ��������");
	LevelOrderTraverse(T, &PrintTnode);*/
	//printf("\n");
	/*printf("��������ǰ�ݹ������������");
	PreOrderTraverse(T, &PrintTnode);
	printf("\n");
	SwapChild(T);*/
	/*printf("�������Ӳ�α�������");
	LevelOrderTraverse(T, &PrintTnode);
	printf("\n");*/
	/*printf("�������Ӻ�ݹ������������");
	PreOrderTraverse(T, &PrintTnode);
	printf("\n");*/
	//printf("�ݹ������������");
	//InOrderTraverse(T, &PrintTnode);
	//printf("\n");
	///*InOrderTraverse_1(T, &PrintTnode);
	//printf("\n");*/
	//printf("�ݹ�����������");
	//PostOrderTraverse(T, &PrintTnode);
	//printf("\n");
	///*PostOrderTraverse_1(T, &PrintTnode);
	//printf("\n");*/
	//printf("���Ľ�������%d\n", CountNodeNum(T));
	//printf("����Ҷ�ӽ�������%d\n", CountLeafNum(T));
	DestroyTree(T);
	return 0;
}

int InitBiTree(BiTree & T)
{//��ʼ��������
	T = (BiTree)malloc(sizeof(BiTnode));
	if (!T) {
		exit(INFEASIBLE);
	}
	return OK;
}

int CreateBiTree(BiTree& T)
{//���������������������
	Telemtype	e;
	scanf("%c", &e);
	if (e == '?')
	{
		T = NULL;
		return OK;
	}
	else
	{
		T = (BiTree)malloc(sizeof(BiTnode));
		if (!T) {
			exit(INFEASIBLE);
		}
		T->data = e;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
		return OK;
	}
	
}

int DestroyTree(BiTree& T)
{//�ݻ�������
	if (T != NULL) {
		DestroyTree(T->lchild);
		DestroyTree(T->rchild);
		free(T);
		T->lchild = NULL;
		T->rchild = NULL;
		T = NULL;
	}
	return OK;
}

int BiTreeEmpty(BiTree& T)
{//����������Ƿ�Ϊ��
	if (T == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//int PrintTelemtype(Telemtype e)
//{//�������ڵ�ĺ���
//	printf("%d\n", e);
//	return OK;
//}


int SwapChild(BiTree T)
{//�������ӵݹ��㷨
	BiTree tem = NULL;
	if (T != NULL) {
		SwapChild(T->lchild);
		SwapChild(T->rchild);
		tem = T->lchild;
		T->lchild = T->rchild;
		T->rchild = tem;
	}
	tem = NULL;
	return OK;
}

int CountNodeNum(BiTree T)
{//��α�����������
	BiTree Queue[MAX_NODE], p = T;
	int  front = 0, rear = 0;
	int num = 0;
	if (p != NULL)
	{
		Queue[++rear] = p;    /*   ��������  */
		while (front < rear)
		{
			p = Queue[++front];  
			num++;
			if (p->lchild != NULL)
				Queue[++rear] = p->lchild;    /*   �������  */
			if (p->rchild != NULL)
				Queue[++rear] = p->rchild;    /*   �ҽ�����  */
		}
	}
	return num;
}

int CountLeafNum(BiTree T)
{//��α�������Ҷ�ӽڵ����
	BiTree Queue[MAX_NODE], p = T;
	int  front = 0, rear = 0;
	int num = 0;
	if (p != NULL)
	{
		Queue[++rear] = p;    /*   ��������  */
		while (front < rear)
		{
			p = Queue[++front];
			if (p->lchild != NULL)
				Queue[++rear] = p->lchild;    /*   �������  */
			if (p->rchild != NULL)
				Queue[++rear] = p->rchild;    /*   �ҽ�����  */
			if (p->lchild == NULL && p->rchild == NULL)
				num++;							//�ж�Ҷ�ӽڵ㲢����
		}
	}
	return num;
}


//void  LevelorderTraverse(BiTree T, int (*visit)(Telemtype e))
//{
//	BiTree Queue[MAX_NODE],  p = T;
//	int  front = 0, rear = 0;
//	if (p != NULL)
//	{
//		Queue[++rear] = p;   
//		while (front < rear)
//		{
//			p = Queue[++front];  visit(p->data);
//			if (p->lchild != NULL)
//				Queue[++rear] = p;    
//			if (p->rchild != NULL)
//				Queue[++rear] = p;  
//		}
//	}
//}




//int  CreateCTree(BiTree& BT) 
//{//����int�����У���-1Ϊ������־��������ȫ������
//	Telemtype e;
//	BiTree  T;//T�������ճ��ӽ��
//	BiTree q[MAX_NODE];//�����ն���
//	int  front = 0, rear = 0;
//
//	printf("\n������int�����в��Իس���Ϊ������־��");
//	scanf("%c", &e);
//
//	if (e != '\0') {
//		//�������㵥Ԫ����������ַ���
//		BT = (BiTree)malloc(sizeof(BiTnode));
//		BT->data = e;
//		BT->lchild = BT->rchild = NULL;
//		q[rear++] = BT;
//	}
//	else
//		return NULL;//����һ�����ݷǷ����ͷ��ؿ���
//
//	while (front<=rear) {//���в���ʱ��ѭ��
//		T = q[front];//�Ӷ�����ȡ��һ����ַ
//		front++;
//		scanf("%c", &e);//��ȡT������
//		if (e != '\0' && e == '\n') {
//			T->lchild = (BiTree)malloc(sizeof(BiTnode));
//			T->lchild->data = e;
//			T->lchild->lchild = T->lchild->rchild = NULL;
//			q[rear++] = T->lchild;
//		}
//		else if (e == '\n') {
//			break;
//		}
//		else if (e == '\0') {//�����½�㣬���ӽ������ӣ��½�����
//			T->lchild = NULL;//������ȫ��������break��
//		}
//
//		scanf("%c", &e);//��ȡT���Һ���
//		if (e != '\0'&&e == '\n') {
//			T->rchild = (BiTree)malloc(sizeof(BiTnode));
//			T->rchild->data = e;
//			T->rchild->lchild = T->rchild->rchild = NULL;
//			q[rear++] = T->rchild;
//		}
//		else if (e == '\n') {
//			break;
//		}
//		else if(e=='\0') {//�����½�㣬���ӽ����Һ��ӣ��½�����
//			T->rchild = NULL;//������ȫ��������break��
//		}
//	}
//	return OK;//����ͷ����ַ
//}

int GetTreeDepth(BiTree& T)
{//���������
	if (T == NULL)
		return 0;
	int left = GetTreeDepth(T->lchild);
	int right = GetTreeDepth(T->rchild);

	return (left > right ? left : right) + 1;
}



int GetPosDepth(BiTree& T, Telemtype e)
{//��Ԫ��ֵΪe�Ľ��Ϊ�������������,ͨ���������
	SqStack S;
	BiTree p = T, q;
	int num;
	InitStack(S);
	if (T == NULL) {
		return ERROR;
	}
	else {
		while (p != NULL) {
			if (p->data == e) {
				num = GetTreeDepth(p);
				printf("%d\t",num);
			}
			q = p->rchild;
			if (q != NULL) {
				Push(S, q);
			}
			p = p->lchild;
			if (p == NULL) {
				Pop(S, p);
			}
		}
	}
	DestroyStack(S);
	return OK;
}

void  LevelOrderTraverse(BiTree T, int (*visit)(Telemtype e))
{
	BiTree Queue[MAX_NODE],  p = T;
	int  front = 0, rear = 0;
	if (p != NULL)
	{
		Queue[++rear] = p;    /*   ��������  */
		while (front < rear)
		{
			p = Queue[++front];  visit(p->data);
			if (p->lchild != NULL)
				Queue[++rear] = p->lchild;    /*   �������  */
			if (p->rchild != NULL)
				Queue[++rear] = p->rchild;    /*   �ҽ�����  */
		}
	}
}

int PreOrderTraverse(BiTree T, int (*visit)(Telemtype e))
{//����������������ݹ��㷨
	if (T != NULL) {
		if (visit(T->data)) {
			if (PreOrderTraverse(T->lchild, visit)) {
				if (PreOrderTraverse(T->rchild, visit)) {
					return OK;
				}
			}
		}
		return ERROR;
	}
	else {
		return OK;
	}
}

int InOrderTraverse(BiTree T, int (*visit)(Telemtype e))
{//����������������ݹ��㷨
	if (T != NULL) {
		if (InOrderTraverse(T->lchild, visit)) {
			if (visit(T->data)) {
				if (InOrderTraverse(T->rchild, visit)) {
						return OK;
				}
			}
				
		}
	}
	else {
		return OK;
	}
}

int PostOrderTraverse(BiTree T, int (*visit)(Telemtype e))
{//����������������ݹ��㷨
	if (T != NULL) {
		if (PostOrderTraverse(T->lchild, visit)) {
			if (PostOrderTraverse(T->rchild, visit)) {
				if(visit(T->data)){
					return OK;
				}
			}	
		}	
	}
	else {
		return OK;
	}
}

int PreOrderTraverse_1(BiTree T, int (*visit)(Telemtype e))
{//��������ǵݹ��㷨
	SqStack S;
	BiTree p=T,q;
	InitStack(S);
	printf("�ǵݹ������������");
	if (T == NULL) {
		return ERROR;
	}
	else {
		while (p != NULL) {
			visit(p->data);
			q = p->rchild;
			if (q != NULL) {
				Push(S, q);
			}
			p = p->lchild;
			if (p == NULL) {
				Pop(S, p);
			}
		}
	}
	DestroyStack(S);
	return OK;
}


int InOrderTraverse_1(BiTree T, int (*visit)(Telemtype e))
{//��������㷨���ǵݹ��㷨һ
	SqStack S;
	BiTree p;
	InitStack(S);
	Push(S, T);
	printf("�ǵݹ������������");
	while (!StackEmpty(S)) {
		while (GetTop(S, p) && p) {
			Push(S, p->lchild);
		}
		Pop(S, p);
		if (!StackEmpty(S)) {
			Pop(S, p);
			if (!visit(p->data)) {
				return ERROR;
			}
			Push(S, p->rchild);
		}
	}
	DestroyStack(S);
	return OK;
}

int PostOrderTraverse_1(BiTree T, int (*visit)(Telemtype e))
{//��������ǵݹ��㷨
	SqStack S;
	BiTree p = T,q;
	int Tag[MAX_NODE], top = 0, b = 1;
	InitStack(S);
	printf("�ǵݹ�����������");
	if (T == NULL) {
		return ERROR;
	}
	else {
		while (b) {
			while (p != NULL) {
				Push(S, p);
				top++;
				Tag[top] = 0;
				p=p->lchild;
			}
			if (top == 0) {
				b = 0;
			}
			else if (Tag[top] == 0) {
				GetTop(S, q);
				p = q->rchild;
				Tag[top] = 1;
			}
			else {
				Pop(S, p);
				top--;
				visit(p->data);
				p = NULL;
			}
		}
	}
	DestroyStack(S);
	q = NULL;
	return OK;
}
int InOrderTraverse_2(BiTree T, int (*visit)(Telemtype))
{//��������㷨���ǵݹ��㷨��
	SqStack S;
	InitStack(S);
	BiTree p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, p);
			if (!visit(p->data)) {
				return ERROR;
			}
			p = p->rchild;
		}
	}
	DestroyStack(S);
	return OK;
}

int PrintTnode(Telemtype e)
{
	printf("%c\t", e);
	return OK;
}
