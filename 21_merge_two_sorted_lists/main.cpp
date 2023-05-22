////////////////////////////////////////////////////
//                    LeetCode                    //
//           21. Merge Two Sorted Lists           //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *soln = new ListNode();
        ListNode *temp = soln;
        while(list1 && list2) {
            if(list1->val < list2->val) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;   
            }
            temp = temp->next;
        }
        
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;

        return soln->next;
    }
};

void insert(ListNode** root, int data) {
   ListNode* node = new ListNode(data);
   ListNode* ptr;
   if (*root == nullptr) {
      *root = node;
   } else {
      ptr = *root;
      while (ptr->next != nullptr) {
         ptr = ptr->next;
      }
      ptr->next = node;
   }
}

ListNode* make_list(vector<int> lst) {
    ListNode* list = nullptr;
    for(int i : lst) {
        insert(&list, i);
    }
    return list;
}

void print_list(ListNode* lst) {
    while(lst != nullptr) {
        cout << lst->val << ", ";
        lst = lst->next;
    }
    cout << endl;
}

int main() {
    vector<int> list1 = { 1, 2, 4 };
    vector<int> list2 = { 1, 3, 4 };
    ListNode* lst1 = make_list(list1);
    ListNode* lst2 = make_list(list2);

    Solution solution = {};
    ListNode* lst = solution.mergeTwoLists(lst1, lst2);
    print_list(lst);

    return EXIT_SUCCESS;
}