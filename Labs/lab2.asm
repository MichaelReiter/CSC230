.cseg ;select current segment as code
.org 0 ;begin assembling at address 0
 
main:
  ldi r18, 0x09 ;Load 0x09 to Reg 18
  andi r18, 0x01 ;Set all bits except for least significant of Reg 18 to 0
  cpi r18, 0x00 ;Compare Reg 18 with 0x00
  breq even
  ldi r19, 0x00 ;Set Reg 19 to 0x00
  rjmp done
 
even:
  ldi r19, 0x01
 
done:
  jmp done