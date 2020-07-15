//
// Created by Pengr on 2020/7/15.
//

//Given a binary tree, determine if it is height-balanced.
//
//For this problem, a height-balanced binary tree is defined as:
//
//a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
//
//
//
//Example 1:
//
//Given the following tree [3,9,20,null,null,15,7]:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7
//Return true.

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
    int judge(TreeNode* root, bool &res){
        if(root==NULL){
            res = res&&true;
            return 0;
        }
        int lheight = judge(root->left, res);
        int rheight = judge(root->right, res);
        res = res&&(lheight-rheight>=-1)&&(lheight-rheight<=1);
        return max(lheight, rheight)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        int height = judge(root, res);
        return res;
    }
};