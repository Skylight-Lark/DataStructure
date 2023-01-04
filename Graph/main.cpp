#define _CRT_SECURE_NO_WARNINGS

#include "graph.h"

int main()
{
	int i, j,k;
	ALGraph G,G1;
	MGraph M;
	int p[MAX_VERTEX_NUM];
	int d[MAX_VERTEX_NUM];
	/*printf("����һ������ͼ\n");
	CreateALG(G);
	printf("------------------------------------------------\n");
	printf("vexnum = %d ; arcnum = %d \n", G.vexnum, G.arcnum);
	printf("------------------------------------------------\n");
	printf("����ͼ���ڽӱ�Ϊ��\n");
	PrintALG(G);
	printf("------------------------------------------------\n");
	printf("��ʼ�������λ�ã�");
	scanf("%d %d", &i, &j);
	FindPathDFS(G, i, j);*/

	printf("����һ������ͼ\n");
	CreateALG(G1);
	printf("------------------------------------------------\n");
	printf("vexnum = %d ; arcnum = %d \n", G1.vexnum, G1.arcnum);
	printf("------------------------------------------------\n");
	printf("����ͼ���ڽӱ�Ϊ��\n");
	PrintALG(G1);
	printf("------------------------------------------------\n");
	printf("��ʼ�������λ�ú�·�����ȣ�");
	scanf("%d %d %d", &i, &j,&k);
	FindKPathDFS(G1, i, j ,k);

	ALGraphToMGraph(G1, M);
	PrintMG(M);
	printf("��������ʼ���λ��\n");
	scanf("%d", &i);
	ShortPath_DJS(M, i, p, d);
	for (int j = 0; j < G1.vexnum; j++)
	{
		printf("��%d���㵽��%d��������·������Ϊ%d\n", i, j, d[j]);
	}
	return 0;
	
}