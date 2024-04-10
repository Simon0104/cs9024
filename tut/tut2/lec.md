Big O:

matrixProduct(A,B):
|  Input  n×n matrices A, B
|  Output n×n matrix A·B
|
|  for all i=1..n do
|  |  for all j=1..n do
|  |  |  C[i,j]=0
|  |  |  for all k=1..n do
|  |  |     C[i,j]=C[i,j]+A[i,k]·B[k,j]
|  |  |  end for
|  |  end for
|  end for

Determine the number of primitive operations
matrixProduct(A,B):
|  Input  n×n matrices A, B
|  Output n×n matrix A·B
|  for all i=1..n do

//time complexity:
for(i = 1; i < n; i++)
首先循环时间复杂度为n+1(因为要判断n+1次)，i++的时间复杂度为n
所以该for loop的时间复杂度为2n+1//

|  |  for all j=1..n do
//time complexity:
for(j = 1; j < n; j++)

//same as the above for loop, the time complexity is n(2n+1)
because this loop time complexity is (2n+1), but every above for loop run once, this for loop will run (2n+1), then above loop runs n times.//

|  |  |  C[i,j]=0

//because the range of i and j is n, then [i,j] is n^2//

|  |  |  for all k=1..n do

这个for loop 本身的时间复杂度为(2n+1)，
|  |  |     C[i,j]=C[i,j]+A[i,k]·B[k,j]

//A[i,k]和B[k,j]分别是执行n^2次，此处则已经有2次的n^2,然后乘法操作又是n次，则此处有3次n^2，在之后执行加法操作则应为4*n^2//

|  |  |  end for
|  |  end for
|  end for
|  return C



Self-referential Structures	
1.创建新节点
Create a new list node:

makeNode(v)
|  Input  value v
|  Output new linked list node with value v
|
|  new.value=v      // initialise data
|  new.next=NULL    // initialise link to next node
|  return new       // return pointer to new node

创建一个新的node节点，每个node包含一个value和一个pointer，此处创建新节点设置定值value并且链接到链表的末尾设置.next为NULL
作用是方便后续添加延长链表方便


2.创建新链表
Creating a Linked List	
Write pseudocode to create a linked list of three nodes with values 1, 42 and 9024.

mylist=makeNode(1)
mylist.next=makeNode(42)
(mylist.next).next=makeNode(9024)


3.初始化链表
Iteration over Linked Lists	
When manipulating list elements
(a)首先set一个pointer指向首节点
p = list
\\因为链表首节点就是链表名\\
(b)其次获取现在节点的数值
p.value
(c)指向下一个节点
p.next


4.迭代链表
To iterate over a linked list:

set p to point at first node (head)
examine node pointed to by p
change p to point to next node
stop when p reaches end of list (NULL)

... Iteration over Linked Lists	
Standard method for scanning all elements in a linked list:

list  // pointer to first Node in list
p     // pointer to "current" Node in list
p=list
while p≠NULL do
|  … do something with p.value …
|  p=p.next
end while


Modifying a Linked List	
Insert a new element at the beginning:
input: value d, linked list L
output: new linked list with value d

new = newlistnode(d)
new.next = L
return new
//创建新节点链接到list开头然后返回new即可//


5.删除一个特定的元素
Delete a specific element (recursive version):
deleteLL(L,d):
|  Input  linked list L
|  Output L with element d deleted
|
|  if L=NULL then            // element not in list
|     return L
|  else if L.value=d then    // d found at front
|     return deleteHead(L)   // delete first element 
|  else                      // delete element in tail list
|     L.next=deleteLL(L.next,d) // the rest of the list (i.e., L.next)  
|     return L               // is what you get by deleting 'd' from the rest of the list
|  end if


                                Complexity of operations, n elements

                                        array	    linked list
insert/delete at beginning              O(n)         O(1)
insert/delete at end	                O(n)         O(1)
insert/delete at middle	                O(n)         O(n)   
find an element	                        O(n)         O(n)
                                if sorded_arrayO(logn)         
index a specific element	            O(n)         O(n)






