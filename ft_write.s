; ssize_t write(int fd, const void *buf, size_t count);
; ft_write(r8, r9, rdx)

segment .text
		global ft_write

ft_write:
		mov rbx, rdx		; save len (rbx) in rdx
		mov rax, 0x2000004	; set call to write in rax
		syscall				; call rax / write
			jc error		; if do not write, jump if carry (flag to 1) to error
		mov rax, rbx		; set rbx (rdx value) in ret
		ret					; return rax

error:
		mov rax, -1			; set return to -1
		ret					; return error
