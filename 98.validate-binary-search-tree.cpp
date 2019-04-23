/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

// 中序遍历
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        stack<TreeNode*> st;
        TreeNode* p = root;
        TreeNode* prev = NULL;
        while(p || !st.empty()){
            //cout<<1;
            while(p){
                st.push(p);
                p = p -> left;
            }
            if(!st.empty()){
                //cout<<"1";
                p = st.top();
                st.pop();

                if(prev != NULL && prev -> val >= p -> val) 
                    return false;
                prev = p;

                p = p -> right;
            }
        }
        return true;
    }
};

