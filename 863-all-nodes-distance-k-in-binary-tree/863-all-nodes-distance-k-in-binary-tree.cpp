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
        
        // map to store node and its parent node
        
        map<TreeNode*, TreeNode*> mp;
        
        
        // level order traversal to track parent
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            
            TreeNode* node=q.front();
            q.pop();
            if(node->left!=NULL){
                q.push(node->left);
                mp[node->left]=node;
            }
              if(node->right!=NULL){
                q.push(node->right);
                mp[node->right]=node;
            }
                  
            
        }
        
        // now do dfs traversal starting from target node
        
        int distance=0;  // stop when distance = k
        
        
        if(distance==k)
            return {target->val};
        vector<int> final;
        queue<TreeNode*> q1;
         map<TreeNode*,int> mp2;
        
        q1.push(target);
        mp2[target]=1;  // visited
        // make a visited map as well
        
       
        while(!q1.empty()){
            
           
            int n=q1.size();
            for(int i=0;i<n;i++){
                 TreeNode* node=q1.front();
                 q1.pop();
                
                // push all neighbours 
                
                if(mp.find(node)!=mp.end() && mp2[mp[node]]==0){
                     q1.push(mp[node]); // push parent of node in queue
                    mp2[mp[node]]=1;
                }
                   
                if(node->left!=NULL && mp2[node->left]==0){
                    q1.push(node->left);
                    mp2[node->left]=1;
                }
                    
                if(node->right!=NULL && mp2[node->right]==0){
                       q1.push(node->right);
                      mp2[node->right]=1;
                }
                 
                
                
            }
            // increase distance    
            distance++;
            if(distance==k){
                // push all elements present in the queue to result
                
                while(!q1.empty()){
                    int value=q1.front()->val;
                   final.push_back(value);
                    q1.pop();
                }
               return final; 
            }
                
        }
        
       
            
            
            return final;
    }
};