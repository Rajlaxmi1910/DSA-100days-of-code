/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    // Base case
    if (root == NULL || root->val == val) {
        return root;
    }

    // If value is smaller, search in left subtree
    if (val < root->val) {
        return searchBST(root->left, val);
    }
    
    // If value is greater, search in right subtree
    return searchBST(root->right, val);
}