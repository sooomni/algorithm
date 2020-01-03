#include "stdafx.h"
#include <iostream>

using namespace std;

int solution(int n, int m, int k) {
	int answer = 0;
	
	while (n > 0 && m > 0) {
		if (n - 2 < 0 || m - 1 < 0) break;
		n -= 2;
		m -= 1;
		answer += 1;
	}
	
	while (k > 0) {
		if (m <= 0 && n <= 0) {
			answer -= 1;
			n += 2;
			m += 1;
		}
		if (m > 0) {
			m--; k--;
		}		
		if (n > 0) {
			n--; k--;
		}			
	}

	return answer;
}
int main(void){
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	
	if (n < 0 || n >100 || m < 0 || m>100 || k<0 || k>m + n)
		return -1;

	cout<<solution(n,m,k)<<endl;
	return 0;
}