#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void perm_print(vector <int> * v) {
	for (int i = 0; i < (*v).size(); i++) {
		if (i != (*v).size()-1)
			cout << (*v)[i] << " ";
		else
			cout << (*v)[i] << endl;
	}

}	
void swap(vector <int>* v, int i, int j) {
	int t = (*v)[i];
	(*v)[i] = (*v)[j];
	(*v)[j] = t;
}

void permutation(vector <int>* v, int dept, int n, int k) {
	if (dept == k) {
		perm_print(v);
		return;
	}

	for (int i = dept; i < n; i++) {
		swap(v, i, dept);
		permutation(v, dept + 1, n, k);
		swap(v, i, dept);
	}

}



int main(void) { 
	vector <int> v;

	int n = 0;
	int input = 0;
	cin>> n;

	for (int i = 0; i < n; i++) {	
		cin >> input;
		v.push_back(input);
	}

	permutation(&v, 0, v.size(), v.size());

	return 0;
}

