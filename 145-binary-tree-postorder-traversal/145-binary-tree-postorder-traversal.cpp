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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        TreeNode* current = root;
        while(current)
        {
            if(current->right == NULL)
            {
                result.push_back(current->val);
                current = current->left;
            }
            else
            {
                TreeNode* pred = current->right;
                while(pred->left && pred->left != current)
                    pred = pred->left;
                if(pred->left == NULL)
                {
                    pred->left = current;
                    result.push_back(current->val);
                    current = current->right;
                }
                else
                {
                    pred->left = NULL;
                    current = current->left;
                }
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};