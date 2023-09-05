////////////////////////////////////////////////////
//                    LeetCode                    //
//             141. Linked List Cycle             //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *tortoise = head;
    struct ListNode *hare = head;
    while(tortoise && hare && hare->next) {
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) {
            return true;
        }
    }
    return false;
}

int main() {
    return EXIT_SUCCESS;
}