class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // Brute force would be to apply bfs for every node 
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> vis(n , vector<int> (m , 0));
        queue<pair<int , int>> pq;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 0){
                    pq.push({i , j});
                }
            }
        }
        int delRow [] = {-1 , 0 , 1 , 0};
        int delCol [] = {0 , -1 , 0 , 1};
        while(!pq.empty()){
            int row = pq.front().first;
            int col = pq.front().second;
            pq.pop();
            for(int j = 0; j < 4 ; j++){
                int newRow = delRow[j] + row;
                int newCol = delCol[j] + col;
                if( newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 2147483647 ){
                    grid[newRow][newCol] = grid[row][col] + 1;
                    pq.push({newRow , newCol});
                    // vis[newRow][newCol] = 1;
                }
            }
        }
    }
};
