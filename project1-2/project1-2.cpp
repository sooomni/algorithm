#include <iostream>
#include <fstream>

using namespace std;

void swap(int& a, int& b);
void selection(int * arr, int n, int m);
int partition(int * arr, int p, int r);
void quicksort(int * arr, int p, int r);

int main()
{
	char input[] = "input";
	char txt[] = ".txt";
	char filename[20];
	int n, m, k;

	int * result = new int[256000000];

	ifstream fin("input.txt");
	if (fin.is_open()) {
		fin >> n >> m >> k;
	}
	for (int i = 0; i < n; i++) {
	sprintf(filename, "%s%d%s", input, i+1, txt);
	ifstream fin(filename);
	for (int j = i*m; j < m*n; j++) {
		fin >> result[j];
	}
	}
	fin.close();

	selection(result, n, m);
	quicksort(result, 0, n*m-1);

	ofstream fout("output.txt");
	if (fout.is_open()) {
		for (int i = 1; i < n * m; i = i+k) {
			fout << result[i] <<" ";
		}
		fout.close();
	}
	delete[] result;
	return 0;
}


void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int find_median(int& m) {
	int key = 0;

	if (m % 2 == 0) key = m / 2;
	else key = int(m / 2);
	return key;
}

void selection(int * arr, int n, int m) {
	int * med = new int[256];
	int key = find_median(m);
	int t_median = 0;

	for (int i = 0; i < n*m; i = i + m) {
		if (i == 0) med[i] = arr[i + key];
		else med[i / m] = arr[i + key];
	}
	quicksort(med,0,n-1);
	t_median = find_median(n)*m + key;
	swap(arr[t_median], arr[0]);

	delete[] med;
}

int partition(int * arr, int p, int r) {
	int pivot = arr[p];
	int i = p;

	for (int j = p + 1; j <= r; j++) {
		if (pivot >= arr[j])
			swap(arr[++i], arr[j]);
	}
	swap(arr[p], arr[i]);
	return i;
}


void quicksort(int * arr, int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		quicksort(arr, p, q - 1);
		quicksort(arr, q + 1, r);
	}

}
