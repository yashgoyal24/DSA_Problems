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

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int> preOrder=preorder;
        sort(preorder.begin(),preorder.end());
        vector<int> inOrder=preorder;
      
        // now we have inorder and preorder of the tree, so create tree normally
        
        
         if(preOrder.size()==1){
            // single node which will be root itself
            TreeNode* root= new TreeNode(preOrder[0]);
            return root;
        }
        
        // store index of inorder elements in a map
        
        map<int, int> mp;
        for(int i=0;i<inOrder.size();i++){
            mp[inOrder[i]]=i;
        }
        
        
        
        return F(preOrder, inOrder, 0, inOrder.size()-1,0,preOrder.size()-1,mp);
        
        
    }
    
     TreeNode* F(vector<int>& preOrder, vector<int>& inOrder,int inStart, int inEnd, int preStart, int preEnd, map<int,int> &mp){
          
        if(inStart>inEnd || preStart>preEnd){
            // no nodes left
            return NULL;
        }
       // else{
         
             TreeNode* root=new TreeNode(preOrder[preStart]);
            // call for left subtree
            
            int leftNodes=mp[preOrder[preStart]] - inStart;
            root->left=F(preOrder, inOrder, inStart, mp[preOrder[preStart]]-1, preStart+1,preStart+leftNodes ,mp);
            
            // call for right subtree
            
            root->right=F(preOrder, inOrder,mp[preOrder[preStart]]+1, inEnd,preStart+leftNodes+1 , preEnd,mp);
     //   }
        return root;
    }
    
  
};