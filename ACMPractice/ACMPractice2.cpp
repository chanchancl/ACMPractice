
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n, t, i;
	while (cin >> n)
	{
		vector<long long> v;
		v.resize(n);
		for (i = 0; i < n; ++i)
			cin >> v[i];
		sort(v.begin(), v.end());
		int last = v.size() - 1;
		if (v.size() == 2)
			cout << v[0] * v[1] << endl;
		else
			cout << v[last] * (v[last - 1] + v[last - 2]) << endl;
	}
	return 0;
}

/*
int main()
{
	string str;
	int i;
	while (cin >> str)
	{
		for (i = 0; i < str.size(); ++i)
		{
			if (((i+1) & 1) && isupper(str[i]))
				str[i] = tolower(str[i]);
			else if (((i+1) & 1) == 0 && islower(str[i]))
				str[i] = toupper(str[i]);
		}
		cout << str << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n, i, t, r,k;
	while (cin >> n >> t)
	{
		r = 0;
		for (i = 0; i < t; ++i)
		{
			cin >> k;
			if (k < n)
				r++;
		}
		cout << r << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int a[5] = { 1,2,3,4 };
	sort(a,a+5);
	do
	{
		for (int i = 0; i < 4; ++i)
			printf("%d ", a[i]);
		printf("\n");
	} while (next_permutation(a, a + 4));
	return 0;
}
*/

/*
int main()
{
	char c[24] = "ZTtc";
	unsigned int  a = (*c) << 24;
	unsigned int  b = (*(c + 1)) << 16;
	unsigned int  d = (*(c + 2)) << 8;
	unsigned int  e = (*(c + 3));
	unsigned int  f = (*c) << 24 | (*(c + 1)) << 16 | (*(c + 2)) << 8 | (*(c + 3));
	cout << f << endl;
}
*/

/*
int main()
{
	char ch[10][8] = {
		"zero","one","two","three","four",
		"five","six","seven","eight","nine"
	};
	map<string, int> m;
	for (int i = 0; i < 10; ++i)
		m[ch[i]] = i;
	string a, b;
	while (cin >> a >> b)
		cout << m[a] + m[b] << endl;
	return 0;
}
*/

/*
int k, m;
string str;
int dir[100005];
int num[100005];

void solve()
{
	int sum = 0, res = 0;
	memset(num, 0, sizeof(num));
	for (int i = 0; i < str.size(); ++i)
		dir[i] = str[i] - '0';
	for (int i = 0; i <= str.size() - k; ++i)
	{
		if ((dir[i] + sum) % 2)
		{
			res++;
			num[i] = 1;
		}
		sum += num[i];
		if (i - k + 1 >= 0)
			sum -= num[i - k + 1];
	}
	bool flag = true;
	for (int i = str.size()-k+1 ; i < str.size(); ++i)
	{
		if ((dir[i] + sum) % 2)
		{
			flag = false;
			break;
		}
		else
			sum -= num[i - k + 1];
	}
	if (flag && res <= m)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> k >> m >> str;
		solve();
	}
	return 0;
}
*/

/*
int a[10005];
int n, k;

void solve()
{
	sort(a, a + n);
	printf("%d %d\n", a[(k-1)/n], a[(k-1)%n]);
}

int main()
{
	while (cin >> n >> k)
	{
		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		solve();
	}
	return 0;
}
*/

/*
double v1, v2, x, k;
void solve()
{
	printf("%.2lf\n", k / (x*v1)*(3.1415926 / 2 - atan(-v2 / v1)));
}

int main()
{
	int T;
	
	cin >> T;
	while (T--)
	{
		scanf("%lf %lf %lf %lf", &v1, &v2, &x, &k);
		solve();
	}
}
*/

/*
struct DNA
{
	string str;
	int num;
};
bool operator<(DNA &d1, DNA &d2)
{
	return d1.num < d2.num;
}

vector<DNA> v;
void solve()
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].str.size(); ++j)
		{
			for (int k = j + 1; k < v[i].str.size(); ++k)
				if (v[i].str[j] > v[i].str[k])
					v[i].num++;
		}
	}
	sort(v.begin(), v.end());
	for (vector<DNA>::iterator it = v.begin(); it != v.end(); ++it)
		cout << it->str << endl;
}

int main()
{
	int T, n;
	while (cin >> n >> T)
	{
		v.resize(T);
		for (int i = 0; i < T; ++i)
			cin >> v[i].str;
		solve();
	}
	return 0;
}
*/


/*
int a[100005];
int sum[100005];
int n, S;

void solve()
{
	for (int i = 0; i < n; ++i)
		sum[i + 1] = sum[i] + a[i];
	if (sum[n] < S)
	{
		cout << 0 << endl;
		return;
	}
	int res = n;
	for (int s = 0; sum[s] + S <= sum[n]; s++)
	{
		int t = lower_bound(sum + s, sum + n, sum[s] + S) - sum;
		res = min(res, t - s);
	}
	cout << res << endl;
}

int main()
{
	int T,i;
	cin >> T;
	while (T--)
	{
		scanf("%d %d", &n, &S);
		for (i = 0; i < n; ++i)
			scanf("%d", &a[i]);
		solve();
	}
	return 0;
}


void solve1()
{
	int res = n + 1;
	int s = 0, t = 0, sum = 0;
	for (;;)
	{
		while (t < n && sum < S)
			sum += a[t++];
		if (sum < S) break;
		res = min(res, t - s);
		sum -= a[s++];
	}
	if (res > n)
		res = 0;
	cout << res << endl;
}
*/

/*
int main()
{
	int T, x, y, ret;
	cin >> T;
	while (T--)
	{
		cin >> x >> y;
		ret = -1;
		if (x == y)
		{
			if (x == 0)
				ret = 0;
			else if (x & 1)
				ret = 2 * x - 1;
			else
				ret = 2 * x;
		}
		else if (x == y + 2)
		{
			if (x & 1)
				ret = x + y - 1;
			else
				ret = x + y;
		}
		if (ret == -1)
			cout << "No Number" << endl;
		else
			cout << ret << endl;
	}
	return 0;
}
*/

/*
int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int i,n, a, b;
	while (cin >> n)
	{
		cin >> a;
		for (i = 1; i < n; ++i)
		{
			cin >> b;
			a = b / gcd(a, b)*a;
		}
		cout << a << endl;
	}
	return 0;
}
*/

/*
bool cmp(string& raw, string& str)
{
	if (raw.size() != str.size())
		return false;
	for (int i = 0; i < raw.size();++i)
	{
		if (raw[i] != str[i] && raw[i] != '*')
			return false;
	}
	return true;
}

int main()
{
	int T, n, i,cnt;
	cin >> T;
	while (T--)
	{
		cnt = 0;
		string raw, str;
		cin >> raw;
		cin >> n;
		for (i = 0; i < n; ++i)
		{
			str = "";
			while(str == "")
				getline(cin, str);
			
			if (cmp(raw, str))
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int T, v, k, s, e, n;
	cin >> T;
	while (T--)
	{
		cin >> v >> k >> s >> e;
		if (s == e && e % k == 0)
			n = 1;
		else
			n = e / k - (s - 1) / k;
		if (n > v)
			n = v;
		cout << n << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int T, n, t,i;
	cin >> T;
	while (T--)
	{
		list<int> anime;
		vector<int> food;
		cin >> n;
		for (i = 0; i < n; ++i)
		{
			cin >> t;
			anime.push_back(t);
		}
		food.resize(n);
		for (i = 0; i < n; ++i)
			cin >> food[i];
		sort(food.begin(), food.end());
		bool bao = true;
		for (auto it = anime.begin(); it != anime.end(); ++it)
		{
			auto it2 = lower_bound(food.begin(), food.end(), *it);
			if (it2 == food.end())
			{
				bao = false;
				break;
			}
			else
				food.erase(it2);
		}
		if (bao)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
*/


/*
struct tree
{
	tree *left, *right;
	char value;
	tree(char c) : value(c),left(NULL),right(NULL){}
};

string pre, mid;
int current = 0;
tree* make(char c, int l, int r)
{
	tree *ret = new tree(c);
	current++;
	if (l > r || current > pre.size())
		return ret;

	int m = mid.find(c);
	if (current < mid.size() && l != m)
		ret->left = make(pre[current], l, m - 1);
	if (current < mid.size() && r != m)
		ret->right = make(pre[current], m + 1, r);
	return ret;
}


void visit(tree *t)
{
	if (!t)
		return;
	visit(t->left);
	visit(t->right);
	cout << t->value;
}

void del(tree *t)
{
	if (!t)
		return;
	del(t->left);
	del(t->right);
	delete t;
}

int main()
{
	while (cin >> pre >> mid)
	{
		current = 0;
		tree *root = make(pre[current], 0, pre.size());
		visit(root);
		printf("\n");
		del(root);
	}
	return 0;
}
*/


/*
int num[25];

void lower(string &str)
{
	for (int i = 0; i < str.size(); ++i)
		if (isupper(str[i]))
			str[i] = tolower(str[i]);
}

int main()
{
	int k, e, i, j,T=0;
	while (cin >> k >> e)
	{
		T++;
		vector<string> keyword;
		vector<string> jiekouraw,jiekou;
		string tmp;
		keyword.resize(k);
		jiekou.resize(e);
		for (i = 0; i < k; ++i)
			cin >> keyword[i];
		getline(cin, tmp);
		for (i = 0; i < e; ++i)
			getline(cin, jiekou[i]);
		jiekouraw = jiekou;
		for (i = 0; i < e; ++i)
			lower(jiekou[i]);
		memset(num, 0, sizeof(num));
		for (i = 0; i < e; ++i)
		{
			for (j = 0; j < k; ++j)
			{
				int pos,end;
				if ((pos = jiekou[i].find(keyword[j])) != string::npos)
				{
					if (pos == 0 || !isalpha(jiekou[i][pos-1]))
					{
						end = pos + keyword[j].size();
						if (end == jiekou[i].size() || !isalpha(jiekou[i][end]))
							num[i]++;
					}
				}
			}
		}
		int max = -1;
		for (i = 0; i < e; ++i)
			if (num[i] > max)
				max = num[i];
		cout << "Excuse Set #" << T << endl;
		for (i = 0; i < e; ++i)
			if (num[i] == max)
				cout << jiekouraw[i] << endl;
		cout << endl;
	}
	return 0;
}
*/

/*
string text, mode;
int nextt[1000005];

void kmp_next(string &str)
{
	int i = 0, j = -1;
	nextt[0] = -1;
	while (i < str.length())
	{
		if (j == -1 || str[i] == str[j])
		{
			i++, j++;
			if (str[i] != str[j])
				nextt[i] = j;
			else
				nextt[i] = nextt[j];
		}
		else
			j = nextt[j];
	}
}

int main()
{
	int T,i,j,cnt;
	cin >> T;
	while (T--)
	{
		cin >> mode >> text;
		kmp_next(mode);
		i = j = cnt = 0;
		while(i < text.length())
		{
			if (j == -1 || text[i] == mode[j])
				i++, j++;
			else
				j = nextt[j];
			if (j == mode.length())
				cnt++, j = nextt[j];
		}
		cout << cnt << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int T, n, i,j,k;
	cin >> T;
	while (T--)
	{
		cin >> n;
		string DNA[10], ans,sub;
		for (i = 0; i < n; ++i)
			cin >> DNA[i];
		for (i = 0; i < 60; ++i)
		{
			for (j = 1; j <= 60 - i; ++j)
			{
				sub = DNA[0].substr(i, j);
				
				int allfind = true;
				for (k = 1; k < n; ++k)
				{
					if (DNA[k].find(sub) == string::npos)
					{
						allfind = false;
						break;
					}
				}
				if (allfind)
				{
					if (sub.size() > ans.size())
						ans = sub;
					else if (sub.size() == ans.size() && sub < ans)
						ans = sub;
				}
			}
		}
		if (ans.size() < 3)
			cout << "no significant commonalities" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
*/

/*
struct task
{
	int id, pri;
	task(int ID, int PRI) : id(ID), pri(PRI){}
};

int main()
{
	int T, n, m, i, t;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;

		list<task> l;
		for (i = 0; i < n; ++i)
		{
			cin >> t;
			l.push_back(task(i, t));
		}

		int time = 0;
		while (1)
		{
			task head = l.front();
			l.pop_front();
			bool canprint = true;
			for (auto it = l.begin(); it != l.end(); ++it)
			{
				if (head.pri < it->pri)
				{
					canprint = false;
					break;
				}
			}
			if (canprint)
				time++;
			else
				l.push_back(head);
			if (canprint && head.id == m)
			{
				cout << time << endl;
				break;
			}
		}
	}

	return 0;
}
*/

/*
int main()
{
	double x, y, r, x1, y1, x2, y2;
	double k, b,R;
	while (cin >> x >> y >> r >> x1 >> y1 >> x2 >> y2)
	{
		if (x1 == x2)
			R = fabs(x - x1);
		else if (y1 == y2)
			R = fabs(y - y1);
		else
		{
			k = (y1 - y2) / (x1 - x2);
			b = y1 - k*x1;
			R = fabs((k*x - y + b)) / sqrt(k*k + 1);
		}
		if (fabs(R - r) <= 1e-6)
			cout << 1 << endl;
		else if (R < r)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
*/

/*
struct mofa
{
	int a, b,c;
};

int value[100005];
mofa mofac[100005];
int changed, n, m;

int main()
{
	int T,i,j,a,b,c;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (i = 1; i <= n; ++i)
			scanf("%d", &value[i]);
		for (i = 0; i < m; ++i)
			scanf("%d %d %d", &mofac[i].a, &mofac[i].b, &mofac[i].c);

		changed = 1;
		while (changed)
		{
			changed = 0;
			for (int i = 0; i <= m; ++i)
			{
				if (value[mofac[i].c] > value[mofac[i].a] + value[mofac[i].b])
				{
					value[mofac[i].c] = value[mofac[i].a] + value[mofac[i].b];
					changed = 1;
				}
			}
			for (int i = m; i >= 0; --i)
			{
				if (value[mofac[i].c] > value[mofac[i].a] + value[mofac[i].b])
				{
					value[mofac[i].c] = value[mofac[i].a] + value[mofac[i].b];
					changed = 1;
				}
			}
		}
		for (i = 1; i <= n; ++i)
		{
			if (i != 1)
				cout.put(' ');
			printf("%d", value[i]);
		}
		printf("\n");
	}
	return 0;
}
*/

/*
struct stu
{
	char name[30];
	int id;
	int actotal; // ac 过的总题数
	int ac[10]; // 1通过， 0 没通过
	int wa[10]; // wa 次数
	int totaltime; // 总罚时
};

bool operator<(const stu& s1, const stu& s2)
{
	if (s1.actotal != s2.actotal)
		return s1.actotal > s2.actotal;
	else
	{
		if (s1.totaltime != s2.totaltime)
			return s1.totaltime < s2.totaltime;
		else
			return s1.id < s2.id;
	}
}

int main()
{
	stu s[10];
	sort(s, s + 10, std::less<stu>());
}
*/

/*
int t[10][10];
int main()
{
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			cin >> t[i][j];
	bool r = true;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (i > j)
				if (t[i][j] != 0)
					r = false;
	if (r)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
*/

/*
int main()
{
	int i, m, n;
	vector<int> v1, v2, v3;
	cin >> m;
	v1.resize(m);
	for (i = 0; i < m; ++i)
		cin >> v1[i];
	cin >> n;
	v2.resize(n);
	for (i = 0; i < n; ++i)
		cin >> v2[i];
	int end = n + m;
	m -= 1, n = 0;
	for (i=0;i<end;++i)
	{
		if (i != 0)
			cout.put(' ');
		if (m >= 0 &&n < v2.size() )
		{
			if (v1[m] > v2[n])
				cout << v1[m--];
			else
				cout << v2[n++];
		}
		else if (m >= 0)
			cout << v1[m--];
		else
			cout << v2[n++];
	}
	return 0;
}
*/

/*
int main()
{
	int t[100] = { 0 };
	int a, n = 0 , i, r, max;
	while (cin >> a && a >= 0)
		t[a]++,n++;
	max = -1;
	for(i=0;i<100;++i)
		if (max < t[i])
			max = t[i];
	bool first = true;
	for(i=0;i<100;++i)
		if (t[i] == max)
		{
			if (first)
				first = false;
			else
				cout.put(' ');
			cout << i;
		}
	return 0;
}
*/

/*
int main()
{
	int i,n,t;
	set<int> s;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		s.insert(t);
	}
	cout << s.size() << endl;
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		if (it != s.begin())
			cout.put(' ');
		cout << *it;
	}
	return 0;
}
*/

/*
int main()
{
	int now=0, next, n, total = 0;
	cin >> n;
	while (n--)
	{
		cin >> next;
		if (next > now)
			total += (next - now) * 6;
		else if (next < now)
			total += (now - next) * 4;
		total += 5;
		now = next;
	}
	cout << total << endl;

	return 0;
}
*/

/*
int main()
{
	vector<int> v;
	int n, t,i;
	cin >> n;
	v.resize(n);
	for (i = 0; i < n; ++i)
		cin >> v[i];

	swap(*v.begin(), *min_element(v.begin(), v.end()));
	swap(*--v.end(), *max_element(v.begin(), v.end()));

	for (auto it = v.begin(); it != v.end(); ++it)
	{
		if (it != v.begin())
			cout << ' ';
		cout << *it;
	}
	return 0;
}
*/

/*
int main()
{
	float x, y;
	for (y = 1; y >= -1; y -= 0.05f, putchar('\n'))
		for (x = -1; x <= 1; x += 0.025f)
			putchar(x*x + y*y > 1 ? 'M' : "@@%#*+=;:. "[int(((x + y + sqrt(1 - (x*x + y*y)))*0.5773502692f + 1)*5.0f + 0.5f)]);
}
*/

/*
int main()
{
	string op;
	int m1, m2, r1, r2, r3,first=1;
	while (cin >> m1 >> m2)
	{
		getline(cin, op);
		while(op == "")
			getline(cin, op);
		r1 = r2 = r3 = 0;
		for(int i=0; i < op.size(); ++i)
			switch (op[i])
			{
			case 'A':
				r1 = m1;
				break;
			case 'B':
				r2 = m2;
				break;
			case 'C':
				m1 = r3;
				break;
			case 'D':
				m2 = r3;
				break;
			case 'E':
				r3 = r1 + r2;
				break;
			case 'F':
				r3 = r1 - r2;
				break;
			}
		cout << m1 << ',' << m2 << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int t, n, x1, y1, x2, y2, ans;
	cin >> t;
	while (t--)
	{
		cin >> n >> x1 >> y1 >> x2 >> y2;
		int d = abs(x1 - x2) + abs(y1 - y2);
		ans = 0;
		if ((n + 1) / 2 < d)
			ans = n & 1;
		else
		{
			if (d & 1)
			{
				if (n & 1)
					ans = 2;
			}
			else
				ans = 1;
		}
		if (ans == 0)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
*/


/*
int d[32];
int pos = 0;
void f(int x)
{
	pos = 0;
	while (x)
	{
		d[pos++] = x % 2;
		x /= 2;
	}
}

int check()
{
	int i,ret = 0;
	for (i = 0; i < pos; ++i)
		if (d[i] == 1)
			ret++;
	return ret;
}

int main()
{
	int t, n, k;
	cin >> t;
	while (t--)
	{
		string str;
		int need = 0;
		cin >> str >> k;
		auto it = str.begin();
		for (; it != str.end();)
		{
			if (*it == ',')
				it = str.erase(it);
			else
				it++;
		}
		n = atoi(str.c_str());
		if (n <= k)
			cout << 0 << endl;
		else
		{
			f(n);
			int c = check();
			if (c <= k)
			{
				cout << 0 << endl;
				continue;
			}
			int j;
			for (j = pos - 1; j >= 0; --j)
			{
				if (d[j] == 1)
					k--;
				if (k == 0)
					break;
			}
			int n = pow(2, j+1);
			for (int i = 0; i <= j; ++i)
				n -= d[i] * pow(2, i);
			cout << n << endl;
		}
	}
	return 0;
}
*/

/*
int main()
{
	int n, a, b, c;
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c;
		cout << a*b + a / 30 * c << endl;
	}
	return 0;
}
*/

/*
int dp[25] = { 0,1,2,4 };
int main()
{
	int t, n, i, m, ret;
	for (i = 4; i <= 20; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	cin >> t;
	while (t--)
	{
		cin >> n;
		ret = 1;
		for (i = 0; i < n - 1; ++i)
		{
			cin >> m;
			ret = (ret * dp[m]) % 10007;
		}
		cout << ret << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n,t,first = 1;
	cin >> n;
	while (n--)
	{
		if (first)
			first = 0;
		else
			putchar('\n');
		cin >> t;
		t %= 10;
		for (int i = 0; i < t; ++i)
			cout << "I am a good ACMer" << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int t,a,b,c;
	cin >> t;
	while (t--)
	{
		cin >> a >> b >> c;
		cout << a / 2 - (c - 4 * b) / 4 << endl;
	}
	return 0;
}
*/

/*
typedef long long ll;
ll gcd(ll a, ll b)
{
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main()
{
	int i, n, m;
	while (~scanf("%d %d",&n, &m))
	{
		vector<int> v, vt;
		v.resize(n);
		ll all = 0;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &v[i]);
			all += v[i];
		}
		ll sq,sqb;
		if (m == 1)
		{
			printf("0/1\n");
			continue;
		}
		else if (n == m)
		{
			sq = 0;
			for (i = 0; i < n; ++i)
				sq += (n*v[i] - all)*(n*v[i] - all);
			sqb = n*n;
		}
		else
		{
			sort(v.begin(), v.end());
			int start = 0, left, right;
			for (i = 0; i < n; ++i)
			{
				if (n*v[i] - all > 0)
				{
					start = i;
					break;
				}
			}
			if (start - 1 >= 0 && v[start] - all > all - v[start - 1])
				start--;
			int c = 1;
			left = c - 1, right = c + 1;
			vt.resize(m);
			vt[0] = v[start];
			for (; c < m; ++c)
			{
				if (left >= 0 && right < n)
				{
					if (abs(n*v[left] - all) < abs(n*v[right] - all))
						vt[c] = v[left--];
					else
						vt[c] = v[right++];
				}
				else if (left < 0)
					vt[c] = v[right++];
				else
					vt[c] = v[left--];
			}
			all = 0;
			for (i = 0; i < vt.size();++i)
				all += vt[i];
			sq = 0;
			for (i = 0; i < vt.size(); ++i)
				sq += (m*vt[i] - all)*(m*vt[i] - all);
			sqb = m*m;
		}
		
		ll g = gcd(sq, sqb);
		sq /= g, sqb /= g;
		if (n == m)
			sqb *= n;
		else
			sqb *= m;
		g = gcd(sq, sqb);
		sq /= g, sqb /= g;
		if (sqb == 0 || sqb == 1)
			printf("%lld\n", sq);
		else
			printf("%lld/%lld\n", sq, sqb);
	}
	return 0;
}
*/

/*
int main()
{
	long long a, b, c,d,e,f;
	while (cin >> a >> b >> c)
	{
		d = min(a, min(b, c));
		f = max(a, max(b, c));
		e = a + b + c - d - f;
		if (d + e > f && e - d < f)
			cout << d + e + f << endl;
		else
			cout << 2 * (d + e)-1 << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a == b && a + b > c)
			cout << "Yes" << endl;
		else if (a == c && a + c > b)
			cout << "Yes" << endl;
		else if (b == c && b + c > a)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
*/

/*

*/


/*
int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int start[60] = { 3 };

int main()
{
	int year, month, c = 1;
	for (year = 2015; year <= 2018; ++year)
	{
		for (month = 1; month <= 12; ++month)
		{
			if (year == 2015 && month == 1)
				month = 2;
			int m = month - 2;
			if (m == -1)
				m = 11;
			int day = days[m];
			if (year == 2016 && m == 1)
				day++;
			start[c] = (start[c - 1] + day) % 7 ;
			c++;
		}
	}
	while (~scanf("%d-%d", &year, &month))
	{
		int s = start[(year - 2015) * 12 + month - 1];
		int day = days[month - 1];
		if (year == 2016 && month == 2)
			day++;

		int d,now;
		now = s;
		cout << string(3 * s, ' ');
		for (d = 1; d <= day; ++d)
		{
			printf("%2d", d);
			now++;
			if (now == 7)
			{
				putchar('\n');
				now = 0;
			}
			else if (d != day)
				putchar(' ');
		}
		if (now != 0)
			putchar('\n');
		putchar('\n');
	}
	return 0;
}
*/

/*
int n,sum;
vector<int> v;
int visit[100];
bool dfs(int curlen, int expect, int start, int num)
{
	if (num == n)
		return true;
	
	int last = -1;
	for (int i = start; i < n; ++i)
	{
		if (visit[i] || v[i] == last)
			continue;

		visit[i] = 1;
		if (curlen + v[i] < expect)
		{
			if (dfs(curlen + v[i], expect, i, num + 1))
				return true;
			else
				last = v[i];
		}
		else if (curlen + v[i] == expect)
		{
			if (dfs(0, expect, 0, num + 1))
				return true;
			else
				last = v[i];
		}
		visit[i] = 0;
		if (curlen == 0)
			break;
	}
	return false;
}

int main()
{
	while (cin >> n && n != 0)
	{
		v.resize(n);
		sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			sum += v[i];
		}
		sort(v.begin(), v.end(), greater<int>());
		memset(visit, 0, sizeof(visit));
		int cur = v[0];
		bool flag = false;
		for (cur = v[0]; cur <= sum - cur; ++cur)
		{
			if ((sum%cur == 0) && dfs(0, cur, 0, 0))
			{
				cout << cur << endl;
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << sum << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n, m;
	int i, k;
	while (cin >> n >> m >> k)
	{
		if (n % m == 0)
			cout << 0 << endl;
		else
		{
			int t = n / m;
			int next = (n - t*m)*10;
			for (i = 0; i < k; ++i)
			{
				t = next / m;
				next = (next - t*m) * 10;
			}
			cout << t << endl;
		}
	}
	return 0;
}
*/

/*
int main()
{
	long long i, n, a, b;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> a >> b;
		if (a % b == 0)
			cout << a / b << ' '<< b << endl;
		else
			cout << a / b + 1 << ' '<< a%b << endl;
	}
	return 0;
}
*/
/*
long long tab[4] = {0,0,0,1};
long long ret[1005];
int main()
{
	int i,n;
	
	for (i = 0; i <= 1000; ++i)
	{
		ret[i] = (tab[1] + tab[2] + tab[3]) % 1000000007;
		tab[1] = tab[2] % 1000000007;
		tab[2] = tab[3] % 1000000007;
		tab[3] = (tab[1] + tab[2]) % 1000000007;
	}

	while (cin >> n)
		cout << ret[n]  << endl;
	return 0;
}
*/


/*
int main()
{
	long long a, b;
	char c;
	while (cin >> a >> c >> b)
		cout << a + b << endl;
	return 0;
}
*/

/*
int main()
{
	int i,n,cc=1,t;
	while (cin >> n && n != 0)
	{
		map<int, int> id2team;
		int inqueue[1005];
		memset(inqueue, 0, sizeof(inqueue));
		queue<int> q[1005], allqueue;
		for (i = 0; i < n; ++i)
		{
			int tn;
			cin >> tn;
			for (int j = 0; j < tn; ++j)
			{
				cin >> t;
				id2team[t] = i;
			}
		}
		cout << "Scenario #" << cc << endl;
		
		string tmpstr;
		while (cin >> tmpstr)
		{
			if (tmpstr == "STOP")
			{
				cout.put('\n');
				cc++;
				break;
			}
			else if (tmpstr == "ENQUEUE")
			{
				cin >> t;
				int team = id2team[t];
				q[team].push(t);	
				if (!inqueue[team])
				{
					allqueue.push(team);
					inqueue[team] = 1;
				}
			}
			else
			{
				queue<int> &tmpq = q[allqueue.front()];
				cout << tmpq.front() << endl;
				tmpq.pop();
				if (tmpq.empty())
				{
					inqueue[allqueue.front()] = 0;
					allqueue.pop();
				}
			}
		}
	}
	return 0;
}
*/

/*
int main()
{
	int n;
	while (cin >> n && n != 0)
	{
		vector<int> need(n);
		
		while (cin >> need[0])
		{
			if (need[0] == 0)
				break;
			for (int i = 1; i < n; ++i)
				cin >> need[i];
			int current = 1;
			int out = 0;
			stack<int> q;
			bool flag = true;
			for (; out < n && flag;)
			{
				int v = need[out];
				if (v == current)
				{
					out++;
					current++;
				}
				else if (!q.empty() && v == q.top())
				{
					out++;
					q.pop();
				}
				else
				{
					q.push(current);
					current++;
				}
				if (current > n + 1)
					flag = false;
			}
			if (flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		cout << endl;
	}
}
*/

/*
int w, h;
char map[30][30];

int bfs(int x, int y)
{
	int ret = 0;
	queue<int> qx;
	queue<int> qy;
	qx.push(x);
	qy.push(y);
	while (!qx.empty())
	{
		x = qx.front(), y = qy.front();
		qx.pop(), qy.pop();
		if (map[y][x] == '#')
			continue;

		if (map[y][x] == '.' || map[y][x] == '@')
		{
			ret++;
			map[y][x] = '#';
		}
		if (x != w - 1)
		{
			qx.push(x + 1);
			qy.push(y);
		}
		if (x != 0)
		{
			qx.push(x - 1);
			qy.push(y);
		}
		if (y != h - 1)
		{
			qx.push(x);
			qy.push(y + 1);
		}
		if (y != 0)
		{
			qx.push(x);
			qy.push(y - 1);
		}
	}
	return ret;
}

int main()
{	
	int i,x,y;
	while (cin >> w >> h && (w != 0 && h != 0))
	{
		for (i = 0; i < h; ++i)
			scanf("%s", map[i]);
		bool finded = false;
		for (x = 0; x < w && !finded; ++x)
			for (y = 0; y < h && !finded; ++y)
				if (map[y][x] == '@')
					finded = true;
		cout << bfs(x-1, y-1) << endl;
	}
	return 0;
}
*/

/*
bool joseph(int k, int m)
{
	int n, index, i;
	n = 2 * k;
	index = 0;
	for (i = 0; i < k; i++)
	{
		index = (index + m - 1) % n;
		n--;
		if (index < k)
			return false;
	}
	return true;
}
int tab[15] = { 0 };
int main()
{
	int k, n, i, ex;
	while (cin >> k && k != 0)
	{
		if (tab[k] == 0)
		{
			ex = 0;
			for (n = k + 1; !ex; ++n)
			{
				if (joseph(k, n))
				{
					tab[k] = n;
					ex = 1;
					break;
				}
			}
		}
		cout << tab[k] << endl;
	}
	return 0;
}
*/

/*
int m, n;
int main()
{
	int T, dp[50][50] = { 0 };
	cin >> T;
	dp[0][0] = 1;
	for(int y=1;y<=40;++y)
		for (int x = 1; x <= 40; ++x)
		{
			if (y - 2 >= 0 && x - 1 >= 0)
				dp[x][y] += dp[x - 1][y - 2];
			if (y - 1 >= 0 && x - 2 >= 0)
				dp[x][y] += dp[x - 2][y - 1];
		}
	while (T--)
	{
		cin >> m >> n;
		cout << dp[m - 1][n - 1] << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int i,n,t;
	string str,out;
	cin >> n;
	while (n--)
	{
		str.clear();
		getline(cin, str);
		if (str == "")
		{
			n++;
			continue;
		}
		out.resize(str.size());
		for (i = 0; i < str.size(); ++i)
		{
			cin >> t;
			out[t - 1] = str[i];
		}
		cout << out << endl;
	}
	return 0;
}
*/

/*
int main()
{
	vector<int> v;
	int n, i, t;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		v.push_back(t);
	}
	cin >> t;
	auto it = find(v.begin(), v.end(), t);
	if (it == v.end())
		cout << "Not Found";
	else
	{
		v.erase(it);
		for (i = 0; i < v.size(); ++i)
			cout << setw(4) << v[i];
	}
	return 0;
}
*/

/*
int main()
{
	int i, n;
	double sum = 0;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		if (i % 2 == 0)
			sum -= 1.0 * i / (2 * i - 1);
		else
			sum += 1.0 * i/ (2 * i - 1);
	}
	printf("%.3lf", sum);
	return 0;
}
*/

/*
int main()
{
	int i, n, m=0, t;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		if (t > m)
			m = t;
	}
	cout << m;
	return 0;
}
*/

/*
int main()
{
	int i, n;
	double sum = 0;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		if (i % 2 == 0)
			sum -= 1.0 / (2*i - 1);
		else
			sum += 1.0 / (2 * i - 1);
	}
	printf("%.2lf", sum);
	return 0;
}
*/
/*
int main()
{
	int i, t, m;
	m = 0;
	for (i = 0; i < 3; ++i)
	{
		cin >> t;
		if (abs(t) > abs(m))
			m = t;
	}
	cout << m;
	return 0;
}
*/

/*
int main()
{
	int n, t, i;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		if (t <= 3)
			cout << "No" << endl;
		else if (t % 2 == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n, i, m, id, t;
	cin >> n;
	m = 999999, id = 0;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		if (t < m)
		{
			id = i;
			m = t;
		}
	}
	cout << m << ' ' << id << endl;
	return 0;
}
*/

/*
int main()
{
	set<string> s;
	string str, t;
	cin >> t >> str;
	do{
		s.insert(str);
	} while (next_permutation(str.begin(), str.end()));
	cout << s.size();
	return 0;
}
*/

/*
int main()
{
	int dp[300][300] = { 0 };
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int i, j;
	for (i = 0; i < s1.size(); ++i)
		dp[i][0] = i;
	for (i = 0; i < s2.size(); ++i)
		dp[0][i] = i;
	for (i = 1; i <= s1.size(); ++i)
	{
		for (j = 1; j <= s2.size(); ++j)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
		}
	}
	cout << dp[s1.size()][s2.size()];
	return 0;
}
*/

/*
int main()
{
	int n,i;
	cin >> n;
	while (n--)
	{
		int m;
		cin >> m;
		vector<int> v;
		v.resize(m);
		for (int i = 0; i < m; ++i)
			cin >> v[i];
		sort(v.begin(), v.end());
		int a, b;
		a = b = 0;
		for (i = 0; i < m; ++i)
		{
			if (v[i] % 2) a++;
			else b++;
		}
		if (a > 0)
		{
			int ans = 0;
			if (a % 2 == 0)
				a--;
			for (i = m - 1; i >= 0; --i)
			{
				if (v[i] % 2 == 1 && a > 0)
				{
					ans += v[i];
					a--;
				}
				else if (v[i] % 2 == 0)
					ans += v[i];
			}
			cout << ans << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int d[31][31];
	int i,n,x,y;
	while (cin >> n && n != 0)
	{
		fill(d[0], d[0] + 31 * 31, 0);
		x = (n - 1) / 2;
		y = n-1;
		d[x][y] = 1;
		for (i = 2; i <= n*n; ++i)
		{
			x++, y++;
			if (d[x%n][y%n] != 0)
				x--, y -= 2;
			d[x%n][y%n] = i;
		}
		for (y = 0; y < n; ++y)
		{
			for (x = 0; x < n; ++x)
			{
				if (x != 0)
					putchar(' ');
				if (n < 5)
					printf("%d", d[x][y]);
				else if (n < 10)
					printf("%2d", d[x][y]);
				else
					printf("%3d", d[x][y]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
*/

/*
int d[1005][10] = { 0 };
int visit[1005] = { 0 };
bool cmp(int a, int b)
{
	for (int i = 0; i < 10; ++i)
		if (d[a][i] != d[b][i])
			return false;
	return true;
}
void f(int n)
{
	if (visit[n])
		return;
	visit[n] = 1;
	int t = n;
	while (t)
	{
		d[n][t % 10]++;
		t /= 10;
	}
}

int main()
{
	vector<int> v;
	int n, t, i;
	while (cin >> n && n != 0)
	{
		v.clear();
		v.resize(n);
		fill(d[0], d[0] + 1005 * 10, 0);
		for (i = 0; i < n; ++i)
		{
			cin >> v[i];
			f(v[i]);
		}
		auto it = v.begin();
		
		for (; it != v.end(); )
		{
			bool flag = false;
			auto next = it+1;
			while (next != v.end())
			{
				if (*it == *next || cmp(*it, *next))
				{
					next = v.erase(next);
					flag = true;
				}
				else
					++next;
			}
			if (!flag)
				it++;
			else
				it = v.erase(it);
		}
		sort(v.begin(), v.end());
		if (v.empty())
			cout << "None";
		else
		{
			for (i = 0; i < v.size(); ++i)
			{
				if (i != 0)
					putchar(' ');
				cout << v[i];
			}
		}
		cout << endl;
	}
	return 0;
}
*/

/*
int main()
{
	map<int,int> d;
	int i, n, t, m;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> t;
		d[t]++;
	}
	n = (--d.end())->first;
	m = 0;
	t = 0;
	for (i = 0; i < n; ++i)
	{
		if (d[i] > m)
		{
			t = i;
			m = d[i];
		}
	}
	cout << t << endl << m;
	return 0;
}
*/

/*
int main(){
int m,n,i,a,b,c,d;cin>>m>>n>>a;
for(i=1;i<m;++i)cin>>b;cin>>c;
for(i=1;i<n;++i)cin>>d;
if(a>d)i=abs(a-d);
else if(c>b)i=abs(c-b);
else i=0;cout<<i;return 0;
}
*/

/*
void inverse(int n)
{
	int t;
	if (n == 1)
		cin >> t;
	else
	{
		cin >> t;
		inverse(n - 1);
	}
	printf("%4d", t);
}

int main()
{
	int n;
	cin >> n;
	inverse(n);
	return 0;
}
*/

/*
int c = 0;
int fib(int k)
{
	c++;
	if (k == 1 || k == 2)
		return 1;
	else
		return fib(k - 1) + fib(k - 2);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fib(n));
	printf("递归调用了%d次", c);
	return 0;
}
*/


/*
void convert(int n)
{
	if (n > 0)
	{
		convert(n / 2);
		cout << n % 2;
	}
}

int main()
{
	int n;
	cin >> n;
	convert(n);
	return 0;
}
*/

/*
void inverse(int n)
{
	int t;
	if (n == 1)
		cin >> t;
	else
	{
		cin >> t;
		inverse(n - 1);
	}
	cout << t << ' ';
}

int main()
{
	int n;
	cin >> n;
	inverse(n);
	return 0;
}
*/

/*
int common(int x, int y)
{
	if (x == y)
		return x;
	else if (x > y)
		return common(x / 2, y);
	else
		return common(x, y / 2);
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << common(x, y);
	return 0;
}
*/

/*
int digitSum(int n)
{
	int ret = 0;
	while (n)
	{
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int in;
	cin >> in;
	while (in >= 10)
		in = digitSum(in);
	cout << in;
	return 0;
}
*/

/*
void printline(int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d", i + 1);
	for (i = n - 1; i > 0; --i)
		printf("%d", i);
	putchar('\n');
}

int main()
{
	int n,i;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cout << string(n - i, ' ');
		printline(i);
	}
	for (i = 1; i < n; ++i)
	{
		cout << string(i, ' ');
		printline(n-i);
	}
	return 0;
}
*/

/*
int reverse(int n)
{
	int ret = 0;
	while (n)
	{
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int i, m, n;
	cin >> n;
	bool flag = false;
	if (n == reverse(n))
		printf("%d",n);
	else
	{
		while (m = reverse(n), m != n)
		{
			if (flag)
				putchar(' ');
			printf("%d", n);
			flag = true;
			n = m + n;
		}
		printf(" %d", n);
	}
	return 0;
}
*/

/*
int table[100000] = { 0 };
int facsum(int n)
{
	if (table[n])
		return table[n];
	int ret, i;
	ret = 0;
	for (i = 1; i < n; ++i)
		if (n % i == 0)
			ret += i;
	return table[n] = ret;
}

int main()
{
	int m, n,i,j;
	cin >> m >> n;
	bool flag = false;
	for (i = m; i <= n; ++i)
	{
		int other = facsum(i);
		if (i < other && other <= n && facsum(other) == i)
		{
			printf("%d %d\n", i, other);
			flag = true;
		}
	}
	if (!flag)
		printf("No answer");
	return 0;
}
*/

/*
int main()
{
	int n;
	int all, a, b,c;
	cin >> n;
	all = c = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		all += a;
		if (b >= 60)
			c += (b - 50) / 10 * a;
	}
	printf("%.1lf", 1.0*c / all);
	return 0;
}
*/

/*
int main()
{
	double in;
	cin >> in;
	in *= 0.05;
	double t = in - int(in);
	in -= t;
	if (t < 0.25)
		t = 0;
	else if (t < 0.75)
		t = 0.5;
	else
		t = 1;
	in += t;
	printf("%.1lf", in);
	return 0;
}
*/

/*
int reverse(int n)
{
	int ret = 0;
	while (n)
	{
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int in;
	cin >> in;
	cout << in + reverse(in);
	return 0;
}
*/
/*
long long fact(int n)
{
	long long ret = 1;
	for (int i = 2; i <= n; ++i)
		ret *= i;
	return ret;
}

int main()
{
	int m,k;
	cin >> m >> k;
	cout << fact(m) / (fact(k)*fact(m - k));
	return 0;
}
*/

/*
int main()
{
	set<char> s;
	char duichen[12] = "AHIMOTUVWXY";
	int i;
	for (i = 0; i < 12; ++i)
		s.insert(duichen[i]);

	string str;
	bool flag = true;
	while (cin >> str)
	{
		flag = true;
		for (i = 0; i < str.size(); ++i)
		{
			if (s.find(str[i]) == s.end())
			{
				cout << "No" << endl;
				flag = false;
				break;
			}
		}
		if (flag)
		{
			string rev(str.rbegin(), str.rend());
			if (rev == str)
				cout << "Yes" << endl;
			else
				cout << "No";
		}
	}
	return 0;
}
*/

/*
int main()
{
	double a, b, c;
	char op;
	cin >> a >> op >> b;
	switch (op)
	{
	case '+':
		printf("%.2lf", a + b);
		break;
	case '-':
		printf("%.2lf", a - b);
		break;
	case '*':
		printf("%.2lf", a * b);
		break;
	case '/':
		if (fabs(b) < 1e-10)
			printf("Wrong input!");
		else
			printf("%.2lf", a / b);
		break;
	default:
		printf("Wrong input!");
	}
	return 0;
}
*/

/*
int main()
{
	int days[12] = { 31 ,28,31,30,31,30,31,31,30,31,30,31 };
	int year, month;
	cin >> year >> month;
	if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && month == 2)
		cout << days[month-1] + 1;
	else
		cout << days[month - 1];
	return 0;
}
*/
/*
int f(int x)
{
	if (x < -2)
		return 7 - 2 * x;
	if (x >= 3)
		return 3 * x + 4;
	return 5 - abs(3 * x + 2);
}

int main()
{
	int in;
	cin >> in;
	cout << f(in);
	return 0;
}
*/

/*
int op(char o)
{
	if (o == '+' || o == '-')
		return 1;
	if (o == '*' || o == '/')
		return 2;
	return 0;
}
double out(double a, char op, double b)
{
	switch (op)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}

int main()
{
	double a, b, c, ret,tmp;
	char op1, op2;
	while (~scanf("%lf%c%lf%c%lf", &a, &op1, &b, &op2, &c))
	{
		if (op(op1) >= op(op2))
		{
			tmp = out(a, op1, b);
			ret = out(tmp, op2, c);
		}
		else
		{
			tmp = out(b, op2, c);
			ret = out(a, op1, tmp);
		}
		printf("%.4lf\n", ret);
	}
	return 0;
}
*/
/*
int main()
{
	int a, b,c,d;
	int q, w, e;
	while (cin >> a >> b)
	{
		a = a + b;
		b = a / 100;
		c = a % 100 / 10;
		d = a % 10;
		q = max(b, max(c, d));
		e = min(b, min(c, d));
		w = b + c + d - q - e;
		cout << q * 100 + w * 10 + e << endl;
	}
}
*/
/*
int main()
{
	int money, n;
	while (cin >> money)
	{
		n = money / 9;
		bool t = false;
		while (n)
		{
			if (n % 10 == 7)
			{
				t = true;
				break;
			}
			n /= 10;
		}
		if (t)
			cout << "么么哒" << endl;
		else
			cout << "呵呵哒" << endl;
	}
	return 0;
}
*/

/*
int main()
{
	long long i,n, r;
	
	while (cin >> n)
	{
		r = 0;
		for (i = 0; i < n; ++i)
		{
			if (i == 0)
				r += 15;
			else if (i == 1)
				r += 195;
			else if (i == 2)
				r += 1995;
			else
				r += 9995;
			r = r % 10000;
		}
		i = r / 1000 + (r / 100) % 10 + (r / 10) % 10 + r % 10;
		cout << i << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cout << string(n - i - 1, ' ') << string(2*i+1,'o') << endl;
	return 0;
}
*/

/*
int main()
{
	double rx,ry, r,x1,y1,x2,y2;
	while (cin >> rx >> ry >> r >> x1 >> y1 >> x2 >> y2)
	{
		double dis;
		if (x1 == x2)
			dis = fabs(rx - x1);
		else if (y1 == y2)
			dis = fabs(ry - y1);
		else
		{
			double k1, b1, k2, b2, x3, y3;
			k1 = (y1 - y2) / (x1 - x2);
			b1 = y1 - k1*x1;
			k2 = -1 / k1;
			b2 = ry - k2*rx;
			y3 = (k2*b1 - k1*b2) / (k2 - k1);
			x3 = (y3 - b1) / k1;
			dis = sqrt(pow(rx - x3, 2) + pow(ry - y3, 2));
		}
		if (fabs(dis - r) <= 1e-6)
			cout << 1;
		else if (dis < r)
			cout << 2;
		else
			cout << 0;
		cout << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int year;
	cin >> year;
	if ((year % 4 == 0 && year % 100 != 0 ) || year % 400 == 0)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}
*/

/*
int main()
{
	double a,b,c,d,e,s,v;
	cin >> a >> b >> c >> d >> e;
	s = 2 * (a*b + b*c + a*c) + 8*d*(a+b+c-6*e);
	v = a*b*c - 2 * d*(a - 2 * e)*(c - 2 * e) - 2 * d*(b - 2 * e)*(c - 2 * e) - 2 * d*(a - 2 * e)*(b - 2 * e);
	printf("%.0lf %.0lf",s,v);
	return 0;
}
*/

/*
int main()
{
	int i;
	printf("Please enter data of students:\n");
	for (i = 0; i<SIZE; i++)
		scanf("%s%d%d%s", stud[i].name, &stud[i].num, &stud[i].age, stud[i].addr);
	save();
	return 0;
}
*/

/*
int main()
{
	long long a,b;
	cin >> a >> b;
	cout << a+b << ' ' << a-b << ' ' << a*b << ' ' << a/b << ' ' << a - (a/b)*b;
	return 0;
}
*/

/*
typedef pair<int, int> cai;

bool cmp(const cai& c1, const cai& c2)
{
	return (1.0*c1.first/c1.second) > (1.0*c2.first/c2.second);
}

int main()
{
	int c;
	cin >> c;
	
	cai cc;
	while (c--)
	{
		vector<cai> v;
		int i, n, k, x, y,sum;
		sum = 0;
		cin >> n >> k >> x >> y;
		for (i = 0; i < n; ++i)
		{
			cin >> cc.first >> cc.second;
			v.push_back(cc);
			sum += cc.second;
		}
		if (sum <= k)
			cout << "go die" << endl;
		else
		{
			sort(v.begin(), v.end());

			int cm,ck;
			cm = ck = 0;
			for (i = 0; i < v.size(); ++i)
			{
				cm += v[i].first;
				ck += v[i].second;
				if (ck > k)
					break;
			}
			if (cm >= x)
				cm -= y;
			else
			{
				int tcm, tck;
				tcm = cm, tck = ck;
				for (; i < v.size(); ++i)
				{
					tcm += v[i].first;
					tck += v[i].second;
					if (tcm >= x)
						break;
				}
				tcm -= y;
				if (tcm < cm)
					cm = tcm;
			}
			cout << cm;
			if (c)
				putchar('\n');
		}
	}
	return 0;
}
*/

/*
struct edge
{
	int a, b;
	int gongsi;
	edge() {}
	edge(int aa, int bb, int g) : a(aa), b(bb), gongsi(gongsi) {}
};

const int MAX = 100005;
const int INF = 0x3fffffff;

vector<edge> e[MAX];
int visited[MAX];
int repath[MAX];
int path[MAX];
int findd = false;

int table[MAX][MAX];
int finde(int ee, int v)
{
	int ret = 0;
	for (int i = 0; i < e[ee].size(); ++i)
	{
		if (e[ee][i].b == v)
			return i;
	}
	return -1;
}

int getlen(int start, int end)
{
	int current = end;
	int ret = 0;
	while (current != start)
	{
		int prev = e[current][repath[current]].b;
		path[prev] = finde(prev, current);
		current = prev;
		ret++;
	}
	return ret;
}



void dij(int start, int end)
{
	int dis[MAX], count[MAX];
	fill(dis, dis + MAX, INF);
	fill(count, count + MAX, INF);

	dis[start] = 0;
	count[start] = 0;

	while (1)
	{
		int id = -1, ii, ma = INF;
		for (int i = 0; i < MAX; ++i)
		{
			if (!visited[i] && dis[i] != INF && ma > dis[i])
			{
				id = i;
				ma = dis[i];
			}
		}

		if (id == -1)
			break;

		if (id == end)
		{
			findd = true;
			break;
		}

		visited[id] = 1;

		for (int j = 0; j < e[id].size(); ++j)
		{
			int v = e[id][j].b;
			if (!visited[v])
			{
				int vid = finde(v, id);
				if (dis[id] + 1 < dis[v])
				{
					dis[v] = dis[id] + 1;
					if (id == start)
						count[v] = count[id];
					else if (e[id][repath[id]].gongsi == e[v][vid].gongsi)
						count[v] = count[id];
					else
						count[v] = count[id] + 1;
					repath[v] = vid;
				}
				else if (dis[id] + 1 == dis[v])
				{
					if (count[v] > count[id])
					{
						count[v] = count[id];
						repath[v] = finde(v, id);
					}
				}
			}
		}
	}

}


int main()
{
	int n;
	edge edg;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int k;
		cin >> k;
		int a, b;
		cin >> a;
		edg.gongsi = i+1;
		for (int j = 1; j < k; ++j)
		{
			cin >> b;
			edg.a = a;
			edg.b = b;
			e[a].push_back(edg);
			swap(edg.a, edg.b);
			e[b].push_back(edg);
			a = b;
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int start, end;
		cin >> start >> end;
		findd = false;
		memset(visited, 0, 4 * MAX);
		dij(start, end);
		
		if (!findd)
		{
			printf("Sorry, no line is available.\n");
			continue;
		}
		int len = getlen(start, end);
		cout << len << endl;
		int currentgongsi = e[start][path[start]].gongsi;
		int next = start;
		int nextgongsi = currentgongsi;
		while (start != end)
		{
			while (currentgongsi == nextgongsi)
			{
				next = e[next][path[next]].b;
				nextgongsi = e[next][path[next]].gongsi;
				if (next == end)
					break;
			}
			printf("Go by the line of company #%d from %d to %d.\n", currentgongsi, start, next);
			start = next;
			currentgongsi = nextgongsi;
		}
	}
	return 0;
}

*/

/*
string game[100000];
vector<int> ret[100000];

int main()
{
	int i,n;
	cin >> n;
	getline(cin, game[0]);

	for (i = 0; i < n; ++i)
		getline(cin, game[i]);

	for (i = 0; i < n; ++i)
	{
		int c = count(game[i].begin(), game[i].end(), 'D');
		if (c == n - 1)
		{
			printf("No Solution\n");
			return 0;
		}
	}
}
*/

/*
double a[1000000], b[1000000], c[1000000];

int main()
{
	int maxa, maxb;
	maxa = maxb = 0;

	int i, n, m;
	cin >> n;
	int xi, e;
	for (i = 0; i < n; ++i)
	{
		cin >> e >> xi;
		a[e] = xi;
		if (i == 0)
			maxa = e;
	}

	cin >> m;
	for (i = 0; i < m; ++i)
	{
		cin >> e >> xi;
		b[e] = xi;
		if (i == 0)
			maxb = e;
	}

	for (int j = maxa; j >= maxb; --j)
	{
		c[j - maxb] = a[j] / b[maxb];
		for (int k = j, p = maxb; k >= j - maxb && p >= 0; --k, --p)
			a[k] = a[k] - c[j - maxb] * b[p];
	}

	int cc = 0;

	for (i = maxa - maxb; i >= 0; --i)
	{
		int z = c[i] * 100;
		int d = z % 10;
		if (abs(d) > 5)
		{
			if (z > 0)
				c[i] = (z - d + 10)*1.0 / 100;
			else
				c[i] = (z - d - 10)*1.0 / 100;
		}

		else
			c[i] = (z - d)*1.0 / 100;
		if (c[i] != 0)
			cc++;
	}
	if (cc == 0)
		printf("0 0 0.0");
	else
	{
		printf("%d", cc);

		// 商 
		// b 与 c 同阶 
		for (i = maxa - maxb; i >= 0; i--)
		{
			if (c[i] != 0)
				printf(" %d %.1lf", i, c[i]);
		}
	}
	putchar('\n');

	cc = 0;
	for (i = maxb - 1; i >= 0; --i)
	{
		int z = a[i] * 100;
		int d = z % 10;
		if (abs(d) > 5)
		{
			if (d > 0)
				a[i] = (z - d + 10)*1.0 / 100;
			else
				a[i] = (z - d - 10)*1.0 / 100;
		}

		else
			a[i] = (z - d)*1.0 / 100;
		if (a[i] != 0)
			cc++;
	}
	if (cc == 0)
		printf("0 0 0.0");
	else
	{
		printf("%d", cc);
		for (i = maxb - 1; i >= 0; --i)
		{
			if (a[i] != 0)
				printf(" %d %.1lf", i, a[i]);
		}
	}
	putchar('\n');
	return 0;
}
*/


/*
int main()
{
	int half, num, a, b,i;
	vector<int> v;

	cin >> num;
	v.resize(num);

	for (i = 0; i < num; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	half = num / 2;
	a = b = 0;
	for (i = half; i < num; ++i)
		a += v[i];
	for (i = 0; i < half; ++i)
		b += v[i];
	if (num % 2 != 0)
		half++;
	printf("Outgoing #: %d\n", half);
	printf("Introverted #: %d\n", num - half);
	printf("Diff = %d\n", a - b);
	return 0;
}
*/


/*
int main()
{
	int year, num;
	set<int> t;
	cin >> year >> num;
	int c[4];
	int ret = 0, tmp;

	tmp = year;
	do
	{
		t.clear();
		c[0] = tmp / 1000;
		c[1] = (tmp % 1000) / 100;
		c[2] = (tmp % 100) / 10;
		c[3] = tmp % 10;
		for (int i = 0; i < 4; ++i)
			t.insert(c[i]);
		ret++;
		tmp++;
		
	} while (t.size() != num);
	printf("%d %04d", ret-1, year + ret-1);
	return 0;
}
*/

/*
#include <iostream>
#include <cmath>
using namespace std;

double E = 1000,g = 9.8, m, w,p;

double E2V(double E)
{
	return sqrt(2*E/m);
}

int main()
{
	double ang;
	double v;
	cin >> w >> p;
	
	ang = acos(-1)/4;
	m = w/100;
	
	p = (1-p/100);
	
	double s=0,vx,vy,t,dx;
	v = E2V(E);
	vy = v * sin(ang);
	vx = v * cos(ang);
	t = vy/g;
	dx = 2*t*vx;
	do
	{
		s += dx;
		E = E * p;
		v = E2V(E);
		vy = v * sin(ang);
		vx = v * cos(ang);
		t = vy/g;
		dx = 2*t*vx;
	}
	while(abs(dx) > 1e-10);
	
	printf("%.3lf\n", s);
}
*/

/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <cmath>
#include <functional>
#include <string.h>
using namespace std;

const int MAX = 100005;
vector<int> e[MAX];
int visited[MAX]  = {0};
double gongli[MAX];
int    dedao[MAX] = {0};
int    shifu[MAX] = {0};
long long beishu[MAX] = {0};

double z,r;

double bfs()
{
	double ans = 0;
	
	queue<int> q;
	q.push(0);
	visited[0] = 1;
	
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		
		if (dedao[now])
		{
			gongli[now] = gongli[shifu[now]] * r * beishu[now];
			
			ans += gongli[now];
		}
		else
		{
			if (now != 0)
				gongli[now] = gongli[shifu[now]] * r;
		}
		
		
		visited[now] = 1;
		
		for(int i=0; i < e[now].size(); ++i)
		{
			int v = e[now][i];
			if (!visited[v])
			{
				q.push(v);
			}
		}
	}
	return ans;
}

int main()
{
	long long n,i,j;
	
	cin >> n >> z >> r;
	gongli[0] = z;
	
	r = (1-r/100);
	for(i=0; i < n; ++i)
	{
		long long k,t;
		cin >> k;
		if (k == 0)
		{
			cin >> t;
			dedao[i] = 1;
			beishu[i] = t;
		}
		else
		{
			for(j=0; j < k; ++j)
			{
				cin >> t;
				e[i].push_back(t);
				e[t].push_back(i);
				shifu[t] = i;
			}
		}
	}
	
	long long ans = bfs();
	
	cout << ans;
	return 0;
}
*/

/*
int main()
{
	int n,m,i,j;
	int total;
	set<string> guanzhu;
	map<string, int> zan;
	
	scanf("%d",&n);
	
	char buffer[10];
	for(i=0; i < n; ++i)
	{
		scanf("%s", buffer);
		guanzhu.insert(buffer);
	}
	
	total = 0;
	cin >> m;
	for(i=0; i < m; ++i)
	{
		int number;
		scanf("%s %d", buffer, &number);
		zan[buffer] = number;
		total += number;
	}
	
	double avr = 1.0* total / zan.size();
	
	map<string,int>::iterator it = zan.begin();
	
	set<string> out;
	for(; it != zan.end(); ++it)
	{
		if (it->second > avr && guanzhu.find(it->first) == guanzhu.end())
		{
			out.insert(it->first);
		}
	}

	if (!out.empty())
	{
		set<string>::iterator it2 = out.begin();
		for(; it2 != out.end(); ++it2)
			cout << *it2 << endl;
	}
	else
		cout << "Bing Mei You";
	

	return 0;
}
*/
/*
int main()
{
	int n,i,t;
	vector<int> v;
	
	cin >> n;
	v.resize(n);
	for(i=0; i<n;++i)
		cin >> v[i];
	
	sort(v.begin(), v.end());	
	int sum1,sum2;
	sum1=sum2=0;

	int half = v.size()/2;
	
	for(i=half; i <v.size(); ++i)
		sum1 += v[i];
	for(i=0; i < half; ++i)
		sum2 += v[i];
	
	if (v.size() % 2 != 0)
		half++;
	
	int diff = abs(sum1-sum2);
	
	printf("Outgoing #: %d\n", half);
	printf("Introverted #: %d\n", v.size()-half);
	printf("Diff = %d\n", sum1-sum2);
	return 0;
}
*/

/*
int main()
{
	int n,i,lie,j;
	lie = 1;
	string str;
	cin >> n;
	getline(cin,str);
	if (str == "")
		getline(cin,str);
	while(lie*n < str.size())
	{
		lie++;
	}
	
	for(i=0; i < n; ++i)
	{
		for(j=lie-1; j >=0; --j)
		{
			int loc = j*n+i;
			if (loc < str.size())
				putchar(str[loc]);
			else
				putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
*/

/*
int main()
{
	vector<string> v;
	int n;
	n = 0;
	string str;
	while(n <= 20)
	{	
		n++;
		cin >> str;
		
		if (str == ".")
			break;
		v.push_back(str);
	}
	
	if (v.size() >= 14)
		printf("%s and %s are inviting you to dinner...", v[1].c_str(), v[13].c_str());
	else if (v.size() >= 2 )
		printf("%s is the only one for you...", v[1].c_str());
	else
		printf("Momo... No one is for you ...");
	return 0;
}
*/

/*
int main()
{
	int texing[1005] = {0};
	int n,i,j,t,k,c;
	cin >> n;
	for(i=0; i< n; ++i)
	{
		cin >> k;
		for(j=0; j < k; ++j)
		{
			cin >> t;
			texing[t]++;
		}
	}
	
	int id, max = -1;
	for(i=1000; i >= 0; i--)
	{
		if (max < texing[i])
		{
			id = i;
			max = texing[i];
		}
	}
	
	printf("%d %d", id, max);
	return 0;
}
*/
/*
int main() 
{
	int i,j ;
	int year,n;
	cin >> year >> n ;
	int out;
	
	set<int> v;
	int a[4];
	a[0] = year /1000;
	a[1] = year%1000/100;
	a[2] = year%100/10;
	a[3] = year%10;
	for (int i=0; i <4;++i)
		v.insert(a[i]);
	
	out = 0;
	while(v.size() != n)
	{
		year++;
		out++;
		v.clear();
		a[0] = year /1000;
		a[1] = year%1000/100;
		a[2] = year%100/10;
		a[3] = year%10;
		for (int i=0; i <4;++i)
			v.insert(a[i]);
	}
	
	printf("%d %04d", out, year);
	
	return 0;
}
*/


/*
int main()
{
	string s1, s2, s3, s4;

	cin >> s1 >> s2 >> s3 >> s4;

	int i;
	int index = 0;
	for (i = 0; i < s1.size() && i < s2.size(); ++i)
	{
		if (s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'G'))
		{
			switch (s1[i])
			{
			case 'A': cout << "MON "; break;
			case 'B': cout << "TUE "; break;
			case 'C': cout << "WED "; break;
			case 'D': cout << "THU "; break;
			case 'E': cout << "FRI "; break;
			case 'F': cout << "SAT "; break;
			case 'G': cout << "SUN "; break;
			}
			index = i;
			break;
		}
	}
	for (i = index + 1; i < s1.size() && i < s2.size(); ++i)
	{
		if (s1[i] == s2[i] && (isdigit(s1[i]) || (s1[i] >= 'A' && s1[i] <= 'N')))
		{
			if (isdigit(s1[i]))
			{
				printf("%02d:", s1[i] - '0');
			}
			else
			{
				int d = s1[i] - 'A' + 10;
				printf("%02d:", d);
			}
			break;
		}
	}
	for (i = 0; i < s3.size() && i < s4.size(); ++i)
	{
		if (s3[i] == s4[i] && (isupper(s3[i]) || islower(s3[i])))
		{
			printf("%02d\n", i);
			break;
		}
	}
	return 0;
}
*/


/*
int main()
{
	string a, b;
	int da, db, i,pa,pb;

	cin >> a >> da >> b >> db;

	pa = pb = 0;
	for (i = 0; i < a.size(); ++i)
	{
		if (a[i] == da + '0')
			pa = pa * 10 + da;
	}
	for (i = 0; i < b.size(); ++i)
	{
		if (b[i] == db + '0')
			pb = pb * 10 + db;
	}
	cout << pa + pb << endl;
	return 0;
}
*/

/*
struct people
{
	char number[14];
	int de, cai;
};

bool operator<(const people& p1,const people& p2)
{
	if (p1.de + p1.cai == p2.de + p2.cai)
	{
		if (p1.de == p2.de)
			return strcmp(p1.number,p2.number) < 0;
		else
			return p1.de > p2.de;
	}
	else
		return p1.de + p1.cai > p2.de + p2.cai;
}

int main()
{
	vector<people> v[4];
	int n, l, h, i,j, c;
	cin >> n >> l >> h;

	c = 0;
	people tmp;
	for (i = 0; i < n; ++i)
	{
		scanf("%s %d %d", tmp.number, &tmp.de, &tmp.cai);

		if (tmp.de < l || tmp.cai < l)
			continue;

		c++;
		if (tmp.de >= h && tmp.cai >= h)
			v[0].push_back(tmp);
		else if (tmp.de >= h && tmp.cai < h)
			v[1].push_back(tmp);
		else if (tmp.de < h && tmp.cai < h && tmp.de >= tmp.cai)
			v[2].push_back(tmp);
		else
			v[3].push_back(tmp);
	}

	for (i = 0; i < 4; ++i)
		sort(v[i].begin(), v[i].end());

	cout << c << endl;

	for (i = 0; i < 4; ++i)
		for (j = 0; j < v[i].size(); ++j)
			printf("%s %d %d\n", v[i][j].number, v[i][j].de, v[i][j].cai);

	return 0;
}
*/

/*
bool is_prime(int x)
{
	int end = sqrt(x);
	if (x == 1)
		return false;
	for (int i = 2; i <= end; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int next_prime(int x)
{
	int ret = x+1;
	while (!is_prime(ret))
		ret++;
	return ret;
}


int main()
{
	int start, end, i, now;
	cin >> start >> end;
	int c = 0;
	i = 1;
	now = 2;
	for (; i < start; ++i)
		now = next_prime(now);

	bool first = true;
	for (; i <= end; ++i)
	{
		if (c == 10)
		{
			cout << endl;
			first = true;
			c = 0;
		}
		if (first)
			first = false;
		else
			cout << ' ';
		c++;
		cout << now;
		now = next_prime(now);
	}
}

*/

/*
int main()
{
	int a1,a2,a3,a5;
	double a4;
	bool add = true;

	bool b1, b2, b3, b4, b5;
	b1 = b2 = b3 = b4 = b5 = false;

	a1 = a2 = a3 = a5 = 0;
	a4 = 0;
	int c;
	cin >> c;
	int n;
	int count = 0;
	for(int i=0; i < c; ++i)
	{
		cin >> n;
		switch (n % 5)
		{
		case 0:
			if (n % 2 == 0)
			{
				a1 += n;
				b1 = true;
			}
			break;
		case 1:
			b2 = true;
			if (add)
			{
				a2 += n;
				add = false;
			}
			else
			{
				a2 -= n;
				add = true;
			}
			break;
		case 2:
			b3 = true;
			a3++;
			break;
		case 3:
			b4 = true;
			count++;
			a4 += n;
			break;
		case 4:
			b5 = true;
			if (n > a5)
				a5 = n;
			break;
		}
	}
	if (b1)
		cout << a1;
	else
		cout << 'N';
	cout << ' ';
	if (b2)
		cout << a2;
	else
		cout << 'N';
	cout << ' ';
	if (b3)
		cout << a3;
	else
		cout << 'N';
	cout << ' ';
	if (b4)
	{
		a4 = a4 / count;
		printf("%.1lf", a4);
	}
	else
		cout << 'N';
	cout << ' ';
	if (b5)
		cout << a5;
	else
		cout << 'N';
	return 0;
}
*/

/*
int n,m;
vector<int> heap;

int find(int x)
{
	for(int i=1; i <=n;++i)
		if (heap[i] == x)
			return i;
	return -1;
}

int main()
{
	int i,t;
	cin >> n >> m;
	heap.resize(n+1);
	for(i=1; i <= n; ++i)
		cin >> heap[i];
		
	make_heap(heap.begin()+1, heap.end(), greater<int>());
	
	for(i=1; i <= n; ++i)
	{
		if (i != 1)
			cout << ' ';
		cout << heap[i];
	}
	cout << endl;
	for(i=0; i < m; ++i)
	{
		string line;
		getline(cin, line);
		if (line.size() == 0)
		{
			i--;
			continue;
		}
		if (line.find("root") != string::npos)
		{
			int id;
			sscanf(line.c_str(), "%d is the root", &id);
			if (heap[1] == id)
				printf("T\n");
			else
				printf("F\n");
		}
		else if (line.find("siblings") != string::npos)
		{
			int a,b;
			sscanf(line.c_str(), "%d and %d are siblings", &a, &b);
			
			a = int(log(find(a))/log(2));
			b = int(log(find(b))/log(2));
			if (a == b)
				printf("T\n");
			else
				printf("F\n");
		}
		else if (line.find("parent") != string::npos)
		{
			int a,b;
			sscanf(line.c_str(), "%d is the parent of %d", &a, &b);
			
			a = find(a);
			b = find(b);
			if (b/2 == a)
				printf("T\n");
			else
				printf("F\n");
		}
		else
		{
			int a,b;
			sscanf(line.c_str(), "%d is a child of %d", &a, &b);
			
			a = find(a);
			b = find(b);
			if (a/2 == b)
				printf("T\n");
			else
				printf("F\n");
		}
	}
	
	
	return 0;
}
*/

/*
const int MAX = 100005;
int d[MAX];
set<int> noSingle;

void init()
{
	for(int i=0; i <MAX;++i)
		d[i] = i;
}

int find(int x)
{
	if (x == d[x])
		return x;
	return d[x] = find(d[x]);
}

void merge(int x, int y)
{
	d[find(y)] = d[find(x)];
}

int count(int x)
{
	int ret = 0;
	for(int i=0; i <MAX;++i)
	{
		if (i != x && find(i) == x)
		{
			ret++;
			return ret;
		}
	}
	return ret;
}

bool single(int x)
{
	if (find(x) != x)
		return false;
	if (noSingle.find(x) != noSingle.end())
		return false;
	
	return true;
}

int main()
{
	int n,k,m,i,j;
	cin >> n;
	vector<int> out;
	init();
	for(i=0;i<n;++i)
	{
		int head, tmp;
		scanf("%d %d", &k, &head);
		if (k > 1)
			noSingle.insert(head);
		for(j=1; j < k;++j)
		{
			scanf("%d", &tmp);
			merge(tmp,head);
			noSingle.insert(tmp);
		}
	}
	cin >> m;
	for(i=0; i < m; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (single(tmp))
		{
			if (find(out.begin(), out.end(), tmp) == out.end())
				out.push_back(tmp);
		}
			
	}
	if (!out.empty())
	{
		for(i=0; i < out.size(); ++i)
		{
			if (i != 0)
				cout << ' ';
			printf("%05d", out[i]);
		}
	}
	else
		cout << "No one is handsome";
	cout << endl;
	return 0;
}
*/

/*
int n,m,k;
vector<int> e[10005];
int visited[10005];


struct node
{
	int id;
	int deep;
	node() {}
	node(int i, int d) : id(i), deep(d) {}
};

int bfs(int s)
{
	node ans(0,0);
	
	queue<node> q;
	q.push(node(s,0));
	visited[s] = 1;
	
	while(!q.empty())
	{
		node now = q.front();
		q.pop();
		if (now.deep == ans.deep)
			ans.id = min(ans.id, now.id);
		if (ans.deep < now.deep)
			ans.id = now.id, ans.deep = now.deep;
		
		for(int i=0; i < e[now.id].size(); ++i)
		{
			int v = e[now.id][i];
			if(visited[v])
				continue;
			visited[v] = 1;
			q.push(node(v,now.deep+1));
		}
	}
	
	return ans.id;
}

int main()
{
	int i;
	cin >> n >> m >> k;
	
	for(i = 0; i <m; ++i)
	{
		int a,b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(i = 0; i < k; ++i)
	{
		int a;
		cin >> a;
		memset(visited, 0, sizeof(visited));
		cout << bfs(a) << endl;
	}
	
	return 0;
}
*/


/*
vector<int> pre,mid;
int current;

struct Tree
{
	int value;
	Tree *left, *right;
	Tree(int v) : value(v), left(NULL), right(NULL) {}
};

int find(int value)
{
	for(int i=0; i <mid.size(); ++i)
	{
		if (mid[i] == value)
			return i;
	}
	return -1;
}

Tree* buildTree(int value, int l, int r)
{
	Tree* ret = new Tree(value);
	current++;
	if (l >= r || current > mid.size())
		return ret;
	
	int m = find(value);
	
	if (current < mid.size() && l != m)
		ret->left = buildTree(pre[current], l, m-1);
	if (current < mid.size() && r != m)
		ret->right = buildTree(pre[current], m+1, r);
	
	return ret; 
}

void translate(Tree *p)
{
	if (p == NULL)
		return;
	translate(p->left);
	translate(p->right);
	Tree *tmp = p->left;
	p->left = p->right;
	p->right = tmp;
}

void visit(Tree *p)
{
	queue<Tree*> q;
	q.push(p);
	
	bool first = true;
	
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		if (first)
			first = false;
		else
			cout << ' ';
		cout << p->value;
		if (p->left != NULL)
			q.push(p->left);
		if (p->right != NULL)
			q.push(p->right);
	}
}

int main()
{
	int n,i;
	cin >> n;
	pre.resize(n);
	mid.resize(n);
	
	for(i=0; i < n;++i)
		cin >> mid[i];
	for(i=0;i < n; ++i)
		cin >> pre[i];
	
	current = 0;
	Tree *root = buildTree(pre[current],0, pre.size()-1);
	translate(root);
	visit(root);
	
	return 0;
}
*/

/*
const int MAX = 105;

int didui[MAX][MAX] = {0};

int d[MAX];
void init()
{
	for(int i=0; i <MAX;++i)
		d[i] = i;
}

int find(int x)
{
	if (x == d[x])
		return x;
	return d[x] = find(d[x]);
}

void merge(int x, int y)
{
	d[find(y)] = d[find(x)];
}

int n,m,k;

int main()
{
	int i;
	cin >> n >> m >> k;
	
	init();
	for(i=0; i < m; ++i)
	{
		int a,b,c;
		cin >> a >> b >> c;
		if (c == 1)
			merge(a,b);
		else
			didui[a][b] = didui[b][a] = 1;
	}
	for(i=0; i < k; ++i)
	{
		int a,b;
		cin >> a >> b;
		if (find(a) == find(b))
		{
			if (didui[a][b] == 0)
			{
				cout << "No problem" << endl;
			}
			else
			{
				cout << "OK but..." << endl;
			}
		}
		else
		{
			if (didui[a][b] == 0)
			{
				cout << "OK" << endl;
			}
			else
			{
				cout << "No way" << endl;
			}
		}
	}
	return 0;
}
*/

/*
struct peo
{
	int id;
	double total;
	peo() {}
	peo(int i, double t) : id(i), total(t) {}
};

int countt[10005] = {0};

bool operator<(peo p1, peo p2)
{
	if (fabs(p1.total-p2.total) < 1e-6)
	{
		if (countt[p1.id] == countt[p2.id])
		{
			return p1.id < p2.id;
		}
		else
			return countt[p1.id] > countt[p2.id];
	}
	else
		return p1.total > p2.total;
}

int main()
{
	int receive[10005] = {0};
	int send[10005] = {0};
	
	vector<peo> v;
	
	int n,i;
	cin >> n;
	for(i=1; i <= n; ++i)
	{
		int m;
		cin >> m;
		for(int j=1; j <= m; ++j)
		{
			int a,b;
			cin >> a >> b;
			countt[a]++;
			receive[a] += b;
			send[i] += b;
		}
	}
	v.resize(n);
	for(i=1; i <=n; ++i)
	{
		v[i-1].id = i;
		v[i-1].total = (1.0*receive[i] - send[i])/100;
	}
	sort(v.begin(),v.end());
	
	for(i=0; i < n; ++i)
	{
		printf("%d %.2lf\n", v[i].id, v[i].total);
	}
	return 0;
}
*/



/*
int main()
{
	int in;
	cin >> in;
	in = (in+2-1)%7 + 1;
	printf("%d",in);
	return 0;
}
*/
/*
int main()
{
	int g,p,l,t,i;
	g=p=l=t = 0;
	string in;
	cin >> in;
	
	for(i=0; i < in.size(); ++i)
	{
		if (in[i] == 'g' || in[i] == 'G')
			g++;
		else if (in[i] == 'p' || in[i] == 'P')
			p++;
		else if (in[i] == 'l' || in[i] == 'L')
			l++;
		else if (in[i] == 't' || in[i] == 'T')
			t++;
	}

	while (g || p || l || t)
	{
		if (g > 0)
		{
			putchar('G');
			g--;
		}
		if (p > 0)
		{
			putchar('P');
			p--;
		}
		if (l > 0)
		{
			putchar('L');
			l--;
		}
		if (t > 0)
		{
			putchar('T');
			t--;
		}
	}
	return 0;
}
*/

/*
int main()
{
	int n,a,b;
	a = b = 0;
	cin >> n;
	while(n--)
	{
		int t;
		cin >> t;
		if (t % 2 == 1)
			a++;
		else
			b++; 
	}
	printf("%d %d", a,b);
}
*/

/*
int main()
{
	for(int i=0; i <3;++i)
		printf("I'm gonna WIN!\n");
	return 0;
}
*/
/*
int main()
{
	int aMax,bMax;
	int aHe,bHe;
	int aHan,bHan;
	int aHua,bHua;
	
	int i,n;
	cin >> aMax >> bMax;
	cin >> n;
	
	bool agg,bgg;
	agg = bgg = false;
	aHe = bHe = 0;
	for(i=0; i < n;++i)
	{
		cin >> aHan >> aHua >> bHan >> bHua;
		int Han = aHan + bHan;
		
		if (aHua == Han && bHua == Han)
			continue;
		
		if (aHua == Han)
		{
			aHe++;
			if (aHe > aMax)
			{
				agg = true;
				break;
			}
		}
		else if (bHua == Han)
		{
			bHe++;
			if (bHe > bMax)
			{
				bgg = true;
				break;
			}
		}
	}
	if (agg)
		cout << "A" << endl << bHe;
	else
		cout << "B" << endl << aHe;
	return 0;
}
*/

/*
int main()
{
	int hour,m;
	scanf("%d:%d", &hour, &m);
	if (hour >= 0 && hour <= 12)
		printf("Only %02d:%02d.  Too early to Dang.", hour,m);
	else
	{
		int n = hour - 12;
		for(int i=0; i < n; ++i)
			printf("Dang");
		if (m > 0)
			printf("Dang");
	}
	
	return 0;
}
*/

/*
int main()
{
	bool fu;
	int count;
	string in;
	cin >> in;
	fu = false;
	if (in[0] == '-')
	{
		fu = true;
		in.erase(in.begin());
	}
	count = 0;
	for(int i=0; i < in.size(); ++i)
	{
		if (in[i] == '2')
			count++;
	}
	double ret;
	ret = 1.0*count/in.size();
	if (fu)
		ret *= 1.5;
	if ((in[in.size()-1]-'0')%2 == 0)
		ret *= 2;
	printf("%.2lf%%", ret*100);
	
	return 0;
}
*/


/*
int main()
{
	long long a, b, c;
	int n, i;
	cin >> n;
	for (i = 0; i < n; ++i)
	{
		cin >> a >> b >> c;
		printf("Case #%d: ", i+1);
		if (a + b > c)
			printf("true\n");
		else
			printf("false\n");
	}
	return 0;
}
*/

/*
int main()
{
	int n, e, flag = 0;
	while (cin >> n >> e)
	{
		if (n*e)
		{
			if (flag)
				cout << ' ';
			else
				flag = 1;
			cout << n*e << ' ' << e - 1;
		}
	}
	if (!flag)
		cout << "0 0";

	return 0;
}
*/

/*
int main()
{
	vector<string> v;
	string tmp;
	while (cin >> tmp)
		v.push_back(tmp);

	for (int i = v.size() - 1; i >= 0; --i)
	{
		if (i != v.size() - 1)
			cout << ' ';
		cout << v[i];
	}
	return 0;
}
*/

/*
int main()
{
	int table[200] = { 0 };
	int n, m, i, head, tail;
	cin >> n >> m;
	tail = 0;
	head = n-1;
	for (i = 0; i < n; ++i)
		cin >> table[i];
	
	head = (head - m) % n;
	tail = (tail - m) % n;
	if (head < 0)
		head += n;
	if (tail < 0)
		tail += n;

	cout << table[tail];
	for (; tail != head && n != 1; )
	{
		++tail;
		tail %= n;
		cout << ' ' << table[tail];
	}
	return 0;
}
*/

/*
bool is_prime(int x)
{
	int end = sqrt(x), i;
	if (x == 1)
		return false;
	for (i = 2; i <= end; ++i)
		if (x % i == 0)
			return false;
	return true;
}

int next_prime(int x)
{
	do
	{
		++x;
	} while (!is_prime(x));
	return x;
}


int main()
{
	int n;
	cin >> n;
	
	int now = 3, c = 0;
	while (now <= n)
	{
		int next = next_prime(now);
		if (next > n)
			break;
		int d = next - now;
		if (d == 2)
			c++;
		now = next;
	}
	cout << c;
	return 0;
}
*/

/*
int main()
{
	int in, a, b, c, i;
	cin >> in;

	a = in / 100;
	b = (in % 100) / 10;
	c = in % 10;
	
	if (a > 0)
		cout << string(a, 'B');
	if (b > 0)
		cout << string(b, 'S');

	for (i = 1; i <= c; ++i)
		cout << i;
	return 0;
}
*/

/*
int main()
{
	int d[10000] = { 0 };
	int n, in;
	cin >> n;

	set<int, greater<int> > out;
	
	for (int i = 0; i < n; ++i)
	{
		cin >> in;
		int before;
		bool start = true;
		while (in != 1)
		{
			if (d[in] == 0)
			{
				if (start)
				{
					out.insert(in);
					start = false;
				}
				before = in;
				if (in % 2 == 0)
					in /= 2;
				else
					in = (in * 3 + 1) / 2;
				d[before] = in;
			}
			else
			{
				if (!start)
					out.erase(in);
				break;
			}
		}
	}

	set<int>::iterator it = out.begin();
	bool first = true;
	while (it != out.end())
	{
		if (!first)
			cout << ' ';
		else
			first = false;
		cout << *it;
		it++;
	}
	return 0;
}
*/



/*
struct stu
{
	string name, number;
	int chengji;
};


bool operator<(stu s1, stu s2)
{
	return s1.chengji > s2.chengji;
}


int main()
{
	int i, n;
	cin >> n;
	vector<stu> v;
	v.resize(n);

	for (i = 0; i < n; ++i)
		cin >> v[i].name >> v[i].number >> v[i].chengji;

	sort(v.begin(), v.end());

	cout << v[0].name << ' ' << v[0].number << endl;
	int end = v.size() - 1;
	cout << v[end].name << ' ' << v[end].number << endl;
	return 0;
}
*/

/*
int main()
{
	int in, n;
	cin >> in;
	n = 0;
	while (in != 1)
	{
		n++;
		if (in % 2 == 0)
			in /= 2;
		else
			in = (in * 3 + 1) / 2;
	}
	cout << n;
	return 0;
}
*/

/*

int main()
{
	int sum, i;
	string pin[10] = {
		"ling", "yi", "er", "san", "si", "wu",
		"liu", "qi", "ba", "jiu",
	};
	stack<string> out;
	string in;
	cin >> in;

	sum = 0;
	for (i = 0; i < in.size(); ++i)
		sum += (in[i] - '0');

	while (sum)
	{
		int d = sum % 10;
		out.push(pin[d]);
		sum /= 10;
	}

	while (!out.empty())
	{
		cout << out.top();
		out.pop();
		if (!out.empty())
			cout << ' ';
	}
	return 0;
}
*/

/*
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
*/

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

// 奖牌榜

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
// dfs 练习
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