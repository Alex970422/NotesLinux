#define GNU source
#include <stdio.h>
#include <dlfcn.h>

int printf(const char* message, ...){
	int (*OGprintf)(const char * , ...);

      	OGprintf = dlsym(RTLD_NEXT, "printf");  
	OGprintf("marche\n")
       	OGprintf("Hooked: %s \n" , message); 
return 0;
}
