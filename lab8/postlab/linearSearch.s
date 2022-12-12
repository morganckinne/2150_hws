; Morgan Kinne
; 2150 Post-Lab 8
; Nov 2021
; linearSearch.s

    global linearSearch
    
    section .text

; Parameter 1: rdi = arr[]
; Parameter 2: rsi = size
; Parameter 3: rdx = target
; Return type is int

linearSearch:
    ; searches through array at index i, returns index of target if found, otherwise -1
    xor     rax, rax        ; rax = 0
    xor     r10, r10        ; int i = 0
loop1:                      ; search loop
    cmp     r10, rsi        ; if (i < n)
    je      notfound        ;
    mov     eax,[rdi+4*r10] ;
    cmp     eax, edx        ; does this compare array pointer at r10(i) with target?
    je      found           ; jump if (a[i] == target)
    inc     r10             ; i++
    jmp     loop1           ; jump to loop1
notfound:
    mov     rax, -1         ; set rax to -1
    ret
found:
    mov     rax, r10        ; sets rax to r10 (i)
    ret                     ; returns i
