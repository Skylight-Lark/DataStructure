#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"

int visit1[MAX_VERTEX_NUM];
int visit2[MAX_VERTEX_NUM];
int tag=0;
int length[MAX_VERTEX_NUM];

int PathDFS1(ALGraph& G, int start, int end)
{
	Arcnode* temp = NULL;
	int index;

	if (start == end)
	{
		return 1;
	}

	temp = G.adjlist[start].firstarc;
	while (temp)
	{
		LocateVex(G, temp->adjvex, &index);
		if (!visit1[index]) {
			if (PathDFS1(G, index, end))
			{
				return 1;
			}
		}
		temp = temp->nextarc;
	}
	return 0;
}

int FindPathDFS(ALGraph& G, int start, int end)
{
	if (start == end)
	{
		printf("两点重合！\n");
		return FALSE;
	}
	if (PathDFS1(G, start, end))
	{
		printf("图中第%d个顶点和第%d个顶点存在路径！\n", start, end);
		return TRUE;
	}
	else
	{
		printf("图中第%d个顶点和第%d个顶点不存在路径！\n", start, end);
		return FALSE;
	}
}

int PathDFS2(ALGraph& G, int start, int end,int l,int k)
{
	Arcnode* temp = NULL;
	int index;
	
	if (start == end && l == k)
	{
		return 1;
	}
	else if (start==end && l != k)
	{
		return 0;
	}

	temp = G.adjlist[start].firstarc;
	while (temp)
	{
		LocateVex(G, temp->adjvex, &index);
		if (!visit2[index])
		{
			if (PathDFS2(G, index, end, l+1, k))
			{
				return 1;
			}
		}
		temp = temp->nextarc;
	}
	return 0;
}

int FindKPathDFS(ALGraph& G, int start, int end,int k)
{
	int l=0;
	if (!(FindPathDFS(G, start, end)))
	{
		return FALSE;
	}
	
	if (PathDFS2(G, start, end, l, k))
	{
		printf("图中第%d个顶点和第%d个顶点之间存在长度为%d的路径!\n",start,end,k);
		return TRUE;
	}
	else {
		printf("图中第%d个顶点和第%d个顶点之间存在长度为%d的路径!\n",start,end,k);
		return FALSE;
	}
}