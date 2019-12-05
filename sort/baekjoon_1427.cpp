#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void input(int n, vector <int> *v) {	
	string int_to_string = to_string(n);
	string tmp = "";

	for (int index = 0; index<int_to_string.size(); index++) {
		tmp = int_to_string[index];
		(*v).push_back(atoi(tmp.c_str()));
	}
}

void solution(vector <int> *v) {
	sort((*v).begin(), (*v).end(),greater <int>());
	for (int index = 0; index<(*v).size(); index++) {
		cout << (*v).at(index);
	}
}

int main(void) {
	vector <int> v;
	int n = 0;
	cin >> n;
	
	input(n, &v);
	solution(&v);

	return 0;
}