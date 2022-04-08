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
class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        partialBuild(root);
    }
    void partialBuild(TreeNode* root){
        if(root == NULL)
            return;
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }
    int next() {
        if(!s.empty())
        {
            TreeNode* nextNode = s.top();
            s.pop();
            partialBuild(nextNode->right);
            return nextNode->val;
        }
        return -1;
    }
    
    bool hasNext() {
        if(!s.empty())
            return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */