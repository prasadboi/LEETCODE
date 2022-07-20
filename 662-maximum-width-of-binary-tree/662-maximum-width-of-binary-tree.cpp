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
    #define ull unsigned long long
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        ull res = 0;
        queue<pair<TreeNode*, ull>> q;
        q.push({root, 1});
        while(q.size()){
            ull k = q.size();
            ull l = q.front().second, r = q.front().second;
            for(auto i = 0; i < k; i++)
            {
                TreeNode* u = q.front().first; r = q.front().second; 
                q.pop();
                if(u->left) q.push({u->left, 2*r});
                if(u->right) q.push({u->right, 2*r+1});
            }
            res = max(res, (ull)r - l + 1);
        }
        return (int)res;
    }
};