#include <stdio.h>

int add(int* a, int* b, int* c) {

	return *a + *b + *c;
}

int main() {

	int a, b, c;
	printf("Insert three numbers to add (space seperated).\n");
	scanf("%d %d %d", &a, &b, &c);

	int sum = add(&a,&b,&c);
	printf("This is the sum of %d, %d and %d: %d\n", a, b, c, sum);
	
	return 0;
}
