"li t1, 0\n\t"               
"li t2, 1\n\t"               
"li t3, -1\n\t"               
"addi %[lw_cnt], %[lw_cnt], 1\n" 
"addi %[lw_cnt], %[lw_cnt], 1\n" 
"addi %[lw_cnt], %[lw_cnt], 1\n" 
"i_loop:\n\t"
 
       "add t4, t1, t1\n\t"         
       "addi %[add_cnt], %[add_cnt], 1\n" 
       
       "addi t4, t4, 1\n\t"         
       "addi %[add_cnt], %[add_cnt], 1\n" 
       
       "fcvt.d.w f1,t2\n\t"
       "addi %[others_cnt], %[others_cnt], 1\n" 
 
       
       "fcvt.d.w f2,t4\n\t" 
       "addi %[others_cnt], %[others_cnt], 1\n" 
       
       "mul t2,t2,t3\n\t"
       "addi %[mul_cnt], %[mul_cnt], 1\n"
       
                     
       "fdiv.d f1, f1, f2\n\t"            
       "addi %[div_cnt], %[div_cnt], 1\n"
             
       "fadd.d %[pi], %[pi], f1\n\t"          
       "addi %[add_cnt], %[add_cnt], 1\n" 
             
              
        
"addi t1, t1, 1\n\t"          
"addi %[add_cnt], %[add_cnt], 1\n" 


"addi %[others_cnt], %[others_cnt], 1\n"  
"bne t1, %[N], i_loop\n\t"      
     










































