#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"

int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
int final[MAX_VERTEX_NUM];
void ShortPath_DJS(MGraph& G, int v0, PathMatrix P, ShortPathTable D)
{//用Dijkstra算法求v0到其余各顶点v的最短路径P[v]及其带全长度D[v]
//若path[v][w]为True，则w是从v0到v当前球的最短路径上的顶点
//final[v]为True当且仅当v属于S，即求得从v0到v的最短路径
	int v, w;
	for (v = 0; v < G.vexnum; v++)
	{
		final[v] = 0;
		D[v] = G.arcs[v0][v];
		for (w = 0; w < G.vexnum; w++)
		{
			path[v][w] = 0;
		}
		if (D[v] < INFINITY) {
			path[v][v0] = 1;
			path[v][v] = 1;
		}
	}
	D[v0] = 0;
	final[v0] = 1;
	for (int i = 1; i < G.vexnum; i++)
	{
		int min = INFINITY;
		for (w = 0; w < G.vexnum; w++)
		{
			if (!final[w]) {
				if (D[w]<min) {
					v = w;
					min = D[w];
				}
			}
			final[v] = 1;
			for (w = 0; w < G.vexnum; w++)
			{
				if (!final[w] && (min + G.arcs[v][w] < D[w]))
				{
					D[w] = min + G.arcs[v][w];
					P[w] = P[v];
					path[w][w] = 1;
				}
			}
		}
	}
}

void ALGraphToMGraph(ALGraph& A, MGraph& M)
{
	int v, w;
	M.vexnum = A.vexnum;
	M.arcnum = A.arcnum;
	for (v = 0; v < A.vexnum; v++)
	{
		M.vexs[v] = A.adjlist[v].vex;
	}
	for (v = 0; v < A.vexnum; v++)
	{
		for (w = 0; w < A.vexnum; w++)
		{
			if (v == w) {
				M.arcs[v][w] = INFINITY;
				continue;
			}
			M.arcs[v][w] = FindArc(A, v, w);	
		}
	}	
}

int FindArc(ALGraph& G, int v, int w)
{//找到从v指向w的有向弧
	int index;
	Arcnode* temp = NULL;
	temp = G.adjlist[v].firstarc;
	while (temp)
	{
		LocateVex(G, temp->adjvex, &index);
		if (w ==index)
		{
			return temp->data;
		}
		temp = temp->nextarc;
	}
	return INFINITY;
}