
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//int lentg(string s); //prototype

int fact(int n);
int fibo(int n);
void draw(int n);
int vote(int rank, char *name, int ranks[]);
void selectionSort(void);
void swap(int *a, int *b);

typedef uint8_t BYTE;

typedef struct nodePtr
{
  int number;
  struct nodePtr *next;
}
node;

int main(void)
{
  draw(5);
  /*node *list = NULL;
  node *x = malloc(sizeof(node));
  x -> number = 3;
  x -> next = NULL;
  list = x;
  x = malloc(sizeof(node));
  x -> number = 4;
  x -> next = NULL;
  list -> next = x;
  x = malloc(sizeof(node));
  x -> number = 1;
  x -> next = list;
  list = x;
  x = malloc(sizeof(node));
  x -> number = 00;
  x -> next = list;
  list = x;
  for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
  {
    printf("%i : %p\n", tmp->number, &(tmp->number));
  }*/
//  printf("%i\n", list->number);
//  printf("%i\n", list->next->number);
}


void swap(int *a, int *b)
{
  int *tmp = a;
  a = b;
  b = tmp;
  printf("x : %i\ny: %i\n", *a, *b);
}

int fact(int n)
{
  if (n == 0)
    return 1;
  else
    return n*fact(n-1);
}

int fibo(int n)
{
  if (n==0)
    return 0;
  else if (n==1)
    return 1;
  else
    return fibo(n-1) + fibo(n-2);
}

void draw(int n)
{
  if (n <= 0)
  {
    return;
  }

  for (int k = 0; k < n; k++)
  {
    printf("#  ");
  }
  printf("\n");

  draw(n-1);
}

void selectionSort(void)
{

   int n = get_int("number of numbers to sort : ");
   int L[n];

  for (int i = 0; i < n; i++)
  {
    L[i] = get_int("number %i : ", i+1); //get the number from the user
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = k+1; i <n; i++)
    {
      if (L[k] > L[i]) // use selectionsort algorithm to sort the prompt numbers
      {
        int c = L[k];
        L[k] = L[i];
        L[i] = c;
      }
    }

  }
  printf("Your sorted list is\n");
  for (int k = 0; k < n; k++)
  {
    printf("%i\n", L[k]);
  }
}
