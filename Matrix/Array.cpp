#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"

void ReverseArray(int A[], int p, int q)
{//反转数组特定区段的序列
	for (; p < q; p++, q--)
	{
		int temp = A[q];
		A[q] = A[p];
		A[p] = temp;
	}
}

void RightMove(int A[], int n, int k)
{//数组循环右移k个元素
	k %= n;
	ReverseArray(A, 0, n - k - 1);
	ReverseArray(A, n - k, n - 1);
	ReverseArray(A, 0, n - 1);
}

void PrintArray(int A[], int n)
{//打印数组
	for (int i = 0; i < n; i++) {
		printf("%d\t", A[i]);
	}
	printf("\n");
}
