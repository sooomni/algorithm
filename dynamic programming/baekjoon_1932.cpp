#include <iostream>
#include <vector>

using namespace std;

int Max(int a, int b) {
	return a > b ?  a : b;
}

int main(void) {
	int n, max = 0;
	int dp[501][501] = {0};
	cin >> n;
	
	for (int i = 1; i < n+1; i++) {
		for (int j = 0; j < i; j++) {
			cin >> dp[i][j];
			if (j == 0)
				dp[i][j] += dp[i - 1][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = Max(dp[i][j] + dp[i - 1][j], dp[i][j] + dp[i - 1][j - 1]);
		
			if (max < dp[i][j])
				max = dp[i][j];
		}
	}
	cout << max<<endl;

	return 0;
}