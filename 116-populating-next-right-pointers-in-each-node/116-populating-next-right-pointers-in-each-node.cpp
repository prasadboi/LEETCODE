/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // bfs approach
    Node* bfs(Node* root)
    {
        if(root == NULL) return NULL;
        
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int k = q.size();
            Node* u = q.front(); q.pop();
            if(u->left) q.push(u->left);
            if(u->right) q.push(u->right);
            
            for(int i = 0; i < k-1; i++){
                u->next = q.front();
                u = q.front();
                q.pop();
                if(u->left) q.push(u->left);
                if(u->right) q.push(u->right);
            }
        }
        return root;
    }
    
    Node* connect(Node* root) 
    {
         return bfs(root);
    }
};