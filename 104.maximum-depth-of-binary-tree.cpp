/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    struct TN{
        int lv;
        TreeNode* node;
        TN(int l, TreeNode *tn) : lv(l), node(tn) {};
    };
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root -> left && !root -> right) return 1;
        queue<TN> que;
        TN tn(1, root);
        que.push(tn);
        int l = 0;
        while(!que.empty()){
            l++;
            while(!que.empty()){
                if(l != tn.lv)
                    break;
                if(tn.node -> left)
                    que.push(TN(l + 1, tn.node -> left));
                if(tn.node -> right)
                    que.push(TN(l + 1, tn.node -> right));
                tn = que.front();
                que.pop();
            }
            
        }
        return l;
    }
};

