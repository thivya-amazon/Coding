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
    ListNode* reverseKNodes(ListNode* head, int k)
    {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr && k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = right - left + 1;
        ListNode* sentinel = new ListNode(INT_MIN, head);
        ListNode* prev = sentinel;
        ListNode* listHead = sentinel;
        while(listHead != NULL && left > 0)
        {
            prev = listHead;
            listHead = listHead->next;
            left--;
        }
        ListNode* tailLink = listHead;
        int k = 0;
        while(tailLink && k < count)
        {
            tailLink = tailLink->next;
            k++;
        }
        ListNode* revHead = reverseKNodes(listHead, count);
        prev->next = revHead;
        listHead->next = tailLink;
        
        return sentinel->next;
        
    }
};