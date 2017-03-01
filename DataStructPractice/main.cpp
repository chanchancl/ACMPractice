
#include "string.h"
#include "LCS.h"
#include <time.h>
#include "stirling.h"

void main()
{
#if 0
	string str1, str2;
	cin >> str1 >> str2;

	cout << "LCS1 : " << LCS1(str1.c_str(), str2.c_str(), str1.size(), str2.size()) << endl;
	reset();
	cout << "LCS2 : " << LCS2(str1.c_str(), str2.c_str(), str1.size(), str2.size()) << endl;
	reset();
	cout << "LCS3 : " << LCS3(str1.c_str(), str2.c_str(), str1.size(), str2.size()) << endl;
#endif

#if 0
	char a[100000], b[100000];

	int i;
	clock_t start, end, pass=0;
	int n = 10;
	printf("%-30s   %s\n", "a", "b");
	srand(time(NULL));
	while (n--)
	{
		for (i = 0; i < 30; ++i)
			a[i] = (rand() % 26) + 'a';
		a[i] = '\0';
		for (i = 0; i < 2; ++i)
			b[i] = (rand() % 26) + 'a';
		b[i] = '\0';
		start = clock();
		int x = KMP::Match(b, a);
		end = clock();
		pass += end - start;
		cout << a << "  " << b << "  " << x << endl;
	}
	cout << float(pass)/CLK_TCK << endl;
#endif
#if 1
	for (int i = 1; i <= 100; ++i)
		cout << bell(i) << endl;

#endif
}