#ifndef _STRING_H
#define _STRING_H


#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAXSTRLEN 255

#define TRUE	1
#define FALSE	0
#define OK		1
#define ERROR	0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef unsigned char SString[MAXSTRLEN + 1];//O号元素存放串的长度

int StrCreat(SString& S);
int StrClear(SString& S);
int Concat(SString& T, SString S1, SString S2);
int StrCopy(SString& T, SString S);
int SubString(SString& Sub, SString S, int pos, int len);
int StrCompare(SString S1, SString S2);
int Compare(SString S1, SString S2);
void StrRelace(SString& T, SString P, SString S);
int StrPrint(SString S);

void get_next(SString T, int next[]);
void get_nextval(SString T, int nextval[]);
int Index_KMP(SString S, SString T, int pos);

#endif 

