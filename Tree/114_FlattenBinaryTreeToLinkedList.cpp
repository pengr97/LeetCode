//
// Created by Pengr on 2020/7/15.
//

//Given a binary tree, flatten it to a linked list in-place.
//
//For example, given the following tree:
//
//    1
//   / \
//  2   5
// / \   \
//3   4   6
//The flattened tree should look like:
//
//1
// \
//  2
//   \
//    3
//     \
//      4
//       \
//        5
//         \
//          6

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
    void flatten(TreeNode* root) {
        if(root==NULL || (root->left==NULL&&root->right==NULL))
            return;
        if(root->right!=NULL)
            flatten(root->right);
        if(root->left!=NULL){
            flatten(root->left);
            TreeNode* tmp = root->right;
            root->right = root->left;
            TreeNode* tmp2 = root->left;
            while(tmp2->right!=NULL)
                tmp2 = tmp2->right;
            tmp2->right = tmp;
            root->left = NULL;
        }
    }
};