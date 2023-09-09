#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
    printf(1, "Pid before sleep: %d\n", getpid());
    printf(1, "Parent pid before sleep: %d\n", get_parent_pid());
    sleep(2000);
    printf(1, "Pid after sleep: %d\n", getpid());
    printf(1, "Parent pid after sleep: %d\n", get_parent_pid());
    exit();
}