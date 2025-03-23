#include<stdio.h>
int main()
{ 
    int f, i, j;
    int h[9] = {0}, x[6] = {0}, y[6] = {0}; 
    FILE *input = fopen("../input/3.txt", "r");
    for(i = 0; i < 9; i++) fscanf(input, "%d", &h[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &x[i]);
    for(i = 0; i < 6; i++) fscanf(input, "%d", &y[i]);
    fclose(input);
    int *p_x = &x[0] ;
    int *p_h = &h[0] ;
    int *p_y = &y[0] ;
    for (i = 0; i < 3; i++){ 
        for (j = 0; j < 2; j++){        	
            for (f = 0; f < 3; f++){
                asm volatile(
                
                    "add t0, %3, %3\n\t"		//2i
                    "add t1, t0, %4\n\t"		//2i+j
                    "add t2, t0, %3\n\t"		//3i
                    "add t2, t2, %5\n\t"		//3i+f
                    "add t0, %5, %5\n\t"		//2f
                    "add t3, t0, %4\n\t"		//2f+j
                    
                    "slli t3, t3, 2\n\t"          // t3 = (2f+j) * 4(byte)
                    "add t3, t3, %[p_x]\n\t"      // t3 = x[2f+j]
                    "lw t4, 0(t3)\n\t"            // Load x[2f+j]into t4
                    
                    
                    "slli t2, t2, 2\n\t"          // t2 = (3i+f) * 4(byte)
                    "add t2, t2, %[p_h]\n\t"      // t2 = h[3i+f]
                    "lw t5, 0(t2)\n\t"            // Load h[3i+f]into t5
                    
                    
                    
                    "slli t1, t1, 2\n\t"          // t1 = (2i+j) * 4(byte)
                    "add t1, t1, %[p_y]\n\t"      // t1 = y[2i+j]
                    "lw t6, 0(t1)\n\t"            // Load y[2i+j]into t6
                    
                    
                    
                    
                    "mul t0, t4, t5\n\t"          // t0 =  h[3i+f] * x[2f+j]
                    
                    "add t6, t6, t0\n\t"          // y[2i+j] += t0
                    "sw t6, 0(t1)\n\t"            // Store t0 into y[2i+j]
                    :                             // No outputs, directly modifying memory
                    : [p_y] "r" (p_y), [p_h] "r" (p_h), [p_x] "r" (p_x), "r"(i), "r"(j), "r"(f)  // Inputs
                );
            }
	}
    }
    p_y = &y[0];
    for(i = 0; i < 6; i++)
    printf("%d ", *p_y++);
    printf("\n");
    return 0; 
 
}
