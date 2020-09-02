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
		push rax				; put rax in top of stack
		call __errno_location	; call error definition.
		pop rcx					; get rbx from top stack
		neg rcx					; set negative rax
		mov [rax], rcx			; set error in rcx
		mov rax, -1				; set return to -1
		ret						; return error