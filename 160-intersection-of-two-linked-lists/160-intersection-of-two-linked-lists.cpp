/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL)
            return NULL;
        if(headB == NULL)
            return NULL;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        
        int m = 0;
        int n = 0;
        
        while(curr1)
        {
            curr1 = curr1->next;
            m++;
        }
        
        while(curr2)
        {
            curr2 = curr2->next;
            n++;
        }
        
        curr1 = headA;
        curr2 = headB;
        if(m > n)
        {
            while(curr1)
            {
                curr1 = curr1->next;
                m--;
                if(m == n)
                {
                    while(m > 0)
                    {
                        if(curr1 == curr2)
                            return curr1;
                        else
                        {
                            curr1 = curr1->next;
                            curr2 = curr2->next;
                            m--;
                            n--;
                        }
                    }
                }

            }
        }
        else if(n > m)
        {
            while(curr2)
            {
                curr2 = curr2->next;
                n--;
                if(m == n)
                {
                    while(n > 0)
                    {
                        if(curr1 == curr2)
                            return curr1;
                        else
                        {
                            curr1 = curr1->next;
                            curr2 = curr2->next;
                            m--;
                            n--;
                        }
                    }
                }

            }
        }
        else
        {
            cout << m << "," << n << endl;
            while(n > 0)
            {
                if(curr1 == curr2)
                    return curr1;
                else
                {
                    curr1 = curr1->next;
                    curr2 = curr2->next;
                    m--;
                    n--;
                }
            }
        }
        
       return NULL; 
    }
};