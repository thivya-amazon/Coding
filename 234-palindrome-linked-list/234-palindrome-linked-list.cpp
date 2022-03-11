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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next)
            slow = slow->next;
        return slow;
    }
    
      ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        bool result = true;
        if(head == NULL || head->next == NULL)
            return result;
        ListNode* temp1 = head;
        ListNode* mid = findMiddle(temp1);
        ListNode* head2 = reverseList(mid);
        
        ListNode* temp = head2;
        while(temp != NULL)
        {
            if(head->val != temp->val)
            {
                result = false;
                break;
            }                
            head = head->next;
            temp = temp->next;
        }
        
        ListNode* curr = head;
        while(curr)
        {
            cout << curr->val << "";
            cout << endl;
            curr = curr->next;
        }
        
        return result;
        
    }
};