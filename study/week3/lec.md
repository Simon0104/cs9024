
Examples of Pointers	
int *p; int *q; // this is how pointers are declared
int a[5];
int x = 10, y;

 p = &x;      // 指针p指向x的地址
*p = 20;      //指针p的数值为20
 y = *p;      //y指向p，无论何时两者数值相等
 p = &a[2];   //指针p指向数组a的第三个element
 q = p;      //q和p的数值相等

////////////////////////////////////////////////////////////////////////////

 Pointers and Arrays	
An alternative approach to iteration through an array:

1.determine the address of the first element in the array
2.determine the address of the last element in the array
3.set a pointer variable to refer to the first element
3.use pointer arithmetic to move from element to element
4.terminate loop when address exceeds that of last element


int a[6];
int *p;
p = &a[0];
while (p <= &a[5]) {
    printf("%2d ", *p);
    p++;
}

////////////////////////////////////////////////////////////////////////////
then the following are all equivalent:

s.SomeElem    sp->SomeElem    (*sp).SomeElem

////////////////////////////////////////////////////////////////////////////
代码存储的内存区域：
1.code … fixed-size, read-only region
平时运行的代码都存储在code area
2.global data … fixed-size
如果是golbal variables 那么则存储在read-write,如果是constant strings那么就是read
3.heap … very large, read-write region
存储动态数据结构，malloc
4.stack … dynamically-allocated data (function local vars)
存储局部变量

////////////////////////////////////////////////////////////////////////////
... The malloc() function	
Things to note about   void *malloc(size_t):

it is defined as part of  stdlib.h
its parameter is a size in units of bytes
its return value is a generic pointer  (void *)
the return value must always be checked   (may be NULL)
Required size is determined by   #Elements * sizeof(ElementType)


////////////////////////////////////////////////////////////////////////////
Write code to
create space for 1,000 speeding tickets (cf. Lecture Week 1)
create a dynamic m×n-matrix of floating point numbers, given m and n


Ticket *ticket;
ticket = malloc*(1000*sizeof(ticktet));
assert(ticket != NULL);


给矩阵分配地址有两大部分：1.指针分配   2.value数值分配地址
folat **matric
matric = malloc*(m*sizeof(float*));
assert(matric != 0);
int i;
for(i = 0;i < m;i++)
    matric[i] = malloc*(n*sizeof(float));
    assert(matric[i] != NULL); 

// Exercise #7: Dynamic Arrays	
// Write a C-program that
// prompts the user to input a positive number n
// allocates memory for two n-dimensional floating point vectors a and b
// prompts the user to input 2n numbers to initialise these vectors
// computes and outputs the inner product of a and b
// frees the allocated memory

////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////

Reminder: To realise a "chain of elements", need a node containing

1.a value
2.a link to the next node

In C, we can define such nodes as:
typedef struct node {
   int data;
   struct node *next;
} NodeT;

////////////////////////////////////////////////////////////////////////////

Memory Storage for Linked Lists	
Create a new list node: C implementation of makeNode()

NodeT *makeNode(int v) {
   NodeT *new = malloc(sizeof(NodeT));
   assert(new != NULL);
   new->data = v;       // initialise data
   new->next = NULL;    // initialise link to next node
   return new;          // return pointer to new node
}


////////////////////////////////////////////////////////////////////////////

Standard method for scanning all elements in a linked list:

NodeT *list;  // pointer to first Node in list
NodeT *p;     // pointer to "current" Node in list

for (p = list; p != NULL; p = p->next) {
	… do something with p->data …
}

... Iteration over Linked Lists	(inLL)
Check if list contains an element:

int inLL(NodeT *list, int d) {
   NodeT *p;
   for (p = list; p != NULL; p = p->next)
      if (p->data == d)      // element found
         return true;
   return false;             // element not in list
}
Print all elements:showlinedlist

void showLL(NodeT *list) {
   NodeT *p;
   for (p = list; p != NULL; p = p->next)
      printf("%6d", p->data);
}

Modifying a Linked List	
Insert a new element at the beginning:

NodeT *insertLL(NodeT *list, int d) {
   NodeT *new = makeNode(d);  // create new list element
   new->next = list;          // link to beginning of list
   return new;                // new element is new head
}
Usage:

NodeT *myList;
myList = makeNode(5);
myList = insertLL(myList, 4);
... Modifying a Linked List	
Delete the first element:

NodeT *deleteHead(NodeT *list) {
   assert(list != NULL);  // ensure list is not empty
   NodeT *head = list;    // remember address of first element
   list = list->next;     // move to second element
   free(head);
   return list;           // return pointer to second element
}

////////////////////////////////////////////////////////////////////////////

Stack as ADT	
Interface (in stack.h)

// provides an opaque view of ADT
typedef struct StackRep *stack;

// set up empty stack
stack newStack();
// remove unwanted stack
void dropStack(stack);
// check whether stack is empty
bool StackIsEmpty(stack);
// insert an int on top of stack
void StackPush(stack, int);
// remove int from top of stack
int StackPop(stack);
ADT stack defined as a pointer to an unspecified struct named StackRep

Stack ADT Implementation	
Linked list implementation (stack.c):

Remember: stack.h includes  typedef struct StackRep *stack;

#include <stdlib.h>
#include <assert.h>
#include "stack.h"

typedef struct node {
   int data;
   struct node *next;
} NodeT;

typedef struct StackRep {
   int    height;   // #elements on stack
   NodeT *top;      // ptr to first element
} StackRep;

// set up empty stack
stack newStack() {
   stack S = malloc(sizeof(StackRep));     
   assert(S != NULL);
   S->height = 0;
   S->top = NULL;
   return S;
}

// remove unwanted stack
void dropStack(stack S) {
   NodeT *curr = S->top;
   while (curr != NULL) {  // free the list
      NodeT *temp = curr->next;
      free(curr);
      curr = temp;
   }
   free(S);           // free the stack rep
}

// check whether stack is empty
bool StackIsEmpty(stack S) {
   return (S->height == 0);
}

// insert an int on top of stack
void StackPush(stack S, int v) {
   NodeT *new = malloc(sizeof(NodeT));  
   assert(new != NULL);
   new->data = v;
   // insert new element at top
   new->next = S->top;
   S->top = new;
   S->height++;
}

// remove int from top of stack
int StackPop(stack S) {
   assert(S->height > 0);
   NodeT *head = S->top;
   // second list element becomes new top
   S->top = S->top->next;
   S->height--;
   // read data off first element, then free
   int d = head->data;
   free(head);
   return d;
}
