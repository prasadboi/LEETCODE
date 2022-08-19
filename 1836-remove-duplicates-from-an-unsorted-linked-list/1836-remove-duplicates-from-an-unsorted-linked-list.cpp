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
    #define umap unordered_map
    
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        umap<int, int> count;
        ListNode* sentinel = new ListNode(0);
        ListNode* sentinelHead = sentinel;
        ListNode* temp;

        for (temp = head; temp != nullptr; temp = temp->next)
        {
            if (count.find(temp->val) != count.end())
            {
                count[temp->val]++;
            } else {
                count[temp->val] = 1;
            }
        }

        for (temp = head; temp != nullptr; temp = temp->next)
        {
            if (count[temp->val] == 1)
            {
                sentinel->next = temp;
                sentinel = sentinel->next;
            } 
        }
        sentinel->next = nullptr;  
        return sentinelHead->next;
    }
};