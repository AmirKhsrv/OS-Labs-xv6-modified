#include "types.h"
#include "user.h"
#include "stat.h"


 
int main()
{
    for (int i = 0; i < 5; i++){
        sem_init(i, 1);
    }

    for (int i = 0; i < 5; i++) {
        char id[] = {i+'0', '\0'};
        char *args[] = {
            "phil", 
            id, 
            '\0'
        };

        int pid = fork();
        if (pid==0) {
            exec("phil", args);
            exit();
        }
    }
    return 0;
}