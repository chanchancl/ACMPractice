#pragma once

#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[105][105] = { 0 };
int visited[105];
const int INF = 0x7f7f7f7f;
int prim()
{
	int ans = 0;
	int cost[105] = { 0 };
	fill(cost, cost + 105, INF);
	cost[1] = 0;
	for (int i = 0; i < n; ++i)
	{
		int min = INF, id = -1;
		for (int j = 1; j <= n; ++j)
		{
			if (!visited[j] && min > cost[j])
			{
				id = j;
				min = cost[j];
			}
		}
		if (id == -1)
			continue;
		ans += min;
		visited[id] = 1;
		for (int j = 1; j <= n; ++j)
		{
			if (!visited[j] && map[id][j] < cost[j] && map[id][j] != INF)
			{
				cost[j] = map[id][j];
			}
		}
	}
	return ans;
}
/*
int main()
{
	int i, k;
	cin >> n;
	k = n*(n - 1) / 2;
	for (i = 0; i < k; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (d == 0)
		{
			map[a][b] = c;
			map[b][a] = c;
		}
	}
	cout << prim() << endl;

	return 0;
}
*/