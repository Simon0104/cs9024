#include <stdio.h>
#include "mystrlen.h"

int main(void) {
   char s[MAXLEN];
   int len;

   // your code here to repeatedly prompt the user for a string 
   // and print its length using mystrlen

    while (1) {
        printf("Enter a string: ");
        fgets(s, MAXLEN, stdin);
        len = mystrlen(s);

        if (len == 1 && s[0] == '\n') {
            break;
        }
        
        printf("%d\n", len);
    }

    printf("Goodbye!\n");

   return 0;
}