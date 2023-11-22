#include <stdio.h>
// #include <stdlib.h>
// #include <fcntl.h>
#include <unistd.h>
#include <string.h>
#ifdef stdlib.h
#undef exit
#endif
#define exit(code) _exit(code);
#define print(x) printf("%s", x)
int main(int argc, char* argv[]){
    if(argv[1]==NULL || argv[2]==NULL){
        printf("not enough args\n");
        exit(1);
    }
    FILE *fd=fopen("config", "r");
      if(fd!=NULL && strcmp(argv[1], "-b")==0){
        char buff[255];
        fscanf(fd, "%s", buff);
        char* args[]={buff, argv[2], "-o", argv[3], NULL};
        printf("arg:{%s} arg1:{%s}\n", argv[2], argv[3]);
        printf("buff:{%s}\n", args[0]);
        fork();
        execv(args[0], args);
    }
    if(fd==NULL){
    fd=fopen("config", "w+");
        char buff[255];
        printf("enter in a compiler:");
        fscanf(stdin, "%s", buff);
        fprintf(fd, "%s", "/usr/bin/");
        fprintf(fd, "%s", buff, sizeof(buff));
    fclose(fd);
    }
}