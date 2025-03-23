"vsetivli t0, 8, e16\n\t"
"addi %[others_cnt], %[others_cnt], 1\n"


"loop:\n"       

	"vle16.v v0, (%[h])\n"  
	"addi %[lw_cnt], %[lw_cnt], 1\n"
	
    	"vle16.v v1, (%[x])\n"  
    	"addi %[lw_cnt], %[lw_cnt], 1\n"
    	
    	"vmul.vv v2, v0, v1\n"  
    	"addi %[mul_cnt], %[mul_cnt], 1\n"
    	
    	"vadd.vx v2, v2, %[id]\n"  
        "addi %[add_cnt], %[add_cnt], 1\n"
        
        "vse16.v v2, (%[y])\n"  
    	"addi %[sw_cnt], %[sw_cnt], 1\n"
	
	"addi %[y], %[y], 16\n"  
    	"addi %[h], %[h], 16\n"  
    	"addi %[x], %[x], 16\n"  
    	"addi %[add_cnt], %[add_cnt], 1\n"
    	"addi %[add_cnt], %[add_cnt], 1\n"
    	"addi %[add_cnt], %[add_cnt], 1\n"
    	
    	
    	"sub %[arr_size], %[arr_size], t0\n" 
        "addi %[sub_cnt], %[sub_cnt], 1\n"    
    	
    	"addi %[others_cnt], %[others_cnt], 1\n\t"
        "beqz %[arr_size], exit\n"    
  	
    	
	"addi %[others_cnt], %[others_cnt], 1\n"
        "j loop\n"                          
        
        
"exit:\n"
