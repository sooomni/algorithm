#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(void) {
	int answer = 0;
	int n = 0;
	string str;
	vector <int> v;

	getline(cin, str);
	n = atoi(str.c_str());
	str = "";
	getline(cin, str);
	string strNum = ""; 
	for (int i = 0; i < str.length(); i++) {
		if (str.at(i) == ' ') {
			v.push_back(atoi(strNum.c_str()));
			strNum = "";
		}
		else
		{
			strNum += str.at(i);
			continue;
		}
	}
	v.push_back(atoi(strNum.c_str()));

	int * arr = new int(n);
	sort(v.begin(), v.end());

	arr[0] = *v.begin();
	answer += arr[0];

	for (int i = 1; i < n; i++) {
		v[i] += v[i - 1];
		answer += v[i];
	}

	cout << answer;
	return 0;
}