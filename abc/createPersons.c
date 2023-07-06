#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct person
{
    struct person next;
    int number;
}
person;

person *create(int a);
void print_persons(person *p);
void free_persons(person *p);


int main(void)
{
    srand(time(0));
    person *p = create(3);
    print_persons(p);
    //free_persons(p);
}

person *create(int a)
{
    person *p = malloc(sizeof(person));

    if (a > 1)
    {
        person nextP = create(a-1);
        p -> next = nextP;
        p -> number = rand()%10 + 1;
    }
    else
    {
        p -> next = NULL;
        p -> number = 0;
    }
    return p;
}

vo