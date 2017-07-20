
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
#include <stdio.h>
#include <sstream>
using namespace std;

/*
int mp[105][105];
int visit[105];
int n, m;
const int INF = 0x3fffffff;
int prim()
{
	int ret = 0;
	int d[105];
	fill(d, d + 105, INF);
	memset(visit, 0, sizeof(visit));
	d[1] = 0;

	for (int i = 0; i < m; ++i)
	{
		int min = INF, id = -1;
		for (int j = 1; j <= m; ++j)
		{
			if (!visit[j] && d[j] < min)
			{
				id = j;
				min = d[j];
			}
		}

		if (id == -1)
			break;
		ret += min;
		visit[id] = 1;
		for (int j = 1; j <= m; ++j)
		{
			if (!visit[j] && mp[id][j] < d[j] && mp[id][j] != INF)
			{
				d[j] = mp[id][j];
			}
		}
	}
	return ret;
}

int main()
{
	while (~scanf("%d %d", &n, &m) && n)
	{
		fill(mp[0], mp[0] + 105 * 105, INF);
		for (int i = 0; i < n; ++i)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			mp[a][b] = mp[b][a] = c;
		}
		if (n < m - 1)
		{
			printf("?\n");
			continue;
		}
		int ans = prim();
		int all = 0;
		for (int i = 1; i <= m; ++i)
			if (visit[i])
				all++;
		if (all == m)
			printf("%d\n", ans);
		else
			printf("?\n");
	}
	return 0;
}
*/

/*
class Token
{
public:
	Token(char kid, double val = 0)
		: kind(kid), value(val) {}
	char kind;
	double value;
};

Token next_Token(stringstream &cin)
{
	double val;
	char c;
	cin >> c;
	if (!cin)
		return Token('e');
	switch (c)
	{
	case '+': case '-':
		return Token(c, 1);
	case '*': case '/':
		return Token(c, 2);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		cin.putback(c);
		cin >> val;
		return Token('n', val);
	}
}

Token compute(Token t1, Token t2, Token op)
{
	switch (op.kind)
	{
	case '+':
		return Token('n', t1.value + t2.value);
	case '-':
		return Token('n', t1.value - t2.value);
	case '*':
		return Token('n', t1.value * t2.value);
	case '/':
		return Token('n', t1.value / t2.value);
	}
}

int main()
{
	string str;

	while (getline(cin, str) && str != "0")
	{
		stack<Token> nums;
		stack<Token> ops;

		stringstream strstream;
		strstream << str;

		Token tok('e');
		while ((tok = next_Token(strstream)).kind != 'e')
		{
			if (tok.kind == 'n')
			{
				nums.push(tok);
			}
			else
			{
				while (ops.size() && ops.top().value >= tok.value)
				{
					Token t2 = nums.top();
					nums.pop();
					Token t1 = nums.top();
					nums.pop();
					nums.push(compute(t1, t2, ops.top()));
					ops.pop();
				}
				ops.push(tok);
			}
		}

		while (ops.size())
		{
			Token t2 = nums.top();
			nums.pop();
			Token t1 = nums.top();
			nums.pop();
			Token op = ops.top();
			ops.pop();
			nums.push(compute(t1, t2, op));
		}
		printf("%.2lf\n", nums.top().value);

	}
	return 0;
}
*/


/*
int t[101][101];

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;
		memset(t, 0, sizeof(t));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j)
				cin >> t[i][j];
		for (int i = n - 1; i >= 0; --i)
			for (int j = 0; j <= i; ++j)
				t[i][j] += max(t[i + 1][j], t[i + 1][j + 1]);
		cout << t[0][0] << endl;
	}

	return 0;
}
*/

/*
int dp[100005][13];

int main()
{
	int n;
	while (~scanf("%d", &n) && n)
	{
		int x, t, mt = 0;
		memset(dp, 0, sizeof(0));
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &x, &t);
			dp[t][x+1]++;
			mt = max(mt, t);
		}
		for (t = mt - 1; t >= 0; --t)
			for (x = 1; x < 12; ++x)
				dp[t][x] += max(dp[t + 1][x - 1], max(dp[t + 1][x], dp[t + 1][x + 1]));

		printf("%d\n", dp[0][6]);
	}
	return 0;
}
*/

/*
int dp[1005][2005];
int maxs = 0x3fffffff;
int main()
{
	int n, k;
	int s[2005];
	while (cin >> n >> k)
	{
		int i, j, m, t, a, b, c;
		memset(dp, 0, sizeof(dp));
		memset(s, 0, sizeof(s));
		for (i = 1; i <= n; i++)
			cin >> s[i];
		sort(s + 1, s + n + 1);
		for (i = 1; i <= k; i++)
			for (j = 0; j <= n; j++)
				dp[i][j] = maxs;
		for (i = 1; i <= k; i++)
			for (j = 2 * i; j <= n; j++)
			{
				dp[i][j] = min(dp[i][j - 1],
					dp[i - 1][j - 2] + (s[j] - s[j - 1])*(s[j] - s[j - 1]));
			}

		cout << dp[k][n] << endl;
	}

	return 0;
}
*/

/*
int dp[2005][1005];
int maxs = 2147483646;
int main()
{
	int n, k;
	int s[2005];
	while (cin >> n >> k)
	{
		int i, j, m, t, a, b, c;
		memset(dp, 0, sizeof(dp));
		memset(s, 0, sizeof(s));
		for (i = 1; i <= n; i++)
			cin >> s[i];
		sort(s + 1, s + n + 1);

		for (int i = n - 1; i >= 1; --i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				dp[i][j] = (s[j] - s[i])*(s[j] - s[i]);
				for (int q = i; q < j; ++q)
					dp[i][j] = min(dp[i][j], dp[i][q] + dp[q + 1][j]);
			}
		}

		cout << dp[1][n] << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int c[26];
	char buf[100005];
	while (gets_s(buf,100005))
	{
		memset(c, 0, sizeof(c));
		int len = strlen(buf);
		for (int i = 0; i < len; ++i)
		{
			if (islower(buf[i]))
				c[buf[i] - 'a']++;
		}
		for (int i = 0; i < 26; ++i)
			cout << char('a' + i) << ':' << c[i] << endl;
		cout << endl;
	}

	return 0;
}
*/

/*
int a[1005];
int dp[1005];

int main()
{
	int n,m;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		cin >> m;
		sort(a, a + n);
		if (m < 5)
		{
			cout << m << endl;
			continue;
		}
		else
		{
			m -= 5;
			memset(dp, 0, sizeof(dp));
			for (int i = 0; i < n - 1; ++i)
			{
				for (int j = m; j >= a[i]; j--)
				{
					dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
				}
			}
			cout << m - dp[m] - a[n - 1] + 5 << endl;
		}
	}

	return 0;
}
*/

/*
int t[100005];
int dp[100005];
int head[100005];

int main()
{
	int T,c = 1;
	cin >> T;
	bool first = true;
	while (T--)
	{
		if (first)
			first = false;
		else
			putchar('\n');
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> t[i];
		dp[0] = t[0];
		head[0] = 0;

		for (int i = 1; i < n; ++i)
		{
			if (dp[i - 1] >= 0)
			{
				dp[i] = dp[i - 1] + t[i];
				head[i] = head[i - 1];
			}
			else
			{
				dp[i] = t[i];
				head[i] = i;
			}
		}
		int *ret = max_element(dp, dp + n);
		printf("Case %d:\n%d %d %d\n", c++, *ret, head[ret - dp]+1, ret - dp+1);
	}

	return 0;
}
*/


/*
struct number
{
	int c[1000];
	int len;

	void output()
	{
		for (int i = len - 1; i >= 0; --i)
			putchar('0' + c[i]);
	}

	number operator+(number &num)
	{
		number ret = *this;
		for (int i = 0; i < num.len; ++i)
			ret.c[i] += num.c[i];
		ret.jinwei();
		return ret;
	}

	number operator*(int n)
	{
		number ret = *this;
		for (int i = 0; i < len; ++i)
			ret.c[i] *= n;
		ret.jinwei();
		return ret;
	}

	void jinwei()
	{
		for (int i = 0; i < len - 1; ++i)
		{
			if (c[i] >= 10)
			{
				c[i] -= 10;
				c[i + 1] += 1;
			}
		}
		if (c[len - 1] >= 10)
		{
			c[len - 1] -= 10;
			c[len] = 1;
			len++;
		}
	}
};

number t[1005];

int main()
{
	t[0] = { {0},1 };
	t[1] = t[0];
	t[2] = { {1},1 };
	t[3] = t[2];
	for (int i = 4; i <= 1000; ++i)
		t[i] = (t[i - 2] * 2) + t[i - 1] ;
	int n;
	while (cin >> n)
	{
		t[n].output();
		cout << endl;
	}
	return 0;
}
*/


/*
int main()
{
	int n;
	while (cin >> n && n)
	{
		map<string, int> mp1;
		map<int, string, greater<int> > mp2;

		for (int i = 0; i < n; ++i)
		{
			string str;
			cin >> str;
			mp1[str]++;
		}
		for (auto it : mp1)
		{
			mp2[it.second] = it.first;
		}
		cout << mp2.begin()->second << endl;
	}
	return 0;
}
*/

/*
int main()
{
	set<int> s;
	s.insert(1);
	s.insert(10);
	s.insert(11);
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); )
	{
		if (*it == 10)
			it = s.erase(it);
		else
			++it;
	}
	for (it = s.begin(); it != s.end(); ++it)
		cout << *it << endl;
	return 0;
}
*/


/*
int main()
{
	int n, in;
	cin >> n;
	while (n-- && cin >> in)
	{
		double t = in*log10(static_cast<double>(in));
		double r = t - floor(t);
		printf("%d\n", static_cast<int>(pow(10.0, r)));
	}
	return 0;
}
*/

/*
int main()
{
	int n;
	while (cin >> n && n)
	{
		vector<int> v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		int cur = 0, time = 0;
		for (int i = 0; i < n; ++i)
		{
			int next = v[i];
			if (next > cur)
				time += 6 * (next - cur);
			else
				time += 4 * (cur - next);
			cur = next;
			time += 5;
		}
		printf("%d\n", time);
	}
	return 0;
}
*/

/*
int tab[1000] = { 0,1,1 };
int main()
{
	int A, B, n;
	while (cin >> A >> B >> n && (A != 0 && B!= 0 && n!=0))
	{
		int s = 0, j;
		for (int i = 3; i <= n; ++i)
		{
			tab[i] = (A*tab[i - 1] + B*tab[i - 2]) % 7;

			for (j = 2; j < i; ++j)
			{
				if (tab[i] == tab[j] && tab[i - 1] == tab[j - 1])
				{
					s = i - j;
					break;
				}
			}
			if (s > 0)
				break;
		}
		if (s > 0)
			printf("%d\n", tab[j + (n-j)%s]);
		else
			printf("%d\n", tab[n]);
	}

	return 0;
}
*/


/*
void dfs(long long n)
{
	if (n)
	{
		int t = n % -2;
		if (t < 0)
		{
			t += 2;
			dfs(n / -2 + 1);
		}
		else
			dfs(n / -2);
		printf("%d", t);
	}
}

int main()
{
	long long n;
	while (cin >> n)
	{
		if (!n)
		{
			printf("0\n");
			continue;
		}
		dfs(n);
		putchar('\n');
	}
	return 0;
}
*/


/*
int main()
{
	int N;
	string str;
	while (cin >> N >> str)
	{
		map<char, int> mp;
		for (int i = 0; i < str.size(); ++i)
			mp[str[i]]++;

		int ji = 0;
		for (const auto it : mp)
		{
			if (it.second % 2)
				ji++;
		}
		if (ji > 1)
		{
			printf("");
			break;
		}

	}


	return 0;
}
*/


/*
int r = 0, v[15][15] = { 0 }, mi = 0x3fffffff, s[15][15];
int f[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int m, n;
void dfs(int x, int y, int sum, int num)
{
	int i, j;
	if (sum == r)
	{
		if (num<mi)
			mi = num;
		return;
	}
	if (sum>r || num>mi || x<1 || y<1 || x > m || y > n)
		return;
	v[x][y] = 1;
	for (i = 0; i<4; i++)
	{
		if (!v[x+f[i][0]][y+f[i][1]] )
			dfs(x + f[i][0], y + f[i][1], sum + s[x][y], num + 1);
	}
	v[x][y] = 0;
}
int main()
{
	int i, j, k;
	cin >> n >> m;
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			cin >> s[i][j];
			r += s[i][j];
		}
	r /= 2;
	dfs(1, 1, 0, 0);
	cout << mi;
}
*/

/*
string a, b;
bool huiwen(int x)
{
	char buffer[10];
	sprintf(buffer, "%d", x);
	a = buffer;
	b = string(a.rbegin(), a.rend());
	if (a == b)
		return true;
	return false;
}

int sum(int x)
{
	int ret = 0;
	while (x)
	{
		ret += x % 10;
		x /= 10;
	}
	return ret;
}


int main()
{
	int in;
	while (cin >> in)
	{
		int cont = 0;
		for (int i = 10000; i <= 999999; ++i)
		{
			if (sum(i) == in && huiwen(i))
			{
				printf("%d\n", i);
				cont++;
			}
		}
		if (!cont)
			printf("%d\n", -1);
	}
	return 0;
}
*/


/*
int mp[1005][1005];
int n, m;
int visit[1005];

bool isLink(int a, int b, int ig = -1)
{
	int i, j;
	visit[a] = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (i == ig || i == a)
			continue;
		if (mp[a][i] && !visit[i])
		{
			if (i == b)
			{
				visit[a] = 0;
				return true;
			}
			visit[i] = 1;
			if (isLink(i, b, ig))
			{
				visit[a] = 0;
				visit[i] = 0;
				return true;
			}
			visit[i] = 0;
		}
	}
	visit[a] = 0;
	return false;
}

int main()
{
	int i, j;
	int start, end;
	while (cin >> n >> m)
	{
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			cin >> a >> b;
			mp[a][b] = 1;
			mp[b][a] = 1;
		}
		cin >> start >> end;

		if (!isLink(start, end))
		{
			cout << -1 << endl;
			continue;
		}
		int ret = 0;
		for (int i = 1; i <= n; ++i)
			if (i != start && i != end && !isLink(start, end, i))
			{
				ret++;
				//printf("Error %d\n", i);
			}
		cout << ret << endl;
	}

	return 0;
}
*/

/*
int tab[205][205];
int main()
{
	int m, n;

	while (cin >> m >> n)
	{
		memset(tab, 0, sizeof(tab));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				cin >> tab[i][j];

		int i = -1, j = 0;
		int sum = n*m;
		while(sum)
		{
			while (tab[++i][j] != -1 && i < m)
			{
				cout << tab[i][j];
				if (sum != 1)
					cout << ' ';
				tab[i][j] = -1;
				sum--;
			}
			i--;
			while (tab[i][++j] != -1 && j < n)
			{
				cout << tab[i][j];
				if (sum != 1)
					cout << ' ';
				tab[i][j] = -1;
				sum--;
			}
			j--;
			while (tab[--i][j] != -1 && i >= 0)
			{
				cout << tab[i][j];
				if (sum != 1)
					cout << ' ';
				tab[i][j] = -1;
				sum--;
			}
			i++;
			while (tab[i][--j] != -1 && j >= 0)
			{
				cout << tab[i][j];
				if (sum != 1)
					cout << ' ';
				tab[i][j] = -1;
				sum--;
			}
			j++;
		}
	}
	return 0;
}
*/


/*
long long tab[30] = {0, 1};

long long getN(int x)
{
	if (tab[x] != 0)
		return tab[x];

	long long a = 1;
	for (int i = 2; i <= x; ++i)
		a *= i;
	return tab[x] = a;
}

int main()
{
	int in;
	while (cin >> in)
	{
		long long sum = 0;
		for (int i = 1; i <= in; ++i)
			sum += getN(i);
		printf("%lld", sum);
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
	for (int i = 1; i < 40; ++i)
	{
		if (gcd(i, 40) == 1)
			printf("%d/40,", i);
	}
	return 0;
}
*/

/*
int getSum(int a)
{
	int sum = 1;
	for (int i = 2; i <= a / 2; ++i)
	{
		if (a % i == 0)
			sum += i;
	}
	return sum;
}

int main()
{
	for (int i = 2; i <= 3000; ++i)
	{
		int sum = getSum(i);
		if (sum > i && i == getSum(sum))
			printf("(%d,%d)", i, sum);
	}
	return 0;
}
*/

/*
int main()
{
	for (int i = 1; ; ++i)
	{
		int q = ((8 * i + 7) * 8 + 1) * 8 + 1;
		int w = (2 * i * 17 + 15) * 17 + 4;
		if (q == w)
		{
			printf("%d",q);
			break;
		}
	}
	return 0;
}
*/

/*
int main()
{

	for(int i=100; i<=999; ++i)
	{
		int a = i;
		int b, c, d;
		b = a % 10; a /= 10;
		c = a % 10; a /= 10;
		d = a % 10; a /= 10;
		if (i == b*b*b + c*c*c + d*d*d)
			printf("%d\n", i);
	}
	return 0;
}
*/

/*
int tab[205][205];
int main()
{
	int m, n;

	while (cin >> m >> n)
	{
		memset(tab, 0, sizeof(tab));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				cin >> tab[i][j];
		int x, y, dir;
		x = y = 0;
		// 1 up, 2 right, 3 down, 4 left
		int t, l, r, b;
		l = t = -1;
		r = n;
		b = m;
		dir = 3;
		for (int i = 0; i < n*m; ++i)
		{
			if (i != 0)
				cout << " ";
			cout << tab[y][x];

			if (y == b - 1 && dir == 3)
			{
				dir = 2;
				x += 1;
				l += 1;
			}
			else if (x == r - 1 && dir == 2)
			{
				dir = 1;
				y -= 1;
				b -= 1;
			}
			else if (y == t + 1 && dir == 1)
			{
				dir = 4;
				x -= 1;
				r -= 1;
			}
			else if (x == l + 1 && dir == 4)
			{
				dir = 3;
				y += 1;
				t -= 1;
			}
			else
			{
				switch (dir)
				{
				case 1:
					y -= 1; break;
				case 2:
					x += 1; break;
				case 3:
					y += 1; break;
				case 4:
					x -= 1; break;
				}
			}
		}
	}
	return 0;
}
*/


/*
char Switch(char c)
{
	if (c == '*') return 'o';
	if (c == 'o') return '*';
	return 0;
}

int main()
{
	char in1[1024], in2[1024];
	while (cin >> in1 >> in2)
	{
		int ret = 0;
		int len = strlen(in1);
		for (int i = 0; i < len - 1; ++i)
		{
			if (in1[i] != in2[i])
			{
				in1[i] = Switch(in1[i]);
				in1[i + 1] = Switch(in1[i+1]);
				ret++;
			}
		}
		cout << ret << endl;
	}
	return 0;
}
*/

/*
int n;
int tab1[105], tab2[105];

bool equal()
{
	for (int i = 0; i < n - 1; ++i)
		if (tab1[i] != tab1[i + 1])
			return false;
	return true;
}


int main()
{
	while (cin >> n)
	{
		int ret = 0;
		memset(tab1, 0, sizeof(tab1));
		memset(tab2, 0, sizeof(tab2));

		for (int i = 0; i < n; ++i)
			cin >> tab1[i];

		while (!equal())
		{
			for (int i = 0; i < n; ++i)
			{
				tab1[i] /= 2;
				tab2[i] = tab1[i];
			}
			for (int i = 0; i < n - 1; ++i)
				tab1[i] += tab2[i + 1];
			tab1[n - 1] += tab2[0];

			for (int i = 0; i < n; ++i)
			{
				if (tab1[i] % 2)
				{
					tab1[i]++;
					ret++;
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}
*/


/*
int main()
{
	long long current;
	char buff1[100], buff2[100];

	cout << 0;
	for (current = 1; current <= 200000; ++current)
	{
		long long dou = current * current;
		sprintf(buff1, "%lld", current);
		sprintf(buff2, "%lld", dou);
		int len1 = strlen(buff1), len2 = strlen(buff2);
		if (strcmp(buff1, buff2 + len2 - len1) == 0)
			cout << "  " << current;
	}
	return 0;
}
*/

/*
int main()
{
	vector<string> v;
	string in;
	while (cin >> in)
		v.push_back(in);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;
	return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>
void fun(char*a, char*b, char*c)
{
	int i, j;
	char ch;
	i = 0; j = strlen(a) - 1;
	while (i<j)
	{
		ch = a[i]; a[i] = a[j]; a[j] = ch;
		i++; j--;
	}
	while (*a || *b)
	{
		if (*a)
		{
			*c = *a; c++; a++;
		}
		if (*b)
		{
			*c = *b; c++; b++;
		}
	}
	*c = '\0';
}
int main()
{
	char s1[100], s2[100], t[200];
	printf("\nEnter s1 string:");
	scanf("%s", s1);
	printf("\nEnter s2 string:");
	scanf("%s", s2);
	fun(s1, s2, t);
	printf("\nThe result is:%s\n", t);
	return 0;
}
*/


/*
char str[105];

int getline(FILE *fp)
{
	fgets(str, 100, fp);
	return strlen(str);
}

int main(int argc, char *argv[])
{
	// 我能怎么办。我也很绝望

	if (argc <= 1)
	{
		printf("Please input a valid file path.\n");
		return 0;
	}

	FILE *fp = fopen(argv[1], "r");
	if (!fp)
	{
		printf("Error: can't open file %s", argv[1]);
		return 0;
	}

	int len = getline(fp);
	printf("%s \n%d\n", str, fp);

	return 0;
}
*/

/*
int n, t;
double d[1005], s[1005];
double a, b;

bool C(double c)
{
	double nowt = 0;
	for (int i = 0; i < n; ++i)
		nowt += d[i] / (c + s[i]);
	if (nowt > t)
		return true;
	else
		return false;
}

void solve()
{

	for (int i = 0; i < 100; ++i)
	{
		double mid = (a + b) / 2;
		if (C(mid))
			a = mid;
		else
			b = mid;
	}
	printf("%.12lf\n", (a+b)/2);
}

int main()
{
	while (~scanf("%d %d", &n, &t))
	{
		a = -1e3, b = 1e9;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf %lf", &d[i], &s[i]);
			a = max(a, double(-s[i]));
		}
		solve();
	}

	return 0;
}
*/

/*
string str[60];
int n, m;
int solve()
{
	int ret = n*m;
	if ( m != 1)
		for (int i = 0; i < n; ++i)
		{
			string tmp(str[i].rbegin(), str[i].rend());
			if (tmp == str[i])
				ret++;
		}

	if (n != 1)
		for (int i = 0; i < m; ++i)
		{
			string s;
			for (int j = 0; j < n; ++j)
				s.push_back(str[j][i]);
			string tmp(s.rbegin(), s.rend());
			if (s == tmp)
				ret++;
		}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> str[i];
		printf("%d\n", solve());
	}
	return 0;
}
*/

/*
int main()
{
	char current = 'a';
	int n;
	string in;
	cin >> n >> in;
	n = 0;
	for (int i = 0; i < in.size(); ++i)
	{
		int l = abs(current - in[i]);
		if (l > 13)
			l = 26 - l;
		n += l;
		current = in[i];
	}
	printf("%d", n);
	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	if (n <= 2)
		printf("2");
	else
		printf("%d", n);
	return 0;
}
*/

/*
int n, k;

int solve()
{
	int ret = k;
	while (n--)
		ret = 4 * ret + 2;
	return ret;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		printf("%d\n", solve());
	}
	return 0;
}
*/

/*
void push(list<char>& q, string & s)
{
	q.clear();
	for (int i = 0; i < s.size(); ++i)
		q.push_back(s[i]);
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string a, b;
		cin >> a >> b;
		list<char> qa, qb;
		push(qa, a), push(qb, b);

		int right=0, left=0;
		//  -->
		while (qa != qb)
		{
			right++;
			char c = qa.front();
			qa.pop_front();
			qa.push_back(c);
		}
		push(qa, a);
		while (qa != qb)
		{
			left++;
			char c = qa.back();
			qa.pop_back();
			qa.push_front(c);
		}
		printf("%d\n", min(left, right));

	}
	return 0;
}
*/

/*
long long Fib[105] = { 0,1,1 };

long long fib(int x)
{
	if (Fib[x]) return Fib[x];
	return Fib[x] = fib(x - 1) + fib(x - 2);
}

int main()
{
	fib(100);
	int T;
	cin >> T;
	while (T--)
	{
		bool find = false;
		long long n;
		cin >> n;
		for (int i = 1; i < 80 && Fib[i] < n; ++i)
		{
			for (int j = i; j < 80 && Fib[i] + Fib[j] < n; ++j)
			{
				for (int k = j; k < 80 && Fib[i] + Fib[j] + Fib[k] <= n; ++k)
				{
					if (find)
						continue;
					if (Fib[i] + Fib[j] + Fib[k] == n)
					{
						find = true;
						printf("%d %d %d\n", Fib[i], Fib[j], Fib[k]);
					}
				}
			}
		}
		if (!find)
			printf("No Answer\n");

	}
	return 0;
}
*/


/*
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, ji, ou;
		cin >> n >> m;
		if (n & 1)
		{
			ji = (n + 1) / 2;
			ou = (n - 1) / 2;
		}
		else
		{
			ji = n / 2;
			ou = n / 2;
		}
		if (m <= ou)
			printf("%d\n", 2 * m);
		else
			printf("%d\n", 2 * (m-ou) - 1);
	}
	return 0;
}
*/

/*
int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
		cout << max(a, max(b, c)) << endl;
	return 0;
}
*/



/*
int main()
{
	char str[10][100] =
	{
		"",
		"你就是海滩下的那乌克丽丽",
		"你发如雪",
		"我喜欢的样子你都有",
		"你是天使的魔法温暖中慈祥",
		"你的温柔象羽毛",
		"终有一天你有属于你的天",
	};

	int n;
	while (cin >> n)
		cout << str[n] << endl;
	return 0;
}
*/

/*
struct jian
{
	int a, b;
};

bool operator<(const jian& j1, const jian& j2)
{
	return j1.a < j2.a;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<jian> v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> v[i].a >> v[i].b;
		}
		sort(v.begin(), v.end());

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < v[i].b; ++j)
				cout << ">+" << string(v[i].a - 2, '-') << "+>" << endl;
			cout << endl;
		}
	}
	return 0;
}
*/

/*
const int MAX = 1005;
int go[MAX];
int a[MAX], n;
int num;

void solve()
{
	bool changed = true;
	num = 0;
	memset(go, 0, sizeof(go));
	while (changed)
	{
		changed = false;
		for (int i = 0; i < n; ++i)
		{
			if (go[i])
				continue;
			if (a[i] == i + 1 || go[a[i] - 1])
			{
				go[i] = 1;
				changed = true;
				num++;
			}
		}
	}
}

int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		solve();
		if (num == n)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
*/


/*
int main()
{
	string in;
	while (cin >> in)
	{
		int cur = -1;
		for (int i = 0; i < in.size() - 1; ++i)
			if (in[i] > in[i + 1])
			{
				cur = i;
				break;
			}
		if (cur == -1)
			cur = in.size() - 1;
		for (int i = 0; i < in.size(); ++i)
			if (i != cur)
				putchar(in[i]);
		putchar('\n');
	}
	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string in;
		cin >> in;
		int cnt = 0;
		for(int i=0; i <in.size(); ++i)
			switch (in[i])
			{
			case 's': case 'n': case 'a': case 'i': case 'l':
				cnt++;
				break;
			}
		int out = 100.0 * cnt / in.size();
		printf("%d%%\n", out);
	}
	return 0;
}
*/

/*
int main()
{
	int w,h;
	while (cin >> w >> h)
	{
		cout << '+' << string(w, '-') << '+' << endl;
		for (int i = 0; i < h; ++i)
			cout << '|' << string(w, ' ') << '|' << endl;
		cout << '+' << string(w, '-') << '+' << endl << endl;
	}
	return 0;
}
*/

/*
int main()
{
	map<char, char> m;
	m['A'] = 'T', m['T'] = 'A';
	m['G'] = 'C', m['C'] = 'G';
	int n;
	cin >> n;
	while (n--)
	{
		string in;
		cin >> in;
		for (int i = 0; i < in.size(); ++i)
			putchar(m[in[i]]);
		putchar('\n');
	}
	return 0;
}
*/

/*
int main()
{
	int a, b, c;
	for (int a = 3; a <= 100; ++a)
		for (int b = a+1; b <= 100; ++b)
			for (int c = b+1; c <= 100; ++c)
				if (a*a + b*b == c*c)
					printf("(%d,%d,%d)\n", a, b, c);

	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, ret = 0, x[35],y[35];
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];
		sort(x, x + n);
		sort(y, y + n);
		for (int i = 0; i < n/2; ++i)
			ret += x[n - i - 1] - x[i] + y[n - i - 1] - y[i];
		printf("%d\n", ret);
	}

	return 0;
}
*/

/*
bool is_prime(int x)
{
	int end = sqrt(x);
	for (int i = 2; i <= end; ++i)
		if (x % i == 0)
			return false;
	return x != 1;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int mid, l = 0;
		cin >> mid;
		if (!is_prime(mid))
			while (1)
			{
				l++;
				if (mid - l >= 2 && is_prime(mid - l))
				{
					mid -= l;
					break;
				}
				else if (is_prime(mid + l))
				{
					mid += l;
					break;
				}
			}
		printf("%d %d\n", mid, l);
	}

	return 0;
}
*/

/*
void printstr(char *p)
{
	while (*p != '\0')
		putchar(*p++);
}

int main()
{
	char str[20] = "this is it.";
	printstr(str);
	return 0;
}
*/

/*
int main()
{
	int T, n;
	double r[605];
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> r[i];
		sort(r, r + n, greater<double>());
		int ret = 0;
		double len = 0;
		while (len < 20)
		{
			double l = 2*sqrt(r[ret] * r[ret] - 1);
			len += l;
			ret++;
		}
		printf("%d\n", ret);
	}
	return 0;
}
*/
/*
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char a[15], b[1005];
		scanf("%s", a);
		scanf("%s", b);
		int la, lb, ret = 0;
		la = strlen(a), lb = strlen(b);
		for (int i = 0; i + la <= lb; ++i)
		{
			if (strncmp(a, b+i, la) == 0)
				ret++;
		}
		printf("%d\n", ret);
	}
	return 0;
}
*/

/*
int main()
{
	int n;
	char c[5];
	cin >> n;
	while (n--)
	{
		cin >> c;
		sort(c, c + 3);
		printf("%c %c %c\n", c[0], c[1], c[2]);
	}
	return 0;
}
*/

/*
int n, k;
double l[10005];

bool C(double len)
{
	int num = 0;
	for (int i = 0; i < n; ++i)
		num += int(l[i] / len);
	return num >= k;
}

void solve()
{
	double lb = 0, ub = 100005;
	for (int i = 0; i < 100; ++i)
	{
		double mid = (lb + ub) / 2;
		if (C(mid))lb = mid;
		else ub = mid;
	}
	printf("%.2lf\n", floor(ub * 100) / 100);
}

int main()
{
	while (cin >> n >> k)
	{
		for (int i = 0; i < n; ++i)
			cin >> l[i];
		solve();
	}

	return 0;
}
*/

/*
int main()
{
	char str[10] = "jklmn";
	char *p = str + 2;

	printf("%s\n", str);
	printf("%s\n", str + 2);
	printf("%s\n", &str[2]);

	printf("%s\n", &*(str + 2));

	printf("%s\n", p);
	printf("%s\n", p + 1);

	return 0;
}
*/

/*
int inverse(string &str)
{
	int ret = 0;
	string inv(str.rbegin(), str.rend());
	while (inv[0] == '0') inv.erase(inv.begin());
	ret = atoi(inv.c_str());
	return ret;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		string a, b;
		cin >> a >> b;
		cout << inverse(a) + inverse(b) << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int a, ans = 0;
	while (cin >> a && a)
	{
		int end = sqrt(a);
		for (int i = 1; i <= end; ++i)
		{
			if (a == i*i*i)
			{
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
*/

/*
int main()
{
	map<char, char> m;
	m['A'] = m['W'] = m['F'] = 'I';
	m['C'] = 'L', m['M'] = 'o', m['S'] = 'v';
	m['D'] = m['P'] = m['G'] = m['B'] = 'e';
	m['L'] = 'Y';
	m['X'] = 'u';
	string in;
	while (1)
	{
		getline(cin, in);
		if (in == "END")
			break;
		for (int i = 0; i < in.size(); ++i)
		{
			if (m[in[i]])
			{
				in[i] = m[in[i]];
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
	char str[10][5] = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	map<char, int> m;
	for (int i =1; i < 10; ++i)
	{
		int len = strlen(str[i]);
		for (int j = 0; j < len; ++j)
			m[str[i][j]] = i;
	}

	string in;
	while (cin >> in)
	{
		for (int i = 0; i < in.size(); ++i)
		{
			if (isupper(in[i]))
			{
				if (in[i] == 'Z')
					in[i] = 'a';
				else
					in[i] = tolower(in[i] + 1);
			}
			else if (islower(in[i]))
				in[i] = '1' + m[in[i]];
		}
		cout << in << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int v, d;
	while (cin >> v >> d)
		cout << ceil(1.0*v/d) + ceil((sqrt(d*d + 8 * d*v) - d) / (2 * d)) - 1 << endl;
	return 0;
}
*/

/*
int main()
{
	int w, sum;
	while (cin >> w)
	{
		w -= 265716;
		for (int i = 0; i < 10; ++i)
		{
			if (i != 0)
				putchar(' ');
			cout << 9 + w % 3;
			w /= 3;
		}
		putchar('\n');
	}
	return 0;
}
*/

/*
int main()
{
	int a,t[50] = { 1,2,4,7 };
	for (int i = 4; i <= 40; ++i)
		t[i] = 2 * t[i - 1] - t[i - 4];
	while (cin >> a)
		cout << t[a] << endl;
	return 0;
}
*/

/*
struct date
{
	int year, month, day;
};

bool operator<(const date &d1,const date &d2)
{
	if (d1.year != d2.year)
		return d1.year < d2.year;
	else
	{
		if (d1.month != d2.month)
			return d1.month < d2.month;
		else
			return d1.day < d2.day;
	}
}

int main()
{
	string str;
	vector<date> v;
	while (cin >> str)
	{
		stringstream ss;
		char tmp;
		date d;
		ss << str;
		ss >> d.month >> tmp >> d.day >> tmp >> d.year;
		v.push_back(d);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i)
		printf("%02d/%02d/%d\n", v[i].month, v[i].day, v[i].year);

	return 0;
}
*/

/*
int main()
{
	int T, k[25];
	cin >> T;
	while (T--)
	{
		int n, ans = 0,a,b;
		cin >> n;
		memset(k, 0, sizeof k);
		for (int i = 0; i < n; ++i)
		{
			cin >> a >> b;
			for (int j = a; j <= b; ++j)
				k[j]++;
		}
		ans = -1;
		for (int i = 0; i <= 24; ++i)
			ans = max(ans, k[i]);

		cout << ans << endl;
	}
	return 0;
}
*/

/*
long long fact(int x)
{
	if (x == 0)
		return 0;
	long long ret = 1;
	for (long long i = 2; i <= x; ++i)
		ret *= i;
	return ret;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, sum = 0, k;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> k;
			sum += k;
		}
		if (sum <= 30)
			cout << fact(n);
		else
			cout << "poor dongdong! You are dead";
		cout << endl;
	}
	return 0;
}
*/


/*
int r, n;
int x[1005];

int main()
{
	while (cin >> r >> n && (r != -1 && n != -1))
	{
		for (int i = 0; i < n; ++i)
			cin >> x[i];
		sort(x, x + n);
		int i = 0, ans = 0;
		while (i < n)
		{
			int s = x[i++];
			while (i < n && x[i] <= s + r) ++i;

			int p = x[i - 1];
			while (i < n && x[i] <= p + r) ++i;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
*/


/*
int main()
{
	set<string> s;
	string str;
	while (1)
	{
		s.clear();
		getline(cin, str);
		if (str == "")
			break;
		stringstream ss;
		ss.str("");
		ss << str;
		while (ss >> str)
			s.insert(str);
		cout << s.size() << endl;
	}
	return 0;
}
*/

/*
int n;
char S[2005];

void solve()
{
	int a = 0, b = n - 1, cnt=0;
	while (a <= b)
	{
		bool left = false;
		for (int i = 0; a + i <= b; ++i)
		{
			if (S[a + i] < S[b - i]) // 左边小
			{
				left = true;
				break;
			}
			else if (S[a + i] > S[b - i]) // 右边小
			{
				left = false;
				break;
			}
		}
		if (left)
			putchar(S[a++]);
		else
			putchar(S[b--]);
		cnt++;
		if (cnt == 80)
		{
			putchar('\n');
			cnt = 0;
		}
	}
	putchar('\n');
}

int main()
{
	int i = 0;
	while (cin >> n)
	{
		for (i = 0; i < n;++i)
			scanf("%s", &S[i]);
		solve();
	}
	return 0;
}
*/

/*
int L, n;
int x[1000005];


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> L >> n;
		for (int i = 0; i < n; ++i)
			scanf("%d", &x[i]);
		int minT = 0,maxT = 0;
		for (int i = 0; i < n; ++i)
		{
			minT = max(minT, min(x[i], L - x[i]));
			maxT = max(maxT, max(x[i], L - x[i]));
		}
		printf("%d %d\n", minT, maxT);
	}
	return 0;
}
*/

/*
int t[60][60];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int m, n;
		cin >> m >> n;
		for (int y = 0; y < m; ++y)
			for (int x = 0; x < n; ++x)
				scanf("%d", &t[x][y]);
		int depth = -1;
		for( int y=0; y <m;++y)
			for (int x = 0; x < n; ++x)
			{
				if (t[x][y] == 0)
					continue;
				int my = t[x][y];
				if (my < depth)
					continue;
				bool next = true;
				if (x != 0)
				{
					if (my == t[x - 1][y])
					{
						depth = my;
						next = false;
					}
				}
				if (next && x != n - 1)
				{
					if (my == t[x + 1][y])
					{
						depth = my;
						next = false;
					}
				}
				if (next && y != 0)
				{
					if (my == t[x][y-1])
					{
						depth = my;
						next = false;
					}
				}
				if (next && y != m - 1)
				{
					if (my == t[x][y + 1])
					{
						depth = my;
						next = false;
					}
				}
				if (next && x != 0)
				{
					if (y != 0 && my == t[x-1][y-1])
					{
						depth = my;
						next = false;
					}
					if (y != m - 1 && my == t[x - 1][y + 1])
					{
						depth = my;
						next = false;
					}
				}
				if (next && x != n-1)
				{
					if (y != 0 && my == t[x + 1][y - 1])
					{
						depth = my;
						next = false;
					}
					if (y != m - 1 && my == t[x + 1][y + 1])
					{
						depth = my;
						next = false;
					}
				}
			}
		printf("%d\n", depth);
	}
	return 0;
}
*/

/*
int prime[200];

void get(int n)
{
	int c = 2;
	int last = 2;
	prime[1] = 2;
	for (int i = 0; i < n; ++i)
	{
		int is = false;
		while (!is)
		{
			last++;
			is = true;
			int end = sqrt(last);
			for (int i = 2; i <= end; ++i)
			{
				if (last % i == 0)
				{
					is = false;
					break;
				}
			}
		}
		prime[c++] = last;
	}
}


int main()
{
	get(160);
	string in;
	while (cin >> in)
	{
		int ret = 0;
		for (int i = in.size() - 1; i >= 0; --i)
			ret += in[i] == '1' ? prime[in.size() - i] : 0;
		printf("%d\n", ret);
	}
	return 0;
}
*/

/*
const int MAXN = 105;
int A[MAXN];
int dp[MAXN][MAXN];

int main()
{
	int n, k, c;
	while (cin >> n >> k >> c)
	{
		memset(dp, 10000, sizeof(dp));
		for (int i = 0; i < n; ++i)
			scanf("%d", &A[i]);
		sort(A, A + n);

		// 区间起点
		for (int i = n - k; i >= 0; --i)
		{
			// 区间终点
			for (int j = i + k - 1; j < n; ++j)
			{
				// 该区间的奖金
				dp[i][j] = c + (A[j] - A[i])*(A[j] - A[i]);
				for (int q = i; q < j; ++q)
				{
					dp[i][j] = min(dp[i][j], dp[i][q] + dp[q + 1][j]);
				}
			}
		}
		printf("%d\n", dp[0][n - 1]);
	}
	return 0;
}
*/


/*
int table[20005];
int number[3005];

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			scanf("%d", &number[i]);
		int ret = n;
		bool right = false;
		while (!right)
		{
			bool next = true;
			memset(table, 0, 20005);
			for (int i = 0; i < n && next; ++i)
			{
				int mod = number[i] % ret;
				if (table[mod])
					next = false;
				else
					table[mod] = 1;
			}
			if (next)
				right = true;
			else
				ret++;
		}
		printf("%d\n", ret);
	}
	return 0;
}
*/


/*
int main()
{
	map<string, int> m;

	string tmp;
	while (cin >> tmp)
	{
		if (tmp[tmp.size() - 1] == ',' || tmp[tmp.size() - 1] == '.')
			tmp.erase(tmp.size() - 1);
		m[tmp]++;
	}
	map<string, int>::iterator max, it;
	for (int i = 0; i < 10; ++i)
	{
		max = it = m.begin();
		for (; it != m.end(); ++it)
		{
			if (it->second > max->second)
				max = it;
		}
		printf("%s %d\n", max->first.c_str(), max->second);
		m.erase(max);
	}
	return 0;
}
*/

/*
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
			scanf("%d", &v[i]);
		for (int i = 0; i < m; ++i)
		{
			int opt, x, y;
			scanf("%d", &opt);
			if (opt == 1)
			{
				scanf("%d %d", &x, &y);
				for (int j = 0; j < n; ++j)
				{
					if (v[j] == x)
						v[j] = y;
				}
			}
			else
			{
				scanf("%d", &x);
				printf("%d\n", v[x-1]);
			}
		}
	}
	return 0;
}
*/


/*
map<int, int> mp;

int main()
{
	int m, t, count;
	scanf("%d", &m);

	while (m--)
	{
		int opt, x;
		scanf("%d %d", &opt, &x);
		map<int, int>::iterator it;
		map<int, int>::reverse_iterator rit;
		switch (opt)
		{
		case 1:
			mp[x]++;
			break;
		case 2:
			count = 0;
			it = mp.begin();
			for (; it != mp.end(); ++it)
			{
				if (it->first >= x)
					break;
				count += it->second;
				it->second = 0;
			}
			mp[x] += count;
			break;
		case 3:
			count = 0;
			rit = mp.rbegin();
			for (; rit != mp.rend(); ++rit)
			{
				if (rit->first <= x)
					break;
				count += rit->second;
				rit->second = 0;
			}
			mp[x] += count;
			break;
		case 4:
			count = 0;
			it = mp.begin();
			for (; it != mp.end(); ++it)
			{
				count += it->second;
				if (count >= x)
					break;
			}
			printf("%d\n", it->first);
			break;
		case 5:
			count = 0;
			it = mp.begin();
			for (; it != mp.end(); ++it)
			{
				if (it->first > x)
					break;
				count += it->second;
			}
			printf("%d\n", count);
			break;
		}
	}
	return 0;
}
*/

/*
#include <stdio.h>
#define _(_) putchar(_);
int main(void) {
	int i = 0; _(
		++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++
		++++i)_(++++++++++++++++++++
		++++++++++++++++++++++++++++
		++++++++++i)_(++++++++++++++
		i)_(--++i)_(++++++i)_(------
		----------------------------
		----------------------------
		----------------------------
		----------------------------
		----------------i)_(--------
		----------------i)_(++++++++
		++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++
		++++++++++++++++++++++++++++
		++++++++++++++++++++++++++i)
		_(----------------i)_(++++++
		i)_(------------i)_(--------
		--------i)_(----------------
		----------------------------
		----------------------------
		----------------------------
		----------------------------
		------i)_(------------------
		----------------------------
	i)return i;
}

*/

/*
	这道题里面有一些东西需要根据样例的输出来获取
	比如： 0 也要向上级传递信息
		  这个树的关系是确定的，但通道并不一定建立
		  这可以通过样例的前5条推断出来
*/
/*
int n, m;
int up[5100];
int build[5100];
vector<int> down[5100];

int Send(int s)
{
	int ret = 0;
	// 顺着s一直找上级，一直找到0
	while (s)
	{
		if (!build[s])
		{
			build[s] = true;
			ret++;
		}
		s = up[s];
	}
	// 注意0本身也要向上建立通道。
	// 因为样例的第一行 Send 0  输出为 0
	if (!build[0])
	{
		build[0] = true;
		ret++;
	}
	return ret;
}

int Danger(int s)
{
	int ret = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		// 从队列中拉取一个节点
		s = q.front();
		q.pop();

		// 看 s 自己是否向上级建立了通道
		if (build[s])
		{
			ret++;
			build[s] = false;
		}
		// 遍历 s 所有的下级
		for (int i = 0; i < down[s].size(); ++i)
		{
			// 看这个下级是否建立了通道
			if (build[down[s][i]])
				q.push(down[s][i]);
		}
	}
	return ret;
}

int main()
{
	int i;
	cin >> n;
	for (i = 1; i < n; ++i)
	{
		scanf("%d", &up[i]);      // 设置 i 的上级
		down[up[i]].push_back(i); // 设置属于up[i]  的下级
	}
	char buffer[20];
	cin >> m;
	for (i = 0; i < m; ++i)
	{
		int num;
		scanf("%s", buffer);
		scanf("%d", &num);
		// 只用比较第一个字符就可以知道是哪条命令
		if (buffer[0] == 'S')
			printf("%d\n", Send(num));
		else
			printf("%d\n", Danger(num));
	}
	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string in;
		cin >> in;
		stack<char> s;
		bool right = true;
		for (int i = 0; i < in.size(); ++i)
		{
			if (in[i] == '(')
				s.push('(');
			else if (in[i] == '[')
				s.push('[');
			else if (in[i] == ')')
			{
				if (!(s.size() > 0 && s.top() == '('))
				{
					right = false;
					break;
				}
				s.pop();
			}
			else if (in[i] == ']')
			{
				if (!(s.size() > 0 && s.top() == '['))
				{
					right = false;
					break;
				}
				s.pop();
			}
		}

		if (right)
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
	set<string> s;
	string str;
	while (cin >> str)
		s.insert(str);
	cout << s.size() << endl;
	return 0;
}
*/

/*
long long fact(int x)
{
	long long ret = 1;
	for (int i = 2; i <= x; ++i)
		ret *= i;
	return ret;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, sum=0,k;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> k;
			sum += k;
		}
		if (sum <= 30)
			cout << fact(n);
		else
			cout << "poor dongdong! You are dead";
		cout << endl;
	}
	return 0;
}
*/