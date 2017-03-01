#pragma once

int stirling(int k, int m)
{
	if (k == 0 && m == 0) return 1;
	else if (k == 0 || m == 0) return 0;
	else return k*stirling(k, m - 1) + stirling(k - 1, m - 1);
}

int bell(int m)
{
	int ret = 0;
	for (int i = 1; i <= m; ++i)
		ret += stirling(i, m);
	return ret;
}