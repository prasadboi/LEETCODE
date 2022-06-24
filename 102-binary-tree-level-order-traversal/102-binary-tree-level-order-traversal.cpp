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
    #define vvi vector<vector<int>>
    #define vi vector<int>
    
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        vvi res;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty())
        {
            int k = q.size();
            vi level;
            for(int i = 0; i < k; i++)
            {
                TreeNode* u = q.front(); q.pop();
                level.push_back(u->val);
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            res.push_back(level);
        }
        return res;
    }
};