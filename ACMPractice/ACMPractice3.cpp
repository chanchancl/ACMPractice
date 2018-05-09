
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
using namespace std;


#define forin(i,s,n) for(int i=s; i < n; ++i)
#define forn(i,n) forin(i,0,n)

int n;
int a[2 * 100005];

int main()
{
	cin >> n;
	forn(i, n) cin >> a[i];

	map<int, int> mp;
	int end = -1, maxlen = -1;
	forn(i, n) {
		int now = a[i];
		mp[now] = mp[now - 1] + 1;
		if (mp[now] > maxlen) {
			end = i;
			maxlen = mp[now];
		}
	}
	cout << maxlen << endl;
	vector<int> v;
	int t = maxlen;
	v.push_back(end + 1);
	for (int i = end-1; i >= 0 && t; i--) {
		if (a[i] == a[v.back()-1] - 1){
			v.push_back(i+1);
			t--;
		}
	}
	auto ed = v.rbegin();
	cout << *(ed++);
	while (ed != v.rend()) cout << ' ' << *(ed++);

	return 0;
}



/*
int fa[2 * 100005];
int n, m;

void init() {
	forn(i, n) fa[i] = i;
}

int find(int x) {
	if (x != fa[x]) return fa[x] = find(fa[x]);
	return x;
}

void _union(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (a > b) fa[b] = a;
	else fa[a] = b;
}

int main()
{
	cin >> n >> m;
	vector<pair<int, int>> mp(m);
	vector<int> out(n+1);
	init();
	int ans = 0;
	forn(i, m) {
		cin >> mp[i].first >> mp[i].second;
		out[mp[i].first]++, out[mp[i].second]++;
	}
	forn(i, m) {
		if (out[mp[i].first] == 2 && out[mp[i].second] == 2) {
			if (find(mp[i].first) == find(mp[i].second)) ans++;
			else _union(mp[i].first, mp[i].second);
		}
	}
	cout << ans;

	return 0;
}
*/

/*
using ll = long long;
#define all(x) x.begin(),x.end()

int main()
{
	int n;
	cin >> n;
	vector<ll> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	ll start;
	sort(s.begin(), s.end(), greater<int>());
	start = s[0];

	bool flag = true;
	for(int i=0; i < n && flag; ++i) {
		flag = false;
		if (find(all(s),start*3) != s.end() ) {
			start *= 3;
			flag = true;
		}
		else if (find(all(s), start / 2) != s.end() && start % 2 == 0) {
			start /= 2;
			flag = true;
		}
	}
	cout << start;
	n -= 1;
	while (n--) {
		if (start % 3 == 0 && find(all(s), start /3) != s.end()) 
			start /= 3;
		else 
			start *= 2;
		cout << ' ' << start;
	}

	return 0;
}
*/

/*
int a[2 * 100005];
int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	if (k == 0)
	{
		if (a[0] == 1)
			cout << -1;
		else
			cout << a[0] - 1;
	}
	else
	{
		if (a[k - 1] == a[k])
			cout << -1;
		else
			cout << a[k - 1];
	}

	return 0;
}
*/

/*
int main()
{
	int mp[26][26];
	memset(mp, 0, sizeof mp);
	int n;
	char str[105];
	cin >> n >> str;

	for (int i = 0; i < n - 1; ++i) mp[str[i] - 'A'][str[i + 1] - 'A']++;

	int max;
	char ans1, ans2;
	max = -1;
	for (int i = 0; i < 26; ++i)
		for(int j=0; j < 26; ++j)
			if (mp[i][j] > max) {
				max = mp[i][j];
				ans1 = i + 'A';
				ans2 = j + 'A';
			}
	cout << ans1 << ans2;
	return 0;
}
*/

/*
int main()
{
	int n, k;
	cin >> n >> k;
	while (k--) {
		if (n % 10) n -= 1;
		else n /= 10;
	}
	cout << n << endl;

	return 0;
}
*/


/*
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

typedef struct student {
	unsigned m_id;
	string m_name;
	unsigned m_age;
	string m_sex;
	struct student *m_next;

	student() : m_next(NULL) {}

	void write(ofstream &ss)
	{
		ss << m_id << ' ' << m_name << ' ' << m_age << ' ' << m_sex << endl;
	}
	void read(ifstream &ss)
	{
		ss >> m_id >> m_name >> m_age >> m_sex;
		char s;
		ss.get(s);
		if (s != '\n')
			ss.putback(s);
	}
}student;

class CStudent {
private:
	student * head;
public:
	CStudent() {
		head = new student;
		head->m_id = 0;
		head->m_name = "noname";
		head->m_next = NULL;
	}
	~CStudent() {
		student *p = head, *q;
		while (p) {
			q = p;
			p = q->m_next;
			delete q;
		}
	}
	student readdata(int model); // model = 1:不读取学号，2:不读取姓名，其他，读取所有信息
	void entering();
	bool insert(const student &astu);
	student *findid(unsigned id) const;
	student *findname(const string &name) const;
	student *findsex(const string &sex) const;
	unsigned boys() const;
	unsigned girls() const;
	unsigned headcount() const;
	bool eraseid();
	bool erasename();
	bool modifyid();
	bool modifyname();
	void Show() const;
	void query() const;
	void friend statistics(const CStudent &aclss);
	void friend erase(CStudent &aclss);
	void friend modify(CStudent &aclss);

	void WriteToFile()
	{
		ofstream fs("students.txt");
		student *cur = head->m_next;
		while (cur)
		{
			cur->write(fs);
			cur = cur->m_next;
		}
	}

	void ReadFromFile()
	{
		ifstream fs("students.txt");
		if (!fs)
			return;

		fs.seekg(0, ios_base::end);
		size_t size = fs.tellg();
		if (size <= 1)
			return;

		fs.seekg(0);
		student tmp;
		while (fs.tellg() < size) {
			tmp.read(fs);
			insert(tmp);
		}

	}
};

string readstring() {
	string str;
	while (cin.get() != '\n');
	cin >> str;
	return str;
}

student CStudent::readdata(int model) {
	student tmp;
	if (model != 1) { cout << "学    号: "; cin >> tmp.m_id; }
	if (model != 2) { cout << "姓    名: "; tmp.m_name = readstring(); }
	cout << "年    龄: ";
	cin >> tmp.m_age;
	cout << "性    别: ";
	tmp.m_sex = readstring();
	return tmp;
}

void CStudent::entering() {
	student tmp;
	cout << "学号(0 to return): ";
	cin >> tmp.m_id;
	while (tmp.m_id) {
		if (findid(tmp.m_id) == NULL) {
			cout << "姓    名: ";
			tmp.m_name = readstring();
			cout << "年    龄: ";
			cin >> tmp.m_age;
			cout << "性    别: ";
			tmp.m_sex = readstring();
			insert(tmp);
		}
		else cout << "重复的学号:" << tmp.m_id << endl;
		cout << "学号(0 to return): ";
		cin >> tmp.m_id;
	}
}

student *CStudent::findid(unsigned id) const {
	student *p;
	for (p = head; p->m_next; p = p->m_next)
		if (p->m_next->m_id == id) return p;
	return NULL;
}

student *CStudent::findname(const string &name) const {
	student *p;
	for (p = head; p->m_next; p = p->m_next)
		if (p->m_next->m_name == name) return p;
	return NULL;
}


student *CStudent::findsex(const string &sex) const {
	student *p;
	for (p = head; p->m_next; p = p->m_next)
		if (p->m_next->m_sex == sex) return p;
	return NULL;
}

bool CStudent::insert(const student &astu) {
	student *newnode, *p = head;
	if (p->m_next == NULL) {
		p->m_next = new student(astu);
		p->m_next->m_next = NULL;
		return true;
	}
	while (p->m_next) {
		if (p->m_next->m_id == astu.m_id) {
			cout << "重复的学号，插入失败!\n";
			return false;
		}
		if (p->m_next->m_id > astu.m_id) {
			newnode = new student(astu);
			newnode->m_next = p->m_next;
			p->m_next = newnode;
			return true;
		}
		p = p->m_next;
	}
	p->m_next = new student(astu);
	p->m_next->m_next = NULL;
	return true;
}

unsigned  CStudent::boys() const {
	unsigned cnt = 0;
	student *p;
	for (p = head->m_next; p; p = p->m_next)
		if (p->m_sex == "男") ++cnt;
	return cnt;
}

unsigned CStudent::girls() const {
	unsigned cnt = 0;
	student *p;
	for (p = head->m_next; p; p = p->m_next)
		if (p->m_sex == "女") ++cnt;
	return cnt;
}

unsigned CStudent::headcount() const {
	unsigned cnt = 0;
	student *p;
	for (p = head->m_next; p; p = p->m_next, ++cnt);
	return cnt;
}

bool CStudent::eraseid() {
	student *q, *p;
	unsigned id;
	cout << "输入要删除的学号:";
	cin >> id;
	p = findid(id);
	if (p == NULL) {
		cout << "没有找到学号是\"" << id << "\"的学生，删除失败!\n";
		return false;
	}
	q = p->m_next;
	p->m_next = q->m_next;
	delete q;
	return true;
}
bool CStudent::erasename() {
	student *q, *p;
	string name;
	cout << "输入要删除人的姓名:";
	name = readstring();
	p = findname(name);
	if (p == NULL) {
		cout << "没有找到姓名是\"" << name << "\"的学生，删除失败!\n";
		return false;
	}
	q = p->m_next;
	p->m_next = q->m_next;
	delete q;
	return true;
}

bool CStudent::modifyid() {
	student tmp, *p;
	unsigned id;
	cout << "输入要修改的学号:";
	cin >> id;
	p = findid(id);
	if (p == NULL) {
		cout << "没有找到学号是\"" << id << "\"的学生，修改失败!\n";
		return false;
	}
	tmp = readdata(1);
	tmp.m_id = id;
	*(p->m_next) = tmp;
	return true;
}

bool CStudent::modifyname() {
	student *p, tmp;
	string name;
	cout << "输入要修改人的姓名:";
	name = readstring();
	p = findname(name);
	if (p == NULL) {
		cout << "没有找到姓名是\"" << name << "\"的学生，修改失败!\n";
		return false;
	}
	tmp = readdata(2);
	tmp.m_name = name;
	*(p->m_next) = tmp;
	return true;
}

int menu() {
	int choice;
	do {
		system("cls");
		cout << "\t****************************\n";
		cout << "\t*   学生基本信息管理系统   *\n";
		cout << "\t*==========================*\n";
		cout << "\t*    1、录入学生信息       *\n";
		cout << "\t*    2、显示学生信息       *\n";
		cout << "\t*    3、查询学生信息       *\n";
		cout << "\t*    4、添加学生信息       *\n";
		cout << "\t*    5、统计学生信息       *\n";
		cout << "\t*    6、删除学生信息       *\n";
		cout << "\t*    7、修改学生信息       *\n";
		cout << "\t*    0、退出管理系统       *\n";
		cout << "\t****************************\n";
		cout << "\n\t请选择:";
		cin >> choice;
	} while (choice < 0 || choice > 7);
	return choice;
}

void show(student *p) {
	cout << p->m_id << " " << p->m_name << " " << p->m_age << " ";
	cout << p->m_sex << " " << endl;
}

void CStudent::Show() const {
	student *p;
	cout << "----------------------------------------------------------\n";
	for (p = head->m_next; p; p = p->m_next) show(p);
	cout << "----------------------------------------------------------\n";
	system("pause");
}

void CStudent::query() const {
	int select;
	unsigned id;
	string name;
	student *p;
	cout << "1、按学号查询\n2、按姓名查询\n0、返回\n";
	cin >> select;
	switch (select) {
	case 1: cout << "请输入学号:"; cin >> id;
		if (p = findid(id)) show(p->m_next);
		break;
	case 2: cout << "请输入姓名:"; name = readstring();
		if (p = findname(name)) show(p->m_next);
		break;
	case 0: return;
	default: cout << "选择错误。\n";
	}
	system("pause");
}

void statistics(const CStudent &a) {
	unsigned total = a.headcount();
	unsigned boys = a.boys();
	unsigned girls = a.girls();
	cout << "学生总数:" << total << "人。\n";
	cout << "其中，男生:" << boys << "名。";
	cout << "女生:" << girls << "名。\n";
	system("pause");
}

void erase(CStudent &a) {
	int select;
	unsigned id;
	string name;
	student *p, *q;
	cout << "1、按学号删除\n2、按姓名删除\n0、返回\n";
	cin >> select;
	switch (select) {
	case 1: cout << "请输入学号:"; cin >> id;
		if (p = a.findid(id)) {
			q = p->m_next;
			p->m_next = q->m_next;
			delete q;
			cout << "成功删除 " << id << " 的信息。\n";
		}
		break;
	case 2: cout << "请输入姓名:"; name = readstring();
		if (p = a.findname(name)) {
			q = p->m_next;
			p->m_next = q->m_next;
			delete q;
			cout << "成功删除 " << name << " 的信息。\n";
		}
		break;
	case 0: return;
	default: cout << "选择错误。\n";
	}
	system("pause");
}

void modify(CStudent &a) {
	int select;
	cout << "1、按学号修改\n2、按姓名修改\n0、返回\n";
	cin >> select;
	switch (select) {
	case 1: if (a.modifyid()) cout << "修改成功。\n"; break;
	case 2: if (a.modifyname()) cout << "修改成功。\n"; break;
	case 0: return;
	default: cout << "选择错误。\n";
	}
	system("pause");
}

int main() {
	CStudent a;
	a.ReadFromFile();

	int an;
	do {
		an = menu();
		switch (an) {
		case 1: a.entering(); break;
		case 2: a.Show(); break;
		case 3: a.query(); break;
		case 4: a.entering(); break;
		case 5: statistics(a); break;
		case 6: erase(a); break;
		case 7: modify(a); break;
		case 0: break;
		default: cout << "选择错误。\n"; break;
		}
		a.WriteToFile();
	} while (an);
	a.WriteToFile();
	return 0;
}
*/



/*
#include <iostream>
using namespace std;

class IList;
class TList;
class node
{
	node *next;
	int value;
public:
	friend TList;
	node(int v, node* n=NULL) : value(v), next(n) {}
};

class IList
{
public:
	IList() {}
	IList(int values[]) {};

public:
	virtual void show() {};
	virtual void insert(IList *l) {};
	virtual void showreverse() {};
	virtual size_t size() { return 0; };
	virtual void clear() {};

	node *begin;
};

class TList : public IList
{
public:
	TList() { begin = NULL; }
	TList(int values[], int len)
	{
		begin = new node(values[0]);
		node *cur = begin;
		for (int i = 1; i < len; ++i) {
			cur->next = new node(values[i]);
			cur = cur->next;
		}
	}

	virtual void show()
	{
		cout << "{";
		node * cur = begin;
		if (cur)
		{
			while (true)
			{
				cout << cur->value;
				if (cur->next) {
					cout << ",";
					cur = cur->next;
				}
				else
					break;
			}
		}
		cout << "}" << endl;
	}

	virtual void insert(IList *l) 
	{
		node *end, *lnode;

		lnode = l->begin;
		if (!begin)
		{
			begin = new node(l->begin->value);
			lnode = l->begin->next;
		}
		end = begin;

		int lsize = l->size();
		while (end->next) end = end->next;
		while (lnode)
		{
			end->next = new node(lnode->value);
			end = end->next;
			lnode = lnode->next;
		}
	}

	virtual void append(int value)
	{
		node *end = begin;
		if (!begin)
			begin = new node(value);
		else 
		{
			while (end->next) end = end->next;
			end->next = new node(value);
		}
	}

	void showback(node *cur, bool first = false) 
	{
		if (!cur)
			return;
		if (cur->next)
			showback(cur->next);
		cout << cur->value;
		if (!first)
			cout << ",";
	}

	virtual void showreverse()
	{
		cout << "{";
		showback(begin, true);
		cout << "}" << endl;
	}

	virtual size_t size()
	{
		size_t ret = 0;
		node *cur = begin;
		while (cur) cur = cur->next, ret++;
		return ret;
	}

	virtual void clear()
	{
		node *last, *cur;
		last = cur = begin;
		cur = cur->next;
		while (cur) {
			delete last;
			last = cur;
			cur = cur->next;
		}
		if (last)
			delete last;
	}
};



int main()
{
	int elements[] = { 4, 1993, 33, 253, 545 };

	TList A, B(elements, 5), C;

	C.append(1);
	C.append(2);
	C.append(3);

	cout << "表A的长度:" << A.size() << ", 内容 : ";
	A.show();

	cout << "表B的长度:" << B.size() << ", 内容 : ";;
	B.show();

	cout << "表C的长度:" << C.size() << ", 内容 : ";;
	C.show();

	cout << "B的内容添加到表A中 : ";
	A.insert(&B);
	A.show();
	cout << "倒序查看A : ";
	A.showreverse();
	cout << "表A的长度为 : " << A.size() << endl;

	cout << "将C中的元素添加到表A 中 : ";
	A.insert(&C);
	A.show();
	cout << "倒序查看A : ";
	A.showreverse();
	cout << "表A的长度为 : " << A.size() << endl;

	A.clear();
	B.clear();
	C.clear();

	return 0;
}
*/

/*
int dp[55][5005];
int a[55];
int main()
{
	int sum = 0, n;
	cin >> n;

	int mi = 1000000;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
		mi = min(mi, a[i]);
	}
	if (sum % 2) {
		cout << 0 << endl;
		return 0;
	}
	else {
		for (int i = 0; i <= n; ++i)
			dp[i][0] = 1;
		for (int i=1; i <= n; ++i) // 遍历所有物品
			for (int j = mi; j <= sum / 2; ++j) {
				if (a[i] > j)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
			}
		cout << dp[n][sum / 2] / 2 << endl;
	}

	return 0;
}
*/

/*
const int N = 55;
double dis[N][N];
double d[N];
bool visit[N];
struct point {
	double x, y, z;
}p[N];

double distance(point &a, point &b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> p[i].x >> p[i].y >> p[i].z;

		for(int i=0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				dis[i][j] = dis[j][i] = distance(p[i], p[j]);

		memset(visit, 0, sizeof visit);
		fill(d, d + N, 1e10);

		d[0] = 0;
		double ans = 0;
		for(int t=0; t < n; ++t) {

			int id = -1;
			double Min = 1e10;
			for (int i = 0; i < n; ++i) {
				if (!visit[i] && d[i] < Min) {
					Min = d[i];
					id = i;
				}
			}
			if (id == -1)
				break;
			
			for (int i = 0; i < n; ++i)
				if (!visit[i] && dis[id][i] < d[i])
					d[i] = dis[id][i];

			ans += Min;
			visit[id] = true;
		}
		printf("%.2lf\n", ans);
	}

	return 0;
}
*/


/*
vector<int> prim;

int is_prime(int x) {
	if (x < 2) return false;
	if (x % 2 == 0 && x != 2) return false;
	for (int i = 2; i*i <= x; ++i) 
		if (x % i == 0) return false;
	return true;
}

void gen() {
	for (int i = 2; prim.size() < 200; ++i) {
		if (is_prime(i)) prim.push_back(i);
	}
}


int main()
{
	gen();
	int ans ,c;
	string str;
	while (cin >> str) {
		ans = c = 0;
		for (int i = str.size() - 1; i >= 0; --i) {
			if (str[i] == '1')
				ans += prim[c];
			c++;
		}
		cout << ans << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n, sum, v[55];
	cin >> n;
	sum = 0;

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum % 2) 
		printf("0");
	else {


	}


	return 0;
}
*/

/*
int a[100005], ans[100005];
int v[100005];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d %d", &n, &m);

		for (int i = 0; i < n; ++i)
			scanf("%d", &a[i]);

		memset(v, 0, sizeof v);

		ans[n - 1] = 1;
		v[a[n - 1]] = 1;
		for (int i = n - 2; i >= 0; i--) {
			if (v[a[i]] == 0) {
				ans[i] = ans[i + 1] + 1;
				v[a[i]] = 1;
			}
			else
				ans[i] = ans[i + 1];
		}
		for (int i = 0; i < m; ++i) {
			int t;
			scanf("%d", &t);
			printf("%d\n", ans[t-1]);
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
		int n, ans;
		ans = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			if (t >= 50 && t <= 59)ans++;
		}
		cout << ans << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int T, n;
	cin >> T;

	while (T--) {
		int x[6];
		for (int i = 0; i < 6; ++i)
			cin >> x[i];
		int ans = x[5];
		cin >> n;

		for (int i = 0; i < n; ++i) {
			int op;
			cin >> op;
			
			int old[6];
			copy(x, x + 6, old);
			if (op == 0) {
				
				x[0] = old[4];
				x[4] = old[1];
				x[1] = old[5];
				x[5] = old[0];
			}
			else if (op == 1) {
				x[0] = old[5];
				x[4] = old[0];
				x[1] = old[4];
				x[5] = old[1];
			}
			else if (op == 2) {
				x[3] = old[5];
				x[5] = old[2];
				x[2] = old[4];
				x[4] = old[3];
			}
			else if (op == 3) {
				x[2] = old[5];
				x[5] = old[3];
				x[3] = old[4];
				x[4] = old[2];
			}
			ans += x[5];
		}
		cout << ans <<endl;
	}

	return 0;
}
*/


/*
int main()
{
	int t, n, a,b;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			cout << a + b << endl;
		}
	}

	return 0;
}
*/

/*
long long pre[200005];
int main()
{
	int n, q;
	cin >> n >> q;

	vector<long long> a(n);
	cin >> a[0];
	pre[0] = a[0];
	for (int i = 1; i < n; ++i) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}

	long long sum = 0;
	for (int i = 0; i < q; ++i) {
		long long k;
		cin >> k;

		sum += k;
		if (sum >= pre[n - 1]) {
			cout << n << endl;
			sum = 0;
		}
		else {
			int pos = lower_bound(pre, pre + n, sum) - pre;
			if (pre[pos] == sum)
				cout << n - pos - 1 << endl;
			else
				cout << n - pos << endl;

		}
	}

	return 0;
}
*/


/*
long long v[14];
long long mov(int x)
{
	long long ans = 0;
	int vv[14];
	copy(v, v + 14, vv);

	if (x + vv[x] <= 13) {
		int t = vv[x];
		vv[x] = 0;
		for (int i = 0; i <= 13; i++) {
			if (i > x && t) vv[i]++, t--;
			if (vv[i] % 2 == 0) ans += vv[i];
		}
	}
	else {
		long long t = vv[x];
		vv[x] = 0;
		int n = t / 14;
		int p = t % 14;

		for (int i = 0; i < 14; ++i) vv[i] += n;
		for (int i = x + 1; p; ++i) vv[i % 14]++, p--;
		for (int i = 0; i < 14; ++i) if (vv[i] % 2 == 0) ans += vv[i];
	}
	return ans;
}

int main()
{
	for (int i = 0; i < 14; i++)
		cin >> v[i];

	long long ans = -1;
	for (int i = 0; i < 14; i++) {
		ans = max(ans, mov(i));
	}
	cout << ans;

	return 0;
}
*/

/*
int main()
{
	int n, i, j, ans;
	cin >> n;

	vector<set<int>> v;
	ans = 0;
	for (i = 0; i < n; ++i) {
		string str;
		cin >> str;
		
		set<int> s;
		for (auto i : str) s.insert(i);
		
		if (find(v.begin(), v.end(), s) == v.end()) ans++;
		v.push_back(s);
	}
	cout << ans;

	return 0;
}
*/

/*
int main()
{
	long long k;
	int n, m;
	int x, y;

	cin >> n >> m >> k;

	x = y = 1;
	if (k == 0) {
		cout << x << ' ' << y;
		return 0;
	}
	
	bool flag = true;
	if (1 + k <= n) {
		flag = false;
		x += k;
	}
	else {
		x = n;
		y = 2;
		k -= n;
	}

	while (flag) { 
		if (m == 2) {
			x -= k;
			flag = false;
		}
		else {
			// x = ?, y = 2
			if (y + k <= m) {
				y += k;
				flag = false;
				break;
			}
			else {
				y = m;
				x--;
				k -= m - 1;
			}

			if (y - k >= 2) {
				y -= k;
				flag = false;
				break;
			}
			else {
				y = 2;
				x--;
				k -= m - 1;
			}
		}
		
	}

	cout << x << ' ' << y;

	return 0;
}
*/


/*
int main()
{
	string str;
	int n;
	cin >> n >> str;

	bool flag = true;
	while (flag) {
		flag = false;

		size_t pos;
		while ((pos = str.find("01")) != string::npos) {
			swap(str[pos], str[pos + 1]);
			flag = true;
		}
		while ((pos = str.find("11")) != string::npos) {
			str.erase(pos, 1);
			flag = true;
		}
	}
	cout << str;

	return 0;
}
*/

/*
int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	char v[2 * 100005];
	cin >> v;

	int ans = 0, all = a+b;

	int  last = -1;
	for (int i = 0; i < n; ++i) {
		if (ans >= all) break;

		if (v[i] == '.') {
			if (last == -1) {
				ans++;
				if (a > b)
					a--, last = 1;
				else
					b--, last = 2;
			}
			else if (last == 1 && b > 0) {
				b--, ans++, last = 2;
			}
			else if (last == 2 && a > 0) {
				a--, ans++, last = 1;
			}
			else
				last = -1;

		}
		else if (v[i] == '*') {
			last = -1;
		}
		
	}
	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	int n, sum;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int half = (int)ceil(1.0*accumulate(v.begin(), v.end(), 0) / 2);
	sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += v[i];
		if (sum >= half) {
			cout << i + 1;
			break;
		}
	}

	return 0;
}
*/

/*
struct tnode {
	tnode *go[26];
	bool term;
	tnode() {
		for (int i = 0; i < 26; ++i) go[i] = nullptr;
		term = false;
	}
};

tnode *root;
char s[100005];
int n;

void add() {
	tnode *cur = root;
	char *a = s;
	while (*a != '\0') {
		if (cur->go[*a - 'a'] == nullptr) cur->go[*a - 'a'] = new tnode;
		cur = cur->go[*a - 'a'];
		a++;
	}
	cur->term = true;
}

using tans = multiset<int>;
using pans = tans * ;

pans merge(pans a, pans b) {
	if (a->size() > b->size()) swap(a, b);
	for (auto i : *a) b->insert(i);
	delete a;
	return b;
}

pans calc(tnode *cur, int curd) {
	pans ans = new tans;
	for (int i = 0; i < 26; ++i) if (cur->go[i] != nullptr) {
		auto t = calc(cur->go[i], curd + 1);
		ans = merge(ans, t);
	}
	if (cur->term) ans->insert(curd);
	else if (curd != 0) {
		ans->erase(prev(ans->end()));
		ans->insert(curd);
	}
	return ans;
}

int main()
{
	root = new tnode;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		add();
	}
	auto ans = calc(root, 0);
	cout << accumulate(ans->begin(), ans->end(), 0) << endl;

	return 0;
}
*/

/*
int main()
{
	long long n, k, M, D;
	cin >> n >> k >> M >> D;

	long long ans = 0,x;
	for (int d = 1; d <= D; d++)
	{
		x = min(M, n / ((d - 1)*k + 1));
		if (x == 0)
			break;
		if (((n/x +k-1)/k) != d )
			continue;

		ans = max(ans, d*x);

	}
	cout << ans;

	return 0;
}
*/

/*
char mp[105][105];
int n, k;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> mp[i];

	int ma = 0;
	int ansx=0, ansy=0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			int cur = 0;
			int l, r ;
			l = r = 0;
			while (l < k && x - l >= 0 && mp[y][x - l] == '.') l++;
			while (r < k && x + r < n && mp[y][x + r] == '.') r++;
			cur = max(0, r + l - k);
			if (k != 1) {
				l = r = 0;
				while (l < k && y - l >= 0 && mp[y - l][x] == '.') l++;
				while (r < k && y + r < n && mp[y + r][x] == '.') r++;
				cur += max(0, r + l - k);
			}
			//printf("%d %d  : %d\n", y+1, x+1, cur);
			if (cur > ma) {
				ma = cur;
				ansx = x;
				ansy = y;
			}
		}
	}
	cout << ansy+1  << ' ' << ansx+1 << endl;

	return 0;
}
*/


/*
#include <iostream>
#include <stdio.h>
using namespace std;


int main()
{
	int n1, n2;
	float h[100], w[100];
	float r[100];

	cout << "输入格式 类型 参数" <<endl;
	cout << "1 代表矩形，后跟两个数 长和宽，如 1 2 2" << endl;
	cout << "2 代表圆形，后跟一个数 半径，如 2 3" << endl;
	cout << "0 代表计算所有面积，并退出" << endl;
	cout << "请输入选项：";

	int op;
	n1 = n2 = 0;
	while (cin >> op) {
		if (op == 1) {
			cin >> h[n1] >> w[n1];
			n1++;
		}
		else if (op == 2) {
			cin >> r[n2++];
		}
		else if (op == 0) {
			cout << "共有" << n1 + n2 << "个图形" << endl;
			for (int i = 0; i < n1; ++i) {
				printf("长为%.2f，宽为%.2f的矩形的面积是%.2f\n", h[i], w[i], h[i] * w[i]);
			}
			for (int i = 0; i < n2; ++i) {
				printf("半径为%.2f的圆的面积是%.2f\n", r[i], 3.1415926*r[i] * r[i]);
			}
			cout << "输入任意键退出";
			getchar();
		}
	}

	return 0;
}
*/


/*
int main()
{
	int k, n, s, p;
	cin >> k >> n >> s >> p;
	int packs = ceil(k*ceil(1.0*n / s)/p);
	cout << packs;

	return 0;
}
*/

/*
int main()
{
	int n, L;
	cin >> n >> L;
	vector<int> c(n);

	for (int i = 0; i < n; ++i)
		cin >> c[i];

	for (int i = 0; i < n - 1; ++i)
		c[i + 1] = min(c[i + 1], 2 * c[i]);

	long long ans = (long long)4e18, sum = 0;

	for (int i = n - 1; i >= 0; --i) {
		long long need = L / (1 << i);
		sum += need * c[i];
		L -= need << i;
		
		ans = min(ans, sum + (L > 0)*c[i]);
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
	vector<int> p(n), deg(n);
	
	for (int i = 1; i < n ; ++i) {
		cin >> p[i];
		p[i]--;
		deg[p[i]]++;
	}
	vector<int> sons_leaves(n);
	for (int i = 0; i < n; ++i) {
		if (deg[i] == 0)
			sons_leaves[p[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		if (deg[i] > 0 && sons_leaves[i] < 3) {
			cout << "No";
			return 0;
		}
	}
	
	cout << "Yes";

	return 0;
}
*/

/*
int main()
{
	int n, m;
	cin >> n >> m;
	if (n >= 31)
		cout << m;
	else
		cout << (m % (1 << n));

	return 0;
}
*/

/*
bool found;

void dfs(unsigned long long t, int n, int k)
{
	if (found)
		return;
	if (t % n == 0)
	{
		cout << t << endl;
		found = true;
		return;
	}
	if (k == 19)
		return;
	dfs(t * 10, n, k + 1);
	dfs(t * 10 + 1, n, k + 1);
}


int main()
{
	int n;
	while (cin >> n && n )
	{
		found = false;
		dfs(1, n, 0);
	}

	return 0;
}
*/


/*
int main()
{
	int n,t;
	ifstream fin("ate.in");
	ofstream fout("ate.out");
	while (fin >> n)
	{
		if (n > 99 * 2)
			fout << 0 << endl;
		else
			fout << 199 - n << endl;
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
		if (n == 1 || n % 2 == 0)
			printf("2^? mod %d = 1\n", n);
		else
		{
			int x = 1, t = 2;
			while (t%n != 1)
			{
				x++;
				t = t * 2 % n;
			}
			printf("2^%d mod %d = 1\n", x,n);
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
		long long n;
		cin >> n;
		cout << "Alice" << endl;
	}

	return 0;
}
*/


/*
char in[55][55];
char out[55][55];
int n, m;

void output(char c[55][55])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			putchar(c[i][j]);
		putchar('\n');
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int  ang;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> in[i];
		cin >> ang;
		if (ang == 0)
			output(in);
		else if (ang == 90)
		{
			for (int i = 0; i < m; ++i)
			{
				for (int j = n - 1; j >= 0; --j)
					putchar(in[j][i]);
				putchar('\n');
			}
		}
		else if (ang == 180)
		{
			for (int i = n - 1; i >= 0; --i)
			{
				for (int j = m - 1; j >= 0; --j)
					putchar(in[i][j]);
				putchar('\n');
			}
		}
		else
		{
			for (int i = m - 1; i >= 0; --i)
			{
				for (int j = 0; j < n; ++j)
					putchar(in[j][i]);
				putchar('\n');
			}
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
		int a;
		cin >> a;
		if (a <= 3 || a % 2)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}

	return 0;
}
*/


/*
const double esp = 1e-8;
const int N = 1010;
struct point { double x, y; }p[N];

#define parm (double x, double y)
bool dy parm{ return x+esp > y ; }
bool xy parm{ return x < y - esp; }
bool dyd parm{ return x > y - esp; }
bool xyd parm{ return x < y + esp; }
bool dd parm{ return abs(x - y) <= esp; }

double dis(point a, point b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

point center(point a, point b, point c)
{
	point ret;
	double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1 * b1) / 2;
	double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2 * b2) / 2;
	double d = a1 * b2 - a2 * b1;
	ret.x = a.x + (c1*b2 - c2 * b1) / d;
	ret.y = a.y + (a1*c2 - a2 * c1) / d;
	return ret;
}

void min_cov_circle(int n, point& c, double &r)
{
	random_shuffle(p, p + n);
	c = p[0]; r = 0;
	for (int i = 1; i < n; ++i)
	{
		if (dy(dis(p[i], c), r))
		{
			c = p[i]; r = 0;
			for (int k = 0; k < i; ++k)
			{
				if (dy(dis(p[k], c), r))
				{
					c.x = (p[i].x + p[k].x) / 2;
					c.y = (p[i].y + p[k].y) / 2;
					r = dis(p[k], c);
					for (int j = 0; j < k; ++j)
					{
						if (dy(dis(p[j], c), r))
						{
							c = center(p[i], p[k], p[j]);
							r = dis(p[i], c);
						}
					}
				}
			}
		}
	}
}

int main()
{
	int n;

	double x, y;
	while (cin >> x >> y >> n)
	{
		for (int i = 0; i < n; ++i)
			cin >> p[i].x >> p[i].y;
		double r;
		point c;
		min_cov_circle(n, c, r);
		printf("(%.1lf,%.1lf).\n", c.x, c.y);
		printf("%.1lf\n", r);
	}
	return 0;
}
*/

/*
const int N = 5005;
struct _s
{
	int from, to, v;
}edge[N];

int fa[N];
void init(int n)
{
	for (int i = 0; i <= n; ++i)
		fa[i] = i;
}
int find(int x)
{
	if (fa[x] != x)
		return fa[x] = find(fa[x]);
	return x;
}
void h(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
		fa[a] = b;
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, m, s, t, j;
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
			cin >> edge[i].from >> edge[i].to >> edge[i].v;
		cin >> s >> t;

		sort(edge, edge + m, [](_s a, _s b) { return a.v > b.v; });

		//for (int i = 0; i < m; ++i)
		//	printf("%d to %d , v : %d\n", edge[i].from, edge[i].to, edge[i].v);

		double rate = 1e10;
		int x, y;
		for (int i = 0; i < m; ++i)
		{
			init(n);

			for (j = i; j < m; ++j)
			{
				if (find(edge[j].from) != find(edge[j].to)) h(edge[j].from, edge[j].to);
				if (find(s) == find(t)) break;
			}
			if (j == m) break;

			if (edge[i].v*1.0 / edge[j].v < rate) 
			{
				x = edge[i].v, y = edge[j].v;
				rate = edge[i].v*1.0 / edge[j].v;
			}
		}
		if (rate == 1e10) printf("IMPOSSIBLE\n");
		else if (x % y == 0) printf("%d\n", x/y);
		else printf("%d/%d", x / gcd(x, y), y / gcd(x, y));

	}

	return 0;
}
*/


/*
int a[1000005];

int main()
{
	int T, n, t, i;
	scanf("%d", &T);
	while (T--)
	{
		int sum, max;
		sum = max = 0;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
			if (max < a[i]) max = a[i];
		}
		for ( i = 0; i < n; ++i)
		{
			if (a[i] != max) sum += a[i];
			if (sum >= max - 1) break;
		}

		printf("%s\n", i!=n ? "Yes" : "No");
	}
	return 0;
}
*/


/*
const int N = 100005;
int n, m, a[2*N], b[2*N],fa[N], in[N], all;
char op[2*N];
vector<int> v[N];

void init()
{
	for (int i = 0; i < n; ++i)
	{
		fa[i] = i;
		v[i].clear();
		in[i] = 0;
	}
}

int find(int x)
{
	if (x != fa[x])
		return fa[x] = find(fa[x]);
	return x;
}

void h(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b)
		fa[a] = b;
}

void topsort()
{
	queue<int> q;
	bool flag = true;
	for (int i = 0; i < n; ++i)
	{
		if (in[i] == 0 && find(i) == i)
			q.push(i);
	}

	while (!q.empty())
	{
		if (q.size() > 1) flag = false;
		int cur = q.front(); q.pop();
		all--;
		for (int i = 0; i < v[cur].size(); ++i)
		{
			in[v[cur][i]]--;
			if (in[v[cur][i]] == 0)
				q.push(v[cur][i]);
		}
	}

	if (all > 0) printf("CONFLICT\n");
	else if (!flag) printf("UNCERTAIN\n");
	else printf("OK\n");
}

int main()
{
	while (cin >> n >> m)
	{
		init();
		all = n;
		for (int i = 0; i < m; ++i)
		{
			cin >> a[i] >> op[i] >> b[i];
			if (op[i] == '=')
			{
				int aa = find(a[i]);
				int bb = find(b[i]);
				if (aa != bb)
				{
					h(aa, bb);
					all--;
				}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			int aa = find(a[i]);
			int bb = find(b[i]);
			if (op[i] == '>')
			{
				in[bb]++;
				v[aa].push_back(bb);
			}
			else if (op[i] == '<')
			{
				in[aa]++;
				v[bb].push_back(aa);
			}
		}
		topsort();
	}

	return 0;
}
*/

/*
int main()
{
	int n;
	string str;
	cin >> n >> str;
	set<string> s;
	sort(str.begin(), str.end());
	do
	{
		s.insert(str);
	} while (next_permutation(str.begin(), str.end()));
	cout << s.size();
	return 0;
}
*/

/*
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a == "0" && b == "0")
			break;
		if (a.size() < b.size())
			cout << "No" << endl;
		else
		{
			bool flag = true;
			for (int i = 0; i <= a.size()-b.size(); ++i)
			{
				// a[i]
				size_t last = 0;
				for (auto t : b)
				{
					char f = char('A'+25-(t-'A'));
					last = a.find(f, last);
					if (last == string::npos)
					{
						flag = false;
						break;
					}
					last++;
				}
				if (flag)
					break;
			}
			if (flag)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}

	}

	return 0;
}
*/


/*
#define loop(i,n) for(i=0; i < n; ++i)

struct
{
	int l, r, sum,lazy,t;
}tree[100005 * 4];
int n;

void init(int l, int r, int rt)
{
	tree[rt].l = l;
	tree[rt].r = r;
	tree[rt].lazy = 0;
	tree[rt].t = 0;
	if (l == r) 
	{
		tree[rt].sum = 1;
		return;
	}
	else {
		int mid = (tree[rt].l + tree[rt].r) >> 1;
		init(l, mid, rt << 1);
		init(mid + 1, r, rt << 1 | 1);
		tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
	}
}

void update(int l, int r, int rt, int x)
{
	if (tree[rt].l == l && tree[rt].r == r)
	{
		tree[rt].sum = (r - l + 1)*x;
		tree[rt].lazy = 1;
		tree[rt].t = x;
		return;
	}
	int mid = (tree[rt].l + tree[rt].r) >> 1;

	if (tree[rt].lazy)
	{
		tree[rt].lazy = 0;
		update(tree[rt].l, mid, rt << 1, tree[rt].t);
		update(mid + 1, tree[rt].r, rt << 1 | 1, tree[rt].t);
		tree[rt].t = 0;
	}
	if (mid < l)
		update(l, r, rt << 1 | 1, x);
	else if (mid >= r)
		update(l, r, rt << 1, x);
	else
	{
		update(l, mid, rt << 1, x);
		update(mid + 1, r, rt << 1 | 1, x);
	}
	tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
}

int main()
{
	int i,q,t,k;
	scanf("%d", &k);
	loop(t, k)
	{
		scanf("%d %d", &n, &q);
		init(1, n, 1);
		loop(i, q)
		{
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			update(x, y, 1,z);
		}
		printf("Case %d: The total value of the hook is %d.\n", t + 1, tree[1].sum);
	}
	
	return 0;
}
*/


/*
int main()
{
	int a, b, c;
	while (cin >> a >> b)
	{
		a %= 10;
		b -= 1;
		switch (a)
		{
		case 0: case 1: case 5: case 6: c = a; break;
		case 2:
			c = "2486"[b % 4] - '0'; break;
		case 3:
			c = "3971"[b % 4] - '0'; break;
		case 4:
			c = "46"[b % 2] - '0'; break;
		case 7:
			c = "7931"[b % 4] - '0'; break;
		case 8:
			c = "8426"[b % 4] - '0'; break;
		case 9:
			c = "91"[b % 2] - '0'; break;
		}
		cout << c << endl;
	}

	return 0;
}
*/


/*
int n, k;
int vis[10];
char mp[10][10];
int ans, cur;

void dfs(int r)
{
	if (cur == k)
	{
		ans++;
		return;
	}
	if (cur > n)
		return;
	int i = 0;
	for (i = 0; i < n; ++i)
	{
		if (vis[i] == 0 && mp[r][i] == '#')
		{
			vis[i] = 1;
			cur++;
			dfs(r + 1);
			vis[i] = 0;
			cur--;
		}
	}
	if (r < n)
		dfs(r + 1);
}

int main()
{
	while (cin >> n >> k && n != -1 && k != -1)
	{
		ans = cur = 0;
		for (int i = 0; i < n; ++i)
			cin >> mp[i];
		memset(vis, 0, sizeof vis);
		dfs(0);
		cout << ans << endl;
	}
	
	return 0;
}
*/


/*
int vis[10];
int ans = 0;

bool check(int r, int c)
{
	for (int i = 1; i < r; ++i) {
		if (vis[i] == c) return false;
		if (abs(vis[i] - c) == abs(r - i)) return false;
	}
	return true;
}

void dfs(int r)
{
	if (r > 8)
	{
		ans++;
		return;
	}

	for (int i = 1; i <= 8; ++i)
	{
		if (check(r, i))
		{
			vis[r] = i;
			dfs(r + 1);
			vis[r] = 0;
		}
	}
}

int main()
{
	dfs(1);
	cout << ans << endl;
	return 0;
}
*/

/*
double qin[1005][1005];

int main()
{
	int n, m;
	cin >> n >> m;
	set<int> nv;
	vector<int> v[1005];

	for (int i = 0; i < m; ++i)
	{
		int k;
		cin >> k;
		v[i].resize(k);
		for (int j = 0; j < k; ++j)
			cin >> v[i][j];
	}
	string sa, sb;
	cin >> sa >> sb;
	int a, b;
	a = atoi(sa.c_str());
	b = atoi(sb.c_str());
	if (sa[0] == '-')
		nv.insert(a);
	if (sb[0] == '-')
		nv.insert(b);

	for (int i = 0; i < m; ++i)
	{
		if (find(v[i].begin(), v[i].end(), a) != v[i].end())
		{
			for (int j = 0; j < v[i].size(); ++j)
			{
				if (v[i][j] == a || v[i][j] * a > 0)
					continue;
				qin[abs(a)][abs(v[i][j])] += 1.0 / v[i].size();
			}
		}
		if (find(v[i].begin(), v[i].end(), b) != v[i].end())
		{
			for (int j = 0; j < v[i].size(); ++j)
			{
				if (v[i][j] == b || v[i][j] * b > 0)
					continue;
				qin[abs(b)][abs(v[i][j])] += 1.0 / v[i].size();
			}
		}
	}
	double ab = qin[abs(a)][abs(b)];
	double maxa, maxb;
	int ida, idb;
	maxa = maxb = 0;
	for (int i = 0; i < n; ++i)
	{
		if (qin[abs(a)][i] > maxa)
		{
			ida = i;
			maxa = qin[abs(a)][i];
		}
		if (qin[abs(b)][i] > maxb)
		{
			idb = i;
			maxb = qin[abs(b)][i];
		}
	}
	if (ida == b && idb == a)
		cout << a << ' ' << b;
	else
	{
		vector<int> out,out2;

		for (int i = 0; i < n; ++i)
		{
			if (abs(qin[abs(a)][i] - maxa) <= 1e-4)
			{
				if (a >= 0)
					out.push_back(-i);
				else
					out.push_back(i);
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (abs(qin[abs(b)][i] - maxb) <= 1e-4)
			{
				if (b >= 0)
					out2.push_back(-i);
				else
					out2.push_back(i);
			}
		}

		sort(out.begin(), out.end(), [](int a, int b) { return abs(a) < abs(b); });
		sort(out2.begin(), out2.end(), [](int a, int b) { return abs(a) < abs(b); });

		if (find(out.begin(), out.end(), b) != out.end() && find(out2.begin(), out2.end(), a) != out2.end())
			cout << a << ' ' << b;
		else
		{
			for (int i = 0; i < out.size(); ++i)
				cout << a << ' ' << out[i] << endl;
			for (int i = 0; i < out2.size(); ++i)
				cout << b << ' ' << out2[i] << endl;
		}
	}

	return 0;
}
*/

/*
#include<iostream>
using namespace std;
class Set
{
public:
	int items[100]; //定义一个数组作为容器存放100个集合元素
	int number; //定义数字i表示集合中元素的个数
				//构造函数和析构函数
	Set() {
		this->number = 0;
		memset(this->items, 0, sizeof(items));
	}
	//初始化方法
	void init(int items[], int num)
	{
		this->number = num;
		memcpy(this->items, items, sizeof(int)*num);
	}
	//添加元素
	bool add_item(int item);
	//删除元素
	bool remove_item(int item);
	//求集合的并集
	Set operator+ (Set &set2);
	//求集合的交集
	Set operator* (Set &set2);
	//显示集合元素
	void display();
	//判断集合当中是否存在item,返回元素在集合中的位置，不存在返回-1
	int is_exist(int item);
};

int Set::is_exist(int item)
{
	for (int i = 0; i< this->number; i++) {
		if (this->items[i] == item) {
			return i;
		}
	}
	return -1;
}
bool Set::add_item(int item)
{
	if (is_exist(item) >= 0 || this->number >= 100) {
		return false;
	}
	this->items[this->number] = item;
	this->number++;
	return true;
}

bool Set::remove_item(int item)
{
	int pos = is_exist(item);
	if (pos == -1) return false;
	for (int i = pos; i< this->number - 1; i++) {
		this->items[i] = this->items[i + 1];
	}
	this->number--;
	return true;
}
Set Set::operator* (Set &set2)
{
	Set result;
	for (int i = 0; i< this->number; i++) {
		if (set2.is_exist(this->items[i]) >= 0) {
			result.add_item(this->items[i]);
		}
	}
	return result;
}
Set Set::operator+ (Set &set2)
{
	Set result;
	for (int i = 0; i<this->number; i++) {
		result.add_item(this->items[i]);
	}
	for (int j = 0; j<set2.number; j++) {
		if (result.is_exist(set2.items[j]) == -1) {
			result.add_item(set2.items[j]);
		}
	}
	return result;
}

void Set::display()
{
	cout << "{";
	if (this->number > 0)
		cout << this->items[0];
	for (int i = 1; i < this->number; ++i)
		cout << ',' << this->items[i];
	cout << "}";
}

int main()
{
	Set a, b, c;
	int data[] = { 1,4,6,8,9,15,23 };
	a.init(data, 7);
	
	for (int i = 1; i < 5; ++i)
		b.add_item(i);

	cout << "Set A : ";
	a.display();
	cout << endl;
	cout << "Set B : ";
	b.display();
	cout << endl;
	cout << "Set C : ";
	c.display();
	cout << endl;

	Set res = a + b;
	cout << "Set A + B : ";
	res.display();
	cout << endl;

	res = a * b;
	cout << "Set A * B : ";
	res.display();
	cout << endl;

	return 0;
}
*/


/*
struct _stu
{
	string name;
	int p;
}stu[10005];

bool operator<(_stu &a, _stu &b)
{
	if (a.p != b.p)
		return a.p > b.p;
	else return a.name < b.name;
}

int main()
{
	int n, g, k;
	int moy = 0;
	cin >> n >> g >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> stu[i].name >> stu[i].p;
		if (stu[i].p >= g)
			moy += 50;
		else if (stu[i].p >= 60)
			moy += 20;
	}
	sort(stu, stu + n);
	int prevn = 0;
	int prevp = 0;
	cout << moy << endl;
	for (int i = 0; ; ++i)
	{
		if (i + 1 > k && stu[i].p < prevp)
			break;
		if (prevp && stu[i].p == prevp)
			cout << prevn << ' ' << stu[i].name << ' ' << stu[i].p;
		else
		{
			cout << i + 1 << ' ' << stu[i].name << ' ' << stu[i].p;
			prevn = i + 1;
		}
		cout << endl;
		prevp = stu[i].p;
	}

	return 0;
}
*/

/*
set<int> childs[100005];
int lev[100005];
int maxx = -1;

void updatelev(int x, int l)
{
	lev[x] = l + 1;
	if (lev[x] > maxx)
		maxx = lev[x];
	for (auto child : childs[x])
		updatelev(child, lev[x]);
}

int main()
{
	memset(lev, 0, sizeof lev);
	int n, t, top = -1;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> t;
		if (t == -1)
			top = i;
		else
			childs[t].insert(i);
	}
	updatelev(top, 0);
	cout << maxx << endl;
	vector<int> v;
	for (int i = 1; i <= n; ++i)
	{
		if (lev[i] == maxx)
			v.push_back(i);
	}
	cout << v[0];
	for (int i = 1; i < v.size(); ++i)
		cout << ' ' << v[i];

	return 0;
}
*/


/*
int vis[10005];
int main()
{
	set<int> s[10005];
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		s[a].insert(b);
		s[b].insert(a);
	}
	int ka;
	scanf("%d", &ka);
	for (int i = 0; i < ka; ++i)
	{
		int np, t;
		scanf("%d", &np);
		memset(vis, 0, sizeof vis);
		for (int j = 0; j < np; ++j)
		{
			scanf("%d", &t);
			vis[t] = 1;
		}
		bool flag = true;
		for (int j = 1; j <= n; ++j)
		{
			if (s[j].size() && !vis[j])
			{
				for (auto k : s[j])
				{
					if (!vis[k])
					{
						flag = false;
						break;
					}
				}
			}
			if (!flag)
				break;
		}

		printf("%s\n", flag ? "YES" : "NO");
	}

	return 0;
}
*/

/*
int main()
{
	int n;
	map<string, int> a, b;
	double ave;
	double sum;
	sum = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string name;
		int t;
		cin >> name >> t;
		a[name] = t;
		sum += t;
	}
	ave = sum / n / 2;
	for (auto i : a)
		b[i.first] = abs(i.second - ave);
	
	string win;
	double now = 1e8;
	for (auto i : b)
	{
		if (i.second < now)
		{
			win = i.first;
			now = i.second;
		}
	}
	printf("%d %s", int(ave), win.c_str());

	return 0;
}
*/

/*
int main()
{
	int n, m[105];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> m[i];

	vector<vector<int>> s[105];
	for (int i = 0; i < 105; ++i)
		s[i].resize(15);

	int num = 0;

	int cur = 1;
	int last = 0;
	for(num =0; ;num++)
	{
		bool exit = true;
		int c = 0;
		int id = -1;
		for (int i = 0; i < n; ++i)
			if (m[i] > num)
			{
				exit = false;
				c++;
				id = i;
			}
		if (exit)
			break;
		for (int i = 0; i < 10; ++i)
		{
			if (c == 1)
			{
				if (last && last == id)
				{
					cur++;
					last = 0;
				}
				s[id][num].push_back(cur);
				cur += 2;
			}
			else
			{
				for (int j = 0; j < n; ++j)
				{
					if (m[j] > num)
					{
						s[j][num].push_back(cur);
						last = j;
						cur++;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout << "#" << i+1 << endl;
		for (int j = 0; j < m[i]; ++j)
		{
			cout << s[i][j][0];
			for (int k = 1; k < 10; ++k)
				cout << ' ' << s[i][j][k];
			cout << endl;
		}
	}
	

	return 0;
}
*/


/*
#define MAX 200005
int v[MAX], ans[MAX];

int main()
{
	int n;
	while (~scanf("%d",&n))
	{
		for (int i = 0; i < n; ++i)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			v[i] = v[i+n] = a - b;
			ans[i] = ans[i+n] = 1;
		}
		for (int i = 1; i < 2 * n; ++i)
		{
			if (v[i] + v[i - 1] >= 0 && v[i - 1] >= 0)
			{
				v[i] = v[i] + v[i - 1];
				ans[i] += ans[i - 1];
				if (ans[i] == n) break;
			}
		}

		int max=0;
		for (int i = 0; i < 2 * n; ++i)
			if (max < ans[i])
				max = ans[i];
		printf("%d\n", max);
	}

	return 0;
}
*/

/*
int main() {
	int n,i;
	char blocks[105][105];
	int vis[105];

	while (cin >> n && n >= 0) {
		memset(vis, 0, sizeof vis);
		for (i = 1; i <= n; ++i)
			cin >> (blocks[i] + 1);
		
		int maxnum, minnum;
		maxnum = minnum = 0;
		for (i = 1; i <= n; ++i) {
			if (i % 2 == 0) {
				maxnum += i / 2;
				minnum += i / 2;
			}
			else {
				for (int j = 1; j <= i; ++j) {
					if (blocks[i][j] != '?' && !vis[i]) {
						vis[i] = 1;
						if (blocks[i][j] == '*') {
							if (j % 2) minnum += i / 2, maxnum += i / 2;
							else minnum += i / 2 + 1, maxnum += i / 2 + 1;
						}
						else {
							if (j % 2) minnum += i / 2 + 1, maxnum += i / 2 + 1;
							else minnum += i / 2, maxnum += i / 2;
						}
					}
				}
				if (!vis[i]) minnum += i / 2, maxnum += i / 2 + 1;
			}
		}
		cout << maxnum << ' ' << minnum << endl;
	}

	return 0;
}
*/

/*
int st[10005];
int c=1;

void insert(int x)
{
	int now = c;
	st[c] = x;
	for (int i = c / 2; i > 0; i /=2)
	{
		if (st[now] < st[i])
		{
			swap(st[now], st[i]);
			now = i;
		}
	}
	c++;
}

int main()
{
	int n, m, t;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		insert(t);
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> t;
		vector<int> v;
		while (t)
		{
			v.push_back(st[t]);
			t /= 2;
		}
		cout << v[0];
		for (int i = 1; i < v.size(); ++i)
			cout << ' ' << v[i];
		cout << endl;
	}

	return 0;
}
*/

/*
vector<string> v;
string spaces[10005];
map<string, string> father;
const string null = "null";

void build()
{
	for (int i = 0; i < v.size(); ++i)
	{
		int n = count(v[i].begin(), v[i].end(), ' ');
		if (n == 0)
		{
			father[v[i]] = null;
			spaces[0] = v[i];
		}
		else
		{
			v[i] = v[i].substr(n);
			father[v[i]] = spaces[n - 2];
			spaces[n] = v[i];
		}
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	cin.get();

	for (int i = 0; i < n; ++i)
	{
		string str;
		getline(cin, str);
		v.push_back(str);
	}

	build();

	for (int i = 0; i < m; ++i)
	{
		string a, b, c, d;
		cin >> a >> d >> d >> c >> d >> b;
		bool flag = false;
		if (c == "ancestor" || c == "descendant")
		{
			// a is ancestor of b
			if (c == "descendant") swap(a, b);
			while (father[b] != a && father[b] != null)
				b = father[b];
			flag = father[b] != null;
		}
		else if (c == "parent" || c == "child")
		{
			if (c == "child") swap(a, b);
			// a is parent of b
			if (father[b] == a)
				flag = true;
		}
		else
		{
			if (father[a] == father[b])
				flag = true;
		}
		cout << (flag ? "True" : "False") << endl;
	}

	return 0;
}
*/

/*
vector<string> v;
map<string, set<string>> mp;
map<string, string> father;
map<string, int> _n;
int getn(string& str)
{
	if (_n.find(str) == _n.end())
	{
		int n = count(str.begin(), str.end(), ' ');
		str = str.substr(n);
		_n[str] = n;
	}
	
	return _n[str];
}

void build(string name, int n)
{
	int c = getn(name);
	for (int i = n+1; i < v.size(); ++i)
	{
		string cur = v[i];
		int curN = getn(cur);
		if (c == curN)
			break;
		if (curN == c + 2)
		{
			mp[name].insert(cur);
			father[cur] = name;
			build(cur, i);
		}
	}
}

bool find(string &a, string &b)
{
	bool finded = false;
	for (auto i : mp[a])
	{
		if (i == b)
		{
			finded = true;
			break;
		}
		finded = find(i, b);
	}
	return finded;
}

int main()
{
	int n, m;
	cin >> n >> m;
	cin.get();

	for (int i = 0; i < n; ++i)
	{
		string str;
		getline(cin, str);
		v.push_back(str);
	}

	build(v[0], 0);

	for (int i = 0; i < m; ++i)
	{
		string a, b, c, d;
		cin >> a >> d >> d >> c >> d >> b;
		bool flag = false;
		if (c == "ancestor" || c == "descendant")
		{
			// a is ancestor of b
			if (c == "descendant") swap(a, b);
			if (find(a, b))
				flag = true;
		}
		else if (c == "parent" || c == "child")
		{
			if (c == "child") swap(a, b);
			// a is parent of b
			set<string> &s = mp[a];
			if (find(s.begin(), s.end(), b) != s.end())
				flag = true;
		}
		else
		{
			if (getn(a) == getn(b) && father[a] == father[b])
				flag = true;
		}
		cout << (flag ? "True" : "False") << endl;
	}

	return 0;
}
*/

/*
using namespace std;
int main() {
	int n, m;
	string t;
	unordered_map<string, int> mp;
	unordered_map<string, int>::iterator it;
	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, t);
		int num = count(t.begin(), t.end(), ' ');
		mp[t.substr(num)] = num;
		cout << t.substr(num) << ' ' << num << endl;
		// mp['Robert'] = 2
		// mp['Nancy'] = 2
		// mp['Frank'] = 4
		// mp['David'] = 4
	}
	string a, b, c, d;
	while (m--) {
		cin >> a >> d >> d >> c >> d >> b;
		if (c[0] == 'a') {
			if (mp[a] < mp[b])cout << "True" << endl;
			else cout << "False" << endl;
		}
		else if (c[0] == 's') {
			if (mp[a] == mp[b])cout << "True" << endl;
			else cout << "False" << endl;
		}
		else if (c[0] == 'd') {
			if (mp[a] > mp[b])cout << "True" << endl;
			else cout << "False" << endl;
		}
		else {
			if (c[0] == 'c')swap(a, b);
			int flag = 0;
			if (mp[a] == mp[b] - 2) {
				it = mp.find(a);
				it++;
				while (it != mp.end() && it->second > mp[a]) {
					if (it->first == b) {
						flag = 1;
						break;
					}
					it++;
				}
			}
			if (flag == 0)cout << "False" << endl;
			else cout << "True" << endl;
		}
	}
	return 0;
}
*/

/*
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
*/


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
		printf("第%02d项 : %lf %lf\n", i, double(f[i] / f[i - 1]), 1.0*f[i] / f[i - 1]);
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
		sort(station, station + n);     // 距离从大到小  

		scanf("%d%d", &l, &p);

		fuel.push(p);
		int ans = 0, i = 0;
		// l 为剩余路程, fuel 是目前可以到达的车站的队列
		while (l > 0 && !fuel.empty()) {
			ans++;
			l -= fuel.top();
			fuel.pop();
			// 把可到达，或者说，可以够到的加油站加入优先队列
			while (i < n && l <= station[i].dist)
				fuel.push(station[i++].fuel);
		}
		printf("%d\n", l <= 0 ? ans - 1 : -1);
	}

	return 0;
}
*/



// 输入， 若干个 1-4 的数，以 -1 为结束符
// 统计各个数出现的次数

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
		memset(c1, 0, sizeof(c1));    //c1[ ]保存当前得到的多项式各项系数
		memset(c2, 0, sizeof(c2));    //c2[ ]保存每次计算时的临时结果
		for (int i = 1; i <= 26; i++)
			scanf("%d", &num[i]);
		c1[0] = 1;                //相当于用X^0去乘以后面的多项式 
		for (int i = 1; i <= 26; i++) 
		{   
			//要乘以26个多项式
			for (int j = 0; j <= N; j++)   //c1的各项的指数
				for (int k = 0; k <= num[i] && j + k*i <= N; k++)  //k*i表示被乘多项式各项的指数,(X^0*i + X^1*i + X^2*i + ……)
					c2[j + k*i] += c1[j];       //指数相加得j+k*i,加多少只取决于c1[j]的系数，因为被乘多项式的各项系数均为1
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

	/*					表达式的值	i的值
		初始							5
		先计算前缀表达式
		这里，先计算 ++i	6			6
		计算i++			6			6
		计算 (i++)+(++i) 12			6
		赋值(=)给 i		12			12
		计算后缀表达式， i再+1		
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
	// i 代表当前循环的层数
	for (i = 1; i <= n; i++)
	{
		// (n-i）个空格
		for (j = 0; j < n - i; j++)
			printf(" ");

		// 从 1 到 i
		for (j = 1; j <= i; j++)
			printf("%d", j);

		// 从 (i-1) 到 j
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
		printf("%d不是素数", x);
	}
	else
	{
		printf("%d是素数", x);
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
		for (int i = 1; i <= k; ++i) // 遍历所有科目
			for (int j = n; j >= sc[i]; --j) // 遍历剩余的分数
				for (int l = 1; l <= num[i] && j >= l *sc[i]; ++l) // 遍历科目的使用次数
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
		// 找到能走到的，且价格比当前节点低的加油点
		for (int i = pos + 1; i <= n + 1 ; ++i)
		{
			if (d[i] > d[pos] + c*d2)
				break;

			if (p[i] < p[pos])
			{
				// 剩余的油可以走到
				if (d[pos] + remain*d2 >= d[i])
				{
					// 减去消耗的油
					remain -= (d[i] - d[pos]) / d2;
				}
				else
				{
					// 算出需要加多少油才能走到
					cost += ((d[i] - d[pos]) / d2 - remain)*p[pos];
					remain = 0;
				}
				pos = i;
				found = true;
				break;
			}
		}
		// 没有可以直接走到的节点
		if (!found)
		{
			// 尝试在当前节点加满油
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

// 在 T 中寻找 P
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
// 回文
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

// 在 P中，寻找 T
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

// 变化, 
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

// 在 P中，寻找 T
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
	// n 个点， m 条 边
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

