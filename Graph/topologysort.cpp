#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"

Vertextype vexs[MAX_VERTEX_NUM];
int visit[MAX_VERTEX_NUM];
int count = 0;

void TopologicakSort_DFS(ALGraph& G)
{
	int i = 0;
	//��ʼ����־����
	for (i = 0; i < G.vexnum; i++) {
		visit[i] = 0;
	}

	//��һ���ڵ㿪ʼDFS����
	for (i = 0; i < G.vexnum; i++)
	{
		if (!visit[i]) {
			DFSALG_TS(G, i);
			vexs[count] = G.adjlist[i].vex;
			count++;
		}
	}
	printf("\n");
	printf("�����޻�ͼ����������");
	for (int i = G.vexnum - 1; i >= 0; i--)
	{
		if (i != 0) {
			printf("[ %c ] -> ", vexs[i]);
		}
		else {
			printf("[ %c ] ", vexs[i]);
		}
	}
	printf("\n");
}

void DFSALG_TS(ALGraph G, int i)
{
	Arcnode* temp = NULL;
	int index;

	visit[i] = 1;


	temp = G.adjlist[i].firstarc;
	while (temp)
	{
		LocateVex(G, temp->adjvex, &index);
		if (!visit[index])
		{
			DFSALG_TS(G, index);
			vexs[count] = G.adjlist[index].vex;
			count++;
		}
		temp = temp->nextarc;
	}
}