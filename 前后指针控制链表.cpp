#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

void moveZeroes(ListNode* nums) {
    ListNode* p = nums;
    ListNode* q = nums;
    while (q != NULL) {
        if (q->val != 0) {
            /* (5) */ p->val = q->val;  // 将非零值赋给p指向的节点
            /* (6) */ p = p->next;     // p指针后移，准备存下一个非零值
        }
        q = q->next;
    }
    while (/* (7) */ p != NULL) {  // 遍历p之后的剩余节点
        /* (8) */ p->val = 0;      // 将剩余节点置为0
        p = p->next;
    }
}
