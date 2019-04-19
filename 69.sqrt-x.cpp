/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (30.93%)
 * Total Accepted:    352.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        int r = x - 1, l = 1;
        while( 1 ){
            int mid = l + (r - l) / 2;
            if(mid > x / mid)
                r = mid - 1;
            else {
                if(mid + 1 > x / (mid + 1))
                    return mid;
                l = mid + 1;
            }  
        }
        return l;  
    }
};

