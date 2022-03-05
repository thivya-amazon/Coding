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
   ListNode* reverseKNodes(ListNode* head, int k)
   {
       ListNode* prev = NULL;
       ListNode* curr = head;
       ListNode* next = NULL;
       while(curr && k)
       {
           next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = next;
           k--;
       }
       return prev;
   }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode* newHead = NULL;
        ListNode* curr = head;
        ListNode* tail = NULL;
        while(curr)
        {
            int count = 0;
            while(curr && count < k)
            {
                curr = curr->next;
                count++;
            }
            
            if(count == k)
            {
                ListNode* revHead = reverseKNodes(head, k);
                if(!newHead)
                    newHead = revHead;
                if(tail != NULL)
                    tail->next = revHead;
                tail = head;
                head = curr;
            }
        }
        if(tail)
            tail->next = head;
        
        return newHead ? newHead : head;
    }
};