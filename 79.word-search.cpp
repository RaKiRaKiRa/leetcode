/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (30.69%)
 * Total Accepted:    269.9K
 * Total Submissions: 872.9K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool func(vector<vector<char>>& board, string &word, int i, int j, int n){
        if(word[n] != board[i][j]) return false;
        if(n == word.size() - 1) return true;
        char ch = board[i][j];
        board[i][j] = '*';
        bool res = false;

        if(i > 0) 
            res = func(board, word, i - 1, j, n + 1);
        if(!res && j > 0) 
            res = func(board, word, i, j - 1, n + 1);
        if(!res && i < board.size() - 1 ) 
            res = func(board, word, i + 1, j, n + 1);
        if(!res && j < board[0].size() - 1) 
            res = func(board, word, i, j + 1, n + 1);
            
        board[i][j] = ch;
        return res;
    }


    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();

        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                if(func(board, word, i, j, 0)) return true;
            
        return false;        
    }
};

