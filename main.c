#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
//#include <stddef.h> //wchar_t for Assia chars
//#include <limits.h> //min-max val of std types: LONG_MAX +2147463647, LONG_MIN -2147483647
//#include <ctype.h>
#include <signal.h>
//#include <math.h>

#include "converter.h"


void sig_handler(int signum)
{
    printf("Incorrect work of programm\n");
}


int main (int argc, char *argv[])
{
    #ifdef UT
        printf("-= UT mode =-\n");
    #endif

   if (argc <= 1)
    {
        printf("Application was run without any params. Use --help\n");
        return 0;
    }
        
    printf("%s => ", argv[1]);

    signal(SIGSEGV, sig_handler); // register signal handler

    char *hex_result = malloc(ARRAY_SIZE);
    s2x(argv[1], hex_result);

#ifdef WINDOWS_VERSION
    printf("%s", hex_result);
#else
    printf("%s \n", hex_result);
#endif

 free(hex_result);
    
    return 0;
}

