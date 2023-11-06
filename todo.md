                                PROJECT=dir_test.c
[TODO] make alphabetical sorting for files for ux friendly file selection,
i want to be able to list files and have the user choose which one to open, by default it would open in a+ mode
[TODO] make exec use an exec family function using program and argv or at least make file execution work
[TODO] make dir_test.c work with windows
[TODO] make every function able to take path as an argument and if a certain argument isnt path it would use cwd as default
[TODO] use /usr/local/bin for new projects and eventually this one
[TODO] make symlinks relative and not absolute
[TODO] make path work on list_dir
[!done] make sym -r work with directories by parsing until the last / to get the directory before the last / then using the string after the last / for deleting the sym link
[TODO] write a string manipulation library in c
[TODO] make it so that files created using symlink make a symlink with the same extension as the src file
[TODO] try to make a scripting language in c with PATHS (just a directory/directories that the program looks in to compare input to file name and if those are the same it runs the file)
[TODO] try to make dir_lib.h and dir_test.c in another language, probably python?
[TODO] use atexit() // atexit takes a function, use atexit for DEFER // defer is a function that is run on exit but only if exit() is done
or use atexit() for error messages by having functions that display error messages for a FILE, DIRECTORY, SYMLINK, etc
[TODO] write a program that you would call on a file that uses my scripting language, it would need something like a bash path but would instead be more like a scripting directory?, you could have a script that calls into that directory and tries to execute a script, so it would be kind of like bash, with bash you can make a custom PATH, put scripts in that directory and then go into your .bashrc and go hey if i type this string in i want you to look into all paths and look for this file and if you find it i want you to run it. what bash does is, it looks at all of your paths, then compares the input to a file name and if those two are the same, it will execute the file, i want this for my scripting language but all the scripts would be in one directory(maybe more) and it would also support recursion so you could just do path/to/parent/directory then make a subdirectory and it would still run files in the subdirectory even without you having to make another path to that new directory.
[TODO] write a server in c that can run my programs using commands, so what you would do is ./server_run or server_run then type input and the server would try to interpret
the input to run certain commands like bash commands or custom programs if you can give it the full path to the file or maybe I could even make a directory that it would search in and compare input to file names to attempt to run files.
[TODO] learn signals to write my own exit() functions
[TODO] make my own print to FILE *stream function for logging, you would do something like my_print(file, string); it would check for double or single quotes it probably wouldnt handle integers as numbers so you would do my_print(file, "1"); which is okay? there is strtol