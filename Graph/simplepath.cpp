#define _CRT_SECURE_NO_WARNINGS
#include "graph.h"

int visited1[MAX_VERTEX_NUM];     //定义存放节点的访问标志的全局数组
void FindPaths(ALGraph& G, int u, int v, int path[], int d)
//d是到当前为止已走过的路径长度，调用时初值为-1
{
    int w, i;
    Arcnode* p;
    visited1[u] = 1;
    d++;            //路径长度增1
    path[d] = u;              //将当前顶点添加到路径中
    if (u == v && d > 1)            //输出一条路径
    {
        printf("  ");
        for (i = 0; i <= d; i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    p = G.adjlist[u].firstarc; //p指向u的第一条边
    while (p != NULL)
    {
        w = p->adjvex;     //w为u的邻接顶点
        if (visited1[w] == 0)      //若顶点未标记访问，则递归访问之
            FindPaths(G, w, v, path, d);
        p = p->nextarc; //找u的下一个邻接顶点
    }
    visited1[u] = 0;   //恢复环境
}


void DispSimplePaths(ALGraph& G, int u, int v)
{
    int i;
    int path[MAX_VERTEX_NUM];
    for (i = 0; i < G.vexnum; i++)
        visited1[i] = 0; //访问标志数组初始化
    printf("从%d到%d的所有路径:\n", u, v);
    FindPaths(G, u, v, path, -1);
    printf("\n");
}