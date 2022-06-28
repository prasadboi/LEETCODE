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
    
    int ans;
    int ctr;
    bool inorder(TreeNode* root, int k)
    {
        if(root == NULL) return false;
        if(inorder(root->left, k)) return true;
        ctr++;
        // cout<<"at node :"<<root->val<<" with k = "<<k<<endl;
        if(ctr == k){ans = root->val; return true;}
        if(inorder(root->right, k)) return true;
        return false;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        ans = -1;
        bool flag = inorder(root, k);
        // cout<<"--------------------------\n";
        return ans;
    }
};