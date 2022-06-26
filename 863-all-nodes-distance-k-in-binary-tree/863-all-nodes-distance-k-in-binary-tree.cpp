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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, bool> vis;
    
    void disK(TreeNode* root, int k, vector<int> &res)
    {
        if(root == NULL) {return;}
        vis[root] = true;
        // cout<<"at node : "<<root->val<<endl;
        if(k == 0){
            // cout<<"adding result : "<<root->val<<endl;
            res.push_back(root->val);
        }
        
        if(vis.find(root->left) == vis.end() or vis[root->left] == false)disK(root->left, k-1, res);
        if(vis.find(root->right) == vis.end() or vis[root->right] == false)disK(root->right, k-1, res);
        if((parent[root]->val != -1) and (vis.find(parent[root]) == vis.end() or vis[parent[root]] == false)) disK(parent[root], k-1, res);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == NULL) return {};
        parent[root] = new TreeNode(-1);
        q.push(root);
        while(!q.empty())
        {
            TreeNode* u = q.front();
            q.pop();
            if(u->left){
                parent[u->left] = u;
                q.push(u->left);
            }
            if(u->right)
            {
                parent[u->right] = u;
                q.push(u->right);
            }
        }
        disK(target, k, res);
        // if(res.size() and res[res.size()-1] == -1)res.pop_back();
        return res;
    }
};