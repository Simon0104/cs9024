gcc
We can then use gcc to compile with the command format:

gcc [options] <file1.c> (<file2.c> ... <fileN.c>)
Throughout the term you'll be submitting code for assessment. During marking we'll compile your code using a number of options, so now is a good time to get into the habit of using them yourself. Specifically:

-Wall: Enable (almost) all warnings
//允许所有的警告 warning all
-Werror: Turn all warnings into errors
//允许所有错误 warning error
-std=c11: Compile based on the C11 revision of the C language
//标准基于c11 standard = c11
We can also use the -o <program> option to specify the name of the output file. If we don't use this option then the output file will be saved with the default name a.out (or on Windows, a.exe).

So to compile and run our program you can execute the following commands, and you should get the expected output:

gcc -Wall -Werror -std=c11 -o hello hello.c
./hello
Hello, COMP9024!


(dcc)
gcc is the GNU Compiler Collection. It was originally the GNU C Compiler, but now it supports numerous languages (e.g. C++, Objective C, Fortran, Go, ...). It's freely and widely available, with support for numerous platforms (so you may want to install it on your home computer, if it isn't already - see the Home Computing Advice pages). Unfortunately though, it isn't always friendly for the novice programmer. Let's look at an example...

Create a new file in your tut1 workspace called bad.c with the following code:

#include <stdio.h>

int main(void) {
    char *p = 0;
    printf("%c\n", *p);
    return 0;
}
Then compile and run the program:

gcc -Wall -Werror -std=c11 -o bad bad.c
./bad
Despite compiling without issue, the program crashes and reports a rather unhelpful error message.
As an alternative to gcc, CSE has developed the Debugging C Compiler, dcc, to catch common errors and provide easy-to-understand explanations. They both follow the same interface, simply replace gcc with dcc when compiling code on CSE.
Now re-compile the code using dcc and run it again:

dcc -Wall -Werror -std=c11 -o bad bad.c
./bad
Compare the error messages and consider which is more helpful in debugging your code. Also try running dcc-help after the program crashes to get additional AI-generated help.

Hopefully it's clear that using dcc could save you from quite a few debugging headaches and speed up the development process.



// There is a 5-digit number that satisfies 4·abcde = edcba, that is, when multiplied by 4 yields the same number read backwards. Write a C-program to find this number.

// Hint: Only use arithmetic operations; do not use any string operations.

#include <stdlib.h>
#include <stdio.h>

#define MIN 10000
#define MAX 24999

int main(){
    int a, b, c, d, e, i;
    for(i = MIN; i <= MAX; i++)
    {
        a = (i / 10000) % 10;
        b = (i / 1000) % 10;
        c = (i / 100) % 10;
        d = (i / 10) % 10;
        e = i % 10;
        if(4 * i == e * 10000 + d * 1000 + c * 100 + b * 10 + a){
            printf("%d\n", i);
        }
    }
    return 0;
}


(Elementary control structures)
Write a C-function that takes a positive integer n as argument and outputs a series of numbers according to the following process, until 1 is reached:

if n is even, then n ← n/2
if n is odd, then n ← 3*n+1
The Fibonacci numbers are defined as follows:

Fib(1) = 1
Fib(2) = 1
Fib(n) = Fib(n-1)+Fib(n-2) for n≥3
Write a C program fibonacci.c that applies the process described in Part a. to the first 10 Fibonacci numbers.

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void fibor(int n){
   printf("%d\n", n);
   while (n != 1) {
      if (n % 2 == 0) {
	 n = n / 2;
      } else {
	 n = 3*n + 1;
      }
      printf("%d\n", n);
   }
}

int main(){
    int fib[MAX] = {1,1};
    for(int i = 2; i < MAX; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for(int i = 0; i < MAX; i++){
        printf("fib(%d) = %d\n",i+1,fib[i]);
        fibor(fib[i]);
    }
    return 0;
}



(Stack ADO)
Modify the Stack ADO from the lecture (Stack.h and Stack.c) to an implementation of a stack of integers. Below is the header file (IntStack.h) for your ADO:

IntStack.h
// Integer Stack ADO header file ... COMP9024 24T1

#define MAXITEMS 10

void StackInit();     // set up empty stack
int  StackIsEmpty();  // check whether stack is empty
void StackPush(int);  // insert int on top of stack
int  StackPop();      // remove int from top of stack
Your task is to implement these functions in a program called IntStack.c.

Complete the test program below (StackTester.c) and run it to test your integer stack ADO. The tester

initialises the stack
prompts the user to input a number n
checks that n is a positive number
prompts the user to input n numbers and push each number onto the stack
uses the stack to output the n numbers in reverse order (needs to be implemented)
StackTester.c
// Integer Stack ADO tester ... COMP9024 24T1
#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int main(void) {
   int i, n;
   char str[BUFSIZ];

   StackInit();

   printf("Enter a positive number: ");
   scanf("%s", str);
   if ((n = atoi(str)) > 0) {    // convert to int and test if positive
      for (i = 0; i < n; i++) {
	 printf("Enter a number: ");
	 scanf("%s", str);
	 StackPush(atoi(str));
      }
   }

   /* NEEDS TO BE COMPLETED */

   return 0;
}