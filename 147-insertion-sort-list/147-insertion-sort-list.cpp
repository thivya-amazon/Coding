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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sentinel = new ListNode(INT_MIN, NULL);
        ListNode* pred = sentinel;
        ListNode* curr = head;
        ListNode* succ = NULL;
        while(curr)
        {
            //Extract the node from the list
            succ = curr->next;
            curr->next = NULL;
            
            //Insert the node into sorted list
            pred = sentinel;
            ListNode* curr2 = sentinel->next;
            
            while(curr2 && curr->val > curr2->val)
            {
                pred = curr2;
                curr2= curr2->next;
            }
            pred->next = curr;
            curr->next = curr2;
            
            //Increment curr node in original list
            curr = succ;
                        
        }
        return sentinel->next;
        
    }
};