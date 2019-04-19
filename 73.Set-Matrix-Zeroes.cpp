class Solution {
public:
    /*
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return ;
        int m = matrix.size();
        int n = matrix[0].size();
        int f = 0;
        set<int> row;
        for(int i = 0; i < m ; ++i){
            f = 0;
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    f = 1;
                    row.insert(j);
                }
            }
            if(f)
                matrix[i] = vector<int>(n, 0);
        }
            

        for(set<int>::iterator j = row.begin(); j != row.end(); ++j){
            for(int i = 0; i < m; ++i)
                matrix[i][*j] = 0;
        }
    }*/
    
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return ;
        int m = matrix.size();
        int n = matrix[0].size();
        bool isZeroRow = false, isZeroCol = false; 
        for(int i = 0; i < m; ++i)
            if(matrix[i][0] == 0){
                isZeroCol = true;
                break;
            }
         for(int i = 0; i < n; ++i)
            if(matrix[0][i] == 0){
                isZeroRow = true;
                break;
            }

                
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
        
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] =0;
        
        if (isZeroCol) { //handle the first column
            for (int i = 0; i < matrix.size(); i++) 
                matrix[i][0] = 0;
        }
        if (isZeroRow) { //handle the first row
            for (int i = 0; i < matrix[0].size(); i++) 
                matrix[0][i] = 0;
        }
         
    }
};