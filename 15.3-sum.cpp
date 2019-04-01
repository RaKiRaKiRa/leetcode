/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.65%)
 * Total Accepted:    509.9K
 * Total Submissions: 2.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        /*	
        //Time Limit Exceeded
        if(nums.size() < 3)
            return vector<vector<int> >();
        vector<vector<int> > res;
        for(int k = 2; k < nums.size(); ++k){
            int target = 0 - nums[k];
            unordered_map<int, int> record;
            for(int i = 0; i < k; ++i){
                int f = target - nums[i];
                if(record.find(f) != record.end()){
                    vector <int> tmp{f, nums[i], nums[k]};
                    sort(tmp.begin(), tmp.end());
                    if(find(res.begin(), res.end(), tmp) != res.end())
                        continue;
                    res.push_back(tmp);
                    break;
                }
                record[nums[i]] = i;    
            }
        }
        return res;
        */
        
        if(nums.size() < 3)
            return vector<vector<int> >();
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); ++k){
            int target = 0 - nums[k], r = nums.size() - 1, l = k + 1;
            while( l < r ){
                int tmp = nums[l] + nums[r];
                if(tmp == target){
                    res.push_back(vector<int>{ nums[l++], nums[r--], nums[k] });
                    while(l < r && nums[l] == nums[l - 1])
                        ++l;
                    while(l < r && nums[r] == nums[r + 1])
                        --r;
                }
                else if(tmp < target)
                    ++l;
                else
                    --r;
                
            }
            while(k < nums.size() - 1 && nums[k] == nums[k + 1])
                ++k;
        }
        return res;
    }
};

