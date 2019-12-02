#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;
	
bool compare(int a, int b) {
	return a >b;
}

int main(void) {
	int n = 0;
	int k = 0;
	int count = 0;

	string t = "";
	getline(cin, t);
	stringstream ss(t);
	ss >> n >> k;

	vector <int> v;
	int input = 0;
	for (int i = 0; i < n; i++) {
		cin >> input;
		v.push_back(input);
	}

	sort(v.begin(), v.end(),compare);

	int i = 0;
	while (i < n) {
		while(k >= v.at(i)) {
			k-= v.at(i);
			count++;
		}
		i++;
	}

	cout << count <<endl;

	return 0;
}