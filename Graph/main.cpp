#define _CRT_SECURE_NO_WARNINGS

#include "graph.h"

int main()
{
	int i, j,k;
	ALGraph G,G1;
	MGraph M;
	int p[MAX_VERTEX_NUM];
	int d[MAX_VERTEX_NUM];
	/*printf("创建一个有向图\n");
	CreateALG(G);
	printf("------------------------------------------------\n");
	printf("vexnum = %d ; arcnum = %d \n", G.vexnum, G.arcnum);
	printf("------------------------------------------------\n");
	printf("有向图的邻接表为：\n");
	PrintALG(G);
	printf("------------------------------------------------\n");
	printf("起始两个点的位置：");
	scanf("%d %d", &i, &j);
	FindPathDFS(G, i, j);*/

	printf("创建一个无向图\n");
	CreateALG(G1);
	printf("------------------------------------------------\n");
	printf("vexnum = %d ; arcnum = %d \n", G1.vexnum, G1.arcnum);
	printf("------------------------------------------------\n");
	printf("无向图的邻接表为：\n");
	PrintALG(G1);
	printf("------------------------------------------------\n");
	printf("起始两个点的位置和路径长度：");
	scanf("%d %d %d", &i, &j,&k);
	FindKPathDFS(G1, i, j ,k);

	ALGraphToMGraph(G1, M);
	PrintMG(M);
	printf("请输入起始点的位置\n");
	scanf("%d", &i);
	ShortPath_DJS(M, i, p, d);
	for (int j = 0; j < G1.vexnum; j++)
	{
		printf("第%d顶点到第%d顶点的最短路径长度为%d\n", i, j, d[j]);
	}
	return 0;
	
}