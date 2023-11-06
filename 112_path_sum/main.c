////////////////////////////////////////////////////
//                    LeetCode                    //
//                 112. Path Sum                  //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL) return false;
    int sum = targetSum - root->val;
    if(sum == 0 && root->left == NULL && root->right == NULL) return true;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

int main() {
    return EXIT_SUCCESS;
}