#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
int min(int a, int b) {
	return a < b ? a : b;
}
int main(void) {
	
	int block[501] = { 0 };

	int height = 0;
	int width = 0;
	int answer = 0;

	cin >> height >> width;	
	for (int i = 0; i < width; i++) cin >> block[i+1];
	
	for(int i = 2;i<width;i++){
		int col = 0, row = 0;
		for (int j = 1; j < i; j++) col = max(col, block[j]);
		for (int j = width; j > i; j--) row = max(row, block[j]);
		answer += max(0, min(row, col) - block[i]);
	}
	
	cout << answer<<"\n";
	return 0;
}
	