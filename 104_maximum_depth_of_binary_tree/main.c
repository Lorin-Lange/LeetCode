////////////////////////////////////////////////////
//                    LeetCode                    //
//       104. Maximum Depth of Binary Tree        //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////


#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
    if(root == NULL) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    int max = l > r ? l : r;
    return 1 + max;
}

int main() {
    return EXIT_SUCCESS;
}