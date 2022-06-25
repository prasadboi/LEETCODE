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
    int ctr;
    
    int FindAll(TreeNode* i, ll target)
    {
        if(!i) return 0;
        target -= i->val;
        int ans = 0;
        if(target == 0) ans++;
        ans += FindAll(i->left, target);
        ans += FindAll(i->right, target);
        return ans;
    }
    
    void preorder(TreeNode* i, ll target)
    {
        if(i == NULL) return;
        preorder(i->left, target);
        preorder(i->right, target);
        ctr += FindAll(i, target);
    }
    
    int pathSum(TreeNode* root, int targetSum) 
    {
        ctr = 0;
        preorder(root, targetSum);
        return ctr;
    }
};