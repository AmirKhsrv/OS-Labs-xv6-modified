#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf(2, "Usage: set process parent. One pid needed.\n");
        exit();
    }
    int pid = atoi(argv[1]);

    asm ("movl %0, %%ebx"
        :
        : "r"(pid)
        :  "%ebx"
    );
    get_parent_pid();
    set_process_parent();
    exit();
}