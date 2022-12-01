#Q = {copy,idle,0,cp,cmp,mh,accept,accept2,accept3,accept4,halt_accept,reject,reject2,reject3,reject4,reject5,halt_reject}
#S = {0,1}
#G = {0,1,_,t,r,u,e,f,a,l,s}
#q0 = 0
#B = _
#F = {halt_accept}   ;niasaassa

#N = 2

cmp 01 __ rl reject ; 当前处于状态 cmp
                    ; 两个带头下符号分别为 '0' 和 '1'
                    ; 
                    ; 下一步第一个带头向右移动，第二个带头向左移动
                    ; 下一个状态为 reject
                    
idle ** ** ** idle	; 当前处于状态idle
					; 两个带头下符号可以是 '0' 或 '1' 中的任意一个
					; 将要写入的新符号和原符号保持一致
					; 下一步两个带头均不移动
					; 下一个状态为idle
					
copy 0* 00 ll copy	; 当前处于状态copy
					; 第一条纸带的带头下符号为 '0' ，第二条纸带的带头下符号为'0' 或 '1' 中的任意一个
					; 将要写入的新符号为 '0' 和 '0'
					; 下一步两个带头均向左移动
					; 下一个状态为copy