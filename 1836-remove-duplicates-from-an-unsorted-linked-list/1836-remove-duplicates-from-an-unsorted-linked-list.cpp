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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        if(head == NULL)
            return NULL;
        unordered_map<int, int> umap;
        ListNode* curr = head;
        //Push all calues into a map along with their frequencies
        while(curr)
        {
            umap[curr->val]++;
            curr = curr->next;
        }
        curr = head;
        ListNode* sentinel = new ListNode(INT_MIN, head);
        ListNode* pred = sentinel;
        while(curr)
        {
            if(umap[curr->val] > 1)
            {
                pred->next = curr->next;
            }
            else
            {
                pred = curr;
            }
            curr = curr->next;
        }
        return sentinel->next;
    }
};