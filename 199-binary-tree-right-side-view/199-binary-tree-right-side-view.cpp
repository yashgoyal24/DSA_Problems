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
    vector<int> rightSideView(TreeNode* root) {
         int level=0;
   vector<int> answer;
   rView(root,answer,level);
   
   return answer;
        
        
    }
    
    void rView(TreeNode* root,vector<int> &answer,int level){
    
    if(root==NULL)
    return;
    
    if(level==answer.size()){
        answer.push_back(root->val);
    }
    
    rView(root->right,answer,level+1);
    rView(root->left,answer,level+1);
    
    
    
}
};