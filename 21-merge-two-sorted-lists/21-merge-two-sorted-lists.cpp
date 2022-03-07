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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* SortedList = new ListNode();
        ListNode* L3 = SortedList;
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1;        
        
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val <= list2->val)
            {
                L3->next = list1;
                list1 = list1->next;                
            }
            else 
            {
                L3->next = list2;
                list2 = list2->next;               
            }
            L3 = L3->next;               
        }
        
    if(list1 == NULL) L3->next = list2;
    if(list2 == NULL) L3->next = list1;
      return SortedList->next;  
    }
};