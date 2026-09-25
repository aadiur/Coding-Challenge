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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL)return result;
        queue<TreeNode*>Q;
        Q.push(root);
        bool flag=true;
        while(!Q.empty()){
            int n=Q.size();
            vector<int>row(n);
            for(int i=0;i<n;i++){
                TreeNode*Node=Q.front();
                Q.pop();
                int ind=flag?i:n-i-1;
                row[ind]=Node->val;
                if(Node->left!=NULL)Q.push(Node->left);
                if(Node->right!=NULL)Q.push(Node->right);

            }
            flag=!flag;
            result.push_back(row);

        }return result;

        
    }
};