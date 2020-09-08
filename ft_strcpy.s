; Rep - Repeats execution of string instructions while CX != 0.
; movsb - Move byte at address DS:(E)SI to address ES:(E)DI
; cld - clear de DF from register. When DF == 0, string op. increase the index registers (ESI/EDI)

segment .text
		global ft_strcpy
		extern ft_strlen

; ft_strcpy(arg0, arg1)
; ft_strcpy(rdi, rsi)
; ft_strcpy(dst, src)
ft_strcpy:
		push rdi			; save on to of the stack
		mov rdi, rsi		; save the src in the dest
		call ft_strlen		; result will be saved in rax
		mov rcx, rax		; save the length in rcx
		pop rdi				; get rdi from top stack
		cld					; clear set DF to 0, for REP increase
		mov rax, rdi		; set rdi with the first adress of rax
		rep movsb			; move byte by byte of a string from rsi to rdi at rep, rep increases while rsi != 0
		mov BYTE [rdi], 0	; rdi increases by mosvb, the current position is at the end of the string and set \0
		ret					; return rax