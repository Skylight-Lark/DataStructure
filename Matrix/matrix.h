#ifndef _MATRIX_H
#define _MATRIX_H
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define MAXRC 10
#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define INFEASIBLE	-1
#define OVERFLOW	-2
typedef int Elemtype;

typedef struct {
	int i, j;
	Elemtype e;
}Triple;


typedef struct {
	Triple data[MAXSIZE + 1];
	int rpos[MAXRC + 1];//各行第一个非零元的位置表
	int mu, nu, tu;//矩阵的行数、列数和非零元素个数
}TMatrix;

int CreatMatrix(TMatrix& M);//注意元素值数据类型为int型
int DestroyMatrix(TMatrix& M);
int AddMatrix(TMatrix M1, TMatrix M2, TMatrix& M);
int PrintMatrix(TMatrix M);
#endif

