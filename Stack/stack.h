#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>

#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define INFEASIBLE	-1
#define OVERFLOW	-2

#define STACK_INIT_SIZE 100
#define STACKINCREMENT	10
typedef int Elemtype;

typedef struct {
	Elemtype* base;
	Elemtype* top;
	int stacksize;
}SqStack;

typedef struct {
	Elemtype* data;
	Elemtype* left;
	Elemtype* right;
	int stacksize;
}DuStack;

int InitStack(SqStack& S);
int DestroyStack(SqStack& S);
int GetTop(SqStack S, Elemtype& e);
int Push(SqStack& S, Elemtype e);
int Pop(SqStack& S, Elemtype& e);
int CreatStack(SqStack& S);
int PrintStack(SqStack S, int Printtype);

int InitDustack(DuStack& S);
int DestroyDu(DuStack& S);
int PopDustack(DuStack& S, int i, int& e);
int PushDustack(DuStack& S, int i, int e);
int PrintDu(DuStack& S, int type);
#endif
