#ifndef CONVERTER_H_
#define CONVERTER_H_

#include <ctype.h>

//#define STATIC static
#define ARRAY_SIZE  45

//int32_t data;
//static int32_t static_data;

/// @brief Numbers string to hexadecimal string converter
/// @param str - pointer to string with numbers 
/// @param result - pointer to string with hexadecimal numbers
/// @return 0 - ok, if > 0 - error
int8_t s2x(const char *str, char *result);

//static int32_t x2i(const char* hex);

#endif
