#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void BFS(int start, vector<int>graph[], int check[]) {
	queue <int> q;
	q.push(start);
	check[start] = 1;

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << " ";

		for (int i = 0; i < graph[tmp].size(); i++) {
			if (check[graph[tmp][i]] == 0) {
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = 1;
			}
		}
	}
}

void DFS(int start, vector<int>graph[], int check[]) {
	stack<int> s;
	s.push(start);
	check[start] = 1;
	cout << start << " ";

	while (!s.empty()) {
		int current_node = s.top();
		s.pop();

		for (int i = 0; i < graph[current_node].size(); i++) {
			int next_node = graph[current_node][i];

			if (check[next_node] == 0) {
				cout << next_node<<" ";
				check[next_node] = 1;

				s.push(current_node);
				s.push(next_node);
				break;
			}

		}
	
	}

}


int main(void) {
	int n = 0;
	int m = 0;
	int start = 0;
	
	cin >> n>> m >> start;

	vector <int> graph[n + 1];
	int * check = new int[n + 1]();

	int num1 = 0;
	int num2 = 0;

	for (int i = 0; i < m; i++) {
		cin>>num1>>num2;
		graph[num1].push_back(num2);
		graph[num2].push_back(num1);
	}
	
	for (int i = 1; i < n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	DFS(start, graph, check);
	cout << endl;
	fill(check,check+n+1,0);
	BFS(start, graph, check);

	return 0;

}