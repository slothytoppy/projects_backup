#define DIR_LIB_IMPLEMENTATION
#include "dir_lib_copy.h"
int main(int argc, char **argv){
    if(argv[1]==NULL){
        printf("no arguments supplied\n");
        return 1;
    }
    if(strcmp(argv[1], "sym")==0){
        if(argv[2]==NULL){
            fprintf(stderr, "not enough arguments given to:sym\n");
            return 1;
        }
        if(argv[2]!=NULL){
            if(strcmp(argv[2], "-r")==0){
                symlink_destroy(argv[3]);
                }
            if(argv[3]!=NULL){
                if(strcmp(argv[3], "-s")==0){
                    if(argv[4]!=NULL){
                symlink_create(argv[2], argv[4]);
                    }
                }
            }
        }
    }   
        if(strcmp(argv[1], "mkf")==0){
            if(argv[2]==NULL){
                fprintf(stderr,"not enough arguments for:mkf\n");
                return 1;
            }
            if(argv[2]!=NULL){
                make_file(argv[2]);
            }
        }
        if(strcmp(argv[1], "mkdir")==0){
            if(argv[2]!=NULL){
            make_dir(argv[2]);
            } else if(argv[2]==NULL){
            fprintf(stderr,"not enough arguments for:mkdir\n");
              }
        }
        if(strcmp(argv[1], "exec")==0){
            if(argv[2]==NULL){
                fprintf(stderr,"you must provide two arguments to exec\n");
                return 1;
            }
            if(argv[2]!=NULL){
                // char *args[]==argv[3];
                exec(argv[2]);
            }
        }
        if(argv[2]==NULL && strcmp(argv[1], "dir")==0){ 
        list_dir(".",0);  // does NOT run from /home
        }
    if(strcmp(argv[1], "dir")==0){
      if(argv[2]!=NULL && strcmp(argv[1], "dir")==0){
        if(strcmp(argv[2], "-i")==0){
            list_dir(".",1);
        } 
        if(strcmp(argv[2], "-r")==0){
            remove_dir(argv[3]);
        }
      }
    }
    return 0;
}
