#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int 
itoa(int value,char *ptr)
{
    int count=0,temp;  
    if(value==0)
    {   
        *ptr='0';
        return 1;
    }

    if(value<0)
    {
        value*=(-1);    
        *ptr++='-';
        count++;
    }
    for(temp=value;temp>0;temp/=10,ptr++);
    *ptr='\0';
    for(temp=value;temp>0;temp/=10)
    {
        *--ptr=temp%10+'0';
        count++;
    }
    return count;
}

void factor(char* number){

    int fd = open("/factor_result.txt", O_RDONLY);
    if(fd > 0){
        unlink("/factor_result.txt");
    }

    fd = open("/factor_result.txt", O_CREATE|O_WRONLY);
    int num = atoi(number);
    for(int i=1; i<= num; i++){
        if(num%i==0){
            char divisor[100];
            int size = itoa(i, divisor);
            write(fd, divisor, size);
            write(fd, " ", 1);
        }
    }
    write(fd, "\n", 1);
    close(fd);
}

int
main(int argc, char *argv[])
{
    if(argc < 2){
        printf(1, "No arguments passed, exitting...\n");
    }
    else{
        for(int i=1; i< argc; i++){
            factor(argv[i]);
        }
    }


    exit();
}