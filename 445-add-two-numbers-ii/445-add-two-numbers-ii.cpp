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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        //Find the count for each list
        int n1 = 0;
        int n2 = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        while(curr1->next)
        {
            n1++;
            curr1 = curr1->next;
        }
        while(curr2->next)
        {
            n2++;
            curr2 = curr2->next;
        }
        
        //Add 0s to the beginning of the shorter list
        if(n1 < n2)
        {
            int numZeros = n2 - n1;
            while(numZeros)
            {
                ListNode* zeroNode = new ListNode(0, l1);
                l1 = zeroNode;
                numZeros--;
            }
        }
        
        else if(n1 > n2)
        {
            int numZeros = n1 - n2;
            while(numZeros)
            {
                ListNode* zeroNode = new ListNode(0, l2);
                l2 = zeroNode;
                numZeros--;
            }
        }
        
        //Create a list with sum values without considering carry
        ListNode* sumHead = NULL;
        while(l1 != NULL)
        {
            int sum = l1->val + l2->val;
            ListNode* sumNode = new ListNode(sum, sumHead);
            sumHead = sumNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        curr1 = sumHead;
        sumHead = NULL;
        int carry = 0;
        while(curr1 != NULL)
        {
            int sum = (curr1->val + carry) % 10;
            carry = (curr1->val + carry) / 10;
            ListNode* sumNode = new ListNode(sum, sumHead);
            sumHead = sumNode;
            curr1 = curr1->next;
        }
        if(carry)
        {
            ListNode* carryNode = new ListNode(carry, sumHead);
            sumHead = carryNode;
        }
        return sumHead;
    }
};