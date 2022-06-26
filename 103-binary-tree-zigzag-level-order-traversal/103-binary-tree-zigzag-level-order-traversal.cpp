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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        queue<TreeNode*> q;
        
        vector<vector<int>> res;
        
        if(root == NULL) return {};
        q.push(root);
        bool flag = false;
        
        while(!q.empty()){
            int k = q.size();
            vector<int> temp;
            flag = (flag + 1)%2;
            for(int i = 0; i < k; i++)
            {
                TreeNode* u = q.front();
                if(flag) temp.push_back(u->val);
                else temp.insert(temp.begin(), u->val);
                q.pop();
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};