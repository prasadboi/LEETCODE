/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool checkSym(TreeNode* l, TreeNode* r)
    {
        if(l == NULL and r == NULL) return true;
        else if(l == NULL or r == NULL) return false;
        if(l->val != r->val)  return false;
        return checkSym(l->right, r->left) and checkSym(l->left, r->right);
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        return checkSym(root, root);
    }
};