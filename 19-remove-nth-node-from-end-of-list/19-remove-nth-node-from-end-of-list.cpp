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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* sentinel = new ListNode(INT_MIN);
        sentinel->next = head;
        ListNode* prev = NULL;
        ListNode* leader = sentinel;
        ListNode* follower = sentinel;
        int count = 0;
        while(leader && n)
        {
            leader = leader->next;
            n--;          
        }
        while(leader)
        {
            prev = follower;
            leader = leader->next;
            follower = follower->next;
        }
        ListNode* temp = follower;
        prev->next = follower->next;
        delete(temp);
        temp = NULL;
        return sentinel->next;
    }
};