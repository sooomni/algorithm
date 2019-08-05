#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

int fibo(int n,int * p);

int main(void) {
	int n = 0;
	cin >> n;

	if (n > 90) {
		return -1;
	}

	int * p = new int[n];
	fill_n(p, n, -1);
	cout << fibo(n,p);

	return 0;
}

int fibo(int n,int * p) {

	if (n == 0)
		return 0;
	else if (n == 1 || n == 2)
		return 1;
	else if (p[n] > -1)
		return p[n];
	else {
		p[n] = fibo(n-1,p) + fibo(n - 2,p);
		return p[n];
	}
}