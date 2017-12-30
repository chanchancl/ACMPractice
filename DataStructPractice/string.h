#pragma once

#include <string.h>

// �ַ���ƥ��

//1.BF

// �� str1 ��Ѱ�� str2
namespace BF
{
	int Match1(char *P, char *T)
	{
		unsigned int i = 0, n = strlen(T);
		unsigned int j = 0, m = strlen(P);
		while (j < m && i < n)
		{
			if (T[i] == P[j])
				i++, j++;
			else
				i = i - j + 1, j = 0;
		}
		return i - j;
	}

	int Match2(char *P, char *T)
	{
		unsigned int i = 0, n = strlen(T);
		unsigned int j = 0, m = strlen(P);
		for (i = 0; i < n - m + 1; ++i)
		{
			for (j = 0; j < m; ++j)
				if (T[i + j] == P[j]) break;
			if (j >= m) break;
		}
		return i;
	}
}

//2. KMP

namespace KMP
{
	int* buildNext(const char *P)
	{
		unsigned j = 0, pLen = strlen(P);
		int *next = new int[pLen];
		int t = next[0] = -1;
		while (j < pLen)
		{
			if (t < 0 || P[j] == P[t])
			{
				++j, ++t;
				next[j] = t;

			}
			else
				t = next[t];
		}
		return next;
	}

	// ������ T �У�����ģʽ�� P
	int Match(const char *P,const char *T)
	{
		int *next = buildNext(P);
		int i = 0, n = (int)strlen(T);
		int j = 0, m = (int)strlen(P);
		while (i < n && j < m)
		{
			if (j < 0 || T[i] == P[j])
				++i, ++j;
			else
				j = next[j];
		}
		delete[] next;
		return i - j;
	}
}
