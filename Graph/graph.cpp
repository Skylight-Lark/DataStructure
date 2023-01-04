#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"

int visited[MAX_VERTEX_NUM];

void CreateALG(ALGraph& G)
{
	Vertextype ch;
	int w=0;
	int i = 0;
	int count = 0;
	Arcnode* temp = NULL;
	//���������
	printf("������ͼ�Ķ��㣺");
	while ((ch = getchar()) != '\n')
	{
		G.adjlist[i].vex = ch;
		G.adjlist[i].firstarc = NULL;
		i++;
	}
	G.vexnum = i;
	//����ÿ��������ٽ�߱�
	//����@Ϊ������־
	for (int i = 0; i < G.vexnum; i++) {
		printf("�������%d���������Ӧ�ߵ�Ȩֵ���ڽӶ���:", i);
		scanf("%d %c",&w , &ch);
		while (ch  != '@')
		{//ͷ�巨�����ڽӱ�
			temp = (Arcnode*)malloc(sizeof(Arcnode));
			if (!temp) {
				printf("out of space!");
				exit(1);
			}
			temp->adjvex = ch;
			temp->nextarc = G.adjlist[i].firstarc;
			G.adjlist[i].firstarc = temp;
			temp->data = w;
			count++;
			ch = getchar();
			printf("�������%d���������Ӧ�ߵ�Ȩֵ���ڽӶ���:", i);
			scanf("%d %c", &w, &ch);
		}
	}
	G.arcnum = count / 2;
}

void PrintMG(MGraph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			if (G.arcs[i][j] == INFINITY) {
				printf("-1\t");
			}
			else {
				printf("%d\t", G.arcs[i][j]);
			}
		}
		printf("\n");
	}
}
void PrintALG(ALGraph G)
{
	int i;
	Arcnode* temp=NULL;

	if (G.vexnum == 0)
	{
		printf("the graph is empty!\n");
		return;
	}
	for (i = 0; i < G.vexnum; i++)
	{
		printf("vexnode %c : ", G.adjlist[i].vex);
		temp = G.adjlist[i].firstarc;
		while (temp)
		{
			printf("[ %c ][ %d ] -> ", temp->adjvex,temp->data);
			temp = temp->nextarc;
		}
		printf("NULL\n");
	}
}

void DFSTraverseALG(ALGraph& G)
{
	int i = 0;
	//��ʼ����־����
	for (i = 0; i < G.vexnum; i++) {
		visited[i] = 0;
	}

	printf("ͼ��������ȱ������У�");

	//��һ���ڵ㿪ʼDFS����
	for (i = 0; i < G.vexnum; i++)
	{
		if (!visited[i]) {
			DFSALG(G, i);
		}
	}
}

void DFSALG(ALGraph G,int i)
{
	Arcnode* temp = NULL;
	int index ;

	printf("%c, ", G.adjlist[i].vex);
	visited[i] = 1;


	temp = G.adjlist[i].firstarc;
	while (temp)
	{
		LocateVex(G, temp->adjvex, &index);
		if (!visited[index])
		{
			DFSALG(G, index);
		}
		temp = temp->nextarc;
	}
}




void LocateVex(ALGraph G, Vertextype vertex, int* index)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.adjlist[i].vex == vertex)
		{
			*index = i;
			return;
		}
	}
	printf("fail to find the node��\n");
}

void initQueue(Queue& Q)
{
	Q.data = (Qdata*)malloc(CQ_INIT_SIZE * sizeof(Qdata));
	if (!Q.data)
	{
		printf("out of space��\n");
		exit(1);
	}
	Q.front = 0;
	Q.tail = 0;
	Q.QCapacity = CQ_INIT_SIZE;
}

int isFull(Queue& Q)
{
	return (Q.tail + 1) % Q.QCapacity == Q.front ? 1 : 0;
}

int isEmpty(Queue& Q)
{
	return Q.front == Q.tail ? 1 : 0;
}

int Qpush(Queue& Q,Qdata& e)
{
	if (isFull(Q))
	{
		Q.data = (Qdata*)realloc(Q.data, (CQ_INIT_SIZE + Q.QCapacity) * sizeof(Qdata));
		if (!Q.data) {
			printf("out of space!\n");
			exit(1);
		}
		Q.QCapacity += CQ_INIT_SIZE;
	}
	Q.data[Q.tail] = e;
	Q.tail = (Q.tail + 1) % Q.QCapacity;
	return 1;
}

int Qpop(Queue& Q, Qdata& e)
{
	if (isEmpty(Q))
	{
		printf("the queue is empty!\n");
		return 0;
	}
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % Q.QCapacity;
	return 1;
}

void BFSTraverseALG(ALGraph& G)
{
	int index;
	char ch;
	Arcnode* temp = NULL;
	Queue Q;
	initQueue(Q);

	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = 0;
	}

	printf("�����뿪ʼ�ڵ㣺");
	scanf("%c", &ch);
	LocateVex(G, ch, &index);

	printf("ͼ�Ĺ�����ȱ�����");
	if (!visited[index]) {
		Qpush(Q, index);
		visited[index] = 1;


		while (!isEmpty(Q))
		{
			Qpop(Q, index);
			printf("%c, ", G.adjlist[index].vex);

			temp = G.adjlist[index].firstarc;

			while (temp)
			{
				LocateVex(G, temp->adjvex, &index);

				if (!visited[index])
				{
					Qpush(Q, index);
					visited[index] = 1;
				}
				temp = temp->nextarc;
			}
		}
	}
}

