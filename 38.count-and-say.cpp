/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (39.87%)
 * Total Accepted:    270.3K
 * Total Submissions: 676.2K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
class Solution {
public:
    string countAndSay(int n) {
        string last;
        string cur = "1";
        while(--n){
            last = cur;
            cur = "";
            int cnt = 1;
            char c = last[0];
            for(int i = 1;i < last.size(); ++i){
                if(last[i] == c)
                    ++cnt;
                else{
                    cur += (char)('0'+cnt);
                    cur += c;
                    cnt = 1;
                    c = last[i];
                }
            }
            cur += (char)('0'+cnt);
            cur += c;
        }
        return cur;
    }
};

