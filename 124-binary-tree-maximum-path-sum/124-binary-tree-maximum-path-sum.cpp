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
#define umap unordered_map


class Solution {
public:
    int maxRootToLeaf(TreeNode* root){
        if(root == NULL) return 0;
        ll curr = root->val;   
        return max({(ll)0, curr, curr + maxRootToLeaf(root->left), curr + maxRootToLeaf(root->right)});
    }
    
    umap<TreeNode*, ll> dp;
    int maxPathSum(TreeNode* root) {
        // cases where the max path sum is entirely in the left or the right sub tree
        if(root == NULL) return 0;
        // cout<<"at node : "<<root->val<<endl;
        if(dp.find(root) != dp.end()) return dp[root];
        ll L = maxPathSum(root->left); // cout<<"maxpath sum left : "<<L<<endl;
        ll R = maxPathSum(root->right); // cout<<"maxpathsum right : "<<R<<endl;
        // case where the max path goes through the root
        ll u = root->val;
        // best path through given node:
        // curr =  val + largest path from root->left to leaf + largest path from root->right to leaf
        ll curr = u + max(0, maxRootToLeaf(root->left)) + max(0, maxRootToLeaf(root->right));
        return (int)(dp[root] = max({curr, (L == 0)?INT_MIN : L, (R == 0) ? INT_MIN : R}));
    }
};