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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* sentinel = new ListNode(INT_MIN, head);
        ListNode* pred = sentinel;
        
        ListNode* curr = head;
        while(curr && curr->next)
        {
            ListNode* node1 = curr;
            ListNode* node2 = curr->next;
            
            pred->next = node2;
            node1->next = node2->next;
            node2->next = node1;        
            
            pred = node1;
            curr = node1->next;
        }
        return sentinel->next;
        
    }
};