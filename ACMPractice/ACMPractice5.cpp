
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
#include <climits>
#include <functional>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <numeric>
#include <bitset>
#include <tuple>
using namespace std;

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define rep(i,a,b) for(int i=a; i < b; ++i)
#define repn(i, n) for(int i=1; i <=n; ++i)
#define pre(i,a,b) for(int i=a; i >=b; --i)
#define pren(i, a) for(int i=a; i > 0; --i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll  INF_LL = (ll)1e18;

using namespace std;

int main()
{
	int a, b, c, ans;
	cin >> a >> b >> c;

	int idx[7] = { 0,1,2,0,2,1,0 };
	int na = a / 3, nb = b / 2, nc = c / 2;
	int full = min(na, min(nb, nc));
	na = a - full * 3, nb = b - full * 2, nc = c - full * 2;

	ans = 0;
	for (int start = 0; start < 7; ++start) {
		int day = start;
		vector<int> b = { na,nb,nc };
		int cur = 0;
		while (b[idx[day]] > 0) {
			--b[idx[day]];
			day = (day + 1) % 7;
			++cur;
		}
		ans = max(ans, full * 7 + cur);
	}

	cout << ans << endl;

	return 0;
}


/*
void fk() {
	cout << -1;
	exit(0);
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	set<int> s;
	rep(i, 0, n) {
		cin >> v[i];
		s.insert(v[i]);
	}
	if (s.size() > 3) 
		fk();
	int mi = *s.begin(), ma = *s.rbegin();
	if (s.size() == 3) {
		if (2**(++s.begin()) != (ma + mi))
			fk();
		cout << ma - (ma + mi) / 2;
	}
	else if (s.size() == 2) {
		if ((ma - mi) % 2 == 0)
			cout << ma - (ma + mi) / 2;
		else
			cout << ma - mi;
	}
	else {
		cout << 0;
	}

	return 0;
}
*/

/*
int main()
{
	int v[4];
	rep(i, 0, 4) cin >> v[i];
	sort(v, v + 4);
	cout << v[3] - v[0] << ' ' << v[3] - v[1] << ' ' << v[3] - v[2] << endl;

	return 0;
}
*/

/*
void fk() {
	cout << ":(";
	exit(0);
}

int main()
{
	int n;
	string in;
	cin >> n >> in;
	if (n % 2) {
		fk();
	}
	int n1, n2;
	n1 = n2 = 0;
	for (char c : in) {
		if (c == '(') n1++;
		else if (c == ')') n2++;
	}
	if (n1 > n / 2 || n2 > n / 2) {
		fk();
	}
	n1 = n / 2 - n1;
	for (char &c : in) {
		if (c == '?') {
			if (n1) {
				--n1;
				c = '(';
			}
			else {
				c = ')';
			}
		}
	}
	
	int b = 0;
	for (int i = 0; i + 1 < n; ++i) {
		if (in[i] == '(')
			++b;
		else
			--b;
		if (b <= 0)
			fk();
	}
	cout << in;
	return 0;
}
*/

/*
int main()
{
	int n, m, h;
	cin >> n >> m >> h;

	vector<int> front(m), left(n);
	rep(i, 0, m) {
		cin >> front[i];
	}
	rep(i, 0, n) {
		cin >> left[i];
	}
	vector<vector<int>> high(n, vector<int>(m));
	rep(i, 0, n) rep(j, 0, m) 
		cin >> high[i][j];
	
	rep(i, 0, n) rep(j, 0, m) {
		if (high[i][j] > 0) {
			high[i][j] = min(front[j], left[i]);
		}
	}

	rep(i, 0, n) {
		rep(j, 0, m) {
			cout << high[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n, t;
	cin >> n >> t;

	vector<pii> v(n);
	rep(i, 0, n) cin >> v[i].first >> v[i].second;

	int id = -1;
	int ans = INF;
	rep(i, 0, n) {
		if (t <= v[i].first) {
			if (ans > v[i].first) {
				ans = v[i].first;
				id = i + 1;
				//cout << "\t" << ans << endl;
			}
		}
		else {
			int rem = abs(v[i].first - t) / v[i].second;
			if ((v[i].first - t) % v[i].second != 0) 
				rem += 1;
			int q = min(ans, v[i].first + rem * v[i].second);
			if (ans > q) {
				ans = q;
				id = i + 1;
				//cout << "\t" << ans << endl;
			}
		}
	}
	cout << id << endl;

	return 0;
}
*/

/*
int main()
{
	FASTIO;
	int n;
	string s, t;
	cin >> n >> s >> t;

	vector<int> a(n+1), b(n+1);
	rep(i, 0, n) {
		a[i + 1] += s[i] - 'a';
		b[i + 1] += t[i] - 'a';
	}
	pre(i, n, 0) {
		a[i] += b[i];
		if (i) {
			a[i - 1] += a[i] / 26;
			a[i] %= 26;
		}
	}

	rep(i, 0, n + 1) {
		int rem = a[i] % 2;
		a[i] /= 2;
		if (i + 1 <= n) {
			a[i + 1] += rem * 26;
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << char('a' + a[i]);
	}
	cout << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;

	vector<int> a(n), sum(n);
	rep(i, 0, n) {
		cin >> a[i] >> sum[i];
		sum[i] += a[i];
	}

	sort(all(sum));
	bool ans = false;

	rep(i, 0, n) {
		if (binary_search(sum.begin(), sum.end(), a[i])) {
			ans = true;
			break;
		}
	}

	cout << (ans ? "YE5" : "N0") << endl;
	
	return 0;
}
*/

/*
int main()
{
	int n, t;
	cin >> n;
	vector<int> a(n), cnt(200*1005);

	rep(i, 0, n) {
		cin >> a[i];
		++cnt[a[i]];
	}

	int val = max_element(all(cnt)) - cnt.begin();
	int pos = find(all(a), val) - a.begin();

	cout << n - cnt[val] << endl;

	for (int i = pos - 1; i >= 0; --i) {
		cout << 1 + (a[i] > a[i + 1]) << " " << i + 1 << " " << i + 2 << " " << endl;
		a[i] = a[i + 1];
	}

	for (int i = 0; i < n - 1; ++i) {
		if (a[i + 1] != val) {
			cout << 1 + (a[i + 1] > a[i]) << " " << i + 2 << " " << i + 1 << " " << endl;
			a[i + 1] = a[i];
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

	vector<int> v(2 * 100005);
	rep(i, 0, n) {
		int t;
		cin >> t;
		v[t]++;
		if (v[t] > 2) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
	cout << count(v.begin(), v.end(), 2) << endl;
	for(int i = 0; i < 2 * 100005; ++i) {
		if (v[i] == 2) {
			--v[i];
			cout << i << " ";
		}
	}
	cout << endl << count(v.begin(), v.end(), 1) << endl;
	for(int i = 2 * 100005; i >= 0 ; --i) {
		if (v[i] == 1) {
			--v[i];
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;

	vector<int> odd,even;
	int sum = 0;
	rep(i, 0, n) {
		int t;
		cin >> t;
		sum += t;
		if (t % 2 == 0) even.push_back(t);
		else odd.push_back(t);
	}

	sort(odd.rbegin(), odd.rend());
	sort(even.rbegin(), even.rend());

	int st = min(even.size(), odd.size());
	rep(i, 0, st) 
		sum -= even[i] + odd[i];
	
	if ( even.size() > st)
		sum -= even[st];
	else
		sum -= odd[st];

	cout << sum << endl;

	return 0;
}
*/

/*
int v[105];

int main()
{
	int n;
	cin >> n;
	while(n--) {
		string in;
		cin >> in;
		
		memset(v, 0, sizeof(v));

		int l = 1000, r = -1;
		rep(i, 0, in.size()) {
			int cur = in[i] - 'a';
			v[cur]++;
			l = min(l, cur);
			r = max(r, cur);
		}

		bool ans = true;
		for(int i=0; i < 100; i ++) if (v[i] >= 2) {
			ans = false;
			break;
		}

		if ( ans ) {
			for(int i=l; i <= r; i++) if (v[i] == 0) {
				ans = false;
				break;
			}
		}

		cout << (ans ? "Yes" : "No") << endl;
	}

	return 0;
}
*/

/*
// 0 1 2 3 4
vector<int> v;
int get(int l, int r)
{
	if (is_sorted(v.begin() + l, v.begin() + r))
		return r - l;
	int ans = 1;
	ans = max(ans, get(l, (l+r)>>1));
	ans = max(ans, get((l+r)>>1, r));
	return ans;
}

int main()
{
	int n;
	cin >> n;
	
	v.resize(n);
	rep(i, 0, n) cin >> v[i];
	
	cout << get(0, n) << endl;

	return 0;
}
*/

/*
int main() 
{
	int n;
	cin >> n;

	vector<int> v(n), p(n);
	rep(i, 0, n) cin >> v[i];

	p[0] = v[0];
	rep(i, 1, n)
		p[i] = max(v[i], p[i-1]);
	
	int res = 0;
	rep(i, 0, n) if (i + 1 == p[i])
		res++;
	
	cout << res << endl;

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


	bool yes = false;
	rep(i, 0, (1 << n)-1) {
		int sum = 0;
		int t = i;
		rep(j, 0, n) {
			if (t&1) sum += v[j];
			else sum -= v[j];
			t >>= 1;
		}
		if (abs(sum) % 360 == 0) {
			yes = true;
			break;
		}
	}

	puts(yes ? "YES" : "NO");

	return 0;
}
*/

/*
int main() 
{
	char rink, suit;
	cin >> rink >> suit;

	bool yes = false;
	rep(i, 0, 5) {
		char nr, ns;
		cin >> nr >> ns;
		if (nr == rink || ns == suit) {
			yes = true;
			break;
		}
	}
	puts(yes ? "YES" : "NO");

	return 0;
}
*/

/*
int main()
{
	int q;
	cin >> q;
	while(q--){
		ll n,a,b;
		cin >> n >> a >> b;
		if (2*a <= b)
			cout << n * a;
		else {
			if (n % 2 == 0)
				cout << n / 2 * b;
			else
				cout << n / 2 * b + a;
		}
		cout << endl;
	}
	return 0;
}


/*
void rem(string &s, const string &c) {
	auto pos = s.find(c);
	if (pos == string::npos) {
		cout << -1 << endl;
		exit(0);
	}
	s.erase(0, pos + 1);
}

int main()
{
	string in;
	cin >> in;

	int ans = -1;

	rem(in, "[");
	rem(in, ":");
	reverse(all(in));
	rem(in, "]");
	rem(in, ":");

	cout << count(all(in), '|') + 4 << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	rep(i, 0, n) {
		int l, r, d;
		cin >> l >> r >> d;
		int ans = d;
		if (d > r)
			ans = d;
		else if (d >= l)
			ans = (r/d+1)*d;
		else
			ans = d;
		cout << ans << endl;
	}
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


	bool yes = false;
	rep(i, 0, (1 << n)-1) {
		int sum = 0;
		int t = i;
		rep(j, 0, n) {
			if (t&1) sum += v[j];
			else sum -= v[j];
			t >>= 1;
		}
		if (abs(sum) % 360 == 0) {
			yes = true;
			break;
		}
	}

	puts(yes ? "YES" : "NO");

	return 0;
}
*/

/*
int main() 
{
	char rink, suit;
	cin >> rink >> suit;

	bool yes = false;
	rep(i, 0, 5) {
		char nr, ns;
		cin >> nr >> ns;
		if (nr == rink || ns == suit) {
			yes = true;
			break;
		}
	}
	puts(yes ? "YES" : "NO");

	return 0;
}
*/

/*
int main()
{
	int *grtfish, *lastfish;
	grtfish = (int*)malloc(1);
	lastfish = grtfish;
	rep(i, 2, 10) {
		grtfish = (int*)realloc(grtfish, i);
		if (lastfish != grtfish || 1) {
			printf("size: %6d, lastfish: %10u, grtfish: %10u\n", i, lastfish, grtfish);

			lastfish = grtfish;
		}
		else {
			if (i % 100 == 0) {
				printf("Yeah!\n");
			}
		}
	}

	return 0;
}
*/

/*
int main() 
{
	vector<int> intfish;
	int lastcap = -1;
	void* lastbegin = nullptr;
	rep(i, 0, 10000) {
		intfish.push_back(i);
		if (lastbegin != &(*intfish.begin())) {
			printf("%7d %7d %10u %10u\n", intfish.size(), intfish.capacity(), lastbegin, &(*intfish.begin()));

			lastbegin = &(*intfish.begin());
		}
	}

	return 0;
}
*/

/*
int main() 
{
	vector<int> morefish;

	int lasti   = -1;
	int lastcap =  0;
	rep(i, 0, 10000) {
		morefish.push_back(i);
		//printf("len: %d, cap: %d\n", morefish.size(), morefish.capacity());
		if (lastcap != morefish.capacity()) {
			int diffi = i - lasti;
			int diffcap = morefish.capacity() - lastcap;
			printf("    %3d %3d %2.2f\n", diffi, diffcap, 1.0*diffcap / lastcap);

			lasti = i, lastcap = morefish.capacity();
		}
	}

	return 0;
}
*/

/*
int main()
{
	int T,l,r;
	cin >> T;
	rep(i, 0, T) {
		cin >> l >> r;
		cout << l << " " << 2 * l << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n, k;
	cin >> n >> k;
	map<int, int> ans;
	queue<int> q;
	rep(i, 0, 31) {
		if (n & (1 << i)) {
			if (i > 0) q.push(1 << i);
			ans[1 << i]++;
		}
	}
	if (ans.size() > k) {
		cout << "NO";
		return 0;
	}

	int cnt = ans.size();
	while (cnt < k && !q.empty()) {
		int z = q.front();
		q.pop();
		ans[z]--;
		ans[z / 2] += 2;
		if (z / 2 > 1) {
			q.push(z / 2);
			q.push(z / 2);
		}
		cnt++;
	}
	if (cnt < k) {
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	for (auto s : ans)
		for (int i = 0; i < s.second; i++)
			cout << s.first << " ";
	cout << endl;
	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	ll tx, ty;
	tx = ty = 0;
	rep(i, 0, 2 * n) {
		int a, b;
		cin >> a >> b;
		tx += a, ty += b;
	}
	tx /= n, ty /= n;
	cout << tx << " " << ty;
	return 0;
}
*/

/*
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int t = min(min(a, b - 1), c - 2);
	cout << 3 * t + 3;
	return 0;
}
*/

/*
int gcd(int a, int b) { return b?gcd(b,a%b):a;}

#define MN 300000
#define MX 15000000

int vis[MX+5], a[MX+5], flag[MX+5];

int main()
{
	int n, gc = 0;
	scanf("%d", &n);
	repn(i, n) {
		scanf("%d", &a[i]);
		vis[a[i]]++;
		if(!gc)
			gc = a[i];
		else
			gc = gcd(gc, a[i]);
	}

	int ans = 0;
	for(int i = gc + 1; i <= MX; i++) {
		if (!flag[i]) {
			int cnt = 0;
			for(int j = i; j <= MX; j += i) {
				cnt += vis[j];
				flag[j] = 1;
			}
			ans = max(ans, cnt);
		}
	}

	printf("%d", ans ? n-ans : -1);

	return 0;
}
*/

/*
int main()
{
	int in;
	cin >> in;

	if ((in-2) % 3 != 0)
		cout << "1 1 " << in-2 ;
	else
		cout << "1 2 " << in-3;

	return 0;
}
*/

/*
int main()
{
	map<int, pair<string, int>> mp;

	int n;
	cin >> n;
	rep(i, 0, n) {
		string num;
		int a, b;
		cin >> num >> a >> b;
		mp[a] = make_pair(num, b);
	}
	cin >> n;
	rep(i, 0, n) {
		int t;
		cin >> t;
		cout << mp[t].first << " " << mp[t].second << endl;
	}

	return 0;
}

/*
int main()
{
	unsigned int x = ~0;
	unsigned int y = (unsigned int)-1;

	printf("%x\n%x\n", x, y);

	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		rep(i, 0, n) {
			rep(i, 0, m) 
				cout << "/\\";
			cout << endl;
			rep(i, 0, m) 
				cout << "\\/";
			cout << endl;
		}
	}

	return 0;
}
*/

/*
int main()
{
	double in;

	while (cin >> in) {
		cout << setprecision(7) << fixed;
		if (in <= 2.0)
			cout << 7;
		else if (in <= 15)
			cout << 7 + ceil(in - 2) * 1.5;
		else {
			cout << 7 + (15 - 2)*1.5 + ceil(in - 15)*2.1;
		}
		cout << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double h, w, wbiao;
		cin >> h >> w;
		// w ���нﻻΪ ����
		w = w * 0.5;
		wbiao = (h - 100)*0.9;
		if (abs(w - wbiao) < wbiao*0.1)
			cout << "You are wan mei!";
		else if (w < wbiao)
			cout << "You are tai shou le!";
		else
			cout << "You are tai pang le!";
		if (i != n - 1)
			cout << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int in, out, t;
	out = 0;
	cin >> in;
	t = in;
	while (t != 0) {
		out = out * 10 + t % 10;
		t /= 10;
	}
	if (in == out)
		cout << "yes";
	else
		cout << "no";

	return 0;
}
*/

/*
int main()
{
	string in, rev;
	cin >> in;
	rev = string(in.rbegin(), in.rend());
	if (in == rev)
		cout << "yes";
	else
		cout << "no";

	return 0;
}
*/

/*
int main()
{
	char n2s[][15] = {
		"ling","yi","er","san","si",
		"wu","liu","qi","ba","jiu"
	};

	string in;
	while (cin >> in) {
		for (int i = 0; i < (int)in.size(); i++) {
			if (in[i] == '-')
				cout << "fu";
			else
				cout << n2s[in[i] - '0'];
			if (i != (int)in.size() - 1)
				cout << " ";
		}
	}

	return 0;
}
*/
/*
int main()
{
	int T;
	cin >> T;
	while (T--) {
		ll s, a, b, c;
		cin >> s >> a >> b >> c;
		ll bar = 0;
		bar = s / (a*c);
		s %= a * c;
		bar = bar * (a + b);
		bar += s / c;
		cout << bar << endl;
	}

	return 0;
}
*/


/*
ll S = 0;
int tmp[3];
int sumCheck(vector<ll>& A, int start, int end, int arr[], int cnt) {
	if (cnt == 2) {
		int sum = arr[0] + arr[1] + arr[2];
		if (sum == S)
			return 1;
	}
	if (start > end || cnt > 2)
		return 0;

	int i = start;
	arr[++cnt] = A[i];
	if (sumCheck(A, start + 1, end, arr, cnt)) return 1;
	arr[cnt] = 0;
	cnt--;
	if (sumCheck(A, start + 1, end, arr, cnt)) return 1;
}

int main()
{
	string str;
	vector<ll> v;
	
	while (cin >> str) {
		//cout << "\t" << str << endl;
		if (str.find(',') != string::npos) {
			size_t pos = str.find(',');
			string n1 = str.substr(0, pos);
			string n2 = str.substr(pos + 1);

			ll sum = atoll(n2.c_str());
			v.push_back(atoll(n1.c_str()));
			S = sum;
			//cout << n1 << endl << n2 << endl;
			//cout << sum << endl;
			sort(all(v));

			if (v.size() < 3) {
				cout << "False";
				return 0;
			}

			memset(tmp, 0, sizeof(tmp));
			if (sumCheck(v, 0, v.size()-1, tmp, -1)) {
				cout << "True" << endl;
				return 0;
			}
		}
		else {
			v.push_back(atoll(str.c_str()));
		}
	}

	cout << "False";

	return 0;
}
*/


/*
int main()
{
	int t;
	cin >> t;
	while (t--) {
		ll x, t;
		cin >> x;
		t = 0;
		while (x != 0) {
			if (x % 2 == 1)
				t++;
			x /= 2;
		}
		cout << (1 << t) << endl;
	}

	return 0;
}
*/

/*
int main()
{
	vector<int> v(3);
	rep(i, 0, 3) cin >> v[i];
	sort(all(v));

	int ans = 0;
	while (v[0] + v[1] <= v[2]) {
		v[0]++;
		ans++;
		sort(all(v));
	}
	cout << ans << endl;
	return 0;
}
*/

/*
class MyClass
{
public:
	MyClass(int i = 0)
	{
		cout << i;
	}
	MyClass(const MyClass &x)
	{
		cout << 2;
	}
	MyClass &operator=(const MyClass &x)
	{
		cout << 3;
		return *this;
	}
	~MyClass()
	{
		cout << 4;
	}
};
int main()
{
	MyClass obj1(1), obj2(2);
	MyClass obj3(obj1);
	obj3 = obj1;
	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> v(n), st(n);
	rep(i, 0, n) {
		cin >> v[i];
		st[i] = v[i];
	}
	sort(all(st));
	int start = 0, end = n - 1;
	while (start < n && v[start] == st[start])start++;
	while (end >= 0 && v[end] == st[end]) end--;
	bool ok = true;
	while (start < end) {
		if (st[start] != v[end]) {
			ok = false;
			break;
		}
		start++, end--;
	}
	if (ok)
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	while (cin >> n) {
		int i = 0;
		while (i*(i + 3) / 2 < n) {
			i++;
		}
		cout << n - 2*(i-1) << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n, r;
	cin >> n >> r;
	vector<int> v(n);
	rep(i, 0, n) cin >> v[i];

	int last = -1;
	int ans = 0;
	while (last < n - 1) {
		int nt = -1;
		for (int i = n - 1; i > max(-1, last - r + 1); --i) {
			if (v[i] == 1 && i - r <= last) {
				nt = i;
				break;
			}
		}
		if (nt == -1) {
			cout << -1 << endl;
			return 0;
		}
		last = nt + r - 1;
		ans++;
	}
	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int L, v, l, r;
		cin >> L >> v >> l >> r;
		cout << L / v - (r/v - (l-1)/v) << endl;
	}
	return 0;
}
*/

/*
int f(int a, int b) {
	return a*10 + b;
}

int main()
{
	auto t = bind(f, 1, std::placeholders::_1);
	// auto t = bind(f, std::placeholers::_1, 1);
	rep(i, 0, 10)
		cout << t(i) << endl;

	return 0;
}
*/

/*
int main()
{
	// 11 = 2 + 9
	// 88 + 0*9
	int n;
	string str;
	cin >> n >> str;

	int n8 = count(all(str), '8');
	int res = n / 11;
	int ans = min(n8, res);

	if (n < 11)
		ans = 0;

	cout << ans << endl;
	return 0;
}
*/

/*
const int N = 3e5 + 10;
int v[N], g[N];

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int n;
	cin >> n;

	int ans = 0, tot = 0;
	set<int> s;
	rep(i, 0, n) {
		int t;
		scanf("%d", v + i);
		s.insert(v[i]);
	}
	if (s.size() == 1) {
		printf("-1\n");
		return 0;
	}
	sort(v, v + tot);

	g[n-1] = v[n-1];
	pre(i, n-2, 0) {
		g[i] = gcd(g[i + 1], v[i]);
	}

	rep(i, 1, n-1) {
		ans++;
		if (g[i] > g[0]) {
			printf("%d\n", ans);
			return 0;
		}
	}
	printf("-1\n");

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<ll> v;
	rep(i, 0, n) {
		ll a, b;
		cin >> a >> b;
		v.push_back(a + b);
	}
	sort(all(v));
	ll t = v.back();

	cout << t << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	for (int i = 1;; i++) {

		for (int j = 1;; j++) {
			if ((n - i - j) % 3 != 0) {
				printf("%d %d %d\n", i, j, n - i - j);
				return 0;
			}

			if ((j + 1) % 3 == 0)
				j++;
		}
		if ((i + 1) % 3 == 0)
			i++;
	}

	return 0;
}
*/

/*
const int MOD = 998244353;
ll dp[1005][2010][4];

int main()
{
	int n, k;
	cin >> n >> k;
	dp[1][1][0] = dp[1][2][2] = dp[1][2][1] = dp[1][1][3] = 1;
	rep(i, 2, n + 1) rep(j, 1, 2 * n + 1) {
		dp[i][j][0] = dp[i - 1][j][0] 
			+ dp[i - 1][j][1] 
			+ dp[i - 1][j][2]
			+ dp[i - 1][j - 1][3];
		dp[i][j][1] = dp[i - 1][j - 1][0]
			+ dp[i - 1][j][1]
			+ (j >= 2 ? dp[i - 1][j - 2][2] : 0)
			+ dp[i - 1][j - 1][3];
		dp[i][j][2] = dp[i - 1][j - 1][0]
			+  (j >= 2 ? dp[i - 1][j - 2][1] : 0)
			+ dp[i - 1][j][2]
			+ dp[i - 1][j - 1][3];
		dp[i][j][3] = dp[i - 1][j - 1][0]
			+ dp[i - 1][j][1]
			+ dp[i - 1][j][2]
			+ dp[i - 1][j][3];
		rep(t, 0, 4)
			dp[i][j][t] %= MOD;
	}

	ll ans = 0;
	rep(i, 0, 4)
		ans += dp[n][k][i];

	ans %= MOD;

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	map<int, int> cnt;
	rep(i, 0, n) {
		cin >> v[i];
		cnt[v[i]]++;
	}

	int size1, size2;
	size1 = size2 = 0;
	rep(i, 0, n) {
		if (cnt[v[i]] == 1) size1++;
		else if (cnt[v[i]] > 2) size2++;
	}
	
	bool ok = false, bu = false;
	if (size1 % 2 == 0) ok = true;
	else if (size2 > 0) ok = true, bu = true;

	string ans;
	puts(ok ? "YES" : "NO");
	if (ok) {
		int single = 0;
		
		rep(i, 0, n) {
			if (cnt[v[i]] == 1) {
				ans.push_back(single & 1 ? 'A' : 'B');
				single++;
			}
			else if (cnt[v[i]] > 2 && bu) {
				bu = false;
				ans.push_back('A');
			}
			else
				ans.push_back('B');
		}
		cout << ans << endl;
	}

	return 0;
}
*/

/*
int main()
{
	string in;
	int T;
	cin >> T;
	while (T--) {
		cin >> in;
		vector<pii> v;
		bool ok = false;
		int up, low, dig;
		up = low = dig = 0;
		for (int j = 0; j < 3; j++) {
			if (islower(in[i + j])) low = 1;
			else if (isupper(in[i + j])) up = 1;
			else if (isdigit(in[i + j])) dig = 1;
		}
		if (up*low*dig != 0){
			cout << in;
			continue;
		}
		for (int i = 0; i + 2 < in.size(); i++) {
			up = low = dig = 0;
			for (int j = 0; j < 3; j++) {
				if (islower(in[i + j])) low = 1;
				else if (isupper(in[i + j])) up = 1;
				else if (isdigit(in[i + j])) dig = 1;
			}
			if (low + up + dig == 3) {
				cout << in << endl;
				ok = true;
				break;
			}
			v.push_back({ low + up + dig, i });
		}
		if (ok) continue;
		sort(all(v));
		auto t = v.back();
		up = low = dig = 0;
		for (int j = t.second; j < t.second + 3; j++) {
			if (islower(in[j])) low++;
			else if (isupper(in[j])) up++;
			else if (isdigit(in[j])) dig++;
		}
		if (t.first == 2) {
			if (up == 2) {
				for (int j = t.second; j < t.second + 3; j++) {
					if (isupper(in[j])) {
						if (low == 0) in[j] = 'a';
						else in[j] = '0';
						break;
					}
				}
			}
			else if (low == 2) {
				for (int j = t.second; j < t.second + 3; j++) {
					if (islower(in[j])) {
						if (up == 0) in[j] = 'A';
						else in[j] = '0';
						break;
					}
				}
			}
			else {
				for (int j = t.second; j < t.second + 3; j++) {
					if (isdigit(in[j])) {
						if (up == 0) in[j] = 'A';
						else in[j] = 'a';
						break;
					}
				}
			}
		}
		else {
			if (up == 3) {
				in[t.second] = 'a';
				in[t.second + 1] = '0';
			}
			else if (low == 3) {
				in[t.second] = 'A';
				in[t.second + 1] = '0';
			}
			else {
				in[t.second] = 'A';
				in[t.second + 1] = 'a';
			}
		}
		cout << in << endl;
	}

	return 0;
}
*/

/*
int main()
{
	ll l, r;
	cin >> l >> r;

	cout << "YES" << endl;
	for (ll i = l; i < r; i+= 2) {
		cout << i << " " << i + 1 << endl;
	}

	return 0;
}
*/


/*
int main()
{
	int n;
	cin >> n;
	
	vector<int> dp(8, INF);

	dp[0] = 0;

	rep(i, 0, n) {
		int cost;
		string s;
		cin >> cost >> s;

		int sta = 0;
		for (auto c : s)
			sta |= 1<<(c - 'A');

		dp[sta] = min(dp[sta], cost);
	}

	rep(i, 1, 8) rep(j, 1, 8)
		dp[i | j] = min(dp[i | j], dp[i] + dp[j]);

	if (dp[7] == INF)
		cout << -1;
	else
		cout << dp[7];

	return 0;
}
*/

/*
int up(int a, int b) {
	if (a % b != 0)
		return a / b + 1;
	return a / b;
}

int main()
{
	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	int total = 0;
	rep(i, 0, n)
		cin >> a[i], total += a[i];

	int mink = max(*max_element(all(a)), up(total + m, n));
	int maxk = *max_element(all(a)) + m;

	cout << mink << " " << maxk << endl;
	return 0;
}
*/

/*
const int N = 2e5 + 5;
int sum[N];
pii v[N];
int n, h;

int getH(int l, int r) {
	int lo = lower_bound(v, v + n, pii(l, -1)) - v;
	int up = lower_bound(v, v + n, pii(r, -1)) - v;

	int s = sum[up] - sum[lo];
	if (lo > 0)
		s += max(0, v[lo - 1].second - l);

	return r - l - s;
}

int main()
{
	scanf("%d%d", &n, &h);

	rep(i, 0, n)
		scanf("%d%d", &v[i].first, &v[i].second);

	sum[0] = 0;
	rep(i, 0, n)
		sum[i + 1] = sum[i] + (v[i].second - v[i].first);

	int ans = 0;
	rep(i, 0, n) {
		int end = v[i].second + 1;

		int l = -(h + 1), r = end;

		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (getH(mid, end) > h)
				l = mid;
			else
				r = mid;
		}

		ans = max(ans, end - r);
	}

	printf("%d\n", ans);

	return 0;
}
*/

/*
const int N = 2e5 + 5;

int a[N], ans[N];

int main()
{
	int n, m, d;
	scanf("%d%d%d", &n, &m, &d);

	set<int> s;
	map<int, int> id;
	rep(i, 0, n)
		scanf("%d", a + i), s.insert(a[i]), id[a[i]] = i + 1;
	
	int curday = 1, last = -1;
	while (!s.empty()) {
		auto now = s.begin();
		last = *now;
		ans[id[last]] = curday;
		s.erase(now);

		while (1)
		{
			now = s.lower_bound(last + d + 1);
			if (now == s.end())
				break;
			last = *now;
			ans[id[last]] = curday;
			s.erase(now);
		}

		curday++;
	}

	int res = *max_element(ans + 1, ans + n + 1);
	printf("%d\n", res);
	rep(i, 1, n + 1)
		printf("%d ", ans[i]);

	return 0;
}
*/

/*
ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ll a, b, x, y;
	cin >> a >> b >> x >> y;

	ll t = gcd(x, y);
	x /= t;
	y /= t;

	ll ans = 0;
	ans = (ll)min(double(a) / x, double(b) / y);

	cout << ans << endl;

	return 0;
}
*/


/*
int a[1005];

int main()
{
	int n;
	cin >> n;
	rep(i, 0, n)
		cin >> a[i];
	sort(a, a+n);
	int ans = 0;
	rep(i, 1, n) 
		ans += a[i] - a[i - 1] - 1;

	cout << ans << endl;

	return 0;
}
*/


/*
vector<ll> res;

void brute(int pos, int cnt, ll cur) {
	if (pos == 18) {
		res.push_back(cur);
		return;
	}

	brute(pos + 1, cnt, cur * 10);

	if (cnt < 3)
		rep(i, 1, 10)
			brute(pos + 1, cnt + 1, cur * 10 + i);
}


int main()
{
	brute(0, 0, 0);
	res.push_back((ll)1e18);

	int T;
	scanf("%d", &T);
	while (T--) {
		ll l, r;
		scanf("%I64d %I64d", &l, &r);
		printf("%d\n", int(upper_bound(all(res), r) - lower_bound(all(res), l)));
	}

	return 0;
}
*/

/*
const int N = 3e5 + 5;
int a[N], b[N];

int main()
{
	int n, m;
	scanf("%d", &n);
	ll sum = 0;
	rep(i, 0, n)
		scanf("%d", a+i), sum += a[i];
	scanf("%d", &m);
	rep(i, 0, m)
		scanf("%d", b+i), sum -= b[i];

	if (sum != 0) {
		puts("-1");
		return 0;
	}

	int posa = 0, posb = 0;
	int res = 0;
	while (posa < n) {
		res++;
		ll suma = a[posa++], sumb = b[posb++];
		while (suma != sumb) {
			if (suma < sumb) suma += a[posa++];
			else sumb += b[posb++];
		}
	}

	printf("%d\n", res);

	return 0;
}
*/

/*
int main()
{
	int q;
	cin >> q;

	while (q--) {
		ll n, m, k;
		cin >> n >> m >> k;

		if (n < m) swap(n, m);
		if (k < n) {
			cout << -1 << endl;
			continue;
		}
		else {
			if ((n + m) % 2) {
				cout << k - 1 << endl;
			}
			else {
				if ((k - n) % 2)
					cout << k - 2 << endl;
				else
					cout << k << endl;
			}
		}

	}

	return 0;
}
*/

/*
int main()
{
	ll n, k;
	cin >> n >> k;
	cout << k / n + (k % n != 0 ? 1 : 0) << endl;

	return 0;
}
*/

/*
const int N = 5e5 + 10;
int l[N][2], r[N][2];

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, 0, n)
		cin >> v[i];

	if (n == 1) {
		cout << v[0] << endl;
		return 0;
	}

	bool pos,neg;
	pos = neg = false;

	int minval = INF;
	ll ans = 0;
	rep(i, 0, n) {
		minval = min(minval, abs(v[i]));

		pos |= (v[i] >= 0);
		neg |= (v[i] <= 0);
		ans += abs(v[i]);
	}

	if (pos && neg) {
		cout << ans << endl;
	}
	else {
		cout << ans - 2 * minval << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n, t;
	cin >> n;
	priority_queue<int> a, b;
	rep(i, 0, n) {
		cin >> t;
		a.push(t);
	}
	rep(i, 0, n) {
		cin >> t;
		b.push(t);
	}

	ll as, bs;
	as = bs = 0;

	int turn = 1;
	while (!a.empty() || !b.empty()) {
		if (!a.empty() && !b.empty()) {
			if (turn == 1) {
				if (a.top() >= b.top()) {
					as += a.top();
					a.pop();
				}
				else {
					b.pop();
				}
			}
			else {
				if (b.top() >= a.top()) {
					bs += b.top();
					b.pop();
				}
				else {
					a.pop();
				}
			}
		}
		else if (a.empty()) {
			if (turn == 0) {
				while (!b.empty()) {
					bs += b.top();
					b.pop();
					if (!b.empty())
						b.pop();
				}
			}
			else {
				while (!b.empty()) {
					b.pop();
					if (!b.empty()) {
						bs += b.top();
						b.pop();
					}
				}
			}
		}
		else if (b.empty()) {
			if (turn == 1) {
				while (!a.empty()) {
					as += a.top();
					a.pop();
					if (!a.empty())
						a.pop();
				}
			}
			else {
				while (!a.empty()) {
					a.pop();
					if (!a.empty()) {
						as += a.top();
						a.pop();
					}
				}
			}
		}
		turn = !turn;
	}

	cout << as - bs << endl;

	return 0;
}
*/

/*
int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int n;
	cin >> n;
	if (n <= 2) {
		cout << "No" << endl;
		return 0;
	}
	rep(i, 2, n) {
		int s1 = n * (n + 1) / 2 - i;
		int s2 = i;
		if (gcd(s1, s2) > 1) {
			cout << "Yes" << endl;
			cout << "1 " << i << endl;
			cout << n - 1 << " ";
			rep(j, 1, n + 1) {
				if (j != i) {
					cout << j << " ";
				}
			}
			return 0;
		}
	}

	cout << "No" << endl;

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

	map<char,int> s;

	rep(i, 0, n)
		s[str[i]]++;

	int ans = INF;
	for (auto i : s)
		ans = min(ans, i.second);

	if (s.size() < k)
		ans = 0;
	else
		ans *= k;

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	ll n, k;
	cin >> n >> k;
	ll l = 1, r = n;

	bool flag = false;

	while (!flag && l < r) {
		ll mid = (l + r + 1) >> 1;

		cout << l << " " << mid << endl;
		cout.flush();
		string ans;
		cin >> ans;

		if (ans[0] == 'Y')
			r = max(l, min(mid + k,n));
		else
			l = min(r, max(mid - k,1ll));
		if (ans[0] == 'B')
			return 0;

		if (ans[0] == 'Y' && l == r)
			return 0;
		else {
			if ((mid - l + 1) <= 2 * k + 1) {
				int size = (r - l + 1);
				ll lo = l, rr = r;
				if (ans[0] == 'Y')
					rr = mid;
				else
					lo = mid;
				if (ans[0] == 'B')
					return 0;
				rep(i, lo, rr+1) {
					cout << i << " " << i << endl;
					cout.flush();
					cin >> ans;
					if (ans[0] == 'Y') {
						return 0;
					}
				}
				l -= size * k;
				r += size * k;
				l = max(l, 1ll);
				r = min(n, r);
			}
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

	if (k == 0) {
		cout << n << endl;
		rep(i, 0, n)
			cout << i + 1 << endl;
	}
	else {
		int size = 2 * k + 1;
		int cnt = n / size;
		int back = 0;
		if (n % size > 0 && n % size < k + 1) {
			back = k + 1 - (n%size);
			back = -back;
		}
		vector<int> ans;
		rep(i, 1, cnt + 1) {
			int pos = back + (i - 1)*size + (size+1) / 2;
			ans.push_back(pos);
		}
		if (n % size != 0) {
			ans.push_back(back + cnt * size + (size+1) / 2);
		}
		cout << ans.size() << endl;
		rep(i, 0, ans.size())
			cout << ans[i] << " ";
	}

	return 0;
}
*/

/*
int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	vector<int> v(n);
	rep(i, 0, n)
		cin >> v[i];

	int i = 0, j = n - 1;
	int ans = 0;
	while (i < j) {
		if (v[i] == v[j]) {
			if (v[i] == 2)
				ans += 2 * min(a, b);

		}
		else if (v[i] == 2) {
			if (v[j] == 0) ans += a;
			else ans += b;
		}
		else if (v[j] == 2) {
			if (v[i] == 0) ans += a;
			else ans += b;
		}
		else {
			cout << -1 << endl;
			return 0;
		}

		i++, j--;
	}

	if (n % 2 == 1) {
		if (v[n / 2] == 2)
			ans += min(a, b);
	}

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> f(n + 1);
	rep(i, 1, n + 1)
		cin >> f[i];

	rep(i, 1, n + 1) {
		int l1 = f[i];
		int l2 = f[l1];
		int l3 = f[l2];
		if (l3 == i) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}
*/

/*
const int N = 2e5 + 5;
int n, m, k, ans[N];
pii edge[N];
set<int> s, mp[N];

void remove(int u) {
	if (mp[u].size() < k && s.erase(u)) {
		for (auto& i : mp[u]) {
			mp[i].erase(u);
			remove(i);
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	rep(i, 1, m + 1) {
		cin >> edge[i].first >> edge[i].second;
		mp[edge[i].first].insert(edge[i].second);
		mp[edge[i].second].insert(edge[i].first);
	}
	rep(i, 1, n + 1) s.insert(i);
	rep(i, 1, n + 1) remove(i);

	pre(i, m, 1) {
		ans[i] = s.size();
		int x, y;
		tie(x, y) = edge[i];
		mp[x].erase(y); mp[y].erase(x);
		remove(x); remove(y);
	}

	rep(i, 1, m + 1)
		cout << ans[i] << endl;

	return 0;
}
*/

/*

const int N = 2e5 + 5;
int n, m, k;
pii edges[N];
vector<pii> mp[N];
multiset<pii> se;
int deg[N], ok[N];


int main()
{
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, m + 1) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[i] = { a,b };
		deg[a]++; deg[b]++;
		mp[a].push_back({b, i});
		mp[b].push_back({a, i});
	}

	rep(i, 1, n + 1) {
		se.insert( {deg[i], i} );
		ok[i] = 1;
	}

	while (!se.empty() && se.begin()->first < k) {
		int u = se.begin()->second;
		se.erase(se.begin());
		ok[u] = 0;
		for (auto & i : mp[u]) {
			int v = i.first;
			if (ok[v]) {
				se.erase({ deg[v], v });
				deg[v]--;
				se.insert({ deg[v], v });
			}
		}
	}

	vector<int> ans(m + 1);
	for (int i = m; i > 0; i--) {
		ans[i] = se.size();
		int u = edges[i].first, v = edges[i].second;
		if (ok[u] && ok[v]) {
			se.erase({ deg[u],u }); se.erase({ deg[v],v });
			deg[u]--, deg[v]--;
			se.insert({ deg[u], u }); se.insert({ deg[v],v });
		}
		while (!se.empty() && se.begin()->first < k) {
			u = se.begin()->second;
			se.erase(se.begin());
			ok[u] = 0;
			for (auto &j : mp[u]) {
				int v = j.first;
				if (j.second >= i)
					continue;
				if (ok[v]) {
					se.erase({ deg[v],v });
					deg[v]--;
					se.insert({ deg[v],v });
				}
			}
		}
	}

	rep(i, 1, m + 1)
		printf("%d\n", ans[i]);

	return 0;
}
*/

/*
vector<int> mp[(int)2e5 + 5], ans;
int inorder[200007], relorder[200007];
int visit[200007];

int main()
{
	int n;
	cin >> n;

	rep(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}

	rep(i, 0, n) {
		cin >> inorder[i], inorder[i]--;
		relorder[inorder[i]] = i;
	}

	rep(i, 0, n) {
		sort(all(mp[i]), [](int a, int b) {
			return relorder[a] < relorder[b];
		});
	}
	queue<int> q;
	q.push(0);

	while (!q.empty()) {
		queue<int> tmp;
		while (!q.empty()) {
			int x = q.front(); q.pop();
			ans.push_back(x);
			visit[x] = 1;
			for (auto i : mp[x]) {
				if (!visit[i]) {
					tmp.push(i);
				}
			}
		}
		q = tmp;
	}

	rep(i, 0, n) {
		if (inorder[i] != ans[i]) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}
*/