/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.empty())
        return 0;
    int sz = s.size(), res = 1;
    vector<int> dp(sz, 1);
    for(int i = 1; i < sz; ++i){
        int tmp = 1;
        for(int j = i - 1; j >= i - dp[i - 1]; --j)
            if(s[i] != s[j])
                ++tmp;
            else
                break;
        dp[i] = tmp;
        if(dp[i] > res)
            res = dp[i];      
    }
    return res;
}