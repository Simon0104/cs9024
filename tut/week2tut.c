// // Suppose you want to write a C program to manage your contacts. Each contact has a name, a phone number, an address, a date of birth, and an email address.
// // You decide to define a structure to represent a contact such that:

// // The name is a nested structure with first name and last name fields. These are strings of up to 20 characters each.
// // The phone number is a string of up to 10 characters.
// // The address is a nested structure with street number, street name, suburb, state, and postcode fields. 
// // The street number and postcode should be short integers, while the street name, suburb, and state should be strings of up to 30, 15, and 3 characters, respectively.
// // The date of birth is a nested structure with day, month, and year fields. These should be short integers.
// // The email address is a string of up to 30 characters.
// // Write a C structure to represent a contact. All structures should be defined as new data types, and any character arrays should allow for end-of-string characters.

// // #include <stdio.h>
// // #include <string.h>
// // typedef struct {
// //     char first_name[20];
// //     char last_name[20];
// //  } Name;

// // typedef struct{
// //     short int street_number;
// //     char street_name[30];
// //     int susburb[15];
// //     int state[3];
// // }




// #include <stdio.h>
// #include <stdlib.h>

// #define MAX_SIZE 100

// // 定义堆栈结构
// typedef struct {
//     char items[MAX_SIZE];
//     int top;
// } Stack;

// // 初始化堆栈
// void initStack(Stack *stack) {
//     stack->top = -1;
// }

// // 入栈操作
// void push(Stack *stack, char value) {
//     if (stack->top == MAX_SIZE - 1) {
//         printf("Stack Overflow\n");
//         exit(EXIT_FAILURE);
//     }
//     stack->items[++stack->top] = value;
// }

// // 出栈操作
// char pop(Stack *stack) {
//     if (stack->top == -1) {
//         printf("Stack Underflow\n");
//         exit(EXIT_FAILURE);
//     }
//     return stack->items[stack->top--];
// }

// // 返回堆栈顶元素
// char peek(Stack *stack) {
//     if (stack->top == -1) {
//         printf("Stack is empty\n");
//         exit(EXIT_FAILURE);
//     }
//     return stack->items[stack->top];
// }

// // 判断堆栈是否为空
// int isEmpty(Stack *stack) {
//     return stack->top == -1;
// }

// // 括号匹配函数
// int bracketMatching(char *s) {
//     Stack stack;
//     initStack(&stack);

//     for (int i = 0; s[i] != '\0'; i++) {
//         if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
//             push(&stack, s[i]);
//         } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
//             if (isEmpty(&stack)) {
//                 return 0; // 括号不匹配情况 1：缺少左括号
//             } else {
//                 char top = pop(&stack);
//                 if ((s[i] == ')' && top != '(') ||
//                     (s[i] == ']' && top != '[') ||
//                     (s[i] == '}' && top != '{')) {
//                     return 0; // 括号不匹配情况 2：错误的右括号
//                 }
//             }
//         }
//     }

//     if (!isEmpty(&stack)) {
//         return 0; // 括号不匹配情况 3：有未匹配的左括号
//     }

//     return 1; // 括号匹配
// }

// int main() {
//     char input[MAX_SIZE];
//     printf("Enter a string: ");
//     fgets(input, sizeof(input), stdin);

//     if (bracketMatching(input)) {
//         printf("Parentheses balanced\n");
//     } else {
//         printf("Parentheses not balanced\n");
//     }

//     return 0;
// }

#include <stdio.h>
#include <math.h>

int unknown(int array[], int l, int r) {
    if (l > r) {
        return -INFINITY;;
    } else if (l == r) {
        return array[l];
    } else {
        int q = l + floor((r - l) / 3);
        int ansL = unknown(array, l, q);
        int ansR = unknown(array, q + 1, r);
        if (ansL > ansR) {
            return ansL;
        } 
        else {
            return ansR;
        }
    }
}

int main(void) {
    // int array[8] = {6, 4, 2, 9, 2, 8, 6, 5};
    int array[8];
    int i = 0;
    for (i = 0; i < 8; i++){
        printf("Enter a number: ");
        scanf("%d", &array[i]);
    }
    if(array[i] == 'quit'){
        return 1;
    }
    int result = unknown(array, 0, 7);
    printf("Result: %d\n", result);
    return 0;
}
