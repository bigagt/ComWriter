; a simple hello world .COM

; compile with: yasm -o simple.com simple.asm

; Ange Albertini, BSD Licence, 2013

org 100h ; standard loaded address
bits 16 ; ouch :p

randomAmount equ 1h
DISPLAY_STRING equ 9h
TERMINATE_WITH_RETURN_CODE equ 4ch

MAIN_DOS_API equ 21h

	mov ecx, 10h    			; size of string
	mov bh, randomAmount 	; amount to add to hello world string
	mov edx, msg   			; initial memory address of data
	
loopstart
	mov ah, [edx] 			; copy the value at bx to ah
	add ah, bh	; do the addition
	mov [edx], ah			; copy the value back
	inc edx
	loop loopstart

    ; print("Hello World!\r\n\r")
    mov  edx, msg			; reset back to the beginning of the string
    mov  ah, DISPLAY_STRING	; set up the print
    int  MAIN_DOS_API		; print

    ; return 1;
    ERRORCODE equ 1
    mov  ax, (TERMINATE_WITH_RETURN_CODE << 8) | ERRORCODE
    int  MAIN_DOS_API

msg db 'Hello World!', 0dh, 0dh, 0ah, '$' ; DOS string are $-terminated

