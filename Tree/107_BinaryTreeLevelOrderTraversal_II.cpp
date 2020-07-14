//
// Created by Pengr on 2020/7/14.
//

//Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its bottom-up level order traversal as:
//[
//    [15,7],
//    [9,20],
//    [3]
//]

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
    void getLevel(vector<vector<int>> &res, vector<TreeNode*> currLevelNodes){
        if(currLevelNodes.empty())
            return;

        vector<TreeNode*> nextLevelNodes;
        vector<int> currLevelVal;
        for(int i=0;i<(int)currLevelNodes.size();i++){
            currLevelVal.push_back(currLevelNodes[i]->val);
            if(currLevelNodes[i]->left!=NULL)
                nextLevelNodes.push_back(currLevelNodes[i]->left);
            if(currLevelNodes[i]->right!=NULL)
                nextLevelNodes.push_back(currLevelNodes[i]->right);
        }
        if(!nextLevelNodes.empty())
            getLevel(res, nextLevelNodes);
        res.push_back(currLevelVal);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        vector<TreeNode*> nextLevelNodes;
        nextLevelNodes.push_back(root);
        getLevel(res, nextLevelNodes);
        return res;
    }
};