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
    #define umap unordered_map
    #define vi vector<int>
    #define vll vector<ll>
    
    ll ctr = 0;
    ll res = 0;
    ll k = 0; // the kth index
    // inorder(root) returns whether the kth element has been found or not
    // once we have reached k we just dont do any update to res. simple
    bool inorder(TreeNode* root)
    {
        if(root == NULL) return false;
        if(inorder(root->left) == true) return true;
        ctr++;
        if(ctr == k){
            res = root->val; return true;
        }
        if(inorder(root->right) == true) return true;
        return false;
    }
    int kthSmallest(TreeNode* root, int K) {
        k = K;
        bool foundKthLargest = inorder(root);
        if(foundKthLargest) return res; else return -1;
    }
};