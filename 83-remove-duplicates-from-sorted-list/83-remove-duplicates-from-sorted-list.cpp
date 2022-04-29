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
            ListNode* succ = curr->next;

            while(succ && curr->val == succ->val)
            {
                ListNode* temp = succ;
                succ = succ->next; 
                delete(temp);
            }
            curr->next = succ;
            prev = curr;
            curr = curr->next;
        }
        return sentinel->next;
    }
};