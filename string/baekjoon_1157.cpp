#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

void solution(string s) {
	int arr[27];
	fill_n(arr, 27, 0);

	for (int i = 0; i < s.size(); i++) {
		if ((s[i] - 'A') >= 32)
			arr[(s[i] - 'A') % 32]++;
		else
			arr[(s[i] - 'A')]++;
	}

	vector<pair<int, int>> v;
	int index = 0;

	for (int i = 0; i < 27; i++) {
		v.push_back(pair<int, int>(arr[i], i));
	}

	sort(v.begin(), v.end(), compare);

	if (v[0].first == v[1].first)
		cout << "?" << endl;
	else 
		cout << static_cast<char>(v[0].second+'A') << endl;
}

int main(void) {
	string s = "";
	cin >> s;
	solution(s);

	return 0;
}