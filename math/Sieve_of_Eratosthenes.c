#include <stdlib.h>
#include <math.h>
#pragma warning (disable : 4996)

int main(void) {
	int num = 0;
	int * ptr;

	scanf("%d", &num);
	while (num < 1) {
		printf("num have to over 1. try again.\n");
		scanf("%d", &num);
	}
	
	ptr = (int *)calloc(num-1, sizeof(int));	
	
	for (int i = 2; i <=sqrt(num); i++) {
		if (ptr[i] == 0) {
			for (int j = i*i; j <= num; j+=i) {
				ptr[j] = 1;
			}
		}
	}

	for (int i = 2; i < num; i++) {
		if (ptr[i] == 0) {
			printf("%d ",i);
		}
	}	

	return 0;

}
