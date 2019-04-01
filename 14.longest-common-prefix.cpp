/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.17%)
 * Total Accepted:    431.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        string res = strs[0];
        int flag = 1;
        for(int i = 1; i < strs.size(); ++i){
            int sz = res.size() < strs[i].size() ? res.size() : strs[i].size();
            flag = 1;
            for(int j = 0; j < sz; ++j)
                if(res[j] != strs[i][j]){
                    if(j == 0)
                        return "";
                    else{
                        flag = 0;
                        res = res.substr(0, j);
                        break;
                    }
                }   
            if(flag)
                res = res.size() < strs[i].size() ? res : strs[i];   
        }
        return res;
    }
};

