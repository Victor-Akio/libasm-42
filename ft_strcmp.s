segment .text
		global ft_strcmp

ft_strcmp:
		mov rax, 0			; i = 0
		jmp compare			; call compare
compare:
		mov al, BYTE [rdi]	; use the shortest byte of rdi to store a Char
		mov bl, BYTE [rsi]	; use the shortest byr of rsi to store a Char
		cmp al, 0			; compare if the value is '\0' - rdi
		je exit				; se o valor bater '\0' ele segue pra exit
		cmp bl, 0			; compare if the value is '\0' - rsi
		je exit				; se o valor bater '\0' ele segue pra exit
		cmp al, bl			; compare byte from rdi with rsi
		jne exit			; if (al - bl) != 0 go to exit
		inc rdi				; al++
		inc rsi				; bl++
		jmp compare			; If (al - bl) == 0, the string continue to compare the values
exit:
		movzx rax, al		; put the lower byte in a bigger one (al -> rax) and fill the remaining bytes with 0
		movzx rbx, bl		; put the lower byte in a bigger one (bl -> rbx) and fill the remaining bytes with 0
		sub rax, rbx		; stock (rax - rbx) in rax, making the diference between rsi and rdi
		ret					; return rax