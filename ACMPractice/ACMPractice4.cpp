
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

#define rep(i,a,b) for(int i=a; i < b; ++i)
#define pre(i,a,b) for(int i=a; i >=b; --i)
#define all(x) x.begin(),x.end()
using ll = long long;


int main()
{
	int n;
	cin >> n;
	list<int> v;
	rep(i, 0, n) {
		int t;
		cin >> t;
		v.push_back(t);
	}
	v.sort();

	while (v.size() > 1) {
		if (v.size() > 1)
			v.pop_back();
		if (v.size() > 1)
			v.pop_front();
	}
	cout << v.back();

	return 0;
}



/*
int main()
{
	int n, w;
	cin >> n >> w;
	vector<int> v(n);
	rep(i, 0, n) {
		cin >> v[i];
		if (i != 0)
			v[i] += v[i - 1];
	}

	int a = *max_element(all(v));
	int p = *min_element(all(v));
	int ans = w - (a > 0 ? a : 0) + 1 - (p < 0 ? -p : 0);
	if (abs(a) > w || abs(p) > w || ans <= 0)
		cout << 0;
	else
		cout << ans;

	return 0;
}
*/


/*
int n, r = -1;
vector<int> v;

int find(int id, int cnt, int a, int b) {
	int ans = 0;
	if (id >= n && (cnt < r || r == -1)) {
		r = cnt;
		return -1;
	}
	int c = v[id], t = -1;
	if (b - a == c - b || id < 2)
		t = find(id + 1, cnt, b, c);
	if (t == -1 && (b - a == c + 1 - b || id < 2))
		t = find(id + 1, cnt + 1, b, c + 1);
	if (t == -1 && (b - a == c - 1 - b || id < 2))
		t = find(id + 1, cnt + 1, b, c - 1);
	if (t == -1)
		return -1;

	ans += t;
	return ans;
}

int main()
{
	cin >> n;

	if (n <= 2)
	{
		cout << 0 << endl;
		return 0;
	}
	v.resize(n);
	rep(i, 0, n) cin >> v[i];

	find(0, 0, 0, 0);
	cout << r;

	return 0;
}
*/