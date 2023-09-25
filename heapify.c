// Max-Heap data structure in C

#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void MAXheapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      MAXheapify(array, size, largest);
    }
  }
}

void MINheapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int lowest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] < array[lowest])
      lowest = l;
    if (r < size && array[r] < array[lowest])
      lowest = r;
    if (lowest != i)
    {
      swap(&array[i], &array[lowest]);
      MINheapify(array, size, lowest);
    }
  }
}

void MAXinsert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      MAXheapify(array, size, i);
    }
  }
}
void MINinsert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      MINheapify(array, size, i);
    }
  }
}
void MAXdeleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }
    if(i==size) {
    printf("The number does not exist in the heap\n");
    return;
  }
  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    MAXheapify(array, size, i);
  }
}
void MINdeleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }
  if(i==size) {
    printf("The number does not exist in the heap\n");
    return;
  }
  swap(&array[i], &array[size - 1]);
  size -= 1;
  printf("After deleting an element: ");

  for (int i = size / 2 - 1; i >= 0; i--)
  {
    MINheapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
  int array[20];

  MAXinsert(array, 3);
  MAXinsert(array, 4);
  MAXinsert(array, 9);
  MAXinsert(array, 5);
  MAXinsert(array, 2);

  printf("Max-Heap array: ");
  printArray(array, size);

  MAXdeleteRoot(array, 4);

  printf("After deleting an element: ");

  printArray(array, size);
    printf("\nImpleminting Min-Heap Functions with Previous & New Nodes:\n\n");
  //Implementing functions for Min-Heap
  MINinsert(array, 13);
  MINinsert(array, 14);
  MINinsert(array, 19);
  MINinsert(array, 15);
  MINinsert(array, 12);

  printf("Min-Heap array: ");
  printArray(array, size);

  MINdeleteRoot(array, 14);

  //After deleting an element:

  printArray(array, size);
}
