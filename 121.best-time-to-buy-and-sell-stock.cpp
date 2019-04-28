/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int min = INT_MAX, max = 0, tmp;
        for(int i = 0; i < prices.size(); ++i)
            if(prices[i] < min){
                min = prices[i];
            }
            else{
                tmp = prices[i] - min;
                if(tmp > max)
                    max = tmp;
            }
        return max;
    }
};

