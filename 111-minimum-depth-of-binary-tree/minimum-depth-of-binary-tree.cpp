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
    int  minDep(TreeNode *root, int cnt){
        if (root == NULL) return cnt;
        if(root->left==NULL & root->right==NULL) return cnt+1;
        if(root->left==NULL) return minDep(root->right,cnt+1);
        if(root->right==NULL) return minDep(root->left,cnt+1); 
        int lD = minDep(root->left,cnt+1);
        int rD = minDep(root->right,cnt+1);
        return min(lD,rD);
        
    }
    int minDepth(TreeNode* root) {
        int cnt = 0;
        if(root==NULL) return 0;
        if(root->left==NULL) return minDep(root->right,cnt+1);
        if(root->right==NULL) return minDep(root->left,cnt+1);
        return minDep(root,cnt);
    }
};