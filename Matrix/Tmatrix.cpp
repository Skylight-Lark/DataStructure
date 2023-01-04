#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"

int CreatMatrix(TMatrix& M)
{//注意元素值数据类型为int型
	int i, j;
	for (i = 1; i <= MAXRC; i++) {
		M.rpos[i] = 0;
	}
	printf("请输入矩阵的行数、列数和非零元个数\n");
	scanf("%d %d %d", &M.mu, &M.nu, &M.tu);
	printf("请按照行序依次输入非零元\n");
	for (i = 1; i <= M.tu; i++) {
		printf("请输入第%d个元素的行数、列数和元素值\n", i);
		scanf("%d %d %d", &M.data[i].i, &M.data[i].j, &M.data[i].e);
	}

	M.rpos[1] = M.data[1].i;

	for (j = M.data[1].i, i = 1; i <= M.tu; i++) {
		if (j != M.data[i].i) {
			j++;
			M.rpos[j] = M.data[i].i;
		}
	}
	return OK;
}

int DestroyMatrix(TMatrix& M)
{//摧毁矩阵
	M.mu = M.nu = M.tu = 0;
	return OK;
}

int AddMatrix(TMatrix M1, TMatrix M2, TMatrix& M)
{//两矩阵相加
	if (M1.mu != M2.mu || M1.nu != M1.nu) {
		return ERROR;
	}
	M.mu = M1.mu;
	M.nu = M1.nu;
	int a;
	int m = 0;
	int m1 = 1;
	int m2 = 1;
	while (m1 <= M1.tu && m2 <= M2.tu) {
		if (M1.data[m1].i < M2.data[m2].i || (M1.data[m1].i == M2.data[m2].i && M1.data[m1].j < M2.data[m2].j)) {
			a = -1;
		}
		else if (M1.data[m1].i == M2.data[m2].i && M1.data[m1].j == M2.data[m2].j) {
			a = 0;
		}
		else if (M1.data[m1].i > M2.data[m2].i || (M1.data[m1].i == M2.data[m2].i && M1.data[m1].j > M2.data[m2].j)) {
			a = 1;
		}
		switch (a) {
		case -1:
			m++;
			M.data[m] = M1.data[m1];
			m1++;
			break;
		case 0:
			m++;
			M.data[m] = M1.data[m1];
			M.data[m].e += M2.data[m2].e;
			m1++;
			m2++;
			break;
		case 1:
			m++;
			M.data[m] = M2.data[m2];
			m2++;
			break;
		}

	}
	while (m1 <= M1.tu) {
		m++;
		M.data[m] = M1.data[m1];
		m1++;
	}
	while (m2 <= M2.tu) {
		m++;
		M.data[m] = M2.data[m2];
		m2++;
	}
	if (m > MAXSIZE) {
		return ERROR;
	}

	M.tu = m;
	for (int i = 1; i <= MAXRC; i++) {
		M.rpos[i] = 0;
	}

	M.rpos[1] = M.data[1].i;

	for (int j = M.data[1].i, i = 1; i <= M.tu; i++) {
		if (j != M.data[i].i) {
			j++;
			M.rpos[j] = M.data[i].i;
		}
	}
	return OK;
}

int PrintMatrix(TMatrix M)
{//输出矩阵
	int k = 1;
	int i = 1;

	int m = M.mu;
	int n = M.nu;

	while (k <= m * n)
	{
		while (i <= M.tu) {
			if (k < (M.data[i].i - 1) * n + M.data[i].j) {
				printf("0\t");
			}
			else if (k == (M.data[i].i - 1) * n + M.data[i].j) {
				printf("%d\t", M.data[i].e);
				i++;
			}
			if (k % n == 0) {
				printf("\n");
			}
			k++;
		}
		if (k <= m * n) {
			printf("0\t");
			k++;
			if (k % n == 0) {
				printf("\n");
			}
		}
	}
	return OK;
}

