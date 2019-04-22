/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (51.65%)
 * Total Accepted:    351.7K
 * Total Submissions: 674.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    void func(int start, vector<int>& nums, vector<int>& cur, vector<vector<int> > &res){
        res.push_back(cur);
        for(int i = start; i < nums.size(); ++i){
            cur.push_back(nums[i]);
            func(i + 1, nums, cur, res);
            cur.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> cur;
        func(0, nums, cur, res);
        return res;
    }
};

