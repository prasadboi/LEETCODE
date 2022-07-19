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
    #define vvi vector<vi>
    #define vb vector<bool>
    
    void dfs(TreeNode* u, int pathsum, vi temp, vvi &res, int &target)
    {
        if(u == NULL){
            return;
        }
        pathsum += u->val; temp.push_back(u->val);
        if(!u->left and !u->right and pathsum == target) res.push_back(temp);
        dfs(u->left, pathsum, temp, res, target);
        dfs(u->right, pathsum, temp, res, target);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vvi res;
        vi temp;
        dfs(root, 0, temp, res, targetSum);
        return res;
    }
};