; ssize_t write(int fd, const void *buf, size_t count);
; ft_write(r8, r9, rdx)

segment .text
		global ft_write
		extern __errno_location

ft_write:
		mov rbx, rdx			; save len (rbx) in rdx
		mov rax, 0x2000004		; set call to write in rax
		syscall					; call rax / write
		cmp rax, 0				; verifica valor de rax com 0
		jl error				; if rax < 0 jump to error
		mov rax, rbx			; set rbx (rdx value) in ret
		ret						; return rax

error:
		push rax				; put rax in top of stack
		call __errno_location	; call error definition.
		pop rcx					; get rbx from top stack
		neg rcx					; set negative rax
		mov [rax], rcx			; set error in rcx
		mov rax, -1				; set return to -1
		ret						; return error
