/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (54.04%)
 * Total Accepted:    359K
 * Total Submissions: 661.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    
    void fun(vector<vector<int> > &res,vector<int> &cur,vector<int>& nums, vector<int> &f,int n){
        if(n == nums.size()){
            res.push_back(cur);
            return ;
        }
        
        for(int i = 0; i < nums.size(); ++i){
            if(f[i])
                continue;
            cur.push_back(nums[i]);
            f[i] = 1;
            fun(res, cur, nums, f, n + 1);
            f[i] = 0;
            cur.pop_back();
        }
            
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        int sz = nums.size();
        vector<int> f(sz,0);
        vector<vector<int> > res;
        vector<int> cur;
        fun(res, cur, nums, f, 0);
        return res;
    }
};

