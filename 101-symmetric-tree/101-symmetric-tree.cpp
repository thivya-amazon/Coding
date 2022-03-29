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
    bool isMirror(vector<int>& input)
    {
        int start = 0;
        int end = input.size()-1;
        while(start < end)
        {
            if(input[start++] != input[end--])
                return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
       
        while(!q.empty())
        {
            count = q.size();
            vector<int> slate;
            for(int i = 0; i < count; i++)
            {
                TreeNode* levelNode = q.front();
                q.pop();

                if(levelNode->left)
                {
                    slate.push_back(levelNode->left->val);
                    q.push(levelNode->left);
                }                    
                else
                    slate.push_back(INT_MIN);

                if(levelNode->right)
                {
                    slate.push_back(levelNode->right->val);
                    q.push(levelNode->right);
                }                    
                else
                    slate.push_back(INT_MIN);

            }
            if(!isMirror(slate))
                return false;
        }
        return true;
        
    }
};