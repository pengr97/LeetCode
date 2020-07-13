//
// Created by Pengr on 2020/7/13.
//

//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//return its level order traversal as:
//[
//    [3],
//    [9,20],
//    [15,7]
//]

#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void getLevelOrder(vector<vector<int>> &res, vector<TreeNode*> currLevelNodes){
        vector<int> vals;
        vector<TreeNode*> nextLevelNodes;
        for(int i=0;i<(int)currLevelNodes.size();i++){
            vals.push_back(currLevelNodes[i]->val);
            if(currLevelNodes[i]->left!=NULL)
                nextLevelNodes.push_back(currLevelNodes[i]->left);
            if(currLevelNodes[i]->right!=NULL)
                nextLevelNodes.push_back(currLevelNodes[i]->right);
        }
        res.push_back(vals);
        if((int)nextLevelNodes.size()!=0)
            getLevelOrder(res, nextLevelNodes);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        vector<TreeNode*> nextLevelNodes;
        nextLevelNodes.push_back(root);
        getLevelOrder(res, nextLevelNodes);
        return res;
    }
};