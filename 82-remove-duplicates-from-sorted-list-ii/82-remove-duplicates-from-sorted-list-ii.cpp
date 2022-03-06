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
        ListNode* sentinel = new ListNode(INT_MIN);
        ListNode* prev = sentinel;
        sentinel->next = head;
        ListNode* curr = head;
        while(curr)
        {
            ListNode* succ = curr->next;
            if(succ && curr->val == succ->val)
            {
                ListNode* ptr = succ;
                while(ptr && ptr->val == curr->val)
                    ptr = ptr->next;
                prev->next = ptr;
                curr = ptr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return sentinel->next;
    }
};