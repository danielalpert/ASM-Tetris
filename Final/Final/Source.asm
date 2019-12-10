include \masm32\include\masm32rt.inc
include drd.inc
includelib drd.lib
include data.inc
include main_funcs.inc

.code
main PROC
	invoke init
	lop:
	invoke update
	invoke draw
	jmp lop
ret
main endp
end main
