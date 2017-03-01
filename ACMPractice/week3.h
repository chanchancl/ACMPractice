#pragma once


#include "stdafx.h"


// y[3] += y[2];
//

/*int f(int m, int n)
{
int dp[101][101];
for (int m = 1; m <= 100; ++m)
for (int n = 1; n <= 100; ++n)
{
if (m == 1 || n == 1)
dp[m][n] = 1;
else if (m>n)
dp[m][n] = dp[m][n - 1] + dp[m - n][n];
else if (m == n)
dp[m][n] = dp[m][n - 1] + 1;
else//m>n
dp[m][n] = dp[m][m];
}
return dp[m][n];
}*/
/*
#include <stdio.h>
int f(int m, int n)
{
if (m == 0 || n == 1)
return 1;
if (m<n)
return f(m, m);
return f(m, n - 1) + f(m - n, n);
}
int main()
{
int m[100], n[100],c,i;
scanf("%d", &c);
for (i = 0; i < c; ++i)
scanf("%d%d", &m[i], &n[i]);
for (i = 0; i < c; ++i)
printf("%d\n", f(m[i], n[i]));
return 0;
}*/

/*
int mod(int a, int b)
{
int c;
c = a / b;
if (c*b == a)
return 0;
else
return a - c*b;
}
void main()
{
int a, b;
while (~scanf("%d%d", &a, &b))
printf("%d\n", mod(a, b));
}*/


#include <stdlib.h>
#include <string.h>
int out[100] = { 0 };
int ret[100] = { 0 };
int n, s;

int FindStart(int start)
{
	int i = start;
	if (i > n)
		i -= n;
	while (out[i])
	{
		++i;
		if (i > n)
			i -= n;
	}
	return i;
}
int Count(int start)
{
	int c = 0, i;
	if (start > n)
		start -= n;
	for (i = 0; i < s - 1; ++i)
	{
		c += FindStart(start + 1) - (start + 1);
		start += c + 1;
	}
	return c;
}

void main()
{
	int i, n, w, start, current, go, remain;
	char **name;
	char Buffer[50];
	scanf("%d", &n);
	name = (char**)malloc(sizeof(char*)*n);
	for (i = 0; i < n; ++i)
	{
		scanf("%s", Buffer);
		*(name + i) = (char*)malloc(sizeof(char) * 50);
		strcpy(*(name + i), Buffer);
	}
	scanf("%d,%d", &w, &s);

	start = w;
	current = start;
	go = 0;
	remain = n;
	while (remain >= s)
	{
		start = FindStart(current);
		if (start > n)
			start -= n;
		go = s - 1 + Count(start);
		current = start + go;
		if (current > n)
			current -= n;
		out[current] = 1;
		ret[n - remain] = current;
		--remain;
	}
	while (remain)
	{
		current = FindStart(current);
		if (current > n)
			current -= n;
		out[current] = 1;
		ret[n - remain] = current;
		--remain;
	}

	for (i = 0; i < n; ++i)
	{
		printf("%s\n", *(name + ret[i] - 1));
		free(*(name + ret[i] - 1));
	}
	free(name);
}



/*
int find(int x, int y)
{
int i;
int c = x < y ? x : y;
for (i = c; i >=2 ;--i)
{
if ( x % i == 0 && y % i == 0)
return i;
}
return 0;
}
void main()
{
int a[100], b[100], c[100], d[100];
int x, y, z,n,i;
char op[100];
n = 0;
while (~scanf("%d/%d%c%d/%d", &a[n], &b[n], &op[n], &c[n], &d[n]))
++n;
for( i=0; i< n; i++)
{
if (op[i] == '+')
x = a[i]*d[i] + b[i]*c[i];
else
x = a[i]*d[i] - b[i]*c[i];
y = b[i]*d[i];
if (x == 0 || y == 0)
printf("0\n");
else
{
while (z = find(x>0? x: -x, y>0 ? y:-y))
{
x /= z;
y /= z;
}
if (y != 1)
printf("%d/%d\n", x, y);
else
printf("%d\n", x);
}
}
}*/



/*
void main()
{
int current;
int y[3] = { 0 };
int _x, x[100],n;
n = 0;
while (~scanf("%d", &_x))
{
if (_x == 0)
break;
x[n++] = _x;
}
for (int j = 0; j < n; ++j)
{
current = 1;
y[0] = y[1] = y[2] = 0;
for (int i = 0; i < x[j]-1; ++i)
{
current += y[2];
y[2] = y[1];
y[1] = y[0];
y[0] = current;
}
printf("%d\n", current + y[2] + y[1] + y[0]);
}
}*/


/*
#include <string.h>
#include <stdlib.h>
void main()
{
char Buffer[512];
char *p;
char ch;
int IsText = 0;
char Pass[] = "VWXYZABCDEFGHIJKLMNOPQRSTU";
char **Text;
int n = 0,i;
Text = (char**)malloc(101 * sizeof(char*));
while (1)
{
p = Buffer;
while ( (ch = getchar()) != '\n')
*p++ = ch;
*p = '\0';
IsText = 1;
if (strcmp(Buffer, "START") == 0)
IsText = 0;
else if (strcmp(Buffer, "END") == 0)
IsText = 0;
else if (strcmp(Buffer, "ENDOFINPUT") == 0)
break;
if (IsText)
{
*(Text + n) = (char*)malloc(sizeof(char) * 201);
strcpy(*(Text + n), Buffer);
++n;
}
}
for (i = 0; i < n; ++i)
{
for (p = *(Text + i); *p != '\0'; ++p)
{
if (*p >= 'A' && *p <= 'Z' )
*p = Pass[((int)*p) - 'A'];
}
printf("%s\n", *(Text + i));
free(*(Text + i));
}
free(Text);
}*/


/*
#include <math.h>
int IsPrimer(int n)
{
if (n == 0)
return 0;
for (int i = 2; i < sqrt(n)+1; ++i)
if (n % i == 0)
return 0;
return 1;
}
void main()
{
int _x, _y,n;
int x[100], y[100], i,flag;
n = 0;
while (~scanf("%d%d", &_x, &_y))
{
if (_x == 0 && _y == 0)
break;
x[n] = _x;
y[n++] = _y;
}
for(int j = 0; j< n; ++j)
{
for (i = x[j]; i <= y[j]; ++i)
{
flag = 0;
if (!IsPrimer(i*i + i + 41))
{
printf("Sorry\n");
flag = 1;
break;
}
}
if (!flag)
printf("OK\n");
}
}*/



// 1
// d1 * 3.7/100 * ÌìÊý/365
// money = d1*(1.0f+d3/100*d2/365.0f)
// money = moeny*(1 + d5/100)
// money = d1*(1.0f+d3/100*d2/365.0f)*(1 + d5/100)

// 2
// money = d1*(1+d4/100*(d2+365)/365)

/*void main()
{
int n,i;
float d1[100], d2[100], d3[100], d4[100], d5[100];
while (~scanf("%d", &n))
{
for(i=0; i < n; ++i)
scanf("%f%f%f%f%f", &d1[i], &d2[i], &d3[i], &d4[i], &d5[i]);
for (i = 0; i < n; ++i)
printf("%.1f\n%.1f\n", d1[i]*(1.0f + d3[i] / 100 * d2[i] / 365.0f)*(1 + d5[i] / 100),d1[i]*(1.0f + d4[i] / 100 * (d2[i] + 365) / 365));
}
}*/



/*#include <math.h>
void main()
{
float x1, y1, x2, y2;
while (~scanf("%f%f%f%f", &x1, &y1, &x2, &y2))
printf("%.2f\n", sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)));
}*/

/*void main()
{
int year, month, day;
int days_1[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int days_2[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int run,i;
while (~scanf("%d/%d/%d", &year, &month, &day))
{
run = 0;
if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
run = 1;
for (i = 0; i < month - 1; ++i)
{
if (run)
day += days_2[i];
else
day += days_1[i];
}
printf("%d\n", day);
}
}*/




