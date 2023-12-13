package main
import(
	"os"
  "fmt"
	"path"
	"strings"
)
// [TODO]: gets directory path; checks if file(s)/source file(s) in path exist, then you get the basename(file without extension), then remove the file(s) if it exists; 
// then you would either import this file or run it on a config.go file; end goal is to have this be scriptable, may end up being just function calls

func check(e error) {
    if e != nil {
        panic(e)
    }
}

func stat(file *os.File) (int64){
	fi, err:=file.Stat(); if err!=nil{
	fmt.Println(err)
	os.Exit(1)
	}
	return fi.Size()
}

func f_exist(file string) bool{
	if _, err:=os.Stat(file); err!=nil{
		return false
	}
	return true
}

func f_ext(file string) string{
	return strings.TrimSuffix(file, path.Ext(file))
}

func f_list(list ...string){
	for _, list:=range list{
		if f_exist(list){
			if(f_exist(f_ext(list))){
			fmt.Printf("{%s}\n", list)
			fmt.Printf("deleted:{%s}\n", f_ext(list))
			os.Remove(f_ext(list))
			} else{
				fmt.Printf("file {%s} doesnt exist\n", f_ext(list))
			}
		}
  }
}

func args() int{  
  return len(os.Args)
}

func dir_remove(dir string){
  err:=os.RemoveAll(dir); if err!=nil{
    fmt.Printf("error removing %s", dir)
  }
}

func create(file string){
  os.Open(file)
}

func main(){
	args_c:=len(os.Args)
	if args()==2 && os.Args[1]=="term"{
		fmt.Println("usage: term \"args...\"")
	}
	if args()>=2 && os.Args[1]=="term"{
	var max=len(os.Args)
	var i int=2
	if(i<=max){
		for args_c>i{
		f_list(os.Args[i])
		i++
	  }
	}
} 
  if args()>=2 && os.Args[1]!="term"{
	f_exist("tes.c")
  f_list("tes.c", "gend.c", "perms.go")
	}
  if args()==1{
	fmt.Printf("usage: command args...\n")
	os.Exit(1)
  }
  if args()>=2 && os.Args[1]=="rdir"{
  dir_remove(os.Args[2])
}
}
