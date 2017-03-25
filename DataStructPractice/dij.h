#pragma once

#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int MAX = 505;

int n, m, s, d;
struct edge
{
	int v;
	int dis;
};
vector<edge> e[MAX];
int visited[MAX] = { 0 };
int num[MAX] = { 0 };
int path[MAX] = { 0 };
int dis[MAX], jiu[MAX];

void djstra(int start, int end)
{
	int i, j;
	fill(dis, dis + MAX, INF);
	fill(jiu, jiu + MAX, INF);

	dis[start] = 0;
	path[start] = -1;
	jiu[start] = num[start];

	for (i = 0; i < n; ++i)
	{
		int id = -1, mn = INF;
		for (j = 0; j < n; ++j)
		{
			if (!visited[j] && mn > dis[j])
			{
				id = j;
				mn = dis[j];
			}
		}

		if (id == -1)
			break;
		visited[id] = 1;

		if (id == d)
			break;

		for (j = 0; j < e[id].size(); ++j)
		{
			int v = e[id][j].v;
			if (!visited[v])
			{
				if (dis[id] + e[id][j].dis < dis[v])
				{
					dis[v] = dis[id] + e[id][j].dis;
					jiu[v] = jiu[id] + num[v];
					path[v] = id;
				}
				else if (dis[id] + e[id][j].dis == dis[v])
				{
					if (jiu[v] < jiu[id] + num[v])
					{
						jiu[v] = jiu[id] + num[v];
						path[v] = id;
					}
				}
			}
		}
	}
}

int road = 0;
void dps(int start, int end)
{
	if (start == end)
	{
		road++;
		return;
	}
	for (int i = 0; i < e[start].size(); ++i)
	{
		int v = e[start][i].v;
		if (!visited[v] && dis[start] + e[start][i].dis == dis[v])
		{
			visited[v] = 1;
			dps(v, end);
			visited[v] = 0;
		}
	}
}

/*
int main()
{
	int i;
	cin >> n >> m >> s >> d;

	for (i = 0; i < n; ++i)
		cin >> num[i];
	edge ed;
	for (i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> ed.dis;
		ed.v = b;
		e[a].push_back(ed);
		ed.v = a;
		e[b].push_back(ed);

	}

	djstra(s, d);
	fill(visited, visited + MAX, 0);
	dps(s, d);

	stack<int> st;
	int tmp = d;
	while (tmp != -1)
	{
		st.push(tmp);
		tmp = path[tmp];
	}

	cout << road << ' ' << jiu[d] << endl;
	cout << st.top();
	st.pop();
	while (!st.empty())
	{
		cout << ' ' << st.top();
		st.pop();
	}
	cout << endl;

	return 0;
}
*/