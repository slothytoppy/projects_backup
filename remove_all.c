#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

typedef char* string;

long fsize(string path){
  struct stat finfo;
  stat(path, &finfo);
  return finfo.st_size;
}

string fext(char* filename) {
    char* dot = strrchr(filename, '.');
    int sz=strlen(filename)-strlen(dot);
    char* ext=malloc(sz);
    memcpy(ext, filename, sz);
    return ext;
}

string rm(string path){
  long sz=fsize("end.c");
  if(errno>0){
  fprintf(stderr, "file error:%d\n", errno);
  return "";
  }
  printf("%ld\n", sz);
  return path;
}

string remove_all(string path){
  printf("%s\n", path);
  return path;
}

int main(){
  printf("%s\n", fext("gend.c"));
  string path="hello";
  rm("r.c");
  remove_all(path);
}
