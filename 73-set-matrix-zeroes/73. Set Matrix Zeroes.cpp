class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> cols;
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); ++j) {
                if(matrix[i][j] == 0) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        for(int i=0; i<rows.size(); i++) {
            matrix[rows[i]].assign(matrix[0].size(), 0);
        }
        for(int i=0; i<cols.size(); i++) {
            for(vector<int>& row : matrix) {
                row[cols[i]] = 0;
            }
        }
    }
};