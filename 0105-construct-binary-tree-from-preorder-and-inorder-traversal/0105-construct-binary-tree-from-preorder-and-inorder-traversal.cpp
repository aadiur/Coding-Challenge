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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        TreeNode*root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;

        
        
    }
    TreeNode*build(vector<int>&preorder,int pre_s,int pre_end,vector<int>&inorder,int in_s,int in_end,map<int,int>&mpp){
        if(pre_s>pre_end || in_s>in_end)return NULL;
        TreeNode* root=new TreeNode(preorder[pre_s]);
        int numL=mpp[root->val]-in_s;
        root->left=build(preorder,pre_s+1,pre_s+numL,inorder,in_s,mpp[root->val]-1,mpp);
        root->right=build(preorder,pre_s+numL+1,pre_end,inorder,mpp[root->val]+1,pre_end,mpp);

        return root;


    }
};