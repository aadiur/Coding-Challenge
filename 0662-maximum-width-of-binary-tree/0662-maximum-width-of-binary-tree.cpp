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
        if(!root)return 0;
        int ans=0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            int minn=q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                long long lvl=q.front().second-minn;
                TreeNode*node=q.front().first;
                q.pop();
                if(i==0)first=lvl;
                if(i==size-1)last=lvl;
                if(node->left){
                    q.push({node->left,2*lvl+1});
                }
                if(node->right){
                    q.push({node->right,2*lvl+2});
                }
                
            }ans=max(ans,(int)(last-first+1));
        }return ans;
        
    }
};