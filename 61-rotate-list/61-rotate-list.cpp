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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* newHead = NULL;
        ListNode* curr = head;
        int count = 1;
        if(!curr || curr->next == NULL || k == 0)
            return curr;
        while(curr->next)
        {
            curr = curr->next;
            count++;
        }
        //Make it a circular list
        curr->next = head;
    
        ListNode* newTail = head;
        for(int i = 0; i < count - k % count-1; i++)
        {
            newTail = newTail->next;
        }
        newHead = newTail->next;
        
        //Break the ring
        newTail->next = NULL;
        ListNode* curr2 = newHead;

        return newHead;
    }
};