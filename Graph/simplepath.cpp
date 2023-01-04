#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"

int visited1[MAX_VERTEX_NUM];     //�����Žڵ�ķ��ʱ�־��ȫ������
void FindPaths(ALGraph& G, int u, int v, int path[], int d)
//d�ǵ���ǰΪֹ���߹���·�����ȣ�����ʱ��ֵΪ-1
{
    int w, i;
    Arcnode* p;
    visited1[u] = 1;
    d++;            //·��������1
    path[d] = u;              //����ǰ������ӵ�·����
    if (u == v && d > 1)            //���һ��·��
    {
        printf("  ");
        for (i = 0; i <= d; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    p = G.adjlist[u].firstarc; //pָ��u�ĵ�һ����
    while (p != NULL)
    {
        w = p->adjvex;     //wΪu���ڽӶ���
        if (visited1[w] == 0)      //������δ��Ƿ��ʣ���ݹ����֮
            FindPaths(G, w, v, path, d);
        p = p->nextarc; //��u����һ���ڽӶ���
    }
    visited1[u] = 0;   //�ָ�����
}


void DispSimplePaths(ALGraph& G, int u, int v)
{
    int i;
    int path[MAX_VERTEX_NUM];
    for (i = 0; i < G.vexnum; i++)
        visited1[i] = 0; //���ʱ�־�����ʼ��
    printf("��%d��%d������·��:\n", u, v);
    FindPaths(G, u, v, path, -1);
    printf("\n");
}