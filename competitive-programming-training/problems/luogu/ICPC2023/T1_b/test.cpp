#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

inline long long read()
{
	char c = getchar();
	long long sum = 0;
	while (c < '0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')sum = (sum << 1) + (sum << 3) + (c ^ 48), c = getchar();
	return sum;
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	return 0;
}