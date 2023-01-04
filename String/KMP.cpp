#include "string.h"

void get_next(SString T, int next[])
{//ԭʼKMP��ȡnext����
	int i = 1;
	int j = 0;
	next[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}

void get_nextval(SString T, int nextval[])
{//�Ľ���KMP
	int i=1;
	int j = 0;
	nextval[0] = T[0];
	nextval[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			i++;
			j++;
			if (T[i] == T[j]) {
				nextval[i] = nextval[j];
			}
			else {
				nextval[i] = j;
			}
		}
		else {
			j = nextval[j];
		}
	}
}

int Index_KMP(SString S, SString T, int pos)
{//�Ľ�KMP�㷨������Tģʽ����S����������1<=pos<=S[0]���ӵ�pos��Ԫ�ؿ�ʼƥ��
	int i = pos;
	int j = 1;
	int* nextval = (int*)malloc((T[0] + 1) * sizeof(int));
	
	nextval[0] = T[0];
	get_nextval(T, nextval);

	if (pos<1 || pos>S[0]) {
		return ERROR;
	}
	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j]) {
			i++;
			j++;
		}
		else {
			j = nextval[j];
		}
	}
	if (j > T[0]) {
		return i - T[0];
	}
	else
		return 0;
}