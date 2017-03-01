#pragma once

#include <string.h>

// ×Ö·û´®Æ¥Åä

//1.BF

// ÔÚ str1 ÖĞÑ°ÕÒ str2
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

	int* buildNext2(const char *P)
	{
		unsigned int t = 0, j = 0, m = strlen(P);
		int *N = new int[m];
		t = N[0] = -1;
		while (j < m)
		{
			if (t < 0 || P[j] == P[t])
			{
				++t, ++j;
				if (P[j] != P[t])
					N[j] = t;
				else
					N[j] = N[t];
			}
			else
				t = N[t];
		}
		return N;
	}

	int* buildNext(const char *P)
	{
		unsigned j = 0, m = strlen(P);
		int *N = new int[m];
		int t = N[0] = -1;
		while (j < m )
		{
			if (t < 0 || P[j] == P[t])
				 N[++j] = ++t;
			else
				t = N[t];
		}
		return N;
	}

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
