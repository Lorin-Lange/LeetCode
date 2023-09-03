////////////////////////////////////////////////////
//                    LeetCode                    //
//            206. Reverse Linked List            //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList_iteratively(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while(head != NULL) {
        struct ListNode* tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }
    return prev;
}

struct ListNode* reverseList_recursively(struct ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    struct ListNode* tmp = reverseList_recursively(head->next);
    head->next->next = head;
    head->next = NULL;
    return tmp;
}

struct ListNode* reverseList(struct ListNode* head) {
    return reverseList_iteratively(head);
}

int main() {
    return EXIT_SUCCESS;
}