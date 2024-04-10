// Write a program popularityRank.c that
// builds a directed graph from user input:

// first, the user is prompted for the number of vertices
// then, the user is repeatedly asked to input an egde by entering a "from" vertex followed by a "to" vertex
// until any non-numeric character(s) are entered
// You should use scanf to read the input and check the return value to determine whether an int was successfully read.

// ranks all the nodes according to their popularity, where the popularity of a vertex v is defined by the following formula:

//    popularityRank(v) = inDegree(v) / outDegree(v)

// (if outDegree(v) is zero, replace it by 0.5)

// outputs the nodes and their popularity rating rounded to 1 decimal place, from most popular to least popular. 
// Nodes that rank equally should be printed in their natural (increasing) order.

// popularityRank(v) = inDegree(v) / outDegree(v)

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double popularityRank(int v, int inDegree, int outDegree){
    if(outDegree == 0){
        outDegree = 0.5;
    }
    // double poprank(v) = inDegree(v) / outDegree(v);
    return (double)inDegree / outDegree;
}

// Insertion sort ... COMP9024 24T1

// #define SIZE 6
void insertionSort(int array[], int n) {
   int i;
   int numbers[n];
   for (i = 1; i < n; i++) {
      int element = array[i];                 // for this element ...
      int j = i-1;
      while (j >= 0 && array[j] > element) {  // ... work down the ordered list
         array[j+1] = array[j];               // ... moving elements up
         j--;
      }
      array[j+1] = element;                   // and insert in correct position
      for (i = 0; i < n; i++){
        return numbers[i];
      }

   }
}

// int main(void) {
//    int numbers[SIZE] = { 3, 6, 5, 2, 4, 1 };
//    int i;
   
//    insertionSort(numbers, SIZE);
//    for (i = 0; i < SIZE; i++)
//       printf("%d\n", numbers[i]);

//    return 0;
// }

int main(void) {
    int n, from, to;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = newGraph(n); // Create graph
    printf("Enter an edge (from): ");
    while (scanf("%d", &from) == 1) {
        if (from == -1) break; // End input if -1 is entered
        printf("Enter an edge (to): ");
        scanf("%d", &to);
        if (from < 0 || from >= n || to < 0 || to >= n) break;
        insertEdge(g, (Edge) {from, to}); // Insert edge
        printf("Enter an edge (from): ");
    }
    printf("Done.\n");
    printf("Popularity rank:\n");
}