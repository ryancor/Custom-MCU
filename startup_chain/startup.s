.global _Reset

.word	_sdata
.word _sidata
.word	_edata
.word	_sbss
.word _ebss

_Reset:
	LDR 	sp, =stack_top
	MOVS 	r1, #0
	B 		LoopCopyDataInit

CopyDataInit:
	LDR		r3, =_sidata
	LDR		r3, [r3, r1]
	STR 	r3, [r0, r1]
	ADDS 	r1, r1, #4

LoopCopyDataInit:
	LDR 	r0, =_sdata
	LDR 	r3, =_edata
	ADDS  r2, r0, r1
	CMP 	r2, r3
	BCC 	CopyDataInit
	LDR 	r2, =_sbss
	B			LoopFillZerobss

/* Zero fill the bss segment. */
FillZeroBs:
	MOVS	r3, #0
	STR 	r3, [r2]
	ADDS 	r2, r2, #4

LoopFillZerobss:
	LDR 	r3, =_ebss
	CMP 	r2, r3
	BCC 	FillZeroBs

	/* Call the application's entry point. */
	BL 		main
	B 		.
