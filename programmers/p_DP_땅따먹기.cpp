include <vector>

using namespace std;

int dp[10001][4] = { 0 }; //행 최대 개수가 10000개. 열은 4개

int solution(vector<vector<int>>land) {
	int answer = 0;

	int r = land.size();

	for (int i = 0; i < 4; ++i) {
		dp[0][i] = land[0][i];  //첫 행 초기화
	}

	for (int i = 1; i< r; ++i) { //행  
		for (int j = 0; j < 4; ++j) {  //열
			for (int k = 0; k < 4; ++k) {  //각 열에 대해 이동 가능한 경우가 4번
				if (j!=k) {  //각 열에서 이동하는 경우가 같지 않은 경우에만
					dp[i][j] = max(dp[i][j], land[i][j] + dp[i - 1][k]); 
				}			
			}
		}
	}

	for (int i = 0; i < 4; ++i) {
		answer = max(answer, dp[r - 1][i]);
	}
	return answer;
}