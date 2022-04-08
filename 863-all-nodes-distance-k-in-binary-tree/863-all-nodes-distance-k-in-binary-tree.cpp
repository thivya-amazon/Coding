/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        if(root == NULL)
            return result;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        
        //1st BFS for populating parent map
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* levelNode = q.front();
            q.pop();
            if(levelNode->left)
            {
                parent[levelNode->left] = levelNode;
                q.push(levelNode->left);
            }
            if(levelNode->right)
            {
                parent[levelNode->right] = levelNode;
                q.push(levelNode->right);
            }
        }
        
        //2nd BFS to collect all nodes at distance(or level) k from target node
        queue<TreeNode*> q2;
        q2.push(target);
        visited[target] = true;
        int level = 0;
        int count = 0;
        while(!q2.empty())
        {
            if(level == k)
                break;
            else
                level++;
            count = q2.size();
            for(int i = 0; i < count; i++)
            {
                TreeNode* levelNode = q2.front();
                q2.pop();
                if(levelNode->left && !visited[levelNode->left])
                {
                    visited[levelNode->left] = true;
                    q2.push(levelNode->left);
                }
                if(levelNode->right && !visited[levelNode->right])
                {
                    visited[levelNode->right] = true;
                    q2.push(levelNode->right);
                }
                if(parent[levelNode] != NULL && !visited[parent[levelNode]])
                {
                    visited[parent[levelNode]] = true;
                    q2.push(parent[levelNode]);
                }
            }
            
        }
        
        while(!q2.empty())
        {
            result.push_back(q2.front()->val);
            q2.pop();
        }
        return result;       
    }
};