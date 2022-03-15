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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode* sentinel = new ListNode(INT_MIN, head);
        ListNode* pred = sentinel;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next)
        {
            pred = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // ListNode* current = head;
        // while(current->next != slow && current->next != NULL)
        //     current = current->next;
        // current->next = slow->next;
        pred->next = slow->next;
        return sentinel->next;
    }
};