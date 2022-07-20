/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool next = false;
    TreeNode* successor = NULL;
    void inorder(TreeNode* root, TreeNode* p)
    {
        if(root == NULL) return;
        inorder(root->left, p);
        if(next == true and successor == NULL) successor = root;
        if(root == p) next = true;
        inorder(root->right, p);
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inorder(root, p);
        if(next) return successor; else return NULL;
    }
};