#include "stdio.h"
#include <stddef.h>
#include <stdlib.h>

int add_memory(int **ptr, size_t n)
{
  int *buff = malloc(n * sizeof(int));
  *ptr = buff;

  return 0;
}

int append(int **ptr, size_t length, int size)
{
  for (int i = 0; i < length; i++)
  {
    if (i == size)
    {
      printf("Add memory\n");

      int *tmp;
      add_memory(&tmp, size * 2);

      for (int j = 0; j < i; j++)
      {
        *(tmp + j) = *(*ptr + j);
      }

      free(*ptr);
      *ptr = tmp;
    }
    *(*ptr + i) = i * i;
  }

  return 0;
}

int print(int *array, size_t length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%d\n", *(array + i));
  }

  return 0;
}

int main(void)
{
  int length = 0;
  int is_readed = scanf("%d", &length);

  if (is_readed == 0)
  {
    printf("Input Error");

    return 1;
  }

  int *ptr;

  add_memory(&ptr, 10);
  append(&ptr, length, 10);

  print(ptr, length);

  return 0;
}
