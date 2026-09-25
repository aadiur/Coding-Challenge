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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxfn(root,maxi);
        return maxi;
    }
    int maxfn(TreeNode*root,int &maxi){
        if(root==NULL)return 0;
        int lefts=max(0,maxfn(root->left,maxi));
        int rights=max(0,maxfn(root->right,maxi));
        maxi=max(maxi,root->val+lefts+rights);
        return max(lefts,rights)+root->val;
    }
};