/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (28.45%)
 * Total Accepted:    201.7K
 * Total Submissions: 706.7K
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;
        //cout << 1;
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] > 0 && nums[i] < nums.size() + 1 && i + 1 != nums[i]){
                int t = nums[i];
                if(nums[i] == nums[t - 1]) break;
                nums[i] = nums[t - 1];
                nums[t - 1] = t;
            }
        }

        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != i + 1)
                return i + 1;
        return nums.size() + 1;
    }
};

