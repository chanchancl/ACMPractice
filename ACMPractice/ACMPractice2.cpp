
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <functional>
#include <utility>
using namespace std;

int d[21] = {0};

void insert(int root, int x)
{
	if (d[root] == 0)
	{
		d[root] = x;
		return;
	}
	if (x > d[root])
		insert(root * 2, x);
	else
		insert(root * 2 + 1, x);
}

int main()
{
	int i, t, n;
	cin >> n;

	for (i = 0; i < n; ++i)
	{
		cin >> t;
		insert(1, t);
	}

	bool yes = true;
	for (i = 1; i <= n; ++i)
	{
		if (d[i] != 0)
		{
			if (i != 1)
				putchar(' ');
			printf("%d", d[i]);
		}
		else
		{
			n++;
			yes = false;
		}
	}
	putchar('\n');
	if (yes)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

/*
typedef pair<int,int> line;

const int MAX = 505;
int table[MAX] = { 0 };
void init()
{
	for (int i = 0; i < MAX; ++i)
		table[i] = i;
}
int find(int x)
{
	if (x == table[x])
		return x;
	return table[x] = find(table[x]);
}
void merge(int x, int y)
{
	table[find(y)] = table[find(x)];
}
int count(int end)
{
	int ret = 0;
	for (int i = 0; i < end; ++i)
		if (find(i) == i)
			ret++;
	return ret;
}

int main()
{
	vector<line> v;
	int n, m, i;

	cin >> n >> m;
	v.resize(m);
	init();
	for (i = 0; i < m; ++i)
	{
		cin >> v[i].first >> v[i].second;
		merge(v[i].first, v[i].second);
	}
	
	int before, now;
	before = count(n);

	int k;
	cin >> k;

	for (i = 0; i < k; ++i)
	{
		int t;
		cin >> t;
		vector<line>::iterator it = v.begin();
		init();
		for (; it != v.end();)
		{
			if (it->first == t || it->second == t)
				it = v.erase(it);
			else
			{
				merge(it->first, it->second);
				it++;
			}
		}
		now = count(n);

		if (before == now || before + 1 == now)
			printf("City %d is lost.\n", t);
		else
			printf("Red Alert: City %d is lost!\n", t);
		before = now;
	}
	if (now == n)
		printf("Game Over.\n");
	return 0;
}

*/


/*

// ½±ÅÆ°ñ

struct country
{
	int gold, jiang;
	int people;

	double agold, ajiang;
	int rank[4];
	int id;
};


vector<country> vc;

int main()
{
	int n, m, i, t;
	cin >> n >> m;
	vc.resize(n);

	for (i = 0; i < n; ++i)
	{
		vc[i].id = i;
		cin >> vc[i].gold >> vc[i].jiang >> vc[i].people;
		vc[i].agold = 1.0*vc[i].gold / vc[i].people;
		vc[i].ajiang = 1.0*vc[i].jiang / vc[i].people;
	}

	sort(vc.begin(), vc.end(), [](const country c1, const country c2) {
		return c1.gold > c2.gold;
	});
	for (i = 0; i < n; ++i)
		vc[i].rank[0] = i;

	sort(vc.begin(), vc.end(), [](const country c1, const country c2) {
		return c1.jiang > c2.jiang;
	});
	for (i = 0; i < n; ++i)
		vc[i].rank[1] = i;

	sort(vc.begin(), vc.end(), [](const country c1, const country c2) {
		return c1.agold > c2.agold;
	});
	for (i = 0; i < n; ++i)
		vc[i].rank[2] = i;

	sort(vc.begin(), vc.end(), [](const country c1, const country c2) {
		return c1.ajiang > c2.ajiang;
	});
	for (i = 0; i < n; ++i)
		vc[i].rank[3] = i;

	int j,k;

	for (i = 0; i < m; ++i)
	{
		int c, min = 99999, method;
		cin >> c;
		for (j = 0; j < vc.size(); ++j)
		{
			if (c == vc[j].id)
			{
				k = j;
				break;
			}
		}
		for (j = 0; j < 4; ++j)
		{
			if (min > vc[k].rank[j])
			{
				min = vc[k].rank[j];
				method = j;
			}
		}
		if (i != 0)
			cout << ' ';
		printf("%d:%d", min + 1, method+1);
	}

	return 0;
}
*/

/*
const int MAX = 505;
const int INF = 0x7fffffff;
int mapdis[MAX][MAX] = { {0} };
int maptime[MAX][MAX] = { {0} };
int visited[MAX] = { 0 };
int path[MAX] = { 0 };
int n, m;
vector<int> pathdis, pathtime;
int ttime[MAX], dis[MAX], num[MAX];

void djkstra_time(int start, int end)
{
	int i,j;
	fill(ttime, ttime + MAX, INF);
	fill(dis, dis + MAX, INF);


	ttime[start] = 0;
	dis[start] = 0;
	path[start] = -1;

	for (i = 0; i < n; ++i)
	{
		int id = -1, mn = INF;
		for (j = 0; j < n; ++j)
		{
			if (!visited[j] && ttime[j] < mn)
			{
				id = j;
				mn = ttime[j];
			}
		}

		visited[id] = 1;
		if (id == end)
			break;

		for (j = 0; j < n; ++j)
		{
			if (!visited[j] && maptime[id][j])
			{
				if (ttime[id] + maptime[id][j] < ttime[j])
				{
					ttime[j] = ttime[id] + maptime[id][j];
					dis[j] = dis[id] + mapdis[id][j];
					path[j] = id;
				}
				else if (ttime[id] + maptime[id][j] == ttime[j])
				{
					if (dis[id] + mapdis[id][j] < dis[j])
					{
						dis[j] = dis[id] + mapdis[id][j];
						path[j] = id;
					}
				}
			}
		}
	}
	int e = end;
	while (e != -1)
	{
		pathtime.push_back(e);
		e = path[e];
	}
}

void djkstra_dis(int start, int end)
{
	int i, j;
	fill(ttime, ttime + MAX, INF);
	fill(dis, dis + MAX, INF);
	fill(num, num + MAX, INF);
	fill(visited, visited + MAX, 0);

	ttime[start] = 0;
	dis[start] = 0;
	num[start] = 0;
	path[start] = -1;

	for (i = 0; i < n; ++i)
	{
		int id = -1, mn = INF;
		for (j = 0; j < n; ++j)
		{
			if (!visited[j] && dis[j] < mn)
			{
				id = j;
				mn = dis[j];
			}
		}

		visited[id] = 1;
		if (id == end)
			break;

		for (j = 0; j < n; ++j)
		{
			if (!visited[j] && mapdis[id][j])
			{
				if (dis[id] + mapdis[id][j] < dis[j])
				{
					dis[j] = dis[id] + mapdis[id][j];
					num[j] = num[id] + 1;
					path[j] = id;
				}
				else if (dis[id] + mapdis[id][j] == dis[j])
				{
					if (num[id] + 1 < num[j])
					{
						num[j] = num[id];
						path[j] = id;
					}
				}
			}
		}
	}

	int e = end;
	while (e != -1)
	{
		pathdis.push_back(e);
		e = path[e];
	}

}

void print_road(vector<int> &p)
{
	int i;
	cout << p[p.size() - 1];
	for(i=p.size()-2; i >= 0; --i)
	{
		cout << " => " << p[i];
	}
}

int main()
{
	int i, start, end;
	cin >> n >> m;

	for (i = 0; i < m; ++i)
	{
		int a, b, c, d, f;
		cin >> a >> b >> c >> d >> f;
		if (!c)
		{
			mapdis[a][b] = mapdis[b][a] = d;
			maptime[a][b] = maptime[b][a] = f;
		}
		else
		{
			mapdis[a][b] = d;
			maptime[a][b] = f;
		}
	}
	cin >> start >> end;

	djkstra_time(start, end);
	int timeend = ttime[end];
	djkstra_dis(start, end);
	cout << "Time = " << timeend;

	if (pathdis == pathtime)
	{
		cout << "; ";
	}
	else
	{
		cout << ": ";
		print_road(pathtime);
		cout << endl;
	}
	
	cout << "Distance = " << dis[end] << ": ";
	print_road(pathdis);
	cout << endl;

	return 0;
}
*/

/*
// dfs Á·Ï°
int n, m;
const int MAX = 105;
int map[MAX][MAX] = { 0 };
int visited[MAX] = { 0 };
int path[MAX] = { 0 };

void dfs(int start, int end)
{
	cout << ' ' << start;
	if (start == end)
	{
		cout << endl;
		return;
	}
	
	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i] && map[start][i])
		{
			visited[i] = 1;
			dfs(i, end);
			visited[i] = 0;
		}
	}
	cout << endl;
}

int main()
{
	int i;
	cin >> n >> m;
	for (i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}

	visited[1] = 1;
	dfs(1, 20);

}
*/


/*
int main()
{
	int i, n, sum;
	priority_queue<int, vector<int>, greater<int>> q;
	cin >> n;
	sum = 0;
	for (i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		q.push(t);
	}
	if (n == 1)
	{
		cout << 0 << endl;
	}
	else
	{
		while (1)
		{
			int a, b;
			a = q.top(); q.pop();
			b = q.top(); q.pop();
			sum += a + b;
			if (q.empty())
				break;
			q.push(a + b);
		}
		cout << sum << endl;
	}
	return 0;
}
*/

/*
int n, in[20], out[20];

int j = 0;

void build(int root, int n)
{
	if (root <= n)
	{
		build(2 * root, n);
		out[root] = in[j++];
		build(2 * root + 1, n);
	}
}

int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> in[i];

	sort(in, in + n);

	build(1, n);

	cout << out[1] << endl;
	return 0;
}
*/

/*
int n, in[1005], out[2010];
int j = 0;
void build(int root, int n)
{
	if (root <= n)
	{
		build(2 * root, n);
		out[root] = in[j++];
		build(2 * root + 1, n);
	}
}

int main()
{
	int i;
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> in[i];

	sort(in, in + n);

	build(1, n);

	for (i = 1; i <= n; ++i)
	{
		if (i != 1)
			cout << ' ';
		cout << out[i];
	}

	return 0;
}
*/

/*
const int INF = 0x7fffffff;
int n, m;
int map[105][105] = { 0 };
int visited[105] = { 0 };

int bfs(int start)
{
	int num = 0,i;

	queue<int> q;
	q.push(start);

	while (!q.empty())
	{
		start = q.front();
		q.pop();
		if (visited[start])
			continue;
		visited[start] = 1;
		num++;
		for (i = 1; i <= n; ++i)
		{
			if (!visited[i] && map[start][i] != INF)
				q.push(i);
		}
	}
	return num;
}


int main()
{
	int i, j, k;
	fill(map[0], map[0] + 105 * 105, INF);
	
	cin >> n >> m;
	for (i = 1; i <= n; ++i)
		map[i][i] = 0;
	for (i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = map[b][a] = c;
	}

	for (k = 1; k <= n; ++k)
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j)
				if (map[i][k] != INF && map[k][j] != INF && map[i][k] + map[k][j] < map[i][j])
					map[i][j] = map[i][k] + map[k][j];

	int Max[105] = { 0 };
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
			if (map[i][j] != INF && map[i][j] > Max[i])
				Max[i] = map[i][j];
	}

	int m, id;
	m = 0x7fffffff;
	for (i = 1; i <= n; ++i)
	{
		if (Max[i] < m)
		{
			m = Max[i];
			id = i;
		}
	}
	int num = bfs(id);
	if (num != n)
		cout << 0 << endl;
	else
		cout << id << ' ' << m << endl;

	return 0;
}
*/


/*
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

/*

const int INF = 0x7fffffff;
const int MAX = 505;

int n, m, s, d;
int map[MAX][MAX] = { 0 };
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

		for (j = 0; j < n; ++j)
		{
			if (!visited[j] && map[id][j])
			{
				if (dis[id] + map[id][j] < dis[j])
				{
					dis[j] = dis[id] + map[id][j];
					jiu[j] = jiu[id] + num[j];
					path[j] = id;
				}
				else if (dis[id] + map[id][j] == dis[j])
				{
					if (jiu[j] < jiu[id] + num[j])
					{
						jiu[j] = jiu[id] + num[j];
						path[j] = id;
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
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i] && map[start][i] && dis[start] + map[start][i] == dis[i])
		{
			visited[i] = 1;
			dps(i, end);
			visited[i] = 0;
		}
	}
}

int main()
{
	int i;
	cin >> n >> m >> s >> d;

	for (i = 0; i < n; ++i)
		cin >> num[i];

	for (i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = map[b][a] = c;
	}

	djstra(s,d);
	fill(visited, visited + MAX, 0);
	dps(s,d);

	stack<int> st;
	int e = d;
	while (e != -1)
	{
		st.push(e);
		e = path[e];
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

/*
const int INF = 0x7fffffff;
const int MAX = 1005;
int map[MAX][MAX] = { 0 };
int visited[MAX] = { 0 };
int m, n;

int prim()
{
	int i,j ,ans = 0;
	int dis[MAX];
	fill(dis, dis + MAX, INF);

	dis[1] = 0;
	for (i = 0; i < n; ++i)
	{
		int id = -1, mn = INF;
		for (j = 1; j <= n; ++j)
		{
			if (!visited[j] && dis[j] < mn)
			{
				id = j;
				mn = dis[j];
			}
		}
		if (id == -1)
			return ans;
		visited[id] = 1;
		ans += dis[id];

		for (j = 1; j <= n; ++j)
		{
			if (!visited[j] && map[id][j] && map[id][j] < dis[j])
			{
				dis[j] = map[id][j];
			}
		}
	}
	return ans;
}

int main()
{
	int i;
	cin >> n >> m;
	
	for (i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = map[b][a] = c;
	}
	int ans = prim();

	bool allvisit = true;
	for (i = 1; i <= n; ++i)
		if (!visited[i])
			allvisit = false;

	if (allvisit)
		cout << ans << endl;
	else
		cout << -1 << endl;

	return 0;
}
*/

/*
const int MAX = 30005;
int table[MAX];

void init()
{
	for (int i = 0; i < MAX; ++i)
		table[i] = i;
}
int find(int x)
{
	if (table[x] != x)
		return table[x] = find(table[x]);
	return x;
}
void Union(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x != y)
		table[x] = y;
}

int main()
{
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	init();
	for (i = 0; i < m; ++i)
	{
		int t, first;
		scanf("%d %d", &t, &first);
		t--;
		for (j = 0; j < t; ++j)
		{
			int k;
			scanf("%d", &k);
			Union(k, first);
		}
	}

	for (i = 1; i <= n; ++i)
		find(i);

	int count[MAX] = { 0 };
	for (i = 1; i <= n; ++i)
		count[table[i]]++;

	int *c = max_element(count, count + n);
	cout << *c << endl;
	return 0;
}
*/