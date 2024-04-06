#include<stdio.h>
#include<string.h>
int arr[10] = {2, 4, 7, 1, 10, 3, 11, 6, 20, 5};
int* ptr = &arr[0]; // Pointer to the first element
for(int i = 0; i < 10; i++){
  printf("%i\n", *ptr); // Dereference the pointer and print the value
  ptr++; // Increment the pointer to point to the next int in the array
}
