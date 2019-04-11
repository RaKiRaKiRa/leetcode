/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (42.39%)
 * Total Accepted:    274.2K
 * Total Submissions: 644.5K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax(height.size(), 0), rmax(height.size(), 0);
        int t = 0;
        for(int i = 0; i < height.size(); ++i){
            lmax[i] = t;
            if(t < height[i])
                t = height[i];
        }
        for_each(lmax.begin(),lmax.end(),[&](int &i)(cout<<i<<" ";));

        t = 0;
        for(int i = height.size() - 1; i > -1; --i){
            rmax[i] = t;
            if(t < height[i])
                t = height[i];
        }
        int res = 0;
        for(int i = 0; i < height.size(); ++i){
            t = rmax[i] > lmax[i] ? lmax[i] : rmax[i];
            if(t > height[i])
                res += t - height[i];
        }
        return res;
    }
};

