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
            //Case 2 : Has only right child
            else if(root->left == NULL)
            {
                // TreeNode* temp = root->right;
                // root = root->right;
                // root->right = deleteNode(root->right, temp->val);
                return root->right;
            
            }
             //Case 3 : Has only left child
            else if(root->right == NULL)
            {
                // TreeNode* temp = root->left;
                // root = root->left;
                // root->left = deleteNode(root->left, temp->val);   
                return root->left;
            }
             //Case 4 : Has both children
            else
            {
                TreeNode* temp = minValue(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }
        return root;
        
    }
};