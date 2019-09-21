#include <iostream>

using namespace std;

void print_result(int num, int * test_case);
int func(int * test_case);

int main(void) {
	int test_case;
	int p_test_case = 1;

	cin >> test_case;

	while (p_test_case<=test_case) {

		print_result(func(&p_test_case), &p_test_case);
		p_test_case++;
	}

	return 0;
}

void print_result(int num, int * p_test_case) {
	cout << "#" <<*p_test_case << " ";
	cout << num<<endl;
}

int func(int * p_test_case) {
	
	int * arr = new int[101]();
	int num = 0;
	int n;
	int max = 0;
	int max_index;

	for (int i = 0; i <= 1000; i++) {
		cin >> n;
		arr[n]++;
	}

	max = arr[0];
	max_index = 0;
    
    for (int i = 0; i <= 100; i++) {
		if (max == arr[i]) {
            max_index = i;
        }
        else if(max < arr[i]){
			max = arr[i];
			max_index = i;
    }
}
	delete[] arr;

	return max_index;
}