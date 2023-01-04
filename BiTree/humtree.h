#ifndef HUMTREE_H_
#define HUMTREE_H_
#include "bitree.h"

typedef struct
{
    int weight;
	unsigned int parent, lchild, rchild;
}HTnode,*HMTree;

typedef char** HMcode;
void HMTcoding(HMTree& HT, HMcode& HC, int* w, int n);
int Select(HMTree& HT, int n, int& s1, int& s2);
#endif // !HUMTREE_H_

