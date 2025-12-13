#define GNU source
#include <stdio.h>
#include <stdarg.h>
#include <dlfcn.h>

int printf(const char *format, ...){

int done;
const char *test = "test";
        va_list arg;
        va_start(arg, test);	

 done = vfprintf(stdout,test , arg);
 
 va_end (arg);

return done;
}
