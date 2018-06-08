
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <cctype>
#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <numeric>
#include <bitset>
using namespace std;

const int INF = 0x3f3f3f3f;
#define rep(i,a,b) for(int i=a; i < b; ++i)
#define pre(i,a,b) for(int i=a; i >=b; --i)
#define all(x) x.begin(),x.end()
using ll = long long;

int main()
{


	return 0;
}



/*
int main()
{
	int a, n, m;
	cin >> a >> n >> m;

	vector<int> rain(a + 1, 0);
	vector<int> umb(a + 1, INF);

	rep(i, 0, n) {
		int l, r;
		cin >> l >> r;
		rep(j, l, r)
			rain[j] = 1;
	}

	rep(i, 0, m) {
		int x, p;
		cin >> x >> p;
		umb[x] = min(umb[x], p);
	}
	vector<int> dp(a + 1, INF);	
	dp[0] = 0;

	rep(i, 1, a + 1) {
		if (!rain[i - 1]) {
			dp[i] = dp[i - 1];
		}
		else {
			pre(j, i - 1, 0) {
				if (umb[j] != INF)
					dp[i] = min(dp[i], dp[j] + (i - j)*umb[j]);
			}
		}
	}
	if (dp[a] == INF)
		cout << -1;
	else
		cout << dp[a];


	return 0;
}
*/


/*
const int N = 1e5+5;
list<int> g[N];
bool visit[N];
int ans = 0;

int dfs(int x) {
	int res = 0;
	
	for (auto i : g[x]) {
		if (!visit[i]) {
			visit[i] = true;
			int tmp = dfs(i);
			if (tmp % 2 == 0)
				ans++;
			res += tmp;
		}
	}
	return res + 1;
}


int main()
{
	int n;
	cin >> n;

	rep(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	if (n & 1)
		cout << -1;
	else {
		visit[1] = true;
		dfs(1);
		cout << ans << endl;
	}

	return 0;
}
*/


/*
const int INF = 0x3fffffff;

int main()
{
	ll n;
	cin >> n;

	string s = to_string(n);

	int ans = INF;
	rep(i, 0, s.size()) {
		rep(j, 0, s.size()) {
			if (i == j) continue;
			string t = s;
			int cnt = 0;

			rep(k, i, s.size() - 1) {
				swap(t[k], t[k + 1]);
				cnt++;
			}

			int k = j;
			if (j > i)
				k--;
			for (; k < s.size() - 2; ++k) {
				swap(t[k], t[k + 1]);
				cnt++;
			}

			int pos = -1;
			pos = find_if(all(t), [](char c) {return c != '0'; }) - t.begin();

			for (k = pos; k > 0; k--) {
				swap(t[k], t[k - 1]);
				cnt++;
			}
			ll now = atoll(t.c_str());

			if (now % 25 == 0)
				ans = min(ans, cnt);
		}
	}
	if (ans == INF)
		cout << "-1";
	else
		cout << ans;

	return 0;
}
*/

/*
int const N = 2 * 1e5 + 5;

int x[N];
map<int, bool> enable;

int main() 
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	rep(i, 0, n) {
		cin >> x[i];
		enable[x[i]] = true;
	}

	sort(x, x + n);
	vector<int> res = { x[0] };

	rep(i, 0, n) {
		rep(j, 0, 31) {
			int lx = x[i] - (1 << j);
			int rx = x[i] + (1 << j);
			bool isl = binary_search(x, x + n, lx);
			bool isr = binary_search(x, x + n, rx);
			if (isl && isr && res.size() < 3) 
				res = { lx, x[i], rx };
			if (isl && res.size() < 2)
				res = { lx, x[i] };
			if (isr && res.size() < 2)
				res = { x[i], rx };
		}
	}
	cout << res.size() << endl;
	rep(i, 0, res.size())
		cout << res[i] << ' ';

	return 0;
}
*/


/*
struct node{
	int i, j;
	int sum;
};

bool operator<(node & a, node & b) {
	return a.sum < b.sum;
}

int main()
{
	int k;
	cin >> k;

	vector<vector<int>> v(k);
	vector<int> n(k);
	vector<node> vnode;

	rep(i, 0, k) {
		cin >> n[i];
		int sum = 0;
		
		v[i].resize(n[i]);
		rep(j, 0, n[i]) cin >> v[i][j], sum += v[i][j];
		rep(j, 0, n[i]) {
			node t;
			t.i = i + 1;
			t.j = j + 1;
			t.sum = sum - v[i][j];
			vnode.push_back(t);
		}
	}

	sort(all(vnode));
	
	bool flag = false;
	rep(i, 0, vnode.size() - 1) {
		if (vnode[i].sum == vnode[i + 1].sum && vnode[i].i != vnode[i+1].i) {
			flag = true;
			cout << "YES" << endl;
			cout << vnode[i].i << ' ' << vnode[i].j << endl;
			cout << vnode[i+1].i << ' ' << vnode[i+1].j << endl;
			break;
		}
	}
	if (!flag)
		cout << "NO";

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;

	vector<string> v(n);
	rep(i, 0, n) cin >> v[i];

	sort(all(v), [](string& a, string& b) {
		return a.size() < b.size();
	});

	bool flag = true;
	rep(i, 0, n - 1) {
		if (v[i + 1].find(v[i]) == string::npos)
		{
			flag = false;
			break;
		}
	}
	if (!flag)
		cout << "NO";
	else
	{
		cout << "YES" << endl;
		rep(i, 0, n)
			cout << v[i] << endl;
	}

	return 0;
}
*/

/*
int id[105];

int main() 
{
	int n, k;
	cin >> n >> k;

	set<int> s;

	rep(i, 0, n) {
		int t;
		cin >> t;
		s.insert(t);
		id[t] = i + 1;
	}

	if (s.size() < k)
		cout << "NO";
	else
	{
		cout << "YES" << endl;
		int cnt = 0;
		for (auto i : s) {
			cout << id[i] << ' ';
			cnt++;
			if (cnt >= k)
				break;
		}
	}

	return 0;
}
*/


/*
const int N = (1 << 22) - 1;

int a[N];
bool exist[N], visit[N];
int n, m, mask;

void search(int x) 
{
	if (visit[x]) return;
	visit[x] = true;

	// ~x 存在，将其本身标记为已搜索
	if (exist[x]) search(mask ^ x);

	rep(i, 0, n) {
		// 搜索所有子集
		if ((x&(1 << i)) != 0) {
			// 若第i位为1，则将其置0，然后搜索
			search(x ^ (1 << i));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;

	mask = (1 << n) - 1;

	rep(i, 0, m) cin >> a[i], exist[a[i]] = true;

	int ans = 0;

	rep(i, 0, m) {
		if (!visit[a[i]]) {
			search(mask ^ a[i]);
			ans++;
		}
	}

	cout << ans;

	return 0;
}
*/


/*
const int N = 1000005;
int a[N];
int id[N];

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i], id[a[i]] = i;

	int cnt = 0;

	rep(i, 1, n + 1) {
		if (a[i] != i) {
			a[id[i]] = a[i];
			id[a[i]] = id[i];
			a[i] = i;
			cnt++;
		}
	}

	if (((cnt + 3 * n) & 1) == 0)
		cout << "Petr";
	else
		cout << "Um_nik";
	
	return 0;
}
*/


/*
const int N = 100005;
int n, m, k, s;
int type[N], tvi[105], dis[N][105];
bool visit[N];
list<int> v[N];

void bfs(int tid)
{
	memset(visit, false, sizeof visit);

	queue<int> q;
	
	rep(i, 1, n + 1) if (type[i] == tid) {
		q.push(i);
		dis[i][tid] = 0;
		visit[i] = true;
	}

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (auto i : v[now]) {
			if (!visit[i]) {
				dis[i][tid] = dis[now][tid] + 1;
				visit[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> m >> k >> s;

	rep(i, 1, n + 1) cin >> type[i];

	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	rep(i, 1, k + 1)
		bfs(i);

	rep(i, 1, n + 1) {
		int ans = 0;
		sort(dis[i] + 1, dis[i] + k + 1);
		rep(j, 1, s + 1)
			ans += dis[i][j];
		cout << ans << ' ';
	}

	return 0;
}
*/


/*
int main()
{
	int a, b;
	cin >> a >> b;

	if (log(a)*b > (log(b)*a))
		puts(">");
	else if (log(a)*b < (log(b)*a))
		puts("<");
	else
		puts("=");
	return 0;
}
*/

/*
int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v(n);

	rep(i, 0, n) {
		cin >> v[i].first;
	}
	rep(i, 0, n) {
		cin >> v[i].second;
	}

	vector<int> ans(n + 1);

	bool flag = false;
	rep(i, 1, n - 1) {
		int ml, mr;
		ml = mr = inf;
		rep(j, 0, i) if (v[j].first < v[i].first) 
			ml = min(ml, v[j].second);
		
		rep(j, i + 1, n) if (v[j].first > v[i].first)
			mr = min(mr, v[j].second);

		if (ml != inf && mr != inf) {
			flag = true;
			ans[i] = ml + mr + v[i].second;
		}
	}

	if (!flag)
		cout << -1;
	else
	{
		int res = inf;
		rep(i, 1, ans.size()) {
			if (ans[i] > 0 && ans[i] < res)
				res = ans[i];
		}
		cout << res << endl;
	}

	return 0;
}
*/

/*
int main()
{
	map<string, string> mp;
	mp["purple"] = "Power";
	mp["green"] = "Time";
	mp["blue"] = "Space";
	mp["orange"] = "Soul";
	mp["red"] = "Reality";
	mp["yellow"] = "Mind";

	vector<string> v;
	v.push_back("Power");
	v.push_back("Time");
	v.push_back("Space");
	v.push_back("Soul");
	v.push_back("Reality");
	v.push_back("Mind");

	int n;
	cin >> n;
	rep(i, 0, n) {
		string s;
		cin >> s;
		v.erase(find(all(v),mp[s]));;
	}

	cout << v.size() << endl;
	rep(i, 0, v.size()) {
		cout << v[i] << endl;
	}


	return 0;
}
*/


/*
const int N = 100005;
int out[N], ans[N];

int main()
{
	int n;
	scanf("%d", &n);
	rep(i, 0, n - 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		out[a]++;
		out[b]++;
	}

	int id, maxout=-1, cnt = 0;
	bool flag = false;
	rep(i, 1, n + 1) {
		if (out[i] > 2) {
			flag = true;
			id = i;
			maxout = out[i];
		}
		if (out[i] == 1)
			ans[cnt++] = i;
	}
	if (!flag) {
		printf("Yes\n1\n%d %d\n", ans[0], ans[1]);
	}
	else if (cnt == maxout) {
		printf("Yes\n%d\n", cnt);
		rep(i, 0, cnt)
			printf("%d %d\n", id, ans[i]);
	}
	else
		printf("No\n");

	return 0;
}
*/


/*
const int N = 100005;
int out[N], visit[N], n;
int va[N], vb[N];
vector<int> v[N];
vector<int> res;
bool rt = true;


void bfs(int id) {

	queue<int> q;
	q.push(id);
	visit[id] = 1;

	while (!q.empty()) {
		int u = q.front(), vv;
		q.pop();

		// 不和id紧邻的地方，有多条岔路，直接gg
		if (u != id && v[u].size() > 2) {
			rt = false;
			return;
		}

		// 向外延伸
		bool flag = false;
		vv = -1;
		rep(i, 0, v[u].size()) {
			vv = v[u][i];

			if (visit[vv]) continue;
			flag = true;

			visit[vv] = 1;
			q.push(vv);
		}

		// 该节点是树的边缘（出度为1)
		if (!flag) res.push_back(u);
	}
}

int main()
{
	scanf("%d", &n);

	int Max = 0, id;
	rep(i, 0, n - 1) {
		int a, b;
		scanf("%d %d", &a, &b);
		va[i] = a;
		vb[i] = b;
		v[a].push_back(b);
		v[b].push_back(a);

		out[a]++;
		if (out[a] > Max) {
			Max = out[a];
			id = a;
		}
		out[b]++;
		if (out[b] > Max) {
			Max = out[b];
			id = b;
		}
	}

	rep(i, 0, n - 1) {
		int a = va[i], b = vb[i];
		if (out[a] > 2 && out[b] > 2) {
			printf("No\n");
			return 0;
		}
	}

	bfs(id);

	if (!rt) {
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
	if (res.size() == 1) {
		printf("1\n%d %d\n", id, res[0]);
	}
	else if (res.size() == 2) {
		printf("1\n%d %d\n", res[0], res[1]);
	}
	else {
		printf("%d\n", res.size());
		rep(i, 0, res.size()) {
			printf("%d %d\n", id, res[i]);
		}
	}

	return 0;
}
*/


/*
int main()
{
	string str;
	cin >> str;

	set<char> s;
	for (auto i : str) s.insert(i);

	if (s.size() == 1)
	{
		cout << 0;
		return 0;
	}

	bool flag = true;
	rep(i, 0, str.size() / 2) {
		if (str[i] != str[str.size() - i - 1]) {
			flag = false;
			break;
		}
	}
	if (!flag) {
		cout << str.size();
		return 0;
	}

	pre(j, str.size() - 2, 0) {
		int i, t;

		bool flag = true;
		for (i = 0, t = j; t >= 0; i++, --t) {
			if (str[i] != str[t]) {
				flag = false;
				break;
			}
		}
		if (!flag) {
			cout << j + 1;
			return 0;
		}
	}

	return 0;
}
*/

/*
int main()
{
	int n, m;
	cin >> n;

	map<int, int> mp;

	rep(i, 0, n) {
		int a, b;
		cin >> a >> b;
		mp[a] = b;
	}
	cin >> m;
	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		mp[a] = max(mp[a], b);
	}

	ll res = 0;
	for (auto i : mp)
		res += i.second;

	cout << res;

	return 0;
}
*/



/*
const int N = 2005;
int n, u[N], v[N], f[N][11][11][11][11];

int dis(int a, int b) { return abs(a - b); }

int dfs(int i, int cur, int a,int b,int c)
{
	if (~f[i][cur][a][b][c]) return f[i][cur][a][b][c];
	int ret = 0x3f3f3f3f;
	if (i > n) {
		if (a == 0 && b==0 && c==0) return 0;
		if (a) ret = min(ret, dfs(i, a, 0, b, c) + dis(cur, a) + 1);
		if (b) ret = min(ret, dfs(i, b, a, 0, c) + dis(cur, b) + 1);
		if (c) ret = min(ret, dfs(i, c, a, b, 0) + dis(cur, c) + 1);
		return f[i][cur][a][b][c] = ret;
	}
	if (a) ret = min(ret, dfs(i, a, 0, b, c) + dis(cur, a) + 1);
	if (b) ret = min(ret, dfs(i, b, a, 0, c) + dis(cur, b) + 1);
	if (c) ret = min(ret, dfs(i, c, a, b, 0) + dis(cur, c) + 1);
	if (a && b && c) {
		ret = min(ret, dfs(i + 1, v[i], a, b, c) + dis(cur, u[i]) + dis(u[i], v[i]) + 2);
		ret = min(ret, dfs(i + 1, a, v[i], b, c) + dis(cur, u[i]) + dis(u[i], a) + 2);
		ret = min(ret, dfs(i + 1, b, a, v[i], c) + dis(cur, u[i]) + dis(u[i], b) + 2);
		ret = min(ret, dfs(i + 1, c, a, b, v[i]) + dis(cur, u[i]) + dis(u[i], c) + 2);
	}
	else {
		if (!a) ret = min(ret, dfs(i + 1, u[i], v[i], b, c) + dis(cur, u[i]) + 1);
		else if (!b) ret = min(ret, dfs(i + 1, u[i], a, v[i], c) + dis(cur, u[i]) + 1);
		else ret = min(ret, dfs(i + 1, u[i], a, b, v[i]) + dis(cur, u[i]) + 1);
	}
	return f[i][cur][a][b][c] = ret;
}


int main()
{
	memset(f, 0xff, sizeof f);
	cin >> n;
	rep(i, 1, n+1) cin >> u[i] >> v[i];
	cout << dfs(1, 1, 0, 0, 0);

	return 0;
}
*/

/*
char mp[105][105];
int n, m;

bool check(int x, int y)
{
	int ar[][2]={
		{1,0},{1,1},{0,1},{-1,1},
		{-1,0},{-1,-1},{0,-1},{1,-1}
	};

	if (mp[y][x] == '*') return true;

	int sum = 0;
	rep(i, 0, 8) {
		int xx, yy;
		xx = x + ar[i][0], yy = y + ar[i][1];
		if (xx >= 1 && xx < m && yy >= 1 && yy < n) {
			if (mp[yy][xx] == '*') sum++;
		}
	}
	if (mp[y][x] == '.' && sum == 0)
		return true;
	if (sum == mp[y][x] - '0')
		return true;
	else
		return false;
}

int main()
{
	cin >> n >> m;

	n++, m++;
	rep(y, 1, n)
		cin >> (mp[y]+1);

	bool flag = true;
	rep(y, 1, n) {
		rep(x, 1, m) {
			if (!check(x, y))
				flag = false;
			if (!flag)
				break;
		}
		if (!flag)
			break;
	}
	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}
*/


/*
int main()
{
	int n;
	cin >> n;
	vector<int> v(n / 2);
	rep(i, 0, n / 2) cin >> v[i];

	sort(all(v));

	int black, white;
	black = white = 0;

	rep(i, 0, n / 2) 
		black += abs((1 + 2 * i) - v[i]);
	
	rep(i, 0, n / 2)
		white += abs(((i + 1) * 2) - v[i]);

	cout << min(black, white);

	return 0;
}
*/

/*
int main() 
{
	int n;
	cin >> n;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> one;
	priority_queue<pair<int, int>> two;

	rep(i, 0, n) {
		int t;
		cin >> t;
		one.push(make_pair(t, i + 1));
	}

	rep(i, 0, 2 * n) {
		char c;
		cin >> c;
		if (c == '0') {
			auto q = one.top();
			one.pop();
			cout << q.second << ' ';
			two.push(q);
		}
		else
		{
			auto q = two.top();
			two.pop();
			cout << q.second << ' ';
		}
	}

	return 0;
}
*/

/*
int main()
{
	long long n;
	cin >> n;
	n += 1;

	if (n == 1)
		cout << 0;
	else if (n % 2 == 0)
		cout << n / 2;
	else
		cout << n;

	return 0;
}
*/

/*
int main()
{
	int n;
	string str;
	cin >> n >> str;

	bool flag = true;

	if (n == 1 && str[0] == '0')
		flag = false;

	rep(i, 0, n) {
		if (i >= 1 && str[i] == '1' && str[i - 1] == '1') {
			flag = false;
			break;
		}
		if (i >= 2 && str[i] == '0' && str[i - 1] == '0' && str[i - 2] == '0') {
			flag = false;
			break;
		}
		if (str[0] == '0' && str[1] == '0') {
			flag = false;
			break;
		}
		if (str[n - 1] == '0' && str[n - 2] == '0') {
			flag = false;
			break;
		}
	}
	if (flag)
		cout << "Yes";
	else
		cout << "No";
	
	return 0;
}
*/

/*
int value[5005][5005], ans[5005][5005];
int v[5005];
int Max;

int main()
{
	int n, q;
	cin >> n;
	rep(i, 1, n + 1) cin >> v[i];

	rep(i, 1, n + 1) {
		value[1][i] = v[i];
		ans[i][i] = v[i];
	}
	rep(i, 2, n + 2) {
		rep(j, 1, n - i + 2) {
			value[i][j] = value[i - 1][j] ^ value[i - 1][j + 1];
			ans[j][j + i - 1] = max(max(value[i][j], ans[j][j +i-2]), ans[j+1][j + i - 1]);
		}
	}

	cin >> q;
	
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << ans[l][r] << endl;
	}

	return 0;
}
*/

/*
ll gcd(ll a, ll b) {
	if (b != 0) return gcd(b, a % b);
	return a;
}

int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		ll p, q, b;
		scanf("%I64d%I64d%I64d", &p, &q, &b);

		if (p % q == 0) {
			printf("Finite\n");
			continue;
		}

		ll t = gcd(p, q);
		
		p /= t, q /= t;
		if (q == 1) {
			printf("Finite\n");
			continue;
		}
		while (q != 1 && b != 1) {
			b = gcd(q, b);
			q /= b;
		}

		if (q == 1)
			printf("Finite\n");
		else
			printf("Infinite\n");
	}

	return 0;
}
*/


/*
int main()
{
	int n, k;

	cin >> n >> k;
	vector<int> ski(n + 1), ans(n+1);
	vector<pair<int, int>> v(n + 1);

	rep(i, 1, n + 1) { 
		cin >> ski[i];
		v[i].first = i;
		v[i].second = ski[i];
	}
	sort(v.begin()+1, v.end(), [](pair<int, int> &a, pair<int, int> &b) {
		return a.second < b.second;
	});

	ans[v[1].first] = 0;
	rep(i, 2, n + 1) {
		if (v[i].second > v[i - 1].second)
			ans[v[i].first] = i - 1;
		else
			ans[v[i].first] = ans[v[i - 1].first];
	}

	rep(i, 0, k) {
		int a, b;
		cin >> a >> b;
		if (ski[a] > ski[b] && ans[a] > 0)
			ans[a]--;
		else if (ski[a] < ski[b] && ans[b] > 0)
			ans[b]--;
	}

	rep(i, 0, n) cout << ans[i+1] << ' ';

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	list<int> v;
	rep(i, 0, n) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	v.sort();

	while (v.size() > 1) {
		if (v.size() > 1)
			v.pop_back();
		if (v.size() > 1)
			v.pop_front();
	}
	cout << v.back();

	return 0;
}
*/


/*
int main()
{
	int n, w;
	cin >> n >> w;
	vector<int> v(n);
	rep(i, 0, n) {
		cin >> v[i];
		if (i != 0)
			v[i] += v[i - 1];
	}

	int a = *max_element(all(v));
	int p = *min_element(all(v));
	int ans = w - (a > 0 ? a : 0) + 1 - (p < 0 ? -p : 0);
	if (abs(a) > w || abs(p) > w || ans <= 0)
		cout << 0;
	else
		cout << ans;

	return 0;
}
*/


/*
int n, r = -1;
vector<int> v;

int find(int id, int cnt, int a, int b) {
	int ans = 0;
	if (id >= n && (cnt < r || r == -1)) {
		r = cnt;
		return -1;
	}
	int c = v[id], t = -1;
	if (b - a == c - b || id < 2)
		t = find(id + 1, cnt, b, c);
	if (t == -1 && (b - a == c + 1 - b || id < 2))
		t = find(id + 1, cnt + 1, b, c + 1);
	if (t == -1 && (b - a == c - 1 - b || id < 2))
		t = find(id + 1, cnt + 1, b, c - 1);
	if (t == -1)
		return -1;

	ans += t;
	return ans;
}

int main()
{
	cin >> n;

	if (n <= 2)
	{
		cout << 0 << endl;
		return 0;
	}
	v.resize(n);
	rep(i, 0, n) cin >> v[i];

	find(0, 0, 0, 0);
	cout << r;

	return 0;
}
*/