//
// Created by Pengr on 2020/7/14.
//

//Given inorder and postorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//inorder = [9,3,15,20,7]
//postorder = [9,15,7,20,3]
//Return the following binary tree:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7

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
    TreeNode* build(vector<int> inorder, vector<int> postorder){
        TreeNode* root = NULL;
        if(inorder.empty())
            return root;

        root = new TreeNode(postorder[(int)postorder.size()-1]);

        int idx;
        for(idx=0;idx<(int)inorder.size();idx++){
            if(inorder[idx]==postorder[(int)postorder.size()-1])
                break;
        }
        vector<int> lino(inorder.begin(), inorder.begin()+idx);
        vector<int> lpos(postorder.begin(), postorder.begin()+idx);
        root->left = build(lino, lpos);

        vector<int> rino(inorder.begin()+idx+1, inorder.end());
        vector<int> rpos(postorder.begin()+idx, postorder.end()-1);
        root->right = build(rino, rpos);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = NULL;
        if(inorder.empty())
            return root;
        root = build(inorder, postorder);
        return root;
    }
};