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
    #define vi vector<int>
    
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vi res;
        if(root == NULL) return res;
        res.push_back(root->val);
        vi l = preorderTraversal(root->left);
        vi r = preorderTraversal(root->right);
        res.insert(res.end(), l.begin(), l.end());
        res.insert(res.end(), r.begin(), r.end());
        return res;
    }
};