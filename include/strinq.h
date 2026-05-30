#ifndef STRING_H
#define STRING_H
#include <uint.h>
typedef struct {
    char* data;
    Size size;
} __attribute__((packed)) String;
#endif // STRING_H