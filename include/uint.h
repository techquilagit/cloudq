#pragma once
typedef unsigned char Uint8;
typedef unsigned short Uint16;
typedef unsigned int Uint32;
typedef unsigned long long Uint64;
typedef signed char Int8;
typedef signed short Int16;
typedef signed int Int32;
typedef signed long long Int64;
#if defined(__x86_64__) || defined(_WIN64) || defined(__LP64__)
typedef char* Universal;
typedef unsigned long Size;
typedef unsigned long long Uintn;
typedef signed long long Intn;
#else
typedef char* Universal;
typedef unsigned int Size;
typedef unsigned int Uintn;
typedef signed int Intn;
#endif