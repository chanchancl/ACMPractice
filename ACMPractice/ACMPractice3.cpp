
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
#include <stdio.h>
#include <string.h>
using namespace std;

string digits = "0123456789ABCDEFabcdef";

int main()
{
	string in, out;
	cin >> in;
	bool fu = false;
	bool before = false;
	for (int i = 0; i < in.size(); ++i)
	{
		if (in[i] == '-' && !fu && !before)
			fu = true;
		if (find(digits.begin(), digits.end(), in[i]) != digits.end())
		{
			out.push_back(in[i]);
			before = true;
		}
	}

	stringstream ss;
	ss << hex << out;
	long long o;
	ss >> o;
	if (fu)
		o = -o;
	cout << o;

	return 0;
}


/*
int main()
{
	int N;
	vector<int> a, b;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		vector<int>::iterator it;
		if ((it = find(a.begin(), a.end(), t)) != a.end())
			b[it - a.begin()]++;
		else
		{
			a.push_back(t);
			b.push_back(1);
		}
	}
	int index = max_element(b.begin(), b.end()) - b.begin();
	cout << a[index] << ' ' << b[index];


	return 0;
}
*/

/*
bool isprime(int x)
{
	int end = sqrt(x);
	if (x <= 1)
		return false;
	if (x == 2)
		return true;

	for (int i = 2; i <= end; ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	bool f = false;
	for (int i = 0; i <= n; ++i)
	{
		int t = pow(2, i) - 1;
		if (isprime(t))
		{
			cout << t << endl;
			f = true;
		}
	}
	if (!f)
		cout << "None";

	return 0;
}
*/

/*
bool isprime(int x)
{
	int end = sqrt(x);
	if (x <= 1)
		return false;
	if (x == 2)
		return true;

	for (int i = 2; i <= end; ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int N, p;
	cin >> N;
	for (p = 2; ; p++)
	{
		if (isprime(p) && isprime(N - p))
		{
			printf("%d = %d + %d", N, p, N - p);
			break;
		}
	}

	return 0;
}
*/

/*
char keys[10][10] = {
	"0 ",
	"1,.?!", "2ABC","3DEF",
	"4GHI", "5JKL", "6MNO",
	"7PQRS", "8TUV", "9WXYZ",
};

char get(int key, int n)
{
	if (n != 0)
		return keys[key][n - 1];
	else
		return keys[key][strlen(keys[key]) - 1];
}

int main()
{
	string out;
	string in;
	while (cin >> in)
			out.push_back(get(in[0] - '0', in.size()%strlen(keys[in[0]-'0'])));
	cout << out;
	return 0;
}
*/


/*
int main()
{
	int h, n, u, d;

	cin >> n >> u >> d;

	int t;
	h = 0;
	for (t = 1; ; ++t)
	{
		if (t % 2)
			h += u;
		if (h >= n)
			break;
		if (t % 2 == 0)
			h -= d;
	}
	cout << t;

	return 0;
}
*/

/*
int main()
{
	int va, vb;
	int a1, a2, b1, b2;
	int a, b, n;
	bool fa, fb;
	a = b = 0;
	
	fa = fb = true;
	cin >> va >> vb >> n;
	for (int i = 0; i < n && fa && fb; ++i)
	{
		cin >> a1 >> a2 >> b1 >> b2;
		if (a1 + b1 == a2 && a2 == b2)
			continue;
		if (a1 + b1 == a2)
		{
			a++;
			if (a > va)
				fa = false;
		}
		else if (a1 + b1 == b2)
		{
			b++;
			if (b > vb)
				fb = false;
		}
	}
	if (!fa)
		cout << "A" << endl << b;
	else if (!fb)
		cout << "B" << endl << a;

	return 0;
}
*/

/*
int main()
{
	char start;
	int n;

	cin >> start >> n;
	char c = start;
	if (n >= 3)
	{
		int half = n / 2;
		cout << string(half, ' ') << c << endl;
		c++;
		for (int i = 1; i <= half; ++i)
		{
			cout << string((half - i), ' ') << c << string(2 * i - 1, ' ') << c << endl;
			c++;
		}
		c -= 2;
		for (int i = 1; i < half; ++i)
		{
			cout << string(i, ' ') << c << string(2 * (half - i) - 1, ' ') << c << endl;
			c--;
		}
		cout << string(half, ' ') << c;
	}
	else
		cout << c;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> a, b, c;

	int i, j, k;
	i = j = k = 1;
	for (i = 1; i <= 30; i++)
	{
		for (j = 1; j <= (150 - 5 * i) / 2; ++j)
		{
			for (k = 1; k <= (150 - 5 * i - 2 * j); ++k)
			{
				if (i * 5 + j * 2 + k == 150 && i +j +k == 100)
				{
					a.push_back(i);
					b.push_back(j);
					c.push_back(k);
				}
			}
		}
	}

	n = min(n, int(a.size()));
	for (int i = 0; i < n; ++i)
		printf("%d %d %d\n", a[i], b[i], c[i]);
	return 0;
}
*/

/*
void fun(int array[3][3])
{
	for (int i = 0; i < 3 / 2; ++i)
	{
		for (int j = 0; j < 3 / 2; ++j)
		{
			int t = array[i][j];
			array[i][j] = array[j][i];
			array[j][i] = t;
		}
	}

}

int main()
{
	int a[10005], b[10005], t, n, c;
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		memset(b, 0, sizeof(b));

		for (int i = 0; i < n; ++i)
		{
			int j;
			for (j = i + 1; j < n && a[j] == a[i]; ++j);

			b[i] = j - i;
		}
		cout << *max_element(b, b + n) << endl;
	}


	return 0;
}
*/

/*
int  a[100005] = { 0 };
int  n, m, i, x, k = 0;

int search(int x)
{
	int l, h, mid;
	l = 0;
	h = n - 1;

	while (l <= h)
	{
		mid = (l + h) >> 1;
		if (x < a[mid])
			h = mid - 1;
		else if (a[mid] < x)
			l = mid + 1;
		else
			return mid;
	}

	return -1;
}

int  main()
{
	cin >> n;
	for (i = 0; i<n; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	for (i = 0; i<m; i++)
	{
		cin >> x;
		k = search(x);
		if (k >= 0)
			cout << k << endl;
		else
			cout << "Not found!" << endl;

	}
	return 0;
}
*/


/*
const int INF = 0x7fffffff;
int ani[105][105];
int visit[105];
int visited;
int n, m;

int max = -1;
int find(int x)
{
	int res = 0 ,dis[105];
	fill(dis, dis + 105, INF);
	memset(visit, 0, sizeof visit);
	dis[x] = 0;
	visited = 0;
	for (int i = 0; i < n; ++i)
	{
		int mi = INF, id = -1;
		for (int j = 1; j <= n; ++j)
		{
			if (!visit[j] && dis[j] < mi)
			{
				id = j;
				mi = dis[j];
			}
		}
		if (id == -1)
			return 0;
		visit[id] = 1;
		visited++;
		for (int j = 1; j <= n; ++j)
		{
			if (ani[id][j] && dis[id] + ani[id][j] < dis[j])
				dis[j] = dis[id] + ani[id][j];
		}
	}
	int ma = -1;
	for (int i = 1; i <= n; ++i)
	{
		if (dis[i] != INF && dis[i] > ma)
			ma = dis[i];
	}

	return ma;
}

int main()
{
	cin >> n >> m;
	memset(ani, 0, sizeof ani);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		ani[a][b] = ani[b][a] = c;
	}

	int flag = true;
	int res = 0, min = INF;
	for (int i = 1; i <= n; ++i)
	{
		int r = find(i);
		if (visited != n)
		{
			flag = false;
			break;
		}
		if (r < min)
		{
			min = r;
			res = i;
		}
	}
	if (!flag)
		cout << 0 << endl;
	else
	{
		cout << res << ' ' << min << endl;
	}

	return 0;
}
*/

/*
int main()
{
	const int MAXN = 10;
	int a[MAXN][MAXN];
	int n, x, y, tot = 0;
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	tot = a[x = 0][y = n - 1] = 1;
	while (tot < n*n)
	{
		while (x + 1 < n  && !a[x + 1][y]) a[++x][y] = ++tot;
		while (y - 1 >= 0 && !a[x][y - 1]) a[x][--y] = ++tot;
		while (x - 1 >= 0 && !a[x - 1][y]) a[--x][y] = ++tot;
		while (y + 1 < n  && !a[x][y + 1]) a[x][++y] = ++tot;
	}
	for (x = 0; x < n; x++)
	{
		for (y = 0; y < n; y++) printf("%3d", a[x][y]);
		puts("");
	}

	return 0;
}
*/


/*
int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		int a = 0, ab = 0, aba = 0, abab = 0;
		for(int i=0; i < n; ++i)
		{
			int x;
			scanf("%d", &x);
			if (x == 1)
				a++, aba++;
			else
				ab++, abab++;
			ab = max(ab, a);
			aba = max(aba, ab);
			abab = max(abab, aba);
		}
		printf("%d\n", abab);
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
		int n, m;
		cin >> n >> m;
		int ac[13], wa[13];
		int hr, mi;
		int num;
		char c;
		string rst;
		int pently = 0;
		memset(ac, 0, sizeof(ac));
		memset(wa, 0, sizeof(wa));
		for (int i = 0; i < m; ++i)
		{
			cin >> num >> hr >> c >> mi >> rst;
			num -= 1001;
			if (ac[num])
				continue;
			if (rst == "AC")
			{
				pently += hr * 60 + mi + wa[num] * 20;
				ac[num] = 1;
			}
			else
				wa[num]++;
		}
		cout << count(ac, ac + n, 1) << ' ' << pently << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int i, a, n, m, p, flag;
	scanf("%d", &a);
	for (i = 0; i<a; i++)
	{
		flag = 1;
		int a[9][9] = { 0 };
		int b[9][9] = { 0 };
		for (n = 0; n<9; n++)
		{
			for (m = 0; m<9; m++)
			{
				scanf("%d", &p);
				a[n][p - 1]++;
				b[p - 1][m]++;
			}
		}
		for (m = 0; m<9; m++)
		{
			for (n = 0; n<9; n++)
			{
				if (a[m][n] != 1)
				{
					flag = 0;
					break;
				}
			}
		}
		for (m = 0; m<9; m++)
		{
			for (n = 0; n<9; n++)
			{
				if (b[n][m] != 1)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag) printf("Yes\n");
		else printf("No\n");
	}
}
*/

/*
struct people
{
	string name;
	int arr;
	int use;
}peo[10005];

int fn[10005];

void init()
{
	for (int i = 0; i < 10005; ++i)
		fn[i] = i;
}

int find(int x)
{
	if (fn[x] != x)
		return fn[x] = find(fn[x]);
	return x;
}

void make(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		fn[a] = b;
}

int visit[10005];
map<string, int> ID;
int cur = 0;
int getid(string x)
{
	if (ID.find(x) != ID.end())
		return ID[x];
	int tmp = ID[x] = cur++;
	peo[tmp].name = x;
	return tmp;
}

int main()
{
	int n, m;
	cin >> n >> m;
	people tmp;
	int t;
	int cid = 0;

	init();
	for (int i = 0; i < m; ++i)
	{
		int l, id;
		cin >> l;
		cin >> tmp.name;
		id = getid(tmp.name);
		peo[id] = tmp;
		int last = id;

		for (int j = 1; j < l; ++j)
		{
			cin >> tmp.name;
			id = getid(tmp.name);
			peo[id] = tmp;
			make(last, id);
		}
	}

	vector<int> li;
	for (int i = 0; i < n; ++i)
	{
		string name;
		int arr, use;
		cin >> name >> arr >> use;
		int id = getid(name);
		peo[id].arr = arr;
		peo[id].use = min(use, 60);
		
		li.push_back(id);
	}

	memset(visit, 0, sizeof(visit));
	queue<people> q;
	q.push(peo[li[0]]);
	visit[li[0]] = 1;

	double total = 0;
	int last = peo[li[0]].arr + peo[li[0]].use;
	vector<string> out;

	while (!q.empty())
	{
		people p = q.front(); q.pop();
		out.push_back(p.name);
		bool f = false;
		for (int i = 0; i < li.size(); ++i)
		{
			if (visit[li[i]]) continue;
			if (peo[li[i]].arr > last) break;
			if (find(getid(p.name)) == find(li[i]))
			{
				q.push(peo[li[i]]);
				visit[li[i]] = 1;
				f = true;
				total += last - peo[li[i]].arr;
				last += peo[li[i]].use;
				break;
			}
		}
		if (!f)
		{
			for (int i = 0; i < li.size(); ++i)
			{
				if (visit[li[i]]) continue;
				q.push(peo[li[i]]);
				visit[li[i]] = 1;
				total += max(0, last - peo[li[i]].arr);
				last = max(last, peo[li[i]].arr);
				last += peo[li[i]].use;
				break;
			}
		}
	}
	for (int i = 0; i < out.size(); ++i)
	{
		cout << out[i] << endl;
	}
	printf("%.1f\n", total / n);

	return 0;
}
*/

/*
int main()
{
	int n;
	vector<int> v;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int mlen, clen;
	mlen = clen = 1;
	int s, e;
	s = e = 0;
	int cs, ce;
	cs = ce = 0;
	for (int i = 1; i < n; ++i)
	{
		if (v[i] > v[i - 1])
		{
			clen++;
			ce++;
			if (clen > mlen)
			{
				mlen = clen;
				s = cs;
				e = ce;
			}
		}
		else
		{
			clen = 1;
			cs = ce = i;
		}
	}
	cout << v[s];
	for (int i = s + 1; i <= e; ++i)
		cout << ' ' << v[i];
	return 0;
}
*/

/*
int main()
{
	list<int > v1, v2,o;
	int n,t;
	cin >> n;
	for(int i=0; i < n; ++i)
	{
		cin >> t;
		if (t % 2)
			v1.push_back(t);
		else
			v2.push_back(t);
	}
	while (v1.size() || v2.size())
	{
		if (v1.size())
		{
			o.push_back(*v1.begin());
			v1.pop_front();
		}
		if (v1.size())
		{
			o.push_back(*v1.begin());
			v1.pop_front();
		}
		if (v2.size())
		{
			o.push_back(*v2.begin());
			v2.pop_front();
		}
	}
	list<int>::iterator it = o.begin();
	cout << *it;
	for (it++; it != o.end(); ++it)
	{
		cout << ' ' << *it;
	}

	return 0;
}
*/

/*
int num = 0;
string err;
/*
	1   2
	l	r

	/*  0
	(   1
	[   2
	{   3
*/
/*
bool func(string s)
{
	int a[4];
	memset(a, 0, sizeof(int) * 4);
	for (int i = 0; i < s.size() && num == 0; ++i)
	{
		if (s[i] == '(')
			a[1]++;
		else if (s[i] == '[')
			a[2]++;
		else if (s[i] == '{')
			a[3]++;
		else if (s[i] == '/' && s[i + 1] == '*')
		{
			a[0]++;
			i++;
		}
		else if (s[i] == ')')
		{
			a[1]--;
			if (a[1] < 0)
			{
				err = ")";
				num = 1;
			}
		}
		else if (s[i] == ']')
		{
			a[2]--;
			if (a[2] < 0)
			{
				err = ']';
				num = 1;
			}
		}
		else if (s[i] == '}')
		{
			a[3]--;
			if (a[3] < 0)
			{
				err = "}";
				num = 1;
			}
		}
		else if (s[i] == '*' && s[i + 1] == '/')
		{
			a[0]--;
			if (a[0] < 0)
			{
				err = "*///";
	/*
				num = 1;
			}
		}
	}
	if (err != "")
		return false;

	if (a[0] != 0)
	{
		err = "/*";
		num = 2;
	}
	else if (a[1] != 0)
	{
		err = "(";
		num = 2;
	}
	else if (a[2] != 0)
	{
		err = "[";
		num = 2;
	}
	else if (a[3] != 0)
	{
		err = "{";
		num = 2;
	}
	if (err != "")
		return false;
	return true;
}

int main()
{
	string prog;
	set<char> s{'(',')','[',']', '{','}' };
	while (1)
	{
		string str;
		getline(cin, str);
		if (str[0] == '.')
			break;
		for (int i = 0; i < str.size(); ++i)
		{
			if (s.find(str[i]) != s.end())
				prog.push_back(str[i]);
			else if ((str[i] == '/' && str[i + 1] == '*') || (str[i] == '*' && str[i + 1] == '/'))
			{
				prog.push_back(str[i]);
				prog.push_back(str[i + 1]);
				i++;
			}
		}
	}
	if (func(prog))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO" << endl;
		if (num == 1)
		{
			cout << "?-" << err;
		}
		else if (num == 2)
		{
			cout << err << "-?";
		}
	}
	return 0;
}
*/

/*
int main()
{
	int n, m;
	cin >> n >> m;

	for (int t = 0; t < n; ++t)
	{
		string op;
		cin >> op;
		int c = 0;
		bool err = false;
		for (int i = 0; i < op.size() && !err; ++i)
		{
			if (op[i] == 'S')
			{
				c++;
				if (c > m)
					err = true;
			}
			else if (op[i] == 'X')
			{
				c--;
				if (c < 0)
					err = true;
			}
		}
		cout << (!err && c == 0 ? "YES" : "NO") << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int k;
	cin >> k;
	vector<int> v;
	v.resize(k);
	for (int i = 0; i < k; ++i)
		cin >> v[i];

	int msum, csum;
	msum = csum = 0;
	for (int i = 0; i < k; ++i)
	{
		csum += v[i];
		if (csum > msum)
			msum = csum;
		else if (csum < 0)
			csum = 0;
	}
	cout << msum;

	return 0;
}
*/

/*
int main()
{
	int t;
	vector<int> s;
	while (1)
	{
		cin >> t;
		if (t != -1)
			s.push_back(t);
		else
			break;
	}
	while (1)
	{
		cin >> t;
		if (t != -1)
			s.push_back(t);
		else
			break;
	}
	if (s.size() > 0)
	{
		sort(s.begin(), s.end());
		vector<int>::iterator it = s.begin();
		cout << *it;
		for (it++; it != s.end(); ++it)
		{
			cout << ' ' << *it;
		}
	}
	else
		cout << "NULL";

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
		sort(v.begin(), v.end(), [](int a, int b) { return abs(a) > abs(b); });
		cout << v[0];
		for (int i = 1; i < n; ++i)
			cout << ' ' << v[i];
		cout << endl;
	}
	return 0;
}
*/

/*
int get(int x)
{
	int i, sum = 0;
	for (i = 1; i < x; ++i)
		if (x % i == 0)
			sum += i;
	return sum;
}

int main()
{
	int m;
	while (cin >> m)
	{
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			if (get(a) == b && get(b) == a)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}
*/

/*
int main()
{
	vector<string> v1,v2,v3;
	string s1,s2;
	v1.push_back("123");
	v1.push_back("456");
	v1.push_back("789");

	cout << string(10, '-') << "Round 1" << string(10, '-') << endl;
	cout << "v1.size() :" << v1.size() << endl;
	cout << "v2.size() :" << v2.size() << endl;
	v2 = v1;
	cout << "After assign" << endl;
	cout << "v1.size() :" << v1.size() << endl;
	cout << "v2.size() :" << v2.size() << endl;

	cout << string(10, '-') << "Round 2" << string(10, '-') << endl;
	v2 = v1;
	cout << "v2.size() :" << v2.size() << endl;
	cout << "v3.size() :" << v3.size() << endl;

	v3 = move(v2);

	cout << "After move" << endl;
	cout << "v2.size() :" << v2.size() << endl;
	cout << "v3.size() :" << v3.size() << endl;

	cout << string(10, '-') << "Round 2" << string(10, '-') << endl;
	v2 = v1;
	cout << "v1.size() :" << v1.size() << endl;
	cout << "v2.size() :" << v2.size() << endl;

	s1.reserve(9), s2.reserve(9);

	for (const string str : v1)
	{
		s1 += str;
	}
	for (const string str : v2)
	{
		s2 += move(str);
	}
	cout << "After build" << endl;
	cout << "s1 : " << s1 << endl;
	cout << "s2 : " << s2 << endl;
	cout << "v1.size() :" << v1.size() << endl;
	cout << "v2.size() :" << v2.size() << endl;
	for (string str : v1)
	{
		cout << str << endl;
	}
	for (string str : v2)
	{
		cout << str << endl;
	}
}
*/

/*
int getid(map<string, int> &id, string &str)
{
	if (id.find(str) == id.end())
		id[str] = id.size();
	return id[str];
}

int main()
{
	int n;
	map<string, int> id;
	set<string> s;
	while (cin >> n && n)
	{
		vector<int> v,v1,v2;
		id.clear();
		s.clear();
		

		for (int i = 0; i < n; ++i)
		{
			int id2;
			string str;
			cin >> str;
			s.insert(str);
			//id1 = getid(id, str);
			//v1.push_back(id1);

			cin >> str;
			s.insert(str);
			id2 = getid(id, str);
			v2.push_back(id2);
		}
		v.resize(s.size(), 1);
		for (int i = 0; i < n; ++i)
			v[v2[i]] = 0;

		int c = count(v.begin(), v.end(), 1);
		cout << (c == 1 ? "Yes" : "No") << endl;
	}
	return 0;
}
*/

/*
int main()
{
	
	int time;
	int work1, work2, work3, work4;
	int flag;
	for (time = 160; time <= 184; ++time)
	{
		work1 = time - 160;
		work2 = 200 - 184;
		work3 = work2 / 3;
		work4 = work3 / 2;
		if (work1 >= 0 && work2 >= 0 && work3 > 0)
		{
			if ((work1%work3 <= work4))
				printf("%d is on.\n", time);
			else
				printf("%d is off.\n", time);
		}
		
	}
	return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
	int swa(char *a[], int n);
	int print(char *a[], int n);
	char *a[] = { "Luhan","Leonardo DiCaprio","Jack dawson" };
	int n = 3;
	swa(a, 3);
	print(a, 3);
	return 0;
}
int swa(char *a[], int n)
{
	char *t;
	int i, j, k;
	for (i = 0; i<n - 1; i++)
	{
		k = i;
		for (j = i + 1; j<n; j++)
			if (strcmp(a[k], a[j]) > 0)   
				k = j;
		if (k != i)
		{
			t = a[i];
			a[i] = a[k];
			a[k] = t;
		}
	}
	return 0;
}
int print(char *a[], int n)
{
	int i;
	for (i = 0; i<n; i++)
		printf("%s\t", a[i]);
	return 0;
}
*/

/*
#include<stdio.h>
void change(int a[100], int n);
int main()
{
	int num[100] = { 0 };
	int n;
	scanf("%d", &n);
	change(num, n);
	return 0;
}
void change(int a[100], int n)
{
	int i, j, m;
	scanf("%d", &m);
	int b[100] = { 0 };
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for (int i = 0; i < n-m; ++i)
		b[i + m] = a[i];
	
	for (int i = 0; i < m; ++i)
		b[i] = a[i + n - m];

	for (j = 0; j < n; j++)
		printf("%d ", b[j]);
}
*/

/*
#include<stdio.h>
#include<string.h>
void swap(char **p1, char **p2);

int main()
{
	char *ch[3];
	char **p;
	int i;
	for (i = 0; i < 3; ++i)
		ch[i] = (char*)malloc(sizeof(char) * 1024);

	scanf("%s", ch[0]);
	scanf("%s", ch[1]);
	scanf("%s", ch[2]);
	if (strcmp(ch[0], ch[1])>0)
	{
		swap(&ch[0], &ch[1]);
	}
	if (strcmp(ch[1], ch[2])>0)
	{
		swap(&ch[1], &ch[2]);
	}
	for (p = ch; p < (ch + 3); p++)
		printf("%s\n", *p);

	for (i = 0; i < 3; ++i)
		free(ch[i]);

	return 0;
}

void swap(char **p1, char **p2)
{
	char *tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
*/

/*
#include<stdio.h>
#include<string.h>
void swap(char *p1, char *p2);

int main()
{
	char ch[3][1024];
	char **p;

	scanf("%s", ch[0]);
	scanf("%s", ch[1]);
	scanf("%s", ch[2]);
	if (strcmp(ch[0], ch[1])>0)
	{
		swap(ch[0], ch[1]);
	}
	if (strcmp(ch[1], ch[2])>0)
	{
		swap(ch[1], ch[2]);
	}
	for (p = ch; p < (ch + 3); p++)
		printf("%s", *p);
	return 0;
}

void swap(char *p1, char *p2)
{
	int len;
	char *tmp;
	len = strlen(p1);
	tmp = (char*)malloc(sizeof(char)*len);
	strcpy(tmp, p1);
	strcpy(p1, p2);
	strcpy(p2, tmp);
}
*/

/*
int main()
{
	int n, ma, t;
	
	while (cin >> n && n)
	{
		ma = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> t;
			ma = max(ma, t);
		}
		cout << ma << endl;
	}
	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	int f[21];
	double s1 = 0, s2 = 0;

	f[1] = 2, f[0] = 1;

	for (int i = 2; i <= 20; ++i)
		f[i] = f[i - 1] + f[i - 2];
	
	for (int i = 1; i <= 20; ++i)
	{
		printf("��%02d�� : %lf %lf\n", i, double(f[i] / f[i - 1]), 1.0*f[i] / f[i - 1]);
		s1 += f[i] / f[i - 1];
		s2 += 1.0*f[i] / f[i - 1];
	}

	printf("%f\n%f\n", s1, s2);
	return 0;
}
*/

/*
const int N = 10000;

struct _station {
	int dist, fuel;
	bool operator < (const _station& s) const {
		return dist > s.dist;
	}
} station[N];
int n, l, p;

int main()
{
	while (scanf("%d", &n) != EOF) {
		priority_queue<int> fuel;

		for (int i = 0; i<n; i++)
			scanf("%d%d", &station[i].dist, &station[i].fuel);
		sort(station, station + n);     // ����Ӵ�С  

		scanf("%d%d", &l, &p);

		fuel.push(p);
		int ans = 0, i = 0;
		// l Ϊʣ��·��, fuel ��Ŀǰ���Ե���ĳ�վ�Ķ���
		while (l > 0 && !fuel.empty()) {
			ans++;
			l -= fuel.top();
			fuel.pop();
			// �ѿɵ������˵�����Թ����ļ���վ�������ȶ���
			while (i < n && l <= station[i].dist)
				fuel.push(station[i++].fuel);
		}
		printf("%d\n", l <= 0 ? ans - 1 : -1);
	}

	return 0;
}
*/



// ���룬 ���ɸ� 1-4 �������� -1 Ϊ������
// ͳ�Ƹ��������ֵĴ���

/*
void deal(int a[20], int n);
int main()
{
	int b[20];
	int i, n=0;

	for (i = 0; i<20; i++)
	{
		scanf("%d", &b[i]);
		if (b[i] == -1)
			break;
		n++;
	}
	deal(b, n);

	return 0;
}

void deal(int a[20], int n)
{
	int i, j;
	int b[20];

	memset(b, 0, sizeof(b));
	for (i = 0; i<n; i++)
	{
		j = a[i];
		b[j]++;
	}
	for (j = 1; j <= 4; j++)
		printf("%d:   %d\n", j, b[j]);
}
*/

/*
int bits[20], fn[20][2];

int dfs(int c, int last, bool lim)
{
	int ans = 0;
	if (c == -1)
		return 1;
	if (!lim && fn[c][last == 6] != -1)
		return fn[c][last == 6];
	int up = lim ? bits[c] : 9;
	for (int i = 0; i <= up; ++i)
	{
		if (last == 6 && i == 2) continue;
		if (i == 4) continue;
		ans += dfs(c - 1, i, lim && i == bits[c]);
	}
	if (!lim)
		fn[c][last == 6] = ans;
	return ans;
}

int f(int n)
{
	int c = 0;
	memset(bits, 0, sizeof(bits));
	while (n)
	{
		bits[c++] = n % 10;
		n /= 10;
	}
	return dfs(c - 1, -1, true);
}

int main()
{
	int n, m;
	memset(fn, -1, sizeof(fn));
	while (cin >> n >> m && n && m)
		cout << f(m) - f(n-1) << endl;

	return 0;
}
*/

/*
// HDU 2089  Time Limit Exceeded
int main()
{
	int n, m;
	while (cin >> n >> m && n && m)
	{
		int ret = 0;
		for (int i = n; i <= m; ++i)
		{
			string str;
			stringstream ss;
			ss << i;
			ss >> str;
			if (str.find("62") == string::npos && str.find("4") == string::npos)
				ret++;
		}
		cout << ret << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n;
	bool f = true;
	while (cin >> n && n)
	{
		if (f)
			f = !f;
		else
			cout << endl;
		int total = 0, av, ret = 0;
		vector<int> v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> v[i];
			total += v[i];
		}
		av = total / n;
		for (int i = 0; i < n; ++i)
		{
			if (v[i] > av)
				ret += v[i] - av;
		}
		cout << ret << endl;
	}

	return 0;
}
*/

/*
#include<stdio.h>
#include<math.h>
int main()
{
	int m, i, j;
	double sum;
	int a[105];
	scanf("%d", &m);

	for (i = 0; i<m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i<m; i++)
	{
		sum = 0;
		for (j = 1; j <= a[i]; j++)
		{
			if (j % 2 == 1)
				sum += 1.0 / j;
			else
				sum += -1.0 / j;
		}
		printf("%.2lf\n", sum);
	}
	return 0;
}
*/

/*
int main()
{
	int n;
	double a0, an, c;

	while (cin >> n)
	{
		cin >> a0 >> an;
		double sum = n*a0 + an;
		for (int i = 0; i < n; ++i)
		{
			cin >> c;
			sum -= 2*(n - i)*c;
		}
		sum /= n + 1;
		printf("%.2lf\n", sum);
	}

	return 0;
}
*/

/*
long long a[50] = { 1 }, b[50];

int main()
{

	for (int i = 1; i <= 33; ++i)
	{
		a[i] = 3 * a[i - 1] + 2 * b[i - 1];
		b[i] = a[i - 1] + b[i - 1];
	}

	int x;
	while (cin >> x && x != -1)
		printf("%lld, %lld\n", a[x], b[x]);
	return 0;
}
*/

/*
int main()
{
	int x, i;
	scanf("%d", &x);

	for (i = 2; i < x; ++i)
	{
		if (x % i == 0)
		{
			printf("no\n");
			break;
		}
	}
	if (i == x)
		printf("yes\n");

	return 0;
}
*/

/*
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		int dp[105][105];
		
		cin >> n;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j)
				cin >> dp[i][j];

		for (int i = n - 2; i >= 0; --i)
			for (int j = 0; j <= i; ++j)
				dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);

		cout << dp[0][0] << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int sum, n, x[505], mi;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> x[i];
		for (int i = 0; i < n; ++i)
		{
			sum = 0;
			for (int j = 0; j < n; ++j)
				sum += abs(x[i] - x[j]);

			if (i == 0)
				mi = sum;
			else
				mi = min(sum, mi);
		}
		cout << mi << endl;
	}


	return 0;
}
*/

/*
const int N = 50;

int c1[N + 10], c2[N + 10], num[30];

int main() 
{

	int t;
	scanf("%d", &t);
	while (t--) 
	{
		memset(c1, 0, sizeof(c1));    //c1[ ]���浱ǰ�õ��Ķ���ʽ����ϵ��
		memset(c2, 0, sizeof(c2));    //c2[ ]����ÿ�μ���ʱ����ʱ���
		for (int i = 1; i <= 26; i++)
			scanf("%d", &num[i]);
		c1[0] = 1;                //�൱����X^0ȥ���Ժ���Ķ���ʽ 
		for (int i = 1; i <= 26; i++) 
		{   
			//Ҫ����26������ʽ
			for (int j = 0; j <= N; j++)   //c1�ĸ����ָ��
				for (int k = 0; k <= num[i] && j + k*i <= N; k++)  //k*i��ʾ���˶���ʽ�����ָ��,(X^0*i + X^1*i + X^2*i + ����)
					c2[j + k*i] += c1[j];       //ָ����ӵ�j+k*i,�Ӷ���ֻȡ����c1[j]��ϵ������Ϊ���˶���ʽ�ĸ���ϵ����Ϊ1
			for (int j = 0; j <= N; j++) 
			{
				c1[j] = c2[j];
				c2[j] = 0;
			}
		}
		int ans = 0;
		for (int i = 1; i <= N; i++)
			ans += c1[i];
		printf("%d\n", ans);
	}
	return 0;
}
*/

/*
int main()
{
	double n, sum;
	int m, i;

	while (scanf("%lf%d", &n, &m) != EOF)
	{
		sum = 0;
		for (i = 0; i < m; ++i)
		{
			sum += n;
			n = sqrt(n);
		}
		printf("%.2lf\n", sum);
	}

	return 0;
}
*/

/*
int main()
{
	// i++   ++i
	// 1. ++i 
	// 2. expression
	// 3. i++

	int a = 5 ,i = 5;
	i = ++i + ++i;
	a = a++ + a++; 


	printf("%d\n" , i);
	printf("%d\n" , a);

	/*					����ʽ��ֵ	i��ֵ
		��ʼ							5
		�ȼ���ǰ׺����ʽ
		����ȼ��� ++i	6			6
		����i++			6			6
		���� (i++)+(++i) 12			6
		��ֵ(=)�� i		12			12
		�����׺����ʽ�� i��+1		
	*/

/*
}
*/

/*
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		cout << "6" + s.substr(6) << endl;
	}

	return 0;
}
*/

/*
#include<stdio.h>
int main()
{
	char a[10];
	int i, j, t;
	for (i = 0; i<10; i++)
		scanf("%c", &a[i]);
	for (j = 0; j < 9; j++)
	{
		for (i = 0; i < 9-j; i++)
		{
			if (a[i]>a[i + 1])
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
		}
	}
	for (i = 0; i<10; i++)
	{
		printf("%c", a[i]);
	}
	return 0;
}
*/

/*
#include<stdio.h>
int sum(int x);
int main()
{
	int i, a, b, c;
	for (i = 100; i <= 999; i++)
	{
		if (sum(i))
			printf("%d\n", i);
	}
	return 0;
}
int sum(int x)
{
	int a, b, c;
	a = x / 100;
	b = (x - a * 100) / 10;
	c = x % 10;
	if (a*a*a + b*b*b + c*c*c == x)
		return 1;
	return 0;
}
*/


/*
void NumTower(int n);

int main()
{
	int n;

	scanf("%d", &n);
	NumTower(n);

	return 0;
}

void NumTower(int n)
{
	int i, j;
	// i ������ǰѭ���Ĳ���
	for (i = 1; i <= n; i++)
	{
		// (n-i�����ո�
		for (j = 0; j < n - i; j++)
			printf(" ");

		// �� 1 �� i
		for (j = 1; j <= i; j++)
			printf("%d", j);

		// �� (i-1) �� j
		for (j = i - 1; j >= 1; j--)
			printf("%d", j);

		printf("\n");
	}
}
*/

/*
int isprime(int a);

int main()
{
	int x = 57;
	if (isprime(x) == 0)
	{
		printf("%d��������", x);
	}
	else
	{
		printf("%d������", x);
	}
	return 0;
}

int isprime(int a)
{
	int i;
	if (a <= 1)
		return 0;
	for (i = 2; i <= sqrt(a); i++)
	{
		if (a%i == 0)
		{
			return 0;
		}
			
	}
	return 1;
}
*/

/*
int main()
{
	int n;
	double x1, y1, x2, y2, len, s;
	cin >> n;
	while (n--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		len = sqrt(x1*x1 + y1*y1) * sqrt(x2*x2 + y2*y2);
		s = acos((x1*x2 + y1*y2) / len) / 3.1415926*180.0;
		printf("%.2lf\n", s );
	}

	return 0;
}
*/

/*
int main()
{
	int dp[50], sc[10], num[10];
	int T, n, k;
	cin >> T;

	while (T--)
	{
		memset(dp, 0, sizeof(dp));
		cin >> n >> k;
		for (int i = 1; i <= k; ++i)
			cin >> sc[i] >> num[i];
		dp[0] = 1;
		for (int i = 1; i <= k; ++i) // �������п�Ŀ
			for (int j = n; j >= sc[i]; --j) // ����ʣ��ķ���
				for (int l = 1; l <= num[i] && j >= l *sc[i]; ++l) // ������Ŀ��ʹ�ô���
					dp[j] += dp[j - l*sc[i]];
		cout << dp[n] << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int T,n, m, mi;

	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		mi = 100;
		while (n--)
		{
			int t;
			cin >> t;
			mi = min(t, mi);
		}
		cout << (100 - mi)*(100 - mi) << endl;
	}

	return 0;
}
*/

/*
// HDU - 2076
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int h, m, s;
		cin >> h >> m >> s;

		h = h % 12;
		float f1, f2;
		f1 = m*6 + (s / 60.0f)*6.0f;
		f2 = h*30 + (f1 / 360.0f)*30.0f;
		f1 = fabs(f1 - f2);
		f2 = fminf(f1, 360 - f1);
		cout << int(f2) << endl;

	}

	return 0;
}
*/

/*
int main()
{
	int n, ret, y;
	while (scanf("%d", &n) && n)
	{
		ret = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &y);
			ret ^= y;
		}
		printf("%d\n", ret);
	}
	return 0;
}
*/

/*
int main()
{
	int n, a;
	while (scanf("%d", &n) && n)
	{
		set<int> s1, s2;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a);
			if (s1.find(a) == s1.end())
			{
				s1.insert(a);
				s2.insert(a);
			}
			else
				s2.erase(a);
		}
		printf("%d\n", *s2.begin());
	}

	return 0;
}
*/

/*
int main()
{
	int *a;
	int b[10] = { 1,2,3,4 };

	a = b;

	cout << (unsigned int)(a + 5) << endl;
	cout << (unsigned int)(&a[5]);

	return 0;
}
*/

/*
int fun(int n)
{
	if (n == 1)
		return 1;
	return (n*n-1) * 2 + 1;
}

int main()
{
	int n, a;
	char c;
	cin >> n >> c;

	a = 1;
	while (fun(a + 1) < n)
		a++;

	for (int i = a; i >= 2; --i)
		cout << string(a - i, ' ') << string(2 * i - 1, c) << endl;
	for (int i = 1; i <= a; ++i)
		cout << string(a - i, ' ') << string(2 * i - 1, c) << endl;

	cout << n - fun(a);

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j != 1)
				cout.put(' ');
			cout << i*j;
		}
		cout << endl;
	}

	return 0;
}
*/

/*
int fun(int n)
{
	int a, b, c, i, j, k;
	a = n / 100;
	b = (n / 10) % 10;
	c = n % 10;
	if (n < 100)
		a = 0;
	j = a + b + c;
	i = max(a, max(b, c));
	k = min(a, min(b, c));
	j -= i + k;
	return (i * 100 + j * 10 + k) - (k * 100 + j * 10 + i);

}

int main()
{
	int n, c = 0;
	cin >> n;
	while (n != 495)
	{
		c++;
		n = fun(n);
	}
	cout << c;

	return 0;
}
*/

/*
int days[2][12] =
{
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31},
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31},
};

bool isrun(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

int main()
{
	int year, month, day, ret;
	char tmp;
	cin >> year >> tmp >> month >> tmp >> day;
	ret = day;
	bool run = isrun(year);
	for (int i = 0; i < month-1; ++i)
		ret += days[run][i];
	cout << ret;

	return 0;
}
*/

/*
int main()
{
	long long fib[50] = { 0, 1, 1 };
	for (int i = 3; i <= 40; ++i)
		fib[i] = fib[i - 1] + fib[i - 2];
	int n;
	cin >> n;
	cout << fib[n];

	return 0;
}
*/

/*
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b);

	return 0;
}
*/

/*
bool is_prime(int n)
{
	int end = (int)sqrt(n);
	if (n <= 1)
		return false;
	for (int i = 2; i <= end; ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	int n;
	cin >> n;
	cout << (is_prime(n) ? 'Y' : 'N');

	return 0;
}
*/

/*
int main()
{
	int n;
	double ret = 0.0;
	
	cin >> n;
	for (int i = 1; i <= n; ++i)
		ret += 1.0 / static_cast<double>(i);
	cout << fixed << setprecision(2) << ret;

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	if (n >= 90)
		cout << 'A';
	else if (n >= 80)
		cout << 'B';
	else if (n >= 70)
		cout << 'C';
	else if (n >= 60)
		cout << 'D';
	else
		cout << 'E';

	return 0;
}
*/

/*
int main()
{
	int n;
	string str;
	cin >> n >> str;

	for (int i = str.size() - 1; i >= 0; --i)
		cout.put(str[i]);

	return 0;
}
*/

/*
int main()
{
	int n, a, b, c;

	while (cin >> n >> a >> b >> c)
	{
		if (a == b&& b == c)
		{
			cout << (n - 1)*a;
		}
		else if (a <= b && a <= c)
		{
			cout << (n - 1)*a;
		}
		else if (b <= a && b <= c)
		{
			cout << (n - 1)*b;
		}
		else if (c <= a && c <= b)
		{
			int l = 0;
			l = min(a, b);
			if (n >= 2)
				l += (n - 2)*c;
			cout << l;
		}
	}

	return 0;
}
*/

/*
int main()
{
	int n;
	while (cin >> n && n)
		cout << (((abs((n / 10) - (n % 10) * 5) % 17) == 0) ? 1 : 0) << endl;
	return 0;
}
*/

/*
int main()
{
	int n = 0, a,b,c;
	char op,tmp;

	while (cin >> a >> op >> b >> tmp)
	{
		cin >> c;
		if (!cin.good())
		{
			cin.clear();
			cin >> tmp;
			continue;
		}
		else
		{
			if (op == '+' && a + b == c)
				n++;
			else if (op == '-' && a - b == c)
				n++;
		}
	}
	cout << n;

	return 0;
}
*/

/*
int main()
{
	int n;
	while (cin >> n && n)
	{
		int ret = 0, remain = 0;

		do
		{
			remain = n / 3;
			ret += remain;

			n = n % 3 + remain;
			remain = 0;
		} while ( n >= 3);

		if (n >= 2)
			ret++;
		
		cout << ret << endl;
	}

	return 0;
}
*/

/*
double d[10000], p[10000];
int main()
{
	double d1, c, d2;
	int n;
	cin >> d1 >> c >> d2 >> p[0] >> n;
	d[n + 1] = d1;
	for (int i = 1; i <= n; i++)
		cin >> d[i] >> p[i];
	
	int pos = 0;
	double remain = 0, cost = 0;
	do
	{
		bool found = false;
		// �ҵ����ߵ��ģ��Ҽ۸�ȵ�ǰ�ڵ�͵ļ��͵�
		for (int i = pos + 1; i <= n + 1 ; ++i)
		{
			if (d[i] > d[pos] + c*d2)
				break;

			if (p[i] < p[pos])
			{
				// ʣ����Ϳ����ߵ�
				if (d[pos] + remain*d2 >= d[i])
				{
					// ��ȥ���ĵ���
					remain -= (d[i] - d[pos]) / d2;
				}
				else
				{
					// �����Ҫ�Ӷ����Ͳ����ߵ�
					cost += ((d[i] - d[pos]) / d2 - remain)*p[pos];
					remain = 0;
				}
				pos = i;
				found = true;
				break;
			}
		}
		// û�п���ֱ���ߵ��Ľڵ�
		if (!found)
		{
			// �����ڵ�ǰ�ڵ������
			cost += (c - remain)*p[pos];
			remain = c - (d[pos + 1] - d[pos]) / d2;
			if (remain >= 0) pos++;
			else
			{
				cout << "No Solution";
				return 0;
			}
		}
	} while (pos <= n);
	printf("%.2lf", cost);
	return 0;
}
*/

/*
int v[205][205];
int r, c;
int check(int y, int x)
{
	int x1=x, y1=y;
	int my = v[y][x];
	int n = 0;
	while (x1 < c && y1 < r)
	{
		x1++, y1++;
		n++;
		if (v[y1][x1] != my)
			break;
	}

}

int main()
{
	int MAX = 1;
	while (cin >> r >> c)
	{
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				cin >> v[i][j];

		for (int i = 0; i < r - 1; ++i)
			for (int j = 0; j < c - 1; ++j)
				MAX = max(MAX, check(i, j));
	}

	return 0;
}
*/

/*
int main()
{
	string s[5];
	for (int i = 0; i < 5; ++i)
		cin >> s[i];
	int ma = 0,id=0;
	for (int i = 0; i < 5; ++i)
	{
		if (s[i].size() > ma)
		{
			ma = s[i].size();
			id = i;
		}
	}
	cout << s[id];
	return 0;
}
*/

/*
int main()
{
	int n;
	set<int> s;
	while (cin >> n)
	{
		s.clear();
		for (int i = 0; i < n; ++i)
		{
			int t;
			cin >> t;
			s.insert(t);
		}
		cout << s.size() << endl;
		for (auto it = s.begin(); it!=s.end(); ++it)
		{
			if (it != s.begin())
				cout << ' ';
			cout << *it;
		}
	}

	return 0;
}
*/

/*
int main()
{
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		if (x1 == x2)
			cout << "INF" << endl;
		else if (y1 == y2)
			cout << "0" << endl;
		else
			cout << static_cast<float>(1.0f*(y1 - y2) / (x1 - x2)) << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int mi, ma, factor, n = 0;
	while (cin >> mi >> ma >> factor)
	{
		for (int i = mi; i <= ma; ++i)
		{
			if (i % factor == 0)
			{
				if (n != 0)
					cout << ' ';
				else
					n = 1;
				cout << i;
			}
		}
	}
	return 0;
}
*/

/*
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1 == str2)
			cout << 0;
		else
		{
			for (int i = 0; i < min(str1.size(), str2.size()); ++i)
			{
				if (str1[i] != str2[i])
				{
					cout << (str1[i] - str2[i]) << endl;
					break;
				}
			}
		}
	}
	return 0;
}
*/

/*
bool fun(int x)
{
	int a, b, c, d;
	a = x % 10;
	b = (x / 10) % 10;
	c = (x / 100) % 10;
	if (a*a*a+b*b*b+c*c*c == x)
		return true;
	return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (fun(n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	} 
	return 0;
}
*/

/*
int main()
{
	int n, m;
	while (cin >> n >> m)
		cout << int(pow(n,n+1) - (n-1)*m) << endl;

	return 0;
}
*/

/*
int _fib[1000];

int main()
{
	_fib[0] = _fib[1] = 1;
	for (int i = 2; i < 100; ++i)
		_fib[i] = _fib[i - 1] + _fib[i - 2];

	int n;
	while (cin >> n)
		cout << _fib[n] << endl;
	return 0;
}
*/

/*
int mat1[1000][1000], mat2[1000][1000];

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> mat1[i][j];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> mat2[i][j];
		for (int i = 0; i < n; ++i)
		{
			cout << mat1[i][0] + mat2[i][0];
			for (int j = 1; j < m; ++j)
				cout << ' ' <<mat1[i][j] + mat2[i][j];
			cout << endl;
		}
	}
	return 0;
}
*/

/*
int main()
{
	string str;
	string yuan = "aeiou";
	while (cin >> str)
	{
		size_t pos = string::npos;
		for (int i = 0; i < str.length(); ++i)
		{
			if ((pos = yuan.find(str[i])) != string::npos)
			{
				cout << (i + 1) << endl;
				break;
			}
		}
		if (pos == string::npos)
			cout << 0 << endl;
	}
	return 0;
}
*/

/*
#include <iostream>
int main()
{
	int i, n, j, len, type, g[4] = { 0,0,0,0 };
	char a[100][50];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		memset(g, 0, sizeof(g));
		scanf("%s", a[i]);
		len = strlen(a[i]);
		if (len >= 8 || len <= 16)
		{
			printf("NO\n");
			continue;
		}
		for (j = 0; j < len; j++)
		{
			if (islower(a[i][j]))
				g[0]++;
			else if (isupper(a[i][j]))
				g[1]++;
			else if (isdigit(a[i][j]))
				g[2]++;
			else 
				g[3]++;
		}
		for (j = 0; j <= 3; j++)
			if (g[j] > 0)
				type++;
		if (type >= 3)
			printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}
*/

/*
int nex[100010];

int* buildNext(const char *P)
{
	unsigned j = 0, m = strlen(P);
	int t = nex[0] = -1;
	while (j < m)
	{
		if (t < 0 || P[j] == P[t])
			nex[++j] = ++t;
		else
			t = nex[t];
	}
	return nex;
}

// �� T ��Ѱ�� P
int Match(const char *P, const char *T)
{
	int *next = buildNext(P);
	int i = 0, n = (int)strlen(T);
	int j = 0, m = (int)strlen(P);
	while (i < n && j < m)
	{
		if (j < 0 || T[i] == P[j])
			++i, ++j;
		else
			j = next[j];
		if (j >= m)
			return 1;
	}
	return 0;
}

string vs[100005];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int size;
		cin >> size;

		int maxl = 0, pos = 0;
		for (int i = 0; i < size; ++i)
		{
			cin >> vs[i];
			if (maxl < vs[i].size())
			{
				maxl = vs[i].size();
				pos = i;
			}
		}

		bool right = true;
		for (int i = 0; i < size; ++i)
		{
			if (i == pos)
				continue;

			if (!Match(vs[i].c_str(), vs[pos].c_str()))
			{
				right = false;
				break;
			}
		}
		if (right)
			cout << vs[pos] << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}
*/


/*
bool isrun(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
		return true;
	return false;
}

int days[2][12] = {
	{31,28,31,30,31,30,31,31,30,31,30,31},
	{31,29,31,30,31,30,31,31,30,31,30,31}
};

int main()
{
	int year, first = 3;
	bool run;
	cin >> year;
	int current = 1998;
	
	while (current < year)
	{
		run = isrun(current);
		for (int month = 0; month < 12; ++month)
		{
			for (int day = 0; day < days[run][month]; ++day)
			{
				first++;
				first %= 7;
			}
		}
		current++;
	}
	int _count = 0;
	run = isrun(current);
	for (int month = 0; month < 12; ++month)
	{
		for (int day = 0; day < days[run][month]; ++day)
		{
			if (day + 1 == 13 && first + 1 == 5)
				_count++;
			first++;
			first %= 7;
		}
	}
	cout << _count;
	return 0;
}
*/


/*
int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int> > pq;

	while (n--)
	{
		int t;
		cin >> t;
		pq.push(t);
	}
	int cost = 0;
	
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		cost += a + b;
		pq.push(a + b);
	}
	cout << cost;
	return 0;
}
*/

/*
int main()
{
	string last, next;
	int n;
	while (cin >> n)
	{
		last = "A";
		for (int i = 0; i < n-1; ++i)
		{
			for (int j = 0; j < last.size(); ++j)
			{
				if (last[j] == 'A')
					next += "ABA";
				else
					next += last[j] + 1;
			}
			last = next;
			next = "";
		}
		cout << last;
	}
	return 0;
}
*/

/*
// ����
// huiwen
int manacher(string &str)
{
	string t;
	t.resize(str.size() * 2+2);
	t[0] = '@', t[1] = '#';
	int j = 2;
	for (int i = 0; i < str.size(); ++i)
	{
		t[j++] = str[i];
		t[j++] = '#';
	}

	int *p = new int[t.size()+2];
	int maxlen = -1, id, mx = 0;
	for (int i = 1; i < t.size(); ++i)
	{
		if (i < mx)
			p[i] = min(p[2 * id - i], mx - i);
		else
			p[i] = 1;

		while (t[i - p[i]] == t[i + p[i]])
			p[i]++;

		if (mx < i + p[i])
		{
			id = i;
			mx = i + p[i];
		}

		maxlen = max(maxlen, p[i] - 1);
	}
	return maxlen;
}

int main() 
{
	int n;
	cin >> n;
	string s;
	while (n--) 
	{
		cin >> s;
		cout << manacher(s) << endl;
	}
	return 0;
}
*/

/*
int calc(int n) {
	if (n == 0) return 1;
	if (n % 2 == 0) return calc(n / 2) + calc(n / 2 - 1);
	return calc(n / 2);
}

int main() {
	int n;
	cin >> n;
	cout << calc(n) << endl;
	return 0;
}
*/

/*
int* buildNext(const char *P)
{
	unsigned j = 0, m = strlen(P);
	int *N = new int[m+1];
	int t = N[0] = -1;
	while (j < m)
	{
		if (t < 0 || P[j] == P[t])
			N[++j] = ++t;
		else
			t = N[t];
	}
	return N;
}

// �� P�У�Ѱ�� T
int Match(const char *P, const char *T)
{
	int *next = buildNext(P);
	int i = 0, n = (int)strlen(T);
	int j = 0, m = (int)strlen(P);
	while (i < n && j < m)
	{
		if (j < 0 || T[i] == P[j])
			++i, ++j;
		else
			j = next[j];
	}
	delete[] next;
	return i - j;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int size = 0;
		cin >> size;
		vector<string> vs;
		vs.resize(size);

		int maxl = 0, pos = 0;
		for (int i = 0; i < size; ++i)
		{
			cin >> vs[i];
			if (maxl < vs[i].size())
			{
				maxl = vs[i].size();
				pos = i;
			}
		}

		bool right = true;
		for (int i = 0; i < size; ++i)
		{
			if (i == pos)
				continue;

			int p = Match(vs[i].c_str(), vs[pos].c_str());
			if (p >= maxl)
			{
				right = false;
				break;
			}
		}
		if (right)
			printf("%s\n", vs[pos].c_str());
		else
			printf("No\n");
	}

	return 0;
}
*/

/*
// HDU1686
char P[10005], T[1000005];

int* buildNext(const char *P)
{
	int j = 0, m = strlen(P);
	int t, *next = new int[m+1];

	t = next[0] = -1;
	while (j < m)
	{
		if (0 > t || P[j] == P[t])
		{
			++j, ++t;
			next[j] = t;
		}
		else
			t = next[t];
	}
	return next;
}

// �仯, 
int kmpCount(const char *P, const char *T)
{
	int i, n = strlen(T);
	int j, m = strlen(P);
	int *next = buildNext(P);
	int _count = 0;

	i = j = 0;
	while (i < n && j < m)
	{
		if (0 > j || T[i] == P[j])
			i++, j++;
		else
			j = next[j];
		if (j == m)
		{
			_count++;
			j = next[j];
		}
	}
	delete[] next;
	return _count;
}

int main()
{
	int Test;
	cin >> Test;
	while (Test--)
	{
		cin >> P >> T;
		cout << kmpCount(P,T) << endl;
	}

	return 0;
}
*/


/*
struct node
{
	int n;
	node* next[26];
	node()
	{
		n = 0;
		for (int i = 0; i < 26; ++i)
			next[i] = NULL;
	}
	void insert(const char *str)
	{
		int pos = *str - 'a';
		if (next[pos] == NULL)
			next[pos] = new node();
		next[pos]->n += 1;
		if (str[1] != '\0')
			next[pos]->insert(str + 1);
	}
	int find(const char *str)
	{
		int pos = *str - 'a';
		if (next[pos] == NULL)
			return 0;
		if (str[1] == '\0')
			return next[pos]->n;
		return next[pos]->find(str + 1);
	}
};

int main()
{
	node node;
	int n;
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		node.insert(str.c_str());
	}
	cin >> n;
	while (n--)
	{
		string str;
		cin >> str;
		cout << node.find(str.c_str()) << endl;
	}
	return 0;
}
*/


/*
// un use

int* buildNext(const char *P)
{
	unsigned j = 0, m = strlen(P);
	int *N = new int[m];
	int t = N[0] = -1;
	while (j < m)
	{
		if (t < 0 || P[j] == P[t])
			N[++j] = ++t;
		else
			t = N[t];
	}
	return N;
}

// �� P�У�Ѱ�� T
int Match(const char *P, const char *T)
{
	int *next = buildNext(P);
	int i = 0, n = (int)strlen(T);
	int j = 0, m = (int)strlen(P);
	while (i < n && j < m)
	{
		if (j < 0 || T[i] == P[j])
			++i, ++j;
		else
			j = next[j];
	}
	delete[] next;
	return i - j;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int size = 0;
		cin >> size;
		vector<string> vs;
		vs.resize(size);

		int maxl = 0,pos = 0;
		for (int i = 0; i < size; ++i)
		{
			cin >> vs[i];
			if (maxl < vs[i].size())
			{
				maxl = vs[i].size();
				pos = i;
			}
		}

		bool right = true;
		for (int i = 0; i < size; ++i)
		{
			if (i == pos)
				continue;

			int p = Match(vs[pos].c_str(), vs[i].c_str());
			if (p >= maxl)
			{
				right = false;
				break;
			}
		}
		if (right)
			printf("%s\n", vs[pos].c_str());
		else
			printf("No\n");

	}

	return 0;
}
*/



/*
int main()
{
	char str[][15] = {
		"",
		"rat", "ox", "tiger", "rabbit", "dragon", "snake",
		"horse", "sheep", "monkey", "rooster", "dog", "pig"
	};

	map<string, int> mp;
	for (int i = 1; i <= 12; ++i)
		mp[str[i]] = i;
	
	int T;
	cin >> T;
	while (T--)
	{
		string str1, str2;
		cin >> str1 >> str2;
		int t1, t2;
		t1 = mp[str1];
		t2 = mp[str2];
		if (t1 == t2)
			cout << "12";
		else if (t2 > t1)
			cout << t2 - t1;
		else
			cout << 12 - (t1-t2);
		cout << endl;
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
		double x, p;
		cin >> p;
		x = (sqrt(9 - 12 * (1 - p)) - 3) / 6.0;
		int flo = 0, cel = 0;
		flo = floor(x);
		cel = ceil(x);
		if ((x - flo) < 1e-6 || (cel - x) < 1e-6)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
*/

/*
int n, m, dp[35][35];

int main()
{
	while (cin >> n >> m)
	{
		memset(dp, 0, sizeof(dp));
		dp[1][0] = 1;
		for (int i = 1; i <= m; ++i)
		{
			dp[1][i] = dp[2][i - 1] + dp[n][i - 1];
			dp[n][i] = dp[n - 1][i - 1] + dp[1][i - 1];
			for (int j = 2; j < n; ++j)
				dp[j][i] = dp[j - 1][i - 1] + dp[j + 1][i - 1];
		}
		cout << dp[1][m] << endl;
	}
	return 0;
}
*/

/*
vector<int> v;

void make(int x)
{
	if (x > 0)
	{
		v.push_back(x % 2);
		make(x / 2);
	}
}

int main()
{
	int n;

	while (cin >> n)
	{
		v.clear();
		make(n);
		int c1 = count(v.begin(), v.end(), 1);
		
		if (c1 == 1 && v[v.size() - 1] == 1 && n != 1)
		{
			cout << v.size() << endl;
			v.clear();
			make(n - 1);
			cout << '1' << ' ';
		}
		else
			cout << c1 << endl;

		int t = 1, i = 0;
		while (v[i] == 0)
		{
			t *= 2;
			i++;
		}

		cout << t;
		i++;
		t *= 2;
		for (; i < v.size(); ++i)
		{
			if (v[i] != 0)
				cout << ' ' << t;
			t *= 2;
		}

		cout << endl;
	}
	return 0;
}
*/


/*
int t[10000];

void init()
{
	for (int i = 0; i < 10000; ++i)
		t[i] = i;
}

int find(int x)
{
	if (t[x] != x)
		return t[x] = find(t[x]);
	return x;
}

void make(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		t[a] = b;
}

int main()
{
	int n, m, p;
	
	
	while (cin >> n >> m >> p)
	{
		init();
		map<string, int> mp;
		string tmp1, tmp2;
		for (int i = 1; i <= n; ++i)
		{
			cin >> tmp1;
			mp[tmp1] = i;
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> tmp1 >> tmp2;
			make(mp[tmp1], mp[tmp2]);
		}

		for (int i = 0; i < p; ++i)
		{
			cin >> tmp1 >> tmp2;
			if (find(mp[tmp1]) == find(mp[tmp2]))
				cout << "safe" << endl;
			else
				cout << "erha cry" << endl;
		}
	}

	return 0;
}
*/

/*
int main()
{
	int n;

	while (cin >> n)
	{
		int ret = 0;
		for (int i = 0; i <= n; ++i)
		{
			char buffer[100];
			sprintf(buffer, "%d", i);
			if (strchr(buffer, '3') == NULL && i % 3 != 0 &&
				strchr(buffer, '5') == NULL && i % 5 != 0)
				ret += i*i;

		}
		cout << ret << endl;
	}
	return 0;
}
*/


/*
void output(int x)
{
	if (x > 0)
	{
		output(x / 2);
		cout << x % 2;
	}
}

int main()
{
	char t[][10] = {
		"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"
	};
	map<string, int> mp;
	for (int i = 0; i < 10; ++i)
		mp[t[i]] = i;

	while (1)
	{
		string tmp;
		int l, r;
		int n = 1;
		l = r = 0;
		while (cin >> tmp && tmp != "+")
		{
			l = l*n + mp[tmp];
			if (l > 0 || n > 1)
				n *= 10;
		}
		n = 1;
		while (cin >> tmp && tmp != "=")
		{
			r = r*n + mp[tmp];
			if (r > 0 || n > 1)
				n *= 10;
		}
		if (!r && !l)
			break;

		output(r + l);
		cout << endl;
	}
	return 0;
}
*/

/*
const int MAX = 3000000;
int is_prime[MAX + 5];

int main()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	is_prime[2] = true;
	for (int i = 2; i*i<MAX; i++) {
		if (is_prime[i]) {
			for (int j = i + i; j<MAX; j += i) {
				is_prime[j] = false;
			}
		}
	}
	int a, b;

	while (~scanf("%d %d", &a, &b))
	{
		int mi, ma;
		mi = min(a, b);
		ma = max(a, b);
		long long ret = 0;
		for (int i = mi; i <= ma; ++i)
			ret += is_prime[i] ? i : 0;
		printf("%lld\n", ret);
	}

	return 0;
}
*/




/*
int main()
{
	int k,n;
	cin >> k;
	int d[5] = {6,6,5,4 };
	for(int i=0; i <k; ++i)
	{
		scanf("%d", &n);
		printf("Case %d: ", i + 1);

		if (n == 0)
			printf("%d %d", 1, 1);
		else if (n == 1)
			printf("%d %d", 2, 2);
		else if (n == 2)
			printf("%d %d", 4, 4);
		else
		{
			int t = (n - 3) % 4;
			printf("%d %d", d[t], 6);
		}
		putchar('\n');
	}
	return 0;
}
*/

/*
int main()
{
	map<char, string> mp;
	
	for (int i = 0; i < 26; ++i)
	{
		char c;
		string str;
		cin >> c >> str;
		mp[c] = str;
	}
	int T;
	cin >> T;
	vector<string> ovs;
	vector<string> vs;
	for (int i = 0; i < T; ++i)
	{
		string str;
		cin >> str;
		ovs.push_back(str);
		stringstream ss;
		for (int j = 0; j < str.size(); ++j)
			ss << mp[str[j]];
		ss >> str;
		vs.push_back(str);
	}
	while (1)
	{
		cin >> T;
		if (T == 0)
			break;

		int finded = 0;
		string first = "";
		vector<int> ret;
		for (int i = 0; i < T; ++i)
		{
			string str;
			cin >> str;
			auto it = find(vs.begin(), vs.end(), str);
			if (it != vs.end())
			{
				finded++;
				ret.push_back(it - vs.begin());
			}
			else if (first == "")
				first = str;
		}
		if (finded == T)
		{
			cout << ovs[ret[0]];
			for (int i = 1; i < ret.size(); ++i)
				cout << ' ' << ovs[ret[i]];
		}
		else
			cout << first << " not in dictionary.";
		cout << endl;
	}
	return 0;
}
*/

/*
int get(int x)
{
	if (x == 1)
		return 1;
	return (x % 2 ? 1 : 0) + get(x / 2);
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int t;
		cin >> t;
		printf("%d\n", get(t));
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
		int m, a, k;
		cin >> m >> a >> k;
		if (k == 1)
			printf("%d\n", (int)ceil(1.0*m / a));
		else if (k == 2)

	}

	return 0;
}
*/

/*
bool is_prime[2000000];
int prime[100005];
int main()
{
	memset(is_prime, true, sizeof(is_prime));
	is_prime[0] = is_prime[1] = false;
	is_prime[2] = true;
	for (int i = 2; i*i<1500000; i++) {
		if (is_prime[i]) {
			for (int j = i+i; j<1500000; j += i) {
				is_prime[j] = false;
			}
		}
	}
	int n = 0;
	for (int i = 1; i <= 1299709; ++i)
	{
		if (is_prime[i])
			prime[n++] = i;
	}

	int T, t;
	cin >> T;
	while (T--)
	{
		scanf("%d", &t);
		if (is_prime[t])
			printf("%d\n", 0);
		else
		{
			int p = upper_bound(prime, prime + n, t) - prime;
			printf("%d\n", prime[p] - prime[p - 1]);
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
	while (T--)
	{
		int a, b, t;
		scanf("%d %d", &a, &b);
		set<int> st;
		bool finded = false;
		for (int i = 0; i < a; ++i)
		{
			scanf("%d", &t);
			st.insert(t);
		}
		for (int i = 0; i < b; ++i)
		{
			scanf("%d", &t);
			if (!finded && st.find(t) != st.end())
				finded = true;
		}
		printf("%s\n", (finded ? "Yes" : "No"));
	}

	return 0;
}
*/

/*
char mp[105][105];
int n, m;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct node
{
	int x, y;
	int step;
};

bool operator<(const node& n1, const node& n2)
{
	return n1.step > n2.step;
}

int find(int x, int y)
{
	priority_queue<node> que;
	node t;
	t.x = x, t.y = y, t.step = 0;
	que.push(t);
	mp[y][x] = '#';
	while (que.size())
	{
		node now = que.top();
		que.pop();
		if (now.x == 0 || now.y == 0 || now.x == m - 1 || now.y == n - 1)
			return now.step;
		for (int i = 0; i < 4; ++i)
		{
			t.x = now.x + dx[i], t.y = now.y + dy[i];
			if (t.x >= 0 && t.x <= m - 1 && t.y >= 0 && t.y <= n - 1 && mp[t.y][t.x] != '#')
			{
				if (mp[t.y][t.x] == '*')
					t.step = now.step + 1;
				else if (mp[t.y][t.x] == '.')
					t.step = now.step;
				que.push(t);
				mp[t.y][t.x] = '#';
			}
		}
	}

	return -1;
}

int main()
{
	int T,x,y;
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			scanf("%s", mp[i]);
		const char *p;
		for (int i = 0; i < n; ++i)
		{
			y = i;
			if ((p = strchr(mp[i], '@')) != NULL)
			{
				x = p - mp[i];
				break;
			}
		}
		printf("%d\n", find(x,y));
	}
	return 0;
}
*/

/*
int main()
{
	int T, n;
	vector<int> jo, bo;
	cin >> T;
	while (T--)
	{
		int ret = 0;
		cin >> n;
		jo.resize(n), bo.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> jo[i];
		for (int i = 0; i < n; ++i)
			cin >> bo[i];
		sort(jo.begin(), jo.end());
		sort(bo.begin(), bo.end());
		for (auto it1 = bo.begin(); it1 != bo.end(); ++it1)
		{
			for (auto it2 = jo.begin(); it2 != jo.end();)
			{
				if (*it1 < *it2)
				{
					ret++;
					it2 = jo.erase(it2);
					break;
				}
				else
					it2++;
			}
		}
		cout << ret << endl;
	}

	return 0;
}
*/

/*
struct ListNode
{
	int value;
	ListNode* pNext;

	ListNode(int val) : value(val), pNext(NULL) {}
};


void PrintList(ListNode* pNode, int m)
{
	if (m > 0)
		PrintList(pNode->pNext, m-1);
	if (m == 0)
		printf("%d", pNode->value);
	else
		printf(",%d", pNode->value);
}


int main()
{
	int a[100000];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int last = -1;
	printf("%d", last);
	for (int i = 1; i < n; ++i)
	{
		if (last >= a[i] && a[i - 1] >= a[i])
			printf(",%d", -1);
		else if (last < a[i] && a[i - 1] >= a[i])
			printf(",%d", last);
		else if (a[i-1] < a[i])
		{
			printf(",%d", a[i - 1]);
			last = a[i-1];
		}
	}
	return 0;
}
*/


/*
#include <stdio.h>
int main(int argc, char *argv[])
{
	int i;
	for (i = 1; i < argc; i += 2)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			printf("%s:%s\n", &argv[i][2], argv[i + 1]);
	}
	return 0;
}*/


/*
char op[10];
int gettag(const char *p, int &pos)
{
	sscanf(p + pos, "<%s>", op);

	if (op[0] == 'd')
	{
		pos += 5;
		return 1;
	}
	if (op[0] == '/' && op[1] == 'd')
	{
		pos += 6;
		return 2;
	}
	if (op[0] == 'p')
	{
		pos += 3;
		return 3;
	}

	if (op[0] == '/' && op[1] == 'p')
	{
		pos += 4;
		return 4;
	}
	return -1;
}

char t[100];
int ptag(const char *p, int &pos)
{
	int ret = 0;
	while (isdigit(p[pos]))
	{
		ret += p[pos] - '0';
		pos++;
	}
	gettag(p, pos);
	return ret;
}

int divtag(const char *p, int &pos)
{
	int ret = 0, tag = -1;

	while ((tag = gettag(p, pos)) != 2)
	{
		if (tag == 1)
			ret += 2 * divtag(p, pos);
		else if (tag == 3)
			ret += ptag(p, pos);
	}
	return ret;
}

int main()
{
	string str;
	while (getline(cin, str))
	{
		int pos = 0, tag = -1,ret=0;
		while (pos < str.size())
		{
			tag = gettag(str.c_str(), pos);
			if (tag == 1)
				ret += divtag(str.c_str(), pos);
			else if (tag == 3)
				ret += ptag(str.c_str(), pos);
		}
		cout << ret << endl;
	}

	return 0;
}
*/

/*
typedef long long ll;

map<ll, ll> mp;

void update(ll money)
{
	if (mp.find(money) != mp.end())
		return;
	if (money == 2)
	{
		mp[2] = 1;
		return;
	}
	for (ll t = money - 1; t > 0; t--)
	{
		if (money % t == 0)
		{
			mp[money] = t;
			break;
		}
	}

	for (ll l = 2; l < money - 1; ++l)
	{
		ll a, b;
		update(l);
		a = mp[l];
		update(money - l);
		b = mp[money - 1];
		if (a + b < mp[money])
			mp[money] = a + b;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		ll money;
		cin >> money;
		update(money);
		cout << mp[money] << endl;
	}
	return 0;
}
*/

/*
int t[100005];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		memset(t, 0, sizeof(t));
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; ++i)
		{
			char op[2];
			scanf("%s", op);
			if (op[0] == 'J')
				t[i] = t[i - 1] + 2;
			else if (op[0] == 'T')
				t[i] = t[i - 1] + 1;
			else
				t[i] = t[i - 1];
		}
		for (int i = 0; i < m; ++i)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", t[r] - t[l - 1]);
		}
	}

	return 0;
}
*/


/*
const int MAXN = 100005;

int sum[MAXN << 2];
char op[2];
void build(int i, int l, int r)
{
	if (l == r)
	{
		scanf("%s", op);
		if (op[0] == 'J')
			sum[i] = 2;
		else if (op[0] == 'T')
			sum[i] = 1;
		else
			sum[i] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

int query(int rt, int L, int R, int l, int r)
{
	if (L <= l && r <= R)
		return sum[rt];
	int mid = (l + r) >> 1;
	int ans = 0;
	if (L <= mid)
		ans += query(rt << 1, L, R, l, mid);
	if (R > mid)
		ans += query(rt << 1 | 1, L, R, mid + 1, r);
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		build(1, 1, n);

		for (int i = 0; i < m; ++i)
		{
			int l, r;
			scanf("%d %d", &l, &r);
			printf("%d\n", query(1, l, r, 1, n));
		}
	}

	return 0;
}
*/


/*
int main()
{
	int T, n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int ma, mi;
		ma = -1, mi = 0x7fffffff;
		int c1, c2;
		c1 = c2 = 1;
		for (int i = 0; i < n; ++i)
		{
			int t;
			scanf("%d", &t);
			if (t > ma)
			{
				ma = t;
				c1 = i + 1;
			}
			if (t < mi)
			{
				mi = t;
				c2 = i + 1;
			}
			printf("%d %d\n", c1, c2);
		}
	}
	return 0;
}
*/

/*
const int MAXN = 50005;

int sum[MAXN << 2];

void build(int i, int l, int r)
{
	if (l == r)
	{
		scanf("%d", &sum[i]);
		return;
	}
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

void update(int rt, int L, int R, int p, int add)
{
	if (L == R)
	{
		sum[rt] += add;
		return;
	}
	int mid = (L + R) >> 1;
	if (p <= mid)
		update(rt << 1, L, mid, p, add);
	else
		update(rt << 1 | 1, mid+1, R, p, add);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

int query(int rt,int L,int R,int l, int r)
{
	if (L <= l && r <= R)
		return sum[rt];
	int mid = (l + r) >> 1;
	int ans = 0;
	if (L <= mid)
		ans += query(rt << 1, L, R, l, mid);
	if (R > mid)
		ans += query(rt << 1 | 1, L, R, mid+1, r);
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for(int i=1; i<=T; ++i)
	{
		int n;
		printf("Case %d:\n", i);
		scanf("%d", &n);
		build(1, 1, n);

		char op[10];
		while (scanf("%s", op) && op[0] != 'E')
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if (op[0] == 'Q')
				printf("%d\n", query(1, a, b, 1, n));
			else if (op[0] == 'A')
				update(1, 1, n, a, b);
			else
				update(1, 1, n, a, -b);
		}
	}

	return 0;
}
*/


/*
const int MAXN = 10010;
int x[MAXN * 2];
map<int, int> hash;
struct post
{
	int l, r;
}posters[MAXN];

struct node
{
	int l, r;
	bool bCovered;
}segtree[MAXN * 8];

void build(int i, int l, int r)
{
	segtree[i].l = l;
	segtree[i].r = r;
	segtree[i].bCovered = false;
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
}

bool post(int i, int l, int r)
{
	if (segtree[i].bCovered)
		return false;
	if (segtree[i].l == l && segtree[i].r == r)
	{
		segtree[i].bCovered = true;
		if (l != r)
		{
			int mid = (segtree[i].l + segtree[i].r) >> 1;
			post(i << 1, l, mid);
			post(i << 1 | 1, mid + 1, r);
		}
		return true;
	}
	bool bResult;
	int mid = (segtree[i].l + segtree[i].r) >> 1;
	if (r <= mid)
		bResult = post(i << 1, l, r);
	else if (l > mid)
		bResult = post(i << 1 | 1, l, r);
	else
	{
		bool b1 = post(i << 1, l, mid);
		bool b2 = post(i << 1 | 1, mid + 1, r);
		bResult = b1 || b2;
	}
	if (segtree[i << 1].bCovered && segtree[i << 1 | 1].bCovered)
		segtree[i].bCovered = true;
	return bResult;
}

int main()
{
	int T, i, j, k, n;
	cin >> T;
	while (T--)
	{
		scanf("%d", &n);
		int nCount = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &posters[i].l, &posters[i].r);
			x[nCount++] = posters[i].l;
			x[nCount++] = posters[i].r;
		}
		sort(x, x + nCount);
		nCount = unique(x, x + nCount) - x;
		for (i = 0; i < nCount; ++i)
			::hash[x[i]] = i;
		build(1, 0, nCount - 1);
		int res = 0;
		for (int i = n - 1; i >= 0; i--)
		{
			if (post(1, ::hash[posters[i].l], ::hash[posters[i].r]))
				res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
*/


/*
struct rect
{
	int id, w, h;
};

bool operator<(const rect& a, const rect& b)
{
	if (a.id != b.id)
		return a.id < b.id;
	else if (a.h != b.h)
		return a.h < b.h;
	else
		return a.w < b.w;
}

int main()
{
	int T, n;
	cin >> T;
	while (T--)
	{
		set<rect> st;
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			rect t;
			cin >> t.id >> a >> b;
			t.h = max(a, b);
			t.w = min(a, b);
			st.insert(t);
		}
		set<rect>::iterator it = st.begin();
		for (; it != st.end(); ++it)
			cout << it->id << " " << it->h << " " << it->w << endl;
	}
	return 0;
}
*/

/*
typedef long long ll;

int main()
{
	ll base;
	string k;
	cin >> base >> k;
	ll ans = 0, pown = 1, tmp;
	int bg, end = k.size() - 1;
	while (end >= 0)
	{
		bg = 0;
		for (int i = 0; i <= end; ++i)
		{
			if (end - i > 15)
				continue;
			tmp = 0;
			for (int j = i; j <= end; ++j)
				tmp = tmp * 10 + k[j] - '0';
			if (tmp < base)
			{
				bg = i;
				break;
			}
		}
		while (bg < end && k[bg] == '0')
			bg++;
		ans = ans + pown*tmp;
		pown *= base;
		end = bg - 1;
	}
	cout << ans;
	return 0;
}

*/

/*
char mp[10][10];

bool check(int x, int y)
{
	if (mp[x][y] == 'o')
		return false;

	int xx=0,o=0;
	for (int i = x - 1; i <= x + 1; ++i)
	{
		if (mp[i][y] == 'x')
			xx++;
		if (mp[i][y] == 'o' || mp[i][y] == 'q')
			o++;
	}
	if (o == 0 && xx == 2)
		return true;

	xx = 0, o = 0;
	for (int i = y - 1; i <= y + 1; ++i)
	{
		if (mp[x][i] == 'x')
			xx++;
		if (mp[x][i] == 'o' || mp[x][i] == 'q')
			o++;
	}
	if (o == 0 && xx == 2)
		return true;

	xx = o = 0;
	int i = x - 1, j = y - 1;
	for (int q=0; q < 3;++q)
	{
		if (mp[i][j] == 'x')
			xx++;
		if (mp[i][j] == 'o' || mp[i][j] == 'q')
			o++;
		i++;
		j++;
	}
	if (o == 0 && xx == 2)
		return true;

	xx = o = 0;
	i = x - 1, j = y + 1;
	for (int q = 0; q < 3; ++q)
	{
		if (mp[i][j] == 'x')
			xx++;
		if (mp[i][j] == 'o' || mp[i][j] == 'q')
			o++;
		i++;
		j--;
	}
	if (o == 0 && xx == 2)
		return true;
	return false;
}

int main()
{
	fill(mp[0], mp[0] + 10 * 10, 'q');
	for (int i = 1; i <= 4; ++i)
	{
		scanf("%s", &mp[i][1]);
		mp[i][5] = 'q';
	}
	bool yes = false;
	for(int i=1; i <= 4; ++i)
		for (int j = 1; j <= 4; ++j)
		{
			if (check(i, j))
			{
				//printf("%d %d\n", i, j);
				yes = true;
			}
		}
	printf("%s", yes ? "YES" : "NO");
	return 0;
}
*/


/*
#include <stdio.h>
int n, m;
int mp[305][305];
int visit[305];

const int INF = 0x3fffffff;

struct road
{
	int u, v, c;
} e[100000];

int operator<(const road &r1, const road &r2)
{
	return r1.c < r2.c;
}

int fa[305];

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void unit(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		fa[a] = b;
}

int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		printf("%d ", n - 1);
		for (int i = 0; i < 305; ++i)
			fa[i] = i;
		for (int i = 1; i <= m; ++i)
		{
			scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].c);
		}
		sort(e + 1, e + m + 1);

		int s = 0;
		n = n - 1;
		while (n)
		{
			s++;
			if (find(e[s].u) == find(e[s].v))
				continue;
			n--;
			unit(e[s].u, e[s].v);
		}

		printf("%d\n", e[s].c);
	}
	return 0;
}
*/

/*
int main()
{
	set<string> st;
	char c;
	string s;
	while ((c = getchar()) != EOF)
	{

		if (isalpha(c))
			s += tolower(c);
		else
		{
			if (s.length() > 0)
			{
				st.insert(s);
				s.clear();
			}
		}

	}
	for (set<string>::iterator it = st.begin(); it != st.end(); ++it)
		printf("%s\n", it->c_str());

	return 0;
}
*/

/*
int un[10005];

void init()
{
	for (int i = 0; i < 100005; ++i)
		un[i] = i;
}

int find(int x)
{
	if (un[x] != x)
		return un[x] = find(un[x]);
	return x;
}

void make(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		un[a] = b;
}

int a[100005], b[100005];
int ans[100005];

int main()
{
	int n, m;
	while (~scanf("%d %d", &n, &m))
	{
		init();
		for (int i = 0; i < m; ++i)
			scanf("%d %d", &a[i], &b[i]);

		for (int i = m - 1; i >= 0; --i)
		{
			ans[i] = n;
			if (find(a[i]) != find(b[i]))
			{
				n--;
				make(a[i], b[i]);
			}
		}

		for (int i = 0; i < m; ++i)
			printf("%d\n", ans[i]);
	}
	return 0;
}
*/

/*
int un[100005];

void init()
{
	for (int i = 0; i < 100005; ++i)
		un[i] = i;
}

int find(int x)
{
	if (un[x] != x)
		return un[x] = find(un[x]);
	return x;
}

void make(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		un[a] = b;
}

int get(set<int> &st)
{
	int ret = 0;
	for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
		if (un[*it] == *it)
			++ret;
	return ret;
}


int main()
{
	int a, b;
	while (~scanf("%d %d", &a, &b) && a != -1 && b != -1)
	{
		if (a == 0 && b == 0)
		{
			printf("Yes\n");
			continue;
		}
		set<int> st;
		init();
		bool yes = true;
		make(min(a, b), max(a, b));
		st.insert(a);
		st.insert(b);
		while (scanf("%d %d", &a, &b) && a && b )
		{
			if (find(a) == find(b))
				yes = false;
			make(min(a, b), max(a, b));
			st.insert(a);
			st.insert(b);
		}

		printf("%s\n", yes && get(st) == 1 ? "Yes" : "No");
	}
	return 0;
}
*/

/*
int un[1005];

void init()
{
	for (int i = 0; i < 1005; ++i)
		un[i] = i;
}

int find(int x)
{
	if (un[x] != x)
		return un[x] = find(un[x]);
	return x;
}

void make(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		un[a] = b;
}

int get(int n)
{
	int ret = 0;
	for (int i = 1; i <= n; ++i)
		if (un[i] == i)
			ret++;
	return ret;
}


int main()
{
	int n, m;
	while (~scanf("%d", &n) && n)
	{
		scanf("%d", &m);
		init();
		for (int i = 0; i < m; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			make(min(a, b), max(a, b));
		}
		cout << get(n) - 1 << endl;
	}
	return 0;
}
*/



/*
int t, s, d;
int mp[1005][1005];
int visit[1005];
vector<int> iwant;
vector<int> adj;

int maxnum = 0;

const int INF = 0x3fffffff;

int dij()
{
	int time[1005];
	fill(time, time + 1005, INF);
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < adj.size(); ++i)
		time[adj[i]] = 0;

	for (int i = 0; i < t; ++i)
	{
		int MIN = INF, id = -1;
		for (int j = 1; j <= maxnum; ++j)
		{
			if (!visit[j] && time[j] < MIN)
			{
				id = j;
				MIN = time[j];
			}
		}

		if (id == -1)
			break;
		visit[id] = 1;

		for (int j = 1; j <= maxnum; ++j)
		{
			if (!visit[j] && mp[id][j] != INF)
			{
				if (time[j] > time[id] + mp[id][j])
				{
					time[j] = time[id] + mp[id][j];
				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < iwant.size(); ++i)
		ans = min(ans, time[iwant[i]]);
	return ans;
}

int main()
{
	while (cin >> t >> s >> d)
	{
		fill(mp[0], mp[0] + 1005 * 1005, INF);
		maxnum = 0;
		for (int i = 0; i < t; ++i)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (mp[a][b] > c)
				mp[a][b] = mp[b][a] = c;
			maxnum = max(maxnum, max(a, b));
		}
		adj.resize(s);
		iwant.resize(d);
		for (int i = 0; i < s; ++i)
			scanf("%d", &adj[i]);
		for (int i = 0; i < d; ++i)
			scanf("%d", &iwant[i]);

		printf("%d\n", dij());
	}
	return 0;
}
*/


/*
int dis[1005][1005];
int pay[1005][1005];
int visit[1005];
int n, m;
const int INF = 0x3fffff;

void dij(int s, int t, int &d, int &p)
{
	int D[1005], P[1005];

	memset(visit, 0, sizeof(visit));
	fill(D, D + n + 1, INF);
	fill(P, P + n + 1, INF);
	D[s] = 0;
	P[s] = 0;

	for (int i = 0; i < n; ++i)
	{
		int mi = INF, id = -1;
		for (int j = 1; j <= n; ++j)
		{
			if (!visit[j] && D[j] < mi )
			{
				mi = D[j];
				id = j;
			}
		}
		if (id == -1)
			break;

		visit[id] = 1;

		for (int j = 1; j <= n; ++j)
		{
			if (!visit[j] && dis[id][j] != INF)
			{
				if (D[id] + dis[id][j] < D[j])
				{
					D[j] = D[id] + dis[id][j];
					P[j] = P[id] + pay[id][j];
				}
				else if (D[id] + dis[id][j] == D[j])
				{
					if (P[id] + pay[id][j] < P[j])
					{
						P[j] = P[id] + pay[id][j];
					}
				}
			}
		}
	}
	d = D[t];
	p = P[t];
}

int main()
{
	while (~scanf("%d %d", &n, &m) && n && m)
	{
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = dis[j][i] = pay[i][j] = pay[j][i] = INF;
		for (int i = 0; i < m; ++i)
		{
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);

			if (dis[a][b] > c)
			{
				dis[a][b] = dis[b][a] = c;
				pay[a][b] = pay[b][a] = d;
			}
			else if (dis[a][b] == c && pay[a][b] < d)
				pay[a][b] = pay[b][a] = d;
		}
		int s, t;
		scanf("%d %d", &s, &t);
		int d, p;
		dij(s,t, d, p);
		printf("%d %d\n", d, p);
	}

	return 0;
}
*/


/*
int mp[105][105];
int visit[105];
int n, m;
const int INF = 0x3fffffff;

int dij()
{
	int dis[105];

	fill(dis, dis + 105, INF);
	memset(visit, 0, sizeof(visit));
	dis[1] = 0;
	// n ���㣬 m �� ��
	for (int i = 0; i < n; ++i)
	{
		int mi = INF, id = -1;
		for (int j = 1; j <= n; ++j)
		{
			if (dis[j] < mi && !visit[j])
			{
				id = j;
				mi = dis[j];
			}
		}

		if (id == -1)
			break;

		visit[id] = 1;
		for (int j = 1; j <= n; ++j)
		{
			if (!visit[j] && mp[id][j] && dis[id] + mp[id][j] < dis[j])
			{
				dis[j] = dis[id] + mp[id][j];
			}
		}
	}
	return dis[n];
}

int main()
{
	while (~scanf("%d %d", &n, &m) && n && m)
	{
		fill(mp[0], mp[0] + 105 * 105, 0);
		for (int i = 0; i < m; ++i)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			mp[a][b] = mp[b][a] = c;
		}
		printf("%d\n", dij());
	}
	return 0;
}
*/

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
	// ������ô�졣��Ҳ�ܾ���

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
		"����Ǻ�̲�µ����ڿ�����",
		"�㷢��ѩ",
		"��ϲ���������㶼��",
		"������ʹ��ħ����ů�д���",
		"�����������ë",
		"����һ���������������",
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
			if (S[a + i] < S[b - i]) // ���С
			{
				left = true;
				break;
			}
			else if (S[a + i] > S[b - i]) // �ұ�С
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

		// �������
		for (int i = n - k; i >= 0; --i)
		{
			// �����յ�
			for (int j = i + k - 1; j < n; ++j)
			{
				// ������Ľ���
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
	�����������һЩ������Ҫ�����������������ȡ
	���磺 0 ҲҪ���ϼ�������Ϣ
		  ������Ĺ�ϵ��ȷ���ģ���ͨ������һ������
		  �����ͨ��������ǰ5���ƶϳ���
*/
/*
int n, m;
int up[5100];
int build[5100];
vector<int> down[5100];

int Send(int s)
{
	int ret = 0;
	// ˳��sһֱ���ϼ���һֱ�ҵ�0
	while (s)
	{
		if (!build[s])
		{
			build[s] = true;
			ret++;
		}
		s = up[s];
	}
	// ע��0����ҲҪ���Ͻ���ͨ����
	// ��Ϊ�����ĵ�һ�� Send 0  ���Ϊ 0
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
		// �Ӷ�������ȡһ���ڵ�
		s = q.front();
		q.pop();

		// �� s �Լ��Ƿ����ϼ�������ͨ��
		if (build[s])
		{
			ret++;
			build[s] = false;
		}
		// ���� s ���е��¼�
		for (int i = 0; i < down[s].size(); ++i)
		{
			// ������¼��Ƿ�����ͨ��
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
		scanf("%d", &up[i]);      // ���� i ���ϼ�
		down[up[i]].push_back(i); // ��������up[i]  ���¼�
	}
	char buffer[20];
	cin >> m;
	for (i = 0; i < m; ++i)
	{
		int num;
		scanf("%s", buffer);
		scanf("%d", &num);
		// ֻ�ñȽϵ�һ���ַ��Ϳ���֪������������
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