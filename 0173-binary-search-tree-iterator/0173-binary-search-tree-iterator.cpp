class BSTIterator {
public:
    stack<TreeNode*> st;

    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    void pushLeft(TreeNode* root) {
        while(root != NULL) {
            st.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if(node->right != NULL) {
            pushLeft(node->right);
        }

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};