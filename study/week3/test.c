
// Exercise #7: Dynamic Arrays	68/98
// Write a C-program that

// prompts the user to input a positive number n
// allocates memory for two n-dimensional floating point vectors a and b
// prompts the user to input 2n numbers to initialise these vectors
// computes and outputs the inner product of a and b
// frees the allocated memory
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(){
    int n = 0;
    printf("please enter a positive number:\n");
    scanf("%d", &n);
    float **Matrix_a, **Matrix_b;
    Matrix_a = malloc(n*sizeof(float*));
    Matrix_b = malloc(n*sizeof(float*));
    assert(Matrix_a != NULL && Matrix_b != NULL);

    for(int i = 0;i < n;i++){
        Matrix_a[i] = malloc(n*sizeof(float));
        assert(Matrix_a[i] != NULL);    
        scanf("%f", Matrix_a[i]);
        }

    for(int i = 0;i < n;i++){
        Matrix_b[i] = malloc(n*sizeof(float));
        assert(Matrix_b[i] != NULL);    
        scanf("%f", Matrix_b[i]);
        }    

    printf("please initialise these vectors");
    // Compute the inner product of a and b
    float inner_product = 0.0;
    for (int i = 0; i < n; i++) {
        inner_product += (*Matrix_a[i]) * (*Matrix_b[i]);
    }

    // Output the inner product
    printf("The inner product of vectors a and b is: %.2f\n", inner_product);

    // Free the allocated memory
    for (int i = 0; i < n; i++) {
        free(Matrix_a[i]);
        free(Matrix_b[i]);
    }
    return 0;
}