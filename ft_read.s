; ft_read(r8, r9, rdx);

segment .text
		global ft_read
		extern __errno_location

ft_read:
		mov rax, 0				; set call to read
		syscall					; call rax / read
		cmp rax, 0				; compare rax with 0
		jl error				; if rax < 0, jump to error.
		ret						; return rax

error:
		neg rax					; set negative rax
		push rax				; put rax in top of stack
		call __errno_location	; call error number definition
		pop rbx					; get rbx from top stack
		mov [rax], rbx			; set error in ptr rax
		mov rax, -1				; set return to -1
		ret						; return error