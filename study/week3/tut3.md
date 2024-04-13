(Algorithms and complexity)
Design an algorithm to determine if an integer array, A，
contains two elements that sum to a given value, v.

Write the algorithm in pseudocode.
Determine the worst-case time complexity of your algorithm.
Translate your algorithm into a C function that accepts the array, its length, and the sum value, and returns true or false.

input: a integer array A, value v;
output: true if two elements that equal to value v, other false;

for i = 1....n - 1 do
    for j = i+1... n do
        if(A[i] + A[j] = v) then
            return true;
        end if
    end for
end for


/////////////////////////////////////////////////////////////////////////////
A word is a palindrome if its reverse is equal to itself. For example, ABBA is a palindrome, whereas ABCA is not. One way of representing a word in a computer is to have a singly-linked list, where we have a list element for each letter. For example, ABBA is represented by the singly-linked list

Design an algorithm that, given a pointer to the head of a singly-linked list which represents a word, outputs true if the word is a palindrome, and false otherwise. Your algorithm should run in linear time and should not use any data structures other than singly-linked lists, i.e. no arrays, stacks, queues, etc.

intput:linked list L,empty linked list R
output:true if linked list is palindrome, otherwise return false

Modifying a Linked List	
Insert a new element at the beginning:

NodeT *insertLL(NodeT *list, int d) {
   NodeT *new = makeNode(d);  // create new list element
   new->next = list;          // link to beginning of list
   return new;                // new element is new head
}

Q = L
R = NULL
while Q != NULL do
    R = inserLL(R, Q.value) 
    Q = Q.next
end while
Q = L
P = R
while Q != NULL do
    if Q.value != P.value then
        return false
    end if
    Q = Q.next
    P = P.next
end while
return true

////////////////////////////////////////////////////////////////////////
(Ordered linked lists)
A particularly useful kind of linked list is one that is sorted. Give an algorithm for inserting an element at the right place into a linked list whose elements are sorted in ascending order.

Example: Given the linked list

L = 17 26 54 77 93
the function insertOrderedLL(L,31) should return the list
L = 17 26 31 54 77 93

Hint: Develop the algorithm with the help of a diagram that illustrates how to use pointers in order to find the right place for the new element and
link the new element to its predecessor and its successor.

intput: sorted list, value v
output: a sorted with right place value list

current = L
previous = NULL

while previous != NULL && current.value < d do
    previous = current
    current = current.next
end while
\\上述代码段段作用是遍历链表并且找到插入点，该点不可等于NULL并且应小于value d
temp = makenode(d)
if temp != NULL do
    temp.next = current
    previous.next = temp
end if
上述代码段是将找到的value d代入makenode代码段,这样才能插入
else 
    temp.next = L
    L = temp
end if
return L
插入应分为两种情况：1.头插
                2.中间尾插
///////////////////////////////////////////////////////////////////////

Let  elem  be a pointer to an element in the list. Describe an algorithm in pseudocode to delete the element at address  elem . How many pointers in total need to be redirected (i.e. their values changed)?

intput:pointer elem, list L
output:list L without elem pointer

R = L


