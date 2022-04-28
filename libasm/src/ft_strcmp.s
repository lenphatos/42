global ft_strcmp

ft_strcmp:
		mov bl, BYTE [rdi]
		mov cl, BYTE [rsi]
		cmp bl, 0							; while s1[i]
		je end
		cmp bl, cl							; if s1 != s2
		jne end								; return
		inc rsi								; else s1++
		inc rdi								; 		 s2++
		jmp ft_strcmp

end:
	xor rax, rax
	sub bl, cl
	mov al, bl
	jnc return

	neg al
	neg eax

return:
	ret
