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
/*
// using O(n) space
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

*/


class Solution {
#define umap unordered_map
#define ll long long int
#define vll vector<ll>
public:
    Node* copyRandomList(Node* head) {
        // make the head point to the new node and store the next elsewhere
        if(head == NULL) return NULL;
        Node* iter = head, *real_next = NULL;
        while(iter)
        {
            real_next = iter->next;
            
            Node* newNode = new Node(iter->val);
            newNode->random = iter->random;
            newNode->next = iter->next;
            
            iter->next = newNode;
            iter = real_next;
        }
        
        // make the radomn pointers point to the new nodes
        Node* hcpy = head->next, *i = NULL, *j = NULL;
        for(i = head->next; i != NULL and i->next != NULL; i = i->next->next){
            if(i->random) i->random = i->random->next;
        }
        if(i and i->random) i->random = i->random->next;
            
        // restore the original list and connect the new nodes        
        for(i = head, j = head->next; j and j->next;)
        {
            Node* nxt = j->next;
            j->next = nxt->next;
            i->next = nxt;
            i = i->next, j = j->next;
        }
        i->next = NULL;
        return hcpy;
    }
};