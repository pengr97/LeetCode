//
// Created by Pengr on 2020/7/12.
//
//Given a binary tree, determine if it is a valid binary search tree (BST).


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#include <vector>
class Solution {
private:
    int leftMax;
    int rightMin;
public:
//    solu 1
    void transMid(vector<int> &values, TreeNode* root){
        while (root!=NULL){
            transMid(values, root->left);
            values.push_back(root->val);
            transMid(values, root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        vector<int> values;
        transMid(values, root);
        for(int i=0;i<(int)values.size()-1;i++){
            if(values[i]>=values[i+1])
                return false;
        }
        return true;
    }
};