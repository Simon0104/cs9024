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
|  |  |  end for
|  |  end for
|  end for
|  return C