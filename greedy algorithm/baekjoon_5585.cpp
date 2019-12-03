#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	int n = 0;
	int answer = 0;
	string str = "";

	getline(cin, str);
	n = atoi(str.c_str());
    
	n = 1000 - n;
	answer += n / 500;
	n %= 500;
	answer += n / 100;
	n %= 100;
	answer += n / 50;
	n %= 50;
	answer += n / 10;
	n %= 10;
	answer += n / 5;
	n %= 5;
	answer += n / 1;

	cout << answer;
	return 0;
}