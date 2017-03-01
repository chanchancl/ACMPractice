#pragma once

#include <stdio.h>

void t11()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%.3lf\n",(a*b*c)/3.0);
}

void t12()
{
	int f;
	scanf("%d", &f);
	printf("%.3lf\n", (f - 32)*5.0 / 9.0);
}

void t13()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", n*(n + 1) / 2);
}

#define _USE_MATH_DEFINES
#include <math.h>
void t14()
{
	int n;
	scanf("%d", &n);
	printf("%lf %lf\n", sin(n*M_PI / 180.0),cos(n*M_PI/180.0));
}

void t15()
{
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	printf("%lf\n", sqrt((a - c)*(a - c) + (b - d)*(b - d)));
}

void t16()
{
	int n;
	scanf("%d", &n);
	printf(n % 2 == 0 ? "yes" : "no");
}

void t17()
{
	int n;
	scanf("%d", &n);
	printf("%.2lf\n", n > 3 ? n * 95 * 0.85 : n * 95);
}

void t18()
{
	double d;
	scanf("%lf", &d);
	printf("%lf\n", d > 0 ? d : -d);
}

void t19()
{
	int a, b, c, t;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b) { t = a; a = b; b = t; }
	if (a > c) { t = a; a = c; c = t; }
	if (b > c) { t = b; b = c; c = t; }
	if (a + b <= c)
		printf("not a triangle\n");
	else if (a*a + b*b == c*c)
		printf("yes");
	else
		printf("no");
}