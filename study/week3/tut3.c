// (Counting primitive operations)
// The following algorithm

// takes a sorted array A[1..n] of characters
// and outputs, in reverse order, all 2-letter words νω such that ν≤ω.

// for all i=n down to 1 do

// for(int i = n;i = 1;i--)
// 该for loop运行次数应该分为两大部分：
// 1.判断i是否等于1，此处应运行n+1次
// 2.每次循环应该执行一次--操作，此处应运行n次
// 综上所述应该运行2n+1次

//       for all j=n down to i do

// for(int j = n;j = i;j--)
/

//           print "A[i]A[j]"

// 因为要找二维数组，所以运行次数应该是n^2

//       end for
//   end for

// Count the number of primitive operations (evaluating an expression, indexing into an array). 
// What is the time complexity of this algorithm in big-Oh notation?

























// (Ordered linked lists)
// A particularly useful kind of linked list is one that is sorted. 
// Give an algorithm for inserting an element at the right place into a linked list whose elements are sorted in ascending order.

// Example: Given the linked list

// L = 17 26 54 77 93
// the function insertOrderedLL(L,31) should return the list
// L = 17 26 31 54 77 93
// Hint: Develop the algorithm with the help of a diagram that illustrates how to use pointers in order to
// find the right place for the new element and
// link the new element to its predecessor and its successor.

insertOrderedLL(L,d):
|  Input  ordered linked list L, value d
|  Output L with d added in the right place
|
|  current=L, previous=NULL
|  while current≠NULL and current.value<d do
|     previous=current
|     current=current.next
|  end while
|  temp=makeNode(d)
|  if previous≠NULL then
|     temp.next=current      // Step 1
|     previous.next=temp     // Step 2
|  else
|     temp.next=L            // add new element at the beginning
|     L=temp
|  end if
|  return L





// Create a new list node:

// input value: a
// output:new linked list node with value asm

new.value = a;   初始化新节点的数值
new.next = NULL;   将新节点的next指针指向null
return new;  返回新节点


// Exercise #7: Creating a Linked List	54/85
// Write pseudocode to create a linked list of three nodes with values 1, 42 and 9024.


mylist = listnode(1);
mylist.next = listnnode(42);
mylist.next.next = listnode(9024);

// Iteration over Linked Lists
list
current

list = current;
while(current != NULL) do
{
  do something with current.value;
  current = current.next;  
} 
end while (
    


Check if list contains an element:
input: list L, value d
output: true if d within the L, false otherwise

p = L;
while p ! = NULL  do
 {
    if p.value = d;
    return true;
    end if;
    p = p.next;
 }
 return false;



#include <stdio.h>
 2
 3  int main(void) {
 4     int *ptr1, *ptr2;
 5     int i = 10, j = 20;
 6
 7     ptr1 = &i;
 8     ptr2 = &j;
 9
10     *ptr1 = *ptr1 + *ptr2;
11     ptr2 = ptr1;
12     *ptr2 = 2 * (*ptr2);
13     printf("Val = %d\n", *ptr1 + *ptr2);
14     return 0;
15  }


4     int *ptr1, *ptr2;
 5     int i = 10, j = 20;
 6
 7     ptr1 = &i = 10
 8     ptr2 = &j = 20
 9
10     *ptr1 = *ptr1 + *ptr2;= 10+ 20 = 30;
11     ptr2 = ptr1; = 30
12     *ptr2 = 2 * (*ptr2);2*30 = 60
13     printf("Val = %d\n", *ptr1 + *ptr2); 60 +
14     return 0;
15  }