/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* root = new PolyNode(INT_MAX, INT_MAX);
        PolyNode* head = root;
        PolyNode *iter1 = poly1, *iter2 = poly2;
        while(iter1 and iter2)
        {
            if(iter1->power > iter2->power) root->next = iter1, iter1 = iter1->next, root = root->next;
            else if(iter2->power > iter1->power) root->next = iter2, iter2 = iter2->next, root = root->next;
            else{
                if(iter1->coefficient + iter2->coefficient != 0){
                    root->next = new PolyNode(iter1->coefficient + iter2->coefficient, iter1->power);
                    iter1 = iter1->next, iter2 = iter2->next, root = root->next;
                }
                else{
                    iter1 = iter1->next, iter2 = iter2->next;
                }
            }
        }
        while(iter1) root->next = iter1, iter1 = iter1->next, root = root->next;
        while(iter2) root->next = iter2, iter2 = iter2->next, root = root->next;
        root->next = NULL;
        return head->next;
    }
};