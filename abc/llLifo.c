#include <stdio.h>
#include <stdlib.h>

//Ll is composed of nodes, we define the node dataStru.

typedef struct singleNode
{
    int number;
    struct singleNode *next;
}
node;

void print_Ll(node *list);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Input format : ./llLifo LlSize\n"); // Ll stands for linked list
        return 1;
    }
    int Llsize = atoi(argv[1]);
    node *list = NULL;
    //node *temp = NULL; // Another method

    for(int k = 0; k < Llsize; k++)
    {
        int n;
        printf("Enter the %i integer to add to the Ll : ", k+1);
        scanf("%i", &n);
        node *x = malloc(sizeof(node));
        x -> number = n;
        x -> next = list;
        list = x;
        //temp = x;
        //temp -> next = list;
        //list = temp;
        //free(x);
    }
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        printf("%i : %p\n", tmp->number, &(tmp->number));
    }

    printf("\n--------PRINTING USING CALL STACK-----------------------\n\n");

    print_Ll(list);
    //node *x = malloc(sizeof(node));
    return 0;
}

//TO UNDERSTAND HOW CALL STACK WORK
void print_Ll(node *list)
{
    if (list == NULL)
    return;
    print_Ll(list->next);
    printf("%i\n",list->number);
}