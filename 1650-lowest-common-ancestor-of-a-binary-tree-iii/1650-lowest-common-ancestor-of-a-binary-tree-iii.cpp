/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* ptrP = p;
        Node* ptrQ = q;
        while(ptrP != NULL && ptrQ != NULL)
        {
            if(ptrP == ptrQ)
                return ptrP;
            
            ptrP = ptrP->parent;
            ptrQ = ptrQ->parent;
            
            if(ptrP != NULL && ptrQ == NULL)
                ptrQ = p;
            if(ptrP == NULL && ptrQ != NULL)
                ptrP = q;
            if(ptrP == NULL && ptrQ == NULL)
                break;
        }
        return NULL;
    }
};