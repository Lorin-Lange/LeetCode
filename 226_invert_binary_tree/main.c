////////////////////////////////////////////////////
//                    LeetCode                    //
//            226. Invert Binary Tree             //
//            Solution by Lorin Lange             //
////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* invertTree(struct TreeNode* root) {
    if(root == NULL) return NULL;
    struct TreeNode* left = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(left);
    return root;
}

int main() {
    return EXIT_SUCCESS;
}