#include <stdio.h>
#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
int isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    if (t1 == NULL && t2 == NULL) return 1;
    if (t1 == NULL || t2 == NULL) return 0;

    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}
int isSymmetric(struct TreeNode* root) {
    if (root == NULL) return 1;
    return isMirror(root->left, root->right);
}