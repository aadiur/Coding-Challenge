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
    void checker(TreeNode*root,TreeNode*target,int k,unordered_map<TreeNode*,TreeNode*>&pm){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            if(node->left){
                pm[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                pm[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>pm;
        checker(root,target,k,pm);
        unordered_map<TreeNode*,bool>mpp;
        queue<TreeNode*>q;
        q.push(target);
        mpp[target]=true;
        int lvl=0;
        while(!q.empty()){
            int size=q.size();
            if(lvl==k)break;
            lvl++;
            for(int i=0;i<size;i++){
                TreeNode*curr=q.front();q.pop();
                if(curr->left&&!mpp[curr->left]){
                    mpp[curr->left]=true;
                     q.push(curr->left);
                }
                if(curr->right&&!mpp[curr->right]){
                    mpp[curr->right]=true;
                    q.push(curr->right);
                }
                if(pm[curr]&&!mpp[pm[curr]]){
                    mpp[pm[curr]]=true;
                    q.push(pm[curr]);
                }
            }


        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode*c=q.front();
            q.pop();
            ans.push_back(c->val);
        }
        return ans;
        
    }
};