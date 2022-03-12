/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(head == NULL)
        {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        
        Node* prev = head;
        Node* curr = head->next;
        
        do{
            //Case 1 : Insert value is within the list's range
            if(prev->val <= insertVal && insertVal <= curr->val)
            {
                Node* newNode = new Node(insertVal, curr);
                prev->next = newNode;
                return head;
            }
            //Case 2: Insert value is out of list's range
            else if(prev->val > curr->val)  //this is the tail node
            {
                if(insertVal >= prev->val || insertVal <= curr->val)
                {
                    Node* newNode = new Node(insertVal, curr);
                    prev->next = newNode;
                    return head;
                }
            }
            
            prev = curr;
            curr = curr->next;
        }while(prev != head);
            
        //Case 3: After a full cycle, none of the above conditions were satisfied. The list contains                 //duplicates. So, insert it anywhere.
            prev->next = new Node(insertVal, curr);
        
        return head;
        
    }
};