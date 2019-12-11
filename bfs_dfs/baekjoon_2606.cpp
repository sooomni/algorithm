#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> connection[101];
int check[101];
int answer = -1;

void bfs(int n) {
	fill_n(check, 100, -1);
	queue<int> q;
	q.push(n);
	check[n] = 1;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i<connection[node].size(); i++) {
			if (check[connection[node][i]] == -1) {
				check[connection[node][i]] = 1;
				q.push(connection[node][i]);
			}
		}

	}

}

int main(void) {
	int com = 0;
	int net = 0;
	cin >> com;
	cin >> net;

	int input1 = 0, input2 = 0;

	for (int i = 0; i < net; i++) {
		cin >> input1 >> input2;
		connection[input1].push_back(input2);
		connection[input2].push_back(input1);
	}

	for (int i = 1; i <= com; i++) {
		sort(connection[i].begin(), connection[i].end());
	}

	bfs(1);
	
	int answer = 0;
	for (int i = 2; i <= com; i++) {
		if (check[i] != -1)
			answer++;
	}

	cout << answer << endl;

	return 0;
}