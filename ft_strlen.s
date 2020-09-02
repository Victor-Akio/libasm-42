; rdi/rsi - 64bits register for source and dest
; rax/rdx - 64bits register of general purposes
; inc - increment to instruction
; jne - jump if not equal to '\0'
; mov - move data from src to dst

segment .text
		global ft_strlen

; size_t	ft_strlen(char *);
ft_strlen:
		mov rax, -1				; i = -1
loop:
		inc rax					; i++;
		cmp BYTE [rdi + rax], 0	; compare str[rax] with '\0'
		jne loop				; while loop
		ret						; return rax