
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
#include <climits>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <utility>

#ifndef _MSC_VER
#include <bits/stdc++.h>
#endif

#define FASTIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define rep(i,a,b) for(int i=a; i < b; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"
using ll = long long;
using pii = std::pair<int, int>;
const int INF = (int)1e8+5;
const ll  INF_LL = (ll)1e18;

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--) {
		int x, n, m;
		cin >> x >> n >> m;
		while(x > 0 && n && x / 2 + 10 < x) {
			n--;
			x = x / 2 + 10;
		}
		if (x <= 10 * m) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
	return 0;
}


/*
int main()
{
	int n;
	cin >> n;
	while(n--) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		cout << b << " " << c  << " " << c << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int a, b, c;
	string in;
	cin >> a >> b;
	cin >> in;

	string ans;
	bool ok;
	c = 0;
	for (int i = 0; i < in.size(); i++) {
		ok = false;
		for (int j = 0; j < 10; j++) {
			if ((c + j) % a != 0 && in[i] == '0' || (c + j) % a == 0 && in[i] == '1') {
				if (i == 0 && j == 0) continue;
				ok = true;
				c += j; c %= a;
				ans.push_back('0' + j);
				break;
			}
		}
		if (!ok) {
			ans = "-1";
			break;
		}
		c *= 10;
	}

	cout << ans;

	return 0;
}
*/

/*
int main()
{
	string in;
	cin >> in;

	vector<int> ans(5, 0);
	if (in.substr(0, 3) != "MDA") {
		ans = { 1,1,1,1,1 };
	}
	else {
		int last = *find_if(in.rbegin(), in.rend(), [](char c) {return isdigit(c); }) - '0';
		if (last < 5) {
			last %= 5;
			if (last == 0) last += 5;
		}
		else last = 5 - last % 5;
		ans[last - 1] = 1;
	}
	cout << ans[0];
	for (int i = 1; i < 5; i++)
		cout << " " << ans[i];

	return 0;
}
*/

/*
int main() 
{
	int T;
	cin >> T;
	while(T--) {
		int n,k1,k2;
		cin >> n >> k1 >> k2;
		vector<int> p1(k1),p2(k2);
		rep(i, 0, k1) cin >> p1[i];
		rep(i, 0, k2) cin >> p2[i];
		if (*max_element(all(p1)) > *max_element(all(p2)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
*/

/*
string p,h;

void solve() {
	vector<int> cntp(26);
	rep(i, 0, p.size()) cntp[p[i] - 'a']++;
	rep(i, 0, h.size()) {
		vector<int> cnth(26);
		for(int j = i; j < h.size(); j++) {
			cnth[h[j] - 'a']++;
			if (cntp == cnth) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int main()
{
	int n;
	cin >> n;
	while(n--) {
		cin >> p >> h;
		solve();
	}

	return 0;
}
*/

/*
int main() 
{
  int n;
	cin >> n;
	cout << 9 * n << " " << 8 * n << endl;
	return 0;
}
*/


// class cls {
// public:
// 	cls(int size) {s = size; cout << "cls" <<endl; p = new int[size];}
// 	~cls() { cout << "~cls" <<endl; delete[] p; }

// 	cls& operator=(const cls& oth) {
// 		// this->a = oth.a;
// 		// this->b = oth.b;
// 		// this->c = oth.c;
// 		this->s = oth.s;
// 		this->p = new int[this->s];
// 		rep(i, 0, this->s ) this->p[i] = oth.p[i];
// 		cout << this->p <<endl;
// 		cout << "operator =" <<endl;

// 	}

// 	void f() { cout << "function f" << endl;}

// 	int s;
// 	int *p;
// };

// union s{
// 	s() {
// 		cl = cls(5);
// 	}
// 	~s() {
// 		cl.~cls();
// 	}

// 	// vector<int> vec;
// 	cls cl;
	
// 	int d[10];
// };

// int main() 
// {
// 	cout << sizeof(s) <<endl;

// 	// s.vec = vector<int>();
// 	vector<int> a, b = vector<int>{1,2,3};
// 	a = b;
// 	b.~vector();

// 	for(int i =0; i < a.size(); i ++){
// 		cout << a[i] <<endl;
// 	}

// 	s ss;

// 	ss.cl.f();
// 	ss.cl.~cls();

// 	cout << "assign 2" <<endl;
// 	rep(i, 0, 10)
// 		ss.d[i] = 10;

// 	cout << ss.cl.p << endl;

// 	cout << "return" <<endl;
// 	return 0;
// }

/*
class Construct {
public:
	Construct() {
		Construct(0);
	}

	Construct(int a) {
		cout << "Construct!" << endl;
	}
};

class Test {
public:
	Test(int a) {
		cout << "Init!" << endl;
		con = Construct(1);
	}

	Test(bool a) : con(1) {
		cout << "Init!" << endl;
	}

	Construct con;
};


int main() 
{
	Test(1);
	Test(true);
	list<int> l;
	sort(l.begin(), l.end());

	return 0;
}
*/

/*
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a = c - a;
	b = d - b;
	if (b < 0) {
		b += 60;
		a--;
	}

	cout << a << " " << b;

	return 0;
}
*/

/*
int main() {
	int a, b;
	cin >> a >> b;
	a = 10 * a + b;
	cout << a / 19;
	
	return 0;
}
*/

/*
int main()
{
	int a, b;
	cin >> a >> b;
	cout << a + b;

	return 0;
}
*/

/*
int main()
{
	cout << "  ********\
			* ***********\
			####....#.\
			#..###.....##....\
			###.......######              ###            ###\
					...........               #...#          #...#\
			##*#######                 #.#.#          #.#.#\
			####*******######             #.#.#          #.#.#\
					...# * **.* * **.*###....          #...#          #...#\
					....* * ********##.....           ###            ###\
					....* * *******....\
			####        ####\
			######        ######\
			##############################################################\
			#...#......#.##...#......#.##...#......#.##------------------#\
			###########################################------------------#\
			#..#....#....##..#....#....##..#....#....#####################\
			##########################################    #----------#\
			#.....#......##.....#......##.....#......#    #----------#\
			##########################################    #----------#\
			#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#\
			##########################################    ############";

	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include<vector>

using namespace std;

vector<char> read(string dispwords = "waiting input") {
	char tempStr;
	vector<char> strVec;
	cout << dispwords << endl;
	while (cin >> tempStr)
	{
		strVec.push_back(tempStr);
		if (cin.get() == '\n')  break;
		else cin.unget();
	}
	return strVec;
}

int main() {

	string s1 = "advantage";
	string s2 = "didactical";

	vector<char> c1, c2;
	for (int i = 0; i < s1.length(); i++)  c1.push_back(s1[i]);
	for (int i = 0; i < s2.length(); i++)  c2.push_back(s2[i]);

	// // reading from input stream
	// vector<char> c1 = read("sequence 1");
	// vector<char> c2 = read("sequence 2");


	vector<vector<int>> canvas(c1.size() + 1, vector<int>(c2.size() + 1, 0));
	for (int i = 0; i < c1.size() + 1; i++) {
		for (int j = 0; j < c2.size() + 1; j++) {
			if (c1[i] == c2[j]) {
				canvas[i + 1][j + 1] = canvas[i][j];
				// recording here
			}
			else {
				canvas[i + 1][j + 1] = canvas[i + 1][j] > canvas[i][j + 1] ? canvas[i + 1][j] : canvas[i][j + 1];
			}
		}
	}
	cout << canvas[c1.size()][c2.size()] << endl;

}
*/

/*
struct RGB
{
	int x;
};

int main()
{
	vector<RGB> v = {
		RGB{1},RGB{2},RGB{3}
	};

	RGB x{ 2 };
	v.insert(v.begin(), RGB{});
	
	auto it = find_if(v.begin(), v.end(), [&](const RGB& value) { return value.x == x.x; });
	if (it != v.end()) {
		cout << it - v.begin() << endl;
	}

	return 0;
}
*/

/*
class ca
{
public:
	void operator+=(const ca& other) {
		this->value += other.value;
	}
	int operator+=(int b) {
		this->value += b;
	}

	int value;
};

class cb : public ca{
	int c;

	//void operator+=(double a) {
	//
	//}
};

int main()
{
	cb a, b;
	a.value = 1;
	b.value = 2;
	a += b;

	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while(T--) {
		int n, x, a, b;
		cin >> n >> x >> a >> b;
		if (a > b) swap(a,b);
		cout << min(n-1, b-a + x) << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int q;
	cin >> q;
	while(q--) {
		ll a,b,n,S;
		cin >> a >> b >> n >> S;
		int flag = false;
		ll c = min(a, S/n);
		if (S - c*n <= b) flag = true;

		if (flag) cout << "YES" <<endl;
		else cout << "NO" << endl;
	}
	return 0;
}
*/

/*
class pool 
{
//这里和类是同一缩进，不要写东西
	//这里开始写东西
	

	// 这是一级缩进，main函数的前后括号和这一行的开头要平级
	void static f()
	{
		// 属于main的语句，都比main函数多一个缩进

		if (1 > 2) {
			// 同样的，属于if的语句都比if的开头多一个缩进

			for (;;) {
				// for 语句也是
			}

		}
	}
};
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
	int x, y;
};

bool operator<(const point& a, const point& b) {
	if (a.x != b.x) return a.y < b.y;
	return a.x < b.x;
}

bool operator==(const point& a, const point& b) {
	return a.x == b.x && a.y == b.y;
}

point _last_point;
bool order(point& a, point& b) {
	return (abs(a.x - _last_point.x) + abs(a.y - _last_point.y)) <
		(abs(b.x - _last_point.x) + abs(b.y - _last_point.y));
}


int shapes[][5] = {
	{1,0,0,0,0}, // 1
	{0,1,0,0,0}, // 2
	{0,0,1,0,0}, // 3
	{0,0,0,1,0}, // 4
	{0,0,0,0,1}, // 5

	{1,1,0,0,0}, // 50
	{0,1,1,0,0}, // 50
	{0,0,1,1,0}, // 50
	{0,0,0,1,1}, // 50

	{1,1,0,1,0}, // 200
	{0,1,1,0,1}, // 200
	{1,0,1,1,0}, //

	{0,0,1,1,1}, // 500
	{1,1,1,0,0},

	{0,1,1,1,0}, // 5000
	{1,1,1,0,1},
	{1,1,0,1,1},
	{1,0,1,1,1},

	{1,1,1,1,0},
	{0,1,1,1,1},
	{1,1,1,1,1}  // 1000000
};

const int MAX = 1000000;
const int SHAPE_NUM = 20;

int score[] = {
	60,60,60,60,60,
	500,500,500,500,
	1000,1000,1000,
	2000,2000,
	5000,5000,5000,5000,
	200000,200000,
	MAX
};


class board {
public:
	board() {
		fill(bd[0], bd[0] + 25, 0);
		turn = 1;
		win = 0;
		black_ai = false;
		white_ai = true;
		DEPTH = 3;
	}


	void ai(point& pt, int bk) {
		DEPTH = min(3, 25 - int(black.size() + white.size()));
		ab_search(pt, bk, DEPTH, -MAX, MAX);
	}

	// bk == True 表示执黑子
	int ab_search(point& pt, int bk, int depth, int alpha, int beta) {
		if (game_win(1) || game_win(0) || depth == 0) {
			return evaluate(bk);
		}

		vector<point> blank_pts;
		point tmp;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				tmp = { i,j };
				if (find(black.begin(), black.end(), tmp) == black.end() &&
					find(white.begin(), white.end(), tmp) == white.end()) {
					blank_pts.emplace_back(tmp);
				}
			}
		}

		if (!all.empty())
			_last_point = all.back();
		else
			_last_point = { 3,3 };
		sort(blank_pts.begin(), blank_pts.end(), order);

		for (int i = 0; i < blank_pts.size(); i++) {
			point next_step = blank_pts[i];

			// 临时走 next_step
			if (bk) {
				black.push_back(next_step);
				bd[next_step.y][next_step.x] = 1;
			}
			else {
				white.push_back(next_step);
				bd[next_step.y][next_step.x] = 2;
			}
			all.push_back(next_step);

			// 计算下一层分数
			int value = -ab_search(pt, !bk, depth - 1, -beta, -alpha);

			// 撤销刚才临时走的一步
			if (bk) {
				black.pop_back();
			}
			else {
				white.pop_back();
			}
			bd[next_step.y][next_step.x] = 0;
			all.pop_back();

			// 剪枝
			if (value > alpha) {
				if (depth == DEPTH) {
					pt = next_step;
				}

				// 大于 beta，则不用继续计算其他
				if (value >= beta) {
					return beta;
				}

				// 更新 alpha 值
				alpha = value;
			}
		}

		return alpha;
	}

	int evaluate(int bk) {
		int total_score = 0;
		vector<point>* my, * enemy;
		if (bk) {
			my = &black;
			enemy = &white;
		}
		else {
			my = &white;
			enemy = &black;
		}

		point tmp;
		int i, j;

		// 横向扫描
		int my_score = 0;
		int enemy_score = 0;
		for (i = 0; i < 5; i++) {
			vector<int> pts;
			for (int j = 0; j < 5; j++) {
				tmp = { i,j };
				if (find(my->begin(), my->end(), tmp) != my->end())
					pts.push_back(1);
				else if (find(enemy->begin(), enemy->end(), tmp) != enemy->end())
					pts.push_back(2);
				else
					pts.push_back(0);
			}
			for (int j = 0; j < SHAPE_NUM; j++) {
				bool right = true;
				for (int k = 0; k < 5; k++) {
					if (pts[k] != shapes[j][k]) {
						right = false;
						break;
					}
				}
				if (right) {
					my_score += score[j];
				}
			}
			for (int j = 0; j < SHAPE_NUM; j++) {
				bool right = true;
				for (int k = 0; k < 5; k++) {
					if (pts[k] == 0 && pts[k] != shapes[j][k]) {
						right = false;
						break;
					}
					if ((pts[k] == 2 ? 1 : 2) != shapes[j][k]) {
						right = false;
						break;
					}
				}
				if (right) {
					enemy_score += score[j];
				}
			}
		}

		// 纵向扫描
		for (i = 0; i < 5; i++) {
			vector<int> pts;
			for (int j = 0; j < 5; j++) {
				tmp = { j, i };
				if (find(my->begin(), my->end(), tmp) != my->end())
					pts.push_back(1);
				else if (find(enemy->begin(), enemy->end(), tmp) != enemy->end())
					pts.push_back(2);
				else
					pts.push_back(0);
			}

			for (int j = 0; j < SHAPE_NUM; j++) {
				bool right = true;
				for (int k = 0; k < 5; k++) {
					if (pts[k] != shapes[j][k]) {
						right = false;
						break;
					}
				}
				if (right) {
					my_score += score[j];
				}
			}
			for (int j = 0; j < SHAPE_NUM; j++) {
				bool right = true;
				for (int k = 0; k < 5; k++) {
					if (pts[k] == 0 && pts[k] != shapes[j][k]) {
						right = false;
						break;
					}
					if ((pts[k] == 2 ? 1 : 2) != shapes[j][k]) {
						right = false;
						break;
					}
				}
				if (right) {
					enemy_score += score[j];
				}
			}
		}


		// 扫描对角线
		vector<int> pts;
		for (i = 0; i < 5; i++) {
			tmp = { i, i };
			if (find(my->begin(), my->end(), tmp) != my->end())
				pts.push_back(1);
			else if (find(enemy->begin(), enemy->end(), tmp) != enemy->end())
				pts.push_back(2);
			else
				pts.push_back(0);
		}

		for (int j = 0; j < SHAPE_NUM; j++) {
			bool right = true;
			for (int k = 0; k < 5; k++) {
				if (pts[k] != shapes[j][k]) {
					right = false;
					break;
				}
			}
			if (right) {
				my_score += score[j];
			}
		}
		for (int j = 0; j < SHAPE_NUM; j++) {
			bool right = true;
			for (int k = 0; k < 5; k++) {
				if (pts[k] == 0 && pts[k] != shapes[j][k]) {
					right = false;
					break;
				}
				if ((pts[k] == 2 ? 1 : 2) != shapes[j][k]) {
					right = false;
					break;
				}
			}
			if (right) {
				enemy_score += score[j];
			}
		}
		pts.clear();

		// 扫描对角线
		for (i = 0; i < 5; i++) {
			tmp = { 4 - i, i };
			if (find(my->begin(), my->end(), tmp) != my->end())
				pts.push_back(1);
			else if (find(enemy->begin(), enemy->end(), tmp) != enemy->end())
				pts.push_back(2);
			else
				pts.push_back(0);
		}

		for (int j = 0; j < SHAPE_NUM; j++) {
			bool right = true;
			for (int k = 0; k < 5; k++) {
				if (pts[k] != shapes[j][k]) {
					right = false;
					break;
				}
			}
			if (right) {
				my_score += score[j];
			}
		}
		for (int j = 0; j < SHAPE_NUM; j++) {
			bool right = true;
			for (int k = 0; k < 5; k++) {
				if (pts[k] == 0 && pts[k] != shapes[j][k]) {
					right = false;
					break;
				}
				if ((pts[k] == 2 ? 1 : 2) != shapes[j][k]) {
					right = false;
					break;
				}
			}
			if (right) {
				enemy_score += score[j];
			}
		}

		//cout << endl;
		//show();
		//cout << "当前局面分为 " << my_score - enemy_score << endl;
		return my_score - enemy_score;
	}

	bool game_win(int bk) {
		point tmp;
		int i, j, cnt;

		// 横向扫描
		for (i = 0; i < 5; i++) {
			cnt = 0;
			for (int j = 0; j < 5; j++) {
				if (bd[i][j] == (bk == 1 ? 1 : 2))
					cnt++;
			}
			if (cnt == 5)
				return true;
		}

		// 纵向扫描
		for (i = 0; i < 5; i++) {
			cnt = 0;
			for (j = 0; j < 5; j++) {
				tmp.x = i;
				tmp.y = j;
				if (bd[j][i] == (bk == 1 ? 1 : 2))
					cnt++;
			}
			if (cnt == 5)
				return true;
		}

		// 扫描对角线
		cnt = 0;
		for (i = 0; i < 5; i++) {
			if (bd[i][i] == (bk == 1 ? 1 : 2))
				cnt++;
		}
		if (cnt == 5)
			return true;

		cnt = 0;
		for (i = 0; i < 5; i++) {
			if (bd[4 - i][i] == (bk == 1 ? 1 : 2))
				cnt++;
		}
		if (cnt == 5)
			return true;

		return false;
	}

	void next_turn() {
		// turn % 2 == 1, 执黑子
		point pt;

		int res = 25 - int(black.size() + white.size());
		if (res <= 0) {
			cout << "平局!!!!!!!!!!!!!";
			win = 3;
			return;
		}

		if (turn % 2 == 1) {
			if (black_ai) {
				cout << "黑棋思考中...";
				ai(pt, 1);
				cout << "下子( " << pt.x + 1<< "," << pt.y + 1<< ")" << endl;
			}
			else {
				get_input(pt, 1);
			}
			black.push_back(pt);
			all.push_back(pt);
			bd[pt.y][pt.x] = 1;
		}
		else {
			if (white_ai) {
				cout << "白棋思考中...";
				ai(pt, 0);
				cout << "下子( " << pt.x + 1 << "," << pt.y + 1 << ")" << endl;
			}
			else {
				get_input(pt, 0);
			}
			white.push_back(pt);
			all.push_back(pt);
			bd[pt.y][pt.x] = 2;
		}

		if (game_win(1))
			win = 1;
		if (game_win(0))
			win = 2;
		if (win != 0) {
			if (win == 1) {
				cout << "黑棋胜利!!!!!!!!!!!!!!!!" << endl;
			}
			else {
				cout << "白棋胜利!!!!!!!!!!!!!!!!" << endl;
			}
			show();
		}

		turn++;
	}

	void get_input(point& pt, int bk) {
		cout << "请输入下一步 ";
		if (bk) cout << "黑子";
		else cout << "白子";
		cout << "的坐标 : ";

		int x, y;
		while (cin >> x >> y) {
			if (!(x >= 1 && x <= 5 && y >= 1 && y <= 5)) {
				cout << endl << "输入范围错误，请重新输入 : ";
				continue;
			}
			x--, y--;
			if (bd[y][x] != 0) {
				cout << endl << "这个位置已经有子了，请重新输入 : ";
				continue;
			}
			pt.x = x;
			pt.y = y;
			return;
		}
		return;
	}

	void show() {
		cout << "-------------" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "| ";
			for (int j = 0; j < 5; j++) {
				cout << bd[i][j] << " ";
			}
			cout << "|" << endl;
		}
		cout << "-------------" << endl;
	}

	bool is_win() {
		return win != 0;
	}

private:
	//
	int win;
	bool black_ai;
	bool white_ai;
	int turn;
	int DEPTH;

	vector<point> black;
	vector<point> white;
	vector<point> all;

	int bd[5][5];
};

int main()
{
	board game;
	while (!game.is_win()) {
		game.show();
		game.next_turn();
	}
	return 0;
}
*/

/*
int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> v(n);
		rep(i, 0, n) cin >> v[i];

		int ans = 0;
		rep(i, 1, n + 1) {
			int cnt = 0;
			rep(j, 0, n) {
				if (v[j] >= i) cnt++;
			}
			if (cnt < i) break;
			ans = i;
		}
		cout << ans << endl;
	}

	return 0;
}
*/

/*
class AC {
public:
	int b;
	int a = 10;

	int& fun() {
		return a;
	}
};

int main() {
	AC ac;
	cout << ac.a << endl;

	int &b = ac.fun();
	b = 20;
	cout << ac.a << endl;
	cout << &ac << endl;
	cout << &b <<endl;
	return 0;
}
*/

/*
int main() {
	shared_ptr<int> a = make_shared<int>(5);
	shared_ptr<int> b = a;
	cout << a.use_count() << endl;
	a = nullptr;
	cout << b.use_count() << endl;
	weak_ptr<int> c(b);
	cout << c.expired() << endl;
	cout << c.use_count() <<endl;
	b = nullptr;
	cout << c.expired() << endl;
	cout << c.use_count() <<endl;
	return 0;
}
/*

/*
struct point {
	int x,y;
	
};

bool operator<(const point &a, const point &b) {
		if (a.x != b.x) return a.y < b.y;
		return a.x < b.x;
	}

point _last_point;
bool order(point &a, point &b) {
	return (abs(a.x-_last_point.x) + abs(a.y-_last_point.y)) <
		(abs(b.x-_last_point.x) + abs(b.y-_last_point.y));
}

struct shape {
	int score;
	vector<int> sp;
};

int shapes[][5] = {
	{0,1,1,0,0}, // 50
	{0,0,1,1,0}, // 50

	{1,1,0,1,0}, // 200

	{0,0,1,1,1}, // 500
	{1,1,1,0,0},

	{0,1,1,1,0}, // 5000
	{1,1,1,0,1},
	{1,1,0,1,1},
	{1,0,1,1,1},
	{1,1,1,1,0},
	{0,1,1,1,1},
	{1,1,1,1,1}  // 1000000
};

const int MAX = 1000000;
const int SHAPE_NUM = 12;

int score[] = {
	50,50,200,500,500,5000,5000,5000,5000,5000,5000,MAX
};


class board {
public:
	board() {
		fill(bd[0], bd[0] + 25, 0);
		turn = 1;
		win = 0;
		black_ai = false;
		white_ai = true;
	}


	bool ai(point &pt, int bk) {
		DEPTH = 3;
		ab_search(pt, bk, DEPTH, -MAX, MAX);
	}

	// bk == True 表示执黑子
	bool ab_search(point &pt, int bk, int depth, int alpha, int beta) {
		if (game_win(black_st) || game_win(white_st) || depth == 0) {
			return evaluate(bk);
		}

		vector<point> blank_pts;
		point tmp;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				tmp = {i,j};
				if (black_st.find(tmp) == black_st.end() && 
					white_st.find(tmp) == white_st.end()) {
						blank_pts.emplace_back(tmp);
					}
			}
		}

		_last_point = all.back();
		sort(blank_pts.begin(), blank_pts.end(), order);

		for (int i = 0; i < blank_pts.size(); i++) {
			point next_step = blank_pts[i];
			if (bk) {
				black.push_back(next_step);
				black_st.insert(next_step);
			} else {
				white.push_back(next_step);
				white_st.insert(next_step);
			}
			all.push_back(next_step);

			int value = -ab_search(pt, !bk, depth - 1, -beta, - alpha);

			if (bk) {
				black.pop_back();
				black_st.erase(next_step);
			} else {
				white.pop_back();
				white_st.erase(next_step);
			}
			all.pop_back();

			if (value > alpha) {
				if (depth == DEPTH) {
					pt = next_step;
				}
				if (value >= beta) {
					return beta;
				}
				alpha = value;
			}
		}

		return alpha;
	}

	int evaluate(int bk) {
		int total_score = 0;
		set<point> *my,*enemy;
		if (bk) {
			my = &black_st;
			enemy = &white_st;
		} else {
			my = &white_st;
			enemy = &black_st;
		}

		point tmp;
		int i,j;
		
		// 横向扫描
		int my_score = 0;
		for (i = 0; i < 5; i++) {
			vector<int> pts;
			for (int j = 0; j < 5; j++) {
				tmp = {i,j};
				if (my->find(tmp) != my->end())
					pts.push_back(1);
				else if (enemy->find(tmp) != enemy->end())
					pts.push_back(2);
				else
					pts.push_back(0);
			}
			for (int j = 0; j < SHAPE_NUM; j++) {
				bool right = true;
				for (int k = 0; k < 5; k++) {
					if (pts[k] != shapes[j][k]) {
						right = false;
						break;
					}
				}
				if (right) {
					my_score += score[j]; 
				}
			}
		}
		
		// 纵向扫描
		for (i = 0; i < 5; i++) {
			vector<int> pts;
			for (int j = 0; j < 5; j++) {
				tmp = {j, i};
				if (my->find(tmp) != my->end())
					pts.push_back(1);
				else if (enemy->find(tmp) != enemy->end())
					pts.push_back(2);
				else
					pts.push_back(0);
			}
			for (int j = 0; j < SHAPE_NUM; j++) {
				bool right = true;
				for (int k = 0; k < 5; k++) {
					if (pts[k] != shapes[j][k]) {
						right = false;
						break;
					}
				}
				if (right) {
					my_score += score[j]; 
				}
			}
		}
		
		// 扫描对角线
		for (i = 0; i < 5; i++) {
			vector<int> pts;
			for (int j = 0; j < 5; j++) {
				tmp = {j, i};
				if (my->find(tmp) != my->end())
					pts.push_back(1);
				else if (enemy->find(tmp) != enemy->end())
					pts.push_back(2);
				else
					pts.push_back(0);
			}
			for (int j = 0; j < SHAPE_NUM; j++) {
				bool right = true;
				for (int k = 0; k < 5; k++) {
					if (pts[k] != shapes[j][k]) {
						right = false;
						break;
					}
				}
				if (right) {
					my_score += score[j]; 
				}
			}
		}
		
		return my_score;
	}

	bool game_win(set<point> &pts) {
		point tmp;
		int i,j;
		bool win;
		
		// 横向扫描
		for (i = 0; i < 5; i++) {
			win = true;
			for (int j = 0; j < 5; j++) {
				tmp.y = i;
				tmp.x = j;
				if (pts.find(tmp) == pts.end()) {
					win = false;
					break;
				}
			}
			if (win) return win;
		}
		
		// 纵向扫描
		for (i = 0; i < 5; i++) {
			win = true;
			for (j = 0; j < 5; j++) {
				tmp.x = i;
				tmp.y = j;
				if (pts.find(tmp) == pts.end()) {
					win = false;
					break;
				}
			}
			if (win) return win;
		}
		
		// 扫描对角线
		win = true;
		for (i = 0; i < 5; i++) {
			tmp.x = i;
			tmp.y = i;
			if (pts.find(tmp) == pts.end()) {
				win = false;
				break;
			}
		}
		if (win)
			return true;

		return false;
	}

	void next_turn() {
		// turn % 2 == 1, 执黑子

		point pt;
		if (turn % 2 == 1) {
			if (black_ai) {
				ai(pt, 1);
			} else {
				get_input(pt, 1);
			}
			black.push_back(pt);
			black_st.insert(pt);
			all.push_back(pt);
			bd[pt.y][pt.x] = 1;
		}
		else {
			if (white_ai) {
				ai(pt, 0);
			} else {
				get_input(pt, 0);
			}
			white.push_back(pt);
			white_st.insert(pt);
			all.push_back(pt);
			bd[pt.y][pt.x] = 2;
		}

		if (game_win(black_st)) win = 1;
		if (game_win(white_st)) win = 2;
		if (win != 0) {
			if ( win == 1) {
				cout << "黑棋胜利!!!!!!!!!!!!!!!!" << endl;
			}
			else {
				cout << "白棋胜利!!!!!!!!!!!!!!!!" << endl;
			}
		}

		turn++;
	}

	void get_input(point &pt, int bk) {
		cout << "请输入下一步 ";
		if (bk) cout << "黑子";
		else cout << "白子";
		cout << "的坐标 : ";

		int x,y;
		while(cin >> x >> y) {
			if (!(x >= 1 && x <= 5 && y >= 1 && y <= 5)) {
				cout << endl << "输入范围错误，请重新输入 : ";
				continue;
			}
			if (bd[y][x] != 0) {
				cout << endl << "这个位置已经有子了，请重新输入 : ";
				continue;
			}
			pt.x = x;
			pt.y = y;
			return;
		}
		return;
	}

	void show() {
		cout << "-------------" << endl;
		for(int i = 0; i < 5; i++) {
			cout << "| ";
			for (int j = 0; j < 5; j++) {
				cout << bd[i][j] << " ";
			}
			cout << "|" << endl;
		}
		cout << "-------------" << endl;
	}

	bool is_win() {
		return win != 0;
	}

private:
	// 
	int win;
	bool black_ai;
	bool white_ai;
	int turn;
	int DEPTH;

	vector<point> black;
	vector<point> white;
	set<point> black_st;
	set<point> white_st;
	vector<point> all;

	int bd[5][5];
};

int main()
{
	board game;
	while(!game.is_win()) {
		game.show();
		game.next_turn();
	}
	return 0;
}
*/

/*
int main()
{
	ll n, l;
	cin >> n;
	vector<ll> a;
	rep(i, 0, n) {
		cin >> l;
		a.push_back(l);
	}
	cin >> l >> l >> l;
	int a1 = round(sqrt(a[1]*a[2]/l));
	cout << a1 << " ";
	rep(i, 1, n)
		cout << a[i] / a1 << " ";
	return 0;
}
*/

/*
int main() 
{
	map<char, int> mp;
	string in;
	int t;
	cin >> t >> in;
	for (auto c : in) 
		mp[c]++;
	
	int z = mp['z'], e = mp['e'], r = mp['r'], o = mp['o'];
	int n = mp['n'];

	int one = min(min(o, n), e);
	int zero = min(min(min(z, e), r), o);
	zero = min(o - one, zero);
	zero = min(e - one, zero);

	rep(i, 0, one)
		cout << 1 << " ";
	rep(i, 0, zero)
		cout << 0 << " ";

	return 0;
}
*/

/*
bool prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}
*/

/*
int main() {
	int n;
	string sa,sb;
	cin >> n >> sa >> sb;
	vector<int> a,b;
	rep(i, 0, n) {
		if (sa[i] != sb[i]) {
			if (sa[i] == 'a') a.push_back(i + 1);
			else b.push_back(i + 1);
		}
	}

	if ((a.size() + b.size()) % 2) {
		puts("-1");
		return 0;
	}

	int cnt = a.size() / 2 + b.size() / 2;
	if ((a.size() % 2) && (b.size() % 2)) cnt += 2;
	cout << cnt << endl;

	for(int i = 0; i+1 < a.size(); i += 2)
		printf("%d %d\n", a[i], a[i+1]);
	for(int i = 0; i+1 < b.size(); i += 2)
		printf("%d %d\n", b[i], b[i+1]);
	if((a.size() % 2) && (b.size() % 2))
	{
		printf("%d %d\n", a.back(), a.back());
		printf("%d %d\n", a.back(), b.back());
	}

	return 0;
}
*/

/*
int main()
{
	ll n;
    cin >> n;
    int temp;
    ll pos = 0, neg = 0;
    ll ansa = 0, ansb = 0;
    rep(i, 0, n) {
        cin >> temp;
        if(temp > 0) {
            pos++;
            ansa += pos;
            ansb += neg;
        }
		else {
            swap(neg, pos);
            neg++;
            ansb += neg;
            ansa += pos;
        }
    }
    cout << ansb << " " << ansa;
	
	return 0;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);

	rep(i, 0, n) cin >> v[i];

	int cnt = n;
	int ans = 0;
	while (cnt) {
		int x = *min_element(all(v));
		ans++;
		rep(i, 0, n) {
			if (v[i] != INT_MAX && v[i] % x == 0) {
				cnt--;
				v[i] = INT_MAX;
			}
		}
	}
	
	cout << ans << endl;

	return 0;
}
*/

/*
long long cnt(int m, int n)
{
	if (m <= 0 || n <= 0)
		return 0;
	vector<long long> data(n, 1);
	long long cur = 0;
	for (int i = 1; i < m; ++i)
	{
		cur = 1;
		for (int j = 1; j < n; ++j)
		{
			cur = cur + data[j];
			data[j] = cur;
		}
	}
	return data[n - 1];
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << cnt(n, m);

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	deque<int> q;
	for (int i = 0; i < n; i++) A.push_back(A[i]);
	vector<int> s(2 * n + 1);

	for (int i = 1; i < 2 * n; i++) {
		s[i] = s[i - 1] + A[i - 1];
	}
	q.push_back(0);
	int res = INT_MIN;

	for (int i = 1; i < 2 * n; i++) {
		if (q.size() && i - n > q.front()) q.pop_front();
		if (q.size()) res = max(res, s[i] - s[q.front()]);
		while (q.size() && s[q.back()] > s[i]) q.pop_back();
		q.push_back(i);
	}
	cout << res;
	
	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;
		int md, mh;
		md = mh = 0;
		rep(i, 0, n) {
			int a, b;
			cin >> a >> b;
			md = max(md, a);
			mh = max(mh, a - b);	
		}
		int res = 1;
		if (x - md > 0) {
			if (mh <= 0) res = -1;
			else res += (x - md + mh - 1) / mh;
		}
		cout << res << endl;
	}
}
*/

/*
int main()
{
	int a1,a2,k1,k2,n;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	if (k1 > k2) {
		swap(a1, a2);
		swap(k1, k2);
	}

	int ans1 = max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1));

	int ans2 = min(a1, n/k1);
	int rest = n - ans2 * k1;
	// cout << "ans2 " << ans2 << " rest : " << rest << endl;
	ans2 += min(a2, rest / k2);

	cout << ans1 << " " << ans2 <<endl;
	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	rep(i, 0, n) {
		int a, b, e;
		cin >> a >> b >> e;
		int minAddStr = max(0, (e + b - a + 2) / 2);
		cout << max(e - minAddStr + 1, 0) << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int t;
	vector<int> v;
	while (cin >> t) {
		v.push_back(t);
	}

	int res = INT_MIN;
	int pre = 0;
	for (int i = 0; i < v.size(); i++) {
		int cur = max(pre, 0) + v[i];
		res = max(res, cur);
		pre = cur;
	}
	cout << res;

	return 0;
}
*/

/*
int main()
{
	string a, b;
	cin >> a;
	int pos = a.find(';');
	b = a.substr(pos + 1);
	a = a.substr(0, pos);
	if (a.size() != b.size()) {
		cout << "False";
		return 0;
	}

	int cnt = 1;
	for (int i = 0; i < a.size(); i++) {
		if (isalpha(a[i])) {
			char t = a[i];
			for (auto& c : a) {
				if (c == t)
					c = cnt;
			}
			cnt++;
		}
	}
	cnt = 1;
	for (int i = 0; i < b.size(); i++) {
		if (isalpha(b[i])) {
			char t = b[i];
			for (auto& c : b) {
				if (c == t)
					c = cnt;
			}
			cnt++;
		}
	}
	if (a == b)
		cout << "True";
	else
		cout << "False";

	return 0;
}
*/

/*
int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		ans ^= t;
	}
	cout << ans;
		
	string c;
	cin >> n;
	cin >> c;
	vector<pii> v(n);
	rep(i, 0, n) cin >> v[i].first >> v[i].second, c[i] -= '0';

	int ans = 0;
	rep(i, 0, 2000) {
		int cnt = 0;
		rep(j, 0, n) {
			if (i >= v[j].second && (i - v[j].second) % v[j].first == 0)
				c[j] ^= 1;
			cnt += c[j];
		}
		// cout << "i " << i << " cnt " << cnt <<endl;
		ans = max(ans, cnt);
	}
	
	cout << ans << endl;

	return 0;
}
*/

/*
string cell[1000005];
int n,m;

bool dfs(int i, int j) {
	if (i == n-1 && j == m -1) return true;
	if (i >= n || j >= m || cell[i][j] == '#') return false;
	if (i || j) cell[i][j] = '#';
	return dfs(i + 1, j) || dfs(i, j + 1);
}

int main()
{
	cin >> n >> m;
	rep(i, 0, n)
		cin >> cell[i];

	if(!dfs(0, 0)) {
		cout << "0";
		return 0;
	}
	cout << (dfs(0,0) ? 2 : 1);

	return 0;
}
*/

/*
int main()
{
	int n;
	string in;
	cin >> n >> in;

	int l = count(all(in), '(');
	int r = count(all(in), ')');
	if (l != r) {
		cout << "No";
		return 0;
	}
	int cnt = 0;
	rep(i, 0, n) {
		if (in[i] == '(') cnt++;
		if (in[i] == ')') cnt--;
		if (cnt == -2) {
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
	string in;
	cin >> in;
	bool f = false;
	if (in[0] == '-') {
		f = true;
		in.erase(in.begin());
	}
	reverse(in.begin(), in.end());
	int t = 0;
	while(in[t] == '0') t++;
	in = in.substr(t);
	if (f) in.insert(0, "-");
	long long l = atoll(in.c_str());
	if ( l < -INT_MAX || l > INT_MAX)
		in = "0";
	cout << in;
	return 0;
}
*/

/*
int main()
{
	int b,g,n;
	cin >> b >> g >> n;
	int cnt = 0;
	for(int i = 0; i <= n; ++i) {
		int x = n - i;
		if (i <= b && x <= g) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
*/

/*
int w[5], v[5];
int dp[INF];
int main() 
{
	int n,d,e;
	cin >> n >> d >> e;
	w[1] = v[1] = d;
	w[2] = v[2] = 5*e;
	for (int i = 1; i <=2; ++i) {
		for (int j = w[i]; j <= n; ++j) {
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
		}
	}
	cout << n - dp[n] << endl;
	return 0;
}
*/

/*
int main()
{
	int n,d,e;
	cin >> n >> d >> e;
	int ans = n;
	for(int i = 0; i * 5 * e <= n; ++i) {
		ans = min(ans, (n - i * 5 * e) % d);
	}
	cout << ans << endl;
	return 0;
}
*/

/*
const int MAX_COUNT = 10005;
int state[MAX_COUNT][MAX_COUNT];
int a[MAX_COUNT];

int schedule(int n, int m)
{
	int i = 0, j = 0, k = 0, temp = 0, MaxInt;
	for (i = 1; i <= n; ++i)
	{
		state[i][1] = state[i - 1][1] + a[i];
	}
	for (j = 2; j <= m; ++j)
	{
		for (i = j; i <= n; ++i)
		{
			temp = 10000000;
			for (k = j; k < i; ++k)
			{
				MaxInt = max(state[i][1] - state[k][1], state[k][j - 1]);
				if (temp > MaxInt)
				{
					temp = MaxInt;
				}
			}
			state[i][j] = temp;
		}
	}
	return state[n][m];
}


int main() {
	int res;

	int m, n;
	cin >> m;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	res = schedule(n, m);
	if (n == m) {
		res = *max_element(a + 1, a + n + 1);
	}
	cout << res << endl;
}
*/

/*
string resolve(string expr) {
	int val = 0;
	bool valid = true;
	int maxl = 0;
	for (int i = 0; i < expr.size(); ++i) {
		if (expr[i] == '(') val++, maxl++;
		if (expr[i] == ')') val--;
		if (val < 0) {
			valid = false;
			break;
		}
	}
	if (val != 0 || !valid) {
		return "";
	}

	while (count(expr.begin(), expr.end(), '(') != 0) {
		int l = expr.find_last_of('(');
		int r = expr.find_first_of(')', l);

		reverse(expr.begin() + l, expr.begin() + r + 1);
		expr.erase(expr.begin() + l);
		expr.erase(expr.begin() + r - 1);
	}

	return expr;
}

int main() {
	string res;

	string _expr;
	getline(cin, _expr);
	res = resolve(_expr);
	cout << res << endl;

	return 0;
}
*/

/*
class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

ListNode* partition(ListNode* head, int m) {
	ListNode* ret = new ListNode(0);
	ListNode* curret = ret;
	ListNode* cur = head;
	bool first = false;

	while (cur != NULL) {
		if (cur->val <= m ) {
			if (!first) {
				ret->val = cur->val;
				first = true;
			}
			else {
				curret->next = new ListNode(cur->val);
				curret = curret->next;
			}
		}
		cur = cur->next;
	}
	if (!first) {
		delete ret;
		return head;
	}
	cur = head;
	while (cur != NULL) {
		if (cur->val > m) {
			if (!first) {
				ret->val = cur->val;
			}
			else {
				curret->next = new ListNode(cur->val);
				curret = curret->next;
			}
		}
		cur = cur->next;
	}
	while (head != NULL) {
		ListNode* p = head;
		head = head->next;
		delete p;
	}

	return ret;
}

int main()
{
	ListNode* head = NULL;
	ListNode* node = NULL;
	int m;
	cin >> m;
	int v;
	while (cin >> v) {
		if (head == NULL) {
			node = new ListNode(v);
			head = node;
		}
		else {
			node->next = new ListNode(v);
			node = node->next;
		}
	}
	head = partition(head, m);
	if (head != NULL) {
		cout << head->val;
		node = head->next;
		delete head;
		head = node;
		while (head != NULL) {
			cout << "," << head->val;
			node = head->next;
			delete head;
			head = node;
		}
	}
	cout << endl;
	return 0;
}
*/

/*
int main()
{
	int currVal = 0, val = 0;
	if (cin >> currVal)
	{
		int cnt = 1;
		while (cin >> val)
		{
			if (val == currVal)
				++cnt;
			else {
				cout << currVal << " occurs " << cnt << " times " << endl;
				currVal = val;
				cnt = 1;
			}
		}
		cout << currVal << " occurs " << cnt << " times " << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int sum = 0;
	int val;
	for (int val = 0; val <= 10; val++);
	{
		sum += val;
	}

	cout << sum << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	string status;
	cin >> n >> status;
	vector<int> v(10);
	rep(i, 0, n) {
		if (status[i] == 'L') {
			for(auto &room : v) {
				if (room != 1) {
					room = 1;
					break;
				}
			}
		}
		else if ( status[i] == 'R') {
			for(auto it = v.rbegin(); it != v.rend(); ++it) {
				if (*it != 1){
					*it = 1;
					break;	
				}
			}
		}
		else {
			v[status[i] - '0'] = 0;
		}
	}

	rep(i, 0, 10)
		cout << v[i];
	return 0;
}
*/

/*
int main()
{
	int n, t;
	cin >> n >> t;
	int best = -1, ans = 1e9;
	rep(i, 0, n) {
		int s, d;
		cin >> s >> d;
		while(s < t) s += d;
		if (s < ans) {
			ans = s;
			best = i + 1;
		}
	}
	cout << best << endl;

	return 0;
}
*/

/*
int main()
{
	for (int i = 0; i < 100; i++) {
		cout << setw(4) << (i&(-i));
		if (i % 10 == 0)
			cout << endl;
	}
	return 0;
}
*/

/*
int a[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

void out(int n, int k) {
	rep(i, 0, 4) {
		rep(j, 0, n) {
			cout << a[4*i + j % 4] + 16*(k*n/4 + j / 4) << " ";
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	rep(i, 0, n/4) out(n, i);
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

	int ans = n - 1;
	map<int,int> freq;
	rep(i, 0, n) {
		bool validPrefix = true;
		rep(j, 0, i) {
			freq[v[j]]++;
			if (freq[v[j]] == 2) {
				validPrefix = false;
				break;
			}
		}
		int min_index_suffiix = n;
		for(int j = n - 1; j >= i; --j) {
			freq[v[j]]++;
			if (freq[v[j]] == 1) {
				min_index_suffiix = j;
			} else {
				break;
			}
		}
		if (validPrefix) {
			ans = min(ans, min_index_suffiix - i);
		}

		freq.clear();
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
	while(T--) {
		int n, a, b;
		cin >> a >> b >> n;
		n %= 3;
		if (n == 0) cout << a << endl; else
		if (n == 1) cout << b << endl; 
		else
			cout << (a ^ b) << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while(T--) {
		int n,a,b;
		string s;
		cin >> n >> a >> b >> s;
		vector<vector<ll>> d(n + 1, vector<ll>(2, 1e16));
		d[0][0] = b;
		rep(i, 0, n) {
			if (s[i] == '0') {
				d[i+1][0] = min(d[i+1][0], d[i][0] + a + b);
				d[i+1][1] = min(d[i+1][1], d[i][0] + 2 * (a+b));

				d[i+1][1] = min(d[i+1][1], d[i][1] + a + 2 * b);
				d[i+1][0] = min(d[i+1][0], d[i][1] + 2 * a + b);
			} else {
				d[i+1][1] = min(d[i+1][1], d[i][1] + a + 2 * b);
			}
		}
		cout << d[n][0] << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n,m;
	cin >> n >> m;
	vector< vector<int>> v(n, vector<int>(m));
	rep(i, 0, n) rep(j, 0, m) 
		cin >> v[i][j];

	vector<pii> ans;
	rep(i, 0, n - 1) rep(j, 0, m - 1) {
		if (v[i][j] * v[i + 1][j] * v[i][j + 1] * v[i + 1][j + 1] > 0) {
			v[i][j] = 2;
			v[i + 1][j] = 2;
			v[i][j + 1] = 2;
			v[i + 1][j + 1] = 2;
			ans.push_back(make_pair(i,j));
		}
	}
	int cnt = 0;
	rep(i, 0, n) rep(j, 0, m) {
		if (v[i][j] == 1) cnt++;
	}
	if (cnt != 0) {
		cout << "-1" <<endl;
	}
	else {
		cout << ans.size() << endl;
		rep(i, 0, ans.size()) {
			cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
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
	while(T--) {
		int b, p, f;
		int h, c;
		cin >> b >> p >> f >> h >> c;
		int q = min(b/2, p);
		int r = min(b/2, f);
		int ans = 0;
		if (h > c) {
			ans += q * h;
			b -= q * 2;
			r  = min(b/2, f);
			ans += r * c;
		} else {
			ans += r * c;
			b -= r * 2;
			q  = min(b/2, p);
			ans += q * h;
		}
		cout << ans << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n, l, r;
	cin >> n >> l >> r;
	int mi, ma;
	mi = ma = 0;
	int t = 1;
	rep(i, 0, l) {
		mi += t;
		t <<= 1;
	}
	mi += (n - l);

	t = 1;
	rep(i, 0, r) {
		ma += t;
		t <<= 1;
	}
	t >>= 1;
	ma += (n - r) * t;

	cout << mi << " " << ma << endl;

	return 0;
}
*/

/*
int main()
{
	string in;
	cin >> in;
	int cnt = count(all(in), '1');
	int ans = (in.size()+1) / 2 + ((cnt == 1 && (in.size()+1)%2==0) ? -1 : 0);
	if (in == "0") ans = 0;
	cout << ans << endl;
	return 0;
}
*/

//int main()
//{
//	int a = 100;
//
//	cout << /* "*/" */";
//
//	return 0;
//}


/*
int main()
{
	int n, r;
	cin >> n >> r;
	vector<pii> pos, neg;
	rep(i, 0, n) {
		pii cur;
		cin >> cur.first >> cur.second;
		if (cur.second >= 0) pos.push_back(cur);
		else {
			cur.first = max(cur.first, abs(cur.second));
			neg.push_back(cur);
		}
	}

	sort(all(pos));
	sort(all(neg), [](pii& a, pii& b) {
		return a.first + a.second > b.first + b.second;
	});

	int taken = 0;
	rep(i, 0, pos.size()) {
		if (r >= pos[i].first) {
			r += pos[i].second;
			++taken;
		}
	}

	vector<vector<int>> dp(neg.size() + 1, vector<int>(r+1, 0) );
	dp[0][r] = taken;
	rep(i, 0, neg.size()) {
		rep(cr, 0, r + 1) {
			if (cr >= neg[i].first && cr + neg[i].second >= 0) {
				dp[i + 1][cr + neg[i].second] = max(dp[i+1][cr+neg[i].second], dp[i][cr] + 1);
			}
			dp[i + 1][cr] = max(dp[i + 1][cr], dp[i][cr]);
		}
	}

	int ans = 0;
	rep(cr, 0, r + 1) {
		ans = max(ans, dp[neg.size()][cr]);
	}
	//cout << (ans == n ? "YES" : "NO") << endl;
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
	rep(i, 0, n) cin >> v[i];

	sort(all(v), greater<int>());

	int lst = 1e7;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if (v[i] + 1 < lst) {
			ans++;
			lst = v[i] + 1;
		}
		else if (v[i] < lst) {
			ans++;
			lst = v[i];
		}
		else if (v[i] - 1 > 0 && v[i] - 1 < lst) {
			ans++;
			lst = v[i] - 1;
		}
	}

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	string s,t;
	cin >> s >> t;
	vector<int> rg(t.size());

	for(int i = t.size()-1; i >= 0; --i) {
		int pos = s.size() - 1;
		if (i + 1 < t.size()) pos = rg[i + 1] - 1;
		while (s[pos] != t[i]) --pos;
		rg[i] = pos;
	}

	int ans = 0;
	int pos = 0;
	for(int i = 0; i < s.size(); ++i) {
		int rpos = s.size() - 1;
		if (pos < t.size()) rpos = rg[pos] - 1;
		ans = max(ans, rpos - i + 1);
		if (pos < t.size() && t[pos] == s[i]) ++pos;
	}

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	string s,t;
	cin >> s >> t;
	int ans = 0;
	for(int i = 0; i < (int)s.size(); ++i) {
		for (int j = i; j < (int)s.size(); ++j) {
			int pos = 0;
			for (int p = 0; p < (int)s.size(); ++p) {
				if (i <= p && p <= j) continue;
				if (pos < (int)t.size() && t[pos] == s[p]) ++pos;
			}
			if (pos == (int)t.size()) ans = max(ans, j - i + 1);
		}
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
	ll g = 0;
	rep(i, 0, n){
		ll x;
		cin >> x;
		g = __gcd(g, x);
	}

	int ans = 0;
	for (int i = 1; i * 1ll * i <= g; ++i) {
		if (g % i == 0) {
			++ans;
			if (i != g / i) {
				++ans;
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
	int T;
	cin >> T;
	while(T--) {
		int n, t;
		cin >> n;
		vector<int> v(4*n + 1);
		rep(i, 1, 4*n + 1) cin >> v[i];
		sort(v.begin() + 1, v.end());
		int area = v[1] * v.back();
		bool can = true;
		rep(i, 1, n + 1) {
			if (v[2*i-1] == v[2*i] && v[4*n-2*i+1] == v[4*n-2*i+2] &&
			    v[2*i-1] * v[4*n-2*i+1] == area)
					continue;
			else{
				can = false;
				break;
			}
		}
		cout << (can?"YES":"NO") <<endl;
	}
	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<int> v(n);
		rep(i, 0, n) cin >> v[i];
		if (n <= 3) {
			cout << "YES" << endl;
			continue;
		}
		int cnt = 0;
		if (abs(v.front() - v.back()) <= 1) cnt++;
		rep(i, 1, n) if (abs(v[i] - v[i-1]) <= 1) cnt++;
		if (cnt >= n -1) 
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
*/

/*
#define N 135
ll n, cnt, mn=1e9, a[N], d[N][N], e[N][N];

int main()
{
	ll i,j,k,t;
	cin >> n;
	for(i = 0; i < n; i++) {
		scanf("%lld", &t);
		if (t) {
			a[cnt++] = t;
			if (cnt > 128)
				break;
		}
	}
	if (i < n) {
		puts("3");
		return 0;
	}
	for (i=0; i < cnt; i++) {
		for (j=0; j < cnt; j++) {
			if (i!=j && a[i]&a[j])
				d[i][j] = e[i][j] = 1; // 联�?
			else
				d[i][j] = e[i][j] = 1e9;
		}
	}
	for(k=0; k<cnt; k++) {
		for(i=0;i<k;i++) {
			for(j=i+1; j < k; j++) {
				mn = min(mn, e[i][k] + e[k][j] + d[i][j]);
			}
		}
		for(i=0; i<cnt;i++) {
			for(j=0;j<cnt;j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

	cout << (mn<1e9 ? mn : -1);

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	if (!(n&1)) {
		cout << "NO";
		return 0;
	}

	cout << "YES" << endl;
	rep(i, 1, 2 * n + 1) {
		if (i <= n)
			cout << 2 * i - i % 2 << " ";
		else
			cout << 2 * (i - n) - i % 2 << " ";
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

	ll ans = 0;
	int zero = 0;
	int ng = 0;
	rep(i, 0, n) {
		if (v[i] > 0) ans += abs(v[i] - 1);
		if (v[i] == 0) ans++, zero++;
		if (v[i] < 0) ng++, ans += abs(-1 - v[i]);
	}
	
	if (ng % 2 != 0 && zero == 0) {
		ans += 2;
	}

	cout << ans << endl;

	return 0;
}
*/

/*
template<typename T>
constexpr auto raxPadding(T nodesize) { return ((sizeof(void*) - ((nodesize + 4) % sizeof(void*))) & (sizeof(void*) - 1)); }
int main()
{
	for (int i = 0x10; i < 0x100; i++) {
		int padding = raxPadding(i);
		cout << "raxPadding(" << i << ") : " << padding << ", Padding to : " << i + padding << endl;
	}
	return 0;
}
*/

/*
using namespace std;
int arr[1005];
int brr[1005];

int main(void)
{

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];


	brr[0] = 100;
	for (int i = 1; i < N; i++) {
		if (arr[i - 1] < arr[i])
			brr[i] = brr[i - 1] + 100;
		else if (arr[i - 1] == arr[i])
			brr[i] = brr[i - 1];
		else
			brr[i] = 100;
	}
	int _temp;
	for (int i = N - 2; i >= 0; i--) {
		if (arr[i] > arr[i + 1]) {
			_temp = brr[i + 1] + 100;
			brr[i] = max(_temp, brr[i]);
		}
		else if (arr[i] == arr[i + 1]) {
			_temp = brr[i + 1];
			brr[i] = max(_temp, brr[i]);
		}

	}
	long long ans = 0;
	for (int i = 0; i < N; i++)
		ans += brr[i];
	cout << ans << endl;
	return 0;
}
*/

/*
int n;
vector<int> v[100005];
int len[100005];
int visit[100005];
int cnt[3] = { 0,0,0 };


void bfs(int x) {
	cnt[len[x] % 3]++;

	for (auto it : v[x]) {
		if (!visit[it]) {
			visit[it] = 1;
			len[it] = len[x] + 1;
			bfs(it);
		}
	}
}

int main()
{
	FASTIO;

	cin >> n;
	rep(i, 0, n - 1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	rep(i, 0, n) {
		memset(len, 0, sizeof(len));
		memset(visit, 0, sizeof(visit));
		visit[i] = 1;
		bfs(i);
	}
	cnt[0] -= n;
	cout << cnt[0] / 2 * 3 << " " << cnt[1] / 2 << " " << cnt[2];

	return 0;
}
*/

/*
int v[100005];
int n, x, y;

int main()
{
	cin >> n >> x >> y;
	rep(i, 1, n + 1) cin >> v[i];

	rep(i, 1, n + 1) {
		bool ok = 1;
		for (int j = max(1, i - x); j <= min(n, i + y); j++)
			if (v[j] < v[i]) ok = 0;
		if (ok) {
			cout << i;
			break;
		}
	}

	return 0;
}
*/

/*
int main()
{
	int t;
	string S, T;
	cin >> t >> S;
	while (t--) {
		cin >> T;
		string s;
		while (s.size() < T.size()) {
			s += S;
		}
		for (auto& c : s) {
			if (c == '1')
				c = '0';
			else
				c = '1';
		}
		string ss;
		ss.append((s.begin() + s.find_first_of('1')), s.end());
		if (ss == T)
			cout << "YES";
		else
			cout << "NO";
		if (t > 0)
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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end(), [](int a, int b) {
		if ((a + b) % 2 == 1 && a < b) return true;
		return false;
	});
	cout << v[0];
	for (int i = 1; i < n; i++) {
		cout << " " << v[i] ;
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
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		bool ans = true;
		for (int i = 1; i < n - 1; i++) {
			if (v[i] > v[i - 1] + v[i + 1]) {
				ans = false;
				break;
			}
		}
		if (v[0] > v[1] + v[n - 1])
			ans = false;
		if (ans)
			cout << "YES";
		else
			cout << "NO";
		if (T > 0) cout << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while(T--){
		int n,k;
		cin >> n >> k;
		vector<int> v(n);
		rep(i, 0, n) cin >> v[i];
		int odd = count_if(all(v), [](int t){return t % 2 == 1;});
		if (odd < k || odd % 2 != k % 2) {
			cout << "NO" <<endl;
			continue;
		}
		cout << "YES" << endl;
		rep(i, 0, n) {
			if (k == 1) break;
			if (v[i] % 2 == 1) {
				cout << i + 1 << " ";
				--k;
			}
		}
		cout << n << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while(T--) {
		ll ans = 0, t;
		rep(i, 0, 3) cin >> t, ans += t;
		ans /= 2;
		cout << ans << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		vector<int> v(n);
		rep(i, 0, n) cin >> v[i];
		sort(v.begin(), v.end());
		int a = v.back(), b = v[v.size()-2];
		cout << min(b - 1, n-2) << endl;
	}
	return 0;
}

 */

/*
bool prime(int x) {
	if (x < 2) return false;
	for(int i=2; i*i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main()
{
	FASTIO;
	int n;
	cin >> n;
	int m = n;
	while(!prime(m)) m++;
	cout << m << endl;
	cout << "1 " << n << endl;
	rep(i, 0, n-1)
		cout << i + 1 << " " << i + 2 << endl;
	rep(i, 0, m-n)
		cout << i + 1 << " " << i + 1 + n/2 << endl;

	return 0;
}
 */

/*
const int MOD = 998244353;

int pw(int a, int x) {
	if (x == 1) return a;
	int r = pw(a, x/2) % MOD;
	if (x % 2)
		return (((1ll *a * r) % MOD) * r) % MOD;
	return (1ll * r * r) % MOD;
}

int main()
{
	int w, h;
	cin >> w >> h;
	int ans = pw(2, w+h);
	cout << ans << endl;
	return 0;
}
 */

/*
int main()
{
	string S; cin >> S;
	ll a=0, b=0, c=0;
	rep(i, 0, S.size()) {
		if (S[i] == 'o'){
			b+=a;
		} else if (i > 0 && S[i-1] == 'v') {
			a++;
			c+=b;
		}
	}
	cout << c << endl;
	return 0;
}
*/

/*
int main() 
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> A{ 1 };
	rep(i, 0, n)
		cin >> v[i];
	int rest = 0, cur = v[0];
	rep(i, 1, n) {
		if (v[0] / 2 >= v[i]) {
			cur += v[i];
			A.push_back(i + 1);
		}
		else {
			rest += v[i];
		}
	}
	if (cur > rest) {
		cout << A.size() << endl;
		cout << A[0];
		rep(i, 1, A.size()) {
			cout << " " << A[i];
		}
		cout << endl;
	}
	else
		cout << 0 << endl;
}
*/

/*
const ll MOD = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
	if (a >= MOD) a += MOD;
	return a;
}

int mul(int a, int b) {
	return a * 1ll * b % MOD;
}

int len;
vector<int> pow10;

int f(int a) {
	int pos = 0;
	int res = 0;
	while (a > 0) {
		int cur = a % 10;
		a /= 10;
		res = add(res, mul(cur, pow10[2 * pos]));
		res = add(res, mul(cur, pow10[2 * pos + 1]));
		++pos;
	}
	return res;
}

int main()
{
	pow10 = vector<int>(30);
	pow10[0] = 1;
	rep(i, 1, 30) {
		pow10[i] = mul(pow10[i - 1],10);
	}

	int n;
	cin >> n;
	int ans = 0;
	rep(i, 0, n) {
		int a;
		cin >> a;
		len = to_string(a).size();
		ans = add(ans, mul(n, f(a)));
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
	vector<ll> a(n + 2), b(n + 2);
	vector<pll> c(n + 2);
	c[0].first = 0; c[0].second = 0;
	rep(i, 1, n + 1) 
		cin >> a[i];
	rep(i, 1, n + 1) 
		cin >> b[i];

	rep(i, 1, n + 1) {
		c[i].first = max(c[i - 1].first, c[i - 1].second + a[i]);
		c[i].second = max(c[i - 1].second, c[i - 1].first + b[i]);
	}
	
	cout << max(c[n].first, c[n].second) << endl;

	return 0;
}
*/

/*
ll n, k;

ll f(ll ans) {
	return (n - ans)*(n - ans + 1)/2 - k - ans;
}

int main()
{
	cin >> n >> k;
	ll l = -1, r = n + 1;
	while (l < r - 1) {
		ll mid = (l + r) >> 1;
		if (f(mid) > 0)
			l = mid;
		else
			r = mid;
	}
	cout << r << endl;
	return 0;
}
*/

/*
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> like(k + 1, 0);

	rep(i, 0, n) {
		int t;
		cin >> t;
		like[t]++;
	}
	int res = n / 2 + (n % 2 ? 1 : 0);
	int a, b;
	a = b = 0;
	rep(i, 1, k + 1) {
		res -= like[i] / 2;
		a += like[i] / 2;
		like[i] %= 2;
	}
	b = res;
	cout << 2 * a + b << endl;

	return 0;
}
*/

/*
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	if (n <= m && n <= k)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
*/
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		vector<int> v1(n), v2(n);
		for (int i = 0; i < n; i++)
			cin >> v1[i];
		for (int i = 0; i < n; i++)
			cin >> v2[i];
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end(), greater<int>());

		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += v1[i] * v2[i];

		cout << ans << endl;
	}

	return 0;
}
*/

/*
#include <iostream>

int main() {
	int t;
	while (cin >> t) {
		int sum = 0;
		if (t % 2)
			sum = t;
		for (int i = 0; i < 9; i++) {
			cin >> t;
			if (t % 2)
				sum += t;
		}
		cout << sum << endl;
	}
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
	int n, ret;
	
	while (cin >> n) {
		int year = 1960;
		for (int i = 0; i < n; i++) {
			ret = 5;
			bool run = isrun(year);
			if (run)
				ret += 366;
			else
				ret += 365;
			year++;
		}
		bool run = isrun(year);
		if (run)
			ret += 31 + 29 + 23;
		else
			ret += 31 + 28 + 23;
		cout << ret % 7 << endl;
	}
	

	return 0;
}
*/

/*
// 1051 ��������
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int is_prime(long long x) {
	if (x < 2) 
		return false;
	if (x % 2 == 0 && x != 2) 
		return false;
	for (long long i = 2; i*i <= x; ++i)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			string in;
			cin >> in;
			string re(in.rbegin(), in.rend());
			long long a = atoll(in.c_str());
			long long b = atoll(re.c_str());
			if (is_prime(a) && is_prime(b))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
	}

	return 0;
}
*/

/*
// 1037 �������?
int main()
{
	int n;
	long long int sum;
	while (cin >> n)
	{
		sum = 0;
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			sum += t;
		}
		cout << sum << endl;
	}
	return 0;
}
*/


/*
int main()
{
	int n;
	cin >> n;
	int ans=1;
	int i;
	for(i=1;i<n;i++)
	{
		ans += 4*i;
	}
	cout << ans;
	return 0;
}
*/

/*
ll in[3];

int main()
{
	ll d;
	for (int i = 0; i < 3; i++) {
		cin >> in[i];
	}

	cin >> d;

	sort(in, in + 3);

	ll q1 = in[1] - d;
	ll q2 = in[1] + d;

	ll ans = 0;
	if (abs(in[0]-in[1]) < d)
		ans += abs(in[0] - q1);
	if (abs(in[1] - in[2]) < d)
		ans += abs(in[2] - q2);

	cout << ans << endl;

	return 0;
}
*/


/*
#include <stdio.h>

int a[2002];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < 2 * n; i++) {
		scanf("%d", &a[i]);
	}

	sort(a, a + 2 * n);

	int sum1, sum2;
	sum1 = sum2 = 0;
	for (int i = 0; i < n; i++)
		sum1 += a[i];

	for (int i = n; i < 2 * n; i++)
		sum2 += a[i];

	if (sum1 == sum2) {
		printf("-1");
		return 0;
	}
	else {
		for (int i = 0; i < 2 * n; i++) {
			printf("%d ", a[i]);
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
	vector<int> v(2 * n);

	int sum = 0;
	for (int i = 0; i <  2 * n, i++) {
		cin >> v[i];
		sum += v[i];
	}

	sort(all(v));
	int sum1 = 0;
	for (int i = 0; i < n, i++) {
		sum1 += v[i];

	if (2 * sum1 == sum) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < 2 * n, i++) {
		cout << v[i] << ' ';
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
	bool even, odd;
	even = odd = false;
	rep(i, 0, n) {
		cin >> v[i];
		if (v[i] % 2 == 0) 
			even = true;
		else
			odd = true;
	}

	if (odd && even)
		sort(all(v));

	rep(i, 0, n)
		cout << v[i] << ' ';
	
	return 0;
}
*/

/*
char maze[3000][3000];
void dfs(int n, int x, int y) 
{
	if (n == 1) 
		maze[x][y] = 'X';
	else {
		int size = pow(3.0, n - 2);
		dfs(n - 1, x, y);
		dfs(n - 1, x, y + 2 * size);
		dfs(n - 1, x + size, y + size);
		dfs(n - 1, x + 2 * size, y);
		dfs(n - 1, x + 2 * size, y + 2 * size);
	}
	return;
}
int main(void) 
{
	int n;
	while (~scanf("%d", &n)) 
	{
		int size = pow(3.0, n - 1);
		for (int i = 0; i <= size; i++) 
			for (int j = 0; j <= size; j++) 
				maze[i][j] = ' ';

		dfs(n, 1, 1);
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				printf("%c", maze[i][j]);
			}
			printf("\n");
		}
		printf("-\n");
	}
	return 0;
}
*/

/*
int main()
{
	int n;
	while (cin >> n) {
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());

		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += a[i] * b[i];
		cout << ans << endl;
	}

	return 0;
}
*/

/*
int gcd(int a, int b);

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c) {
		cout << gcd(gcd(a, b), c) << endl;
	}

	return 0;
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
*/

/*
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while (n--) 
	{
		string a, b;
		char ta[100], tb[100];
		memset(ta, 0, 100);
		memset(tb, 0, 100);

		cin.getline(ta, 100);
		cin.getline(tb, 100);
		

		for(int i = 0; i < strlen(ta); i++)
			if (ta[i] != ' ')
				a.push_back(tolower(ta[i]));
		for (int i = 0; i < strlen(tb); i++)
			if (tb[i] != ' ')
				b.push_back(tolower(tb[i]));

		if (b == a)
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
	int n, k;
	while (cin >> n >> k)
	{
		int t = 0;
		if (20 * n < 200 + 20 * k || k >= n) {
			cout << "Impossible" << endl;
		}
		else {
			while (n * t < 200 + k * t)
				++t;
			cout << t << endl;
		}
	}

	return 0;
}
*/

/*
int n;
int main()
{
	while (cin >> n)
	{
		priority_queue<ll, vector<ll>, greater<ll>> q;
		int t;
		for (int i = 0; i < n; i++) 
		{
			cin >> t;
			q.push(t);
		}
		ll a, b;
		for (int i = 0; i < n - 1; i++) 
		{
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			q.push(a*b + 1);
		}
		ll ans = q.top();
		cout << ans << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int k;
	string n, ans;
	while (cin >> n >> k) 
	{
		ans.clear();
		for (int i = 0; i < n.size(); i++) 
		{
			if (k > 0)
			{
				if (ans.empty()) 
				{
					ans.push_back(n[i]);
					continue;
				}
				while (!ans.empty() && ans.back() < n[i] && k > 0 )
				{
					k--;
					ans.pop_back();
				}
				ans.push_back(n[i]);
			}
			else 
				ans.push_back(n[i]);
		}
		cout << ans << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) 
			cin >> v[i];
		
		float ans = -1;
		sort(v.begin(), v.end());
		for (int i = 0; i < n - 2; i++) 
		{
			for (int j = i + 1; j < n - 1; j++) 
			{
				for (int k = j + 1; k < n; k++) 
				{
					if (v[i] * v[i] + v[j] * v[j] == v[k] * v[k]) 
					{
						ans = max(ans, float(v[i]) * v[j] / 2);
					}
				}
			}
		}
		if (ans != -1)
			printf("%.3f\n", ans);
		else
			cout << "No" << endl;
	}

	return 0;
}
*/

/*
int main()
{
	vector<ll> v[11] = { 
		{0},
		{1, 2, 3, 4, 5, 6, 7, 8, 9,},
		{153, 370, 371, 407,},
		{1634, 8208, 9474,},
		{54748, 92727, 93084,},
		{548834,},
		{1741725, 4210818, 9800817, 9926315,},
		{24678050, 24678051, 88593477,},
		{146511208, 472335975, 534494836, 912985153,},
		{4679307774}
	};
	int n;
	while (cin >> n) {
		if (n == 2) 
			continue;
		if (n > 2) 
			n--;
		for (ll i : v[n]) {
			cout << i << endl;
		}
	}

	return 0;
}
*/
/*
int main()
{
	ll n, m;
	cin >> n >> m;
	int s = min(m, n);
	ll square = s * m*n- (s - 1)*s*(m+n)/2 + s * (2 * s - 1)*(s-1)/6;
	ll total = m * n*(n + 1)*(m + 1) / 4;
	cout << square << ' ' << total - square << endl;
	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
#define NUM 50 

struct event
{
	int start, end;
};

void GreedySelector(int n, event e[], bool select[])
{
	select[0] = true;
	int j = 0;
	for (int i = 1; i < n; i++)
	{
		if (e[i].start >= e[j].end)
		{
			select[i] = true;
			j = i;
		}
		else
			select[i] = false;
	}
}

bool cmp(event &l, event &r) {
	return l.start < r.start;
}

int main()
{
	event e[] = {
		{1,6}, {2,4}, {4,5}, {0,2}, {5,8},{4,11},
		{7,12},{6,8}, {8,9}, {10,11}, {4,8}, {3,4},
		{2,7},{12,15}
	};
	int n = (sizeof(e) / sizeof(e[0])) - 1;

	for (int i = 0; i < n; i++) {
		cout << "�" << i + 1 << "��ʼʱ��Ϊ��" << e[i].start << " " << "����ʱ��Ϊ��" << e[i].end << endl;
	}

	bool select[NUM];
	sort(e, e + n, cmp);

	GreedySelector(n, e, select);

	cout << "����ѡ��Ļ�?����Ϊ��" << endl;
	for (int i = 0; i < n; i++)
	{
		if (select[i])
			cout << "� " << i + 1 << endl;
	}
	return 0;
}
*/


/*
#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <algorithm>
using namespace std;

const int N = 30;
const float W = 150;

struct item {
	int w, v, id;
	float avg;
	bool select;
};

bool cmp(item &l, item &r) {
	return l.avg > r.avg;
}

bool cmpID(item &l, item &r) {
	return l.id < r.id;
}

void greedy(int n, float m, item it[]) {
	int i;

	float b = m;
	for (i = 0; i < n; i++) {
		if (it[i].w > b)
			continue;
		it[i].select = true;
		b -= it[i].w;
	}
}
int main() {
	srand((int)time(0));
	item it[30];
	for (int i = 0; i < 30; i++) {
		it[i].w = 5 + rand() % 10;
		it[i].id = i;
		it[i].select = false;
	}
	for (int i = 0; i < 30; i++) {
		it[i].v = 1 + rand() % 10;
		it[i].avg = 1.0 * it[i].v / it[i].w;
	}
	
	printf("�����������ɵ�����Ϊ��%f\n", W);
	printf("��Ʒ�ĸ���Ϊ: %d\n", N);
	printf("��Ʒ�������ͼ�ֵ�ֱ�Ϊ��\n");
	for (int i = 0; i < 30; i++) {
		printf("��Ʒ%2d  ����%f  ��ֵ%f\n", i + 1, 1.0 * it[i].w, 1.0 * it[i].v);
	}
	
	sort(it, it + N, cmp);
	greedy(N, W, it);
	printf("װ��ʱѡ���ˣ�\n");
	int sumW, sumV;
	sumW = sumV = 0;
	for (int i = 0; i < N; i++) {
		if (it[i].select == true) {
			printf("%d����Ʒ\n", i + 1);
			sumW += it[i].w;
			sumV += it[i].v;
		}
	}
	printf("������Ϊ : %d\n", sumW);
	printf("�ܼ�ֵΪ : %d\n", sumV);

	return 0;
}
*/


/*
int main() {
	int n;
	cin >> n;
	while (n > 4) 
	{
		cout << n << ",";
		cout << n + 1 << "-->";
		cout << 2 * n + 1 << ",";
		cout << 2 * n + 2 << endl;
		cout << 2 * n - 1 << ",";
		cout << 2 * n << "-->";
		cout << n << ",";
		cout << n + 1 << endl;
		n--;
	}
	cout << "4,5-->9,10\n8,9-->4,5\n2,3-->8,9\n7,8-->2,3\n1,2-->7,8";

	return 0;
}
*/

/*
int main()
{
	int n;
	while (cin >> n) {
		
		long ans = 0;
		
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			int ma;
			cin >> ma;
			for (int i = 0; i < t - 1; i++) {
				int a;
				cin >> a;
				ma = max(ma, a);
			}
			ans += ma;
		}
		cout << ans << endl;
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
		vector<int> visit(n + 15);
		bool first = true;
		int idx = 0;
		int cnt = 1;
		int pout = 0;
		while (pout != n)
		{
			if (visit[idx] == 1) // ��out
			{
				idx = (idx + 1) % n;
				continue;
			}

			if (cnt % m == 0)
			{
				pout++;
				visit[idx] = 1;

				if (first)
					first = false;
				else
					cout << ' ';
				cout << idx + 1;
			}
			idx = (idx + 1) % n;
			cnt++;
		}
		cout << endl;
	}

	return 0;
}
*/

/*
const int N = 10110;
bool pd[N];
bool ff(int x) 
{
	while (x) 
	{
		if (x % 10 == 4)
			return false;
		if (x % 10 == 2)
			return false;
		x = x / 10;
	}
	return true;
}

int main() 
{
	int x, res;
	for (int i = 1; i < N; i++)
		if (ff(i))
			pd[i] = 1;

	while (cin >> x) 
	{
		res = 0;
		for (int i = 1; i < x; ++i) 
		{
			if (pd[i] == 0) 
				continue;
			for (int j = i + 1; j < x; ++j) 
			{
				if (pd[j] == 0) 
					continue;
				int k = x - i - j;
				if (k > j && pd[k]) 
					res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}
*/

/*
struct M {
	int n;
	vector<vector<long long>> v;
};

M roate(M &oth) {
	M res;
	res.n = oth.n;
	res.v = vector<vector<long long>>(res.n, vector<long long>(res.n));
	for (int i = 0; i < oth.n; i++) {
		for (int j = 0; j < oth.n; j++) {
			res.v[i][j] = oth.v[oth.n - j - 1][i];
		}
	}
	return res;
}

M operator+(M &l, M &r) {
	M res;
	res.n = l.n;
	res.v = vector<vector<long long>>(res.n, vector<long long>(res.n));
	for (int i = 0; i < l.n; i++) {
		for (int j = 0; j < l.n; j++) {
			res.v[i][j] = l.v[i][j] + r.v[i][j];
		}
	}
	return res;
}

int main()
{
	int n;
	while (cin >> n) {
		M m[4];
		m[0].n = n;
		m[0].v = vector<vector<long long>>(n, vector<long long>(n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> m[0].v[i][j];
		M sum = m[0];
		for (int i = 1; i < 4; i++) {
			m[i] = roate(m[i - 1]);
			sum = sum + m[i];
		}
		int k;
		cin >> k;
		M ans = m[0];
		for (int i = 1; i <= k % 4; i++)
			ans = ans + m[i];

		for (int i = 0; i < ans.n; i++) {
			for (int j = 0; j < ans.n; j++) {
				sum.v[i][j] *= k / 4;
			}
		}
		ans = ans + sum;
		for (int i = 0; i < ans.n; i++) {
			for (int j = 0; j < ans.n; j++) {
				if (j != 0)
					cout << ' ';
				cout << ans.v[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
*/

/*
int f(int n, int m);

int main() {
	int n, m;
	while (cin >> n >> m) {
		cout << f(n, m) << endl;
	}

	return 0;
}

int f(int n, int m) {
	int i, s = 0;
	for (i = 2; i <= n; i++)
		s = (s + m) % i;
	return (s + 1);
}
*/

/*
int main() {
	int n;
	while (cin >> n) {
		n /= 10;
		int res = n + (n / 5) * 2 + (n % 5) / 3;
		cout << res << endl;
	}

	return 0;
}
*/

/*
int f[10010];
int a[3010], b[3010];

void init()
{
	a[1] = 1, b[1] = 2;
	f[1] = f[2] = 1;
	for (int i = 1; i <= 3000; i++)
	{
		for (int j = i; j <= i * 3; j++)
		{
			if (!f[j]) {
				f[j] = 1;
				f[j + i + 1] = 1;
				a[i + 1] = j;
				b[i + 1] = j + i + 1;
				break;
			}
		}
	}
}

int main()
{
	init();
	int n;
	while (cin >> n) {
		cout << a[n] << '/' << b[n] << endl;
	}

	return 0;
}
*/
/*
int f(int n);
int g(int n);

int main()
{
	string in;
	while (cin >> in)
	{
		int res = 0;
		for (int i = 1; i < 291343; i++)
		{
			int t = i * 7371;
			if (g(t) > in.size())
				break;
			if (g(t) == in.size())
			{
				if (f(t) == 1) {
					if (res == 0)
						res = t;
					else {
						res = -1;
						break;
					}
				}
			}
		}
		if (res > 0)
			cout << res << endl;
		else
			cout << "wrong" << endl;
	}

	return 0;
}

int f(int n) {
	return (n / 100) % 10;
}

int g(int n) {
	return log10(n) + 1;
}
*/

/*
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	int n;

	vector<int> v(n);
	while (cin >> n)
	{
		if (n == 0)
			break;
		v.clear();
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int ans = n * (n - 1) / 2;
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (gcd(v[i], v[j]) != 1)
					ans--;
		cout << ans << endl;
	}

	return 0;
}
*/


/*
void countRect(int m, int n, long long *Square, long long *Rect)
{
	*Square = *Rect = 0;
	*Rect = m * (m + 1) / 2;
	*Rect *= n * (n + 1) / 2;
	while (m > 0 && n > 0) {
		*Square += m * n;
		m--, n--;
	}
	*Rect -= *Square;
}

int main()
{
	long long n, m;
	while (cin >> n >> m) {
		long long a, b;
		countRect(n, m, &a, &b);
		cout << a << ' ' << b << endl;
	}

	return 0;
}
*/


/*
int main()
{
	string in;
	while (getline(cin, in)) {
		stringstream s;
		s << in;
		int res = 0;
		s >> res;
		char op;
		int r;
		while (s >> op >> r) {
			if (op == '+')
				res += r;
			else
				res -= r;
		}
		cout << res << endl;
	}

	return 0;
}
*/


/*
int main()
{
	int n;
	cin >> n;

	vector<string> hm = { "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet" };
	vector<string> tz = { "imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau" };

	while (n--) {
		int a, b;
		string in;
		cin >> a >> in >> b;
		int t = find(hm.begin(), hm.end(), in) - hm.begin();
		int day = 20 * t + a + 365 * b;
		int ryear = day / 260;
		day %= 260;
		int rmon = day % 20;
		int rday = day % 13;
		cout << rday + 1 << " " << tz[rmon] << " " << ryear << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n, ma, da, s, mb, db;
	cin >> n;

	int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (n--) {
		cin >> ma >> da >> s >> mb >> db;
		int day = 0;
		for (int i = ma; i < mb; i++)
			day += days[i - 1];
		day += db - da;
		cout << (s << day) << endl;
	}

	return 0;
}
*/

/*
int main()
{
	string a, b;
	while (cin >> a >> b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		vector<int> ans(300);

		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				ans[i + j] += (a[i] - '0') * (b[j] - '0');
				if (ans[i + j] >= 10) {
					ans[i + j + 1] += ans[i + j] / 10;
					ans[i + j] %= 10;
				}
			}
		}
		int end = a.size() + b.size();
		while (ans[end] == 0) end--;
		for (int j = end; j >= 0; j--)
			cout << ans[j];
		cout << endl;
	}

	return 0;
}
*/

/*
int64_t fib[50] = { 1,1 };

int main()
{
	for (int i = 2; i < 40; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	int n;
	while (cin >> n) {
		cout << fib[n] << endl;
	}

	return 0;
}
*/
/*
int main()
{
	string a, b;
	while (cin >> a >> b) {
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		vector<int> ans(300);

		int i = 0;
		int l = max(a.size(), b.size());
		while (i < l) {
			if (i < a.size()) ans[i] += a[i] - '0';
			if (i < b.size()) ans[i] -= b[i] - '0';
			if (ans[i] < 0) {
				ans[i] += 10;
				ans[i + 1]--;
			}
			i++;
		}
		while (ans[i] == 0) i--;
		for (int j = i; j >= 0; j--)
			cout << ans[j];
		cout << endl;
	}

	return 0;
}
*/

/*
int trans(int n, int b) {
	int res = 0, c = 0;
	while (n > 0) {
		int t = n % 10;
		if (t >= b) return -1;
		res += t * pow(b, c++);
		n /= 10;
	}
	return res;
}

int main()
{
	int T;
	int p, q, r, tp, tq, tr;
	cin >> T;
	while (T--) {
		bool flag = true;
		cin >> p >> q >> r;
		for (int i = 2; i <= 16; i++) {
			tp = trans(p, i);
			tq = trans(q, i);
			tr = trans(r, i);

			if (tp == -1 || tq == -1 || tr == -1)
				continue;

			if (tp * tq == tr) {
				cout << i << endl;
				flag = false;
				break;
			}
		}
		if (flag)
			cout << 0 << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n, m;
	while (cin >> n >> m) {
		vector<int> v(n + 1, 1);
		for (int i = 0; i < m; i++) {
			int l, r;
			cin >> l >> r;
			for (int j = l; j <= r; j++)
				v[j] = 0;
		}
		cout << count(v.begin(), v.end(), 1) << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n, i;
	while (cin >> n) {
		bool flag = true;
		while (n != 1) {
			i = 2;
			while (n % i != 0) i++;
			n /= i;
			if (flag) {
				cout << i;
				flag = false;
			}
			else
				cout << " " << i;
		}
		cout << endl;
	}

	return 0;
}
*/

/*
int v[1005][1005];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			v[i][j] += min(v[i + 1][j], v[i + 1][j + 1]);
		}
	}

	cout << v[0][0] << endl;

	return 0;
}
*/

/*
int main()
{
	int n,a,x,b,y;
	cin >> n >> a >> x >> b >> y;
	int t = 0;
	while(true) {
		if (a == b) {
			cout << "YES" << endl;
			return 0;
		}
		if (a == x || b == y)
			break;
		
		a++;
		b--;
		if (a > n) a = 1;
		if (b < 1) b = n;
	} 
	cout << "NO" <<endl;
	
	return 0;
}

/*
int main()
{
	int n, x;
	cin >> n >> x;
	if (n <= 10 * x)
		cout << 10;
	int ans = 10;
	while(ans * x > n)

	return 0;
}
*/

/*
long long cnt(int m, int n)
{
	if (m <= 0 || n <= 0)
		return 0;
	vector<long long> data(n, 1);
	long long cur = 0;
	for (int i = 1; i < m; ++i)
	{
		cur = 1;
		for (int j = 1; j < n; ++j)
		{
			cur = cur + data[j];
			data[j] = cur;
		}
	}
	return data[n - 1];
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << cnt(n, m);

	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
		cin >> A[i];
	deque<int> q;
	for (int i = 0; i < n; i++) A.push_back(A[i]);
	vector<int> s(2 * n + 1);

	for (int i = 1; i < 2 * n; i++) {
		s[i] = s[i - 1] + A[i - 1];
	}
	q.push_back(0);
	int res = INT_MIN;

	for (int i = 1; i < 2 * n; i++) {
		if (q.size() && i - n > q.front()) q.pop_front();
		if (q.size()) res = max(res, s[i] - s[q.front()]);
		while (q.size() && s[q.back()] > s[i]) q.pop_back();
		q.push_back(i);
	}
	cout << res;
	
	return 0;
}
*/

/*
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, x;
		cin >> n >> x;
		int md, mh;
		md = mh = 0;
		rep(i, 0, n) {
			int a, b;
			cin >> a >> b;
			md = max(md, a);
			mh = max(mh, a - b);	
		}
		int res = 1;
		if (x - md > 0) {
			if (mh <= 0) res = -1;
			else res += (x - md + mh - 1) / mh;
		}
		cout << res << endl;
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
		int a, b, e;
		cin >> a >> b >> e;
		int minAddStr = max(0, (e + b - a + 2) / 2);
		cout << max(e - minAddStr + 1, 0) << endl;
	}
	return 0;
}
*/

/*
int main()
{
	int n;
	string in,out;
	cin >> n >> in;
	rep(i, 0, n) {
		if (out.size() % 2 == 0 || out.back() != in[i])
			out.push_back(in[i]);
	}
	if (out.size() % 2 == 1) out.pop_back();
	cout << n - out.size() << endl;
	cout << out << endl;

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
	sort(all(v));

	int ans = 0, j = 0;
	rep(i, 0, n){
		for(; j < n; j++) {
			if ((i+1) <= v[j]){
				ans++;
				j++;
				break;
			}
		}
		if (j == n) break;
	}

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	string in;
	cin >> in;
	in = in.substr(n-x);
	//cout << in << endl;

	int ans = 0;
	for(int i = in.size() - 1, j = 0; i >= 0; i--,j++) {
		if (j == y) {
			if (in[i] == '0')
				ans++;
		} else {
			if (in[i] == '1')
				ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
*/

/*
const int MAX = 600000;

int pre[MAX], val[MAX];

int _find(int x) {
	int a = x;
	while(x != pre[x]) {
		x = pre[x];
		val[a]++;
	}
	return x;
}

int _find1(int x) {
	int a = x;
	while(x != pre[x]) {
		x = pre[x];
	}
	return x;
}

int main()
{
	int n,m;
	rep(i, 0, MAX) {
		pre[i] = i;
		val[i] = 1;
	}
	cin >> n >> m;
	rep(i, 0, m) {
		int N;
		cin >> N;
		if (N == 0)
			continue;

		int a,b;
		cin >> a;
		rep(j, 0, N - 1) {
			cin >> b;
			a = _find(a);
			b = _find(b);
			if (a != b) {
				if (val[a] > val[b]) {
					pre[b] = a;
					val[a] += val[b];
				}
				else {
					pre[a] = b;
					val[b] += val[a];
				}
			}
		}
	}

	rep(i, 1, n + 1) {
		pre[i] = _find1(pre[i]);
		val[i] = val[_find(pre[i])];
	}
	rep(i, 1, n + 1)
		cout << val[i] << " ";

	return 0;
}
*/

/*
int main()
{
	int v[] = {4,8,15,16,23,42};
	map<int, pii> mp;
	rep(i, 0, 6) {
		rep(j, i + 1, 6) {
			mp[v[i] * v[j]] = {v[i], v[j]};
			//cout << v[i] * v[j] << " " << v[i] << " " << v[j] << endl;
		}
	}

	vector<pii> vec(6);
	vector<int> ans(6);
	rep(i, 0, 4) {
		cout << "? " <<  1 << " " << 1 + i + 1 << endl;
		fflush(stdout);

		int t;
		cin >> t;
		vec[i] = mp[t];
	}

	if (vec[0].first == vec[1].first || vec[0].first == vec[1].second)
		ans[0] = vec[0].first;
	else
		ans[0] = vec[0].second;

	rep(i, 1, 5) {
		ans[i] = ans[0] == vec[i-1].first ? vec[i-1].second : vec[i-1].first;
	}
	rep(i, 0, 6) {
		rep(j, 0, 5) {
			if (v[i] == ans[j]) {
				v[i] = 0;
				break;
			}
		}
	}
	rep(i, 0, 6) {
		if (v[i] != 0) {
			ans[5] = v[i];
			break;
		}
	}

	cout << "! ";
	rep(i, 0, 6)
		cout << ans[i] << " ";

	return 0;
}
*/

/*
int main()
{
	int T,n;
	cin >> T;
	while(T--) {
		cin >> n;
		string str;
		cin >> str;
		auto pos = str.find_first_of('8');
		if (pos != string::npos && str.size() - pos >= 11 )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	// 1234
	// 0123
	return 0;
}
*/

/*
int main()
{

	int n;
	string a;
	vector<int> f(10), diff(10);
	cin >> n >> a;
	rep(i, 1, 10) {
		cin >> f[i];
		diff[i] = f[i] - i;
	}

	rep(i, 0, a.size()) {
		//cout << i << " : " << a[i] << " , " << diff[a[i] - '0'] << endl;
		if (diff[a[i] - '0'] > 0) {
			int j = i;
			while(j < a.size() && diff[a[j] - '0'] >= 0) {
				//cout << j << " : " << a[j] << " , " << diff[a[j] - '0'] << endl;
				a[j] = f[a[j] - '0'] + '0';
				j++;
			}
			break;
		}
	}
	cout << a << endl;

	return 0;
}
*/

/*
int f(int x) {
	x++;
	while(x % 10 == 0) x/= 10;
	return x;
}

int main()
{
	int n; set<int> ans;
	cin >> n;
	while(1) {
		ans.insert(n);
		n = f(n);
		if (ans.find(n) != ans.end())
			break;
	}

	cout << ans.size() << endl;

	return 0;
}
*/

/*
int x;

bool ok(int z) {
	z++;
	while(z % 2 == 0) {
		z /= 2;
	}
	return (z == 1);
}

int MSB(int z) {
	for (int i = 20; i >= 0; i--) {
		if ((z>>i) & 1) return i;
	}
	return -1;
}

int main()
{
	int i = 0; vector<int> xorCmd;
	cin >> x;
	while( !ok(x) ) {
		i = i + 1;
		if (i % 2 == 0) {
			x++;
			continue;
		}
		int r = MSB(x);
		if ((1 << r) != x) {
			r++;
		}
		x = (x ^ ((1<<r) - 1));
		xorCmd.push_back(r);
	}
	cout << i << endl;
	for(auto z : xorCmd)
		cout << z << " ";

	return 0;
}
*/

/*
int main()
{
	int n,k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, 0, n) cin >> a[i];

	vector<ll> d1(n), d2(n), d3(n);
	ll ans = 0;
	rep(i, 0, n) {
		d1[i] = a[i] + ((i > 0 && d1[i-1] > 0) ? d1[i-1] : 0);
		ans = max(ans, d1[i]);
	}

	rep(i, 0, n) {
		d2[i] = k * a[i] + (i > 0 ? max(max(d2[i-1], d1[i-1]), 0ll) : 0ll);
		ans = max(ans, d2[i]);
	}

	if (n > 1)
		ans = max(ans, d3[1] = a[0] * k + a[1]);

	rep(i, 2, n) {
		d3[i] = a[i] + max(d3[i-1], d2[i-1]);
		ans = max(ans, d3[i]);
	}

	cout << ans << endl;

	int n, m, t;
	int ca, cb, ka, kb;
	ca = cb = ka = kb = 0;
	cin >> n >> m;
	rep(i, 0, n) {
		cin >> t;
		if (t % 2 == 0)
			ca++;
		else
			cb++;
	}
	rep(i, 0, m) {
		cin >> t;
		if (t % 2 == 0)
			ka++;
		else
			kb++;
	}

	cout << min(ca, kb) + min(cb, ka) << endl;

	return 0;
}
*/

/*
int main()
{
	int n, m, c = 0;
	while (cin >> n >> m && n && m) {
		c++;
		vector<string> in(n);
		rep(i, 0, n)
			cin >> in[i];
		vector<vector<int>> out(n + 2, vector<int>(m + 2));
		rep(i, 1, n + 1) rep(j, 1, m + 1) {
			if (in[i - 1][j - 1] == '*') {
				out[i - 1][j - 1]++;
				out[i - 1][j    ]++;
				out[i - 1][j + 1]++;
				out[i    ][j - 1]++;
				out[i    ][j + 1]++;
				out[i + 1][j - 1]++;
				out[i + 1][j    ]++;
				out[i + 1][j + 1]++;
			}
		}

		cout << "Field #" << c << ":" << endl;
		rep(i, 0, n) {
			rep(j, 0, m) {
				if (in[i][j] == '.')
					cout << out[i + 1][j + 1];
				else
					cout << "*";
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
*/

/*
int main()
{
	int n,k;


	return 0;
}

/*
int main()
{
	int n,m;
	cin >> n >> m;
	vector<ll> x(n), p(m);
	rep(i, 0, n)
		cin >> x[i];
	rep(i, 0, m)
		cin >> p[i];

	vector<ll> d(n-1);
	rep(i, 0, n-1)
		d[i] = x[i+1] - x[i];
	ll g = d[0];
	rep(i, 0, n-1)
		g = __gcd(g, d[i]);
	int ans = 0;
	rep(i, 0, m) {
		if (g % p[i] == 0) {
			ans = i + 1;
			break;
		}
	}

	if (ans) {
		cout << "YES" << endl;
		cout << x[0] << " " <<
		ans << endl;
	}
	else {
		cout << "NO" << endl;
	}


	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	string in;
	cin >> in;
	int t = count(in.begin(), in.begin() + n - 11, '8');
	if (t > (n-11)/2 || (t == (n-11)/2 && in[n-11] == '8') )
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
*/

/*
int main()
{
	int n;
	string in;
	cin >> n >> in;
	map<char, int, greater<char>> mp;
	rep(i, 0, n) {
		if (i != 0) {
			// cout << "\t" << mp.begin()->first << endl;
			if (mp.begin()->first > in[i]) {
				cout << "YES" << endl;
				cout << mp.begin()->second + 1 << " " << i + 1 << endl;
				exit(0);
			}
		}
		mp[in[i]] = i;
	}

	cout << "NO" << endl;

	return 0;
}
*/
/*
int main()
{
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		int x, r = 0;
		for(int d=1; d<=n; d <<= 1) {
			vector<int> a,b;
			for(int i=1; i <=n;i++)
				(i&d?a:b).push_back(i);
			cout << a.size() << " " << b.size() << " ";
			for(auto e:a) cout << e << " ";
			for(auto e:b) cout << e << " ";
			cout << endl;
			cout.flush();
			cin >> x;
			// cout << "xxx" << x << "xxx" << endl;
			if (x == -1)
				exit(0);
			r = max(r, x);
		}
		cout << "-1 " << r <<endl;
		cout.flush();
	}

	return 0;
}
*/

/*
void fk() {
	cout << ":(" << endl;
	exit(0);
}

int main()
{
	string t;
	cin >> t;

	int cnt = 0, pos = -1;
	rep(i, 0, t.size()) {
		if (t[i] == 'a') ++cnt;
		if (2*(i+1) - cnt == t.size()) {
			pos = i;
			break;
		}
	}
	if (pos == -1)
		fk();
	int cur = 0;
	rep(i, pos + 1, t.size()) {
		if (t[i] == 'a')
			fk();
		while(t[cur] == 'a') ++cur;
		if (t[cur] != t[i])
			fk();
		++cur;
	}
	cout << t.substr(0, pos + 1) << endl;
	return 0;
}
*/

/*
int main()
{
	string in;
	cin >> in;
	int a = count(all(in), 'a');
	int b = (int)in.size() - a;
	if (!a) cout << 0 << endl;
	while (a <= b && b > 0) b--;
	if (a > b && b >= 0) cout << a + b << endl;
	return 0;
}
*/

/*
int main()
{
	int n;
	cin >> n;
	vector<pii> v(n);
	rep(i, 0, n)
		cin >> v[i].first >> v[i].second;

	sort(all(v), [](auto a, auto b) {
		return a.first - a.second > b.first - b.second;
	});

	ll sum = 0;
	rep(i, 0, n) {
		sum += (i + 1ll - 1) * v[i].first + v[i].second * (n - (i + 1ll));
	}

	cout << sum << endl;

	return 0;
}
*/

/*
#define MOD 1000000007

ll f(ll x) {
	ll i, odd, even;
	odd = even = 0;
	for (i = 0; i < 64; ++i) {
		if (i % 2 == 0)
			odd += 1ll << i;
		else
			even += 1ll << i;
		x -= 1ll << i;
		if (x <= 0) break;
	}
	if (x < 0) {
		if (i % 2 == 0)
			odd += x;
		else
			even += x;
	}
	even %= MOD;
	odd %= MOD;

	return (((even * (even + 1)) % MOD) + ((odd*odd) % MOD)) % MOD;
}

int main()
{
	ll l, r;
	cin >> l >> r;
	cout << (f(r) - f(l - 1) + MOD) % MOD << endl;

	return 0;
}
*/

/*
int main()
{
	FASTIO;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));

	rep(i, 0, n) rep(j, 0, m)
		cin >> a[i][j];

	int cur = 0;
	rep(i, 0, n) {
		cur ^= a[i][0];
	}

	if (cur > 0) {
		cout << "TAK" << endl;
		rep(i, 0, n) cout << 1 << " ";
		return 0;
	}

	int px = -1, py = -1;

	for (int i = 0; i < n && py == -1; ++i) {
		rep(j, 0, m) {
			int res = cur ^ a[i][0] ^ a[i][j];
			if (res > 0) {
				px = i, py = j;
				cur = res;
				break;
			}
		}
	}
	if (cur > 0) {
		cout << "TAK" << endl;
		rep(i, 0, n) {
			cout << (i == px ? py + 1 : 1) << " ";
		}
	}
	else
		cout << "NIE" << endl;

	return 0;
}
*/

/*
int fk(string &str, int x) {
	char s[5] = "ACTG";
	int res = 0;
	rep(i, 0, 4) {
		res += min(abs(str[i + x] - s[i]), 26 - abs(str[i + x] - s[i]));
	}
	return res;
}

int main()
{
	int n;
	string str;
	cin >> n >> str;

	int ans = INF;
	rep(i, 0, n - 4 + 1)
		ans = min(ans, fk(str,i));

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	int n, k;
	cin >> n >> k;
	vector<pii> a(n);
	rep(i, 0, n) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(all(a), greater<pii>());
	queue<int> q;
	rep(i, 0, n)
		q.push(a[i].second);

	set<int> idx;
	rep(i, 0, n)
		idx.insert(i);
	string ans(n, '0');
	int who = 0;
	while (!idx.empty()) {
		while (!idx.count(q.front()))
			q.pop();
		int pos = q.front();
		q.pop();

		vector<int> add;
		auto it = idx.find(pos);
		rep(i, 0, k + 1) {
			add.push_back(*it);
			if (it == idx.begin()) break;
			--it;
		}
		it = next(idx.find(pos));
		rep(i, 0, k) {
			if (it == idx.end()) break;
			add.push_back(*it);
			++it;
		}
		for (auto it : add) {
			idx.erase(it);
			ans[it] = '1' + who;
		}
		who ^= 1;
	}

	cout << ans << endl;

	return 0;
}
*/

/*
int main()
{
	int n,a,b;
	cin >> n >> a >> b;
	int ea,eb;
	ea = a, eb = b;
	int ans = 0;
	while(n > 0 && (ea > 0 || eb > 0)) {
		n--;
		int light;
		cin >> light;
		if (light) {
			if (ea == 0 || eb == b) {
				eb--;
			}
			else {
				ea--;
				eb = min(eb+1, b);
			}
		}
		else {
			if (eb > 0) {
				eb--;
			}
			else {
				ea--;
			}
		}
		ans++;
	}

	cout << ans << endl;

	return 0;
}
*/

/*
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
*/

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
		// w ???��?? ????
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
