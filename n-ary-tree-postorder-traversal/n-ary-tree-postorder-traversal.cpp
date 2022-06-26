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
    vector<int> postorder(Node* root) {
        vi res;
        if(root == NULL) return res;
        for(auto i : root->children){
            vi temp = postorder(i);
            res.insert(res.end(), temp.begin(), temp.end());
        }
        res.push_back(root->val);
        return res;
    }
};