#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>



#define BUFSIZE 1024

int main(void)
{
    char *ronly_str = "I am in read only memory section";
    char strarray[] = "I live in data section of the memeory";


    pid_t parent_pid = getppid();
    pid_t my_pid = getpid();

    printf("My parent Process ID is : %d\n", parent_pid);
    printf("My PID is %d: \n", my_pid);


    return 0;
}