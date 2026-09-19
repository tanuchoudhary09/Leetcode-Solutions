class Solution {
public:
    pair<int, int> solve(TreeNode* root, int& ans) {
        if (!root)
            return {0, 0};
        pair<int, int> a = solve(root->left, ans);
        pair<int, int> b = solve(root->right, ans);
        if (root->val ==
            (a.first + b.first + root->val) / (a.second + b.second + 1))
            ans++;
        return {a.first + b.first + root->val, a.second + b.second + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};