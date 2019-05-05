/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
class Solution {
public:
/*
    bool func(string &s, int beg, unordered_map<int, vector<string> > &mp){
        if(beg >= s.size()) return true;
        string str;
        vector<string> * v;
        for(int i = beg; i < s.size(); ++i){
            str.append(s, i, 1);
            if(mp.find(i - beg + 1) != mp.end()){
                v = &mp[i - beg + 1];
                if(find(v -> begin(), v -> end(), str) != v -> end())
                    if(func(s, i + 1, mp))
                        return true;
            } 
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string> > mp;
        for(string &str : wordDict){
            mp[str.size()].push_back(str);
        }
        return func(s, 0, mp);
    }
*/
    bool wordBreak(string s, vector<string>& wordDict) {
        int sz = s.size();
        if(sz == 0) return false;
        vector<bool> dp(sz + 1, false);//dp[n]表示s[0 ~ n-1]是否可分
        dp[0] = true;
        string str;
        for(int i = 1; i <= sz; ++i){
            for(int j = i - 1; j >= 0 ; --j){
                if(dp[j]){
                    str = s.substr(j, i - j);//i - 1 - j + 1
                    if(find(wordDict.begin(), wordDict.end(), str) != wordDict.end()){
                        dp[i] = true;
                        break;
                    }
                        
                }
            }
        }
        return dp[sz];
    }
};

