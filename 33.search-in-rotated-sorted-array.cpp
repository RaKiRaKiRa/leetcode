/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.73%)
 * Total Accepted:    390K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int l = 0, r = nums.size() - 1, m;
        //二分找target
        while(l < r){
            m = (r + l) / 2;
            
            if(nums[m] == target)
                break;
            //l ~ r无旋转点
            if(nums[l] < nums[r]){
                if(nums[m] < target)
                    l = m + 1;
                else
                    r = m - 1;                
            }
            //m ~ r存在旋转点,左边正常则判断左边
            else if(nums[m] > nums[r]){
                if(nums[m] > target && nums[l] <= target)
                    r = m - 1;
                else
                    l = m + 1;
            }
            //l ~ m存在旋转点,右边正常则判断右边
            else{
                if(nums[m] < target && nums[r] >= target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        if(l >= r)
            if(l < nums.size() && nums[l] == target)
                return l;
            else if(r >= 0 && nums[r] == target)
                return r;
            else
                return -1;
                       
        return m;
    }
};

