/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return vector<vector<int>>();

        vector<vector<int>> res;
        vector<int> cur;
        
        for(int i = 1; i <= numRows; ++i){
            if(i == 1)
                res.push_back({1});
            else if(i == 2)
                res.push_back({1, 1});
            else{
                cur.push_back(1);
                for(int j = 1; j < i - 1; ++j)
                    cur.push_back(res[i - 2][j] + res[i - 2][j - 1]);
                cur.push_back(1);
                res.push_back(cur);
                cur.clear();
            }
        }
        return res;
    }
};

