/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* func(vector<int>& nums, int s, int e){
        if(s == e) return new TreeNode(nums[s]);
        if(s > e) return NULL;
        int t = (e + s + 1) / 2;
        TreeNode *res = new TreeNode(nums[t]);
        res -> left = func(nums, s, t - 1);
        res -> right = func(nums, t + 1, e);
        return res;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1)
            return new TreeNode(nums[0]);

        return func(nums, 0, nums.size() - 1);
    }
};

