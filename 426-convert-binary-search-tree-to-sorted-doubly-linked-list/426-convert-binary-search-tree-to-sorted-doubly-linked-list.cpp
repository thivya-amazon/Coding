/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
/*
Global problem : Convert into CDLL
Local problem/node : Find its predecessor and make the links
    Predecessor can be received from the parent or from the child. So, it is a combination of top down and bottom up.
    Pass an argument AND return a value - Pass the predecessor if it is from a parent
                                          Return the predecessor if it is from a child
*/
class Solution {
public:
    Node* dfs(Node* node, Node* pred)
    {
        //Internal nodes - pred can be from either direction
        if(node->left)
            pred = dfs(node->left, pred);
        //For inorder traversal, build links here
        pred->right = node;
        node->left = pred;
        pred = node;
        if(node->right)
            pred = dfs(node->right, pred);
        return pred;
    }
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)
            return NULL;
        Node* sentinel = new Node(INT_MIN);
        Node* tail = dfs(root, sentinel);
        Node* head = sentinel->right;
        tail->right = head;
        head->left = tail;
        return head;
    }
};