
#include <stdlib.h>
#pragma warning (disable : 4996)


void CommonDenominator(unsigned int * num, unsigned int * denom);

int main(void) {
	unsigned int numerator;
	unsigned int denominator;

	scanf("%d %d", &numerator, &denominator);
	CommonDenominator(&numerator, &denominator);
	printf("%d %d\n", numerator, denominator);
	printf("result : lcd = %d\n", denominator);

	return 0;
}

void CommonDenominator(unsigned int * num, unsigned int * denom) {
	unsigned int temp = *num % *denom;

	while (temp > 0) {		
		*num = *denom;
		*denom = temp;
		temp = *num % *denom;
	};
	return;
};
