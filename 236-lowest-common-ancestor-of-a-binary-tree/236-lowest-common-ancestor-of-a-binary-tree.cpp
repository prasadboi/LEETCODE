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
    TreeNode* res;
    bool LCA(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == NULL) return false;
        bool lflag = LCA(root->left, p, q);
        bool rflag = LCA(root->right, p, q);
        bool rootflag = (root == p or root == q);
        if(lflag + rflag + rootflag >= 2) res = root;
        return rootflag or rflag or lflag;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        res = new TreeNode();
        bool flag = LCA(root, p, q);
        if(flag) return res; else return NULL;
    }
};