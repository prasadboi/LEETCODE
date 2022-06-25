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
    #define ull unsigned long long int
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        ull res = 0;
        queue<pair<TreeNode*, ull>> q;
        
        q.push({root, 1});
        while (!q.empty()) 
        {
            ull l = q.front().second;
            ull r = l, n = q.size();
            for (ull i = 0; i < n; i++) 
            {
                TreeNode* u = q.front().first;
                r = q.front().second;
                q.pop();
                if (u->left) q.push({u->left, r * 2});
                if (u->right) q.push({u->right, r * 2 + 1});
            }
            res = max(res, r + 1 - l);
        }
        return res;
    }
};