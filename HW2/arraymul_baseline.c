



	
"loop:\n\t"


	


        "lh t0, 0(%[h])\n\t"            
        "lh t1, 0(%[x])\n\t"            
        "addi %[lw_cnt], %[lw_cnt], 1\n\t"
        "addi %[lw_cnt], %[lw_cnt], 1\n\t"
       
        
        "mul t1,t1,t0\n\t"            
        "addi %[mul_cnt], %[mul_cnt], 1\n\t"
       
        
	"add t1,t1,%[id]\n\t"            
	"addi %[add_cnt], %[add_cnt], 1\n\t"
	
	
	"sh t1,0(%[y])\n\t"            
	"addi %[sw_cnt], %[sw_cnt], 1\n\t"

	
	
	"addi %[y], %[y], 2\n"
	"addi %[x], %[x], 2\n"
	"addi %[h], %[h], 2\n"
	"addi %[add_cnt], %[add_cnt], 1\n\t"
	"addi %[add_cnt], %[add_cnt], 1\n\t"
	"addi %[add_cnt], %[add_cnt], 1\n\t"
	
	
	


	"addi %[add_cnt], %[add_cnt], 1\n\t"

	"addi %[arr_size], %[arr_size], -1\n" 
	
	"addi %[others_cnt], %[others_cnt], 1\n\t"

	"beqz %[arr_size], end\n"    


	
	

	
	"addi %[others_cnt], %[others_cnt], 1\n\t"
	
	"j loop\n"                       


	
	
	

"end:\n" 























