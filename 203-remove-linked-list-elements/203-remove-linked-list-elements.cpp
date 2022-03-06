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
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr)
        {
            if(curr->val == val)
            {
                ListNode* temp = curr;
                if(!prev)
                {
                    curr = curr->next;
                    head = curr;
                }
                else
                {
                    prev->next = curr->next;
                    curr = curr->next;
                }
                delete(temp);
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
               
        }
        return head;
    }
};