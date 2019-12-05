#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> *A, vector<int> *B)
{
	int answer = 0;

	sort(A->begin(), A->end());
	sort(B->begin(), B->end(), greater<int>());

	int i = 0;
	int j = B->size();

	while (i<A->size()) {
		answer += (A->at(i) * B->at(i));
		i++;
		j--;
	}
	return answer;
}

void input_func(vector <int> * v,int n){
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		v->push_back(tmp);
	}
}

int main(void) {
	int n = 0;
	cin >> n;

	vector<int> a;
	vector<int> b;

	input_func(&a, n);
	input_func(&b, n);

	cout << solution(&a, &b)<<endl;

	return 0;
}