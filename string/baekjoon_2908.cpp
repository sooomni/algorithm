#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void solution(string a, string b) {
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (a > b)
		cout << a << endl;
	else
		cout << b << endl;
}

int main(void) {
	string a = "", b = "";
	cin >> a >> b;
	solution(a,b);

	return 0;
}