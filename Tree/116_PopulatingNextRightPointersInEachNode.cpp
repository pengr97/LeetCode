//
// Created by Pengr on 2020/7/23.
//

//You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
//
//struct Node {
//    int val;
//    Node *left;
//    Node *right;
//    Node *next;
//}
//        Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
//
//
//Follow up:
//
//You may only use constant extra space.
//Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            Node* tmp1 = q.front();
            if(tmp1->left!=NULL)
                q.push(tmp1->left);
            if(tmp1->right!=NULL)
                q.push(tmp1->right);
            q.pop();
            for(int i=1;i<size;i++){
                Node* tmp2 = q.front();
                if(tmp2->left!=NULL)
                    q.push(tmp2->left);
                if(tmp2->right!=NULL)
                    q.push(tmp2->right);
                tmp1->next = tmp2;
                tmp1 = tmp2;
                q.pop();
            }
            tmp1->next = NULL;
        }
        return root;
    }
};