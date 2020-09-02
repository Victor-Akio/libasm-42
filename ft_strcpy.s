; Rep - Repeats execution of string instructions while CX != 0.
; movsb - Move byte at address DS:(E)SI to address ES:(E)DI

segment .text
		global ft_strcpy
		extern ft_strlen

; ft_strcpy(arg0, arg1)
; ft_strcpy(rsi, rdi)
; ft_strcpy(dst, src)
ft_strcpy:
		push rdi			; save on to of the stack
		mov rdi, rsi		; move src to dst
		call ft_strlen		; result will be saved in rax
		mov rcx, rax		; move rcx to rax, because rcx wll be used later
		pop rdi				; get rdi from top stack
		cld					; clear 
		mov rax, rdi		; set rdi with the first adress of rdi
		rep movsb			; move byte by byte of a string from rsi to rdi at rep, rep increases while rsi != 0
		mov BYTE [rdi], 0	; rdi increases by mosvb, the current position is at the end of the string
		ret					; return rax