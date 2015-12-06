;
; lab6.asm
;
.include "m2560def.inc"

;SPH, SPL etc are defined in "m2560def.inc"

	; initialize the stack pointer
.cseg
	ldi r16, 0xFF
	out SPL, r16
	ldi r16, 0x21
	out SPH, r16
		
	;call subroutine void strcpy(src, dest)
	;push 1st parameter - src address
	ldi r16, high(src << 1)
	push r16
	ldi r16, low(src <<1)
	push r16

	;push 2nd parameter - des address
	ldi r16, high(dest)
	push r16
	ldi r16, low(dest)
	push r16

	call strcpy
	pop ZL
	pop ZH
	pop r16
	pop r16

	;call subroutine int strlen(string dest)
	;return value is in r24
	;push parameter dest, note it is in register Z alreay
	;call the method
	;clear the stack and write the result to length in SRAM
	;write your code here


	;push parameter - dest address
	ldi r16, high(dest)
	push r16
	ldi r16, low(dest)
	push r16

	call strlength

	pop r16
	pop r16
	

done: jmp done

strcpy:
	push r30
	push r31
	push r29
	push r28
	push r26
	push r27
	push r23
	IN YH, SPH ;SP in Y
	IN YL, SPL
	ldd ZH, Y + 14
	ldd ZL, Y + 13
	ldd XH, Y + 12
	ldd XL, Y + 11

next_char:
	lpm r23, Z+
	st X+, r23
	tst r23
	brne next_char
	pop r23
	pop r27
	pop r26
	pop r28
	pop r29
	pop r31
	pop r30
	ret
	
;One parameter - the address of the string, could be in 
;flash or SRAM (chose one). The length of the string is
;going to be stored in r24
strlength:
	
	push r29	;protect Y
	push r28
	push r31
	push r30	;protect Z
				;no need to protect r24, since we are using it for the return value
	push r23	;protect r23

	IN YH, SPH
	IN YL, SPL

	LDD ZH, Y+9
	LDD ZL, Y+10

	clr r24

next:
	inc r24
	ld r23, Z+
	tst r23
	brne next

	dec r24
	sts length, r24

	;recover protected registers:
	pop r23
	pop r30
	pop r31
	pop r28
	pop r29

	ret

src: .db "Hello, world!", 0 ; c-string format

.dseg
.org 0x200
dest: .byte 14
length: .byte 1
