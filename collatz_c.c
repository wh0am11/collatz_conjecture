/*
#####################
#
# Author: wh0am1
# Description: Tries the Collatz Conjecture given an integer
#
#
#####################
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BIG_INT sizeof(unsigned long)*10000

void collatz_c(unsigned long n);

int main(int argc,char* argv[]) {

if (argc == 2) {

char* n_str = malloc(10000);
unsigned long* n = malloc(BIG_INT);

if (n_str == NULL || n == NULL) {

perror("Error");
if (n_str != NULL) free(n_str);
if (n != NULL) free(n);
return -1;

}

strncpy(n_str,argv[1],10000);

*n = strtol(n_str,NULL,10);

free(n_str);

if (*n == 0) {

printf("Error: Number must be greater than or equal to 1\n");
free(n);
return -1;

}

printf("Starting...\n");

collatz_c(*n);

free(n);

}
else fprintf(stderr,"Error: Exactly one argument required (Usage: ./collatz_c [number])\n");

return 0;

}


void collatz_c(unsigned long n) {

/* Execute the Collatz Conjecture */


while (1) {

if (n % 2 == 0) n /= 2;
else n = 3*n + 1;

printf("%ld\n",n);

if (n == 1) break;


}

printf("Cycle concluded\n");

}
