/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.13%)
 * Total Accepted:    548.5K
 * Total Submissions: 1.5M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
//未考虑第一个字符为]})的情况，此时栈空无top
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            else if(s[i] == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return 0;
            }
            else if(s[i] == ']'){
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return 0;
            }
            else if(s[i] == '}'){
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return 0;
            }
        }
        return st.empty();
    }
};

