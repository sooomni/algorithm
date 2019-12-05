#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int input_func(vector <int> * v,int n){
	int sum = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v->push_back(tmp);
		sum += tmp;
	}
	return sum;
}

int main(void) {
	int n = 0;
	cin >> n;

	vector<int> a;

	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	
	cout << input_func(&a, n) << "\n";
	sort(a.begin(), a.end());

	int mid = a.size() / 2;
	cout << a[mid] << "\n";

	cout << "/";

	int sub = a.at(a.size() - 1) - a.at(0);
	cout << sub << "\n";

	return 0;
}