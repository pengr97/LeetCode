//
// Created by Pengr on 2020/7/13.
//

//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//preorder = [3,9,20,15,7]
//inorder = [9,3,15,20,7]
//
//Return the following binary tree:
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
    TreeNode* build(vector<int> preorder, vector<int> inorder){
        TreeNode* root = NULL;
        if((int)preorder.size()==0)
            return root;
        root = new TreeNode(preorder[0]);
        int idx;
        for(idx=0;idx<(int)inorder.size();idx++){
            if(inorder[idx]==preorder[0])
                break;
        }
        vector<int> lpre(preorder.begin()+1, preorder.begin()+idx+1);
        vector<int> lino(inorder.begin(), inorder.begin()+idx);
        root->left = build(lpre, lino);

        vector<int> rpre(preorder.begin()+idx+1, preorder.end());
        vector<int> rino(inorder.begin()+idx+1, inorder.end());
        root->right = build(rpre, rino);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        if((int)preorder.size()==0)
            return root;
        root = build(preorder, inorder);
        return root;
    }
};
