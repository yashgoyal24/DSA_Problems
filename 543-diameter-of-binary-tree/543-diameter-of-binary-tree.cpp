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
int maxi;
    int diameterOfBinaryTree(TreeNode* root) {
         int val=F(root,maxi);
        return maxi;
    }
        
    
 //Use height of a node concept
    
    //Consider every node as a curved point, calulate width and update maxi variable
    
    int F(TreeNode* root,int &maxi){
        
        if(root==NULL){
            return 0;
        }
        
        int lh=F(root->left,maxi);
        int rh=F(root->right,maxi);
        
        //update width
        
        maxi=max(maxi,(lh+rh));
        
        //function returns height ki value
        
        return 1+max(lh,rh);
    }
};