// (Counting primitive operations)
// The following algorithm

// takes a sorted array A[1..n] of characters
// and outputs, in reverse order, all 2-letter words νω such that ν≤ω.
//   for all i=n down to 1 do
//       for all j=n down to i do
//           print "A[i]A[j]"
//       end for
//   end for

// Count the number of primitive operations (evaluating an expression, indexing into an array). 
// What is the time complexity of this algorithm in big-Oh notation?
// for(i = n; i< = ?; i--)



// // (Algorithms and complexity)
// // Design an algorithm to determine if an integer array, A, contains two elements that sum to a given value, v.

// // Write the algorithm in pseudocode.
// // Determine the worst-case time complexity of your algorithm.
// // Translate your algorithm into a C function that accepts the array, its length, and the sum value, and returns true or false.
// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//     int v;
//     int result = 0;
//     printf("please enter a number:");
//     scanf("%d", &v);
//     int A[5] = {1,2,3,4,5};
//     for(int i = 0; i < 5; i++){
//         for(int j = i + 1; j < 5; j++){
//             if(A[i] + A[j] == v){
//                 // return result = A[i] + A[j]; 
//                 printf("true\n");
//                 return 0;
//                 // return result;
//             }
//         }
//     }
//     printf("false\n");
//     return 0;
// }


// Let L be the linked list representing our word; 
// the idea of the algorithm is to create a new linked list R, which contains the word of L reversed, and then compare the two words. 
// We create the linked list R by traversing the list L and for each element in L, inserting this element at the head of R. 
// At the end of this procedure, the list R will be equal to the reverse of L.

// Palindrome(L)
// |  Input  linked list L representing a word
// |  Output true if L is a palindrome, and false otherwise
// |  
// |  p=L
// |  R=NULL
// |  while p≠NULL do
// |     R=insertLL(R,p.value)
// |     p=p.next
// |  end while 
// |  p=L
// |  q=R
// |  while p≠NULL do
// |     if p.value≠q.value then 
// |        return false
// |     end if
// |     p=p.next
// |     q=q.next 
// |  end while
// |  return true

#include <stdio.h>
#include <stdlib.h>
 int main(){
    Node T *makeNode(int v){
        NodeT *new = malloc(sizeof(NodeT));
        assert(new != NULL);
        new -> value = v;
        new -> next = NULL;
        return new;
    }
 }
