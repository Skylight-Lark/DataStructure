#define _CRT_SECURE_NO_WARNINGS
#include "link.h"

int main()
{
	SqList L;
	InitList_Sq(L);
	Create_String(L);
	PrintList_Sq(L);
	InsertSort(L);
	PrintList_Sq(L);
	DestroyList_Sq(L);
	return 0;
}