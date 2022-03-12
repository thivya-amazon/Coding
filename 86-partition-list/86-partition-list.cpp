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
    ListNode* partition(ListNode* head, int x) {
        ListNode* sentinel = new ListNode(INT_MIN, NULL);
        ListNode* tail = sentinel;
        ListNode* greater = NULL;
        ListNode* greaterHead = NULL;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* succ = curr->next;
            curr->next = NULL;
            if(curr->val < x)
            {
                tail->next = curr;
                tail = curr;
            }
            else
            {
                if(!greater)
                {
                    greaterHead = curr;
                    greater = curr;
                }
                else
                {
                    greater->next = curr;
                    greater = curr;
                }
            }
            curr = succ;
        }
        tail->next = greaterHead;
        return sentinel->next;
        
    }
};