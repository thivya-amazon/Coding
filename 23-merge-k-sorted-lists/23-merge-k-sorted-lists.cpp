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
    struct compare{
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val;   
        }                 
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* sentinel = new ListNode(INT_MIN, NULL);
        ListNode* tail = sentinel;
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i])
                pq.push(lists[i]);
        }
        while(!pq.empty())
        {
            ListNode* minNode = pq.top();
            pq.pop();
            tail->next = minNode;
            tail = tail->next;
            if(minNode->next)
            {
                pq.push(minNode->next);
            }
        }
        return sentinel->next;
    }
};