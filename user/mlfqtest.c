//A Simple C program 
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/syscall.h"
    
#define N 5

void
mlfqtest(void){
    int n, pid, i;

    printf("mlfq test\n");

    for(n=0; n<N; n++){
        printmlfq();
        pid = fork();
        if(pid < 0)
            break;
        if(pid == 0){
            i=0; 
            while(i<50000) {
                i++;
                sleep(10);
            }
            exit(0);
        }
    }
}

int main(int argc, char *argv[]) { 
    mlfqtest();
    exit(0); 
} 