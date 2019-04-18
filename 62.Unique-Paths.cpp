class Solution {
public:
   
    /*int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        dp[1][1] = 1;
        for(int i = 1;i <= m; ++i)
            for(int j = 1;j <= n; ++j)
                if(i == 1 && j == 1)
                    continue;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }*/
    int uniquePaths(int m, int n) {
        vector<int> last(n + 1, 0), cur(n + 1, 0), tmp(n + 1, 0);
        last[1] = 1;
        for(int i = 1;i <= m; ++i){
            for(int j = 1;j <= n; ++j)
                cur[j] = last[j] + cur[j - 1];
            last = cur;
            cur = tmp;
        }     
        return last[n];
    }
};