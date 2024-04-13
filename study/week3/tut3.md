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


