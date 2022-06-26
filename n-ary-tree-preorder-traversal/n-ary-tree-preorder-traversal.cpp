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

class Solution {
public:
    #define vi vector<int>
    
    vector<int> preorder(Node* root) 
    {
        vi res;
        if(root == NULL) return res;
        res.push_back(root->val);
        for(auto i : root->children){
            vi temp = preorder(i);
            res.insert(res.end(), temp.begin(), temp.end());
        }
        return res;
    }
};