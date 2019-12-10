#include <iostream>

using namespace std;

long long func(int n) {
	long long  dp[91];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return dp[n];
}

int main(void) {
	int input = 0;
	cin >> input;

	cout << func(input) << endl;

	return 0;
}