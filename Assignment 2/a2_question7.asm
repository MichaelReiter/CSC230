; Michael Reiter
; V00831568
; October 20, 2015
; Assignment 2 Question 7

.cseg
.org 0

.def A = r16
.def B = r17

ldi A, 10
ldi B, 25

;A+B (=R4)
mov r4, A
add r4, b

;A-B (=R5)
mov r5, A
sub r5, B

;A.B(=R6)
mov r6, A
and r6, B

;A|B(=R7)
mov r7, A
or r7, B

;A<<1(=R8)
mov r8, A
lsl r8

;B>>1(=R9)
mov r9, B
lsr r9

done: rjmp done
