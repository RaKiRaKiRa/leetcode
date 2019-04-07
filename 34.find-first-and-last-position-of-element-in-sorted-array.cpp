/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 *
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (33.16%)
 * Total Accepted:    282.3K
 * Total Submissions: 849.6K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * Given an array of integers nums sorted in ascending order, find the starting
 * and ending position of a given target value.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * If the target is not found in the array, return [-1, -1].
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 * 
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        int l = 0, r = nums.size() -1, m = (l + r) / 2;
        while(l < r){
            m = (l + r) / 2;
            if(nums[m] == target)
                break;
            else if(nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }

        if(l > -1 && nums[l] == target)
            m = l;
        else if(r < nums.size() && nums[r] == target)
            m = r;
        if(nums[m] == target){
                l = r = m;
                while(l > 0 && nums[l - 1] == target)
                    --l;
                while(r + 1 < nums.size() && nums[r + 1] == target)
                    ++r;
                return {l, r};
        }
        return {-1, -1};
    }
};

