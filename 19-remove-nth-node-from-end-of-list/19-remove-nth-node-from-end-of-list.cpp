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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int ctr = 0;
        ListNode* iter = head;
        while(iter != NULL and ctr < n){
            iter = iter->next;
            ctr++;
        }
        ListNode* NthNode = head;
        if(iter == NULL and ctr == n) return head->next;
        else if(iter == NULL) return head;
        while(iter->next != NULL) NthNode = NthNode->next, iter = iter = iter->next;
        NthNode->next = NthNode->next->next;
        return head;
    }
};