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
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if(head1 == NULL)
            return head2;
        if(head2 == NULL)
            return head1;
        ListNode* sentinel = new ListNode(INT_MIN);
        ListNode* sortedList = sentinel;
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val < head2->val)
            {
                sortedList->next = head1;
                head1 = head1->next;
            }
            else
            {
                sortedList->next = head2;
                head2 = head2->next;
            }
            sortedList = sortedList->next;    
        }
        if(head1)
            sortedList->next = head1;
        else
            sortedList->next = head2;
        return sentinel->next;
    }
    ListNode* findMiddle(ListNode* head)
    {
        if(head == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // if(fast->next)
        //     slow = slow->next;
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        if(head ->next == NULL)
            return head;
        ListNode* mid = findMiddle(head);
        ListNode* list2 = mid->next;
        mid->next = NULL;
        ListNode* head1 = sortList(head);
        ListNode* head2 = sortList(list2);
        return merge(head1, head2);
        
    }
};