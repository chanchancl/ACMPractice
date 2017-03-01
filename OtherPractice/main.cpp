
#include <stdio.h>
#include "t1.h"

double fact(double n)
{
	if (n == 0) return 1;
	return n * fact(n - 1);
}

double fib1(int n)
{
	if (n <= 0) return 0;
	if (n == 1) return 1;
	return fib1(n - 2) + fib1(n - 1);
}

__int64 memo[101];
__int64 fib2(__int64 n)
{
	if (n <= 1) return n;
	if (memo[int(n)] != 0) return memo[int(n)];
	return memo[int(n)] = fib2(n - 1) + fib2(n - 2);
}


int main()
{
#if 0
	//t11();
	//t12();
	//t13();
	//t14();
	//t15();
	//t16();
	//t17();
	//t18();
	t19();
#endif

	for (int i = 0; i < 101; ++i)
		printf("%d fact : %lld\n", i,fib2(i));

}