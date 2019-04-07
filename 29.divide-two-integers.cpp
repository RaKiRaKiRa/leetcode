/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.14%)
 * Total Accepted:    187.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */
//不用 * / % 做32位除法.
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == INT_MIN || dividend == 0)
            return 0;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if(divisor == 1)
            return dividend;
        int flag = (dividend > 0) ^ (divisor > 0);
            
        unsigned int dvd = (dividend < 0) ? ~dividend + 1 : dividend;
        unsigned int dvs = (divisor < 0) ? ~divisor + 1 : divisor;

        int res = 0, cur_d = dvs, cur_a = 1;

        while(dvd >= dvs){
            if(dvd >= cur_d){
                res += cur_a;
                dvd -= cur_d;
                cur_a <<= 1;
                cur_d <<= 1;
            }
            else{
                cur_a = 1;
                cur_d = dvs;
                res += cur_a;
                dvd -= cur_d;
            }
        } 
       
        return res * flag;
    }
};

