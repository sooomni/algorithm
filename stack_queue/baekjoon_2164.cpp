#include <string>
#include <queue>
#include <iostream>

using namespace std;
 
int solution(int n) {
	int answer = 0;
	queue <int> q;

	for (int i = 0; i < n; i++) {
		q.push(i + 1);
	}
	while (!q.empty()) {
		q.pop();
		if (q.size() == 1) {
			answer = q.front();
			return answer;
		}
		q.push(q.front());
		q.pop();
	}

	return answer;
}

int main(void) {
	int n = 0;
	cin >> n;
	cout << solution(n);
	return 0;
}