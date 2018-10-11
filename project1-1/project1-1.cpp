#include <iostream>
#include <fstream>

using namespace std;

void swap(int& a, int& b);
int partition(int * value, int p, int r);
void quicksort(int * value, int p, int r);

int main(void){
	int * value = new int[100000];
	int n;
	ifstream fin("input.txt"); 

	if (fin.is_open()){
		fin >> n;
		for (int i = 0; i < n; i++) {
			fin >> value[i];
		}
		fin.close();
	}

	quicksort(value, 0, n-1);

	ofstream fout("output.txt"); 
	if (fout.is_open()) {
		for (int i = 0; i < n; i++) {
			fout << value[i]<<" ";
		}
		fout.close();
	}
	delete [] value;

    return 0;
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int * value, int p, int r) {
	int key = value[r];
	int i = p - 1;

	for (int j = p; j < r; j++) {
		if (value[j] <= key)  {
			swap(value[++i], value[j]);
		}
	}
	swap(value[i+1], value[r]);

	return i + 1;
}

void quicksort(int * value, int p, int r) {
	if (p < r) {
		int	q = partition(value, p, r);
		quicksort(value, p, q - 1);
		quicksort(value, q + 1, r);
	}
}
