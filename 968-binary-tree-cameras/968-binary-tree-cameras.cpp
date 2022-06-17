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
int counter=0;
int chaiye=2,hai=1,covered_hu=0;
    int minCameraCover(TreeNode* root) {
        
        if(postorder(root)==chaiye){
            counter++;
        }
        return counter;
        
    }
    
    int postorder(TreeNode* root){
        
        if(root==NULL)
            return covered_hu;
        int left=postorder(root->left);
        int right=postorder(root->right);
        
        if(left==chaiye || right==chaiye){
            
            // laga lo camera
            
            counter++;
            return hai;
            
        }
        else if(left==hai || right==hai){
            return covered_hu;
        }
        else{
            // dono covered hai, to mujhe to chaiye
            
            return chaiye;
            
        }
        
    }
};