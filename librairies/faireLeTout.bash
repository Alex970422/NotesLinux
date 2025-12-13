
#!/bin/bash

ComplieLibraryExample(){
gcc -c MyLib.c -o MyLib.o 
ar rcs libPointA.a My lib.o 
gcc -c Mylib.c -L. -lPointA -o main
}
