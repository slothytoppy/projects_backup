#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#include <fcntl.h>
#include <sys/stat.h>

typedef char* string;

string fext(string path){
    char *retStr;
    char *lastExt;
    if (path== NULL) return NULL;
    if ((retStr = malloc (strlen (path) + 1)) == NULL) return NULL;
    strcpy (retStr, path);
    lastExt = strrchr (retStr, '.');
    if (lastExt != NULL)
        *lastExt = '\0';
    return retStr;
}

int main(){
struct stat finfo;
char* files[]={"test", "test.c", "test.rs", "dir"};
int elem=sizeof(files)/sizeof(files[0]);
int i;
  for(i=0; i<elem; i++){
  lstat(files[i], &finfo);
  char* file=files[i];
  printf("%s\n", fext(file));
  if(S_ISLNK(finfo.st_mode)){
  printf("%s is link\n", file);
    }
    if(S_ISREG(finfo.st_mode)){
  printf("%s is regular\n", file);
    } 
    if(S_ISDIR(finfo.st_mode)){
  printf("%s is a directory\n", file);
    }
  }
  return 0;
}
