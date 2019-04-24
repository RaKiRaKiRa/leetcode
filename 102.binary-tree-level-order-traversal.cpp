/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    public:
        TN(int l, TreeNode* t) : lv(l),tn(t){};
        int lv;
        TreeNode* tn;
        
    };
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) 
            return vector<vector<int> > ();
        vector<vector<int> > res;
        vector<int> tmp;
        TreeNode* p = root;
        TN tn(1, p);
        queue<TN> st;
        st.push(tn);
        int l = 1;
        while(!st.empty()){
            tn = st.front();
            st.pop(); 
            p = tn.tn;
            if(tn.lv != l){
                res.push_back(tmp);
                tmp.clear();
                ++l;
            }
            if(p -> left)
                st.push(TN(l + 1, p -> left));
            if(p -> right)
                st.push(TN(l + 1, p -> right));

            tmp.push_back(p -> val);
        }
        res.push_back(tmp);
        return res;
    }
};

