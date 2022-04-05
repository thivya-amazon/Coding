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
    unsigned int maxCount = 1;
    class BST{
        public:
        int largest;
        int smallest;
        unsigned int count;
        bool isBST;  
        BST()
        {
            
        }
        BST(int l, int s, int c, bool b)
        {
            largest = l;
            smallest = s;
            count = c;
            isBST = b;
        }
    };
    BST dfs(TreeNode* node)
    {
        BST myValue(node->val, node->val, 1, true);
        BST leftValue;
        BST rightValue;

        if(node->left == NULL && node->right == NULL)
        {
            
        }
           
        // myValue.largest = node->val;
        // myValue.smallest = node->val;
        // myValue.count = 1;
        // myValue.isBST = true;       
        
        if(node->left)
        {
            leftValue = dfs(node->left);
            myValue.count += leftValue.count;
            myValue.largest = max(myValue.largest, leftValue.largest);
            myValue.smallest = min(myValue.smallest, leftValue.smallest);
            if(!leftValue.isBST || node->val <= leftValue.largest)
                myValue.isBST = false;
        }
        if(node->right)
        {
            rightValue = dfs(node->right);
            myValue.count += rightValue.count;
            myValue.largest = max(myValue.largest, rightValue.largest);
            myValue.smallest = min(myValue.smallest, rightValue.smallest);
            if(!rightValue.isBST || node->val >= rightValue.smallest)
                myValue.isBST = false;
        }
        if(myValue.isBST)
        {
            maxCount = max(maxCount, myValue.count);
        }

        return myValue;
    }
    int largestBSTSubtree(TreeNode* root) {
        if(root == NULL)
            return 0;
        dfs(root);
        return maxCount;
    }
};