#define _CRT_SECURE_NO_WARNINGS
#include "humtree.h"

//
//int main()
//{
//	HMTree HT;
//	HMcode HC;
//	int w[6] = { 3,5,7,8,11,12 }; 
//	HMTcoding(HT, HC, w, 6);
//	printf("\n赫夫曼编码为：");
//	printf("\n");
//	for (int i = 1; i <= 6; i++)
//	{
//		printf("%s\n", HC[i]);
//	}
//	free(HT);
//	free(HC);
//	return OK;
//}


void HMTcoding(HMTree& HT, HMcode& HC, int* w, int n)
{
	HMTree p;
	char* cd;
	int m = 2 * n - 1;
	int p1 = m;
	int cdlen = 0;
	int i;
	int start;
	int c, f;
	int s1, s2;
	if (n <= 1) {
		return;
	}
	HT = (HMTree)malloc((m + 1) * sizeof(HTnode));//0号单元未用
	for (p = HT + 1, i = 1; i <= n; i++, p++, w++) {
		*p = { *w,0,0,0 };
	}
	for (; i <= m; i++, p++) {
		*p = { 0,0,0,0 };
	}
	for (i = n + 1; i <= m; i++) {
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

	//从叶子到根逆向求赫夫曼树编码

	HC = (HMcode)malloc((n + 1) * sizeof(char*));
	cd = (char*)malloc((n) * sizeof(char));
	cd[n - 1] = '\0';
	for ( i = 1; i <= n; i++)
	{
		start = n - 1;
		for (c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent) {
			if (HT[f].lchild == c) {
				cd[--start] = '0';
			}else{
				cd[--start] = '1';
			}
		}
		HC[i] = (char*)malloc((n - start) * sizeof(char));
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}

int Select(HMTree& HT, int n, int &s1, int& s2)
{//选择函数
	int a;
	for (int i = 1; i <= n; i++) {
		if (HT[i].parent == 0) {
			s1 = i;
			break;
		}
	}
	for (int i = s1 + 1; i <= n; i++) {
		if (HT[i].parent == 0) {
			s2 = i;
			break;
		}
	}
	if (HT[s1].weight > HT[s2].weight) {
		a = s1;
		s1 = s2;
		s2 = a;
	}
	for (int i = s2+1; i <= n; i++) {
		
		if (HT[i].parent == 0) {
			if (HT[s1].weight > HT[i].weight) {
				s2 = s1;
				s1 = i;
			}
			else if (HT[s1].weight < HT[i].weight && HT[i].weight < HT[s2].weight) {
				s2 = i;
			}
			else if (HT[i].weight > HT[s2].weight) {

			}
		}
		
	}
	return OK;
}