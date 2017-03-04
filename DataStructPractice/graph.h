#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;

vector<int> e[10005];
int visited[10005];

void bfs(int start)
{
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < e[now].size(); ++i)
		{
			int v = e[now][i];
			if (visited[v])
				continue;
			visited[v] = 1;
			cout << "Visit From " << now << " to " << v << endl;
			q.push(v);
		}
	}
}

void dfs(int start)
{

	stack<int> s;
	s.push(start);
	visited[start] = 1;

	while (!s.empty())
	{
		int now = s.top();
		s.pop();

		for (int i = 0; i < e[now].size(); ++i)
		{
			int v = e[now][i];
			if (visited[v])
				continue;
			cout << "Visit From " << now << " to " << v << endl;
			dfs(v);
			s.push(v);
			break;
		}
	}
}

/*
int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(visited, 0, sizeof(visited));
	cout << "*******bfs**********" << endl;
	bfs(2);
	memset(visited, 0, sizeof(visited));
	cout << "*******dfs**********" << endl;
	dfs(2);

	return 0;
}
*/