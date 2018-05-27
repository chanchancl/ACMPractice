
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
using namespace std;

#define rep(i,a,b) for(int i=a; i < b; ++i)
#define pre(i,a,b) for(int i=a; i >=b; --i)
#define all(x) x.begin(),x.end()
using ll = long long;

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