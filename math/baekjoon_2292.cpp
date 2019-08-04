#include <iostream>

using namespace std;

int main(void) {
	int n = 0;

	int res = 1;
	int i = 1;
	int j = 1;
	cin >> n;

	if (n < 1 || n> 1000000000) {
		return -1;
	}

	else if (n == 1) {
		cout << 1;
		return 0;
	}
	else {
		while (i < n) {
		    i = i+(6 * j);
			j++;
		}			
	}
		
    cout << j;
	return 0;

}