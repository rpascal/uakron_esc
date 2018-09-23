#include <stdio.h>

void shortInt()
{
    unsigned short int a = 5;
    unsigned short int b = 6;
    unsigned short int result = a - b;
    printf("unsigned short int result: %u\n", result);
}

void Int()
{
    unsigned int a = 5;
    unsigned int b = 6;
    unsigned int result = a - b;
    printf("unsigned int result: %u\n", result);
}

void longInt()
{
    unsigned long a = 5;
    unsigned long b = 6;
    unsigned long result = a - b;
    printf("unsigned long result: %lu\n", result);
}

void main()
{
    shortInt();
    Int();
    longInt();
}