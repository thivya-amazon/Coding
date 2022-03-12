/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Create clone nodes and insert them after original nodes
        if(head == NULL)
            return NULL;
        Node* curr = head;
        while(curr)
        {
            Node* cloneNode = new Node(curr->val);
            Node* succ = curr->next;
            cloneNode->next = curr->next;
            curr->next = cloneNode;
            curr = succ;
        }
        
        //Populate random pointers
        curr = head;
        while(curr)
        {
            Node* cloneNode = curr->next;
            if(curr->random)
            {
                cloneNode->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        //Extract clone nodes
        curr = head;
        Node* cloneHead = head->next;
        Node* clonePtr = cloneHead;
        while(curr)
        {    
            curr->next = curr->next->next;
            clonePtr->next = (clonePtr->next != NULL) ? clonePtr->next->next : NULL;
            clonePtr = clonePtr->next;
            curr = curr->next;
        }

        return cloneHead;
    }
};