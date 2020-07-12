//
// Created by Pengr on 2020/7/10.
//
//Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//Input: 3
//Output:
//[
//  [1,null,3,2],
//  [3,2,null,1],
//  [3,1,null,null,2],
//  [2,1,3],
//  [1,null,2,null,3]
//]
//Explanation:
//The above output corresponds to the 5 unique BST's shown below:
//
//  1         3     3      2      1
//   \       /     /      / \      \
//    3     2     1      1   3      2
//   /     /       \                 \
//  2     1         2                 3

#include <vector>
using namespace std;

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
    vector<TreeNode*> generate(vector<int> avai) {
        vector<TreeNode*> tree;
        if(avai.size()==0) {
            tree.push_back(NULL);
            return tree;
        }
        for(int i=0;i<(int)avai.size();i++){
            vector<int> leftAvai(avai.begin(),avai.begin()+i);
            vector<int> rightAvai(avai.begin()+i+1, avai.end());
            vector<TreeNode*> left = generate(leftAvai);
            vector<TreeNode*> right = generate(rightAvai);
            for(TreeNode* l:left)
                for(TreeNode* r:right){
                    TreeNode* tmp= new TreeNode(avai[i]+1);
                    tmp->left = l;
                    tmp->right = r;
                    tree.push_back(tmp);
                }
        }
        return tree;
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        vector<int> avai;
        for(int i=0;i<n;i++)
            avai.push_back(i);
        res = generate(avai);
        return res;
    }
};

