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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* curr = head;
        ListNode* sentinel = new ListNode(INT_MIN);
        ListNode* prev = sentinel;
        sentinel->next = head;
        while(curr)
        {
            if(curr->val == prev->val)
                prev->next = curr->next;
            else
                prev = curr;
            curr = curr->next;
        }
        return sentinel->next;
    }
};