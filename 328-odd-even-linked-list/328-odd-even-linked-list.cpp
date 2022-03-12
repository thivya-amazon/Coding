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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* sentinel = new ListNode(INT_MIN);
        ListNode* even = sentinel;
        ListNode* curr = head;
        ListNode* pred = NULL;
        int index = 1;
        while(curr)
        {
            if(index % 2)
            {
                pred = curr;
            }
            else
            {
                pred->next = curr->next;
                even->next = curr;
                even = even->next;
            }
            curr = curr->next;
            index++;
        }
        even->next = NULL;
        pred->next = sentinel->next;
        return head;
        
    }
};