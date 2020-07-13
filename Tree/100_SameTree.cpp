//
// Created by Pengr on 2020/7/13.
//

//Given two binary trees, write a function to check if they are the same or not.
//
//Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

//Input:     1         1
//          / \       / \
//         2   3     2   3
//
//        [1,2,3],   [1,2,3]
//
//Output: true


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
    bool judge(TreeNode* p, TreeNode* q){
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
            return false;
        if(p==NULL && q==NULL)
            return true;
        bool res=(p->val==q->val);
        res = res&&judge(p->left, q->left);
        res = res&&judge(p->right, q->right);
        return res;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = judge(p, q);
        return res;
    }
};