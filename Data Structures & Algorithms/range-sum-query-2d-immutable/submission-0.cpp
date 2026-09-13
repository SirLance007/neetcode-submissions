class NumMatrix {
public:
    int n;
    int m;
    vector<vector<int>> matrixx;

    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        matrixx = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        vector<vector<int>> prefix_row(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            prefix_row[i][0] = matrixx[i][0];

            for (int j = 1; j < m; j++) {
                prefix_row[i][j] = matrixx[i][j] + prefix_row[i][j - 1];
            }
        }

        int total = 0;

        for (int i = row1; i <= row2; i++) {
            if (col1 == 0) {
                total += prefix_row[i][col2];
            } else {
                total += prefix_row[i][col2] - prefix_row[i][col1 - 1];
            }
        }

        return total;
    }
};