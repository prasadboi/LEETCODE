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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry = 0;
        ListNode *iter = new ListNode();
        ListNode*head = iter, *prev = NULL;
        while(l1 and l2)
        {
            iter->val = (l1->val + l2->val + carry)%10;
            carry = (l1->val + l2->val + carry)/10;
            l1 = l1->next;
            l2 = l2->next;
            iter->next = new ListNode();
            prev = iter;
            iter = iter->next;
        }
        while(l1)
        {
            iter->val = (l1->val + carry)%10;
            carry = (l1->val + carry)/10;
            iter->next = new ListNode();
            prev = iter;
            l1 = l1->next;
            iter = iter->next;
        }
        while(l2)
        {
            iter->val = (l2->val + carry)%10;
            carry = (l2->val + carry)/10;
            iter->next = new ListNode();
            prev = iter;
            l2 = l2->next;
            iter = iter->next;
        }
        if(iter->val == 0 and carry == 0) prev->next = NULL;
        else if(iter->val == 0 and carry) iter->val = carry;
        return head;
    }
};