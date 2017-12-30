// KMPmatch.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int* buildNext2(const char *P)
{
	int j = 0, m = strlen(P);
	int t, *next = new int[m + 1];

	t = next[0] = -1;
	while (j < m)
	{
		if (0 > t || P[j] == P[t])
		{
			++j, ++t;
			next[j] = P[j] == P[t] ? t : next[t];
		}
		else
			t = next[t];
	}
	return next;
}

int* buildNext(const char *P)
{
	int j = 0, m = strlen(P);
	int t, *next = new int[m+1];

	t = next[0] = -1;
	while (j < m)
	{
		if (0 > t || P[j] == P[t])
		{
			++j, ++t;
			next[j] = t;
		}
		else
			t = next[t];
	}
	return next;
}

int kmpMatch(const char *P, const char *T)
{
	int i, n = strlen(T);
	int j, m = strlen(P);
	int *next = buildNext(P);

	i = j = 0;
	while (i < n && j < m)
	{
		if (0 > j || T[i] == P[j])
			i++, j++;
		else
			j = next[j];
	}
	return i - j;
}

// 变化, 

int kmpCount(const char *P, const char *T)
{
	int i, n = strlen(T);
	int j, m = strlen(P);
	int *next = buildNext(P);
	int _count = 0;

	i = j = 0;
	while (i < n && j < m)
	{
		if (0 > j || T[i] == P[j])
			i++, j++;
		else
			j = next[j];
		if (j == m)
		{
			_count++;
			j = next[j];
		}
	}
	delete[] next;
	return _count;
}

int main()
{
	char t[][1024] = {
		"aaaabbbbaaaabbbbaaaabbbbab",
		"aaaaaaaaaaaaaaa",
		"abcdefga",
		"abcabc",
		"abcabd",
		"abcaba",
		"aabcaaaa",
		"aabbcaabdd",
	};

	size_t s = sizeof(t) / sizeof(t[0]);
	vector<vector<int> > vi;
	vi.resize(s);

	for (int i = 0; i < s; ++i)
	{
		int *next = buildNext(t[i]);
		vi[i].insert(vi[i].begin(), next, next + strlen(t[i]));
	}
	for (int i = 0; i < s; ++i)
	{
		int len = strlen(t[i]);
		for (int j = 0; j < len; ++j)
			printf("%3c", t[i][j]);
		putchar('\n');
		for (int j = 0; j < len; ++j)
			printf("%3d", vi[i][j]);
		putchar('\n');
	}

    return 0;
}

