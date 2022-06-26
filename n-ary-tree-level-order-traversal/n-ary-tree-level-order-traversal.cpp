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
    #define vvi vector<vi>
    vector<vector<int>> levelOrder(Node* root) 
    {
        vvi res;
        queue<Node*> q;
        if(root == NULL) return {};
        q.push(root);
        while(!q.empty())
        {
            int k = q.size();
            vi level;
            for(int i = 0; i < k; i++){
                Node* u = q.front();
                level.push_back(u->val);
                q.pop();
                for(auto i : u->children){
                    q.push(i);
                }
            }    
            res.push_back(level);
        }
        return res;
    }
};