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
    
int maxi=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        
        int val=MPT(root,maxi);
        
        return maxi;
        
        
    }
    
    int MPT(TreeNode* root, int &maxi){
        
        if(root==NULL)
            return 0;
        
        int leftSum=MPT(root->left,maxi);
        int rightSum=MPT(root->right,maxi);
        
        if(leftSum<0 && rightSum>=0){
           maxi=max(maxi,(root->val+rightSum));
            return root->val+rightSum;
        }
        else if(rightSum<0 && leftSum>=0){
          maxi=max(maxi,(root->val+leftSum));
            return root->val+leftSum;
        }
       else if(rightSum<0 && leftSum<0){
            maxi=max(maxi,(root->val));
            return root->val;
       }
        maxi=max(maxi,(leftSum+rightSum+root->val));
        return root->val+max(rightSum,leftSum);
        
    }
};