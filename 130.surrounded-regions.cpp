/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */
class Solution {
public:
    void func(vector<vector<char>>& board, int i, int j){
        if(i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != 'O')
            return ;
        
        board[i][j] = 'o';

        func(board, i - 1, j);
        func(board, i + 1, j);
        func(board, i, j - 1);
        func(board, i, j + 1);
    }
    void solve(vector<vector<char>>& board) {
        //沿边缘寻找O,以及其连接着的O,其他都是X
        if(board.empty() || board[0].empty())
            return ;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            func(board, i, 0);
            func(board, i, n - 1);
        }
        for(int j = 0; j < n; ++j){
            func(board, 0, j);
            func(board, m - 1, j);
        }
        for(int i = 0;i < m; ++i)
            for(int j = 0;j < n; ++j)
                if(board[i][j] == 'o')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
    }
};
