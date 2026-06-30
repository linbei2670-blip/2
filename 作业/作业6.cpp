#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAXSIZE 100
typedef struct string {
	char* str1;
	char* str2;
	char* str3;
}string;

string* initiate();
void StrAssign(char* str, char* c);
void StrAppendN(char* str1, char* str2,int n);
void StrSearch(char* str1, char* str3,int m);

string* initiate() {
	string* s = (string*)malloc(sizeof(string));
	assert(s != NULL);
	s->str1 = (char*)malloc(sizeof(char) * MAXSIZE);
	s->str2 = (char*)malloc(sizeof(char) * MAXSIZE);
	s->str3 = (char*)malloc(sizeof(char) * MAXSIZE);
	return s;
}

void StrAssign(char* str, char* c) {
	int i = 0;
	while (*c != '\0' && i < MAXSIZE - 1) {
		str[i++] = *c++;
	}
	str[i] = '\0';
}

void StrAppendN(char* str1, char* str2,int n) {
	if (n > strlen(str2)) {
		printf("长度有误");
		return;
	}

	if (str1[0] != '\0' || str2[0] != '\0') {
		strncat(str1, str2, n);
		printf("添加成功，新字符为%s\n", str1);
	}
}

void StrSearch(char* str1, char* str3,int m) {
	char* pos = strstr(str1, str3);
	if (pos != NULL) {
		printf("找到字符串，位置为%d", pos - str1);
	}
	else {
		int len1 = strlen(str1);
		int len2 = strlen(str3);
		if (m > len1) {
			m = len1;
		}
		for (int i = len1; i >= m-1; i--) {
			str1[i + len2] = str1[i];
		}
		for (int i = m - 1; i < m - 1 + len2; i++) {
			str1[i] = str3[i - m + 1];
		}
		printf("%s", str1);
	}

}
int main() {
	string* s = initiate();
	char string1[] = "typedefstructArcBox";
	char string2[] = "VertexTypedata";
	char string3[] = "data";
	StrAssign(s->str1,string1);
	StrAssign(s->str2,string2);
	StrAssign(s->str3, string3);
	int n = 0;
	scanf("%d", &n);
	StrAppendN(s->str1, s->str2, n);
	int m = 0;
	scanf("%d", &m);
	StrSearch(s->str1, s->str3,m);
	return 0;
}