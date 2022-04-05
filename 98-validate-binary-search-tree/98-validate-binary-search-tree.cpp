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
    bool validBST = false;
    class BST{
        public:
        int largest;
        int smallest;
        bool isBST;
        BST(){
            
        }
        BST(int l, int s, bool b)
        {
            largest = l;
            smallest = s;
            isBST = b;
        }
    };
    BST dfs(TreeNode* node)
    {
        BST myValue(node->val, node->val, true);
        BST leftValue;
        BST rightValue;
        
        if(node->left)
        {
            leftValue = dfs(node->left);
            myValue.largest = max(myValue.largest, leftValue.largest);
            myValue.smallest = min(myValue.smallest, leftValue.smallest);
            if(!leftValue.isBST || node->val <= leftValue.largest)
                myValue.isBST = false;
        }
        if(node->right)
        {
            rightValue = dfs(node->right);
            myValue.largest = max(myValue.largest, rightValue.largest);
            myValue.smallest = min(myValue.smallest, rightValue.smallest);
            if(!rightValue.isBST || node->val >= rightValue.smallest)
                myValue.isBST = false;
        }
        validBST = myValue.isBST;
        return myValue;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        dfs(root);
        return validBST;
    }
};