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
        ListNode* prev = NULL;
        while(curr && curr->next)
        {
            ListNode* succ = curr->next;
            if(curr->val == succ->val)
                curr->next = succ->next;
            else
                curr = curr->next;
        }
        return head;
    }
};