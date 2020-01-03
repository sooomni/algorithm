#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


int solution(string * a,string * b) {
	int ans = 0;
	while (a->size() < b->size()) {
		int cha = b->size() - a->size();
		int front = 0, back = 0;
		for (int i = 0; i < a->size(); i++) {
			if (a->at(i) != b->at(i)) front++;
			if (a->at(i) != b->at(i + cha)) back++;
		}
		
		if (front == 0 || back == 0)
			return ans = 0;

		else if (front > back) {
			*a += b->at(a->size());
			ans += back;
		}
		else {
			string t = "";
			t = b->at(a->size());
			t += *a;
			*a = t;
			ans += front;
		}
	}

	return ans;
}
int main(void) {
	int answer = 0;
	string a = "";
	string b = "";

	cin >> a >> b;
	int cha = b.size() - a.size();
	if (cha == 0) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i]) answer++;
		}
		cout << answer << endl;
	}	
	else
		cout<<solution(&a, &b)<<endl;
	
	return 0;
}