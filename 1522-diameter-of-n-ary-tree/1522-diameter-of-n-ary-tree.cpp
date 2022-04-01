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
    int Treediameter = 0;
    int getHeight(Node* root)
    {
        if(root == NULL)
            return 0;
        int currHeight = 0;
        int height1 = 0;
        int height2 = 0;
        for(auto child : root->children)
        {
           currHeight =  getHeight(child)+1;
            if(currHeight > height1)
            {
                height2 = height1;
                height1 = currHeight; 
            }
            else if(currHeight > height2)
                height2 = currHeight;
        }                    
        Treediameter = max(Treediameter, height1+height2);
        return height1;
        
    }
    int diameter(Node* root) {
        if(root == NULL)
            return 0;
        getHeight(root);
        return Treediameter;
    }
};