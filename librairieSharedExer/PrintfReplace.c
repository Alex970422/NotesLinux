#define GNU source
#include <stdio.h>
#include <stdarg.h>
#include <dlfcn.h>

int printf(const char *format, ...){
static int (*real_printf)(const char * ,...) = NULL;

if(!real_printf)
realprintf = =dlsym(RTLD_NEXT,"printf");

int done;
        va_list arg;
        va_start(arg, format);	

real_printf("HOOKED :\n")

 done = vprintf(format , arg);

 
 va_end (arg);

return done;
}
