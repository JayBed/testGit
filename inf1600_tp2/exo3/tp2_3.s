.data
debut_data:

i:
.long 0
comparateur:
.long 10

fin_data:
.global func_s
func_s:	
	
movl i,%edi 							
movl comparateur,%esi 				

.debut_for:
cmpl %esi,%edi
ja .fin_for 							

.boucle:
movl d,%edx
movl e,%eax
addl %eax,%edx
movl b,%eax
subl %eax,%edx
movl %edx,%eax
movl %eax,a					

movl b,%eax
subl $1000,%eax
movl %eax,%edx
movl c,%eax
addl $500,%eax
cmpl %eax,%edx

jge .else
 						
movl c,%eax
subl $500,%eax
movl %eax,c
movl b,%edx
movl c,%eax
cmpl %eax,%edx 	

jle .fin

movl b,%eax
subl $500,%eax
movl %eax,b			
jmp .fin				

.else:

movl b,%edx
movl e,%eax
subl %eax,%edx
movl %edx,%eax
movl %eax,b
movl d,%eax
addl $500,%eax
movl %eax,d	 
			
.fin:
addl $1,%edi 						
jmp .debut_for 						

.fin_for:

ret
