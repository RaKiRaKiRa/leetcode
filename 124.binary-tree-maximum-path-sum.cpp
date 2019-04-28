/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int func(TreeNode* root, int &res){
        if(!root) return 0;
        int l = func(root -> left, res);
        int r = func(root -> right, res);
        if(l < 0) l = 0;
        if(r < 0) r = 0;
        int tmp = l + r + root -> val;
        if(tmp > res) res = tmp;
        return root -> val + max(l, r);
    }


    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        func(root, res);
        return res;
    }
};

