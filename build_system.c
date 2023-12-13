#include <stdio.h>
#include <string.h>
#include <unistd.h>

char* fext(char* path){
  if(access(path, F_OK)!=-1){
    for(int i=0; path[i]!='\0'; i++){
      if(path[i]=='.'){
        path[i]='\0';
      printf("{%s}\n", path);
      }  
    }
  }
  return "";
}

int main(int args, char *argv[]){
  printf("%s %d\n", __FILE__, __LINE__);
  fext(argv[1]);
}
