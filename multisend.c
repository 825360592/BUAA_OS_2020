LEAF(syscall_ipc_can_multi_send)
                addiu t0,a0,0		//��һ������ 
                addiu t1,a1,0		//�ڶ������� 
                addiu t2,a2,0		//���������� 
                addiu a0,zero,9543	//���õ�һ��Ϊid 
                addiu t3,a3,0       // num of env
                addiu a1,t3,4		//num+4Ϊ�ܲ������� 
                addiu a2,t0,0		//�����ĵ�һ������ 
                addiu a3,t1,0		//�����ĵڶ������� 

                sw t3,12(sp)		//�����ĵ��ĸ����� 
                sw t2,8(sp)			//�����ĵ��������� 
                addiu sp,sp,-8		//sp-8��Ԥ����λ�� 
                sw ra,0(sp)			//����ra�Ĵ�����ֵ 

                jal msyscall
                nop

                lw ra,0(sp)			//�ָ�ra�Ĵ�����ֵ 
                addiu sp,sp,8		//�ָ�sp 

                jr ra
                nop
END(syscall_ipc_can_multi_send)

LEAF(syscall_ipc_can_multi_send)
                addiu t0,a0,0		//��һ������ 
                addiu t1,a1,0		//�ڶ������� 
                addiu t2,a2,0		//���������� 
                addiu a0,zero,9543	//���õ�һ��Ϊid 
                addiu t3,a3,0       // num of env
                addiu a1,t3,4		//num+4Ϊ�ܲ������� 
                addiu a2,t0,0		//�����ĵ�һ������ 
                addiu a3,t1,0		//�����ĵڶ������� 
				
				addiu s0,sp,0		//s0����sp�ĳ�ʼλ�� 
				li t4,0				//ѭ������ 
				li t5,0				//��¼+4 
				get_top_addr:
					beq t4,t3,end_get_top_addr
					nop
					addiu t5,t5,4
					addiu t4,t4,1
					j get_top_addr
					nop
					
				end_get_top_addr:
					addiu t5,t5,16	//ջ�����Ϸ�����ƫ�� 
					addiu t5,t5,sp	//ջ�����Ϸ�������λ�� 
				
				li t4,0
				addiu sp,sp,-4		//Ԥ�����¸��� 
				copy_from_top:
					beq t4,t3,end_copy_from_top
					nop
					lw t6,(t5)
					sw t6,(sp) 		//��������ǰspλ�� 
					addiu sp,sp,-4	//sp���� 
					addiu t5,t5,-4	//t5���� 
					j copy_from_top
					nop
				
				end_copy_from_top:
					sw t3,(sp)		//ԭ�����ĸ����� 
					addiu sp,sp,-4	 
					sw t2,(sp)		//ԭ������������ 
					addiu sp,sp,-16	//Ԥ���ռ� 
					sw s0,(sp)		//����sp�������� 
					sw ra,4(sp)		//����ra 
				
                jal msyscall
                nop
				
                lw ra,4(sp)			//�ָ�ra�Ĵ�����ֵ 
                lw t0,0(sp)			//ȡ��sp��������
                addiu sp,sp,t0		//�ָ�sp 

                jr ra
                nop	
				
END(syscall_ipc_can_multi_send)
