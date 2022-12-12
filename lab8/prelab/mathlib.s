; mathlib.s
;
; Purpose : This file contains the implementation of the functions product and power.
;
; Parameter 1 (in rdi) is the starting address of a sequence of 64-bit longs
; Parameter 2 (in rsi) is another address of a sequence of 64-bit longs
; Return value (rax) is a long that is the product of the parameters, which then returns, and then the result of the power function
;
    global product
product:
    ; iterative product function (addition only)
    xor    rax, rax     ; zero out the return register
    xor    r10, r10     ; zero out the counter i
loop1:                  ; product(x, y) -> product (rdi, rsi)
    cmp    r10, rdi     ; does i == x
    je     endloop1     ; if so, we are done with the loop
    add    rax, rsi     ; add value of rsi to rax prod+=y
    inc    r10          ; increment our counter i
    jmp    loop1        ; we are done with this loop iteration
endloop1:
    ret                 ; return product(rdi, rsi)
    global power
power:
    ; recursive power function
    xor    rax, rax     ; zero out the return register
loop2:
    cmp    rsi, 0       ; if exp == 0
    je     loop3        ; jump to start of else loop
    dec    rsi          ; power(rdi, rsi-1)
    call   power        ;
    mov    rsi, rax     ;
    call   product      ; product(rdi, rax) -> product(rdi*power(rdi, rsi-1))
    jmp    endloop3     ;
endloop2:
loop3:
    mov     rax, 1      ; rax = 1
    jmp     endloop3    ;
endloop3:
    ret
