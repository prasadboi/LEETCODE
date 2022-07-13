/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b){return a->val > b->val;};
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        
        for(ListNode* l : lists){
            ListNode* iter = l;
            while(iter != NULL){q.push(iter); iter = iter->next;}
        }
        cout<<q.size()<<endl;
        if(q.size() == 0) return NULL;
        
        ListNode* head = q.top(); 
        q.pop();
        ListNode* tail = head;
        while(q.size())
        {
            tail->next = q.top(); q.pop();
            tail = tail->next;
        }
        tail->next = NULL;
        return head;
    }
};