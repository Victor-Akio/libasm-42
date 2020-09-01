
segment .text
		global ft_strlen

; size_t	ft_strlen(char *);
ft_strlen:
		mov eax, -1				; i = -1
loop:
		inc eax					; i++;
		cmp BYTE [rdi + rax], 0	;comp. rbx[rax] with '\0'
		jne loop				;while loop
		ret