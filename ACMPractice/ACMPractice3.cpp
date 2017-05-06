
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <cmath>
#include <string>
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