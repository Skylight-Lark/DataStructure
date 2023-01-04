#ifndef GRAPH_H_
#define GRAPG_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define INFEASIBLE	-1
#define OVERFLOW	-2
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 100
#define CQ_INIT_SIZE 100
typedef int Qdata;
typedef int Infotype;
typedef char Vertextype;
typedef int PathMatrix[];
typedef int ShortPathTable[];
typedef enum { DG, DN, UDG, UDN }GraphKind;

typedef struct {
	Qdata* data;
	int front;
	int tail;
	int QCapacity;
}Queue;
void initQueue(Queue& Q);
int Qpush(Queue& Q, Qdata& e);
int Qpop(Queue& Q, Qdata& e);
int isEmpty(Queue& Q);
int isFull(Queue& Q);
//***********图的数组(邻接矩阵)存储表示**********
typedef int ArcType;
typedef struct {
	Vertextype vexs[MAX_VERTEX_NUM];
	ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//-1代表无穷大，邻接矩阵
	int vexnum, arcnum;
	//GraphKind kind;
}MGraph;

void MiniSpanTree_Prim(MGraph& G, int u);
void Visit(const MGraph& G, int u, int v);

//***********图的邻接表表示方法*************
typedef struct Arcnode
{
	int adjvex;//该弧指向的顶点(有向图是弧头，无向图是与其邻接的顶点)
	struct Arcnode* nextarc;//指向下一条弧的指针
	Infotype data;
}Arcnode;

typedef struct VNode {
	Vertextype vex;//顶点存储名
	Arcnode* firstarc;//指向第一条依附于该顶点的弧指针，构成依附于该顶点的弧链表
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList adjlist;
	int vexnum, arcnum;
	//int kind;
}ALGraph;//无权图的邻接表

//***********有向图的十字链表表示方法**********
typedef struct Arcbox {
	int tailvex, headvex;
	struct Arcbox* hlink, * tlink;//分别为弧头相同和弧尾相同的链域
	Infotype* info;
}Arcbox;
typedef struct Vexnode {
	Vertextype data;
	Arcbox* firstin, * firstout;//分别指向该顶点的第一条入弧和出弧
}Vexbox;
typedef struct {
	Vexnode xlist[MAX_VERTEX_NUM];
	int vexnum, arcnum;
}Olgraph;

void CreateALG(ALGraph& G);//用邻接表创建图
void PrintALG(ALGraph G);//输出邻接表
void DFSTraverseALG(ALGraph& G);//深度优先遍历邻接表存储的图ALG
void DFSALG(ALGraph G,int i);//从vi出发对图进行深度遍历
void LocateVex(ALGraph G, Vertextype vertex, int* index);//定位结点vertex，并将下标赋给index

void BFSTraverseALG(ALGraph& G);

void TopologicakSort_DFS(ALGraph& G);//深度优先遍历的拓扑排序
void DFSALG_TS(ALGraph G, int i);
void FindPaths(ALGraph& G, int u, int v, int path[], int d);
void DispPaths(ALGraph& G, int u, int v);
int FindArc(ALGraph& G, int v, int w);
void ALGraphToMGraph(ALGraph& A, MGraph& M);
void ShortPath_DJS(MGraph& G, int v0, PathMatrix P, ShortPathTable D);
int PathDFS1(ALGraph& G, int start, int end);
int FindPathDFS(ALGraph& G, int start, int end);
int PathDFS2(ALGraph& G, int start, int end, int l, int k);
int FindKPathDFS(ALGraph& G, int start, int end, int k);
void PrintMG(MGraph G);
#endif // !GRAPH_H_

