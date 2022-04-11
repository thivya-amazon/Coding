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
    TreeNode* minValue(TreeNode* root)
    {
        if(root == NULL)
            return NULL;
        TreeNode* current = root;
        while(current->left)
            current = current->left;
        return current;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return NULL;
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else
        {
            //Case 1 : Leaf node
            if(root->left == NULL && root->right == NULL)
            {
                delete(root);
                return NULL;
            }
            //Case 2 : Has only one child
            if(root->left == NULL || root->right == NULL)
            { 
                TreeNode* temp = root;
                root = root->right ? root->right : root->left; 
                delete(temp);
            }
            else
            {
                 //Case 3  : Has both children
                TreeNode* temp = minValue(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
    
        }
        return root;
        
    }
};