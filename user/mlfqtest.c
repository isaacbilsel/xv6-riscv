//A Simple C program 
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/syscall.h"
    
#define N 10

void
forktest(void){
    int n, pid, i;

    printf("fork test\n");

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

    /*
    for(; n > 0; n--){
        // print("waiting... ");
        if(wait(0) < 0){
            printf("wait stopped early\n");
            exit(1);
        }
    }

    if(wait(0) != -1){
    printf("wait got too many\n");
    exit(1);
    }
    printf("fork test OK\n");
    */
}

int main(int argc, char *argv[]) { 
    forktest();
    exit(0); 
} 