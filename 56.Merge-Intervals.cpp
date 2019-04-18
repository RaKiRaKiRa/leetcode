class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& l,const vector<int>& r){return l[0] < r[0];});
        vector<vector<int>> res;
        vector<int> cur = intervals[0];
        for(int i = 1;i < intervals.size(); ++i){
            if(cur[1] >= intervals[i][0])
                cur[1] = max(cur[1], intervals[i][1]);
            else{
                res.push_back(cur);
                cur = intervals[i];
            }    
        }
        res.push_back(cur);
        return res;
    }
};