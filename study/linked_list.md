```c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// 实现一个链表的数据结构
typedef struct node {
   int data; // 链表node的上部分 data
   struct node *next; // node的下半部分 指针存的是 下个node的地址
} NodeT;

NodeT *joinLL(NodeT *list, int v) {
    //1.创建一个node，并把data写入这个node
   NodeT *new = malloc(sizeof(NodeT));
   assert(new != NULL);
   //把data写入node
   new->data = v; // 上半部分 （data）
   new->next = NULL; // 下半部分 （写入NULL）
   //

   //2.把刚刚创建好的这个有写入data的node， 我们把这个node加入链表
   if (list == NULL) {  // 情况1: 一个node = 链表
      list = new;
      // 情况2: 链表有长度，不仅只有一个node， 需要把剩下的node链接上去
   } else {
      NodeT *p = list;
      while (p->next != NULL) {
         p = p->next;
      }
      p->next = new;
   }
   return list;
}

void showLL(NodeT *list) {
   NodeT *p;
   for (p = list; p != NULL; p = p->next) {
      printf("%d", p->data);
      if (p->next != NULL)
         printf("-->");
   }
   putchar('\n');
}

void freeLL(NodeT *list) {
    NodeT *p = list;
    while (p != NULL) {
        NodeT *temp = p->next;
        free(p);
        p = temp;
    }
}

// main函数有三个步骤
int main(void) {
   NodeT *all = NULL; // 1 设置为空， 初始化
   int value;

    //2.加data到链表
   printf("Enter an integer: ");
   while (scanf("%d", &value) == 1) {
      all = joinLL(all, value); // 实现joinLL函数
      printf("Enter an integer: ");
   }

   //3.循环链表的每一个node，打印/free
   if (all != NULL) {
      printf("Done. List is ");
      showLL(all); // 实现 showLL 和 freeLL 两个函数
      freeLL(all);                   // don't forget to free the list
   } else {
      printf("Done.\n");
   }
   return 0;
}
```
