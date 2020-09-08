; rdi/rsi - 64bits register for source and dest
; rax/rdx - 64bits register of general purposes
; inc - increment to instruction
; jne - jump if not equal to '\0'
; mov - move data from src to dst

segment .text
		global ft_strlen

; size_t	ft_strlen(char *);
ft_strlen:
		mov rax, -1				; i = -1 / move the value -1 to RAX
loop:
		inc rax					; i++ / this will set the first position to str[0]
		cmp BYTE [rdi + rax], 0	; compare str[rax] with '\0'
		jne loop				; if met, it will keep in the loop
		ret						; return rax