#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

#include <sys/wait.h>

#ifdef stdlib_h
#undef exit
#endif
#define exit(code) _exit(code);
#define print(x) printf("%s", x)

char* fext(char* filename) {
    char* dot = strrchr(filename, '.');
    int sz=strlen(filename)-strlen(dot);
    char* ext=malloc(sz);
    memcpy(ext, filename, sz);
    // ext[filename-dot];
    return ext;
}

int config_open(void){

}

int exec(char* args[]){
    // printf("args:%s\n", *args);
    pid_t id=fork();
    int child_status;
    if(id==0){
    execv(args[0], args);
    } 
    if(id<0){
        printf("forking failed");
    return -1;
    }
    if(id>0){
    wait(&child_status);
    // waitpid(-1, NULL, 0);
    }
    return 0;
}

int main(int argc, char* argv[]){
    // [TODO] make config resetable, make config deletable, make /usr/bin an optional thing so you can add your own path
    if(argc<=1){
        printf("not enough args\n");
        exit(1);
    }
    const char* file_name="build_config_v1";
    FILE *fd=fopen(file_name, "r");
      if(fd!=NULL && argv[1]!=NULL && strcmp(argv[1], "-b")==0){
        char buff[255];
        fscanf(fd, "%s", buff);
        char* args[]={buff, argv[2], "-o", argv[4], NULL};
        char* arg[]={argv[3], NULL};
        if((exec(args))==-1){
            printf("error:");
        }
        if((exec(arg))==-1){
        printf("error:");
        }
    } 
    if(argv[1]!=NULL && strcmp(argv[1], "-c")==0){
        if(argv[2]==NULL){
            fprintf(stderr, "must have 2 arguments\n");
            exit(1);
        }
        char* args[]={argv[2], "-o", argv[3], argv[4], NULL};
        printf("{%s}\n", *args);
        if((exec(args))==-1){
            printf("error");
        }
    }
    if(fd==NULL){
    fd=fopen(file_name, "w+");
        char buff[255];
        printf("enter in a compiler:");
        fscanf(stdin, "%s", buff);
        // fprintf(fd, "%s", "/usr/bin/");
        fprintf(fd, "%s", buff);
    fclose(fd);
    }
}
