#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "converter.h"
//#define UT

#ifdef UT
#define STATIC 
#else
#define STATIC static
#endif //UT

int8_t s2x(const char *str, char *result)
{
    //check for empty string
    int len = strlen(str);
    if (len <= 0)
    {
        sprintf(result, "No params entered"); // \n
        return 1;
    }

    //check for sign symbol
    if ((str[0]=='-') || (str[0]=='+'))
    {
        //result = "Error: First symbol not a sign of digit\n";
        sprintf(result, "Can't convert string to number");
        return 2;
    }

    //check for digit symbols
    for (int i = 0; i < len; i++)
    {   
        if (0 == isdigit(str[i]))
            {
                //result = "Error: Entered string not a number\n";
                sprintf(result, "Not a decimal number");
                return 3;
            }
    }
       
    //convert
    //todo: check for data size: int, long
    int number = atoi(str);
    sprintf(result, "0x%X", number);
    
    //for validate
    long tnumb = strtol(result, NULL, 16);
    char *int_result = malloc(ARRAY_SIZE);
    sprintf(int_result, "%ld", tnumb);

    //validate
    int cmpresult = strcmp(str, int_result);
    free(int_result);
    
    if (0 == cmpresult)
    {
        return 0;
    }
    else
    {
        sprintf(result, "Number should be between: 0..2147483647\n");
        return 4;        
    }
}

/* 
STATIC int32_t x2i(const char* hex)
{
    //char hex[ARRAY_SIZE];
    int decimal = 0;  // long long decimal = 0
    int base = 1;
    //int i = 0;
    //int length = 0;
    
    printf("\ntake: %s\n", hex); //debug

    int length = strlen(hex);
    printf("lenght: %i\n", length); //debug
    
    for(int i = length--; i >= 0; i--)
    {
        if(hex[i] >= '0' && hex[i] <= '9')
        {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        }
        else if(hex[i] >= 'A' && hex[i] <= 'F')
        {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
        else if(hex[i] >= 'a' && hex[i] <= 'f')
        {
            decimal += (hex[i] - 87) * base;
            base *= 16;
        }
    }
    printf("return: %i\n", decimal); //debug
    return decimal;
} */