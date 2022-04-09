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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        TreeNode* current = root;
        while(current)
        {
            if(current->left == NULL)
            {
                result.push_back(current->val);
                current = current->right;
            }
            else
            {
                TreeNode* pred = current->left;
                while(pred->right && pred->right != current)
                {
                    pred = pred->right;
                }
                //No thread created, yet. Create a thread and traverse left
                if(pred->right == NULL)
                {
                    pred->right = current;
                    current = current->left;
                }
                //Thread already created. Break thread and traverse right 
                else
                {
                    pred->right = NULL;
                    //Visit the node before moving right for inorder
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return result;
    }
};