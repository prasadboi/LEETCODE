/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if(root == NULL) return NULL;
        TreeNode* u = new TreeNode(root->val);
        if(root->children.size() == 0) return u;
        
        u->left = encode(root->children[0]);
        TreeNode* child = u->left;
        for(int i = 1; i < root->children.size(); i++){
            child->right = encode(root->children[i]);
            child = child->right;
        }
        return u;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) 
    {
        if(root == NULL) return NULL;
        Node* u = new Node(root->val);
        TreeNode* v = root->left;
        while(v){
            u->children.push_back(decode(v));
            v=  v->right;
        }
        return u;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));