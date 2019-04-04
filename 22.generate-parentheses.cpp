/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (53.79%)
 * Total Accepted:    315.9K
 * Total Submissions: 586.6K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */
class Solution {
public:
    void func(int l,int r,int &n,vector<string> &res, string &str){
        if(l == n && r == n)
            res.push_back(str);
        else if(l == r){
            str.append(1,'(');
            func(l + 1, r, n, res, str);
            str.pop_back();
        }
        else if(l == n){
            str.append(1,')');
            func(l, r + 1, n, res, str);
            str.pop_back();
        }
        else{
            str.append(1,'(');
            func(l + 1, r, n, res, str);
            str.pop_back();
            str.append(1,')');
            func(l, r + 1, n, res, str);
            str.pop_back();
        }
            
    }


    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        func(0,0,n,res,str);
        return res;
    }
};

