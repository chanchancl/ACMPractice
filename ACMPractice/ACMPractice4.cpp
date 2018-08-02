
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
#define FASTIO ios::sync_with_stdio(false),cin.tie(0);
#define rep(i,a,b) for(int i=a; i < b; ++i)
#define pre(i,a,b) for(int i=a; i >=b; --i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main()
{

	return 0;
}


/*
int n, m;
vector<string> str;

vector<pair<pii,int>> ans;

void check(int i, int j) {
	if (str[i][j] != '*' && str[i][j] != 'x')
		return;

	int dx[4] = { 1,0, -1, 0 };
	int dy[4] = { 0,1,  0, -1 };

	int a[4] = { 0,0,0,0 };
	rep(q, 0, 4) {
		int xx = i + dx[q], yy = j + dy[q];
		while (xx >= 0 && xx <= n - 1 && yy >= 0 && yy <= m - 1) {
			if (str[xx][yy] == '*' || str[xx][yy] == 'x') {
				a[q]++;
				xx += dx[q], yy += dy[q];
			}
			else
				break;
		}
	}
	int cnt = *min_element(a, a + 4);

	if (cnt > 0) {
		str[i][j] = 'x';
		ans.push_back(make_pair(make_pair(i+1,j+1),cnt));
		rep(q, 0, 4) {
			int xx = i + dx[q], yy = j + dy[q];
			rep(t, 0, cnt) {
				str[xx][yy] = 'x';
				xx += dx[q];
				yy += dy[q];
			}
		}
	}
}

int main()
{

	cin >> n >> m;
	str.resize(n);

	rep(i, 0, n) 
		cin >> str[i];
	
	rep(i, 1, n - 1) {
		rep(j, 1, m - 1) {
			check(i, j);
		}
	}
	rep(i, 0, n) {
		//cout << str[i] << endl;
		if (str[i].find('*') != string::npos) {
			cout << -1 << endl;
			return 0;
		}
	}

	cout << ans.size() << endl;
	rep(i, 0, ans.size()) 
		cout << ans[i].first.first << ' ' << ans[i].first.second << ' ' << ans[i].second << endl;

	return 0;
}
*/



/*
int main()
{
	FASTIO;

	ll n, k, s;
	cin >> n >> k >> s;

	if ((n - 1)*k < s || s < k) {
		cout << "NO" << endl;
		return 0;
	}

	int now = 1;
	vector<int> ans;

	while (k) {
		if (s > k) {
			int step = min(n - 1, s - (k - 1));
			if (now == 1) now += step;
			else now -= step;
			s -= step;
		}
		else {
			if (now == 1) now++;
			else now--;
			s--;
		}
		ans.push_back(now);
		k--;
	}
	
	cout << "YES" << endl;
	for (auto i : ans)
		cout << i << ' ';

	return 0;
}
*/

/*
int main()
{
	int n, m;
	cin >> n >> m;
	vector<pii> v(n);
	vector<int> diff(n);

	ll before = 0, after = 0;
	rep(i, 0, n) {
		cin >> v[i].first >> v[i].second;
		diff[i] = v[i].first - v[i].second;
		before += v[i].first;
		after += v[i].second;
	}

	if (after > m) {
		cout << -1 << endl;
		return 0;
	}

	if (before <= m) {
		cout << 0 << endl;
		return 0;
	}

	sort(all(diff), greater<int>());

	vector<ll> dif(n);
	dif[0] = diff[0];
	rep(i, 1, n)
		dif[i] = dif[i - 1] + diff[i];

	rep(i, 0, n) {
		if (before - dif[i] <= m) {
			cout << i + 1 << endl;
			return 0;
		}
	}

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	if (s == t) {
		cout << 0 << endl;
		return 0;
	}

	string ss(s), tt(t);
	sort(all(ss));
	sort(all(tt));
	if (ss != tt) {
		cout << -1 << endl;
		return 0;
	}


	vector<int> ans;
	int cnt = 0;
	// a
	// ...a
	rep(i, 0, t.size()) {
		if (s[i] != t[i]) {
			int pos = find(s.begin() + i, s.end(), t[i]) - s.begin();
			pre(j, pos - 1, i) {
				swap(s[j], s[j + 1]);
				ans.push_back(j + 1);
			}
		}
	}

	//cout << s << endl;
	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i << ' ';

	return 0;
}
*/


/*
int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> v(m + 1, 0);

	rep(i, 0, n) {
		int l, r;
		cin >> l >> r;
		rep(i, l, r + 1)
			v[i]++;
	}

	cout << count(v.begin() + 1, v.end(), 0) << endl;
	rep(i, 1, m + 1) if (v[i] == 0)
		cout << i << ' ';

	return 0;
}
*/

/*
int main()
{
	FASTIO;

	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	set<int> s;
	rep(i, 0, n) {
		cin >> v[i];
		s.insert(v[i]);
	}
	if (s.size() < n) {
		cout << 0 << endl;
		return 0;
	}

	sort(all(v));

	rep(i, 0, n) {
		int t = v[i] & x;
		int pos = lower_bound(all(v), t) - v.begin();
		//cout << t  << " " << pos << " " << i << endl;
		if (pos != n && pos != i && v[pos] == t) {
			cout << 1 << endl;
			return 0;
		}
	}

	s.clear();
	rep(i, 0, n) {
		v[i] &= x;
		s.insert(v[i]);
	}

	if (s.size() < n) {
		cout << 2 << endl;
		return 0;
	}
	
	cout << -1 << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	ll sum1 = 0;
	rep(i, 0, n) {
		int t;
		cin >> t;
		sum1 += t;
	}
	ll sum2 = 0;
	rep(i, 0, n) {
		int t;
		cin >> t;
		sum2 += t;
	}
	if (sum1 >= sum2)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
*/

/*
int count(int x) {
	set<int> s;
	for (int a = 0; a <= x; a++)
		for (int b = 0; a + b <= x; b++)
			for (int c = 0; a + b + c <= x; c++)
			{
				int d = x - a - b - c;
				s.insert(a + b * 5 + c * 10 + d * 50);
			}
	return s.size();
}

int main()
{
	int n;
	cin >> n;
	if (n <= 12)
		cout << count(n) << endl;
	else
		cout << count(12) + ll(n - 12) * 49 << endl;

	return 0;
}
*/

/*
int main()
{
	int n, k;
	cin >> n >> k;

	rep(i, 0, k) {
		int l, r;
		cin >> l >> r;
	}
	rep(i, 0, n) {
		if (i % 2)
			cout << 1;
		else
			cout << 0;
	}

	return 0;
}
*/

/*
int main()
{
	int h, m;
	cin >> h >> m;

	int H, D, C, N;
	cin >> H >> D >> C >> N;

	if (h >= 20) {
		double ans = ceil(1.0 * H / N) * C * 0.8;
		cout << fixed << setprecision(8) << ans << endl;
	}
	else {
		double ans1 = ceil(1.0 * H / N) * C;
		double ans2 = ceil((1.0 * H + D * ((19 - h) * 60 + 60 - m)) / N) * C * 0.8;
		cout << fixed << setprecision(8) << min(ans1,ans2) << endl;
	}

	return 0;
}
*/


/*
int main()
{
	int n, k;
	cin >> n >> k;
	vector<pair<int, pii>> v(n);
	rep(i, 0, n) {
		cin >> v[i].first;
		v[i].second.first = i;
	}
	rep(i, 0, n)
		cin >> v[i].second.second;

	sort(all(v));

	ll money = 0;
	priority_queue<ll, vector<ll>, greater<ll>> p;
	vector<ll> ans(n);

	rep(i, 0, n) {
		money += v[i].second.second;

		ans[v[i].second.first] = money;
		p.push(v[i].second.second);

		if (p.size() > k) {
			money -= p.top();
			p.pop();
		}
	}

	rep(i, 0, n)
		cout << ans[i] << ' ';

	return 0;
}
*/


/*
struct 
{
	int type; // 0 in, 1 and, 2 or, 3 xor, 4 not
	int value;

	int in[2];

	void input() {
		string str;
		cin >> str;
		if (str == "IN") {
			type = 0;
			cin >> value;
		}
		else if (str == "AND") {
			type = 1;
			cin >> in[0] >> in[1];
		}
		else if (str == "OR") {
			type = 2;
			cin >> in[0] >> in[1];
		}
		else if (str == "XOR") {
			type = 3;
			cin >> in[0] >> in[1];
		}
		else if (str == "NOT") {
			type = 4;
			cin >> in[0];
		}
	}
} node[1000005];

int n;

int cal(int a, int b, int type) {
	if (type == 1) return a & b;
	if (type == 2) return a | b;
	if (type == 3) return a ^ b;
}

int dfs(int x) {
	if (node[x].type == 0) return node[x].value;
	if (node[x].type == 4) return node[x].value = !dfs(node[x].in[0]);
	return node[x].value = cal(dfs(node[x].in[0]), dfs(node[x].in[1]), node[x].type);
}

bool f[1000005];

// if cf == 1 (f[rt] == 1)
// node[rt] change will change the value of node[1]
void dfs2(int rt, int cf) {
	int type = node[rt].type;
	int l = node[rt].in[0], r = node[rt].in[1];

	switch (type) {
	case 0:
		f[rt] = cf;
		break;
	case 1: case 2 : case 3:
		if (!cf) {
			dfs2(l, 0);
			dfs2(r, 0);
			break;
		}

		if (cal(node[l].value ^ 1, node[r].value, type) != node[rt].value)
			dfs2(l, 1);
		else
			dfs2(l, 0);
		if (cal(node[l].value, node[r].value ^ 1, type) != node[rt].value)
			dfs2(r, 1);
		else
			dfs2(r, 0);

		break;
	case 4:
		dfs2(l, cf);
		break;
	}
	return;
}

int main()
{
	FASTIO;
	cin >> n;
	vector<int> in;

	rep(i, 1, n + 1) {
		node[i].input();
		if (node[i].type == 0)
			in.push_back(i);
	}

	dfs(1);
	dfs2(1, 1);

	//rep(i, 1, n + 1)
	//	cout << i << " " << f[i] << endl;

	rep(i, 0, in.size()) {
		if (f[in[i]])
			cout << !node[1].value;
		else
			cout << node[1].value;
	}

	return 0;
}
*/

/*
int gcd(int a, int b) {
	if (a < b) swap(a, b);

	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main()
{
	int n, k;
	cin >> n >> k;
	ll g = 0;
	set<int> ans;

	rep(i, 0, n) {
		int t;
		cin >> t;
		g = gcd(g, t);
	}

	rep(i, 0, k) {
		ans.insert((i*g)%k);
	}

	cout << ans.size() << endl;
	for (auto i : ans)
		cout << i << ' ';

	return 0;
}
*/

/*
int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	vector<bool> p(n + 1, true);

	rep(i, 0, n) {
		printf("1\n");
		fflush(stdout);

		int ans = 0;
		scanf("%d", &ans);
		if (ans == 0) return 0;

		if (ans == 1) p[i + 1] = true;
		else p[i + 1] = false;
	}


	int ele = 1;
	int l = 1, r = m;
	while (1) {
		int mid = (l + r + 1) / 2;

		printf("%d\n", mid);
		fflush(stdout);

		int ans = 0;
		scanf("%d", &ans);
		if (ans == 0) break;
		if (ans == -2) break;

		if (p[ele]) {
			if (ans == 1)
				l = mid;
			else
				r = mid;
		}
		else {
			if (ans == 1)
				r = mid;
			else
				l = mid;
		}
		ele++;
		if (ele > n) ele = 1;
	}
	
	return 0;
}
*/

/*
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), b(n + 1);
	bool flag = true;
	rep(i, 1, n + 1) cin >> a[i], flag = flag && a[i] > 1;
	rep(i, 1, n + 1) cin >> b[i], flag = flag && b[i] > 1;

	if (!flag) {
		cout << "-1" << endl;
		return 0;
	}

	double mass = m;
	double fuel = 0;

	// land on earth

	fuel = mass / (b[1] - 1);
	mass += fuel;

	// fly from mars
	fuel = mass / (a[n] - 1);
	mass += fuel;

	pre(i, n, 2) {
		// land on pland i

		fuel = mass / (b[i] - 1.0);
		mass += fuel;

		// fly from plant i-1
		fuel = mass / (a[i-1] - 1);
		mass += fuel;
	}

	cout << mass - (double)m << endl;

	return 0;
}
*/

/*
int main()
{
	int n, m;
	cin >> n >> m;

	map<int, int> food;
	rep(i, 0, m) {
		int a;
		cin >> a;
		food[a]++;
	}

	if (m < n) {
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;
	rep(i, 1, INF) {
		auto tmp = food;
		//cout << "day " << i;
		rep(j, 0, n) {
			bool flag = false;
			for (auto& fd : tmp) {
				if (fd.second >= i) {
					fd.second -= i;
					flag = true;
					//cout << "  people " << j + 1 << "eat " << fd.first;
					break;
				}
			}
			if (!flag) {
				ans = i - 1 ;
				break;
			}
		}
		//cout << endl;
		if (ans != 0) {
			cout << ans << endl;
			break;
		}
	}

	return 0;
}
*/

/*
int main()
{
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;

	sort(all(str));

	ll ans = str[0] - 'a' + 1;
	char last = str[0];
	int cnt = 1;

	rep(i, 1, n) {
		if (cnt >= k) break;
		if (str[i] - last >= 2) {
			cnt++;
			ans += str[i] - 'a' + 1;
			last = str[i];
		}
	}

	if (cnt != k) ans = -1;

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	int n, k, m;
	cin >> n >> k >> m;

	vector<string> v(n + 1);
	map<string, int> word2id;
	vector<int> cost(n + 1);

	rep(i, 1, n + 1) cin >> v[i], word2id[v[i]] = i;
	rep(i, 1, n + 1) cin >> cost[i];

	map<int, int> group;
	map<int, int> groupcost;

	rep(i, 1, k + 1) {
		int t;
		cin >> t;
		rep(j, 0, t) {
			int x;
			cin >> x;
			group[x] = i;
			if (groupcost.count(i) == 0)
				groupcost[i] = cost[x];
			else
				groupcost[i] = min(groupcost[i], cost[x]);
		}
	}

	ll ans = 0;
	string word;
	rep(i, 0, m) {
		cin >> word;
		ans += groupcost[group[word2id[word]]];
	}

	cout << ans << endl;

	return 0;
}
*/

/*
ll cnt = 0;
vector<int> v;
vector<int> a(100005);
vector<int> b(100005);

void merge(int lo, int mid, int hi) {
	copy(v.begin() + lo, v.begin() + mid + 1, a.begin());
	copy(v.begin() + mid + 1, v.begin() + hi + 1, b.begin());
	int l1 = mid - lo + 1;
	int l2 = hi - mid;
	a[l1] = b[l2] = INF;
	int i, j, k;
	i = j = k = 0;
	for (k = lo; k <= hi; k++) {
		if (a[i] <= b[j]) {
			v[k] = a[i];
			i++;
		}
		else {
			v[k] = b[j];
			j++;
			cnt += l1 - i;
		}
	}
}


void merge_sort(int lo, int hi) {
	if (lo < hi) {
		int mid = (lo + hi) / 2;
		merge_sort(lo, mid);
		merge_sort(mid + 1, hi);
		merge(lo, mid, hi);
	}
}

int main()
{
	FASTIO;
	int n, x, y;

	while (cin >> n >> x >> y) {
		v.assign(n, 0);
		rep(i, 0, n) cin >> v[i];

		cnt = 0;
		merge_sort(0, n - 1);

		cout << cnt * min(x,y) << endl;

	}

	return 0;
}
*/


/*
int gcd(int a, int b)
{
	if (b != 0) return gcd(b, a % b);
	return a;
}

int main()
{
	int n, m;
	cin >> n >> m;

	if (n - 1 > m)
		cout << "Impossible" << endl;
	else {
		vector<pii> v;

		rep(i, 0, n) for (int j = i + 1; j < n; ++j) {
			if (int(v.size()) == m) break;

			if (gcd(i + 1, j + 1) == 1)
				v.push_back(pii(i + 1, j + 1));
		}
		if (int(v.size()) < m)
			cout << "Impossible" << endl;
		else {
			cout << "Possible" << endl;
			for (auto &p : v)
				cout << p.first << ' ' << p.second << endl;
		}
	}

	return 0;
}
*/

/*
int main()
{
	ll n, m;
	cin >> n >> m;

	ll ans = 0;
	rep(i, 0, m) {
		ll x, d;
		cin >> x >> d;

		ans += x * n;

		if (d > 0)
			ans += d * (n*(n - 1)) / 2;
		else {
			if (n % 2 == 0) {
				// 1 2 3 4 5 6 7 8 9 10
				// 4 3 2 1 0 1 2 3 4 5
				// 1 + 2 + ... + mid - 1 == mid*(mid-1)/2
				// 1 + 2 + ... + mid     == mid*(mid+1)/2
				// sum == mid^2
				ll mid = n / 2;
				ans += d*mid*mid;
			}
			else {
				// 1 2 3 4 5
				// 2 1 0 1 2
				// 1 + 2 + .. + n == n*(n+1)/2
				ll mid = n / 2;
				ans += d * mid*(mid + 1);
			}
		}
	}

	printf("%.15lf\n", 1.0*ans / n);

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	string str;
	cin >> str;

	rep(i, 0, n - 1) {
		if (str[i] != '?' && str[i] == str[i + 1]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	rep(i, 0, n) {
		if (str[i] == '?') {
			if ((i == 0 || i == n - 1) ||
				str[i + 1] == '?' ||
				str[i - 1] == str[i + 1]) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}

	cout << "NO" << endl;

	return 0;
}
*/

/*
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> p(n), less(n), greater(n);

	rep(i, 0, n)
		cin >> p[i];

	ll ans = 0;
	map<int, int> c;
	c[0] = 1;

	bool has = false;
	int sum = 0;
	rep(i, 0, n) {
		if (p[i] > m) sum++;
		if (p[i] < m) sum--;
		if (p[i] == m) has = true;

		if (has)
			ans += c[sum] + c[sum - 1];
		else
			++c[sum];
	}

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	string in;
	cin >> in;


	vector<int> last(3, -1);
	last[0] = 0;

	int r = 0;

	vector<int> ans(in.size() + 1);
	rep(i, 0, in.size()) {
		r = (r + in[i] - '0') % 3;

		ans[i + 1] = ans[i];
		if (last[r] != -1)
			ans[i + 1] = max(ans[i + 1], ans[last[r] + 1] + 1);

		last[r] = i;
	}

	cout << ans[in.size()] << endl;

	return 0;
}
*/

/*
int n, m, half;
vector<vector<ll>> a;
ll k, ans;

map<ll, int> mp[25][25];

void first(int x, int y, ll value, int cnt) {
	value ^= a[x][y];
	if (cnt == half) {
		++mp[x][y][value];
		return;
	}
	if (x + 1 < n)
		first(x + 1, y, value, cnt + 1);
	if (y + 1 < m)
		first(x, y + 1, value, cnt + 1);
}

void second(int x, int y, ll value, int cnt) {
	if (cnt == n + m - 2 - half) {
		if (mp[x][y].count(k ^ value))
			ans += mp[x][y][k^value];
		return;
	}
	if (x > 0)
		second(x - 1, y, value ^ a[x][y], cnt + 1);
	if (y > 0)
		second(x, y - 1, value ^ a[x][y], cnt + 1);
}

int main()
{
	cin >> n >> m >> k;
	a.assign(n, vector<ll>(m));

	rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

	half = (n + m - 2) / 2ll;

	first(0, 0, 0, 0);
	second(n - 1, m - 1, 0, 0);

	cout << ans << endl;

	return 0;
}
*/


/*
vector<int> v[200005];

int index2id[200005], enter[200005], leave[200005];
int cur = 0;
void dfs(int x) {
	index2id[cur] = x;
	enter[x] = cur++;
	for (auto i : v[x])
		dfs(i);
	leave[x] = cur;
}

int main()
{
	FASTIO;

	int n, q;
	cin >> n >> q;

	rep(i, 2, n + 1) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}

	dfs(1);

	rep(i, 0, q) {
		int u, k;
		cin >> u >> k;
		int target = enter[u] + k - 1;
		if (target >= leave[u]) cout << "-1" << endl;
		else cout << index2id[target] << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int ans = 0;

	for (int i = 0, j = n - 1; i < j; i++, j--) {
		//cout << a[i] << " , " << a[j] << endl;
		if (a[i] == b[i] && a[j] == b[j]) continue;
		else if (a[i] == b[i] && a[j] != b[j]) ans++;
		else if (a[i] != b[i] && a[j] == b[j]) ans++;
		else {
			set<char> s{ a[i],b[i],a[j],b[j] };
			if (s.size() == 4) ans += 2;
			else if (s.size() == 3) {
				ans++;
				if (a[i] == a[j]) ans++;
			}
		}
	}
	// 0 1 2
	// 0 1 2 3
	if (n % 2 != 0 && a[n / 2] != b[n / 2])
		ans++;

	cout << ans;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<ll> v(n), s1(n), s2(n);
	rep(i, 0, n) cin >> v[i];

	s1[0] = v[0];
	rep(i, 1, n) {
		s1[i] = s1[i - 1] + v[i];
	}

	s2[0] = v[n - 1];
	rep(i, 1, n) {
		s2[i] = s2[i - 1] + v[n - 1 - i];
	}

	pre(i, n - 2, 0) {
		bool flag = binary_search(all(s2), s1[i]);
		if (flag) {
			int pos = lower_bound(all(s2), s1[i]) - s2.begin();
			if (i + 1 < n - pos) {
				cout << s1[i];
				return 0;
			}
		}
	}

	cout << 0;

	return 0;
}
*/

/*
int main()
{
	int n, k;
	cin >> n >> k;
	vector<pii> v(n);
	rep(i, 0, n) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}

	sort(all(v), [](pii&a, pii& b) {
		if (a.first == b.first)
			return a.second < b.second;
		return a.first > b.first;
	});

	vector<pii> out;

	int ans = 0;
	rep(i, 0, k) {
		ans += v[i].first;
		out.emplace_back(pii(v[i].second, v[i].first));
	}

	sort(all(out));

	int last = 1;

	cout << ans << endl;

	if (out.size() >= 2) {
		rep(i, 1, out.size()) {
			cout << out[i].first - last << ' ';
			last = out[i].first;
		}

		cout << n + 1 - out.back().first << ' ';
	}
	else {
		cout << n;
	}

	return 0;
}
*/


/*
int main()
{
	int n;
	cin >> n;
	rep(i, 0, n) {
		ll in;
		cin >> in;
		if (in % 2 == 0)
			cout << in - 1 << ' ';
		else
			cout << in << ' ';
	}


	return 0;
}
*/

/*
int main()
{
	string in, out;
	cin >> in;

	int one = count(all(in), '1');
	rep(i, 0, in.size()) {
		if (in[i] != '1')
			out.push_back(in[i]);
	}

	auto pos = out.find_first_of('2');

	if (pos == string::npos) {
		out = out + string(one, '1');
	}
	else {
		rep(i, 0, one)
			out.insert(pos, "1");
	}

	cout << out;

	return 0;
}
*/


/*
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> c(n), v(m);
	rep(i, 0, n) cin >> c[i];
	rep(i, 0, m) cin >> v[i];

	int j = 0;
	int ans = 0;
	rep(i, 0, n) {
		if (c[i] <= v[j]) {
			j++;
			ans++;
		}
		if (j == m) break;
	}
	cout << ans;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, int> c, t;
	rep(i, 0, n) cin >> v[i], ++c[v[i]];

	int ans = 0;

	auto last = c.begin(), now = last;
	now++;
	while (now != c.end()) {
		int used = min(t[last->first] == 0 ? last->second : t[last->first], now->second);
		used = min(used, t[now->first] == 0 ? now->second : t[now->first]);
		ans += used;
		t[now->first] = last->second - used;

		if (t[now->first] == 0) {
			last = now;
			now++;
		}
		else
			now++;
	}

	cout << ans;

	return 0;
}
*/

/*
int main()
{
	FASTIO;

	int n;
	cin >> n;
	vector<pii> v(n);
	rep(i, 0, n) cin >> v[i].first >> v[i].second;

	int lastmi;
	bool flag = true;
	pre(i, n - 1, 1) {
		int mi = min(v[i].first, v[i].second);
		if (i == n - 1)
			lastmi = mi;
		int a, b;
		a = min(v[i-1].first, v[i-1].second);
		b = max(v[i-1].first, v[i-1].second);
		if (a >= lastmi)
			lastmi = a;
		else if (b >= lastmi)
			lastmi = b;
		else {
			flag = false;
			break;
		}
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
	string str;
	cin >> str;

	set<char> s;
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');

	bool flag = true;
	rep(i, 1, str.size()) {
		if (s.find(str[i-1]) == s.end() && s.find(str[i]) == s.end() && str[i-1] != 'n') {
			flag = false;
			break;
		}
	}

	if (s.find(str.back()) == s.end() && str.back() != 'n')
		flag = false;

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
	string s;
	cin >> s;
	int n = s.length();

	int r = 0;
	vector<int> fin(3, -1);
	fin[0] = 0;

	vector<int> z(n + 1);
	for (int i = 1; i <= n; i++) {
		r = (r + s[i - 1] - '0');
		z[i] = z[i - 1];
		//cout << i << " : " << r << endl;
		if (fin[r % 3] != -1)
			z[i] = max(z[i], z[fin[r % 3]] + 1);
		fin[r % 3] = i;
	}
	//rep(i, 0, n + 1)
	//	cout << " " << i << " : " << z[i] << endl;
	cout << z[n] << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, int> mp;
	rep(i, 0, n)
		cin >> v[i], mp[v[i]]--;
	sort(all(v));


	rep(i, 0, n) {
		rep(j, 0, 32) {
			if (binary_search(all(v), (1<<j) - v[i])) {
				//int a = v[i];
				//int b = 1 << j;
				if (!(2 * v[i] == (1 << j) && mp[v[i]] == -1))
				{
					mp[v[i]] = 0;
					//cout << "find " << v[i] << ' ' << (1 << j) - v[i] << endl;
					break;
				}
			}
		}
	}

	int ans = 0;
	for (const auto& i : mp) {
		if (i.second < 0)
			ans += -i.second;
	}
	cout << ans;

	return 0;
}
*/

/*
int main()
{
	string a, b;
	cin >> a >> b;

	int ia, ib;
	ia = a.size() - 1, ib = b.size() - 1;
	while (ia >= 0 && ib >= 0 && a[ia] == b[ib]) {
		ia--, ib--;
	}

	cout << ia + ib + 2;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> v(n), ans;
	rep(i, 0, n) {
		cin >> v[i];
	}

	rep(i, 1, n) {
		if (i == 1 && n > 2 && v[1] <= v[0])
			ans.push_back(v[0]);
		else {
			if (v[i] <= v[i - 1])
				ans.push_back(v[i - 1]);
		}
	}
	ans.push_back(v[n - 1]);

	cout << ans.size() << endl;
	rep(i, 0, ans.size())
		cout << ans[i] << ' ';

	return 0;
}
*/

/*
int main()
{
	int n, d;
	cin >> n >> d;
	vector<int> v(n);

	rep(i, 0, n) {
		cin >> v[i];
	}

	int ans = 0;
	map<int, int> mp;
	rep(i, 0, n) {
		int a, b;
		a = v[i] - d;
		b = v[i] + d;

		int disa = INF, disb = INF;
		rep(j, 0, n) {
			disa = min(disa, abs(a - v[j]));
			disb = min(disb, abs(b - v[j]));
		}
		//cout << i << " : " << a << " " << b << " " << disa << " " << disb << endl;
		if (disa >= d && !mp[a])
			ans++;
		if (disb >= d && !mp[b])
			ans++;
		mp[a] = 1;
		mp[b] = 1;
	}

	cout << ans;

	return 0;
}
*/

/*
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	string str;
	cin >> str;

	int cnt = 0;
	bool f = false;
	rep(i, 0, n) {
		if (str[i] == '0') {
			if (!f) {
				cnt++;
				f = true;
			}
		}
		else
			f = false;
	}
	if (cnt == 0)
		cout << cnt;
	else
		cout << (cnt-1ll) * min(x, y) + y;

	return 0;
}
*/

/*
int main()
{
	int n, B;
	cin >> n >> B;
	vector<int> v(n), a(n), b(n);
	rep(i, 0, n) cin >> v[i];

	int aa, bb;
	aa = bb = 0;
	rep(i, 0, n) {
		if (v[i] & 1) ++aa;
		else ++bb;
		a[i] = aa;
		b[i] = bb;
	}

	vector<int> cost;
	rep(i, 1, n-1) {
		if (a[i] == b[i])
			cost.push_back(abs(v[i + 1] - v[i]));
	}
	sort(all(cost));

	int sum = 0, ans = 0;

	rep(i, 0, cost.size()) {
		sum += cost[i];
		if (sum <= B)
			ans++;
		else
			break;
	}
	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	int n, q;
	cin >> n >> q;

	map<ll, int> mp;
	rep(i, 0, n) {
		ll a;
		cin >> a;
		++mp[a];
	}


	rep(i, 0, q) {
		ll qi;
		int ans = 0;
		cin >> qi;

		for (auto now = mp.rbegin(); now != mp.rend(); now++) {
			int cnt = min(qi / now->first, now->second + 0ll);
			ans += cnt;
			qi -= now->first * cnt;
		}
		if (qi > 0)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	rep(i, 0, n) cin >> v[i];
	double ans = 0, sum , t;

	rep(i, 0, n - k + 1) {
		//cout << "i = " << i << endl;
		sum = 0;
		rep(j, i, n) {
			//cout << "j = " << j << endl;
			sum += v[j];
			if (j - i + 1 >= k) {
				t = sum / (j - i + 1);
				//cout << i << ' ' << j << ' ' << t << endl;
				ans = max(ans, t);
			}
		}
	}

	printf("%.8lf", ans);

	return 0;
}
*/

/*
int main()
{
	int a, b, x;
	cin >> a >> b >> x;
	string ans;

	if (a < b)
		ans = "1";
	else
		ans = "0";

	int ca, cb, cx = 0;

	while (cx < x) {
		if (cx <= x - 2) {
			if (ans.back() == '0')
				ans += "10";
			else
				ans += "01";
			cx += 2;
		}
		else
		{
			ca = count(all(ans), '0');
			cb = ans.size() - ca;

			if (ans.back() == '0') {
				if (b - cb > 0)
					ans += "1";
				else
					ans = "0" + ans;
			}
			else {
				if (a - ca > 0)
					ans += "0";
				else
					ans += "1" + ans;
			}
			cx += 1;
		}
	}


	ca = count(all(ans), '0');
	cb = ans.size() - ca;

	if (ans.front() == '0') {
		if (x - cx > 0)
			ans = string(a - ca, '0') + ans;
		else
		{
			auto pos = find(all(ans), '0');
			rep(i, 0, a - ca) {
				pos = find(all(ans), '0');
				ans.insert(pos, '0');
			}
		}
		if (ans.back() == '0') {
			auto pos = find(all(ans), '1');
			rep(i, 0, b - cb) {
				pos = find(all(ans), '1');
				ans.insert(pos, '1');
			}
		}
		else
			ans = ans + string(b - cb, '1');
	}
	else {
		if (x - cx > 0)
			ans = ans + string(a - ca, '0');
		else
		{
			auto pos = find(all(ans), '0');
			rep(i, 0, a - ca) {
				pos = find(all(ans), '0');
				ans.insert(pos, '0');
			}
		}
		if (ans.front() == '0') {
			auto pos = find(all(ans), '1');
			rep(i, 0, b - cb) {
				pos = find(all(ans), '1');
				ans.insert(pos, '1');
			}
		}
		else
			ans = string(b - cb, '1') + ans;
	}

	cout << ans;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;

	map<int, int> mp;
	rep(i, 0, n) {
		int a;
		cin >> a;
		mp[a]++;
	}

	int ans = 0;
	for (auto i : mp)
		ans = max(ans, i.second);

	cout << ans;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, 0, n) cin >> v[i];

	if (n != 1) {
		int a = v[0];
		rep(i, 1, n) {
			int b = accumulate(v.begin() + i, v.end(), 0);
			if (a != b) {
				cout << i << endl;
				rep(j, 0, i)
					cout << j + 1 << ' ';
				return 0;
			}
			a += v[i];
		}
	}

	cout << -1;
	return 0;

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

	int ans = 0;
	rep(i, 0, n) {
		string str;
		cin >> str;
		vector<string>::iterator pos;
		if (v.end() != (pos = find(all(v), str)))
			v.erase(pos);
		else
			ans++;

	}
	cout << ans;

	return 0;
}
*/

/*
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	rep(i, 0, m) {
		int t;
		cin >> t;
		v[--t]++;
	}
	cout << *min_element(all(v));

	return 0;
}
*/

/*
int main()
{
	int n, a, b, c, t;
	cin >> n >> a >> b >> c >> t;
	vector<int> v(n);
	rep(i, 0, n) cin >> v[i];

	if (b >= c)
		cout << n * a;
	else
	{
		int ans = 0;
		rep(i, 0, n) {
			ans += (t - v[i])*(c - b) + a;
		}
		cout << ans;
	}

	return 0;
}
*/

/*
int main()
{
	FASTIO;
	int n;
	cin >> n;
	vector<pii> a(n);

	rep(i, 0, n) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	rep(i, 0, n) {
		int t = 0;
		while (i + t * n < a[i].first) t++;

		a[i].first = i + t * n;
	}
	sort(all(a));

	cout << a[0].second;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> a(2 * n);
	rep(i, 0, 2 * n) {
		cin >> a[i];
	}

	int ans = 0;
	rep(i, 0, 2 * (n - 1)) {
		int pos = find(a.begin() + i +1, a.end() , a[i]) - a.begin();
		while (abs(pos - i) != 1) {
			swap(a[pos], a[pos - 1]);
			pos--;
			ans++;
		}

		i++;
	}
	cout << ans;
	return 0;
}
*/

/*
int main()
{
	int n, ans;
	cin >> n;

	int a, b, c, d, e;
	a = n / 100;
	n -= a * 100;

	b = n / 20;
	n -= b * 20;

	c = n / 10;
	n -= c * 10;

	d = n / 5;
	n -= d * 5;

	e = n;

	cout << a + b + c + d + e;

	return 0;
}
*/

/*
int main()
{
	unsigned char v[] = { 0,1,2,3,4,16 };

	rep(i, 0, 6)
		printf("%2X ", v[i]);

	return 0;
}
*/

/*
int main()
{
	int a, b, c, n;
	cin >> a >> b >> c >> n;

	bool flag = true;
	int oa, ob, oc, od;
	oa = a - c, ob = b - c, oc = c, od = n - oa - ob - oc;

	if (oa < 0 || ob < 0 || oc < 0 || od <= 0)
		flag = false;

	if (!flag) {
		cout << -1;
		return 0;
	}


	cout << od;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	int sum = 0;
	rep(i, 0, n) {
		cin >> v[i];
		sum += v[i];
	}

	int mi = (int)ceil(4.5* n);

	if (sum >= mi)
		cout << 0;
	else {
		sort(all(v));
		int ans = 0;
		rep(i, 0, n) {
			sum += 5 - v[i];
			ans++;
			if (sum >= mi) {
				cout << ans;
				return 0;
			}
		}
	}


	return 0;
}
*/

/*
vector<int> g[5005];
int used[5005];
int con[5005];
int link[5005];

void dfs(int x) {
	con[x] = used[x] = 1;
	for(auto i : g[x])
		if (!used[i]) {
			link[i] = 0;
			dfs(i);
		}
}

int main()
{
	int n, m, s;
	cin >> n >> m >> s;

	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}

	dfs(s);

	memset(used, 0, sizeof used);

	rep(i, 1, n + 1) {
		if (!con[i]) {
			link[i] = 1;
			dfs(i);

			memset(used, 0, sizeof used);
		}
	}
	int ans = 0;
	rep(i, 1, n + 1)
		if (link[i])
			ans++;

	cout << ans;

	return 0;
}
*/

/*
int main()
{
	int n, m;
	cin >> n >> m;
	int k = n / m;

	vector<int> a(n);
	vector<vector<int>> val(m);

	rep(i, 0, n) {
		cin >> a[i];
		val[a[i] % m].push_back(i);
	}

	ll ans = 0;
	vector<pii> fre;
	rep(i, 0, 2 * m) {
		int cur = i % m;
		while (val[cur].size() > k) {
			fre.push_back(make_pair(val[cur].back(), i));
			val[cur].pop_back();
		}
		// 贪心，从最近的fre中，获取一个number
		while (val[cur].size() < k && !fre.empty()) {
			int elem = fre.back().first;
			int mmod = fre.back().second;
			fre.pop_back();
			val[cur].push_back(elem);
			a[elem] += i - mmod;
			ans += i - mmod;
		}
	}
	cout << ans << endl;
	rep(i, 0, n)
		cout << a[i] << ' ';

	return 0;
}
*/

/*
struct node {
	int id, value, remainder;
};

bool operator<(const node& a, const node& b) {
	return a.remainder < b.remainder;
}
vector<int> a, c;
vector<node> v;
int pos;

void make(int idx)
{
	if (c[idx] >)

}

int main()
{
	int n, m;
	cin >> n, m;

	a.resize(n);
	c.resize(m);

	pos = n / m;
	int cnt = 0;

	rep(i, 0, n) {
		cin >> a[i];
		c[a[i] % m]++;
		node t;
		t.id = i;
		t.value = a[i];
		t.remainder = a[i] % m;
		v.emplace_back(t);
	}

	sort(all(v));
	make(i);


	rep(i, 0, m) {
		if (c[i] > pos) {
			cnt += c[i] - pos;
		}
	}



	return 0;
}
*/


/*
int main()
{
	int n, k;
	cin >> n >> k;
	string in;
	cin >> in;

	map<char, int> mp;
	for (const auto i : in)
		mp[i]++;

	int cnt = 0, cur, last = 0;
	char c;
	for (c = 'a'; c <= 'z'; c++) {
		cnt += mp[c];
		if (cnt >= k) {
			cur = k - last;
			if (cur == 0) {
				c++;
			}

			break;
		}
		last = cnt;
	}

	string out;
	rep(i, 0, n) {
		if (in[i] >= c) {
			if (in[i] == c) {
				if (cur > 0)
					cur--;
				else
					out.push_back(in[i]);
			}
			else
				out.push_back(in[i]);
		}
	}
	cout << out;

	return 0;
}
*/

/*
int main()
{
	int n;
	string str;
	cin >> n >> str;

	rep(i, 0, n) {
		int d = i + 1;
		if (n % d == 0) {
			rep(j, 0, d / 2) {
				swap(str[j], str[i - j]);
			}
		}
	}

	cout << str;

	return 0;
}
*/

/*
int main()
{
	int n, k;
	cin >> n >> k;
	list<int> l;

	rep(i, 0, n) {
		int t;
		cin >> t;
		l.push_back(t);
	}

	int ans = 0;
	bool flag = true;
	while (flag && !l.empty()) {
		flag = false;
		if (!l.empty() && l.front() <= k) {
			l.pop_front();
			ans++;
			flag = true;
		}
		if (!l.empty() && l.back() <= k) {
			l.pop_back();
			ans++;
			flag = true;
		}
	}
	cout << ans;

	return 0;
}
*/

/*
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ll l, r, x, y;
	cin >> l >> r >> x >> y;

	ll g = x;

	ll s = y / x;

	if (y % x != 0) {
		cout << "0";
		return 0;
	}

	ll ans = 0;

	for (ll i = 1; i*i <= s; ++i) {
		ll val = i;

		if (s % val == 0) {
			ll p = val;
			ll q = s / val;

			if (p * g >= l && q * g >= l && q * g <= r && p * g <= r && (gcd(p, q) == 1)) {
				if (p == q) ans++;
				else ans += 2;
			}
		}
	}
	cout << ans;
	return 0;
}
*/

/*
int main()
{
	ll n, k;
	cin >> n >> k;


	ll t = 2 * n - 1;
	ll yu = 1000000007ll;

	if (k == 0) {
		cout << (2 * n) % yu;
		return 0;
	}

	while (k) {
		if (k > 32) {
			t = t * pow(2, 31);
			k -= 32;
			t %= yu;
		}
		else
		{
			t = t * pow(2, k);
			k = 0;
			t %= yu;
		}
	}
	//cout << p << ' ' << t << endl;
	cout << t + 1;

	return 0;
}
*/


/*
int main()
{
	int n;
	cin >> n;
	set<int> s;
	rep(i, 0, n) {
		int t;
		cin >> t;
		if (t != 0)
			s.insert(t);
	}
	cout << s.size() << endl;

	return 0;
}
*/

/*
vector<pii> v1, v2;

int cmp(pii& a, pii& b)
{
	if (a == b)
		return -1;
	if (a.first == b.first || a.first == b.second)
		return a.first;
	if (a.second == b.first || a.second == b.second)
		return a.second;
	return -1;
}

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	rep(i, 0, n) {
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		v1.emplace_back(a, b);
	}
	rep(i, 0, m) {
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		v2.emplace_back(a, b);
	}

	set<int> s1, s2;

	rep(i, 0, n) {
		rep(j, 0, m) {
			int x = cmp(v1[i], v2[j]);
			if (x == -1)
				continue;
			s1.insert(x);
			rep(k, 0, m) if (k != j) {
				int xx = cmp(v1[i], v2[k]);
				if (xx != -1 && xx != x) {
					cout << "-1";
					return 0;
				}
			}
		}
	}
	rep(i, 0, m) {
		rep(j, 0, n) {
			int x = cmp(v2[i], v1[j]);
			if (x == -1)
				continue;
			s2.insert(x);
			rep(k, 0, n) if (k != j) {
				int xx = cmp(v2[i], v1[k]);
				if (xx != -1 && xx != x) {
					cout << "-1";
					return 0;
				}
			}
		}
	}

	if (s1.size() == 1)
		cout << *s1.begin();
	else
		cout << 0;

	return 0;
}
*/
