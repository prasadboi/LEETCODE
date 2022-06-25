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
    
    TreeNode* bt(vi pre, vi in)
    {
        if(pre.size() == 0) return NULL;
        TreeNode* root = new TreeNode(pre[0]);
        // cout<<"at node = "<<root->val<<endl;
        // for(auto x : pre) cout<<x<<" "; cout<<endl;
        // for(auto x : in) cout<<x<<" "; cout<<endl;
        
        if(pre.size() == 1) return root;
        
        int i = 0;
        for(; i < in.size(); i++) if(in[i] == root->val) break;
        vi pl(pre.begin()+1, pre.begin()+i+1);
        vi pr(pre.begin()+i+1, pre.end());
        vi il(in.begin(), in.begin() + i + 1);
        vi ir(in.begin() + i + 1, in.end());  
        
        root->left = bt(pl, il);
        root->right = bt(pr, ir);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        TreeNode* root = bt(preorder, inorder);
        // cout<<"------------\n";
        return root;
    }
};