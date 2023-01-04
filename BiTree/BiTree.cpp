#define _CRT_SECURE_NO_WARNINGS
#include "bitree.h"


int main()
{
	BiTree T=NULL;
	CreateBiTree(T);
	printf("层次遍历完全二叉树：");
	LevelOrderTraverse(T, &PrintTnode);
	printf("\n");
	GetPosDepth(T, 'a');
	/*printf("层次遍历完全二叉树：");
	LevelOrderTraverse(T, &PrintTnode);*/
	//printf("\n");
	/*printf("交换孩子前递归先序遍历树：");
	PreOrderTraverse(T, &PrintTnode);
	printf("\n");
	SwapChild(T);*/
	/*printf("交换孩子层次遍历树：");
	LevelOrderTraverse(T, &PrintTnode);
	printf("\n");*/
	/*printf("交换孩子后递归先序遍历树：");
	PreOrderTraverse(T, &PrintTnode);
	printf("\n");*/
	//printf("递归中序遍历树：");
	//InOrderTraverse(T, &PrintTnode);
	//printf("\n");
	///*InOrderTraverse_1(T, &PrintTnode);
	//printf("\n");*/
	//printf("递归后序遍历树：");
	//PostOrderTraverse(T, &PrintTnode);
	//printf("\n");
	///*PostOrderTraverse_1(T, &PrintTnode);
	//printf("\n");*/
	//printf("树的结点个数：%d\n", CountNodeNum(T));
	//printf("树的叶子结点个数：%d\n", CountLeafNum(T));
	DestroyTree(T);
	return 0;
}

int InitBiTree(BiTree & T)
{//初始化二叉树
	T = (BiTree)malloc(sizeof(BiTnode));
	if (!T) {
		exit(INFEASIBLE);
	}
	return OK;
}

int CreateBiTree(BiTree& T)
{//按照先序遍历创建二叉树
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
{//摧毁整个树
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
{//检验二叉树是否为空
	if (T == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

//int PrintTelemtype(Telemtype e)
//{//访问树节点的函数
//	printf("%d\n", e);
//	return OK;
//}


int SwapChild(BiTree T)
{//交换孩子递归算法
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
{//层次遍历读结点个数
	BiTree Queue[MAX_NODE], p = T;
	int  front = 0, rear = 0;
	int num = 0;
	if (p != NULL)
	{
		Queue[++rear] = p;    /*   根结点入队  */
		while (front < rear)
		{
			p = Queue[++front];  
			num++;
			if (p->lchild != NULL)
				Queue[++rear] = p->lchild;    /*   左结点入队  */
			if (p->rchild != NULL)
				Queue[++rear] = p->rchild;    /*   右结点入队  */
		}
	}
	return num;
}

int CountLeafNum(BiTree T)
{//层次遍历计算叶子节点个数
	BiTree Queue[MAX_NODE], p = T;
	int  front = 0, rear = 0;
	int num = 0;
	if (p != NULL)
	{
		Queue[++rear] = p;    /*   根结点入队  */
		while (front < rear)
		{
			p = Queue[++front];
			if (p->lchild != NULL)
				Queue[++rear] = p->lchild;    /*   左结点入队  */
			if (p->rchild != NULL)
				Queue[++rear] = p->rchild;    /*   右结点入队  */
			if (p->lchild == NULL && p->rchild == NULL)
				num++;							//判断叶子节点并计数
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
//{//输入int型序列，以-1为结束标志，创建完全二叉树
//	Telemtype e;
//	BiTree  T;//T用来接收出队结点
//	BiTree q[MAX_NODE];//创建空队列
//	int  front = 0, rear = 0;
//
//	printf("\n请输入int型序列并以回车键为结束标志：");
//	scanf("%c", &e);
//
//	if (e != '\0') {
//		//分配根结点单元，并将结点地址入队
//		BT = (BiTree)malloc(sizeof(BiTnode));
//		BT->data = e;
//		BT->lchild = BT->rchild = NULL;
//		q[rear++] = BT;
//	}
//	else
//		return NULL;//若第一个数据非法，就返回空树
//
//	while (front<=rear) {//队列不空时，循坏
//		T = q[front];//从队列中取出一结点地址
//		front++;
//		scanf("%c", &e);//读取T的左孩子
//		if (e != '\0' && e == '\n') {
//			T->lchild = (BiTree)malloc(sizeof(BiTnode));
//			T->lchild->data = e;
//			T->lchild->lchild = T->lchild->rchild = NULL;
//			q[rear++] = T->lchild;
//		}
//		else if (e == '\n') {
//			break;
//		}
//		else if (e == '\0') {//分配新结点，出队结点的左孩子；新结点入队
//			T->lchild = NULL;//构造完全二叉树需break；
//		}
//
//		scanf("%c", &e);//读取T的右孩子
//		if (e != '\0'&&e == '\n') {
//			T->rchild = (BiTree)malloc(sizeof(BiTnode));
//			T->rchild->data = e;
//			T->rchild->lchild = T->rchild->rchild = NULL;
//			q[rear++] = T->rchild;
//		}
//		else if (e == '\n') {
//			break;
//		}
//		else if(e=='\0') {//分配新结点，出队结点的右孩子；新结点入队
//			T->rchild = NULL;//构造完全二叉树需break；
//		}
//	}
//	return OK;//返回头结点地址
//}

int GetTreeDepth(BiTree& T)
{//求树的深度
	if (T == NULL)
		return 0;
	int left = GetTreeDepth(T->lchild);
	int right = GetTreeDepth(T->rchild);

	return (left > right ? left : right) + 1;
}



int GetPosDepth(BiTree& T, Telemtype e)
{//以元素值为e的结点为根的子树的深度,通过先序遍历
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
		Queue[++rear] = p;    /*   根结点入队  */
		while (front < rear)
		{
			p = Queue[++front];  visit(p->data);
			if (p->lchild != NULL)
				Queue[++rear] = p->lchild;    /*   左结点入队  */
			if (p->rchild != NULL)
				Queue[++rear] = p->rchild;    /*   右结点入队  */
		}
	}
}

int PreOrderTraverse(BiTree T, int (*visit)(Telemtype e))
{//先序遍历二叉树，递归算法
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
{//中序遍历二叉树，递归算法
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
{//后序遍历二叉树，递归算法
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
{//先序遍历非递归算法
	SqStack S;
	BiTree p=T,q;
	InitStack(S);
	printf("非递归先序遍历树：");
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
{//中序遍历算法，非递归算法一
	SqStack S;
	BiTree p;
	InitStack(S);
	Push(S, T);
	printf("非递归中序遍历树：");
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
{//后序遍历非递归算法
	SqStack S;
	BiTree p = T,q;
	int Tag[MAX_NODE], top = 0, b = 1;
	InitStack(S);
	printf("非递归后序遍历树：");
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
{//中序遍历算法，非递归算法二
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
