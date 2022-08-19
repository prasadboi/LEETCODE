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
    ListNode* reverse(ListNode* head)
    {
        ListNode* iter = head, *prev = NULL, *real_next;
        while(iter)
        {
            real_next = iter->next;
            iter->next = prev;
            prev = iter;
            iter = real_next;
        }
        return prev;
    }
    
    
    ListNode* plusOne(ListNode* head) {
        head = reverse(head);
        ListNode* iter = head, *prev = NULL;
        int c = 1;
        while(iter)
        {
            iter->val += c;
            c = iter->val/10;
            iter->val = iter->val%10;
            prev = iter;
            iter = iter->next;
            if(c == 0) break;
        }
        if(c == 1) prev->next = new ListNode(c);
        return reverse(head);
    }
};