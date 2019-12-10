.code

getBlockLoc PROC x:DWORD, y:DWORD
	;sets eax to the location in the RAM of block in position (x, y)
	push ebx
	push ecx
	push edx
	mov eax, SIZEOF Row
	mul y
	mov ebx, offset matrix
	add ebx, eax
	mov eax, x
	mov ecx, 4
	mul ecx
	add ebx, eax
	mov eax, ebx
	pop edx
	pop ecx
	pop ebx
	ret
getBlockLoc endp

getImgLoc PROC kind:DWORD
	;sets eax to the location in the RAM of the image of the mino of type "kind"
	push edx
	mov eax, kind
	dec eax
	push ebx
	mov ebx, SIZEOF Img
	mul ebx
	pop ebx
	add eax, offset minos
	pop edx
	ret
getImgLoc endp

getRandomNumber PROC min:DWORD, max:DWORD
	LOCAL _st:SYSTEMTIME
	;puts a random number in eax between min and max (min<=num<max) generated using system time
	push ecx
	push edx
	invoke GetSystemTime, addr _st
	movzx eax, SYSTEMTIME.wMilliseconds[_st]
	mov ecx, max
	sub ecx, min
	cmp ecx, 1
	xor edx, edx
	div ecx
	add edx, min
	mov eax, edx
	rt:
	mov temp, eax
	;invoke Sleep, 6
	mov eax, temp
	pop edx
	pop ecx
	ret
getRandomNumber endp

loadBag PROC dst:DWORD, src:DWORD
	;sets bag at location dst in RAM to bag at location src in RAM
	pusha
	mov ecx, 9
	mov eax, src
	mov ebx, dst
	lop:
	mov edx, [eax]
	mov [ebx], edx
	add eax, 4
	add ebx, 4
	dec ecx
	cmp ecx, 0
	jg lop
	popa
	ret
loadBag endp

loadRow PROC dst:DWORD, src:DWORD
	;sets row at location dst in RAM to row at location src in RAM
	pusha
	invoke getBlockLoc, 0, src
	mov ebx, [eax]
	invoke getBlockLoc, 0, dst
	mov [eax], ebx
	invoke getBlockLoc, 1, src
	mov ebx, [eax]
	invoke getBlockLoc, 1, dst
	mov [eax], ebx
	invoke getBlockLoc, 2, src
	mov ebx, [eax]
	invoke getBlockLoc, 2, dst
	mov [eax], ebx
	invoke getBlockLoc, 3, src
	mov ebx, [eax]
	invoke getBlockLoc, 3, dst
	mov [eax], ebx
	invoke getBlockLoc, 4, src
	mov ebx, [eax]
	invoke getBlockLoc, 4, dst
	mov [eax], ebx
	invoke getBlockLoc, 5, src
	mov ebx, [eax]
	invoke getBlockLoc, 5, dst
	mov [eax], ebx
	invoke getBlockLoc, 6, src
	mov ebx, [eax]
	invoke getBlockLoc, 6, dst
	mov [eax], ebx
	invoke getBlockLoc, 7, src
	mov ebx, [eax]
	invoke getBlockLoc, 7, dst
	mov [eax], ebx
	invoke getBlockLoc, 8, src
	mov ebx, [eax]
	invoke getBlockLoc, 8, dst
	mov [eax], ebx
	invoke getBlockLoc, 9, src
	mov ebx, [eax]
	invoke getBlockLoc, 9, dst
	mov [eax], ebx
	popa
	ret
loadRow endp