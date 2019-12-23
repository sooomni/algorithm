#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Time {
	int begin;
	int end;
};

bool compare(Time a, Time b) {
	if (a.end == b.end) return a.begin<b.begin;
	else return a.end < b.end;
}

int solution(vector <Time> v) {
	int answer = 0;
	sort(v.begin(), v.end(), compare);
	
	int endpoint = 0;
	for (int i = 0; i < v.size(); i++) {
		if (endpoint <= v[i].begin) {
			endpoint = v[i].end;
			answer++;
		}
	}
	return answer;
}


int main(void) {
	
	int n = 0;
	cin >> n;
	vector <Time> v(n);

	for (int i = 0; i < n; i++) {
		cin>>v[i].begin >> v[i].end;
	}
	
	cout<<solution(v)<<endl;
	return 0;
}