#include <stdio.h>
#include <ctype.h>

unsigned int hash(const char *word);

int main()
{
    char term[10];
    printf("Enter a word : "); scanf("%s", term);
    printf("%i\n", hash(term));
}

unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}