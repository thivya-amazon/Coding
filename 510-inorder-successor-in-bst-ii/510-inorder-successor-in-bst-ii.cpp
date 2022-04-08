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
    Node* findMin(Node* node)
    {
        if(node == NULL)
            return NULL;
        while(node->left)
            node = node->left;
        return node;
    }
    Node* inorderSuccessor(Node* node) {
        if(node == NULL)
            return NULL;
        if(node->right)
            return findMin(node->right);
        else
        {
            Node* parentNode = node->parent;
            while(parentNode)
            {
                if(parentNode->val > node->val)
                    return parentNode;
                else
                    parentNode = parentNode->parent;
            }
            return parentNode;
        }
    }
};