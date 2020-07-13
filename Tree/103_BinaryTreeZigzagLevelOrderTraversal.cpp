//
// Created by Pengr on 2020/7/13.
//

//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//return its zigzag level order traversal as:
//[
//    [3],
//    [20,9],
//    [15,7]
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
    void getLevelOrder(vector<vector<int>> &res, vector<TreeNode*> currLevelNodes, int flag){
        vector<int> vals;
        vector<TreeNode*> nextLevelNodes;
        for(int i=0;i<(int)currLevelNodes.size();i++){
            int idx = i;
            if(flag==1)
                idx = (int)currLevelNodes.size()-i-1;
            vals.push_back(currLevelNodes[idx]->val);
            if(currLevelNodes[i]->left!=NULL)
                nextLevelNodes.push_back(currLevelNodes[i]->left);
            if(currLevelNodes[i]->right!=NULL)
                nextLevelNodes.push_back(currLevelNodes[i]->right);
        }
        flag = 1-flag;
        res.push_back(vals);
        if((int)nextLevelNodes.size()!=0)
            getLevelOrder(res, nextLevelNodes, flag);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        int flag=0;
        vector<TreeNode*> nextLevelNodes;
        nextLevelNodes.push_back(root);
        getLevelOrder(res, nextLevelNodes, flag);
        return res;
    }
};