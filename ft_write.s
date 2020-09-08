; ssize_t write(int fd, const void *buf, size_t count);
; ft_write(r8, r9, rdx)

segment .text
		global ft_write
		extern __errno_location

ft_write:
		mov rax, 1				; set call to write in rax
		syscall					; call rax / write
		cmp rax, 0				; verifica valor de rax com 0
		jl error				; if rax < 0 jump to error
		ret						; return rax

error:
		neg rax					; set negative rax
		push rax				; put rax in top of stack
		call __errno_location	; call error number definition
		pop rbx					; get rbx from top stack
		mov [rax], rbx			; set error in ptr rax
		mov rax, -1				; set return to -1
		ret						; return error
