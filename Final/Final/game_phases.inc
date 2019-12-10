include funcs.inc

.code
generationPhase PROC
	;generates a new tetromino. if cannot fall, game over.
	pusha
	invoke generate
	invoke Sleep, fallTime
	invoke detectColisionD
	cmp ecx, 1
	jne skipgo
	mov gameOver, 1
	skipgo:
	popa
	ret
generationPhase endp

fallingPhase PROC
	;move tetromino 1 block down. wait falltime before moving to lock phase (chance to manipulate tetromino)
	pusha
	invoke removeTetromino
	invoke getBlockLoc, 5, 10
	mov ebx, 12
	mov [eax], ebx
	invoke checkSwitch
	invoke getBlockLoc, 5, 10
	mov ebx, 0
	mov [eax], ebx
	cmp ecx, 0
	je skipswitch
	invoke getRandomNumber, 1, 8
	mov tetr.kind, eax
	skipswitch:
	invoke putTetromino
	invoke moveTetromino, 0, 1
	invoke Sleep, fallTime
	popa
	ret
fallingPhase endp

lockPhase PROC
	;if tetromino cannot fall, lock it
	push eax
	invoke detectColisionD
	pop eax
	ret
lockPhase endp

patternPhase PROC
	;for all rows, check if the row is full. if it is full, clear it and shift all rows above one block down.
	pusha
	mov edx, 0
	lop:
	invoke checkRowClear, edx
	cmp ecx, 1
	jne skipclr
	invoke clearRow, edx
	skipclr:
	inc edx
	cmp edx, 22
	jl lop
	popa
	ret
patternPhase endp