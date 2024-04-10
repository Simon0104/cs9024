unknown(A,l,r):
|  if l > r then
|     return -∞
|  else if l = r then
|     return A[l]
|  else
|     q = l + ⌊(r-l)/3⌋
|     ansL = unknown(A, l, q)
|     ansR = unknown(A, q+1, r)
|     if ansL > ansR
|        return ansL
|     else
|        return ansR
|     endif
|  endif

#include <stdio.h>
#include <stlib.h>
int main(){
    
}