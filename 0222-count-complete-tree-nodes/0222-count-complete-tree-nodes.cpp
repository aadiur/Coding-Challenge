class Solution {
public:

    int HL(TreeNode* node) {
        int h = 0;

        while (node) {
            h++;
            node = node->left;
        }

        return h;
    }

    int HR(TreeNode* node) {
        int h = 0;

        while (node) {
            h++;
            node = node->right;
        }

        return h;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        int lh = HL(root);
        int rh = HR(root);

        if (lh == rh) {
            return (1 << lh) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};