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
        ListNode* sentinel = new ListNode(INT_MIN, head);
        ListNode* pred = sentinel;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* succ = curr->next;
            while(succ && succ->val == curr->val)
            {
                succ = succ->next;
            }
            curr->next = succ;
            curr = succ;
        }
        
        return sentinel->next;
    }
};