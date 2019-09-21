#include <iostream>

using namespace std;

void print_result(int num, int * test_case);
int func(int * test_case);

int main(void) {
	int p_test_case = 1;

	while (p_test_case <= 10) {

		print_result(func(&p_test_case), &p_test_case);
		p_test_case++;
	}

	return 0;
}

void print_result(int num, int * p_test_case) {
	cout << "#" << *p_test_case << " ";
	cout << num << endl;
}

int func(int * p_test_case) {
	
	int test_set;
	int n;
	int result = 0;
	int target;
	int min;
	bool check = true;

	cin >> test_set;
	
	int * arr = new int[test_set]();
	
	for (int i = 0; i < test_set; i++)
	{
		cin >> n;
		arr[i] = n;
	}

	for (int i = 2; i < test_set-2; i++){	
		target = arr[i];
		min = 255;
		check = true;

		for (int j = i - 2; j <= i + 2; j++) {
			if (j == 0 || j == 1|| j == 999|| j == 1000||j == i) {
				continue;
			}
			else if (target - arr[j] <= 0) {
				check = false;
				continue;
			}
            else if (check== true && target - arr[j] < min) {
				min = target - arr[j];
			}
		}
		if (check == true) {
			result += min;
		}
	}

	delete[] arr;

	return result;
}