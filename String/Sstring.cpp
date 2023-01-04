#define _CRT_SECURE_NO_WARNINGS

#include "string.h"

int main()
{
	SString s1, s2,s3;
	printf("����������\n");
	StrCreat(s1);
	printf("�������ִ�\n");
	StrCreat(s2);
	printf("�������滻��\n");
	StrCreat(s3);
	
	StrRelace(s1, s2, s3);
	
	StrPrint(s1);

	return 0;
}


int StrCreat(SString& S)
{//�����ַ���
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
{//����ַ���
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
{//���������ַ�������δ�ضϣ��򷵻�TRUE�����򷵻�FALSE
	int i;
	int uncut;
	if (S1[0] + S2[0] <= MAXSTRLEN) {//δ�ض�
		for (i = 1; i <= S1[0]; i++) {
			T[i] = S1[i];
		}
		for (i = 1; i <= S2[0]; i++) {
			T[S1[0] + i] = S2[i];
		}
		T[0] = S1[0] + S2[0];
		uncut = TRUE;
	}
	else if (S1[0] < MAXSTRLEN)//�ضϣ�S1���ڣ�S2������
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
{//����S�е����ݵ�T�У����ض�S���򷵻�1�����򷵻�0
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
{//��Sub���ش�S�е�pos���ַ��𳤶�Ϊlen���ִ�
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
{//�Ƚ����ַ����Ĵ�С,��S1����S2ʱ���1����S1����S2ʱ���0����S1С��S2ʱ���-1.
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
{//�Ƚ����ַ������Ƿ����,��S1����S2ʱ�����1����S1������S2ʱ�����0��
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
{//��ӡ�ַ���
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
{//��T�е�һ�γ��ֵ���P��ȵ��Ӵ��滻ΪS����S��P�ĳ��Ȳ�һ�����
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
