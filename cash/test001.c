#include <stdio.h>
//#include <string.h>

void bubble_sort(int arr[], int length_arr);


int main()
{
  int arr[] = {4,2,6,3,4,1,0,55,8,9,0};
  int length_arr = sizeof(arr) / sizeof(arr[0]);

  bubble_sort(arr, length_arr);

  for (int i = 0; i < length_arr; i++)
  {
    printf("%i ", arr[i]);
  }
  printf("\n");
}


void bubble_sort(int arr[], int length_arr)
{
  for (int i = 0; i < length_arr; i++)
  {
    for (int j = 0; j < length_arr - 1; j++)
    {
      if (arr[j] > arr[j+1])
      {
        int tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}