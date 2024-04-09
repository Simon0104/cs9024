// #include <stdio.h>
// #include <stdlib.h>
// int main(){
//   int Fib[10];
//   int n = 0;
//   printf("Enter a number:");
//   scanf("%d", &n);
//   Fib[1] = 1;
//   Fib[2] = 1;
//   for(int i = 3; i <= 10; i++){
//       Fib[i] = Fib[n - 1] + Fib[n - 2];
//       return 0;
//   }
//     printf("Fibonacci series:");
//     for(int i = 1; i <= 10; i++){
//         printf("%d", Fib[i]);
//     }
//   return 0;
//   }
#include <stdio.h>

// 计算斐波那契数列的函数
int fib(int n) {
    if (n <= 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

// 执行指定过程直到 n 变为 1 的函数
void process(int n) {
    while (n != 1) {
        printf("%d\n", n);
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
    }
    printf("1\n");
}

int main() {
    for (int i = 1; i <= 10; i++) {
        printf("Fib[%d] = %d\n", i, fib(i));
        process(fib(i));
    }
    return 0;
}
