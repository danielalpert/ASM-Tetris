include small_funcs.inc

.code

checkOColD PROC
	;detects collision of "O" tetromino from bellow
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	add ebx, 2
	invoke getBlockLoc, edx, ebx
	mov eax, [eax]
	cmp eax, 0
	je skipcol1
		mov ecx, 1
		jmp rt
	skipcol1:
	inc edx
	invoke getBlockLoc, edx, ebx
	mov eax, [eax]
	cmp eax, 0
	je skipcol2
		mov ecx, 1
		jmp rt
	skipcol2:
	mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkOColD endp

checkIColD PROC
	;detects collision of "I" tetromino from bellow
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol1
			mov ecx, 1
			jmp rt
		skipcol1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol2
			mov ecx, 1
			jmp rt
		skipcol2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol3
			mov ecx, 1
			jmp rt
		skipcol3:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol4
			mov ecx, 1
			jmp rt
		skipcol4:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		add ebx, 4
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol
			mov ecx, 1
			jmp rt
		skipcol:
		mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkIColD endp

checkTColD PROC
	;detects collision of "T" tetromino from bellow
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln3
			mov ecx, 1
			jmp rt
		skipcoln3:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		dec ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		inc edx
		dec ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols3
			mov ecx, 1
			jmp rt
		skipcols3:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkTColD endp

checkJColD PROC
	;detects collision of "J" tetromino from bellow
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln3
			mov ecx, 1
			jmp rt
		skipcoln3:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc edx
		sub ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols3
			mov ecx, 1
			jmp rt
		skipcols3:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkJColD endp

checkLColD PROC
	;detects collision of "L" tetromino from bellow
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln3
			mov ecx, 1
			jmp rt
		skipcoln3:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc edx
		dec ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols3
			mov ecx, 1
			jmp rt
		skipcols3:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		add ebx, 2
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkLColD endp

checkSColD PROC
	;detects collision of "S" tetromino from bellow
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh1
			mov ecx, 1
			jmp rt
		skipcolh1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh2
			mov ecx, 1
			jmp rt
		skipcolh2:
		dec ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh3
			mov ecx, 1
			jmp rt
		skipcolh3:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv1
			mov ecx, 1
			jmp rt
		skipcolv1:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv2
			mov ecx, 1
			jmp rt
		skipcolv2:
		mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkSColD endp

checkZColD PROC
	;detects collision of "Z" tetromino from bellow
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh1
			mov ecx, 1
			jmp rt
		skipcolh1:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh2
			mov ecx, 1
			jmp rt
		skipcolh2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh3
			mov ecx, 1
			jmp rt
		skipcolh3:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv1
			mov ecx, 1
			jmp rt
		skipcolv1:
		dec ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv2
			mov ecx, 1
			jmp rt
		skipcolv2:
		mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkZColD endp

detectColisionD PROC
	;uses tetromino specific functions to detect a collision from bellow
	;sets ecx to 1 if collided
	push eax
	mov eax, tetr.kind
	cmp eax, 1
	jne skipo
		invoke checkOColD
		jmp rt
	skipo:
	cmp eax, 2
	jne skipi
		invoke checkIColD
		jmp rt
	skipi:
	cmp eax, 3
	jne skipt
		invoke checkTColD
		jmp rt
	skipt:
	cmp eax, 4
	jne skipl
		invoke checkLColD
		jmp rt
	skipl:
	cmp eax, 5
	jne skipj
		invoke checkJColD
		jmp rt
	skipj:
	cmp eax, 6
	jne skips
		invoke checkSColD
		jmp rt
	skips:
	cmp eax, 7
	jne skipz
		invoke checkZColD
		jmp rt
	skipz:
	rt:
	pop eax
	ret
detectColisionD endp

checkOColR PROC
	;detects collision of "O" tetromino to the right
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	cmp edx, 8
	jne skipwall
	mov ecx, 1
	jmp rt
	skipwall:
	mov ebx, tetr.pos.y
	add edx, 2
	invoke getBlockLoc, edx, ebx
	mov eax, [eax]
	cmp eax, 0
	je skipcol1
		mov ecx, 1
		jmp rt
	skipcol1:
	inc ebx
	invoke getBlockLoc, edx, ebx
	mov eax, [eax]
	cmp eax, 0
	je skipcol2
		mov ecx, 1
		jmp rt
	skipcol2:
	mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkOColR endp

checkIColR PROC
	;detects collision of "I" tetromino to the right
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		cmp edx, 6
		jne skipwallhor
		mov ecx, 1
		jmp rt
		skipwallhor:
		add edx, 4
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol
			mov ecx, 1
			jmp rt
		skipcol:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		cmp edx, 9
		jne skipwallver
		mov ecx, 1
		jmp rt
		skipwallver:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol1
			mov ecx, 1
			jmp rt
		skipcol1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol2
			mov ecx, 1
			jmp rt
		skipcol2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol3
			mov ecx, 1
			jmp rt
		skipcol3:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol4
			mov ecx, 1
			jmp rt
		skipcol4:
		mov ecx, 0
		jmp rt
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkIColR endp

checkTColR PROC
	;detects collision of "T" tetromino to the right
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		cmp edx, 7
		jne skipwalln
			mov ecx, 1
			jmp rt
		skipwalln:
		add edx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		cmp edx, 8
		jne skipwalle
			mov ecx, 1
			jmp rt
		skipwalle:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		inc ebx
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole3
			mov ecx, 1
			jmp rt
		skipcole3:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		cmp edx, 7
		jne skipwalls
			mov ecx, 1
			jmp rt
		skipwalls:
		add edx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		dec edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		cmp edx, 8
		jne skipwallw
			mov ecx, 1
			jmp rt
		skipwallw:
		add edx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw3
			mov ecx, 1
			jmp rt
		skipcolw3:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkTColR endp

checkLColR PROC
	;detects collision of "L" tetromino to the right
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		cmp edx, 7
		jne skipwalln
			mov ecx, 1
			jmp rt
		skipwalln:
		add edx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		cmp edx, 8
		jne skipwalle
			mov ecx, 1
			jmp rt
		skipwalle:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole3
			mov ecx, 1
			jmp rt
		skipcole3:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		cmp edx, 7
		jne skipwalls
			mov ecx, 1
			jmp rt
		skipwalls:
		add edx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		sub edx, 2
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		cmp edx, 8
		jne skipwallw
			mov ecx, 1
			jmp rt
		skipwallw:
		add edx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw3
			mov ecx, 1
			jmp rt
		skipcolw3:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkLColR endp

checkJColR PROC
	;detects collision of "J" tetromino to the right
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		cmp edx, 7
		jne skipwalln
			mov ecx, 1
			jmp rt
		skipwalln:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc ebx
		add edx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		cmp edx, 8
		jne skipwalle
			mov ecx, 1
			jmp rt
		skipwalle:
		add edx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc ebx
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole3
			mov ecx, 1
			jmp rt
		skipcole3:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		cmp edx, 7
		jne skipwalls
			mov ecx, 1
			jmp rt
		skipwalls:
		add edx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		cmp edx, 8
		jne skipwallw
			mov ecx, 1
			jmp rt
		skipwallw:
		add edx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw3
			mov ecx, 1
			jmp rt
		skipcolw3:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkJColR endp

checkSColR PROC
	;detects collision of "S" tetromino to the right
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		cmp edx, 7
		jne skipwallh
		mov ecx, 1
		jmp rt
		skipwallh:
		add edx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh1
			mov ecx, 1
			jmp rt
		skipcolh1:
		inc ebx
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh2
			mov ecx, 1
			jmp rt
		skipcolh2:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		cmp edx, 8
		jne skipwallv
			mov ecx, 1
			jmp rt
		skipwallv:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv1
			mov ecx, 1
			jmp rt
		skipcolv1:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv2
			mov ecx, 1
			jmp rt
		skipcolv2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv3
			mov ecx, 1
			jmp rt
		skipcolv3:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkSColR endp

checkZColR PROC
	;detects collision of "Z" tetromino to the right
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		cmp edx, 7
		jne skipwallh
		mov ecx, 1
		jmp rt
		skipwallh:
		add edx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh1
			mov ecx, 1
			jmp rt
		skipcolh1:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh2
			mov ecx, 1
			jmp rt
		skipcolh2:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		cmp edx, 8
		jne skipwallv
			mov ecx, 1
			jmp rt
		skipwallv:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv1
			mov ecx, 1
			jmp rt
		skipcolv1:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv2
			mov ecx, 1
			jmp rt
		skipcolv2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv3
			mov ecx, 1
			jmp rt
		skipcolv3:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkZColR endp

detectColisionR PROC
	;uses tetromino specific functions to detect a collision to the right
	;sets ecx to 1 if collided
	push eax
	mov eax, tetr.kind
	cmp eax, 1
	jne skipo
		invoke checkOColR
		jmp rt
	skipo:
	cmp eax, 2
	jne skipi
		invoke checkIColR
		jmp rt
	skipi:
	cmp eax, 3
	jne skipt
		invoke checkTColR
		jmp rt
	skipt:
	cmp eax, 4
	jne skipl
		invoke checkLColR
		jmp rt
	skipl:
	cmp eax, 5
	jne skipj
		invoke checkJColR
		jmp rt
	skipj:
	cmp eax, 6
	jne skips
		invoke checkSColR
		jmp rt
	skips:
	cmp eax, 7
	jne skipz
		invoke checkZColR
		jmp rt
	skipz:
	rt:
	pop eax
	ret
detectColisionR endp

checkOColL PROC
	;detects collision of "O" tetromino to the left
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	cmp edx, 0
	jne skipwall
	mov ecx, 1
	jmp rt
	skipwall:
	mov ebx, tetr.pos.y
	dec edx
	invoke getBlockLoc, edx, ebx
	mov eax, [eax]
	cmp eax, 0
	je skipcol1
		mov ecx, 1
		jmp rt
	skipcol1:
	inc ebx
	invoke getBlockLoc, edx, ebx
	mov eax, [eax]
	cmp eax, 0
	je skipcol2
		mov ecx, 1
		jmp rt
	skipcol2:
	mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkOColL endp

checkIColL PROC
	;detects collision of "I" tetromino to the left
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	cmp edx, 0
	jne skipwall
	mov ecx, 1
	jmp rt
	skipwall:
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol
			mov ecx, 1
			jmp rt
		skipcol:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol1
			mov ecx, 1
			jmp rt
		skipcol1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol2
			mov ecx, 1
			jmp rt
		skipcol2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol3
			mov ecx, 1
			jmp rt
		skipcol3:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcol4
			mov ecx, 1
			jmp rt
		skipcol4:
		mov ecx, 0
		jmp rt
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkIColL endp

checkTColL PROC
	;detects collision of "T" tetromino to the left
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		cmp edx, 0
		jne skipwalln
			mov ecx, 1
			jmp rt
		skipwalln:
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		dec edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		cmp edx, 0
		jne skipwalle
			mov ecx, 1
			jmp rt
		skipwalle:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole3
			mov ecx, 1
			jmp rt
		skipcole3:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		cmp edx, 0
		jne skipwalls
			mov ecx, 1
			jmp rt
		skipwalls:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		cmp edx, 0
		jne skipwallw
			mov ecx, 1
			jmp rt
		skipwallw:
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc ebx
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw3
			mov ecx, 1
			jmp rt
		skipcolw3:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkTColL endp

checkLColL PROC
	;detects collision of "L" tetromino to the left
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		cmp edx, 0
		jne skipwalln
			mov ecx, 1
			jmp rt
		skipwalln:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		sub edx, 2
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		cmp edx, 0
		jne skipwalle
			mov ecx, 1
			jmp rt
		skipwalle:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole3
			mov ecx, 1
			jmp rt
		skipcole3:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		cmp edx, 0
		jne skipwalls
			mov ecx, 1
			jmp rt
		skipwalls:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		cmp edx, 0
		jne skipwallw
			mov ecx, 1
			jmp rt
		skipwallw:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw3
			mov ecx, 1
			jmp rt
		skipcolw3:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkLColL endp

checkJColL PROC
	;detects collision of "J" tetromino to the left
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		cmp edx, 0
		jne skipwalln
			mov ecx, 1
			jmp rt
		skipwalln:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		cmp edx, 0
		jne skipwalle
			mov ecx, 1
			jmp rt
		skipwalle:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcole3
			mov ecx, 1
			jmp rt
		skipcole3:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		cmp edx, 0
		jne skipwalls
			mov ecx, 1
			jmp rt
		skipwalls:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc ebx
		add edx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		cmp edx, 0
		jne skipwallw
			mov ecx, 1
			jmp rt
		skipwallw:
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		inc ebx
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolw3
			mov ecx, 1
			jmp rt
		skipcolw3:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkJColL endp

checkSColL PROC
	;detects collision of "S" tetromino to the left
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		cmp edx, 0
		jne skipwallh
			mov ecx, 1
			jmp rt
		skipwallh:
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh1
			mov ecx, 1
			jmp rt
		skipcolh1:
		inc ebx
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh2
			mov ecx, 1
			jmp rt
		skipcolh2:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		cmp edx, 0
		jne skipwallv
			mov ecx, 1
			jmp rt
		skipwallv:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv1
			mov ecx, 1
			jmp rt
		skipcolv1:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv2
			mov ecx, 1
			jmp rt
		skipcolv2:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv3
			mov ecx, 1
			jmp rt
		skipcolv3:
		mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkSColL endp

checkZColL PROC
	;detects collision of "Z" tetromino to the left
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		cmp edx, 0
		jne skipwallh
			mov ecx, 1
			jmp rt
		skipwallh:
		dec edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh1
			mov ecx, 1
			jmp rt
		skipcolh1:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolh2
			mov ecx, 1
			jmp rt
		skipcolh2:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		cmp edx, 0
		jne skipwallv
			mov ecx, 1
			jmp rt
		skipwallv:
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv1
			mov ecx, 1
			jmp rt
		skipcolv1:
		dec edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv2
			mov ecx, 1
			jmp rt
		skipcolv2:
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcolv3
			mov ecx, 1
			jmp rt
		skipcolv3:
		mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkZColL endp

detectColisionL PROC
	;uses tetromino specific functions to detect a collision to the left
	;sets ecx to 1 if collided
	push eax
	mov eax, tetr.kind
	cmp eax, 1
	jne skipo
		invoke checkOColL
		jmp rt
	skipo:
	cmp eax, 2
	jne skipi
		invoke checkIColL
		jmp rt
	skipi:
	cmp eax, 3
	jne skipt
		invoke checkTColL
		jmp rt
	skipt:
	cmp eax, 4
	jne skipl
		invoke checkLColL
		jmp rt
	skipl:
	cmp eax, 5
	jne skipj
		invoke checkJColL
		jmp rt
	skipj:
	cmp eax, 6
	jne skips
		invoke checkSColL
		jmp rt
	skips:
	cmp eax, 7
	jne skipz
		invoke checkZColL
		jmp rt
	skipz:
	rt:
	pop eax
	ret
detectColisionL endp

checkIRotR PROC
	;uses the Super Rotation System 
	;determines how must the "I" tetromino rotate clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 3
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 3
			sub ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 9
			je p2e
			cmp edx, 1
			jle p2e
			add ebx, 2
			sub edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 2
			jle p3e
			add ebx, 2
			sub edx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 7
			jge p4e
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 2
			jle p5e
			sub edx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 7
			jge p0e
			add ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			sub ebx, 2
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 3
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 3
			sub ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			cmp edx, 8
			jge p2w
			inc ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 7
			jge p3w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 2
			jle p4w
			sub edx, 3
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 7
			jge p5w
			add ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 2
			jle p0w
			sub edx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkIRotR endp

checkTRotR PROC
	;uses the Super Rotation System 
	;determines how must the "T" tetromino rotate clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			jmp p5n
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			inc ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			jmp p4s
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			inc ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			add ebx, 2
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			dec ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkTRotR endp

checkLRotR PROC
	;uses the Super Rotation System 
	;determines how must the "L" tetromino rotate clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			add ebx, 2
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			add ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			inc ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			add ebx, 2
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			dec ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkLRotR endp

checkJRotR PROC
	;uses the Super Rotation System 
	;determines how must the "J" tetromino rotate clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p3w
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p4w
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p5w
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p0w
			dec edx
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkJRotR endp

checkSRotR PROC
	;uses the Super Rotation System 
	;determines how must the "S" tetromino rotate clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			dec edx
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			add ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p3w
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p4w
			dec edx
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p5w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p0w
			dec edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkSRotR endp

checkZRotR PROC
	;uses the Super Rotation System 
	;determines how must the "Z" tetromino rotate clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p3w
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p4w
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p5w
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p0w
			dec edx
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkZRotR endp

checkIRotL PROC
	;uses the Super Rotation System 
	;determines how must the "I" tetromino rotate counter-clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 3
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			sub ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 9
			je p2e
			cmp edx, 1
			jle p2e
			inc ebx
			sub edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 7
			jge p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 2
			jle p4e
			sub edx, 3
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 7
			jge p5e
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 2
			jle p0e
			sub edx, 3
			add ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			sub ebx, 2
			add edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 3
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			sub ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			cmp edx, 8
			jge p2w
			add ebx, 2
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 2
			jle p3w
			sub edx, 3
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 7
			jge p4w
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 2
			jle p5w
			sub edx, 3
			add ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 7
			jge p0w
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkIRotL endp

checkTRotL PROC
	;uses the Super Rotation System 
	;determines how must the "T" tetromino rotate counter-clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			add edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			jmp p5n
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			add edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			inc ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			jmp p4s
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			inc ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			add ebx, 2
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			dec ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkTRotL endp

checkLRotL PROC
	;uses the Super Rotation System 
	;determines how must the "L" tetromino rotate counter-clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			inc ebx
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			add ebx, 2
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			add ebx, 3
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2w
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkLRotL endp

checkJRotL PROC
	;uses the Super Rotation System 
	;determines how must the "J" tetromino rotate counter-clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			sub ebx, 2
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc ebx
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p3w
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p4w
			dec edx
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p5w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p0w
			dec edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkJRotL endp

checkSRotL PROC
	;uses the Super Rotation System 
	;determines how must the "S" tetromino rotate counter-clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p3w
			dec edx
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p4w
			dec edx
			add ebx, 3
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p5w
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p0w
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkSRotL endp

checkZRotL PROC
	;uses the Super Rotation System 
	;determines how must the "Z" tetromino rotate counter-clockwise
	push ebx
	push ecx
	push edx
	mov ecx, 0
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		p1n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2n
			mov eax, 1
			jmp rt
		p2n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3n
			mov eax, 2
			jmp rt
		p3n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4n
			mov eax, 3
			jmp rt
		p4n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5n
			mov eax, 4
			jmp rt
		p5n:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0n
			mov eax, 5
			jmp rt
		p0n:
			mov eax, 0
			jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		p1e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p2e
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2e
			mov eax, 1
			jmp rt
		p2e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p3e
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3e
			mov eax, 2
			jmp rt
		p3e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p4e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4e
			mov eax, 3
			jmp rt
		p4e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p5e
			dec edx
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5e
			mov eax, 4
			jmp rt
		p5e:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p0e
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0e
			mov eax, 5
			jmp rt
		p0e:
			mov eax, 0
			jmp rt
	skipe:
	cmp eax, 3
	jne skips
		p1s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			add edx, 2
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2s
			mov eax, 1
			jmp rt
		p2s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3s
			mov eax, 2
			jmp rt
		p3s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			sub ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4s
			mov eax, 3
			jmp rt
		p4s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5s
			mov eax, 4
			jmp rt
		p5s:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			inc edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			dec edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0s
			mov eax, 5
			jmp rt
		p0s:
			mov eax, 0
			jmp rt
	skips:
	cmp eax, 4
	jne skipw
		p1w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p2w
			mov eax, 1
			jmp rt
		p2w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p3w
			dec edx
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p3w
			mov eax, 2
			jmp rt
		p3w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p4w
			dec edx
			add ebx, 2
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p4w
			mov eax, 3
			jmp rt
		p4w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 8
			je p5w
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p5w
			mov eax, 4
			jmp rt
		p5w:
			mov edx, tetr.pos.x
			mov ebx, tetr.pos.y
			cmp edx, 0
			je p0w
			dec edx
			dec ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc ebx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			inc edx
			invoke getBlockLoc, edx, ebx
			cmp [eax], ecx
			jne p0w
			mov eax, 5
			jmp rt
		p0w:
			mov eax, 0
			jmp rt
	skipw:
	rt:
	pop edx
	pop ecx
	pop ebx
	ret
checkZRotL endp

checkOswitch PROC
	;detects collision of "O" tetromino from bellow with switch block
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	add ebx, 2
	invoke getBlockLoc, edx, ebx
	mov eax, [eax]
	cmp eax, 12
	jne skipcol1
		mov ecx, 1
		jmp rt
	skipcol1:
	inc edx
	invoke getBlockLoc, edx, ebx
	mov eax, [eax]
	cmp eax, 12
	jne skipcol2
		mov ecx, 1
		jmp rt
	skipcol2:
	mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkOswitch endp

checkIswitch PROC
	;detects collision of "I" tetromino from bellow with swithc block
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcol1
			mov ecx, 1
			jmp rt
		skipcol1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcol2
			mov ecx, 1
			jmp rt
		skipcol2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcol3
			mov ecx, 1
			jmp rt
		skipcol3:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcol4
			mov ecx, 1
			jmp rt
		skipcol4:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		add ebx, 4
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcol
			mov ecx, 1
			jmp rt
		skipcol:
		mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkIswitch endp

checkTswitch PROC
	;detects collision of "T" tetromino from bellow with switch block
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcoln3
			mov ecx, 1
			jmp rt
		skipcoln3:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		dec ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		inc edx
		dec ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcols3
			mov ecx, 1
			jmp rt
		skipcols3:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkTswitch endp

checkJswitch PROC
	;detects collision of "J" tetromino from bellow with switch block
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcoln3
			mov ecx, 1
			jmp rt
		skipcoln3:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc edx
		sub ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcols3
			mov ecx, 1
			jmp rt
		skipcols3:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkJswitch endp

checkLswitch PROC
	;detects collision of "L" tetromino from bellow with switch block
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 1
	jne skipn
		;north
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcoln1
			mov ecx, 1
			jmp rt
		skipcoln1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 0
		je skipcoln2
			mov ecx, 1
			jmp rt
		skipcoln2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcoln3
			mov ecx, 1
			jmp rt
		skipcoln3:
		mov ecx, 0
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcole1
			mov ecx, 1
			jmp rt
		skipcole1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcole2
			mov ecx, 1
			jmp rt
		skipcole2:
		mov ecx, 0
		jmp rt
	skipe:
	cmp eax, 3
	jne skips
		;south
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcols1
			mov ecx, 1
			jmp rt
		skipcols1:
		inc edx
		dec ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcols2
			mov ecx, 1
			jmp rt
		skipcols2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcols3
			mov ecx, 1
			jmp rt
		skipcols3:
		mov ecx, 0
		jmp rt
	skips:
	cmp eax, 4
	jne skipw
		;west
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolw1
			mov ecx, 1
			jmp rt
		skipcolw1:
		add ebx, 2
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolw2
			mov ecx, 1
			jmp rt
		skipcolw2:
		mov ecx, 0
		jmp rt
	skipw:
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkLswitch endp

checkSswitch PROC
	;detects collision of "S" tetromino from bellow with switch block
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolh1
			mov ecx, 1
			jmp rt
		skipcolh1:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolh2
			mov ecx, 1
			jmp rt
		skipcolh2:
		dec ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolh3
			mov ecx, 1
			jmp rt
		skipcolh3:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		add ebx, 2
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolv1
			mov ecx, 1
			jmp rt
		skipcolv1:
		inc ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolv2
			mov ecx, 1
			jmp rt
		skipcolv2:
		mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkSswitch endp

checkZswitch PROC
	;detects collision of "Z" tetromino from bellow with switch block
	push eax
	push ebx
	push edx
	mov edx, tetr.pos.x
	mov ebx, tetr.pos.y
	mov eax, tetr.rot
	cmp eax, 2
	je skiphor
	cmp eax, 4
	jne skiphor
		;horizontal
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		je skipcolh1
			mov ecx, 1
			jmp rt
		skipcolh1:
		inc edx
		inc ebx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolh2
			mov ecx, 1
			jmp rt
		skipcolh2:
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolh3
			mov ecx, 1
			jmp rt
		skipcolh3:
		mov ecx, 0
		jmp rt
	skiphor:
		;vertical
		add ebx, 3
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolv1
			mov ecx, 1
			jmp rt
		skipcolv1:
		dec ebx
		inc edx
		invoke getBlockLoc, edx, ebx
		mov eax, [eax]
		cmp eax, 12
		jne skipcolv2
			mov ecx, 1
			jmp rt
		skipcolv2:
		mov ecx, 0
	rt:
	pop edx
	pop ebx
	pop eax
	ret
checkZswitch endp

checkSwitch PROC
	;uses tetromino specific functions to detect a collision with switch block from bellow
	;sets ecx to 1 if collided
	push eax
	mov eax, tetr.kind
	cmp eax, 1
	jne skipo
		invoke checkOswitch
		jmp rt
	skipo:
	cmp eax, 2
	jne skipi
		invoke checkIswitch
		jmp rt
	skipi:
	cmp eax, 3
	jne skipt
		invoke checkTswitch
		jmp rt
	skipt:
	cmp eax, 4
	jne skipl
		invoke checkLswitch
		jmp rt
	skipl:
	cmp eax, 5
	jne skipj
		invoke checkJswitch
		jmp rt
	skipj:
	cmp eax, 6
	jne skips
		invoke checkSswitch
		jmp rt
	skips:
	cmp eax, 7
	jne skipz
		invoke checkZswitch
		jmp rt
	skipz:
	rt:
	pop eax
	ret
checkSwitch endp