#define _CRT_SECURE_NO_WARNINGS

#include "string.h"

int main()
{
	SString s1, s2,s3;
	printf("请输入主串\n");
	StrCreat(s1);
	printf("请输入字串\n");
	StrCreat(s2);
	printf("请输入替换串\n");
	StrCreat(s3);
	
	StrRelace(s1, s2, s3);
	
	StrPrint(s1);

	return 0;
}


int StrCreat(SString& S)
{//创建字符串
	int i = 1;
	char s;

	scanf("%c", &s);
	while (s != '\n') {
		S[i] = s;
		scanf("%c", &s);
		i++;
	}
	S[0] = i - 1;
	return OK;
}


int StrClear(SString& S)
{//清空字符串
	int i;
	if (S[0] == 0) {
		return ERROR;
	}
	for (i = 1; i <= S[0]; i++) {
		S[i] = '\0';
	}
	S[0] = 0;
	return OK;
}

int Concat(SString& T, SString S1, SString S2)
{//链接两个字符串。若未截断，则返回TRUE，否则返回FALSE
	int i;
	int uncut;
	if (S1[0] + S2[0] <= MAXSTRLEN) {//未截断
		for (i = 1; i <= S1[0]; i++) {
			T[i] = S1[i];
		}
		for (i = 1; i <= S2[0]; i++) {
			T[S1[0] + i] = S2[i];
		}
		T[0] = S1[0] + S2[0];
		uncut = TRUE;
	}
	else if (S1[0] < MAXSTRLEN)//截断，S1存在，S2部分在
	{
		for (i = 1; i <= S1[0]; i++) {
			T[i] = S1[i];
		}
		for (i = 1; i <= MAXSTRLEN - S2[0]; i++) {
			T[S1[0] + i] = S2[i];
		}
		T[0] = MAXSTRLEN;
		uncut = FALSE;
	}
	else {
		for (i = 1; i <= MAXSTRLEN; i++) {
			T[i] = S1[i];
		}
		T[0] = MAXSTRLEN;
		uncut = MAXSTRLEN;
	}
	return uncut;
}

int StrEmpty(SString S)
{
	if (S[0] == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}

int StrCopy(SString& T, SString S)
{//复制S中的内容到T中，若截断S，则返回1，否则返回0
	int i;
	int uncut;
	if (S[0] <= MAXSTRLEN) {
		for (i = 1; i < S[0]; i++) {
			T[i] = S[i];
		}
		T[0] = S[0];
		uncut = TRUE;
	}
	else if (S[0] > MAXSTRLEN) {
		for (i = 1; i <= MAXSTRLEN; i++) {
			T[i] = S[i];
		}
		T[0] = MAXSTRLEN;
		uncut = FALSE;
	}
	return uncut;
}

int SubString(SString& Sub, SString S, int pos, int len)
{//用Sub返回串S中第pos个字符起长度为len的字串
	if (pos<1 || pos>S[0] || len<0 || len>S[0] - pos + 1) {
		return ERROR;
	}
	int i;
	for (i = 1; i <= len; i++) {
		Sub[i] = S[pos + i - 1];
	}
	Sub[0] = len;
	return OK;
}

int StrCompare(SString S1, SString S2)
{//比较两字符串的大小,当S1大于S2时输出1；当S1等于S2时输出0；当S1小于S2时输出-1.
	int n;
	if (S1[0] >= S2[0]) {
		n = S1[0];
	}
	else {
		n = S2[0];
	}
	for (int i = 1; i <= n; i++) {
		if (S1[i] == S2[i])
			continue;
		else if (S1[i] > S2[i])
			return 1;
		else if (S1[i] < S2[i])
			return -1;
	}
	return 0;
}

int Compare(SString S1, SString S2)
{//比较两字符串的是否相等,当S1等于S2时，输出1；当S1不等于S2时，输出0。
	int n;
	if (S1[0] >= S2[0]) {
		n = S1[0];
	}
	else {
		n = S2[0];
	}
	for (int i = 1; i <= n; i++) {
		if (S1[i] == S2[i])
			continue;
		else
			return 0;

	}
	return 1;
}

int StrPrint(SString S)
{//打印字符串
	if (S == NULL) {
		return ERROR;
	}
	for (int i = 1; i <= S[0]; i++) {
		printf("%c", S[i]);
	}
	printf("\n");

	return OK;
}

void StrRelace(SString& T, SString P, SString S)
{//将T中第一次出现的与P相等的子串替换为S，串S和P的长度不一定相等
	int pos;
	pos=Index_KMP(T, P, 1);
	int i,j;
	if (pos == 0) {
		return;
	}
	else {
		if (P[0] < S[0]) {
			for (i = T[0]; i >= pos + P[0]; i--) {
				T[i + S[0] - P[0]] = T[i];
			}
			T[0] = T[0] + S[0] - P[0];
		}
		else if (P[0] > S[0]) {
			for (i = pos + P[0]; i <= T[0]; i++) {
				T[i - P[0] + S[0]] = T[i];
			}
			T[0] = T[0] - P[0] + S[0];
		}

		i = pos;
		j = 1;
		while (j <= S[0]) {
			T[i] = S[j];
			i++;
			j++;
		}
	}
	
}
