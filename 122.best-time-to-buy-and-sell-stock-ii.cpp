/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, sz = prices.size(), res = 0;
        int min = INT_MAX, max = INT_MIN, tmp;
        while(i + 1 < sz){
            while(i + 1 < sz && prices[i] >= prices[i + 1] )
                ++i;
            min = prices[i];
            while(i + 1 < sz && prices[i] <= prices[i + 1])
                ++i;
            max = prices[i];
            tmp = max - min;
            if(tmp > 0)
                res += tmp;
        }
        return res;
    }
};

