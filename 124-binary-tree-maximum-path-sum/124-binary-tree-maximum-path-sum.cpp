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
    #define ll long long int
    
    unordered_map<TreeNode*, ll> dp;
    
    void mpsFromRoot(TreeNode* i, ll &maxSum, ll curr)
    {
        if(i == NULL) return;
        curr += i->val;
        maxSum = max(maxSum, curr);
        mpsFromRoot(i->left, maxSum, curr);
        mpsFromRoot(i->right, maxSum, curr);
    }
    
    int maxPathSum(TreeNode* root) 
    {
        if(root == NULL) return 0;
        if(dp.find(root) != dp.end()) return dp[root];
        
        ll x = root->val, l = INT_MIN, r = INT_MIN;
        if(root->left) l = maxPathSum(root->left);
        if(root->right) r = maxPathSum(root->right);
        
        ll xl = INT_MIN, xr = INT_MIN;
        mpsFromRoot(root->left, xl, 0); mpsFromRoot(root->right, xr, 0);
        if(xl != INT_MIN) x += max((ll)0,xl);
        if(xr != INT_MIN) x += max((ll)0, xr);
        
        dp[root] = max(max(x, l), r);
        return dp[root];
    }
};