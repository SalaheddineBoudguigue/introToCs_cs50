#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>


typedef struct
{
    int number;
    char N;
}
pep;

int main(void)
{
    pep *list = malloc(2*sizeof(pep));
    list[0].number = 34453;
    list[0].N = 'A';

    list[1].number = 34532;
    list[1].N = 'R';

    // I wanna add a third pep
    // Well, that's not easy with arrays
    // since I have only space for two pep in list
    // And to avoid losing data, I have to make a copy
    // of list, that can hold a third pep and then copy its
    // data to a new list that can hold it
    // let's do that

    pep *temp = malloc(3*sizeof(pep));
    for (int i =0; i <2; i++)
    {
        temp[i] = list[i];
    }
    // Now all list data is copied to temp, and we need
    free(list);
    temp[2].number = 23323;
    temp[2].N = 'c';

    list = malloc(3*sizeof(pep));
    for (int i =0; i<3; i++)
    {
        list[i] = temp[i];
    }
    free(temp);
    for (int i =0; i<3; i++)
    {
        printf("%i : %c\n", list[i].number, list[i].N);
    }
    free(list);
}