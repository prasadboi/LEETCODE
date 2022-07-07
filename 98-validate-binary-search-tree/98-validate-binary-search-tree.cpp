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
    TreeNode* prev;
    bool validate(TreeNode* node)
    {
        if(node == NULL) return true;
        if(!validate(node->left)) return false;
        if(prev != NULL and (prev->val >= node->val)) return false;
        prev = node;
        return validate(node->right);
    }
    bool isValidBST(TreeNode* root) {
        prev=NULL;
        return validate(root);
    }
};


