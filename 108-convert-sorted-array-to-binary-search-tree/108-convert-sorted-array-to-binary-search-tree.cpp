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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int l = 0, r = nums.size();
        if(l == r) return NULL;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        // cout<<"making node = "<<nums[mid]<<endl;
        vector<int> nums_l(nums.begin(), nums.begin() + mid);
        vector<int> nums_r(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(nums_l);
        root->right = sortedArrayToBST(nums_r);
        return root;
    }
};