	AREA SUBSTRING,CODE,READONLY
CNT RN 7
ENTRY LDR R1,=M
	  LDR R2,=S
	  MOV R12,R2
LOOP LDRB R3,[R1]
	 LDRB R4,[R2]
	 CMP R4,#0
	 ADDEQ CNT,CNT,#1
	 MOVEQ R2,R12
	 BEQ LOOP
	 CMP R3,R4
	 ADDEQ R2,R2,#1
	 MOVNE R2,R12
	 ADD R1,R1,#1
	 BEQ LOOP
	 CMP R3,#0
	 BEQ STOP
	 BNE LOOP
STOP B STOP
M DCB "ABCABC",0
S DCB "ABC",0
	 END