/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* treeHelper(stringstream& ss)
    {
        int num;
        TreeNode* node = NULL;
        if(ss >> num)
            node = new TreeNode(num);
        char c;
        while(ss >> c)
        {
            if(c == '(' && node->left == NULL)
                node->left = treeHelper(ss);
            else if(c == '(' && node->left != NULL)
                node->right = treeHelper(ss);
            else if(c == ')')
                break;
        }
        return node;    
    }
    TreeNode* str2tree(string s) {
        if(s.size() == 0)
            return NULL;
        stringstream ss(s);
        return treeHelper(ss);
    }
};