global ft_write
extern __errno_location 

ft_write:
		mov rax, 1
		syscall
		cmp rax, 0
		jl exit_error

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
