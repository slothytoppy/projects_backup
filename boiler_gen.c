#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#include <sys/stat.h>

int main(int argc, char* argv[]){
    if(argc-1>1){
        write(1 ,"too many arguments\n", 19);
        _exit(1);
    }
    FILE *fd=fopen("gend.c", "w+");
    fprintf(fd, "#include <stdio.h>\n");
    fprintf(fd, "#include <string.h>\n");
    fprintf(fd, "#include <unistd.h>\n");
    fprintf(fd, "#include <dirent.h>\n");
    fprintf(fd, "\n");
    fprintf(fd, "#include <sys/stat.h>\n");
    fprintf(fd, "#include <fcntl.h>\n");
    fprintf(fd, "/* written by boiler_gend.c */\n");
    fprintf(fd, "\nint main(int argc, char* argv[]){\n");
    fprintf(fd, "printf(\"hello world\\n\");\n}");
    fclose(fd); 
    int fp=open("gend.c", O_RDWR, 0644);
    struct stat ft;
    fstat(fp, &ft);
    printf("size:%ld\n", ft.st_size);
    close(fp);
}
