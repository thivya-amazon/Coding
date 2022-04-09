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
        set<Node*> nodes;
        
        Node* temp = p;
        while(temp)
        {
            nodes.insert(temp);
            temp = temp->parent;
        }
        temp = q;
        while(temp)
        {
            if(nodes.count(temp))
                return temp;
            temp = temp->parent;
        }
        return NULL;
    }
};