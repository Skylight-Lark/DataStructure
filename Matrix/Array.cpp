#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"

void ReverseArray(int A[], int p, int q)
{//��ת�����ض����ε�����
	for (; p < q; p++, q--)
	{
		int temp = A[q];
		A[q] = A[p];
		A[p] = temp;
	}
}

void RightMove(int A[], int n, int k)
{//����ѭ������k��Ԫ��
	k %= n;
	ReverseArray(A, 0, n - k - 1);
	ReverseArray(A, n - k, n - 1);
	ReverseArray(A, 0, n - 1);
}

void PrintArray(int A[], int n)
{//��ӡ����
	for (int i = 0; i < n; i++) {
		printf("%d\t", A[i]);
	}
	printf("\n");
}
