#include <stdio.h>
int main(){
	int a, b;
	FILE *input = fopen("../input/1.txt", "r");
	fscanf(input, "%d %d", &a, &b);
	fclose(input);
	//a = a / b;
	asm volatile(
        	"div %0, %0, %1\n\t"  // a = a - b;
        	: "+r" (a)            // Outputs and inputs
        	: "r"  (b)            // Inputs only
    	);
	printf("%d\n", a);
	return 0;
}


