/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool func(TreeNode* left, TreeNode* right){
        if((!left) ^ (!right)) return false;
        if(!left && !right) return true;
        if(left -> val != right -> val) return false;
        return func(left -> left, right -> right) && func(left -> right, right -> left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return func(root -> left, root -> right);
    }
};

