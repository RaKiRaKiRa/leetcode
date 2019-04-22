/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (35.17%)
 * Total Accepted:    351.3K
 * Total Submissions: 992.6K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return ;
        if(m == 0) {
            nums1 = nums2;
            return;
        }
        int i = 0, j = 0;
        while(i < m){
            //nums[i]大则i++;
            if(nums1[i] <= nums2[0]){
                ++i;
            }
            //nums2[0]大则交换然后对nums2排序
            else{
                swap(nums1[i], nums2[0]);
                ++i;
                for(int a = 1; a < n; ++a)
                    if(nums2[a] < nums2[a - 1])
                        swap(nums2[a], nums2[a - 1]);
                    else
                        break;    
            }
            for(int k = 0; k < n; ++k)
                nums1[m + k] = nums2[k];

        }

    }
};

