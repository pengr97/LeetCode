//
// Created by Pengr on 2020/7/12.
//

//Two elements of a binary search tree (BST) are swapped by mistake.
//
//Recover the tree without changing its structure.

//Input: [3,1,4,null,null,2]
//
//      3
//     / \
//    1   4
//       /
//      2
//
//Output: [2,1,4,null,null,3]
//
//     2
//    / \
//   1   4
//      /
//     3


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
public:
    void inorder(vector<int> &vals, TreeNode* root){
        if(root==NULL)
            return;
        inorder(vals, root->left);
        vals.push_back(root->val);
        inorder(vals, root->right);
    }
    void regenerate(TreeNode* root, int start, int end, int startVal, int endVal, int &curr){
        if(root==NULL)
            return;
        regenerate(root->left,start,end, startVal, endVal, curr);
        if(curr==start)
            root->val = endVal;
        else if(curr==end)
            root->val = startVal;
        curr++;
        regenerate(root->right,start,end, startVal, endVal, curr);
    }
    void recoverTree(TreeNode* root) {
        vector<int> vals;
        inorder(vals, root);
        int start=0, end=(int)vals.size()-1;
        while(start<end){
            if(vals[start]<vals[start+1])
                start++;
            if(vals[end]>vals[end-1])
                end--;
            if(vals[start]>vals[start+1]&&vals[end]<vals[end-1])
                break;
        }
        int curr = 0;
        regenerate(root,start,end,vals[start], vals[end], curr);
    }
};