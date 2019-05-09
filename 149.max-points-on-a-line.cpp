/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        int sz = points.size();
        for(int i = 0; i < sz; ++i){
            map< pair<int, int>, int> record;
            int same = 1, tmp = 0;
            for(int j = i + 1; j < sz; ++j){
                if(points[i] == points[j])
                    ++same;
                else{
                    int x = points[i][0] - points[j][0], y = points[i][1] - points[j][1];
                    int g = gcd(x, y);
                    x /= g;
                    y /= g;
                    
                    if(tmp < ++record[make_pair(x, y)])
                        tmp = record[make_pair(x, y)];
                }
            }
            res = max(res, tmp + same );//除去i一条线最多tmp个点,i点处有same 个点
        }
        return res;
    }
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
};

