/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> newNodeList;
    void dfs(Node* node, Node** copy, vector<bool> &visited)
    {
        visited[node->val] = true;
        newNodeList[node->val] = (*copy);
        
        for(auto i : node->neighbors)
        {
            Node* newNode = new Node(i->val);
            if(visited[i->val]){
                (*copy)->neighbors.push_back(newNodeList[i->val]);
            }
            else
            {
                (*copy)->neighbors.push_back(newNode);
                dfs(i, &newNode, visited);
            }
        }
    }
    
    Node* cloneGraph(Node* node) 
    {
        if(node == NULL) return NULL;
        Node* newGraphHead = new Node(node->val);
        vector<bool> visited(100, false);
        dfs(node, &newGraphHead, visited);
        return newGraphHead;
    }
};