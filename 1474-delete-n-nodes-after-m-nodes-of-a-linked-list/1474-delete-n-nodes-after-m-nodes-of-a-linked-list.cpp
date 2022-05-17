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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* sentinel = new ListNode(INT_MIN);
        sentinel->next = head;
        ListNode* prev = sentinel;
        ListNode* curr = head;
        while(curr)
        {
            int keepCount = 0;
            while(curr && keepCount < m)
            {
                prev = curr;
                curr = curr->next;
                keepCount++;
            }
            int delCount = 0;
            while(curr && delCount < n)
            {
                ListNode* temp = curr;
                curr = curr->next;
                delCount++;
                delete(temp);
            }
            prev->next = curr;
        }
        return sentinel->next;
    }
};