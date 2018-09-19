
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

#include<stdio.h>
#include<stdlib.h>
typedef struct student {
	int score;
	struct student *next;
}linklist;
linklist *create(int n) {
	linklist *head, *node, *end;//定义头结点，普通节点，尾部节点；
	head = (linklist*)malloc(sizeof(linklist));
	end = head;
	for (int i = 0; i<n; i++) {
		node = (linklist*)malloc(sizeof(linklist));
		scanf("%d", &node->score);
		end->next = node;
		end = node;
	}
	end->next = NULL;
	return head;
}
void change(linklist *list, int n) {
	linklist *t = list;
	int i = 0;
	while (i < n && t != NULL) {
		t = t->next;
		i++;
	}
	if (t != NULL) {
		printf("输入要修改的值 : ");
		scanf("%d", &t->score);
	}
	else {
		printf("节点不存在\n");
	}
}
void printlist(linklist *phead) {
	
	if (NULL == phead) {
		printf("链表为空\n");
	}
	else
	{
		// 跳过头结点
		phead = phead->next;
		while (NULL != phead) {
			printf("%d ", phead->score);
			phead = phead->next;
		}
		printf("\n");
	}
}
int main() {
	int n, m;
	printf("请输入链表的长度 : ");
	scanf("%d", &n);
	printf("请输入%d个整数(空格分隔) : ", n);
	linklist *list = create(n);
	while (1) {
		printf("请输入要修改第几个元素(从1开始, 输入-1退出程序) : ");
		scanf("%d", &m);
		if (m == -1)
			return 0;
		change(list, m);
		printf("修改过后的链表为 : ");
		printlist(list);
	}
	
	return 0;
}


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