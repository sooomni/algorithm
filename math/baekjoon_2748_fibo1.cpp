#include <iostream>

using namespace std;

int fibo(int n);

int main(void) {
	int n = 0;
	cin >> n;

	if (n > 90) {
		return -1;
	}
	
	cout << fibo(n);
	
	return 0;
}

int fibo(int n) {
	int * p = new int[n];

	p[0] = 0;
	p[1] = 1;
	p[2] = 1;

	for(int i = 3;i<=n;i++){
		p[i] = p[i - 1] + p[i - 2];
	}

	return p[n];
}