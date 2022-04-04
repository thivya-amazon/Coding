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

class Codec {
public:
    string s;
    Node* buildTree(queue<string>& q)
    {
        string elem = q.front();
        q.pop();
        int numChildren = stoi(q.front());
        q.pop();
        if(elem == "n")
        {
            return NULL;
        }            
        Node* root = new Node(stoi(elem));
        for(int i = 0; i < numChildren; i++)
            root->children.push_back(buildTree(q));
        
        return root;
    }
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(root == NULL)
             s += "n 0 ";              
        else
        {
            s += to_string(root->val);
            s.push_back(' ');
            s += to_string(root->children.size());
            s.push_back(' ');
            for(auto child : root->children)
                serialize(child);
        }
        return s;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string elem;
        while(ss >> elem)
        {
            q.push(elem);
        }
        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));