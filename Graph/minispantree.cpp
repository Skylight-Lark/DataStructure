#define _CRT_SECURE_NO_WARNINGS

#include "graph.h"

//void MiniSpanTree_Prim(MGraph G, int u)
//{
//	struct {
//		int adjvex;
//		int lowcost;
//	}closearc[MAX_VERTEX_NUM];
//	for (int i = 0; i < G.vexnum; i++)
//	{
//		closearc[i].adjvex = u;
//		closearc[i].lowcost = G.arcs[u][i];
//	}
//	closearc[u].lowcost = 0;
//
//	for (int i = 1; i < G.vexnum; i++)
//	{
//		int min = -1;
//		int v;
//
//		for (int j = 0; j < G.vexnum; j++)
//		{
//			if (min == -1 && closearc[j].lowcost > 0)
//			{
//				min = closearc[j].lowcost;
//				v = j;
//			}
//			if (min != -1 && closearc[j].lowcost > 0 && closearc[j].lowcost < min)
//			{
//				min = closearc[j].lowcost;
//				v = j;
//			}
//		}
//
//		closearc[v].lowcost = 0;
//		int u = closearc[v].adjvex;
//		Visit(G, u, v);
//
//		for (int j = 0; j < G.vexnum; j++)
//		{
//			if (closearc[j].lowcost != 0 && G.arcs[v][j])
//			{
//				if (closearc[j].lowcost == -1)
//				{
//					closearc[j].adjvex = v;
//					closearc[j].lowcost = G.arcs[v][j];
//				}
//			}
//		}
//	}
//}
//
//void Visit(const MGraph& G, int u, int v)
//{
//	printf("[%c] -> [%c] : %d\n", G.vexs[u], G.vexs[v], G.arcs[u][v]);
//}