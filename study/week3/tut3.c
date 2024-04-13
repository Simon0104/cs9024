#include <stdio.h>
#include <stdlib.h>
int main(){
  int A[10] = {0,1,2,3,4,5,6,7,8,9};
  int v = 0;
  printf("Enter a number:");
  scanf("%d", &v);
  for(int i = 0; i <= 9; i++){
    for(int j = i+1; j <= 10; j++){
      if(A[i] + A[j] == v){
        printf("A[%d] + A[%d] = %d\n", i, j, v);
        return 0;
      }
    }
  return 1;
  }
}


// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//   int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//   int v = 0;
//   printf("Enter a number: ");
//   scanf("%d", &v);
  
//   for(int i = 0; i < 9; i++) { // Should iterate up to 8, because inner loop starts at i+1
//     for(int j = i + 1; j < 10; j++) { // j should be less than 10 to avoid out of bounds
//       if(A[i] + A[j] == v) { // Use == for comparison instead of =
//         printf("A[%d] + A[%d] = %d\n", i, j, v);
//         return 0;
//       }
//     }
//   }
  
//   return 1; // This should be outside of the for loop
// }
