; binarySearch.s
; Morgan Kinne
; 2150 Post-Lab 9
; 11/17/21

    global binarySearch

    section .text

    ; parameter 1: rdi, int pointer in array
    ; parameter 2: rsi, int representing front of array (low)
    ; parameter 3: rdx, int representing end of array (high)
    ; parameter 4: rcx, int to be found in array
    ; register: rax
    ; counter (mid value): r10
    xor     r10, r10        ; r10 = 0
binarySearch:
    cmp     rsi, rdx        ; low, high
    jle     start           ; if low<= high, jump to start of array
    jg      notFound        ; if low > high, return -1, value not found
start:
    mov     r10, rsi        ; mid += low
    add     r10, rdx        ; mid += high
    shr     r10, 1          ; mid /= 2 (r10 = (high + low)/2)
    mov     eax, [rdi+4*r10]; set rax = memory address of r10 index in array
    cmp     eax, ecx        ; cmp array val at index of mid with key
    je      found           ; jump to found if equal
    jl      less            ; jl to less if a[mid] < key
    jg      great           ; jg to great if a[mid] > key
less:
    mov     rsi, r10        ; low = mid + 1
    inc     rsi             ; low++ (low = mid + 1)
    jmp     binarySearch    ; or should I call binary search?
great:
    mov     rdx, r10        ; high = mid
    dec     rdx             ; high-- (high = mid-1)
    jmp     binarySearch    ; or should I call binary search?
found:
    mov     rax, r10
    ret
notFound:
    mov     rax, -1
    ret
