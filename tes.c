#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int exec(char* args[]){
    printf("args:%s\n", *args);
    pid_t id=fork();
    int child_status;
    if(id==0){
    execv(args[0], args);
    waitpid(id, NULL, 0);
    } 
    if(id<0){
        printf("forking failed");
    }
}

int main(int argc, char* argv[]){
char* arg[]={"/usr/bin/tcc", "test.c", "-o", "test"};
char* args[]={argv[1], NULL};
exec(arg);
exec(args);
printf("%s\n", *args);
}