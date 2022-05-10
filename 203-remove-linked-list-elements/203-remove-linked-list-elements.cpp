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
       ListNode* sentinel = new ListNode(INT_MIN, head);
        ListNode* prev = sentinel;
        ListNode* curr = head;
        ListNode* temp = NULL;
        while(curr)
        {
            if(val == curr->val)
            {
                temp = curr;
                prev->next = curr->next;
            }
            else
                prev = curr;
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