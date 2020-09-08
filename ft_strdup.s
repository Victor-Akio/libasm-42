; ft_strdup(*rdi)

segment .text
		global ft_strdup
		extern ft_strlen
		extern ft_strcpy
		extern malloc

ft_strdup:
		call ft_strlen			; call len of rdi
		add rax, 1				; add +1 size for the '\0'
		push rdi				; stock on top of stack
		mov rdi, rax			; set rax len to rdi for malloc purpose
		call malloc				; call malloc of rax
		pop r9					; remove r9 from top stack
		mov rdi, rax			; set string stocked in rax to rdi
		mov rsi, r9				; get r9 poped and save in rsi to set strcpy
		call ft_strcpy			; call cpy (rdi, rsi), stocking ret as rax
		ret						; return rax

