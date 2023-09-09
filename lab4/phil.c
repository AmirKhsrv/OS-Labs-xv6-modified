#include "types.h"
#include "user.h"
#include "stat.h"

#define THINKING 2
#define HUNGRY 1
#define EATING 0

int philosofer_num;


int main(int argc, char **argv)
{
    philosofer_num = atoi(argv[1]);
    int odd = (philosofer_num % 3) % 2;

    while (1) {
        int i = philosofer_num;

        printf(1, "Philosopher %d State: THINK\n", philosofer_num);
        sleep(100);
        printf(1, "Philosopher %d State: HUNGRY\n", philosofer_num);
        
        if (odd) {
            sem_acquire(i);
            sem_acquire((i+4) % 5);
        }
        else {
            sem_acquire((i+4) % 5);
            sem_acquire(i);
        }
        
        printf(1, "Philosopher %d State: EAT\n", philosofer_num);
        sleep(100);
        printf(1, "Philosopher %d State: FINISH\n", philosofer_num);

        sem_release(i);
        sem_release((i+4) % 5);
    }
}
 