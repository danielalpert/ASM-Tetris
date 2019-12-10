include game_phases.inc

.code
gameFlow PROC
	;runs in seperate thread
	;while the game isn't over, goes according to game flowchart:
	;generates a new tetromino, then falls until it locks down
	;then clears full rows and goes to beginning of flowchart
	;when game is over, plays game over sound and exits thread
	mov gameOver, 0
	generatePhase:
	invoke generationPhase
	cmp gameOver, 1
	je finish
	fall:
	invoke fallingPhase
	invoke lockPhase
	cmp ecx, 0
	je fall
	invoke patternPhase
	jmp generatePhase
	finish:
	invoke PlaySound, offset gameOverLoc, NULL, SND_SYNC
	invoke ExitThread, NULL
gameFlow endp

init PROC
	;initializes the game:
	;initializes the window, loads the images, loads the surface
	;sets up the "bags", sets up the key handler, creates the appropriate threads
	invoke drd_init,300,660,0
	invoke loadImgs
	invoke loadSurface
	mov fallTime, 1000
	invoke setupBags
	invoke CreateThread, NULL, NULL, offset bgMusic, NULL, 0, addr bgMusicThrId
	invoke CreateThread, NULL, NULL, offset gameFlow, NULL, 0, addr gameFlowThrId
	invoke drd_setKeyHandler, offset keyHandler
	ret
init endp

update PROC
	;processes messages, and puts the tetromino in it's appropriate place
	pusha
	invoke drd_processMessages
	invoke putTetromino
	popa
	ret
update endp

draw PROC
	LOCAL iblocks:DWORD
	LOCAL irows:DWORD
	;draws the matrix
	;draws the grid, and then draws appropriate mino for each block in matrix
	pusha
	invoke drd_pixelsClear, 0
	invoke drawGrid
	mov irows, 0
	forRows:
		mov iblocks, 0
		forBlocks:
			invoke getBlockLoc, iblocks, irows
			mov ebx, [eax]
			cmp ebx, 0
			je skipDraw
			cmp ebx, 12
			je skipDraw
			invoke getImgLoc, ebx
			push eax
			mov eax, iblocks
			mov edx, 30
			mul edx
			mov ecx, eax
			mov eax, irows
			mov edx, 30
			mul edx
			mov edx, eax
			pop eax
			invoke drd_imageDraw, eax, ecx, edx
			skipDraw:
			inc iblocks
			cmp iblocks, 9
		jle forBlocks
		inc irows
		cmp irows, 21
	jle forRows
	invoke drd_flip
	popa
	ret
draw endp