/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#define umap unordered_map
#define ll long long int
#define vll vector<ll>
class Solution {
    umap<Node*, Node*> M;
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *newNode;
        if(M.count(head) > 0) newNode = M[head];
        else newNode = new Node(head->val), M[head] = newNode;
        
        if(M.count(head->random) > 0) newNode->random = M[head->random];
        else{
            if(head->random) M[head->random] = new Node(head->random->val), newNode->random = M[head->random];
            else newNode->random = NULL;
        }
        newNode->next = copyRandomList(head->next);
        return newNode;
    }
};