#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void input(int n, vector <pair<pair<int, int>, string>> *v) {	
	int age = 0;
	string name = "";

	for (int index = 0; index < n; index++) {
		cin >> age >> name;
		v->push_back(pair<pair<int, int>, string>(pair<int, int>(age, index), name));
	}	
}

bool compare(pair<pair<int,int>,string> a, pair<pair<int,int>,string> b) {
	if (a.first.first == b.first.first)
		return a.first.second < b.first.second;
	else
		return a.first.first < b.first.first;
}

void solution(vector<pair<pair<int, int>, string>> *v) {
	sort(v->begin(), v->end(),compare);
	for (int index = 0; index< v->size(); index++) {
		cout << v->at(index).first.first<<" "<< v->at(index).second <<"\n";
	}
}

int main(void) {
	vector <pair<pair<int, int>, string>> v;

	int n = 0;
	cin >> n;
    
    std::ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
	
    input(n, &v);
	solution(&v);

	return 0;
}