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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root->left==NULL && root->right==NULL)
            return 1; // only 1 node present
        
        int maxi=INT_MIN;
        
        queue<TreeNode*> q;  // queue for level order traversal
        map<TreeNode*,long long> mp; // map to store node and its corresponding index number
        
        q.push(root);
        mp[root]=0;
        
        while(!q.empty()){
            
            long long start_index=mp[q.front()];
            int n=q.size();
            for(int i=0;i<n;i++){
                
               
                
                TreeNode* node=q.front();
                 long long end_index=mp[node];
           
                q.pop();
                
                if(node->left!=NULL)
                    q.push(node->left);
                    mp[node->left]=2*(mp[node]-start_index)+1;
                if(node->right!=NULL)
                    q.push(node->right);
                    mp[node->right]=2*(mp[node]-start_index)+2;
                long long diff=end_index-start_index+1;
         maxi=max(maxi, (int)diff); 
                
                
            }
            
        }
        return maxi;
    }
};