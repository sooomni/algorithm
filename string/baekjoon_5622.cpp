#include <string>
#include <iostream>
using namespace std;

void solution(string s) {
	int times[27] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		int index = (s[i] - 'A');
		sum += times[index];
	}
    cout<<sum<<endl;
}
int main(void) {
	string s = "";
	cin >> s;
	solution(s);

	return 0;
}