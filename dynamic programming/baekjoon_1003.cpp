#include <iostream>

using namespace std;

void func(int n) {

	int arr[41][2] = { {1,0},{0,1} };

	for (int i = 2; i <= n; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 2][0];
		arr[i][1] = arr[i - 1][1] + arr[i - 2][1];
	}
	cout << arr[n][0] << " " << arr[n][1] << endl;
}
int main(void) {

	int input, num = 0;
	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> input;
		func(input);
	}
	return 0;
}