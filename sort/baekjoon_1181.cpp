#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void input(int n, vector <string> *v) {	
	string tmp = "";
	for (int index = 0; index<n; index++) {
		cin >> tmp;
		(*v).push_back(tmp);
	}
}
bool compare(string a, string b) {
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() < b.size();
}

void solution(vector <string> *v) {
	sort(v->begin(), v->end(),compare);
	v->erase(unique(v->begin(), v->end()), v->end());
	for (int index = 0; index< v->size(); index++) {
		cout << v->at(index)<<endl;
	}
}

int main(void) {
	vector <string> v;
	int n = 0;
	cin >> n;
	
	input(n, &v);
	solution(&v);

	return 0;
}