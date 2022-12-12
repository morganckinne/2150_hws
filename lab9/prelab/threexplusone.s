; Morgan Kinne
; 2150
; Lab 9 prelab
; 11/14/2021
; using and (for mod) cited: https://www.tutorialspoint.com/assembly_programming/assembly_logical_instructions.htm

    global threexplusone
    section .text
    
threexplusone:
    ; x value stored in rdi
    ; n value stored in rsi
    ; counter is r10
    push    r10
    xor     r10, r10        ; refreshes r10 to 0
    mov     rax, 1          ; stores 1 in rax for modular division, check if the lsb is 1
start:
    cmp     rdi, 1
    je      end             ; if rdi = 1(x = 1), returns 0
    and     rax, rdi        ; rax % rdi
    cmp     rax, 1
    je      odd             ; if the lsb is 1, jump to odd
    jmp     even            ; else jump to even
even:
    inc     r10             ; r10++
    sar     rdi, 1          ; rdi/=2
    call    threexplusone
    add     r10, rax        ; rax holds return value from the call, adds to count
    jmp     start           ; restarts recursive call
odd:
    inc     r10             ; r10++
    imul    rdi, 3          ; x *= 3
    inc     rdi             ; x++
    call    threexplusone
    add     r10, rax        ; rax holds return value from the call, adds to count
    jmp     start           ; restarts recursive call
end:
    mov     rax, r10
    pop     r10
    ret
                            ;pop any leftover values on the stack?
