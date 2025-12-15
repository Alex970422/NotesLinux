#include <stdio.h>
#include <string.h>

/* simple demo of a string type vuln
 * calling printf  with a controlled entry allows to read the stack
*/

void stack_leak(const char *user_input){
	printf("Dump: ");
	printf(user_input); /* vuln : no format imposed */
        printf("\n");
}

int main(void){
	char buffer[64];
	
	puts("input type : (ex %x %x %x):");
	if (fgets(buffer, sizeof(buffer) , stdin) == NULL) {
		return 1; }

	buffer[strcspn(buffer, "\n")] = '\0';
	stack_leak(buffer);
	return 0;
		
	
}
 

