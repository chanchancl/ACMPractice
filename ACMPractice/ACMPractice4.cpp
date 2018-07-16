
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
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int ans = 0;

	rep(i, 0, (n + 1) / 2) {
		if (i == n / 2 && n % 2 != 0) {
			if (a[i] != b[i]) {
				a[i] = b[i];
				ans++;
			}
			continue;
		}
		if (a[i] == b[i] && a[n - 1 - i] == b[n - 1 - i]) continue;
		if (a[i] == a[n - 1 - i] && b[i] == b[n - 1 - i]) continue;
		if (a[i] == b[n - 1 - i] && b[i] == a[n - 1 - i]) continue;
		if (a[i] == b[n - 1 - i]) {
			ans++;
			continue;
		}
		if (b[i] == a[n - 1 - i]) {
			ans++;
			continue;
		}
		if (a[i] != b[i] && a[n - 1 - i] == b[n - 1 - i]) {
			ans++;
			continue;
		}
		if (a[i] == b[i] && a[n - 1 - i] != b[n - 1 - i]) {
			ans++;
			continue;
		}
		//cout <<" : " <<  i << endl;
		ans += 2;

	}
	cout << ans;

	return 0;
}


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
