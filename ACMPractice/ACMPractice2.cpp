
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

		// ÉÌ 
		// b Óë c Í¬½× 
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

// ½±ÅÆ°ñ

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
// dfs Á·Ï°
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