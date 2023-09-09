#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    int saved_ebx;

    int pid;
    pid = fork();
    asm volatile(
    "movl %%ebx, %0;"
    "movl %1, %%ebx;" 
    : "=r" (saved_ebx)
    : "r"(pid));
    if (pid != 0)
        get_parent_pid();
    asm("movl %0, %%ebx" : : "r"(saved_ebx)); 
    exit();
}