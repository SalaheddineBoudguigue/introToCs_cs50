#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
  string s = get_string("Enter a string : ");
  for (int i=0, n=strlen(s); i<n; i++)
  {
    if (s[i] >= 'a' && s[i] <= 'z')
    {
      s[i] = s[i] -32 ;
    }
  }
  printf("%s\n", s);
  /*char a = 'A';
  printf("%i\n", a);*/
  /*int a;
  for (int i = 0; i < 4; i++)
  {
    a = i;
    printf("%i\n",a);
  }*/
  //printf("%i %i\n", argv[1] ,argv[2]);

  /*if ((int)argv[1])
  {
    printf("a is a number: %i\n", (int)argv[1]);
  }
  else
  {
    printf("a is not a number\n");
  } */
  /*string s = get_string("enter a string :  ");
  if ( (int)s == s)
  {
    printf("s is integer\n");
  }
  else
  {
    printf("s is not an integer\n");
  }
  int arr[] = {1,2,3,4,5,6,7};
  int arr001[7];
  for (int i= 0; i<7; i++)
  {
    arr001[i] = arr[6-i];
  }
  for (int i= 0; i<7; i++)
  {
    printf("%i\n", arr001[i]);
  }*/
}