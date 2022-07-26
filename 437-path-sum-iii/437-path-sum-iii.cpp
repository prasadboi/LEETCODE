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
#define ll long long int 
class Solution {
public:
    ll dfs1(TreeNode* root, ll target)
    {
        if(root == NULL) return 0;
        target -= root->val;
        // cout<<"at node : "<<root->val<<",  the updated target val is : "<<target<<endl;
        return dfs1(root->left, target) + dfs1(root->right, target) + (int)(target == 0);
    }
    
    ll dfs2(TreeNode* root, ll target)
    {
        if(root == NULL) return 0;
        ll res = 0;
        res += dfs1(root, target);
        return res + dfs2(root->left, target) + dfs2(root->right, target);
    }
    
    int pathSum(TreeNode* root, int target) {
        return (int)dfs2(root, (ll)target);
    }
};