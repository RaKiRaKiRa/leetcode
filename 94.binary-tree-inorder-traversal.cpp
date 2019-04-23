/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* t = root;
        //st.push(root);
        while(t || st.size()){
            while(t){
                //res.push_back(t -> val);
                st.push(t);
                t = t -> left;
            }
            if(!st.empty()){
                t = st.top();
                res.push_back(t -> val);
                t = t -> right;
                st.pop(); 
            }
        }
        return res;
    }
};




/*******************先序****************************
 
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return vector<int>();
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* t = root;
        //st.push(root);
        while(t || st.size()){
            while(t){
                res.push_back(t -> val);
                st.push(t);
                t = t -> left;
            }
            if(!st.empty()){
                t = st.top();
                //res.push_back(t -> val);
                t = t -> right;
                st.pop(); 
            }
        }
        return res;
    }
*/
