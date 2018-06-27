
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
