//A Simple C program 
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
    
#define N 50

void
forktest(void){
    int n, pid;

    printf("fork test\n");

    for(n=0; n<N; n++){
    // print("Forking...");
    pid = fork();
    if(pid < 0)
        break;
    if(pid == 0)
        exit(0);
    }

   sleep(1000);

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
}

int main(int argc, char *argv[]) { 
    printf("My first xv6 program learnt at GFG\n"); 
    forktest();
    exit(0); 
} 