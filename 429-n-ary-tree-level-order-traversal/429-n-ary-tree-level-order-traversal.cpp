/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> result;
        if(!root)
            return result;
        queue<Node*> q;
        q.push(root);
        int count = 0;
        
        while(!q.empty())
        {
            vector<int> slate;
            count = q.size();
            for(int i = 0 ; i < count; i++)
            {
                Node* levelNode = q.front();
                q.pop();
                slate.push_back(levelNode->val);
                for(auto child : levelNode->children)
                    q.push(child);
            }
            result.push_back(slate);
        }
        return result;
    }
};