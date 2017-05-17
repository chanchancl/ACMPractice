
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