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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root == NULL) return {};
        vi res, l, r;
        l = postorderTraversal(root->left);
        r = postorderTraversal(root->right);
        res.insert(res.end(), l.begin(), l.end());
        res.insert(res.end(), r.begin(), r.end());
        res.push_back(root->val);
        return res;
    }
};