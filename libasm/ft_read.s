section .text
	global ft_read
	extern __errno_location

ft_read:
		mov rax, 0
		syscall
		cmp rax, 0
		jl exit_error
		jmp exit

exit_error:
	neg rax
	push rax
	call __errno_location
	mov rcx, rax
	pop rdx
	mov [rcx], rdx
	mov rax, -1
	ret
	
exit:
	ret
