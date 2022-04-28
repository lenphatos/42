global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
		cmp rax, 0
		je return_error
		call ft_strlen
		push rdi
		mov rdi, rax
		call malloc
		cmp rax, 0
		je return_error
		pop rdi
		mov rsi, rdi
		mov rdi, rax
		call ft_strcpy
		ret


return_error:
		mov rax, 0
		ret
