global  ft_strlen

ft_strlen:
		mov rax, -1

loop:
		inc rax
		cmp BYTE [rax + rdi], 0
		jne loop

end:
	ret
