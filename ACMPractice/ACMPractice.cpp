// ACMPractice.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
/*
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
*/

/*
const int INF = 0x7fffffff;
const int MAX = 205;

map<string, int> name2i;
vector<string> i2name;
int army[MAX] = { 0 };
int Map[MAX][MAX] = { 0 };
int visited[MAX] = { 0 };
int mappsize;

int dis[MAX];
int pathnumber[MAX] = { 0 };
int kill[MAX] = { 0 };
vector<int> path;
int road = 0;

int n, k;

int findnext()
{
	int mindis, id;
	mindis = INF;
	id = -1;
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i] && dis[i] != INF)
			if (dis[i] < mindis)
			{
				id = i;
				mindis = dis[i];
			}
	}
	return id;
}

void djstra(int start, int end)
{
	fill(dis, dis + MAX, INF);
	fill(pathnumber, pathnumber + MAX, INF);
	fill(kill, kill + MAX, INF);

	dis[start] = 0;
	pathnumber[start] = 0;
	kill[start] = 0;
	path.resize(n);
	path[start] = -1;

	for (int i = 0; i < n; ++i)
	{
		int id = findnext();
		if (id == -1)
			return;

		visited[id] = 1;

		if (id == end)
			break;

		for (int j = 0; j < n; ++j)
		{
			if (!visited[j] && Map[id][j])
			{
				if (dis[id] + Map[id][j] < dis[j])
				{
					dis[j] = dis[id] + Map[id][j];
					pathnumber[j] = pathnumber[id] + 1;
					kill[j] = kill[id] + army[j];
					path[j] = id;
				}
				else if (dis[id] + Map[id][j] == dis[j])
				{
					if (pathnumber[j] < pathnumber[id] + 1)
					{
						pathnumber[j] = pathnumber[id] + 1;
						kill[j] = kill[id] + army[j];
						path[j] = id;
					}
					else if (pathnumber[j] == pathnumber[id] + 1)
					{
						if (kill[j] < kill[id] + army[j])
						{
							kill[j] = kill[id] + army[j];
							path[j] = id;
						}
					}
				}

			}
		}
	}
}

void dfs(int start, int end)
{
	if (start == end)
	{
		road++;
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i] && Map[start][i] && dis[start] + Map[start][i] == dis[i])
		{
			visited[i] = 1;
			dfs(i, end);
			visited[i] = 0;
		}
	}
}

int savename(const string &str)
{
	if (name2i.find(str) != name2i.end())
		return name2i[str];
	i2name[mappsize] = str;
	name2i[str] = mappsize;
	return mappsize++;
}

int main()
{
	string s1,s2;
	scanf("%d %d", &n, &k);
	i2name.resize(n);
	mappsize = 0;

	int start, end, i,j;
	cin >> s1 >> s2;
	start = savename(s1);
	end   = savename(s2);

	for (i = 0; i < n - 1; ++i)
	{
		cin >> s1 >> j;
		int id = savename(s1);
		army[id] = j;
	}
	for (i = 0; i < k; ++i)
	{
		int a, b, c;
		cin >> s1 >> s2 >> c;
		a = savename(s1);
		b = savename(s2);
		Map[a][b] = Map[b][a] = c;
	}

	djstra(start, end);
	fill(visited, visited + MAX, 0);
	dfs(start, end);

	stack<int> st;
	int e = end;
	while (e != -1)
	{
		st.push(e);
		e = path[e];
	}

	cout << i2name[st.top()];
	st.pop();
	while(!st.empty())
	{
		cout << "->" << i2name[st.top()];
		st.pop();
	}
	cout << endl;
	
	int mindis, killall = 0;
	mindis = dis[end];
	killall = kill[end];

	cout << road << ' ' << mindis << ' ' << killall << endl;

	return 0;
}
*/


/*
const int MAX = 105;
int table[MAX];
int map[MAX][MAX] = { 0 };

void init()
{
	for (int i = 0; i < MAX; ++i)
		table[i] = i;
}

int find(int x)
{
	if (x != table[x])
		return table[x] = find(table[x]);
	return x;
}

void Union(int a, int b)
{
	table[find(a)] = find(b);
}

bool conncted(int a, int b)
{
	return find(a) == find(b);
}

int main()
{
	int n, m, k, i;
	cin >> n >> m >> k;
	init();
	for (i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c == -1)
			map[a][b] = map[b][a] = -1;
		else
			Union(a, b);
	}
	for (i = 0; i < k; ++i)
	{
		int a, b;
		cin >> a >> b;
		if (conncted(a, b))
		{
			if (map[a][b] != -1)
				cout << "No problem" << endl;
			else if (map[a][b] == -1)
				cout << "OK but..." << endl;
		}
		else
		{
			if (map[a][b] != -1)
				cout << "OK" << endl;
			else if (map[a][b] == -1)
				cout << "No way" << endl;
		}
	}
	return 0;
}
*/

/*

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 1005;
int map[MAX][MAX] = {0}, path[2 * MAX];
int visited[MAX] = { 0 };
int current, n, m, s;

void dfs(int start)
{
	int i;
	for (i = 1; i <= n; ++i)
	{
		if (map[start][i] == 1 && !visited[i])
		{
			visited[i] = 1;
			path[current++] = i;
			dfs(i);
			path[current++] = start;
		}
	}
}

int main()
{
	int i;
	cin >> n >> m >> s;

	for (i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	current = 0;
	path[current++] = s;
	visited[s] = 1;
	dfs(s);

	bool allvisit = true;
	for (i = 1; i <= n; ++i)
	{
		if (!visited[i])
			allvisit = false;
	}


	cout << path[0];
	for (i = 1; i < current; ++i)
		cout << ' ' << path[i];
	if (!allvisit)
		cout << ' ' << 0;

	return 0;
}
*/



/*

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int table[1005];
int e[1005] = { 0 };

void init()
{
	for (int i = 0; i < 1005; ++i)
		table[i] = i;
}

int find(int x)
{
	if (x != table[x])
		return table[x] = find(table[x]);
	return x;
}

void Union(int a, int b)
{
	table[find(a)] = find(b);
}


int main()
{
	int n, m, i;
	cin >> n >> m;
	init();
	for (i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		Union(a, b);
		e[a]++;
		e[b]++;
	}

	int current = find(1);
	for (i = 1; i <= n; ++i)
	{
		if (find(i) != current)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	for (i = 1; i <= n; ++i)
	{
		if (e[i]%2 == 1)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	cout << 1 << endl;

	return 0;
}
*/


/*
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int i, n, l, r;
	vector<int> v;
	cin >> n;
	v.resize(n+1);
	for (i = 1; i <= n; ++i)
		cin >> v[i];
	cin >> l >> r;

	if (v[l] == 0)
		printf("ERROR: T[%d] is NULL\n", l);
	else if (v[r] == 0)
		printf("ERROR: T[%d] is NULL\n", r);
	else
	{
		if (l < r)
			swap(l, r);
		if (l != 1)
		{
			do
			{
				l = l / 2;
				if (l < r)
					swap(l, r);
				if (v[l] == 0)
				{
					printf("ERROR: T[%d] is NULL\n", l);
					return 0;
				}
				else if (v[r] == 0)
				{
					printf("ERROR: T[%d] is NULL\n", r);
					return 0;
				}
			} while (l != r);
		}

		printf("%d %d", l, v[l]);
	}
	return 0;
}
*/

/*
vector<int> mid, last;
int current;

struct Tree
{
	int value;
	Tree *left, *right;
	Tree(int v) : value(v), left(NULL), right(NULL) {}
};

int find(int x)
{
	int i;
	for (i = 0; i < mid.size(); ++i)
		if (mid[i] == x)
			return i;
}

Tree* genTree(int v, int l, int r)
{
	Tree *ret = new Tree(v);
	current--;

	if (l >= r)
		return ret;
	int mid = find(v);
	if (current >= 0 && mid != r)
		ret->right = genTree(last[current], mid + 1, r);
	if (current >= 0 && mid != l)
		ret->left = genTree(last[current], l, mid - 1);
	return ret;
}

void visit(Tree *p)
{

	cout << ' ' << p->value;
	if (p->left)
		visit(p->left);
	if (p->right)
		visit(p->right);
}

int main()
{
	int i, n, t;
	cin >> n;
	mid.resize(n);
	last.resize(n);
	for (i = 0; i < n; ++i)
		cin >> last[i];
	for (i = 0; i < n; ++i)
		cin >> mid[i];

	current = last.size() - 1;
	Tree *root = genTree(last[current], 0, current);

	cout << "Preorder:" ;
	visit(root);

	return 0;
}
*/

/*
vector<int> e[10000];
int			visited[10000] = { 0 };
int			gtao[10000] = { 0 };
int			gS[10000] = { 0 };

struct family
{
	int min, people;
	float tao, s;
	family(int m, int p, float t, float ss) : min(m), people(p), tao(t), s(ss) {}
};

vector<family> vfamily;

bool operator<(const family f1, const family f2)
{
	if (abs(f1.s - f2.s) > 1e-8)
		return f1.s > f2.s;
	else
		return f1.min < f2.min;
}

void addpath(int a, int b)
{
	int i;
	for (i = 0; i < e[a].size(); ++i)
		if (e[a][i] == b)
			return;

	visited[a] = 0;
	visited[b] = 0;
	e[a].push_back(b);
	e[b].push_back(a);
}

void bfs()
{
	int min, people, tao, s;
	min = 0x7fffffff;
	people = tao = s = 0;

	int i, j;
	for (i = 0; i < 10000; ++i)
	{
		min = 0x7fffffff;
		people = tao = s = 0;

		if (!visited[i])
		{
			queue<int> q;
			q.push(i);

			while (!q.empty())
			{
				int now = q.front();
				q.pop();

				if (visited[now])
					continue;
				visited[now] = 1;
				if (now < min)
					min = now;
				people++;
				tao += gtao[now];
				s += gS[now];

				for (j = 0; j < e[now].size(); ++j)
				{
					int v = e[now][j];
					if (!visited[v])
						q.push(v);
				}
			}
			vfamily.push_back(family(min, people, 1.0*tao / people, 1.0*s / people));
		}
	}
}

int main()
{
	int n, i, j;

	cin >> n;
	fill(visited, visited + 10000, 1);

	for (i = 0; i < n; ++i)
	{
		int id, parent1, parent2, cc, child, tao, s;
		cin >> id >> parent1 >> parent2 >> cc;

		if (parent1 != -1)
			addpath(id, parent1);
		if (parent2 != -1)
			addpath(id, parent2);

		for (j = 0; j < cc; ++j)
		{
			cin >> child;
			addpath(id, child);
		}

		visited[id] = 0;

		cin >> tao >> s;
		gtao[id] = tao;
		gS[id] = s;
	}

	bfs();
	sort(vfamily.begin(), vfamily.end());

	cout << vfamily.size() << endl;
	for (i = 0; i < vfamily.size(); ++i)
		printf("%04d %d %.3f %.3f\n", vfamily[i].min, vfamily[i].people, vfamily[i].tao, vfamily[i].s);

	return 0;
}
*/


/*
int main()
{
	char table[30][30][30];
	int  count[30] = { 0 };
	char buffer[30];
	int i, j, len, first, n;
	
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", buffer);
		len = strlen(buffer);
		strcpy(table[len][count[len]++], buffer);
	}

	first = 1;
	for (i = 1; i < 30; ++i)
	{
		int c = count[i];
		for (j = 0; j < c; ++j)
		{
			if (!first)
				putchar(' ');
			else
				first = 0;
			printf("%s", table[i][j]);
		}
	}

	return 0;
}
*/

/*
int main()
{
	int n, i, j;
	string in;
	set<string> s;
	map<string, int> m;

	cin >> n;
	for (i = 0; i < n; ++i)
	{
		getline(cin, in);
		if (in != "")
		{
			s.insert(in);
			for (j = 0; j < in.size(); ++j)
				if (isupper(in[j]))
					in[j] = tolower(in[j]);
			m[in]++;
		}
		else
			i--;
	}
	
	set<string>::iterator it = s.begin();
	for (; it != s.end(); ++it)
	{
		string tmp;
		tmp = *it;
		for (i = 0; i < tmp.size(); ++i)
			if (isupper(tmp[i]))
				tmp[i] = tolower(tmp[i]);
		printf("%s %.4lf%%\n", it->c_str(), 100.0*(double(m[tmp]) / n));
	}

	return 0;
}
*/
/*
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cctype>
using namespace std;

struct Tree
{
	int value;
	Tree *left, *right;
	Tree(int v) : value(v), left(NULL), right(NULL) {}
};

void insert(Tree *p, int v)
{
	if (v <= p->value)
	{
		if (p->right != NULL)
			insert(p->right, v);
		else
			p->right = new Tree(v);
	}
	else
	{
		if (p->left != NULL)
			insert(p->left, v);
		else
			p->left = new Tree(v);
	}
}

bool wanquan(Tree *p)
{
	bool ret = true;
	
	if ((p->left && !p->right) || (!p->left && p->right))
		return false;

	if (p->left)
		ret = wanquan(p->left);
	if (ret && p->right)
		ret = wanquan(p->right);

	return ret;
}

bool first = true;
void visit(Tree *p)
{
	queue<Tree*> q;

	q.push(p);

	while (!q.empty())
	{
		p = q.front();
		q.pop();

		if (!first)
			putchar(' ');
		else
			first = false;
		cout << p->value;
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
}

int main()
{
	int  t, n;
	cin >> n >> t;
	Tree *root = new Tree(t);
	n--;
	while (n--)
	{
		cin >> t;
		insert(root, t);
	}

	visit(root);
	cout << endl;
	if (wanquan(root))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
*/

/*
int main()
{
	// 一般的二维数组
	int table[100][100];

	// 下面两个操作都是合法的，因为内存已经分配了
	table[5][5] = 0;
	table[99][99] = 0;

	// 与之对应的动态二维数组有两种

	vector<vector<int>> dyn1;
	vector<int>         dyn2[100];

	// 此时 dy1,是一点内存都没分配的，
	// dy2 则是一个容量为100的 vector<int> 的数组
	// 此时
	// 对 dyn1 进行下标访问时非法的，
	// 对dyn2 则是合法的
	//dyn1[2].push_back(1);   // 非法
	//dyn2[4].push_back(2);   // 合法

	//可以这样为 dyn1 分配内存，这样dyn1的第一维就是一个长度为100的 vector<int>数组
	//dyn1.resize(100);
	//dyn1[2].push_back(1);   // 合法
	

	// 现在两者基本等价
	// 也就是说，dyn1 是长度和宽度都可以 动态决定的
	// dyn2 的长度是 100， 但宽度是可以 动态决定的

	// 实例
	// dyn2 分别赋值为长度为 1,2,3 ... n 的元素
	dyn2[4].clear();
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j <= i; ++j)
			dyn2[i].push_back(j);

	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < dyn2[i].size(); ++j)
			cout << dyn2[i][j] << ' ';
		cout << endl;
	}

	// 这种情况下， dyn2 中每个 vector<int> 分配的内存可以认为是不相等的
	
}
*/



/*
int m, n, l, t;

int map[61][1300][130] = { 0 };

struct point
{
	int i, j, k;
	point(int ii, int jj, int kk) : i(ii), j(jj), k(kk) {}
};

int bfs(int i, int j, int k)
{
	int ret = 0;
	if (!map[i][j][k])
		return 0;

	queue<point> q;
	q.push(point(i, j, k));

	while (!q.empty())
	{
		point cur = q.front();
		q.pop();

		if (!map[cur.i][cur.j][cur.k])
			continue;
		ret++;
		map[cur.i][cur.j][cur.k] = 0;

		if (cur.i != 0)
			q.push(point(cur.i - 1, cur.j, cur.k));
		if (cur.i != l - 1)
			q.push(point(cur.i + 1, cur.j, cur.k));
		if (cur.j != 0)
			q.push(point(cur.i, cur.j - 1, cur.k));
		if (cur.j != m - 1)
			q.push(point(cur.i, cur.j + 1, cur.k));
		if (cur.k != 0)
			q.push(point(cur.i, cur.j, cur.k - 1));
		if (cur.k != n - 1)
			q.push(point(cur.i, cur.j, cur.k + 1));
	}
	return ret;
}


int get()
{
	int ret = 0, i, j, k;
	for (i = 0; i < l; ++i)
		for (j = 0; j < m; ++j)
			for (k = 0; k < n; ++k)
			{
				int tmp = bfs(i, j, k);
				if (tmp >= t)
					ret += tmp;
			}
	return ret;
}

int main()
{
	int i, j, k;
	cin >> m >> n >> l >> t;

	for (i = 0; i < l; ++i)
		for (j = 0; j < m; ++j)
			for (k = 0; k < n; ++k)
			{
				scanf("%d", &map[i][j][k]);
			}

	cout << get() << endl;
	return 0;
}
*/

/*
#include <iostream>  
#include <string>  
using namespace std;

int maxLen = 0;

void LPS(const string &str)
{
	int len = str.length();

	for (int i = 0; i<len; i++)
	{
		for (int j = len - 1; j >= i; j--)
		{
			if (str[j] == str[i])
			{
				int start, end;
				for (start = i, end = j; start <= end; start++, end--)
					if (str[start] != str[end])
						break;

				if (end <= start)
					maxLen = (maxLen >= j - i + 1) ? maxLen : j - i + 1;

			}

		}

	}

}

int main()
{
	string str;
	getline(cin, str);

	LPS(str);

	cout << maxLen << endl;

	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Tree;
typedef Tree* pointer;

struct Tree
{
	int number;
	pointer left, right;
	Tree(int n) : number(n), left(NULL), right(NULL) {}
};

vector<int> mid, last;
int current;

int find(int number)
{
	int i;
	for (i = 0; i < mid.size(); ++i)
		if (number == mid[i])
			return i;

	return -1;
}

pointer genTree(int num, int l, int m, int r)
{
	pointer ret = new Tree(num);
	current--;
	if (current < 0 || l >= r)
		return ret;

	if (current >= 0 && m != r)
		ret->right = genTree(last[current], m + 1, find(last[current]), r);
	if (current >= 0 && m != l)
		ret->left = genTree(last[current], l, find(last[current]), m - 1);

	return ret;
}



int first = 1;
void visit(pointer tree)
{
	queue<pointer> q;
	q.push(tree);

	while (!q.empty())
	{
		tree = q.front();
		q.pop();

		if (!first)
			cout << ' ';
		first = 0;
		cout << tree->number;
		if (tree->left != NULL)
			q.push(tree->left);
		if (tree->right != NULL)
			q.push(tree->right);
	}
}


int main()
{
	int n, i, t;
	cin >> n;
	for (i = 0; i <n; ++i)
	{
		cin >> t;
		last.push_back(t);
	}
	for (i = 0; i <n; ++i)
	{
		cin >> t;
		mid.push_back(t);
	}

	current = last.size() - 1;
	pointer root = genTree(last[current], 0, find(last[current]), current);
	visit(root);
	putchar('\n');
	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Tree
{
	char c;
	struct Tree *left, *right;
	Tree(char cc) : c(cc), left(NULL), right(NULL) {}
};
typedef Tree* pointer;
string pre, mid;
int current;

int getHeight(pointer p)
{
	int height = 0;
	if (p->left == NULL && p->right == NULL)
		return 1;

	if (p->left != NULL)
		height = max(height, getHeight(p->left) + 1);
	if (p->right != NULL)
		height = max(height, getHeight(p->right) + 1);

	return height;
}

pointer genTree(char c, int l, int r)
{
	pointer ret = new Tree(c);
	current++;
	if (l >= r || current >= pre.size())
		return ret;
	int m = mid.find(c);
	if (m != l)
		ret->left = genTree(pre[current], l , m - 1);
	if (current >= pre.size())
		return ret;
	if (m != r)
		ret->right = genTree(pre[current], m + 1, r);

	return ret;
}

int main()
{

	int n;
	cin >> n >> pre >> mid;

	current = 0;
	pointer root = genTree(pre[0], 0 , pre.size() - 1);
	cout << getHeight(root) << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
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

	for (i = 0; i < n; ++i)
		find(i);

	int count[MAX] = { 0 };
	for (i = 0; i < n; ++i)
		count[table[i]]++;

	int *c = max_element(count, (count + n));
	cout << *c << endl;
	return 0;
}
*/

/*
struct msg
{
	int level;
	string name;
	msg(int l, string n) : level(l), name(n) {}
};


bool operator<(const msg m1, const msg m2)
{
	return m1.level > m2.level;
}


int main()
{
	priority_queue<msg> q;
	int n;
	cin >> n;
	char buffer[10];
	while (n--)
	{
		char name[15];
		int level;
		scanf("%s", buffer);
		if (buffer[0] == 'P')
		{
			scanf(" %s %d", name, &level);
			q.push(msg(level, name));
		}
		else
		{
			if (!q.empty())
			{
				const char *p = q.top().name.c_str(); 
				printf("%s\n", p);
				q.pop();
			}
			else
				cout << "EMPTY QUEUE!" << endl;
		}
	}
	return 0;
}
*/

/*
struct Tree
{
	char c;
	struct Tree *left, *right;
	Tree(char cc) : c(cc), left(NULL), right(NULL) {}
};
typedef Tree* pointer;
string pre, mid;
int current;

int getHeight(pointer p)
{
	int height = 0;
	if (p->left == NULL && p->right == NULL)
		return 1;

	if (p->left != NULL)
		height = max(height, getHeight(p->left) + 1);
	if (p->right != NULL)
		height = max(height, getHeight(p->right) + 1);

	return height;
}

pointer genTree(char c, int l, int m, int r)
{
	pointer ret = new Tree(c);
	current++;
	if (l >= r || l >= m || current >= pre.size())
		return ret;

	ret->left = genTree(pre[current], l, mid.find(pre[current]), m - 1);
	if (current >= pre.size())
		return ret;
	ret->right = genTree(pre[current], m + 1, mid.find(pre[current]), r);

	return ret;
}

int main()
{
	
	int n;
	cin >> n >> pre >> mid;

	current = 0;
	pointer root = genTree(pre[0], 0, mid.find(pre[0]), pre.size()-1);
	cout << getHeight(root) << endl;
	return 0;
}
*/

/*
int main()
{
	int n, i, ma, m;
	ma = m = -0x7fffffff;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		if (t > ma)
		{
			ma = t;
			m = i;
		}
	}
	cout << ma << ' ' << m << endl;
	return 0;
}
*/

/*
int main()
{
	long long a;
	double S,high;
	long long n;
	cin >> a >>n;
	S = (2 * a * (1 - pow(1 / 2.0, n))-a)*2 + a;
	high = a*pow(1 / 2.0, n);
	printf("%.1lf %.1lf\n", S, high);
	return 0;
}
*/

/*
int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	
	while (a % b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return b;
}

int main()
{
	int a, b,c;
	cin >> a >> b;
	c = gcd(a, b);
	cout << c << ' ' << a*b / c << endl;
	return 0;
}
*/

/*
int dat[15][15];

int main()
{
	int n, i, x, y;
	int arrow[4][2] = {
		{1,0}, {0,1},{-1,0}, {0,-1}
	};
	int dir = 0;
	cin >> n;
	int left, top, right, bottom;

	
	left = top = -1;
	right = bottom = n;
	x = y = 0;
	for (i = 0; i < n*n; ++i)
	{
		dat[x][y] = i + 1;
		int new_x, new_y;
		new_x = x + arrow[dir][0];
		new_y = y + arrow[dir][1];
		if ( new_x > left && new_x < right && new_y > top && new_y < bottom)
		{
			x = new_x;
			y = new_y;
		}
		else
		{
			if (dir == 0)
				top +=1;
			if (dir == 1)
				right -= 1;
			if (dir == 2)
				bottom -= 1;
			if (dir == 3)
				left += 1;

			dir = (dir + 1) % 4;
			x = x + arrow[dir][0];
			y = y + arrow[dir][1];
		}
	}

	for (y = 0; y < n; ++y)
	{
		for (x = 0; x < n; ++x)
		{
			printf("%3d", dat[x][y]);
		}
		putchar('\n');
	}
	return 0;
}
*/


/*
int dat[20][20];

int maxx[20];
int minn[20];

int main()
{
	int n, i, j,m;
	cin >> n;
	
	for (i = 0; i < n; ++i)
	{
		m = -1;
		for (j = 0; j < n; ++j)
		{
			int t;
			cin >> t;
			dat[i][j] = t;
			if (t > m)
			{
				m = t;
			}
		}
		maxx[i] = m;
	}
	
	for (i = 0; i < n; ++i)
	{
		m = 0x7fffffff;
		for (j = 0; j < n; ++j)
		{
			if (dat[j][i] < m)
			{
				m = dat[j][i];
				m = dat[j][i];
			}
		}
		minn[i] = m;
	}

	int find = 0;
	int x, y;
	for (i = 0; i < n && !find; ++i)
		for (j = 0; j < n && !find; ++j)
		{
			if ( dat[i][j] == maxx[i] && dat[i][j] == minn[j])
			{
				x = i, y = j;
				find = 1;
				break;
			}
		}

	if (find)
		cout << x << ' ' << y << endl;
	else
		cout << "NONE" << endl;
}
*/


/*
int main()
{
	int n, i, j, ret;
	cin >> n;
	ret = 0;
	for(i=0; i < n; ++i)
		for (j = 0; j < n; ++j)
		{
			int t;
			cin >> t;
			if ((n - i - 1) != j && j != n - 1 && i != n - 1)
			{
				ret += t;
			}
		}
	cout << ret << endl;
}
*/

/*
#define EPS (1e-8)

float round1(float f)
{
	int t;
	if (f > 0)
		t = (f + 0.05) * 10.0;
	else
		t = (f - 0.05) * 10.0;
	return t / 10.0;
}

int main()
{
	float x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	float x, y;
	x = round1(x1 + x2);
	y = round1(y1 + y2);
	
	bool flag1 = false, flag2 = false;

	printf("(%.1f+%.1fi) + (%.1f+%.1fi) = " ,x1, y1, x2, y2);
	if (abs(x) > EPS)
	{
		flag1 = true;
		flag2 = true;
		printf("%.1f", x);
	}
	if (abs(y) > EPS)
	{
		if (y > 0 && flag1)
			putchar('+');
		flag2 = true;
		printf("%.1fi", y);
	}
	if (!flag2)
		printf("0.0");
	putchar('\n');

	flag1 = flag2 = false;
	x = round1(x1 - x2);
	y = round1(y1 - y2);
	printf("(%.1f+%.1fi) - (%.1f+%.1fi) = ", x1, y1, x2, y2);
	if (abs(x) > EPS)
	{
		flag1 = true;
		flag2 = true;
		printf("%.1f", x);
	}
	if (abs(y) > EPS)
	{
		if (y > 0 && flag1)
			putchar('+');
		flag2 = true;
		printf("%.1fi", y);
	}
	if (!flag2)
		printf("0.0");
	putchar('\n');

	flag1 = flag2 = false;
	x = round1(x1*x2 - y1*y2);
	y = round1(x1*y2 + x2*y1);
	printf("(%.1f+%.1fi) * (%.1f+%.1fi) = ", x1, y1, x2, y2);
	if (abs(x) > EPS)
	{
		flag1 = true;
		flag2 = true;
		printf("%.1f", x);
	}
	if (abs(y) > EPS)
	{
		if (y > 0 && flag1)
			putchar('+');
		flag2 = true;
		printf("%.1fi", y);
	}
	if (!flag2)
		printf("0.0");
	putchar('\n');

	flag1 = flag2 = false;
	x = round1((x1*x2 + y1*y2) / (x2*x2 + y2*y2));
	y = round1((-x1*y2 + x2*y1) / (x2*x2 + y2*y2));
	printf("(%.1f+%.1fi) / (%.1f+%.1fi) = ", x1, y1, x2, y2);
	if (abs(x) > EPS)
	{
		flag1 = true;
		flag2 = true;
		printf("%.1f", x);
	}
	if (abs(y) > EPS)
	{
		if (y > 0 && flag1)
			putchar('+');
		flag2 = true;
		printf("%.1fi", y);
	}
	if (!flag2)
		printf("0.0");
	putchar('\n');

	return 0;
}
*/

/*
struct stu
{
	string name, birth, sex, guhua, phone;
};

int main()
{
	int n, i;
	cin >> n;
	vector<stu> v;
	v.resize(n);
	for (i = 0; i < n; ++i)
		cin >> v[i].name >> v[i].birth >> v[i].sex >> v[i].guhua >> v[i].phone;

	cin >> n;
	for (i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		if (k >= v.size())
			cout << "Not Found" << endl;
		else
			cout << v[k].name << ' ' << v[k].guhua << ' ' << v[k].phone << ' ' << v[k].sex << ' ' << v[k].birth << endl;
	}

	return 0;
}
*/

/*
struct stu
{
	string number, name;
	int a, b, c, total;
};

int main()
{
	int n, i;
	cin >> n;
	vector<stu> v;
	v.resize(n);
	for (i = 0; i < n; ++i)
	{
		cin >> v[i].number >> v[i].name >> v[i].a >> v[i].b >> v[i].c;
		v[i].total = v[i].a + v[i].b + v[i].c;
	}
	sort(v.begin(), v.end(), [](const stu s1, const stu s2) {
		return s1.total > s2.total;
	});
	cout << v[0].name << ' ' << v[0].number << ' ' <<  v[0].total << endl;

	return 0;
}
*/


/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	double x1, y1, x2, y2, x,y;
	cin >> x1 >> y1 >> x2 >> y2;
	x = x1 + x2;
	y = y1 + y2;
	int t;
	if (x > 0)
	{
		t = (x + 0.05) * 10;
		x = t / 10.0;
	}
	else
	{
		t = (x - 0.05) * 10;
		x = t / 10.0;
	}
	if (y > 0)
	{
		t = (y + 0.05) * 10;
		y = t / 10.0;
	}
	else
	{
		t = (y - 0.05) * 10;
		y = t / 10.0;
	}

	printf("(%.1f, %.1f)\n", x, y);
	return 0;
}
*/

/*
int main()
{
	int h, m, s, n;
	scanf("%d:%d:%d", &h, &m, &s);
	scanf("%d", &n);

	int nh, nm, ns;
	nh = nm = ns = 0;
	ns = n % 60;
	nm = n / 60;
	nh = nm / 60;

	h += nh;
	m += nm;
	s += ns;

	if (s >= 60)
	{
		s -= 60;
		m++;
	}
	if (m >= 60)
	{
		m -= 60;
		h++;
	}
	h = h % 24;
	printf("%02d:%02d:%02d", h, m, s);
	return 0;
}
*/

/*
int main()
{
	int table[11][20] = {
		{1},
		{1,1}
	};

	int i, j,n;
	cin >> n;
	for (i = 2; i < 11; ++i)
	{
		table[i][0] = 1;
		for (j = 1; j < i; ++j)
			table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
		table[i][j] = 1;
	}

	for (i = 0; i < n; ++i)
	{
		cout << string(n - i - 1, ' ');
		for (j = 0; j <= i; ++j)
			printf("%4d", table[i][j]);
		cout << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n, a, b, c, d;
	cin >> n;
	a = n / 1000;
	b = (n % 1000) / 100;
	c = (n % 100) / 10;
	d = (n % 10);
	a = (a + 9) % 10;
	b = (b + 9) % 10;
	c = (c + 9) % 10;
	d = (d + 9) % 10;
	swap(a, c);
	swap(b, d);
	cout << "The encrypted number is ";
	if (a == 0)
		cout << 0;
	if (b == 0 && a == 0)
		cout << 0;
	if (c == 0 && a == 0 && b == 0)
		cout << 0;
	cout << a * 1000 + b * 100 + c * 10 + d << endl;
	return 0;
}
*/

/*
int main()
{
	vector<string> v;
	v.resize(5);
	int i;
	for (i = 0; i < 5; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	cout << "After sorted:\n";
	for (i = 0; i < 5; ++i)
		cout << v[i] << endl;
	return 0;
}
*/

/*
int main()
{
	int i, n;
	queue<char> q;
	string str;
	getline(cin, str);
	cin >> n;

	for (i = 0; i < str.size(); ++i)
		q.push(str[i]);

	for (i = 0; i < n; ++i)
	{
		q.push(q.front());
		q.pop();
	}
	while (!q.empty())
	{
		putchar(q.front());
		q.pop();
	}

	return 0;
}
*/

/*
int main()
{
	int i, n, k,c;
	cin >> n >> k;
	vector<string> v;
	while (n--)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	bool flag = true;
	c = 0;
	while (flag)
	{
		flag = false;

		for (i = 0; i < v.size() - 1; ++i)
		{
			if (v[i] > v[i + 1])
			{
				swap(v[i], v[i + 1]);
				flag = true;
			}
		}
		c++;
		if (c == k)
			break;
	}
	for (i = 0; i < v.size(); ++i)
		cout << v[i] << endl;

	return 0;
}
*/

/*
int table[10];

int find_min()
{
	for (int i = 0; i < 10; ++i)
		if (table[i] > 0)
			return i;
}

int main()
{
	int n, i, t, zero;
	n = 0;
	for (i = 0; i < 10; ++i)
	{
		cin >> t;
		table[i] = t;
		n += t;
	}

	zero = table[0];
	table[0] = 0;
	t = find_min();
	putchar(t + '0');
	n--;
	table[0] = zero;
	table[t]--;

	while (n--)
	{
		t = find_min();
		putchar(t+ '0');
		table[t]--;
	}

	return 0;
}
*/

/*
int main()
{
	int a, b;
	bool aa, bb;
	aa = bb = true;
	string str;
	cin >> str;
	int i;

	for (i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]) && str[i] != '-')
			aa = false;
	}

	if (aa)
	{
		int t = atoi(str.c_str());
		if (t > 1000 || t <= 0)
			aa = false;
		else
			a = t;
	}

	getline(cin, str);
	for (i = 0; i < str.size(); ++i)
	{
		if (str[0] == ' ' && i == 0)
			i++;
		if (!isdigit(str[i]) && str[i] != '-')
			bb = false;
	}

	if (bb)
	{
		int t = atoi(str.c_str());
		if (t > 1000 || t <= 0)
			bb = false;
		else
			b = t;
	}
	
	if (aa)
		cout << a << ' ';
	else
		cout << "? ";
	cout << "+ ";
	if (bb)
		cout << b << ' ';
	else
		cout << "? ";
	cout << "= ";
	if (aa && bb)
		cout << a + b << endl;
	else
		cout << '?' << endl;
	return 0;
}
*/


/*
int main()
{
	stack<string> s;
	string in;
	while (cin >> in)
		s.push(in);
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
		if (!s.empty())
			cout << ' ';
	}
	return 0;
}
*/

/*
bool isnothex(int c)
{
	return !((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

int hex2int(char c)
{
	if (isdigit(c))
		return c - '0';
	if (isupper(c))
		return c - 'A' + 10;
	else
		return c - 'a' + 10;
}

int main()
{
	string in;
	getline(cin, in);
	in = in.substr(0, in.find('#'));
	int fu, i, flag;
	string::iterator it;
	fu = 0;
	flag = 0;
	for (it = in.begin(); it != in.end(); )
	{
		if (*it == '-')
		{
			if (!flag)
				fu = 1;
		}
		if (isnothex(*it))
			it = in.erase(it);
		else
		{
			flag = 1;
			it++;
		}
	}
	long long ret = 0;
	for (i = 0; i < in.size(); ++i)
	{
		ret += hex2int(in[i]) * pow(16, in.size() - 1 - i);
	}
	if (fu)
		ret = -ret;
	cout << ret << endl;
}
*/

/*
int main()
{
	map<int,int> m;
	int n,t;
	cin >> n;
	while (n--)
	{
		cin >> t;
		m[t]++;
	}
	int number, count;
	number = 0, count = 0;
	map<int, int>::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		if (it->second > count)
		{
			number = it->first;
			count = it->second;
		}
	}
	cout << number << ' ' << count << endl;
	return 0;
}
*/

/*
bool is_prim(int x)
{
	int end = sqrt(x);

	for (int i = 2; i <= end; ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int i, n, c;
	cin >> n;
	c = 0;
	for (i = 2; i <= n; ++i)
	{
		int t = (1 << i) - 1;
		if (is_prim(t))
		{
			c++;
			cout << t << endl;
		}
	}
	if (!c)
		cout << "None" << endl;
	return 0;
}
*/

/*
bool is_prim(int x)
{
	int end = sqrt(x);

	for (int i = 2; i <= end; ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n, p, q;
	cin >> n;
	for (int i = 2; i <= n / 2; ++i)
	{
		if (is_prim(i) && is_prim(n - i))
		{
			p = i;
			q = n - i;
			break;
		}
	}
	cout << n << " = " << p << " + " << q << endl;

	return 0;
}
*/
/*
int main()
{
	char key[10][10] = {
		"0 ","1,.?!","2ABC","3DEF","4GHI","5JKL",
		"6MNO","7PQRS","8TUV","9WXYZ"
	};
	int length[10];
	for (int i = 0; i < 10; ++i)
		length[i] = strlen(key[i]);
	string in;
	while (cin >> in)
	{
		int k, c;
		k = in[0]-'0';
		c = (in.size()-1) % length[k];
		putchar(key[k][c]);
	}

	return 0;
}
*/

/*
int main()
{
	int n, u, d;
	cin >> n >> u >> d;

	int high, time;
	high = time = 0;

	while (high < n)
	{
		time++;
		high += u;
		if (high >= n)
			break;
		high -= d;
		time++;
	}
	cout << time << endl;

	return 0;
}
*/

/*
int main()
{
	int a, b, n, ahe,bhe, dao;
	cin >> a >> b >> n;

	ahe = bhe = dao = 0;

	while (n--)
	{
		int jiahan, jiahua, yihan, yihua;
		cin >> jiahan >> jiahua >> yihan >> yihua;
		
		int han = jiahan + yihan;
		if (jiahua == han && yihua == han)
			continue;
		if (yihua == han)
		{
			b--;
			bhe++;
			if (b < 0)
			{
				dao = 2;
				break;
			}
		}
		if (jiahua == han)
		{
			a--;
			ahe++;
			if (a < 0)
			{
				dao = 1;
				break;
			}
		}
	}

	if (dao == 1)
	{
		cout << 'A' << endl;
		cout << bhe << endl;
	}
	else
	{
		cout << 'B' << endl;
		cout << ahe << endl;
	}
	return 0;
}
*/


/*
int main()
{
	int i, j, k, n,c;
	
	bool flag = true;
	cin >> n;
	c = 0;
	for(i = 1; i <= 100 && flag; i++)
		for(j=1; j <=100 && flag; ++j)
			for (k = 1; k <= 100 && flag; ++k)
			{
				if (c == n)
					flag = false;
				if (i + j + k == 100 && i * 5 + j * 2 + k == 150)
				{
					cout << i << ' ' << j << ' ' << k << endl;
					++c;
				}
			}

	return 0;
}
*/

/*
int main()
{
	int tuzi, wugui;
	int sleep;
	int current, t;

	cin >> t;
	current = tuzi = wugui = sleep = 0;

	while (current < t)
	{
		current++;
		wugui += 3;
		if (sleep == 0)
		{
			tuzi += 9;
			if (current % 10 == 0 && tuzi > wugui)
				sleep = 30;
		}
		else
		{
			sleep--;
		}
	}

	if (wugui > tuzi)
		cout << "@_@ " << wugui << endl;
	else if (wugui < tuzi)
		cout << "^_^ " << tuzi << endl;
	else
		cout << "-_- " << tuzi << endl;

	return 0;
}
*/

/*
int main()
{
	char c;
	int h, w;
	cin >> c >> h;
	w = h;

	for (int i = 0; i < h / 2 + 1; ++i)
	{

		cout << string(h/2-i, ' ');
		if (i == 0)
			cout << char(c) << endl;
		else
		{
			cout << char(c + i);
			cout << string(1 + 2 * (i - 1), ' ');
			cout << char(c + i) << endl;
		}
	}
	for (int i = 0; i < h / 2; ++i)
	{
		cout << string(i + 1, ' ');
		if (i == h/2 -1)
			cout << char(c + h / 2 - 1 - i) << endl;
		else
		{
			cout << char(c + h / 2 - 1 - i);
			cout << string(1 + 2* (h / 2 - i-2), ' ');
			cout << char(c + h / 2 - 1 - i) << endl;
		}
	}

	return 0;
}
*/

/*
int main()
{
	string str;
	int i, j, n;
	while (1)
	{
		char c;
		scanf("%c", &c);
		if (c == '.')
			break;
		str += c;
	}

	i = str.find_first_of(' ');
	n = j = 0;
	if (i == string::npos && str.size() != 0)
		cout << str.size() << endl;
	else
	{
		while (i != string::npos)
		{
			if (i - j != 0)
			{
				if (n > 0)
					cout << ' ';
				cout << i - j;
				n++;
			}
			j = i + 1;
			i = str.find_first_of(' ', j);
		}
		if (str.size() - j != 0)
		{
			if (n > 0)
				cout << ' ';
			cout << str.size() - j;
		}
		cout << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int count = 0, count_0 = 0;
	char n;
	while ((n = getchar()) != '.')
	{
		if (n != ' ')
		{
			if (count > 0 && count_0 > 0)
			{
				printf("%d ", count);
				count = 0;
			}
			count++;
			count_0 = 0;
			continue;
		}
		if (n == ' ')
			count_0++;
	}
	if (count > 0)
		printf("%d\n", count);
	else
		printf("\n");

	return 0;
}
*/

/*
int main()
{
	char pinyin[10][10] = {
		"ling","yi","er","san","si","wu",
		"liu", "qi","ba","jiu"
	};
	int a,b;
	cin >> a;
	b = a > 0 ? a : -a;
	stack<string> s;
	if (b == 0)
		s.push("ling");
	while (b)
	{
		s.push(pinyin[b % 10]);
		b /= 10;
	}
	if (a < 0)
		s.push("fu");
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
		if (!s.empty())
			cout.put(' ');
	}
	cout << endl;

	return 0;
}
*/

/*
int main()
{
	int lo, hi;
	cin >> lo >> hi;

	if (lo > hi)
		cout << "Invalid." << endl;
	else
	{
		cout << "fahr celsius" << endl;
		while (lo <= hi)
		{
			cout << lo << setw(6) << fixed <<  setprecision(1) << (5 * float(lo - 32) / 9.0)<< endl;
			lo += 2;
		}
	}
}
*/

/*
int main()
{
	int a, b, c, d;
	cin >> a >> b;
	c = (b / 100 - a / 100);
	d = (b % 100 - a % 100);

	if (d < 0)
	{
		c--;
		d += 60;
	}
	printf("%02d:%02d\n", c, d);
	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	cout << "2^" << n << " = " << (1 << n) << endl;

	return 0;
}
*/

/*
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	if (a % b == 0)
		printf("%d / %d = %d\n", a, b, a / b);
	else
		printf("%d / %d = %.2f\n", a, b, float(a)/ b);

	return 0;
}
*/

/*
int main()
{
	float cm;
	int foot, inch;
	cin >> cm;
	cm /= 100;
	cm /= 0.3048;
	foot = int(cm);
	inch = (cm - int(cm))*12;
	cout << foot << ' ' << inch << endl;

	return 0;
}
*/

/*
int main()
{
	float a, b;
	int c;
	char d;
	cin >> a >> c >> d >> b;
	cout << fixed << setprecision(2)  << d << ' ' << c << ' ' << a << ' ' << b << endl;

	return 0;
}
*/

/*
int main()
{
	int a, b;
	cin >> a >> b;
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%d / %d = %d\n", a, b, a / b);

	return 0;
}
*/

/*
int m, n, l, t;
int g[62][1300][130] = { 0 };

struct point
{
	int i, j, k;
	point(int ii, int jj, int kk) : i(ii), j(jj), k(kk) {}
};

int bfs(int i, int j, int k)
{
	int ret = 0;
	if (!g[i][j][k])
		return 0;

	queue<point> q;
	q.push(point(i, j, k));
	while (!q.empty())
	{
		point now = q.front(); q.pop();
		if (!g[now.i][now.j][now.k])
			continue;
		g[now.i][now.j][now.k] = 0;
		ret += 1;
		if (now.i != 0)
			q.push(point(now.i - 1, now.j, now.k));
		if (now.i != l - 1)
			q.push(point(now.i + 1, now.j, now.k));
		if (now.j != 0)
			q.push(point(now.i, now.j - 1, now.k));
		if (now.j != m - 1)
			q.push(point(now.i, now.j + 1, now.k));
		if (now.k != 0)
			q.push(point(now.i, now.j, now.k - 1));
		if (now.k != n - 1)
			q.push(point(now.i, now.j, now.k + 1));
	}

	return ret;
}

int get()
{
	int i, j, k, ans;
	ans = 0;
	for (i = 0; i < l; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			for (k = 0; k < n; ++k)
			{
				int tmp = bfs(i, j, k);
				if (tmp >= t)
					ans += tmp;
			}
		}
	}
	return ans;
}

int main()
{
	int i, j, k;
	cin >> m >> n >> l >> t;
	for (i = 0; i < l; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			for (k = 0; k < n; ++k)
			{
				cin >> g[i][j][k];
			}
		}
	}
	cout << get() << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m, k;

vector<int> e[505];
int visited[505];

int bfs()
{
	int i, j, ans = 0;
	fill(visited, visited + 505, 0);

	for (i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			ans++;
			queue<int> q;
			q.push(i);
			visited[i] = 1;
			while (!q.empty())
			{
				int now = q.front(); q.pop();

				for (j = 0; j < e[now].size(); ++j)
				{
					int v = e[now][j];
					if (visited[v])
						continue;
					visited[v] = 1;
					q.push(v);
				}
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
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	int now = bfs();

	cin >> k;
	for (i = 0; i < k; ++i)
	{
		int t;
		cin >> t;
		e[t].clear();
		for (int j = 0; j < n; ++j)
		{
			vector<int>::iterator it;
			if ((it = find(e[j].begin(), e[j].end(), t)) != e[j].end())
				e[j].erase(it);
		}
		int after = bfs();
		if (now == after || now == after - 1)
			cout << "City " << t << " is lost." << endl;
		else
			cout << "Red Alert: City " << t << " is lost!" << endl;
		now = after;
	}
	if (k == n)
		cout << "Game Over." << endl;
}
*/

/*
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
			if ( !visited[j] && min > cost[j])
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

int main()
{
	int i,k;
	cin >> n;
	k = n*(n - 1)/2;
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

/*
#define MAX 505
#define INF 0x7f7f7f7f
struct line
{
	int v;
	int dis, cost;
	line() {}
	line(int vv, int d, int c): v(vv), dis(d), cost(c) {}
};

vector<line> e[MAX];
int visited[MAX];


int n, m;

line findmin(int s, int d)
{
	line ans( 0, INF, INF);
	queue<line> q;
	q.push(line( s, 0, 0));
	visited[s] = 1;

	while (!q.empty())
	{
		line now = q.front(); q.pop();

		if (now.v == d)
		{
			if (now.dis < ans.dis)
				ans.dis = now.dis, ans.cost = now.cost;
			if (now.dis == ans.dis)
				ans.cost = min(ans.cost, now.cost);
		}

		for (int i = 0; i < e[now.v].size(); ++i)
		{
			line vline = e[now.v][i];
			int v = vline.v;
			if (visited[v])
				continue;
			visited[v] = 1;
			
			q.push(line(v, now.dis + vline.dis, now.cost + vline.cost));
		}
	}

	return ans;
}

int main()
{
	int s, d, i;
	cin >> n >> m >> s >> d;
	for (i = 0; i <m; ++i)
	{
		int	q, w, r, t;
		cin >> q >> w >> r >> t;
		line l;
		l.v = w;
		l.dis = r;
		l.cost = t;
		e[q].push_back(l);
		l.v = q;
		e[w].push_back(l);
	}

	line ans = findmin(s, d);

	cout << ans.dis << ' ' << ans.cost << endl;

	return 0;
}
*/

/*
#define MAX 100
int map[MAX][MAX];
int visited[MAX];
int n, e;

void dfs()
{
	int i, j;
	int current, find;
	for (i = 0; i <n; ++i)
	{
		vector<int> shunxu;
		stack<int>  fangwen;
		if (visited[i])
			continue;
		visited[i] = 1;
		fangwen.push(i);
		shunxu.push_back(i);
		current = i;

		while (!fangwen.empty())
		{
			find = 0;
			for (j = 0; j < n; ++j)
			{
				if (!visited[j] && map[current][j])
				{
					visited[j] = 1;
					current = j;
					shunxu.push_back(j);
					fangwen.push(j);
					find = 1;
					break;
				}
			}
			if (!find)
			{
				fangwen.pop();
				if (!fangwen.empty())
					current = fangwen.top();
			}
		}

		if (!shunxu.empty())
		{
			cout << "{ " << shunxu[0];
			for (j = 1; j< shunxu.size(); ++j)
				cout << ' ' << shunxu[j];
			cout << " }" << endl;
		}
	}
}

void bfs()
{
	int i, j;
	int current;
	for (i = 0; i <n; ++i)
	{
		queue<int> fangwen;
		vector<int> shunxu;
		if (visited[i])
			continue;

		visited[i] = 1;
		shunxu.push_back(i);
		fangwen.push(i);
		current = i;

		while (!fangwen.empty())
		{
			for (j = 0; j <n; ++j)
			{
				if (!visited[j] && map[current][j])
				{
					fangwen.push(j);
					shunxu.push_back(j);
					visited[j] = 1;
				}
			}
			fangwen.pop();
			if (!fangwen.empty())
				current = fangwen.front();
		}
		if (!shunxu.empty())
		{
			cout << "{ " << shunxu[0];
			for (j = 1; j< shunxu.size(); ++j)
				cout << ' ' << shunxu[j];
			cout << " }" << endl;
		}

	}
}

int main()
{
	int i;
	cin >> n >> e;
	for (i = 0; i <e; ++i)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	memset(visited, 0, MAX * sizeof(int));
	dfs();
	memset(visited, 0, MAX * sizeof(int));
	bfs();

	return 0;
}
*/

/*
vector<int> e[10005];
int visited[10005];
int kk;

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
	kk++;
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
	kk = 0;
	cout << "*******dfs**********" << endl;
	dfs(2);
	cout << kk << endl;

	return 0;
}
*/


/*
// 喊山，不完全

int map[10005][10005];

const int INF = 20000;
int n;
int find_min(int t)
{
	int max = -INF, i, number;
	for (i = 1; i <= n; ++i)
	{
		if (map[t][i] != INF)
		{
			if (map[t][i] > max)
			{
				max = map[t][i];
				number = i;
			}
			else if (map[t][i] == max && i < number)
				number = i;
		}
	}
	if (max == -INF)
		number = 0;
	return number;
}

int main()
{
	int i, j, k, m, d;
	while (cin >> n >> m >> d)
	{

		for (i = 1; i <= n; ++i)
			for (j = 1; j <= n; ++j)
				map[i][j] = map[j][i] = INF;

		for (i = 0; i < m; ++i)
		{
			cin >> j >> k;
			map[j][k] = map[k][j] = 1;
		}

		// 这里注意循环嵌套的顺序
		for (k = 1; k <= n; ++k)
			for (i = 1; i <= n; ++i)
				for (j = 1; j <= n; ++j)
					if (map[i][k] != INF && map[k][j] != INF && map[i][k] + map[k][j] < map[i][j] && i != j && j != k )
						map[i][j] = map[i][k] + map[k][j];

		for (i = 0; i < d; ++i)
		{
			int t;
			cin >> t;
			cout << find_min(t) << endl;
		}

	}
	return 0;
}
*/

/*
set<int> xue[1005];
int solve[1005] = { 0 };

int main()
{
	int n, m, i, j;
	vector<int> shunxu;
	cin >> n >> m;
	for (i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		xue[b].insert(a);
	}

	set<int> solved;
	for (i = 0; i < n; ++i)
		if (xue[i].empty())
		{
			shunxu.push_back(i);
			solved.insert(i);
			solve[i] = true;
		}

	int current;
	do 
	{
		current = solved.size();
		for (i = 0; i < n; ++i)
		{
			if (!solve[i])
			{
				set<int>::iterator it = xue[i].begin();
				for (; it != xue[i].end();)
				{
					if (solved.find(*it) != solved.end())
					{
						it = xue[i].erase(it);
					}
					else
						++it;
				}
				if (xue[i].empty())
				{
					shunxu.push_back(i);
					solved.insert(i);
					solve[i] = 1;
				}
			}
		}

	} while (current != solved.size());

	if (solved.size() == n)
	{
		cout << "YES" << endl;
		cout << shunxu[0];
		for (i = 1; i < shunxu.size(); ++i)
			cout << ' ' << shunxu[i];
	} 
	else
	{
		cout << "NO" << endl;
		cout << n - solved.size();
	}

	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct stu
{
	int total;
	int number;
};

int main()
{
	int line[5], i, j, n;
	string number[301];
	vector<stu> v;

	int a[301], b[301], c[301], d[301], l[301];
	for (i = 0; i < 5; i++)
		cin >> line[i];
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> number[i] >> a[i] >> b[i] >> c[i] >> d[i];
		l[i] = (a[i] + b[i] + c[i] + d[i]);
	}

	for (i = 0; i < n; ++i)
	{
		if (a[i] >= line[0] && b[i] >= line[1] && c[i] >= line[2] && d[i] >= line[3] && l[i] >= line[4])
		{
			stu tmp;
			tmp.number = i;
			tmp.total = l[i];
			v.push_back(tmp);
		}
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end(), [](const stu s1, const stu s2) {
		return s1.total > s2.total;
	});
	for (i = 0; i < v.size(); ++i)
	{
		if (i < v.size() - 1 && v[i].total == v[i + 1].total)
		{
			vector<stu> v2;
			v2.push_back(v[i]);
			for (j = 1; i + j < v.size(); ++j)
			{
				if (v[i].total == v[i + j].total)
					v2.push_back(v[i+j]);
			}
			sort(v2.begin(), v2.end(), [&](const stu s1, const stu s2) {
				return number[s1.number] < number[s2.number];
			});
			for(j=0; j < v2.size();++j)
				cout << number[v2[j].number] << ' ' << v2[j].total << endl;
			i += v2.size() - 1;
		}
		else
			cout << number[v[i].number] << ' ' << v[i].total << endl;
	}
	return 0;
}
*/
/*
#include <iostream>
#include <cmath>
using namespace std;
#define MAX 105
// map : + 表示已建
//       - 表示未建，绝对值为成本
int map[MAX][MAX] = { 0 };
int visited[MAX] = { 0 };
int visit;
int prim(int n)
{
	int lowcost[MAX];
	int i, j, min, minid, sum = 0;
	
	// 把已连接的边加进来

	return sum;
}

int main()
{
	int i, n, k, sum;
	cin >> n;
	k = n*(n - 1) / 2;
	sum = 0;
	visit = 0;
	for (i = 0; i < k; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		map[a][b] = map[b][a] = d ? c : -c;
		if (d)
		{
			visited[a] = visited[b] = 1;
			visit++;
		}
	}
	
	sum = prim(n);
	cout << sum << endl;

	return 0;
}
*/


/*
int main()
{
	queue<int> a, b;
	int n, i, t;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		if (t % 2) // 奇数
			a.push(t);
		else
			b.push(t);
	}
	bool flag = true;
	while (a.size() || b.size())
	{
		if (a.size())
		{
			if (flag)
			{
				cout << a.front();
				flag = false;
			}
			else
				cout << ' ' << a.front();
			a.pop();
		}
		if (a.size())
		{
			if (flag)
			{
				cout << a.front();
				flag = false;
			}
			else
				cout << ' ' << a.front();
			a.pop();
		}
		if (b.size())
		{
			if (flag)
			{
				cout << b.front();
				flag = false;
			}
			else
				cout << ' ' << b.front();
			b.pop();
		}
	}
	return 0;
}
*/
/*
#include <iostream>
#include <list>
using namespace std;

int main()
{
	int n, t, c, m;
	list<int> v;
	cin >> n;
	while (n--)
	{
		cin >> t;
		v.push_back(t);
	}
	c = 0;
	while (v.size())
	{
		c++;
		m = v.front();
		v.erase(v.begin());
		list<int>::iterator it;
		for (it = v.begin(); it != v.end();)
		{
			if (*it < m)
			{
				m = *it;
				it = v.erase(it);
			}
			else
				++it;
		}
	}
	cout << c << endl;
	return 0;
}
*/

/*
#include <iostream>
using namespace std;

int chegui[100005],csize;
int in[100005];

int find_min_chegui(int current)
{
	int low=0, high = csize - 1,mid;

	while (low <= high)
	{
		mid = (low + high) >> 1;
		if (current >= chegui[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return low;
}

int main()
{
	int  mi, i, n,t, c;
	csize = 0;
	cin >> n;

	for (i = 0; i < n; ++i)
		cin >> in[i];

	// 把第一个元素加入铁轨
	chegui[csize++] = in[0];
	c = 1;
	while (c < n)
	{
		if (chegui[csize - 1] < in[c])
			chegui[csize++] = in[c];
		else
			chegui[find_min_chegui(in[c])] = in[c];
		c++;
	}
	cout << csize << endl;

	return 0;
}
*/

/*
int main()
{
	int i,j,k, n, d[27] = { 0 };
	string in, goal;
	cin >> in >> goal;
	n = in.size();
	for (i = 0; i < n; ++i)
		d[in[i]-'A'] = i;

	bool ok = true;
	for (i = 0; i <n;++i)
		for(j=i+1; j <n; ++j)
			for (k = j+1; k < n; ++k)
				if (d[goal[i]-'A'] > d[goal[j]-'A'] && d[goal[j]-'A'] < d[goal[k]-'A'] && d[goal[i]-'A'] > d[goal[k]-'A'])
					ok = false;

	if (!ok)
		cout << "Are you kidding me?" << endl;
	else
	{
		stack<char> a, b;
		for (i = n-1; i >= 0; --i)
			a.push(in[i]);
		
		while (goal.size())
		{
			if (a.size() > 0 && a.top() == goal[0])
			{
				cout << "1->2" << endl;
				a.pop();
				goal.erase(goal.begin());
			}
			else if (b.size() > 0 && b.top() == goal[0])
			{
				cout << "3->2" << endl;
				b.pop();
				goal.erase(goal.begin());
			}
			else
			{
				cout << "1->3" << endl;
				b.push(a.top());
				a.pop();
			}
		}
	}

	return 0;
}
*/

/*
int main()
{
	vector<int> a, b,c;
	int n, t, i;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		a.push_back(t);
	}
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		b.push_back(t);
	}
	c.resize(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	
	t = c.size()/2;
	cout << (c[t - 1] + c[t]) / 2 << endl;
	return 0;
}

*/
/*
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
using namespace std;

// 求最大公约数。。。
int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	while (a % b != 0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	return b;
}

int main()
{
	string s;
	int n;
	cin >> n;
	int a, b,c;
	a = b = 0;
	while (n--)
	{
		int ta, tb;
		cin >> s;
		ta = atoi(s.substr(0, s.find('/')).c_str());
		tb = atoi(s.substr(s.find('/')+1).c_str());
		if (a == 0 || b == 0)
		{
			a = ta;
			b = tb;
		}
		else if (tb == b)
			a += ta;
		else
		{
			a = a*tb + b*ta;
			b = b*tb;
		}
		if (a != 0)
		{
			c = gcd(a > 0 ? a : -a, b);
			a /= c;
			b /= c;
		}
		else
		{
			b = 0;
		}
	}
	c = 0;
	if (abs(a) > b && b != 1)
	{
		c = abs(a) / b;
		if (a > 0)
			a -= c*b;
		else
			a += c*b;
	}
	if (a != 0)
	{
		if (b != 1)
		{
			if (c == 0)
				cout << a << '/' << b << endl;
			else
				cout << c << ' ' << a << '/' << b << endl;
		}
		else
			cout << a << endl;
	}
	else
		cout << 0 << endl;

	return 0;
}
*/

/*
int main()
{
	string a, b;
	set<char> s;
	int i;

	getline(cin, a);
	getline(cin, b);

	for (i = 0; i < b.size(); ++i)
		s.insert(b[i]);

	set<char>::iterator it;
	size_t c;
	for (it = s.begin(); it != s.end(); ++it)
		while ((c = a.find(*it)) != string::npos)
			a.erase(c, 1);

	cout << a << endl;
	return 0;
}
*/


/*
int main()
{
	int n, i, k,table[100] = { 0,1 };
	for (i = 2; i <= 20; ++i)
		table[i] = table[i - 1] * i;

	cin >> n;
	k = 0;
	for (i = 1; i <= n; ++i)
		k += table[i];
	cout << k;
	return 0;
}
*/

/*
int main()
{
	int d[20] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char Z[15] = "10X98765432";
	int n, he, error;
	cin >> n;
	string s;
	error = 0;
	while (n--)
	{
		cin >> s;
		he = 0;
		for (int i = 0; i <s.size() - 1; ++i)
			he += (s[i]-'0')*d[i];

		he = he % 11;
		if (Z[he] != s[17])
		{
			cout << s << endl;
			error++;
		}
	}
	if (!error)
		cout << "All passed" << endl;
	return 0;
}
*/

/*
int main()
{
	int in, out;
	cin >> in;
	out = 5 * (in - 32) / 9;

	cout << "Celsius = " << out << endl;
}
*/

/*
int main()
{
	int d[11] = { 0 };

	string s;
	cin >> s;
	int i,l = s.size();
	for (i = 0; i < l; ++i)
		d[s[i] - '0']++;

	for (i = 0; i < 10; ++i)
	{
		if (d[i] > 0)
			cout << i << ':' << d[i] << endl;
	}
}
*/

/*
int main()
{
	int top[1005];
	int i, n;
	char c;

	for (i = 1; i < 1005; ++i)
		top[i] = 2 * i*i + 4 * i + 1;

	cin >> n >> c;

	if (n >= 7)
	{

		int row = 1;
		while (top[row] <= n)
			row++;

		int s = n - top[row - 1];

		for (i = row; i > 1; --i)
			cout << string(row - i, ' ') << string(2 * i - 1, c) << endl;
		for (i = 1; i <= row; ++i)
			cout << string(row - i, ' ') << string(2 * i - 1, c) << endl;

		cout << s << endl;
	}
	else
	{
		cout << c << endl << n - 1 << endl;
	}
	return 0;
}
*/

/*
int a[100];
int main()
{
	int t, n, i, j;
	scanf("%d", &t);
	queue<int> q;
	while (t--)
	{
		scanf("%d", &n);
		q.push(n);
		for (i = n - 1; i >= 1; i--)
		{
			q.push(i);
			for (j = 1; j <= i; j++)
			{
				q.push(q.front());
				q.pop();
			}
		}
		int num = n - 1;
		for (i = num; i >= 0; i--)
		{
			a[i] = q.front();
			q.pop();
		}
		for (i = 0; i <= num; i++)
			printf("%d ", a[i]);
		printf("\n");
	}
}
*/

/*
int main()
{
	int n;
	while (cin >> n)
	{
		if ((n - 2) % 4 != 0)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
}
*/

/*
int main()
{
	int n;
	char buff[33];
	string in, out;
	cin >> n;
	while (n--)
	{
		cin >> in;
		out.clear();
		char current = in[0];
		int i, l,cl;
		l = in.length();
		cl = 1;
		for (i = 1; i <= l; ++i)
		{
			if (i == l || current != in[i])
			{
				if (cl != 1)
				{
					sprintf(buff, "%d", cl);
					out += buff;
				}
				out += current;
				cl = 1;
				current = in[i];
			}
			else
				cl++;
		}

		cout << out << endl;
	}
}
*/

/*
int main()
{
	double c;
	while (cin >> hexfloat >> c)
		printf("%lf\n", c);
}
*/

/*
int f(char c)
{
	if (isupper(c))
		return c - 'A' + 1;
	else
		return -(c - 'a' + 1);
}

void main()
{
	int n, x;
	char c;
	cin >> n;
	while (n--)
	{
		cin >> c >> x;
		cout << x + f(c) << endl;
	}
}
*/

/*
int transform(string& str)
{
	int sign = 1 , i;
	if (str[0] == '-')
	{
		str.erase(str.begin());
		sign = -1;
	}
	while (str[0] == '0' && str[1] != '.')
		str.erase(str.begin());
	if (str.find('.') != string::npos)
		for (i = str.size() - 1; str[i] == '0'; --i)
			str.erase(str.begin() + i);
	i = str.size() - 1;
	if (str[i] == '.')
		str.erase(str.begin() + i);

	return sign;
}

int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int sign1, sign2;
		sign1 = transform(a);
		sign2 = transform(b);
		if (sign1 == sign2 && a == b)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
*/
/*
int main()
{
	int state, n, i;
	while (cin >> n)
	{
		state = 0;
		for (i = 1; i <= n; ++i)
			if (n % i == 0)
				state = !state;
		cout << state << endl;
	}
}
*/

/*
string draw(char c, int n)
{
	return string(n, c);
}

void main()
{
	int w, h;
	while (cin >> w >> h)
	{
		cout << '+' << draw('-', w) << '+' << endl;
		while (h--) cout << '|' << draw(' ', w) << '|' << endl;
		cout << '+' << draw('-', w) << '+' << endl;
		cout << endl;
	}
}
*/

/*
// HDU 2051
void main()
{
	int in, out, i;
	while (cin >> in)
	{
		out = 0, i = 1;
		while (in)
		{
			out += (in % 2)*i;
			in /= 2;
			i *= 10;
		}
		cout << out << endl;
	}
}
*/

/*
void main()
{
	int c, n;
	cin >> c;
	while (c--)
	{
		cin >> n;
		cout << 2 * n*n - n + 1 << endl;
	}
}
*/

/*
void main()
{
	long long table[21] = { 0,0,1 }, fact[21] = { 1,1 };
	int i, c, n, m;
	for (i = 3; i < 21; ++i)
		table[i] = (i - 1)*(table[i - 1] + table[i - 2]);
	for (i = 2; i < 21; ++i)
		fact[i] = i*fact[i - 1];

	cin >> c;
	while (c--)
	{
		cin >> n >> m;
		cout << table[m] * (fact[n] / fact[n - m] / fact[m]) << endl;
	}
}
*/

/*
void main()
{
	long long c, n, i, table[21] = { 0, 0, 1 };
	cin >> c;

	for (i = 3; i < 21; ++i)
		table[i] = (i - 1)*(table[i - 1] + table[i - 2]);

	while (c--)
	{
		cin >> n;
		long long d = 1;
		for (i = 2; i <= n; ++i)
			d *= i;
		printf("%.2f%%\n", 100.0*table[n] / d);
	}
}
*/

/*
int n,m, minf;
int a[11], b[11], used[11];

void DFS(int hp, int cnt)
{
	if (cnt > n)
		return;

	if (hp <= 0 && cnt < minf)
	{
		minf = cnt;
		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			used[i] = 1;
			if (hp <= b[i])
				DFS(hp - 2 * a[i], cnt + 1);
			else
				DFS(hp - a[i], cnt + 1);
			used[i] = 0;
		}
	}
}



void main()
{
	int i;
	while (~scanf("%d%d", &n, &m))
	{
		for (i = 0; i < n; ++i)
			scanf("%d%d", &a[i], &b[i]);

		memset(used, 0, sizeof(used));
		minf = 15;
		DFS(m, 0);
		if (minf == 15)
			printf("-1\n");
		else
			printf("%d\n", minf);
	}
}
*/

/*
void main()
{
	int ret[100];
	int n = 0, a, b;
	while (~scanf("%d%d"))
		ret[n++] = a + b;
	for (int i = 0; i < n; ++i)
		printf("%d\n", ret[i]);
}
*/


/*
int map[100][100];

const int INF = 1000;

int main()
{
	int i, j, k, n, m;
	while (cin >> n >> m)
	{

		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
				map[i][j] = map[j][i] = INF;

		for (i = 0; i < m; ++i)
		{
			cin >> j >> k;
			map[j][k] = map[k][j] = 1;
		}

		// 这里注意循环嵌套的顺序
		for (k = 0; k < n; ++k)
			for (i = 0; i < n; ++i)
				for (j = 0; j < n; ++j)
					if (map[i][k] != INF && map[k][j] != INF && map[i][k] + map[k][j] < map[i][j])
						map[i][j] = map[i][k] + map[k][j];

		int flag = 1;
		for (i = 0; i < n&&flag; ++i)
			for (j = 0; j < n; ++j)
			{
				if (map[i][j] > 7)
					flag = 0;
			}

		if (flag)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
*/

/*
int max(int a, int b) { return a > b ? a : b; }
int MAXN[4000001];

void PushUp(int rt)
{
	MAXN[rt] = max(MAXN[rt << 1], MAXN[(rt << 1) + 1]);
}

void build(int l, int r, int rt)
{
	if (l == r)
	{
		scanf("%d", &MAXN[rt]);
		return;
	}
	
	int m = (l + r) >> 1;
	build(l, m, rt << 1);
	build(m + 1, r, (rt << 1) + 1);
	PushUp(rt);
}

void update(int p, int q, int l, int r, int rt)
{
	if (l == r)
	{
		MAXN[rt] = q;
		return;
	}
	int m = (l + r) >> 1;
	if (p <= m)
		update(p, q, l, m, rt << 1);
	else
		update(p, q, m + 1, r, (rt << 1) + 1);
	PushUp(rt);
}

int getmax(int L, int R, int l, int r, int rt)
{
	if (L <= l && r << R)
		return MAXN[rt];
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m)
		ret = max(ret, getmax(L, R, l, m, rt << 1));
	if (R > m)
		ret = max(ret, getmax(L, R, m + 1, r, (rt << 1) + 1));
	return ret;
}

int main()
{
	int n, m, a, b, i;
	char c;
	while (~scanf("%d%d", &n, &m))
	{
		build(1, n, 1);
		for (i = 0; i < m; i++)
		{
			scanf("%c%d%d", &c, &a, &b);
			if (c == 'Q')
				printf("%d\n", getmax(a, b, 1, n, 1));
			else
				update(a, b, 1, n, 1);
		}
	}
	return 0;
}
*/


/*
#include <stdio.h>
#include <string.h>
int dp[12][100001];

int max(int a, int b)
{
	return a > b ? a : b;
}

void main()
{
	int i,n;
	while (~scanf("%d", &n) && n)
	{
		int x, t,maxt;
		maxt = 0;
		memset(dp, 0, sizeof dp);
		for (i = 0; i < n; ++i)
		{
			scanf("%d%d", &x, &t);
			dp[x][t]++;
			if (t > maxt) maxt = t;
		}
		for (t = maxt - 1; t >= 0; --t)
		{
			dp[0][t] += max(dp[0][t + 1], dp[1][t + 1]);
			for( i =1; i < 11; ++i)
				dp[i][t] += max(max(dp[i - 1][t + 1], dp[i][t + 1]), dp[i + 1][t + 1]);
		}
		printf("%d\n", dp[5][0]);
	}
}
*/

/*

// 并查集
int set[1001];
void mkset()
{
	for (int i = 1; i <= 1000; ++i)
		set[i] = i;
}

int find(int x)
{
	if (x != set[x])
		set[x] = find(set[x]);
	return set[x];
}

void unionset(int x, int y)
{
	if ((x = find(x)) == (y = find(y))) return;
	set[x] = y;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int N, M;
		cin >> N >> M;

		mkset();
		while (M--)
		{
			int a, b;
			cin >> a >> b;
			unionset(a, b);
		}
		int ret = 0;
		for (int i = 1; i <= N; ++i)
			if (i == find(i))
				ret++;
		cout << ret << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	map<int, int> f1, f2;
	vector<int> people,single; // 统计测试的人里面，是单身狗的
	while (n--)
	{
		int a,b;
		cin >> a >> b;
		f1[a] = b;
		f2[b] = a;
	}
	cin >> n;
	while (n--)
	{
		int a;
		cin >> a;
		people.push_back(a);
	}
	for (vector<int>::iterator it = people.begin(); it != people.end(); ++it)
	{
		int find;
		find = f1[*it];
		if (find)
		{
			// 找到记录，看对方来了没
			if (std::find(people.begin(), people.end(), find) == people.end())
			{
				// 对方没来,是单身狗
				single.push_back(*it);
			}
		}
		else // 没找到记录，在f2 中找
		{
			find = f2[*it];
			if (find)
			{
				if (std::find(people.begin(), people.end(), find) == people.end())
				{
					// 对方没来,是单身狗
					single.push_back(*it);
				}
			}
			else
				single.push_back(*it);
		}
	}

	sort(single.begin(), single.end()); // 排序
	cout << single.size() << endl; // 单身狗数量
	vector<int>::iterator it = single.begin(); // 按格式输出
	cout << *it;
	for (++it; it != single.end(); ++it)
		cout << ' ' << *it;
	cout << endl;
	return 0;
}
*/
/*
void main()
{
	long long d, f, t[21] = { 0, 0, 1 };
	for (d = 3; d <= 20; ++d)
		t[d] = (d - 1)*(t[d - 1] + t[d - 2]);
	int n;
	cin >> n;
	while (n--)
	{
		cin >> d;
		f = 1;
		for (int i = 2; i <= d; ++i)
			f *= i;
		cout << fixed << setprecision(2) << 100.0*t[d]/f << '%' << endl;
	}
}
*/
/*
void main()
{
	long long d, t[40] = { 0, 3, 8 };
	for (d = 3; d < 40; ++d)
		t[d] = 2 * (t[d - 1] + t[d - 2]);
	while (cin >> d)
		cout << t[d] << endl;
}
*/

/*
void main()
{
	long long d,t[51] = { 0,1,2 };
	for (int i = 3; i <= 50; ++i)
		t[i] = t[i - 1] + t[i - 2];
	while (cin >> d)
		cout << t[d] << endl;
}
*/
/*
void main()
{
	long long t[51] = { 0,3,6,6 };
	for (int i = 4; i <= 50; ++i)
		t[i] = t[i - 1] + 2 * t[i - 2];
	int n;
	while (cin >> n)
		cout << t[n] << endl;
}
*/

/*
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int c = 0;
		string str, s = "~!@#$%^";
		cin >> str;
		if (str.size() >= 8 && str.size() <= 16)
		{
			for (auto i : str)
			{
				if (isupper(i))
					c |= 0x01;
				else if (islower(i))
					c |= 0x02;
				else if (isdigit(i))
					c |= 0x04;
				else if (s.find(i) != string::npos)
					c |= 0x08;
			}
			c = (c & 0x01) + ((c & 0x02) >> 1) + ((c & 0x04) >> 2) + ((c & 0x08) >> 3);
		}
		cout << (c >= 3 ? "YES" : "NO") << endl;
	}
}
*/

/*
void main()
{
	int n, d;
	cin >> n;
	while (n--)
	{
		cin >> d;
		int q= 3;
		while (d--)
			q = (q - 1) * 2;
		cout << q << endl;
	}
}
*/

/*
struct prog
{
	int start, end;
};

void main()
{
	int n;
	prog p;
	while (cin >> n && n)
	{
		int now = 0, c = 0;
		list<prog> v;
		while (n--)
		{
			cin >> p.start >> p.end;
			v.push_back(p);
		}
		v.sort([=](prog& p1, prog& p2) {
			return p1.end < p2.end ;
		});
		while (1)
		{
			while (!v.empty() && now > v.front().start)
				v.pop_front();
			if (!v.empty())
			{
				now = v.front().end;
				c++;
				v.pop_front();
			}
			else
				break;
		}
		cout << c << endl;
	}
}
*/
/*
struct point 
{
	int x, y;
};

void main()
{
	int n;
	point p;
	while (cin >> n && n)
	{
		vector<point> vec;
		while (n--)
		{
			cin >> p.x >> p.y;
			vec.push_back(p);
		}
		double s = 0;
		vec.push_back(vec[0]);
		for (int i = 0; i < vec.size()-1; ++i)
			s += (vec[i].x*vec[i + 1].y - vec[i + 1].x*vec[i].y);
		printf("%.1f\n", s/2);
	}
}
*/
/*
void main()
{
	int a, b;
	while (cin >> a >> b && a && b)
	{
		int ret = 1;
		while (b--)
			ret = ret*a % 1000;
		cout << ret << endl;
	}
}
*/

/*
void main()
{
	int n, m;
	while (cin >> n >> m && (n || m))
	{
		set<int> a;
		int i,d;
		for (i = 0; i < n; ++i)
		{
			cin >> d;
			a.insert(d);
		}
		for (i = 0; i < m; ++i)
		{
			cin >> d;
			a.erase(d);
		}
		if (!a.empty())
			for (auto it = a.begin(); it != a.end(); ++it)
				cout << *it << ' ';
		else
			cout << "NULL";
		cout << endl;
	}
}
*/
/*
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x1, x2, x3, y1, y2, y3;
		cin >> x1 >> x2 >> x3 >> y1 >> y2 >> y3;
		x1 += y1, x2 += y2, x3 += y3;
		if (x3 > 59)
			x3-=60, x2++;
		if (x2 > 59)
			x2-=60, x1++;
		cout << x1 << ' ' << x2 << ' ' << x3 << endl;
	}
}
*/

/*
void main()
{
	int n;
	char BUFFER[100];
	cin >> n;
	bool flag = true;
	while (n--)
	{
		if (flag)
		{
			cin.getline(BUFFER, 99);
			flag = false;
		}
		
		cin.getline(BUFFER, 99);
		bool f = true;
		char *p = BUFFER;
		if (isalpha(*p) || *p == '_')
			p++;
		else
			f = false;
		
		while (*p != '\0')
		{
			if (isalnum(*p) || *p == '_')
				p++;
			else
			{
				f = false;
				break;
			}
		}
		if (f)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
*/

/*
void main()
{
	int n, m, i;
	while (cin >> n >> m)
	{
		vector<vector<int>> students;
		for (i = 0; i < n; ++i)
		{
			students.push_back(vector<int>());
			for (int j = 0; j < m; ++j)
			{
				students[i].push_back(0);
				cin >> students[i].back();
			}
		}
		vector<double> kv, aveStu;
		kv.resize(m);
		for (i = 0; i < n; ++i)
		{
			float t = 0;
			for (int j = 0; j < m; ++j)
			{
				t += students[i][j];
				kv[j] += students[i][j];
			}
			aveStu.push_back(t / m);
		}
		for (i = 0; i < m; ++i)
			kv[i] /= n;
		int t = 0;
		for (i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (students[i][j] >= kv[j])
				{
					if (j == m - 1)
						t++;
				}
				else
					break;
			}
		}
		
		printf("%.2f", aveStu[0]);
		for (i = 1; i < n; ++i)
			printf(" %.2f",aveStu[i]);
		puts("");
		printf("%.2f", kv[0]);
		for (i = 1; i < m; ++i)
			printf(" %.2f", kv[i]);
		printf("\n%d\n\n", t);
	}
}
*/
/*
void main()
{
	int m, n;
	while (cin >> m >> n)
	{
		int max = 0,mx = 1,my = 1;
		for(int y=1; y <=m; ++y)
			for (int x = 1; x <= n; ++x)
			{
				int c;
				cin >> c;
				if (abs(c) > abs(max))
					mx = x, my = y, max = c;
			}
		cout << my << ' ' << mx << ' ' << max << endl;
	}
}
*/

/*
struct MM
{
	int x, y, score;
};

void main()
{
	int m, n;
	MM mm;
	while (cin >> m >> n)
	{
		vector<MM> vec;
		for(int y = 1; y <=m; ++y)
			for (int x = 1; x <= n; ++x)
			{
				mm.x = x, mm.y = y;
				cin >> mm.score;
				vec.push_back(mm);
			}
		sort(vec.begin(), vec.end(), [](const MM& mm1, const MM& mm2) {
			return abs(mm1.score) > abs(mm2.score);
		});
		if (vec.size() >= 2 && abs(vec[0].score) == abs(vec[1].score))
		{
			vector<MM> vec2;
			for (const auto& it : vec)
			{
				if (vec2.empty())
					vec2.push_back(it);
				else
				{
					if (abs(vec2.back().score) == abs(it.score))
						vec2.push_back(it);
					else
						break;
				}
			}
			if (vec2.size() != 1)
			{
				sort(vec2.begin(), vec2.end(), [](const MM& mm1, const MM& mm2) {
					return mm1.y < mm2.y;
				});
				if (vec2[0].y == vec2[1].y)
				{
					vector<MM> vec3;
					for (const auto& it : vec2)
					{
						if (vec3.empty())
							vec3.push_back(it);
						else
						{
							if (vec3.back().x == it.x)
								vec3.push_back(it);
							else
								break;
						}
					}
					if (vec3.size() != 1)
						sort(vec3.begin(), vec2.begin(), [](const MM& mm1, const MM& mm2) {
							return mm1.x < mm2.x;
						});
					mm = vec3[0];
				}
				else
					mm = vec2[0];
			}
			else
				mm = vec2[0];
		}
		else
			mm = vec[0];

		cout << mm.y << ' ' << mm.x << ' ' << mm.score << endl;
	}
}
*/

/*
int v[6] = { 1,2,5,10,50,100 };
int money(int x)
{
	int ret = 0;
	for (int i = 5; i >= 0; --i)
	{
		while (x >= v[i] && x > 0)
		{
			x -= v[i];
			ret++;
		}
	}
	return ret;
}

void main()
{
	int n;
	while (cin >> n && n)
	{
		int ret = 0;
		while (n--)
		{
			int d;
			cin >> d;
			ret += money(d);
		}
		cout << ret << endl;
	}
}
*/
/*
// 233 徒弟
#include <stdio.h>
int main()
{
	char str[6] = { 0x4c,0x4f,0x56,0x45,0x55, '\0' };
	printf("%s\n",str);
	return 0;
}*/

/*
void main()
{
	int n, m, t;
	vector<int> vec;
	while (cin >> n >> m && n != 0 && m != 0)
	{
		t = n;
		vec.clear();
		vec.push_back(m);
		while (t--)
		{
			int d;
			cin >> d;
			vec.push_back(d);
		}
		sort(vec.begin(), vec.end());
		for (t = 0; t < n + 1; ++t)
		{
			if (t)
				cout << " ";
			cout << vec[t];
		}
		cout << endl;
	}
}*/

/*
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		cout << count_if(s.begin(), s.end(), [](char c) {
			return isdigit(c);
		}) << endl;
	}
}*/

/*
void main()
{
	int n, d;
	while (cin >> n)
	{
		d = 1;
		for (int i=1; i <n; ++i)
			d = 2 * d + 2;
		cout << d << endl;
	}
}
*/
/*
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int d;
		cin >> d;
		double f = 0;
		d++;
		while (--d)
		{
			if (d % 2)
				f += 1.0 / d;
			else
				f -= 1.0 / d;
		}
		printf("%.2lf\n", f);
	}
}
*/
/*
void main()
{
	float a, b;
	while (cin >> a >> b)
	{
		double ret = a;
		while (--b)
			ret += a = sqrt(a);
		cout << fixed << setprecision(2) << ret << endl;
	}
}
*/

/*
void main()
{
	int n;
	while (cin >> n && n)
	{
		int a, b, c;
		a = b = c = 0;
		while (n--)
		{
			float f;
			cin >> f;
			if (f < 0) ++a;
			else if (f == 0) ++b;
			else if (f > 0) ++c;
		}
		cout << a << ' ' << b << ' ' << c << endl;
	}
}
*/

/*
void main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a > b)
		{
			int t = a;
			a = b;
			b = t;
		}
		unsigned int c, d;
		c = d = 0;
		for (unsigned int i = a; i <= b; ++i)
		{
			if (i % 2)
				d += i*i*i;
			else
				c += i*i;
		}
		cout << c << ' ' << d << endl;
	}
}
*/
/*
void main()
{
	int n,c;
	while (cin >> n)
	{
		c = 1;
		while (n--)
		{
			int d;
			cin >> d;
			if (d % 2)
				c *= d;
		}
		cout << c << endl;
	}
}
*/
/*
void main()
{
	int s;
	while (cin >> s)
	{
		if (s > 100 || s < 0) cout << "Score is error!";
		else if (s >= 90) cout << "A";
		else if (s >= 80) cout << "B";
		else if (s >= 70) cout << "C";
		else if (s >= 60) cout << "D";
		else if (s >= 0 ) cout << "E";
		cout << endl;
	}
}
*/
/*
void main()
{
	double d;
	while (cin >> d)
		cout << fixed << setprecision(2) << (d < 0 ? -d : d) << endl;
}
*/

/*
void main()
{
	string str;
	while (cin >> str)
	{
		sort(str.begin(), str.end());
		for (int i = 0; i < str.size(); ++i)
		{
			if (i != 0)
				cout << " ";
			cout << str[i];
		}
		cout << endl;
	}
}
*/

/*
void main()
{
	string str;
	
	int n;
	cin >> n;
	bool flag = false;
	while (n--)
	{
		if (!flag)
		{
			flag = true;
			getline(cin, str);
		}
		getline(cin, str);
		int count = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] < 0)
			{
				count++;
				++i;
			}
		}
		cout << count << endl;
	}
}
*/

/*
unsigned int gcd(unsigned int a, unsigned int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void main()
{
	int n;
	while (cin >> n)
	{
		unsigned int a,b;
		cin >> a;
		n--;
		while (n--)
		{
			cin >> b;
			a = a / gcd(a, b)*b;
		}
		cout << a << endl;
	}
}
*/


/*
void main()
{
	int n;
	string str;
	bool flag = false;
	cin >> n;

	while (n--)
	{
		if (flag)
			cout << endl;
		else
		{
			flag = true;
			getline(cin, str);
		}
		getline(cin, str);
		
		cout << "a:" << count(str.begin(), str.end(), 'a') << endl;
		cout << "e:" << count(str.begin(), str.end(), 'e') << endl;
		cout << "i:" << count(str.begin(), str.end(), 'i') << endl;
		cout << "o:" << count(str.begin(), str.end(), 'o') << endl;
		cout << "u:" << count(str.begin(), str.end(), 'u') << endl;
	}
}
*/

/*
void main()
{
	string str;
	stringstream ss;
	while (getline(cin,str))
	{
		ss << str;
		bool flag = false;
		while (ss >> str)
		{
			str[0] = toupper(str[0]);
			if (flag)
				cout << " ";
			else
				flag = true;
			cout << str;
		}
		ss.clear();
		cout << endl;
	}
}*/


/*
void main()
{
	char a,b,BUFFER[81][81];
	int n;
	bool flag = false;
	while (cin >> n >> a >> b)
	{
		if (flag)
			cout << endl;
		else
			flag = true;
		if (n == 1)
		{
			cout << a << endl;
		}
		else
		{
			int d = (n - 1) / 2;
			for (int i = d; i > 0; --i)
			{
				for (int x = -i; x <= i; ++x)
				{
					BUFFER[d - i][d + x] = i % 2 ? b : a;
					BUFFER[d + i][d + x] = i % 2 ? b : a;
				}
				for (int y = -i + 1; y <= i - 1; ++y)
				{
					BUFFER[d + y][d - i] = i % 2 ? b : a;
					BUFFER[d + y][d + i] = i % 2 ? b : a;
				}
			}
			BUFFER[d][d] = a;
			BUFFER[0][0] = BUFFER[0][n - 1] = BUFFER[n - 1][0] = BUFFER[n - 1][n - 1] = ' ';
			for (int i = 0; i < n; ++i)
			{
				BUFFER[i][n] = '\0';
				cout << BUFFER[i] << endl;
			}
		}
	}
}
*/

/*
void main()
{
	int n, t;
	cin >> n;
	while (n--)
	{
		cin >> t;
		float max=0, cur;
		while (t--)
		{
			scanf("%f", &cur);
			if (cur > max)
				max = cur;
		}
		printf("%.2f\n", max);
	}
}
*/

/*
void main()
{
	int n, dp[251][101] = {1};
	int v[] = { 1,5,10,25,50 };
	for (int i = 0; i < 5; ++i)
		for (int j = v[i]; j <= 250; ++j)
			for (int k=1; k <=100; ++k)
				dp[j][k] = dp[j][k] + dp[j - v[i]][k-1];
	while (cin >> n)
	{
		int ans = 0;
		for (int i = 0; i <= 100; ++i)
			ans += dp[n][i];
		cout << ans << endl;
	}
}
*/


/*
#include <stdio.h>
void main()
{
	int n;
	long long fib[51] = { 0,1 };
	for (int i = 2; i <= 50; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];

	while (scanf("%d", &n) && n != -1)
		printf("%lld\n", fib[n]);
}*/


/*
void main()
{
	int n;
	double sq2 = sqrt(2);
	cin >> n;
	while (n--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 && y1 == y2)
			cout << "0.000" << endl;
		else
		{
			double length = 0;
			int r1 = x1 + y1, r2 = x2 + y2;
			if (r1 > r2)
				swap(x1, x2), swap(y1, y2), swap(r1, r2);
			for (int r = r1; r < r2; ++r)
			{
				length += sqrt(pow(r, 2) + pow(r + 1, 2));
				if (r != r1)
					length += sq2*r;
			}
			if (r1 != r2)
				length += sq2*(y1 + x2);
			else
				length += sq2*(y1 - y2);
			cout << fixed << setprecision(3) << length << endl;
		}
	}
}
*/


/*
int main() 
{
	set<string> s;
	string str;
	stringstream ss;
	
	while (getline(cin,str))
	{
		if (str == "#")
			break;
		ss << str;
		while (ss >> str)
			s.insert(str);
		cout << s.size() << endl;
		ss.clear();
		ss.str("");
		s.clear();
	}
	return 0;
}*/

/*
void main()
{
	string str;
	vector<char> vec;
	while (cin >> str)
	{
		vec.clear();
		int t = 0;
		const char *p = str.c_str();
		char ch;
		while ((ch = *p++) != '\0')
		{
			switch (ch)
			{
			case'(':
				vec.push_back('(');
				break;
			case')':
				vec.pop_back();
				break;
			case'B':
				t = vec.size();
				break;
			}
		}
		cout << t << endl;
	}
}*/



/*
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
void main()
{
	int n;
	while (cin >> n)
	{
		vector<float> vec;
		for (int i = 0; i < n; ++i)
		{
			float t;
			cin >> t;
			vec.push_back(t);
		}
		sort(vec.begin(), vec.end());
		vec.pop_back();
		vec.erase(vec.begin());
		float ret = 0;
		for (auto g : vec)
			ret += g;
		cout << fixed << setprecision(2) << ret / (n-2) << endl;
	}
}
*/


/*
// HDU 1686
#include <iostream>
#include <cstring>
using namespace std;
int _next[10001];
char P[10001], T[1000001];
void buildNext(const char *P, int m)
{
	unsigned int j = 0;
	int t = _next[0] = -1;
	while (j < m)
	{
		if (t < 0 || P[j] == P[t])
		{
			++j, ++t;
			if (P[j] != P[t])
				_next[j] = t;
			else
				_next[j] = _next[t];
		}
		else
			t = _next[t];
	}
}

int Match(const char *P, const char *T)
{
	int count = 0;	
	int i = 0, n = (int)strlen(T);
	int j = 0, m = (int)strlen(P);
	buildNext(P, m);

	while (i < n)
	{
		if (j < 0 || T[i] == P[j])
			++i, ++j;
		else
			j = _next[j];
		if (j == m)
		{
			count++;
			j = _next[j];
		}
	}
	return count;
}

void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		cin >> P >> T;
		cout << Match(P,T) << endl;
	}
}

*/
/*
int _next[10005];
char str1[1000005], str2[10005];
int cnt;

void get_next(int len2)//生成next数组  
{
	int i = 0, j = -1;
	_next[0] = -1;
	while (i<len2)
	{
		if (j == -1 || str2[i] == str2[j])
		{
			i++;
			j++;
			if (str2[i] != str2[j])
				_next[i] = j;
			else
				_next[i] = _next[j];
		}
		else
			j = _next[j];
	}
}

void kmp(int len1, int len2)//kmp算法  
{
	int i = 0, j = 0;
	get_next(len2);
	while (i<len1)
	{
		if (j == -1 || str1[i] == str2[j])
		{
			++i;
			++j;
		}
		else
			j = _next[j];
		if (j == len2)
		{
			cnt++;
			j = _next[j];
		}
	}
}

int main()
{
	int n;
	int len1, len2;
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		fgets(str2,10000, stdin);
		fgets(str1,1000000, stdin);
		len1 = strlen(str1);
		len2 = strlen(str2);
		cnt = 0;
		kmp(len1, len2);
		printf("%d\n", cnt);
	}
	return 0;
}*/




/*
#include <iostream>
using namespace std;
int table[2001][2001];
int stirling(int k, int m)
{
	if (table[k][m] >= 0) return table[k][m];
	if (k == 0 && m == 0) return table[k][m] =1;
	else if (k == 0 || m == 0) return table[k][m] =0;
	else return table[k][m] = (k*stirling(k, m - 1) + stirling(k - 1, m - 1)) % 1000;
}

int bell(int m)
{
	int ret = 0;
	for (int i = 1; i <= m; ++i)
		ret += stirling(i, m);
	return ret;
}

void main()
{
	int n;
	cin >> n;
	memset(table, -1, sizeof(table));
	while (n--)
	{
		int t;
		cin >> t;
		cout << bell(t) % 1000 << endl;
	}
}
*/



/*
#include <iostream>
#include <string>
using namespace std;
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string a, b;
		cin >> a >> b;
		string::size_type pos,find;
		int count;
		count = pos = find = 0;
		while (1)
		{
			find = b.find(a, pos);
			if (find == string::npos)
				break;
			count++;
			if (find == pos)
				pos++;
			else
				pos = find + 1;
		}
		cout << count << endl;
	}
}*/


/*
bool fun(int x)
{
	if (x == int(pow(x / 100, 3) + pow(x % 100 / 10, 3) + pow(x % 10, 3)))
		return true;
	return false;
}

void main()
{
	int a, b,c;
	while (cin >> a >> b)
	{
		c = 0;
		for (int i = a; i <= b; ++i)
		{
			if (fun(i))
			{
				if (c)
					cout << ' ';
				cout << i;
				c++;
			}
		}
		if (!c)
			cout << "no";
		cout << endl;
	}
}*/




/*
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct A
{
	int a;
	int b;
};

void main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<A> vec;
		while (n--)
		{
			A tmp;
			cin >> tmp.a >> tmp.b;
			vec.push_back(tmp);
		}
		sort(vec.begin(), vec.end(), [](const A& a, const A& b) {
			return a.a < b.a;
		});
		for (auto it : vec)
		{
			string head = ">+", body(it.a - 2, '-'), end = "+>";
			string out = head + body + end;
			for (int i = 0; i < it.b; ++i)
				cout << out << endl;
			cout << endl;
		}
	}
}*/


/*
void main()
{
	int n;
	while (cin >> n && n)
	{
		string str;
		cin >> str;
		bool red = true;
		int r, y;
		r = y = 7;
		for (int i = 0; i < str.size(); ++i)
		{
			switch (str[i])
			{
			case 'Y': y--; break;
			case 'R': r--; break;
			case 'L':
				if (y != 0)
					red = true, i = str.size();
				else
					red = false, i = str.size();
				break;
			case 'B':
				if (r != 0)
					red = false, i = str.size();
				else
					red = true, i = str.size();
				break;
			}
		}

		cout << (red ? "Red" : "Yellow") << endl;
	}
}*/

/*
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		float a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << fixed << setprecision(1) << sqrt((a - c)*(a - c) + (b - d)*(b - d)) << endl;
	}
}*/

/*
int table[2001][2001] = { 1 };

void main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 2000; ++i)
	{
		table[i][0] = 0;
		table[i][i] = 1;
		for (int j = 1; j <= i; ++j)
			table[i][j] = (table[i - 1][j - 1] + j*table[i - 1][j])%1000;
	}
	while (n--)
	{
		int x;
		cin >> x;
		int out = 0;
		for (int i = 1; i <= x; ++i)
			out += table[x][i];
		cout << out % 1000 << endl;
	}
}*/


/*
const int MAX_W = 1000, MAX_H = 1000;
char BUFFER[MAX_H][MAX_W];
char MOD[8][5];

void main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m;
		char tmp[MAX_W];
		cin >> m;
		for (int i = 0; i < 8; ++i)
			cin >> MOD[i] >> MOD[i][3];
		memset(BUFFER, 0, sizeof(BUFFER));
		
		cin >> tmp;
		int len = strlen(tmp);
		for (int i = 0; i < m; ++i)
			memset(BUFFER[i], '0', (len+4) * sizeof(char));
		memcpy( BUFFER[0] + 2 , tmp, sizeof(char)*len);

		for (int i = 0; i < m; ++i)
		{
			BUFFER[i][0] = BUFFER[i][1] = BUFFER[i][len + 2] = BUFFER[i][len + 3] = '0';
			for (int j = 0; j < len+2; ++j)
			{
				for (int k = 0; k < 8; ++k)
				{
					if (BUFFER[i][j]     == MOD[k][0] &&
						BUFFER[i][j + 1] == MOD[k][1] &&
						BUFFER[i][j + 2] == MOD[k][2])
					{
						BUFFER[i + 1][j + 1] = MOD[k][3];
						break;
					}
				}
			}
		}
		for (int i = 0; i < m; ++i)
			BUFFER[i][len + 2] = '\0'; 
		for (int i = 0; i < m; ++i)
			cout << (BUFFER[i]+2) << endl;
	}
}*/


/*
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int n, m;
		cin >> n >> m;
		cout << n*(n + 1)*m*(m + 1) / 4 << endl;
	}
}*/


/*
int table[30][30] = { 0 };
int C(int n, int m)
{
	if (table[n][m]) 
		return table[n][m];
	if (m == 0) 
		return table[n][m] = 1;
	if (n == m)
		return table[n][m] = 1;
	return table[n][m] = C(n - 1, m - 1) + C(n - 1, m);
}
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int n, m;
		cin >> n >> m;
		if (m == 0 || m == n)
			cout << 1 << endl;
		else if (m > n)
			cout << 0 << endl;
		else
			cout << C(n,m) << endl;
	}
}*/

/*
int g(int x)
{
	if (x == 1)
		return 1;
	int count=2, i;
	for (i = 2; i * 2 < x; ++i)
		if (x % i == 0)
			count++;
	return count;
}

void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b, maxg, max;
		cin >> a >> b;
		max = maxg = -1;
		for (int i = a; i <= b; ++i)
			if (g(i) > maxg)
			{
				maxg = g(i);
				max = i;
			}
		cout << max << endl;
	}
}*/

/*
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long t;
		cin >> t;
		cout << (t*t) % 10000 << endl;
	}
}*/


/*
int find(int a, int b)
{
	if (b == 0)
		return a;
	return find(b, a % b);
}

void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b, c;
		cin >> a >> b;
		// c = n*b,n=2,3,4...
		c = 2 * b;
		while (find(a, c) != b)
			c += b;
		cout << c << endl;
	}
}*/


/*
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		cout << int(pow(2, t - 1) + (t - 1)*pow(2, t - 2)) << endl;
	}
}*/


/*
void main()
{
	long long int fib[50];
	fib[0] = 1; fib[1] = 1;
	for (int i = 2; i < 50; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];

	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << fib[b - a] << endl;
	}
}*/




/*
void main()
{
	int t;
	double n, sum, ft1, ft2, ft3, et1, et2, et3, max, min;
	double sm, sh, mh, tsm, tsh, tmh, fsm, fsh, fmh, esm, esh, emh;
	sm = 10. / 59.; // 
	sh = 120. / 719.;
	mh = 120. / 11.;
	tsm = 360 * sm;
	tsh = 360 * sh;
	tmh = 360 * mh;
	while (scanf("%lf", &n))
	{
		if (n<0)
			break;
		sum = 0;
		fsm = sm*n;
		fsh = sh*n;
		fmh = mh*n;
		esm = tsm - fsm;
		esh = tsh - fsh;
		emh = tmh - fmh;
		for (ft3 = fmh, et3 = emh; et3 <= 43200; et3 += tmh, ft3 += tmh)
		{
			for (ft2 = fsh, et2 = esh; et2 <= 43200; et2 += tsh, ft2 += tsh)
			{
				if (et2<ft3)
					continue;
				if (ft2>et3)
					break;
				for (t = 0, ft1 = fsm, et1 = esm; et1 <= 43200; t = t + 1, et1 = esm + t*tsm, ft1 = fsm + t*tsm)
				{
					if (et1<ft3 || et1<ft2)
						continue;
					if (ft1>et3 || ft1>et2)
						break;
					max = ft1;
					if (ft2>max)
						max = ft2;
					if (ft3>max)
						max = ft3;
					min = et1;
					if (et2<min)
						min = et2;
					if (et3<min)
						min = et3;
					sum += min - max;
				}
			}
		}
		sum /= 432.;
		printf("%.3lfn", sum);
	}
}*/
/*
#include <cstdio>
#include <iostream>
using namespace std;
double max1(double a, double b, double c) {
	if (a<b) a = b;
	if (a<c) a = c;
	return a;
}
double min1(double a, double b, double c) {
	if (a>b) a = b;
	if (a>c) a = c;
	return a;
}
inline bool equal1(double a, double b) {
	if ((a - b)>-0.0000001 && (a - b)<0.0000001) 
		return true;
	else 
		return false;
}
int main() {
	double sum = 0.0, d, newx, newy;
	double mh = 43200.0000 / 11;
	double sm = 3600.0000 / 59;
	double sh = 43200.0000 / 719;
	double dsm, dsh, dmh, tdsm, tdsh, tdmh;
	while (scanf("%lf", &d) && d != -1) {
		sum = 0.0;
		dsm = 10.0*d / 59.0;  tdsm = sm - dsm;
		dsh = 120.0*d / 719.0;	 tdsh = sh - dsh;
		dmh = 120.0*d / 11.0;	 tdmh = mh - dmh;
		newx = max1(dsm, dsh, dmh); newy = min1(tdsm, tdsh, tdmh);
		while (newx <= 43200 && newy <= 43200) {
			newx = max1(dsm, dsh, dmh);
			newy = min1(tdsm, tdsh, tdmh);   	//cout<<newx<<" "<<newy; Sleep(1000);
			if (newx<newy) sum += newy - newx; //cout<<" "<<sum<<" ";Sleep(1000);
			if (newy == tdsm) { dsm += sm; tdsm += sm; }
			else if (newy == tdsh) { dsh += sh; tdsh += sh; }
			else if (newy == tdmh) { dmh += mh; tdmh += mh; }
		}
		printf("%.3lf\n", sum / 432);
	}
	return 0;
}
*/

/*
void main()
{
	double h, m, s,D;
	
	while (cin >> D)
	{
		double happy = 0;
		if (D != 0.0f)
			D /= 6;
		s = m = h = 0;
		for (int i = 0; i < 43200; ++i)
		{
			++s;
			vector<double> vec;
			set<double> se;
			if (s == 60.0f)
				s = 0, m++;
			if (m == 60.0f)
				m = 0, h++;
			se.insert(s);
			se.insert(h);
			se.insert(m);
			se.insert(s);
			if (s < D)
				se.insert(60.0f + D - s);
			else if (s + D > 60.0f)
				se.insert(60.0f - D - s);
			if (m < D)
				se.insert(60.0f + D - m);
			else if (m + D > 60.0f)
				se.insert(60.0f - D - m);
			if (h < D)
				se.insert(60.0f + D - h);
			else if (h + D > 60.0f)
				se.insert(60.0f - D - h);
			for (auto it : se)
				vec.push_back(it);
			
			sort(vec.begin(), vec.end());
			for (int j = 1; j < vec.size(); ++j)
			{
				if (vec[j] - vec[j - 1] >= D)
					happy++;
				else
					break;
			}
		}
		printf("%.3lf\n", happy / (43200));
	}
}
*/

/*
void main()
{
	long long int a,b;
	while (cin >> hex >> a >> hex >> b)
	{
		if (a + b < 0)
			cout << uppercase <<'-' << hex << -(a + b) << endl;
		else
			cout << uppercase << hex << a + b << endl;
	}
}*/

/*
void main()
{
	int A, B, n;
	while (cin >> A >> B >> n && (A || B || n))
	{
		int result[48];
		result[1] = result[2] = 1;
		for (int i = 3; i < 48; ++i)
			result[i] = (A*result[i - 1] + B*result[i - 2]) % 7;

		cout << result[n % 48] << endl;
	}
}*/

/*
void main()
{
	int n;
	while (cin >> n && n)
	{
		map<string, int> mp;
		string str;
		while(n-- && cin >> str)
			mp[str] += 1;

		map<int, string, greater<int>> mp2;
		for (auto it : mp)
			mp2[it.second] = it.first;
		cout << mp2.begin()->second << endl;
	}
}
*/
/*
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		int f = 1, g = 0;
		while (t--)
		{
			g += f;
			f = g - f;
		}
		cout << g << endl;
	}
}*/



/*
struct Stack
{
	int data[32];
	int top;
};

void transform(int n, int r)
{
	Stack s;
	int negative = 0;
	if (n < 0)
		negative = 1, n = -n;
	s.top = 0;

	while (n)
	{
		s.data[s.top++] = n % r;
		n /= r;
	}
	if (negative)
		cout << '-';
	for (int i = s.top - 1; i >= 0; --i)
		if (s.data[i] >= 10)
			cout << char('A' + s.data[i] - 10);
		else
			cout << s.data[i];
	cout << endl;
}

void main()
{
	int n, r;
	while (cin >> n >> r)
		transform(n, r);
}*/



/*
void output(char c, int n)
{
	cout << string(n, c);
}

void main()
{
	
	int n;
	cin >> n;
	while(n--)
	{
		char c;
		int m,t;
		cin >> c >> m;
		t = m - 3;
		int up = t / 2, down = t - up, width = m / 6 + 1;

		output(' ', width); output(c, down); cout << endl;
		for (int i = 0; i < up; ++i)
			output(c, width), output(' ', down), output(c, width), cout << endl;
		output(' ', width); output(c, down), cout << endl;
		for (int i = 0; i < down; ++i)
			output(c, width), output(' ', down), output(c, width), cout << endl;
		output(' ', width); output(c, down), cout << endl;
		if (n)
			cout << endl;
 	}
}*/

/*
void main()
{
	int t, n, tmp, pos1, pos2, max, now, x, i, j;
	cin >> t;
	for (i = 1; i <= t; i++)
	{
		cin >> n >> tmp;
		now = max = tmp;
		pos1 = pos2 = x = 1;
		for (j = 2; j <= n; j++)
		{
			cin >> tmp;
			if (now <0 )
				now = tmp, x = j;
			else
				now += tmp;
			if (now > max)
				max = now, pos1 = x, pos2 = j;
		}
		cout << "Case " << i << ":" << endl << max << " " << pos1 << " " << pos2 << endl;
		if (i != t)
			cout << endl;
	}
}*/


/*
int a[100001], sum[100001], s[100001];

void main()
{
	int n,m;
	cin >> n;
	m = 0;
	while (n--)
	{
		++m;
		int T;
		cin >> T;
		for (int i = 0; i < T; ++i)
			cin >> a[i];

		int end = 0;
		sum[0] = a[0];
		s[0] = 0;
		for (int i = 1; i < T; ++i)
		{
			if (sum[i - 1] >= 0)
			{
				sum[i] = sum[i - 1] + a[i];
				s[i] = s[i - 1];
			}
			else
			{
				sum[i] = a[i];
				s[i] = i;
			}
			if (sum[i] > sum[end])
				end = i;
		}
		cout << "Case " << m << endl
			<< sum[end] << " " << s[end] + 1 << " " << end + 1 << endl;
		if (n)
			cout << endl;
	}
}*/

/*
void main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int m,t; long long sum = 0;
		cin >> m;
		while (m--)
		{
			cin >> t;
			sum += t;
		}
		cout << sum << endl;
		if (n)
			cout << endl;
	}
}*/

/*
void main()
{
	string str;
	while (cin >> str)
	{
		auto it = max_element(str.begin(), str.end());
		char max = *it;
		string::size_type pos = 0;
		while( (pos = str.find(max,pos)) != string::npos)
		{ 
			char buffer[7];
			sprintf(buffer, "%c(max)", max);
			buffer[6] = '\0';
			str.replace(pos, 1, buffer);
			pos += 6;
		}
		cout << str << endl;
	}
}*/

/*
void main()
{
	int n;
	char Buffer[100];
	cin >> n;

	while (n--)
	{
		cin >> Buffer;
		int len = strlen(Buffer);
		int ok = 1;
		for (int i = 0; 2*i < len; ++i)
		{
			if (Buffer[i] != Buffer[len - i - 1])
			{
				printf("no\n");
				ok = 0;
				break;
			}
		}
		if (ok)
			printf("yes\n");
	}
}*/


/*
#include <stdio.h>
int run(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
int next(int year, int n)
{
	int i;
	for (i = year; n; ++i)
		if (run(i))
			n--;
	return i-1;
}

void main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int year, m;
		scanf("%d%d", &year, &m);
		printf("%d\n",next(year, m));
	}
}*/


/*
// HDU 1251
class AlphabetNode
{
public:
	AlphabetNode *next[26];
	int value;
	AlphabetNode() : value(0)
	{
		for (int i = 0; i < 26; ++i)
			next[i] = nullptr;
	}
};
AlphabetNode node[26];
void AddWord(const string& str)
{
	int len = str.size();
	AlphabetNode *pNode;
	pNode = &node[str[0]-'a'];
	pNode->value++;
	for (int i = 1; i < len; ++i)
	{
		int index = str[i] - 'a';
		if (pNode->next[index] == nullptr)
			pNode->next[index] = new AlphabetNode;
		pNode = pNode->next[index];
		pNode->value++;
	}
}
int FindStart(const string& str)
{
	int i;
	AlphabetNode *pNode = &node[str[0] - 'a'];
	for (i = 1; i < str.size(); ++i)
	{
		if (pNode->next[str[i] - 'a'] == nullptr)
			return 0;
		pNode = pNode->next[str[i] - 'a'];
	}
	return pNode->value;
}
void main()
{
	string str;
	while (getline(cin, str) && str.compare(""))
		AddWord(str);
	while (cin >> str)
		cout << FindStart(str) << endl;
}*/


/*
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void main()
{
	vector<int> vec;
	int n,i,t;
	while (cin >> n && n)
	{
		vec.clear();
		for (i = 0; i < n; ++i)
		{
			cin >> t;
			vec.push_back(t);
		}
		sort(vec.begin(), vec.end(), [](int a, int b) {
			return abs(a) > abs(b);
		});
		for (int i=0; i < (int)vec.size() ; ++i)
		{
			cout << vec[i];
			if (i != vec.size() - 1)
				cout << ' ';
		}
		cout << endl;
	}
}*/


/*
int table[30][31] = { {1},{1,1} };

void main()
{
	int n,i,j;

	for (i = 2; i <= 30; ++i)
	{
		table[i][0] = 1;
		for (j = 1; j <= i; ++j)
			table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
	}

	while (cin >> n)
	{
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j <= i; ++j)
			{
				cout << table[i][j];
				if (j != i)
					cout << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
}*/


/*
#include <iostream>
#include <string>
using namespace std;
void main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a == "#")
			break;
		int count = 0,tmp;
		for (int i = 0; i < a.size(); ++i)
		{
			if ((tmp = a.find(b, i)) != string::npos)
			{
				++count;
				i = tmp+b.size()-1;
			}
		}
		cout << count << endl;
	}
}
*/


/*
void main()
{
	char buffer[100];
	while (cin.getline(buffer,100))
	{
		int cn = 0, cd = 0;
		int number = 0;
		int len = strlen(buffer);
		bool ok = true;
		for (int i = 0; i < len; ++i)
		{
			char ch = buffer[i];
			if (isdigit(ch))
			{
				if (!number)
					cn++;
				number = number * 10 + ch - '0';
			}
			else if (ch == '.')
			{
				cd++;
				if (number > 255)
					ok = false;
				if (!ok)
					break;
				number = 0;
			}
			else
			{
				ok = false;
				break;
			}
		}
		if (cn != 4 || cd != 3 || number > 255)
			ok = false;
		if (ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
//cout << "cn : " << cn << "  cd : " << cd << "  last number : " << number << endl;
*/
/*
#include <vector>
#include <algorithm>
void main()
{
	int t,n,v,c,w;
	cin >> t;
	while (t-- && cin >> n >> v >> w)
	{
		vector<int> nongdu;
		while (n-- && cin >> c)
			nongdu.push_back(c);
		sort(nongdu.begin(), nongdu.end());
		if (nongdu[0] > w)
		{
			printf("0 0.00\n");
		}
		else
		{
			int currentV = v;
			int sum = currentV * nongdu[0];
			for (int i = 1; i < nongdu.size(); ++i)
			{
				//try to hunhe
				sum += v*nongdu[i];
				if ( sum <= w*(currentV+v) )
				{
					//ok
					currentV += v;
				}
				else
				{
					sum -= v*nongdu[i];
					break;
				}
			}
			printf("%d %.2lf\n", currentV, double(sum)/currentV/100);
		}
	}
}
*/

/*
int table[41] = { 0 };
int f(int x)
{
	if (table[x]) 
		return table[x];
	if (x == 1) 
		return table[x] = 3;
	else if (x == 2)
		return table[x] = 9;
	
	return table[x] = 2 * f(x - 1) + f(x - 2);
}

void main()
{
	int n,d;
	cin >> n;
	while (n-- && cin >> d)
		cout << f(d) << endl;
}*/


/*
void main()
{
	int n,up,d,len,i,c,j,f;
	string str;
	cin >> n;
	while (n-- && cin >> str)
	{
		up = 0;
		d = len = str.size();
		for (i = 0; i < len; ++i)
		{
			c = isupper(str[i]);
			for (j = i + 1; j < len; ++j)
				if (c != isupper(str[j]))
					break;
			f = j - i;
				
			if (c == 1 && up == 0 && f < 2)
				d++;
			else if (c == 1 && up == 0 && f >= 2)
				d++, up = 1;
			else if (c == 0 && up == 1 && f < 2 && j == len)
				d++,up=0;
			else if (c == 0 && up == 1 && f < 2)
				d++;
			else if (c == 0 && up == 1 && f >= 2)
				d++, up = 0;

			i = j - 1;
		}
		if (up)
			d++;
		cout << d << endl;
	}
}*/


/*
#include<stdio.h>
#include<string.h>

int _hash[110][2], len;
bool as[110];

int mi(int x, int y) {
	if (x>y)return y;
	else return x;
}

int ser(int i, bool z) {
	if (_hash[i][z] >= 0)
		return _hash[i][z];

	int x = 0;

	if (i >= len)
		x = z; 
	else
		if (z == as[i])
			x = ser(i + 1, z) + 1; 
		else
			x = mi(ser(i + 1, z), ser(i + 1, !z)) + 2;

	_hash[i][z] = x;

	return x;
}

int main() {
	int tcase, i;
	char s[110];
	scanf("%d", &tcase);
	while (tcase--&&scanf("%s", s) != EOF) {
		len = strlen(s);
		for (i = 0; i<len; i++) {
			as[i] = s[i]<'a';
			printf("%d",as[i]);
		}
		memset(_hash, -1, sizeof(_hash));
		printf("%d\n", ser(0, 0));
	}
	return 0;
}*/



/*void main()
{
	int n,i;
	string s;
	cin >> n;
	while (n-- && cin >> i)
		s += char(i);
	cout << s;
}*/

/*
#include <iostream>
using namespace std;
void main()
{
	int year, month, day;
	int days_1[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days_2[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int r, i;
	char c;
	while (cin >> year >> c >> month >> c >> day)
	{
		r = 0;
		if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
			r = 1;
		for (i = 0; i < month - 1; ++i)
		{
			if (r)
				day += days_2[i];
			else
				day += days_1[i];
		}
		cout << day << endl;
	}
}*/



/* HDU 2016
#include <iostream>
using namespace std;

void main()
{
	int i, n, t, d[100], min, m;
	while (cin >> n)
	{
		if (n == 0)
			break;
		for (i = 0; i < n; ++i)
			cin >> d[i];
		m = 0;
		min = 0xfffffff;
		for (i = 0; i < n; ++i)
			if (min > d[i])
			{
				m = i;
				min = d[i];
			}
		t = d[0];
		d[0] = min;
		d[m] = t;
		for (i = 0; i < n; ++i)
		{
			cout << d[i];
			if (i != n - 1)
				cout << " ";
		}
		cout << endl;
	}
}
*/


/* HDU 2015
#include <stdio.h>
void main()
{
	int n, m, i, num;
	while (~scanf("%d%d", &n, &m))
	{
		num = n / m;

		printf("%d", m + 1);
		if (num != 1 || n % m != 0)
			printf("/");
		for (i = 2; i < num + 1; ++i)
		{
			printf("%d", 2 * m*i - m + 1);
			if (i != num)
				printf("*");
		}
		if (i == 2)
			i = 1;
		else
			--i;
		if (n % m != 0)
		{
			if (num != 1)
				printf("@");
			printf("%d", (n*(n + 1) - m*i*(m*i + 1)) / (n%m));
		}
		printf("\n");
	}
}*/
/*
#include <stdio.h>
void main()
{
	int n, m, i, num;
	while (~scanf("%d%d", &n, &m))
	{
		num = n / m;

		printf("%d", m + 1);
		if (num != 1 || n % m != 0)
			printf(" ");
		for (i = 2; i < num + 1; ++i)
		{
			printf("%d", 2 * m*i - m + 1);
			if (i != num)
				printf(" ");
		}
		if (i == 2)
			i = 1;
		else
			--i;
		if (n % m != 0)
		{
			if (num != 1)
				printf(" ");
			printf("%d", (n*(n + 1) - m*i*(m*i + 1)) / (n%m));
		}
		printf("\n");
	}
}
*/


/*
#include<iostream>
using namespace std;

int main()
{
	int n, m, s, i, j, k;
	while (cin >> n >> m)
	{
		for (i = 1; i <= n; i += m)
		{
			s = 0;
			k = 0;
			for (j = i; j < i + m && j <= n; j++, k++)
				s += 2 * j;
			cout << s / k;
			if (i + m > n)
				cout << endl;
			else
				cout << " ";
		}
	}
	return 0;
}
*/


/*
void main()
{
	int t, a, b, i;
	vector<int> c;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;

		c.clear();
		for (i = 1; i < a; ++i)
			if (a % i == 0)
				c.push_back(i);

		i = 0;
		for (auto it = c.begin(); it != c.end(); ++it)
			i += *it;
		if (i != b)
		{
			cout << "NO" << endl;
			continue;
		}

		c.clear();
		for (i = 1; i < b; ++i)
			if (b % i == 0)
				c.push_back(i);

		i = 0;
		for (auto it = c.begin(); it != c.end(); ++it)
			i += *it;
		if (i != a)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
}
*/

/*
// HDU 1002
void main()
{
	int t,i,j,k,n;
	string s1, s2;
	int a[1005], b[1005],c[1005];
	cin >>t;
	n = 0;
	while (t--)
	{
		++n;
		cin >> s1 >> s2;

		for (i = 0; i < (int)s1.size(); ++i)
		{
			a[s1.size() - i-1] = s1[i] - '0';
		}
		for (i = 0; i < (int)s2.size(); ++i)
		{
			b[s2.size() - i-1] = s2[i] - '0';
		}
		j = s1.size() > s2.size() ? s1.size() : s2.size();
		k = 0;
		for (i = 0; i < j; ++i)
		{
			c[i] = 0;
			if (k > 0)
			{
				c[i] = k;
				k = 0;
			}
			if (i < (int)s1.size())
				c[i] += a[i];
			if (i < (int)s2.size())
				c[i] += b[i];
			if (c[i] >= 10)
			{
				k = c[i] / 10;
				c[i] -= 10;
			}
		}
		if (k > 0)
		{
			++j;
			c[i] = k;
		}
		cout << "Case " << n << ':' << endl;
		cout << s1 << " + " << s2 << " = ";
		for (i = 0; i < j; ++i)
			cout << (char)(c[j - i - 1] + '0');

		cout << endl;
		if (t)
			cout << endl;
	}
}*/


/*
#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.1415927
void main()
{
double r;
cout << fixed << setprecision(3);
while (cin >> r)
cout << PI*r*r*r*4/3 << endl;
}
*/