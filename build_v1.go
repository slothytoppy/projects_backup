package main

import (
	"fmt"
	"os"
    // "log"
    "os/exec"
    "io"
)

func check(e error) {
    if e != nil {
        panic(e)
    }
}

func no_config_file(){
    f_config:="/home/slothy/custom_programs/ctools/build_config_v1"
    check_dir:="/usr/bin/"
    if _, err :=os.Open(f_config); err != nil {
        file, err:=os.Create(f_config);
        check(err)
        file.WriteString(check_dir);
        var uinput string
        fmt.Print("enter in your compiler:");
        _, _=fmt.Scanf("%s", &uinput)
        // check(err)
        file.WriteString(uinput);
        os.Exit(0);
        } 
        args_c:=len(os.Args[1:])
        if(args_c<2){
            fmt.Fprintf(os.Stderr, "%s\n", "not enough args, required args count is two");
            os.Exit(1);
        }
}

func is_run_normally(){
    f_config:="/home/slothy/custom_programs/ctools/build_config_v1"
    no_config_file();
    dat, err := os.ReadFile(f_config);
    check(err);
    string_dat:=string(dat);
    fmt.Println(string_dat)
    exec.Command(string_dat, os.Args[1], "-o", os.Args[2]).Output();
    if _, err:=os.Stat(os.Args[2]); err!=nil{
        fmt.Printf("file:{%s} was not created\n", os.Args[2]);
        os.Exit(1);
    }    
    if _, err:=os.Open(os.Args[2]); err!=nil{
        fmt.Fprintf(os.Stderr, "couldnt open:{%s}\n", os.Args[2]);
        os.Exit(1);
    } else{
        fmt.Println(os.Args[2], "was compiled");
    }
}

func write_config(config string){
    // [todo] only if my config is multi line, add the ability to remove certain lines in config
    f_config:="build_config_v1"
    check_dir:="/usr/bin/"
    finfo, _:=os.Stat("/home/slothy/custom_programs/ctools/build_config_v1")
    file, _:=os.OpenFile(f_config, os.O_WRONLY, 0644);
    if(finfo.Size()>0){
    os.OpenFile(f_config, os.O_WRONLY | os.O_TRUNC, 0644)
    }
    file.Write([]byte(check_dir))
    file.Write([]byte(config))
    file, _=os.OpenFile(f_config, os.O_RDONLY, 0644)
    data, _:=io.ReadAll(file)
    fmt.Println(string(data))
}

func main(){
    count:=len(os.Args)-1
    if(os.Args[1]==""){
        // config();
    } 
    if(count>0){
        for i:=1; i<=count; i++ {
        fmt.Println(os.Args[i])
        }
    }
    if(os.Args[1]!="" && count>0){
        if(os.Args[1]=="-a"){
        fmt.Println(count)
    write_config(os.Args[2]);
        }
    }
    // is_run_normally();
}
