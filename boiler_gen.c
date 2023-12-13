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
    int fd;
    fd=open("gend.c", O_RDWR | O_CREAT, 0644);
    // write(1, "printf(\"hello world\"\n)", 23);
    write(fd, "#include <stdio.h>\n", 19);
    write(fd, "#include <fcntl.h>\n", 19);
    write(fd, "#include <string.h>\n", 20);
    write(fd, "#include <unistd.h>\n", 20);
    write(fd, "#include <dirent.h>\n\n", 20);
    write(fd, "\nint main(int argc, char* argv[]){\n", 35);
    write(fd, "printf(\"hello world\\n\");\n}", 26);
    struct stat ft;
    stat("gend.c", &ft);
    int size = ft.st_size;
    char buf[sizeof(ft.st_size)];
    sprintf(buf,"%d", size);
    write(1, buf, strlen(buf));
    write(1, "\n", 1);
    // write(1, buf, sizeof(buff));
}