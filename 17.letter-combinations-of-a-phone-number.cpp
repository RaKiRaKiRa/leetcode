/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (40.84%)
 * Total Accepted:    364.5K
 * Total Submissions: 891.6K
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
class Solution {
public:

    void fun(string &digits, unordered_map<char, vector<char>* > &m, int n, int sz, string &str, vector<string> &res){
        if( n == sz ){
            res.push_back(str);
            return ;
        }
        vector<char> mm = *m[digits[n++]];
        for(int i = 0; i < mm.size(); ++i){
            str.append(1,mm[i]);
            fun(digits, m, n, sz, str, res);
            str.pop_back();
        }
            
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return vector<string>();
        unordered_map<char, vector<char>* > m;
        vector<string> res;
        m['2'] = new vector<char>({'a', 'b','c'});
        m['3'] = new vector<char>({'d', 'e','f'});
        m['4'] = new vector<char>({'g', 'h','i'});
        m['5'] = new vector<char>({'j', 'k','l'});
        m['6'] = new vector<char>({'m', 'n','o'});
        m['7'] = new vector<char>({'p', 'q','r','s'});
        m['8'] = new vector<char>({'t', 'u','v'});
        m['9'] = new vector<char>({'w', 'x','y','z'});
        int sz = digits.size();
        string str = string();
        fun(digits, m, 0, sz, str, res);
        return res;

    }
};

