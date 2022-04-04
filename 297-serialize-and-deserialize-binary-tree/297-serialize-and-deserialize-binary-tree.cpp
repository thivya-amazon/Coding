/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    //builds the tree
    string s = "";
    TreeNode* buildTree(queue<string>& q)
    {
        TreeNode* root;

            string elem = q.front();
            q.pop();
            if(elem == "n")
                return NULL;
            root = new TreeNode(stoi(elem));
            root->left = buildTree(q);
            root->right = buildTree(q);

        return root;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            s += "n ";
        else
        {
            s += to_string(root->val);
            s.push_back(' ');
            serialize(root->left);
            serialize(root->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string elem = "";
        while(ss >> elem)
        {
            q.push(elem);
        }
        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));