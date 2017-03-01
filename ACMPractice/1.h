#pragma once

/*void main()
{
int n,m,i,num;
while (~scanf("%d%d", &n, &m))
{
num = n / m;
printf("%d ", m + 1);
for (i = 2; i < num + 1; ++i)
printf("%d ", 2*m*i-m+1);
if (i == 2)
i = 1;
else
--i;
if (n%m != 0)
printf("%d", (n*(n + 1) - m*i*(m*i + 1))/(n%m));
printf("\n");

for (i = 1; i <= n - m; i += m) {
printf("%d ", 2 * i + m - 1);
}
printf("%d\n", i + n);
}
}*/
/*
#include<stdio.h>
int main() {
int n, m, i, j;
while (~scanf("%d %d", &n, &m)) {
getchar();
for (i = 1; i <= n - m; i += m) {
printf("%d ", 2 * i + m - 1);
}
printf("%d\n", i + n);
}
}*/