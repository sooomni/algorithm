﻿#include <string>
#include <iostream>

using namespace std;
 
int main(void) {
	
	int arr[26];
	fill_n(arr, 26, -1);
	string s = "";
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (arr[s[i] - 'a'] == -1)
			arr[s[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}