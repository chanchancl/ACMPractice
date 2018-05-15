
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