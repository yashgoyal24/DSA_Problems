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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> bfs;
        
        if(root==NULL)
            return bfs;
        
       queue<TreeNode*> q;
        
        q.push(root);
        
        //traverse till queue is not empty
        
        while(!q.empty()){
            
            vector<int> level;
            int s=q.size();
            for(int i=0;i<s;i++){
            
            TreeNode* front=q.front();
            level.push_back(front->val);
            q.pop();
            
            if(front->left!=NULL)
                q.push(front->left);
            
            if(front->right!=NULL)
                q.push(front->right);
                
            }
            
            bfs.push_back(level);
            
        }
        
        
        
        return bfs;
    }
};