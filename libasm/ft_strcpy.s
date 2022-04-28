global	ft_strcpy

ft_strcpy:
		mov rax, rdi
		mov rbx, -1

loop:
		inc rbx
		mov rax, [rsi + rbx]
		mov [rdi + rbx], rax
		cmp BYTE [rsi + rbx], 0
		jne loop

end:
	mov rax, rdi
	ret
