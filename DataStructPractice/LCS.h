#pragma once


#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int LCS1(const char *buffer1, const char *buffer2,
	int n, int m)
{
	if (n <= 0 || m <= 0) return 0;
	else if (buffer1[n] == buffer2[m])
		return LCS1(buffer1, buffer2, n - 1, m - 1) + 1;
	else
		return max(LCS1(buffer1, buffer2, n - 1, m),
			LCS1(buffer1, buffer2, n, m - 1));
}

int dp[100][100];

// 调用 LCS2 或 LCS3前，请先调用 reset()
void reset()
{
	memset(dp, -1, sizeof(dp));
}

int LCS2(const char *buffer1, const char *buffer2,
	int n, int m)
{
	if (dp[n][m] >= 0) return dp[n][m];
	if (n <= 0 || m <= 0) return dp[0][0] = 0;
	else if (buffer1[n] == buffer2[m])
		return dp[n][m] = LCS2(buffer1, buffer2, n - 1, m - 1) + 1;
	else
		return dp[n][m] = max(LCS2(buffer1, buffer2, n - 1, m),
			LCS2(buffer1, buffer2, n, m - 1));
}

// 目前空间复杂度为 n*m， 可节省至 2*max(n,m)
int LCS3(const char* buffer1, const char *buffer2,
	int n, int m)
{
	memset(dp, 0, sizeof(dp[0]));
	for (int i = 0; i < 100; ++i)
		dp[i][0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (buffer1[i-1] == buffer2[j-1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	/*
	// 状态图
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	return dp[n][m];
}

