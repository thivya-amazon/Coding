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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        // if(head == NULL)
        //     return result;
        ListNode* curr = head;
        int count = 0;
        int fixedSize = 0;
        int varSize = 0;
        while(curr)
        {
            curr = curr->next;
            count++;
        }
        fixedSize = count / k;
        varSize = count % k;
        
        curr = head;
        for(int i = 0; i < k; i++)
        {
            ListNode* partHead = curr;
            for(int j = 0; j < (fixedSize + (i < varSize ? 1 : 0))-1; j++)
            {
                curr = curr->next;
            }
            if(curr)
            {
                ListNode* temp = curr->next;
                curr->next = NULL;
                curr = temp;               
            }
            result.push_back(partHead);
        }
       return result; 

    }
};