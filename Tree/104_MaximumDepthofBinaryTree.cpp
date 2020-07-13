//
// Created by Pengr on 2020/7/13.
//

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
    void getMaxDepth(int &res, TreeNode* root, int currDepth){
        if(root==NULL){
            res = max(res, currDepth-1);
            return;
        }
        getMaxDepth(res, root->left, currDepth+1);
        getMaxDepth(res, root->right, currDepth+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int res=0;
        getMaxDepth(res, root, 1);
        return res;
    }
};