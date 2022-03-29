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
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        bool firstNull = false;
        //For a complete binary tree, all the levels are filled when traversing BF. So, the first time a NULL pointer is encountered only at            the end
        while(!q.empty())
        {
            TreeNode* levelNode = q.front();
            q.pop();
            if(levelNode == NULL)
                firstNull = true;
            else
            {
                if(firstNull)
                    return false;
                q.push(levelNode->left);
                q.push(levelNode->right);
            }
        }
        return true;
    }
};