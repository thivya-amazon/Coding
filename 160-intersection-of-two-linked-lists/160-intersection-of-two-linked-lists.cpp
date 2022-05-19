/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        while(ptrA && ptrB)
        {
            if(ptrA == ptrB)
                return ptrA;
            
            ptrA = ptrA->next;
            ptrB = ptrB->next;
            
            if(ptrA != NULL && ptrB == NULL)
                ptrB = headA;
            if(ptrA == NULL && ptrB != NULL)
                ptrA = headB;
            if(ptrA == NULL && ptrB == NULL)
                break;            
        }
        return NULL;
    }
};