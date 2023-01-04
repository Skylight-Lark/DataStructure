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
//***********ͼ������(�ڽӾ���)�洢��ʾ**********
typedef int ArcType;
typedef struct {
	Vertextype vexs[MAX_VERTEX_NUM];
	ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//-1����������ڽӾ���
	int vexnum, arcnum;
	//GraphKind kind;
}MGraph;

void MiniSpanTree_Prim(MGraph& G, int u);
void Visit(const MGraph& G, int u, int v);

//***********ͼ���ڽӱ��ʾ����*************
typedef struct Arcnode
{
	int adjvex;//�û�ָ��Ķ���(����ͼ�ǻ�ͷ������ͼ�������ڽӵĶ���)
	struct Arcnode* nextarc;//ָ����һ������ָ��
	Infotype data;
}Arcnode;

typedef struct VNode {
	Vertextype vex;//����洢��
	Arcnode* firstarc;//ָ���һ�������ڸö���Ļ�ָ�룬���������ڸö���Ļ�����
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct {
	AdjList adjlist;
	int vexnum, arcnum;
	//int kind;
}ALGraph;//��Ȩͼ���ڽӱ�

//***********����ͼ��ʮ�������ʾ����**********
typedef struct Arcbox {
	int tailvex, headvex;
	struct Arcbox* hlink, * tlink;//�ֱ�Ϊ��ͷ��ͬ�ͻ�β��ͬ������
	Infotype* info;
}Arcbox;
typedef struct Vexnode {
	Vertextype data;
	Arcbox* firstin, * firstout;//�ֱ�ָ��ö���ĵ�һ���뻡�ͳ���
}Vexbox;
typedef struct {
	Vexnode xlist[MAX_VERTEX_NUM];
	int vexnum, arcnum;
}Olgraph;

void CreateALG(ALGraph& G);//���ڽӱ���ͼ
void PrintALG(ALGraph G);//����ڽӱ�
void DFSTraverseALG(ALGraph& G);//������ȱ����ڽӱ�洢��ͼALG
void DFSALG(ALGraph G,int i);//��vi������ͼ������ȱ���
void LocateVex(ALGraph G, Vertextype vertex, int* index);//��λ���vertex�������±긳��index

void BFSTraverseALG(ALGraph& G);

void TopologicakSort_DFS(ALGraph& G);//������ȱ�������������
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

