#include <iostream>
#include <stack>

#define MAX_NUM 101

using namespace std;

int v[MAX_NUM][MAX_NUM];
int check[MAX_NUM];
int answer[MAX_NUM][MAX_NUM];

void dfs(int n, int x) {
	stack <int> s;
	fill_n(check, n + 1, -1);
	
	s.push(x);

	while (!s.empty()) {
		int current_node = s.top();
		s.pop();

		for (int i = 0; i < n; i++) {
			if (v[current_node][i] == 1 && check[i] == -1) {
				
				check[i] = 1;
				answer[x][i] = 1;

				s.push(current_node);
				s.push(i);
				break;
			}
		}
	}
}

int main(void) {
	int n = 0;
	cin >> n;

	int input = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		dfs(n,i);
	}
    
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << answer[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}