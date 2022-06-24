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
    int res;
    bool isUni(TreeNode* root)
    {
        if(root->left == NULL and root->right == NULL){res++; return true;}
        bool is_unival = true;
        
        if(root->left)
            is_unival = isUni(root->left) and is_unival and (root->left->val == root->val);

        if(root->right)
            is_unival = isUni(root->right) and is_unival and (root->right->val == root->val);
        
        if(is_unival){res++; return true;}
        else return false;
    }
    
    int countUnivalSubtrees(TreeNode* root) 
    {
        if(root == NULL) return 0;
        res = 0;
        isUni(root);
        return res;
    }
};