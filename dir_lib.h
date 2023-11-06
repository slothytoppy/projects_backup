#ifndef DIR_LIB_H
#define DIR_LIB_H
#endif // DIR_LIB_H
// #include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>
// #include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
char *basename (const char *__filename) __THROW __nonnull ((1));
extern int atexit(void (*__func) (void)) __THROW __nonnull ((1));
#define success_color    printf("\033[32;2;1m")
#define failure_color    printf("\033[31;2;1m \033[0m")
#define ERROR_NOENT      2
#define ERROR_EXISTS     17
#define ERROR_DIRTOOLONG 36
#define ERROR_ACCESS     13
#define ERRNO_RESET      0
#define array_size(y)    printf("%d\n",sizeof(y)/sizeof(y[0]))
    int count_dir=0;
    int count_reg=0;
    int count_executables=0;
    int count_links=0;
    int total_files=0;
    int total_in_directory=0;
    const char* DIR_COLOR="\033[35;1;1m";
    const char* EXECUTABLE_FILE="\033[32;1;1m";
    const char* FILE_COLOR="\033[0m";
    const char* SYMLINK_COLOR="\033[34;1;1m";
    const char* CLEAR_COLOR="\033[0m";
    const char* DELETED_DIR="\033[30;21;1m";
    const char* SUCCESS="\033[32;2;1m";
#define	_FAILURE	1	/* Failing exit status.  */
#define	_SUCCESS	0	/* Successful exit status.  */
#ifndef DIR_LIB_IMPLEMENTATION
    void exec(char* program, char* argv);
    void symlink_create(char *name, char *sym_name);
    void list_dir(int toggle);
    void symlink_destroy(char *name);
    void make_file(char *name);
    void remove_dir(char *name);
    void make_dir(char *name);
#endif // no dir_lib_implementation

#ifdef DIR_LIB_IMPLEMENTATION
// [todo] try to keep error helper functions and macros towards the top of this ifdef for easier readability
extern char *realpath(const char *__restrict __name,
		       char *__restrict __resolved) __THROW __wur; 
               // hopefully makes it so i dont have to include <stdlib.h>

void eprintln(const char* format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, format, args);
    va_end(args);
    fprintf(stderr, "\n");
}

void exec(char* program){
    struct stat st;
    char buf[255];
    char *cwd=getcwd(buf,255);
    DIR *DIR;
    struct dirent *direct;
    while((direct=readdir(DIR))!=NULL){
            if(strcmp(direct->d_name,".")!=0 && strcmp(direct->d_name,"..")!=0){
            if(access(direct->d_name, X_OK)==0 && direct->d_type!=DT_DIR ){
            printf("%s", getenv(buf)); 
            count_executables++;
            }
        }
    }
        closedir(DIR);
}

void symlink_create(char *name, char *sym_name){
    // symlink can make a symlink using ABS but the created symlink doesnt "exist"
    char sym_cwd[4096];
    char sym_fp[1024];
    getcwd(sym_cwd, sizeof(sym_cwd));
    strcat(sym_cwd, "/");
    strcat(sym_cwd, name);
    snprintf(sym_fp, sizeof(sym_fp), "%s", sym_name);
    printf("name:%s\n", sym_fp);
    printf("%s && %s\n", sym_cwd, sym_fp);
    // strcat(sym_fp, sym_cwd);
    if(symlink(sym_cwd, sym_fp)==0){
    printf("SUCCESS\n");
    } 
    else if(errno>0){
        // printf("errno:%d\n", errno);
        perror("symlink");
    }
}

void list_dir(char* path,int toggle){
    // marker to do delim seperated parsing to check if there is a path given or not 
    struct stat st;
    char buf[255];
    char *cwd=getcwd(buf,255);
    // printf("%s\n", cwd);
    DIR *DIR;
    struct dirent *direct;
    DIR=opendir(cwd);
    if(DIR){
        while((direct=readdir(DIR))!=NULL){
            if(strcmp(direct->d_name,".")!=0 && strcmp(direct->d_name,"..")!=0){
            if(direct->d_type==DT_DIR){
            DIR_COLOR;
                if(toggle==0){
            printf("%s\033[0m\n", direct->d_name);
                }
            count_dir++;
            }
            if(direct->d_type==DT_REG && access(direct->d_name, X_OK)!=0 && direct->d_type!=DT_LNK){
            #define _FILE_COLOR printf("\033[0m")
            _FILE_COLOR;
                if(toggle==0){
            printf("%s\033[0m\n", direct->d_name);
                }
            count_reg++;
            }
            if(direct->d_type==DT_LNK){
            #define _SYMLINK_COLOR printf("\033[34;1;1m")
            _SYMLINK_COLOR;
                if(toggle==0){
            printf("%s\033[0m\n", direct->d_name);
                }
            count_links++;
            }
            if(access(direct->d_name, X_OK)==0 && direct->d_type!=DT_DIR ){
            #define _EXECUTABLE_FILE printf("\033[32;1;1m")
            _EXECUTABLE_FILE;
                if(toggle==0){
            printf("%s\033[0m\n", direct->d_name);
                }
            count_executables++;
            }
        }
    }
        closedir(DIR);
            if(toggle==1){
                printf("%sTOTAL FILES:%d %s\n",FILE_COLOR, count_reg+count_executables+count_links, CLEAR_COLOR);
                if(count_dir>0){
                total_in_directory=count_reg+count_executables+count_links+count_dir;
                printf("%sAMOUNT OF DIRECTORIES:%d %s\n",DIR_COLOR, count_dir, CLEAR_COLOR);
                }
                printf("%sAMOUNT OF LINKS:%d %s\n", SYMLINK_COLOR, count_links, CLEAR_COLOR);
                printf("%sAMOUNT OF EXECUTABLE FILES:%d %s\n",EXECUTABLE_FILE, count_executables, CLEAR_COLOR);
            }
    }
}
void _dir_close(void){
    fprintf(stderr, "DIRECTORY did not close\n");
}
int symlink_destroy(char *name){ 
    struct stat buf;
    lstat(name, &buf);
    DIR *DIR;
    struct dirent *direct;
    char directory[1024];
    char *lastSlash = strrchr(name, '/');
    size_t length = lastSlash - name;
    if(lastSlash != NULL) {
        directory[length + 1];
        strncpy(directory, name, length);
        directory[length] = '\0';
        // printf("DIRECTORY:%s\n", directory);
    }
    if(lastSlash!=NULL){
    strcat(directory, "/");
    // printf("DIR:%s\n", directory);
    chdir(directory);
    } else{
        // printf("lastSlash:%s\n", name);
        strcat(directory, ".");
      }
    // printf("basename:%s\n", lastSlash);
DIR=opendir(directory);
    while((direct=readdir(DIR))!=NULL){
        if(direct->d_type==DT_LNK){
            if(S_ISLNK(buf.st_mode)){
            printf("LINK:%s\n", direct->d_name);
                if(unlink(name)==0){
            printf("{%s} was successfully deleted\n", name);
            return 0;
                } else if(unlink(lastSlash)!=0){
        printf("ERROR:%s && file name:{%s}\n", strerror(errno), name);
        return 1;
                  }
            }
        } if(direct->d_type==DT_REG){
            if(S_ISREG(buf.st_mode)){
        printf("supplied file to \"sym\" was not a symlink\n");
        return 1;
            }
          }
    } if((direct=readdir(DIR))!=NULL){
        atexit(_dir_close);
    }
    if(errno==ERROR_NOENT){
        printf("link:{%s} isnt in directory:{%s}\n", name, directory);
        closedir(DIR);
        return 1;
    }
    closedir(DIR);
    return 1;
}
void make_file(char *name){
    FILE *fd;
    DIR *DIR;
    struct dirent *dirent;
    char buff[255];
    getcwd(buff, 255);
    DIR=opendir(buff);
while((dirent=readdir(DIR))!=NULL){
    if(strcmp(dirent->d_name, name)==0){
        printf("file {%s} exists\n", name);
        return;
    }
    }  
    if(dirent==NULL){
    fd=fopen(name, "a+");
        if(fd!=NULL){
        fprintf(stdout, "file {%s} was created\n", name);
        } 
        else{
        fprintf(stderr,"error opening:{%s}\n", name);
        return;
        }
}
    fclose(fd);
    closedir(DIR);
    return;
}
void remove_dir(char *name){
    if(rmdir(name)==0){
    printf("REMOVED:%s\n", name);
    }
    if(errno==ERROR_NOENT){
        printf("DIRECTORY DOESNT EXIST:%s\n", name);
    }
}

void make_dir(char *name){
    // char *dir_name=strcat(path, name);
    if(mkdir(name, 0755)==0){
    printf("%ssuccessfully created:%s\n", SUCCESS, name);
    } else if(errno==ERROR_EXISTS){
        perror(name);
        printf("\033[31;1;1mERROR DIR:%s already exists\033[0m\n", name); 
    }
    else if(errno==ERROR_NOENT){
        perror(name);
        printf("ERROR DIR:%s no such file or directory\n", name);
    }
    else if(errno==ERROR_DIRTOOLONG){
        perror(name);
        printf("\033[31;1;1mERROR DIR:%s name too long [MAX_FILE_NAME is usually 255 characters for linux]\033[0m\n", name);
    }
    else if(errno==ERROR_ACCESS){
        perror(name);
        printf("ERROR DIR: insufficient permissions to create dir %s\n", name);
    }
}

#endif // DIR_LIB_IMPLEMENTATION
// void dir_types(void){
//     PRINT_S("DT_UNKNOWN=0, DT_FIFO=1, DT_CHR=2, DT_DIR=4, DT_BLK=6, DT_REG=8, DT_LNK=10, DT_SOCK=12, DT_WHT=14");
// }
// char *trunc(char* string) {
//     char* lastDot = strrchr(string, '.');
//     if (lastDot != NULL) {
//         *lastDot = '\0';
//     }
// }
