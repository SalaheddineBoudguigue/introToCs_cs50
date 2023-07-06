#include <stdio.h>


int main(void)
{
    char term[10];
    scanf("%s", term);
    if (term[1] == '\0')
    printf("this is a character\n");
    else
    printf("this string has more than one character\n");
}