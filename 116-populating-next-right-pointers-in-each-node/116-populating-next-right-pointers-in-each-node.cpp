/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)
            return NULL;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        int count = 0;
        while(!q.empty())
        {
            count = q.size();
            for(int i = 0; i < count; i++)
            {
                Node* levelNode = q.front().first;
                int level = q.front().second;
                q.pop();
                if(levelNode->left)
                    q.push({levelNode->left, level+1});
                if(levelNode->right)
                    q.push({levelNode->right, level+1});
                if(!q.empty())
                {
                    if(q.front().second == level)
                        levelNode->next = q.front().first;
                }
            }
        }
        return root;
    }
};