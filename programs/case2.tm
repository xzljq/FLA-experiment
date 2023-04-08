#Q = {0,1,2,t,r,u,e,f,a,l,s}
#S = {1}
#G = {1,_,t,r,u,e,f,a,l,s}
#q0 = 0
#B = _
#F = {e}
#N = 2

0 1_ __ r* 1
0 __ t_ r* t

1 1_ 11 ** 2
1 11 _1 rr 1
1 __ t_ r* t
1 _1 f_ r* f

2 11 _1 rl 2
2 1_ __ rr 1
2 __ f_ r* f
2 _1 f1 r* f

t __ r_ r* r
r __ u_ r* u
u __ e_ r* e

f __ a_ r* a
f _1 a1 r* a
a __ l_ r* l
a _1 l1 r* l
l __ s_ r* s
l _1 s1 r* s
s __ e_ r* e
s _1 e1 r* e