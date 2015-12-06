; Assignment 1, Question 6
; Michael Reiter
; V00831568

.cseg

.def counter = r17

initialization:
	ldi counter, 0x00		;Initialize count as 0
	ldi r26, 0x00		;Initialize X as the first memory location (200)
	ldi r27, 0x02

loop:
	st X+, counter			;load count into X and increment X
	inc counter				;increment count
	cpi counter, 0x50		;compare count with 0x50 (one more than 4F)
	breq done			;if (count == 0x50) break from the loop (i.e. stop at 4F)
	jmp loop

done:
	jmp done

.dseg
.org 0x200

nums: .byte 0x50
