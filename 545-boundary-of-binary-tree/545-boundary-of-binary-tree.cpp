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
    #define ll long long int
    #define umap unordered_map
    vector<TreeNode*> leaves;
    void dfs(TreeNode* root)
    {
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL) leaves.push_back(root);
        if(root->left) dfs(root->left);
        if(root->right) dfs(root->right);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == NULL) return {};
        if(root->left == NULL and root->right == NULL) return {root->val};
        vector<TreeNode*> LB, RB;
        deque<TreeNode*> q;
        umap<TreeNode*, TreeNode*> parent;
        
        vi res; res.push_back(root->val);
        
        // level order traversal of sorts
        if(root->left) {q.push_back(root->left); parent[root->left] = root; LB.push_back(root->left);}
        if(root->right) {q.push_back(root->right); parent[root->right] = root; RB.push_back(root->right);}
        
        
        while(!q.empty())
        {
            TreeNode *l = q.front(), *r = q.back();
            // cout<<"l = "<<l->val<<", r = "<<r->val<<", parents = "<<parent[l]->val<<","<<parent[r]->val<<endl;
            if(parent.count(l) > 0 and LB.size() and LB.back() == parent[l]){
                if(l->left or l->right)LB.push_back(l);
            }
            if((LB.size() and LB.back() != r) or LB.size() == 0){
                if(parent.count(r) > 0 and RB.size() and RB.back() == parent[r]){
                    if(r->left or r->right) RB.push_back(r);
                }
            }
            
            int k = q.size();
            for(auto i = 0; i < k; i++)
            {
                TreeNode *u = q.front(); q.pop_front();
                // cout<<"at node : "<<u->val<<endl;
                if(u->left){
                    parent[u->left] = u; q.push_back(u->left);
                }
                if(u->right){
                    parent[u->right] = u; q.push_back(u->right);
                }
            }
        }
        dfs(root);
        if(LB.size() and LB.back() == leaves.front()) leaves.erase(leaves.begin());
        if(RB.size() and RB.back() == leaves.back()) leaves.pop_back();
        
        reverse(RB.begin(), RB.end());
        for(auto i : LB){res.push_back(i->val);}
        for(auto i : leaves) {res.push_back(i->val);}
        for(auto i : RB) {res.push_back(i->val);}
            
        return res;
    }
};