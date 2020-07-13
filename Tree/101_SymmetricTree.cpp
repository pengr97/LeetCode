//
// Created by Pengr on 2020/7/13.
//

//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3

//But the following [1,2,2,null,3,null,3] is not:
//    1
//   / \
//  2   2
//   \   \
//    3    3

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
        if(p==NULL&&q==NULL)
            return true;
        bool res = (p->val==q->val);
        res = res&&judge(p->left, q->right);
        res = res&&judge(p->right, q->left);
        return res;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        bool res = judge(root->left, root->right);
        return res;
    }
};