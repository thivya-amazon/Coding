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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        ListNode* sentinel = new ListNode(INT_MIN, head);
        ListNode* pred = sentinel;
        ListNode* curr = head;
        ListNode* temp = NULL;
        while(curr)
        {
            if(curr->val == val)
            {
                temp = curr;
                pred->next = curr->next;
            }
            else
            {
                pred = curr;
            }
            curr = curr->next;
            if(temp)
            {
                delete(temp);
                temp = NULL;
            }
                
        }
        return sentinel->next;
    }
};