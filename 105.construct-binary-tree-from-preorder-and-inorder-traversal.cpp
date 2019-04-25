/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* build(vector<int>& pre,int pre_l, int pre_r, vector<int>& in, int in_l, int in_r){
        //cout << pre_l <<" " << pre_r <<" " <<in_l<<" "<<in_r<<endl;
        if(pre_l > pre_r || in_l > in_r)
            return NULL;
        int tmp = pre[pre_l], t;
        TreeNode* res = new TreeNode(tmp);
        //cout<<res->val;
        if(pre_l == pre_r) return res;
        for(int i = in_l; i <= in_r; ++i)
            if(in[i] == tmp){
                t = i;
                break;
            }
        
        res -> left = build(pre, pre_l + 1, pre_l + t - in_l, in, in_l, t - 1 );
        res -> right = build(pre, pre_l + t - in_l + 1, pre_r, in, t + 1, in_r);
        //res -> right = build(pre, pre_r - (in_r - t) + 1, pre_r, in, t + 1, in_r);
        return res;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //if(preorder.empty() || inorder.empty()) 
            //return NULL;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

    }
};

