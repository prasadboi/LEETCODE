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
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> s;
        if(root == NULL) return {};
        vi res;
        
        s.push(root); 
        bool lflag = false;
        while(!s.empty())
        {
            TreeNode* i = s.top();
            cout<<"i is "<<i->val<<endl;
            if(i->left and lflag == false){
                while(i->left){s.push(i->left); i = i->left;}
            }
            else{
                lflag = true;
                cout<<"i pushed is "<<i->val<<endl;
                res.push_back(i->val);
                s.pop();
                if(i->right != NULL){s.push(i->right); lflag = false;}
            }
        }
        return res;
    }
};