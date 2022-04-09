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
    int maxD = INT_MIN;
    int dfs(Node* node)
    {
        if(!node)
            return 0;
        int height1 = 0;
        int height2 = 0;
        int currHeight = 0;
        for(auto child : node->children)
        {
            currHeight = dfs(child) + 1;
            if(currHeight > height1)
            {
                height2 = height1;
                height1 = currHeight;
            }
            else if(currHeight > height2)
                height2 = currHeight;
        }
        maxD = max(maxD, height1);
        return height1;
    }
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;
        dfs(root);
        return maxD+1;
    }
};