#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first< b.first;
	else
		return a.second < b.second;
}

void solution(vector <pair<int, int>> *v) {
	sort(v->begin(), v->end(), compare);
	for (int index = 0; index< v->size(); index++) {
		cout << v->at(index).first << " " << v->at(index).second << "\n";
	}
}

int main(void) {
	vector <pair<int, int>> v;

	int n = 0;
	cin >> n;

	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int input[2];
	for (int index = 0; index < n; index++) {
		cin >> input[0] >> input[1];
		v.push_back(pair<int, int>(input[0], input[1]));
	}
	solution(&v);

	return 0;
}