#include <stdint.h>

static const uintptr_t REBOOT_MAGIC_1 = 318839184;
static const uintptr_t REBOOT_MAGIC_2 = 3402301098;

static const uintptr_t SYS_WRITE = 1;
static const uintptr_t SYS_BRK = 12;
static const uintptr_t SYS_REBOOT = 48;

static inline long syscall_0(long n) {
    register long a0 asm("a0") = n;
    
    asm volatile ("ecall" 
        : "+r"(a0) 
	:
        : "memory");
    
    return a0;
}

static inline long syscall_1(long n, long arg0) {
    register long a0 asm("a0") = n;
    register long a1 asm("a1") = arg0;
    
    asm volatile ("ecall" 
        : "+r"(a0) 
        : "r"(a1) 
        : "memory");
    
    return a0;
}

static inline long syscall_2(long n, long arg0, long arg1) {
    register long a0 asm("a0") = n;
    register long a1 asm("a1") = arg0;
    register long a2 asm("a2") = arg1;
    
    asm volatile ("ecall" 
        : "+r"(a0) 
        : "r"(a1), "r"(a2)
        : "memory");
    
    return a0;
}

static inline long syscall_3(long n, long arg0, long arg1, long arg2) {
    register long a0 asm("a0") = n;
    register long a1 asm("a1") = arg0;
    register long a2 asm("a2") = arg1;
    register long a3 asm("a3") = arg2;

    asm volatile ("ecall"
        : "+r"(a0)
        : "r"(a1), "r"(a2), "r"(a3)
        : "memory");

    return a0;
}
