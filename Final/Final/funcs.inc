include collision_detectors.inc

includelib Winmm.lib

PlaySound PROTO,
        pszSound:PTR BYTE, 
        hmod:DWORD, 
        fdwSound:DWORD

.code

loadImgs PROC
	LOCAL counter:DWORD
	;loads all images
	pusha
	invoke drd_imageLoadFile, offset redLineLoc, offset redLine
	invoke drd_imageLoadFile, offset gridLineHorLoc, offset gridLineHor
	invoke drd_imageLoadFile, offset gridLineVerLoc, offset gridLineVer
	mov eax, offset minos
	mov counter, eax
	invoke drd_imageLoadFile, offset yellowMinoLoc, counter
	add counter, SIZEOF Img
	invoke drd_imageLoadFile, offset blueMinoLoc, counter
	add counter, SIZEOF Img
	invoke drd_imageLoadFile, offset pinkMinoLoc, counter
	add counter, SIZEOF Img
	invoke drd_imageLoadFile, offset orangeMinoLoc, counter
	add counter, SIZEOF Img
	invoke drd_imageLoadFile, offset purpleMinoLoc, counter
	add counter, SIZEOF Img
	invoke drd_imageLoadFile, offset greenMinoLoc, counter
	add counter, SIZEOF Img
	invoke drd_imageLoadFile, offset redMinoLoc, counter
	invoke drd_imageLoadFile, offset switchLoc, offset switchi
	popa
	ret
loadImgs endp

drawGrid PROC
	;draws the grid of the matrix
	;thin green lines for the borders of the blocks, and a red line where game is over
	pusha
	mov ecx, 9
	vers:
		mov eax, 30
		push ecx
		mul ecx
		invoke drd_imageDraw, offset gridLineVer, eax, 0
		pop ecx
		dec ecx
	jnz vers
	mov ecx, 21
	hors:
		mov eax, 30
		push ecx
		mul ecx
		invoke drd_imageDraw, offset gridLineHor, 0, eax
		pop ecx
		dec ecx
	jnz hors
	invoke drd_imageDraw, offset redLine, 0, 60
	invoke drd_imageDraw, offset switchi, 148, 298
	popa
	ret
drawGrid endp

loadSurface PROC
	;sets the bottom row (row #22 - out of screen) to be occupied
	;so that tetrominos landing on bottom will stop moving
	pusha
	mov ecx, 10
	lop:
		invoke getBlockLoc, ecx, 22
		mov ebx, 8
		mov [eax], ebx
		dec ecx
	cmp ecx, 0
	jne lop
	popa
	ret
loadSurface endp

putO PROC
	;puts the "O" tetromino according to position
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov ebx, tetr.kind
	invoke getBlockLoc, ecx, edx
	mov [eax], ebx
	inc ecx
	invoke getBlockLoc, ecx, edx
	mov [eax], ebx
	dec ecx
	inc edx
	invoke getBlockLoc, ecx, edx
	mov [eax], ebx
	inc ecx
	invoke getBlockLoc, ecx, edx
	mov [eax], ebx
	popa
	ret
putO endp

putI PROC
	;puts the "I" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, tetr.kind
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skiphor:
		;vertical
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	rt:
	popa
	ret
putI endp

putT PROC
	;puts the "T" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, tetr.kind
	cmp eax, 1
	jne skipn
		;north
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipe:
	cmp eax, 3
	jne skips
		;south
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		dec edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skips:
	cmp eax, 4
	jne skipw
		;west
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipw:
	rt:
	popa
	ret
putT endp

putL PROC
	;puts the "L" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, tetr.kind
	cmp eax, 1
	jne skipn
		;north
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipe:
	cmp eax, 3
	jne skips
		;south
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		sub ecx, 2
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skips:
	cmp eax, 4
	jne skipw
		;west
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipw:
	rt:
	popa
	ret
putL endp

putJ PROC
	;puts the "J" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, tetr.kind
	cmp eax, 1
	jne skipn
		;north
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipe:
	cmp eax, 3
	jne skips
		;south
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skips:
	cmp eax, 4
	jne skipw
		;west
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipw:
	rt:
	popa
	ret
putJ endp

putS PROC
	;puts the "S" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, tetr.kind
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skiphor:
		;vertical
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	rt:
	popa
	ret
putS endp

putZ PROC
	;puts the "Z" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, tetr.kind
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skiphor:
		;vertical
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	rt:
	popa
	ret
putZ endp

putTetromino PROC
	;sets all blocks to be occupied by the tetromino to the type of tetromino
	;calls functions specific to the type of tetromino
	pusha
	mov ebx, tetr.kind
	cmp ebx, 1
	jne skipo
		invoke putO
		jmp rt
	skipo:
	cmp ebx, 2
	jne skipi
		invoke putI
		jmp rt
	skipi:
	cmp ebx, 3
	jne skipt
		invoke putT
		jmp rt
	skipt:
	cmp ebx, 4
	jne skipl
		invoke putL
		jmp rt
	skipl:
	cmp ebx, 5
	jne skipj
		invoke putJ
		jmp rt
	skipj:
	cmp ebx, 6
	jne skips
		invoke putS
		jmp rt
	skips:
	cmp ebx, 7
	jne skipz
		invoke putZ
		jmp rt
	skipz:
	rt:
	popa
	ret
putTetromino endp

removeO PROC
	;removes the "O" tetromino according to position
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov ebx, 0
	invoke getBlockLoc, ecx, edx
	mov [eax], ebx
	inc ecx
	invoke getBlockLoc, ecx, edx
	mov [eax], ebx
	dec ecx
	inc edx
	invoke getBlockLoc, ecx, edx
	mov [eax], ebx
	inc ecx
	invoke getBlockLoc, ecx, edx
	mov [eax], ebx
	popa
	ret
removeO endp

removeI PROC
	;removes the "I" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, 0
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skiphor:
		;vertical
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	rt:
	popa
	ret
removeI endp

removeT PROC
	;removes the "T" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, 0
	cmp eax, 1
	jne skipn
		;north
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipe:
	cmp eax, 3
	jne skips
		;south
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		dec edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skips:
	cmp eax, 4
	jne skipw
		;west
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipw:
	rt:
	popa
	ret
removeT endp

removeL PROC
	;removes the "L" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, 0
	cmp eax, 1
	jne skipn
		;north
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipe:
	cmp eax, 3
	jne skips
		;south
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		sub ecx, 2
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skips:
	cmp eax, 4
	jne skipw
		;west
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipw:
	rt:
	popa
	ret
removeL endp

removeJ PROC
	;removes the "J" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, 0
	cmp eax, 1
	jne skipn
		;north
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skipn:
	cmp eax, 2
	jne skipe
		;east
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipe:
	cmp eax, 3
	jne skips
		;south
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skips:
	cmp eax, 4
	jne skipw
		;west
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	skipw:
	rt:
	popa
	ret
removeJ endp

removeS PROC
	;removes the "S" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, 0
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skiphor:
		;vertical
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	rt:
	popa
	ret
removeS endp

removeZ PROC
	;removes the "Z" tetromino according to position and rotation
	pusha
	mov ecx, tetr.pos.x
	mov edx, tetr.pos.y
	mov eax, tetr.rot
	mov ebx, 0
	cmp eax, 2
	je skiphor
	cmp eax, 4
	je skiphor
		;horizontal
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		jmp rt
	skiphor:
		;vertical
		inc ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		dec ecx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
		inc edx
		invoke getBlockLoc, ecx, edx
		mov [eax], ebx
	rt:
	popa
	ret
removeZ endp

removeTetromino PROC
	;clears all blocks previously occupied by the tetromino
	;calls functions specific to the type of tetromino
	pusha
	mov ebx, tetr.kind
	cmp ebx, 1
	jne skipo
		invoke removeO
		jmp rt
	skipo:
	cmp ebx, 2
	jne skipi
		invoke removeI
		jmp rt
	skipi:
	cmp ebx, 3
	jne skipt
		invoke removeT
		jmp rt
	skipt:
	cmp ebx, 4
	jne skipl
		invoke removeL
		jmp rt
	skipl:
	cmp ebx, 5
	jne skipj
		invoke removeJ
		jmp rt
	skipj:
	cmp ebx, 6
	jne skips
		invoke removeS
		jmp rt
	skips:
	cmp ebx, 7
	jne skipz
		invoke removeZ
		jmp rt
	skipz:
	rt:
	popa
	ret
removeTetromino endp

moveTetromino PROC x:DWORD, y:DWORD
	;moves the tetromino x blocks to the right, y blocks down
	pusha
	cmp x, 0
	jle skipr
		invoke moveTetromino, 0, y
		invoke detectColisionR
		pusha
		mov eax, y
		mov ebx, -1
		mul ebx
		invoke moveTetromino, 0, eax
		popa
		cmp ecx, 0
		jne rt
		jmp skipl
	skipr:
	jge skipl
		invoke moveTetromino, 0, y
		invoke detectColisionL
		pusha
		mov eax, y
		mov ebx, -1
		mul ebx
		invoke moveTetromino, 0, eax
		popa
		cmp ecx, 0
		jne rt
		jmp skipl
	skipl:
	invoke removeTetromino
	mov eax, x
	add tetr.pos.x, eax
	mov eax, y
	add tetr.pos.y, eax
	rt:
	popa
	ret
moveTetromino endp

rotOR PROC
	;does nothing, as "O" tetromino is symmetric under rotation
	ret
rotOR endp

rotIR PROC
	;rotates the "I" tetromino clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkIRotR
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			add tetr.pos.x, 2
			dec tetr.pos.y
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			dec tetr.pos.y
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			add tetr.pos.x, 3
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			add tetr.pos.x, 3
			sub tetr.pos.y, 3
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			sub tetr.pos.x, 2
			add tetr.pos.y, 2
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			sub tetr.pos.x, 3
			add tetr.pos.y, 2
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			add tetr.pos.y, 2
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			sub tetr.pos.x, 3
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			add tetr.pos.y, 3
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			inc tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			add tetr.pos.x, 3
			sub tetr.pos.y, 2
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			add tetr.pos.x, 3
			sub tetr.pos.y, 3
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			inc tetr.pos.y
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			sub tetr.pos.x, 3
			inc tetr.pos.y
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			add tetr.pos.y, 3
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			sub tetr.pos.x, 3
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotIR endp

rotTR PROC
	;rotates the "T" tetromino clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkTRotR
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			inc tetr.pos.x
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 5
		jne skip5n
			add tetr.pos.x, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			add tetr.pos.y, 2
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			dec tetr.pos.y
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			sub tetr.pos.y, 2
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotTR endp

rotLR PROC
	;rotates the "L" tetromino clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkLRotR
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			inc tetr.pos.x
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			inc tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			add tetr.pos.y, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			inc tetr.pos.y
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			add tetr.pos.y, 2
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			dec tetr.pos.y
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			inc tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			sub tetr.pos.y, 2
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotLR endp

rotJR PROC
	;rotates the "J" tetromino clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkJRotR
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			inc tetr.pos.x
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			inc tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			add tetr.pos.y, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			inc tetr.pos.y
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			add tetr.pos.y, 2
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			dec tetr.pos.y
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			inc tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			sub tetr.pos.y, 2
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotJR endp

rotSR PROC
	;rotates the "S" tetromino clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkSRotR
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			inc tetr.pos.x
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			inc tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			add tetr.pos.y, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			inc tetr.pos.y
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			add tetr.pos.y, 2
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			dec tetr.pos.y
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			inc tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			sub tetr.pos.y, 2
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotSR endp

rotZR PROC
	;rotates the "Z" tetromino clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkZRotR
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			inc tetr.pos.x
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			inc tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			add tetr.pos.y, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			inc tetr.pos.y
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			add tetr.pos.y, 2
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			dec tetr.pos.y
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			inc tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			sub tetr.pos.y, 2
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotZR endp

rotateTetrominoR PROC
	;rotates the tetromino clockwise
	;calls functions specific to the type of tetromino
	pusha
	invoke removeTetromino
	mov eax, tetr.kind
	cmp eax, 1
	jne skipo
		invoke rotOR
		jmp rt
	skipo:
	cmp eax, 2
	jne skipi
		invoke rotIR
		jmp rt
	skipi:
	cmp eax, 3
	jne skipt
		invoke rotTR
		jmp rt
	skipt:
	cmp eax, 4
	jne skipl
		invoke rotLR
		jmp rt
	skipl:
	cmp eax, 5
	jne skipj
		invoke rotJR
		jmp rt
	skipj:
	cmp eax, 6
	jne skips
		invoke rotSR
		jmp rt
	skips:
	cmp eax, 7
	jne skipz
		invoke rotZR
		jmp rt
	skipz:
	rt:
	inc tetr.rot
	cmp tetr.rot, 5
	jne skip1
	mov tetr.rot, 1
	skip1:
	invoke putTetromino
	popa
	ret
rotateTetrominoR endp

rotOL PROC
	;does nothing, as "O" tetromino is symmetric under rotation
	ret
rotOL endp

rotIL PROC
	;rotates the "I" tetromino counter-clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkIRotL
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			dec tetr.pos.y
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			add tetr.pos.x, 3
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			sub tetr.pos.y, 3
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			add tetr.pos.x, 3
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			sub tetr.pos.x, 2
			inc tetr.pos.y
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			inc tetr.pos.y
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			sub tetr.pos.x, 3
			inc tetr.pos.y
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			sub tetr.pos.x, 3
			add tetr.pos.y, 3
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			add tetr.pos.x, 2
			sub tetr.pos.y, 2
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			add tetr.pos.x, 3
			sub tetr.pos.y, 2
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			add tetr.pos.x, 3
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			sub tetr.pos.y, 3
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			dec tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			sub tetr.pos.x, 3
			add tetr.pos.y, 2
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			add tetr.pos.y, 2
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			sub tetr.pos.x, 3
			add tetr.pos.y, 3
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotIL endp

rotTL PROC
	;rotates the "T" tetromino counter-clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkTRotL
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			inc tetr.pos.x
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 5
		jne skip5n
			inc tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			dec tetr.pos.x
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			inc tetr.pos.y
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			dec tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			sub tetr.pos.y, 2
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			inc tetr.pos.y
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			dec tetr.pos.y
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotTL endp

rotLL PROC
	;rotates the "L" tetromino counter-clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkLRotL
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			inc  tetr.pos.x
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			sub tetr.pos.y, 3
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			add tetr.pos.y, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			dec tetr.pos.x
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			inc tetr.pos.y
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			sub tetr.pos.y, 2
			dec tetr.pos.x
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			sub tetr.pos.y, 2
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			inc tetr.pos.y
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			dec tetr.pos.y
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotLL endp

rotJL PROC
	;rotates the "J" tetromino counter-clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkJRotL
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			inc  tetr.pos.x
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			sub tetr.pos.y, 3
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			add tetr.pos.y, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			dec tetr.pos.x
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			inc tetr.pos.y
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			sub tetr.pos.y, 2
			dec tetr.pos.x
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			sub tetr.pos.y, 2
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			inc tetr.pos.y
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			dec tetr.pos.y
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotJL endp

rotSL PROC
	;rotates the "S" tetromino counter-clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkSRotL
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			inc tetr.pos.x
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			add tetr.pos.y, 2
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			inc tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			dec tetr.pos.x
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			inc tetr.pos.y
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			dec tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			sub tetr.pos.y, 2
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			inc tetr.pos.y
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			dec tetr.pos.y
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotSL endp

rotZL PROC
	;rotates the "Z" tetromino counter-clockwise
	;calls function to determine how to rotate according to Super Rotation System
	pusha
	invoke checkZRotL
	mov ebx, tetr.rot
	cmp ebx, 1
	jne skipn
		cmp eax, 1
		jne skip1n
			jmp rt
		skip1n:
		cmp eax, 2
		jne skip2n
			inc tetr.pos.x
			jmp rt
		skip2n:
		cmp eax, 3
		jne skip3n
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip3n:
		cmp eax, 4
		jne skip4n
			add tetr.pos.y, 2
			jmp rt
		skip4n:
		cmp eax, 5
		jne skip5n
			inc tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip5n:
		dec tetr.rot
		jmp rt
	skipn:
	cmp ebx, 2
	jne skipe
		cmp eax, 1
		jne skip1e
			dec tetr.pos.x
			jmp rt
		skip1e:
		cmp eax, 2
		jne skip2e
			jmp rt
		skip2e:
		cmp eax, 3
		jne skip3e
			inc tetr.pos.y
			jmp rt
		skip3e:
		cmp eax, 4
		jne skip4e
			dec tetr.pos.x
			sub tetr.pos.y, 2
			jmp rt
		skip4e:
		cmp eax, 5
		jne skip5e
			sub tetr.pos.y, 2
			jmp rt
		skip5e:
		dec tetr.rot
		jmp rt
	skipe:
	cmp ebx, 3
	jne skips
		cmp eax, 1
		jne skip1s
			inc tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip1s:
		cmp eax, 2
		jne skip2s
			dec tetr.pos.y
			jmp rt
		skip2s:
		cmp eax, 3
		jne skip3s
			sub tetr.pos.y, 2
			jmp rt
		skip3s:
		cmp eax, 4
		jne skip4s
			inc tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip4s:
		cmp eax, 5
		jne skip5s
			inc tetr.pos.y
			jmp rt
		skip5s:
		dec tetr.rot
		jmp rt
	skips:
	cmp ebx, 4
	jne skipw
		cmp eax, 1
		jne skip1w
			inc tetr.pos.y
			jmp rt
		skip1w:
		cmp eax, 2
		jne skip2w
			dec tetr.pos.x
			inc tetr.pos.y
			jmp rt
		skip2w:
		cmp eax, 3
		jne skip3w
			dec tetr.pos.x
			add tetr.pos.y, 2
			jmp rt
		skip3w:
		cmp eax, 4
		jne skip4w
			dec tetr.pos.y
			jmp rt
		skip4w:
		cmp eax, 5
		jne skip5w
			dec tetr.pos.x
			dec tetr.pos.y
			jmp rt
		skip5w:
		dec tetr.rot
		jmp rt
	skipw:
	rt:
	popa
	ret
rotZL endp

rotateTetrominoL PROC
	;rotates the tetromino counter-clockwise
	;calls functions specific to the type of tetromino
	pusha
	invoke removeTetromino
	mov eax, tetr.kind
	cmp eax, 1
	jne skipo
		invoke rotOL
		jmp rt
	skipo:
	cmp eax, 2
	jne skipi
		invoke rotIL
		jmp rt
	skipi:
	cmp eax, 3
	jne skipt
		invoke rotTL
		jmp rt
	skipt:
	cmp eax, 4
	jne skipl
		invoke rotLL
		jmp rt
	skipl:
	cmp eax, 5
	jne skipj
		invoke rotJL
		jmp rt
	skipj:
	cmp eax, 6
	jne skips
		invoke rotSL
		jmp rt
	skips:
	cmp eax, 7
	jne skipz
		invoke rotZL
		jmp rt
	skipz:
	rt:
	dec tetr.rot
	cmp tetr.rot, 0
	jne skip4
	mov tetr.rot, 4
	skip4:
	invoke putTetromino
	popa
	ret
rotateTetrominoL endp

generateBag PROC
	;generates the next bag:
	;sets current tetromino to 0
	;puts the 7 tetrominos in a random order in tetrs
	;nextbag stays same
	pusha
	mov ebx, currentBag.nextBag
	add ebx, 28
	mov eax, 0 
	mov [ebx], eax
	sub ebx, 28
	mov ecx, 6
	clrTetrs:
		mov eax, 4
		mul ecx
		mov edx, ebx
		add edx, eax
		mov eax, [edx]
		xor [edx], eax
		dec ecx
	cmp ecx, 0
	jge clrTetrs
	mov ecx, 7
	lop1:
		invoke getRandomNumber, 0, ecx
		mov edx, 0
		lop2:
			push eax
			push edx
			mov edx, 4
			mul edx
			pop edx
			add eax, ebx
			push ebx
			mov ebx, 0
			cmp [eax], ebx
			pop ebx
			pop eax
			je skipinc
			inc eax
			skipinc:
			inc edx
		cmp edx, eax
		jle lop2;
		mov edx, 4
		mul edx
		add eax, ebx
		mov [eax], ecx
		;jl lop2
		dec ecx
	cmp ecx, 0
	jg lop1
	popa
	ret
generateBag endp

popBag PROC
	;sets eax to the current tetromino in bag. increments current tetromino pointer.
	;if current tetromino pointer reaches end of bag, set currentbag to the next bag, and generate another bag.
	push edx
	push ebx
	inc currentBag.curr
	mov eax, currentBag.curr 
	cmp eax, 7
	jne skipgen
	invoke loadBag, offset currentBag, currentBag.nextBag
	invoke generateBag
	skipgen:
	mov eax, 4
	mul currentBag.curr
	add eax, offset currentBag
	mov eax, [eax]
	pop ebx
	pop edx
	ret
popBag endp

setupBags PROC
	;sets up the bags: bag1.nextbag=location of bag2, bag2.nextbag=location of bag1, generates tetrominos in both bags 
	pusha
	mov eax, offset bag1
	mov bag2.nextBag, eax
	mov eax, offset bag2
	mov bag1.nextBag, eax
	mov bag1.curr, 6
	invoke loadBag, offset currentBag, offset bag1
	invoke generateBag
	invoke popBag
	popa
	ret
setupBags endp

generate PROC
	;generates a new tetromino (current tetromino in current bag) at top of matrix
	pusha
	invoke popBag
	mov tetr.pos.x, 4
	mov tetr.pos.y, 0
	mov tetr.kind, eax
	mov tetr.rot, 1
	mov fallTime, 1000
	mov eax, falltimedec
	sub fallTime, eax
	popa
	ret
generate endp

keyHandler PROC vkey:DWORD
	;the key handler that works with "drd_setKeyHandler"
	;recieves virtual key code of key as parameter, and acts accordingly
	pusha
	mov eax, VK_RIGHT
	cmp vkey, eax
	jne skipr
	invoke moveTetromino, 1, 0
	skipr:
	mov eax, VK_LEFT
	cmp vkey, eax
	jne skipl
	invoke moveTetromino, -1, 0
	skipl:
	mov eax, VK_DOWN
	cmp vkey, eax
	jne skipd
	mov fallTime, 50
	skipd:
	mov eax, VK_UP
	cmp vkey, eax
	jne skipu
	mov fallTime, 1000
	mov eax, falltimedec
	sub fallTime, eax
	skipu:
	mov eax, 58h
	cmp vkey, eax
	jne skipx
	invoke rotateTetrominoR
	skipx:
	mov eax, 5Ah
	cmp vkey, eax
	jne skipz
	invoke rotateTetrominoL
	skipz:
	popa
	ret
keyHandler endp

checkRowClear PROC row:DWORD
	;checks if a row (row nubmer as parameter) is full. sets ecx to 1 if full, and to 0 otherwise
	push eax
	mov ecx, 0
	invoke getBlockLoc, 0, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	invoke getBlockLoc, 1, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	invoke getBlockLoc, 2, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	invoke getBlockLoc, 3, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	invoke getBlockLoc, 4, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	invoke getBlockLoc, 5, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	invoke getBlockLoc, 6, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	invoke getBlockLoc, 7, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	invoke getBlockLoc, 8, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	invoke getBlockLoc, 9, row
	mov eax, [eax]
	cmp eax, 0
	je rt
	mov ecx, 1
	rt:
	pop eax
	ret
checkRowClear endp

shiftRows PROC row:DWORD
	;shifts all rows beginning with row number (parameter) one down
	pusha
	mov ecx, row
	lop:
		mov edx, ecx
		dec edx
		invoke loadRow, ecx, edx
		dec ecx
	cmp ecx, 1
	jg lop
	popa
	ret
shiftRows endp

clearRow PROC row:DWORD
	;clears a row (row number as parameter) and shifts all rows above one block down
	pusha
	mov ebx, 0
	invoke getBlockLoc, 0, row
	mov [eax], ebx
	invoke getBlockLoc, 1, row
	mov [eax], ebx
	invoke getBlockLoc, 2, row
	mov [eax], ebx
	invoke getBlockLoc, 3, row
	mov [eax], ebx
	invoke getBlockLoc, 4, row
	mov [eax], ebx
	invoke getBlockLoc, 5, row
	mov [eax], ebx
	invoke getBlockLoc, 6, row
	mov [eax], ebx
	invoke getBlockLoc, 7, row
	mov [eax], ebx
	invoke getBlockLoc, 8, row
	mov [eax], ebx
	invoke getBlockLoc, 9, row
	mov [eax], ebx
	invoke shiftRows, row
	cmp falltimedec, 950
	jge skipaccel
	add falltimedec, 20
	skipaccel:
	popa
	ret
clearRow endp

bgMusic PROC
	;runs in seperate thread
	;plays backrgound music
	lop:
	invoke PlaySound, offset korobeinikiLoc, NULL, SND_ASYNC
	invoke Sleep, 77150
	cmp gameOver, 1
	jne lop
	ret
bgMusic endp