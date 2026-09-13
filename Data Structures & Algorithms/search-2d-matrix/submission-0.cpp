class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                ans.push_back(matrix[i][j]);
            }
        }
        sort(ans.begin() , ans.end());
        int left = 0;
        int right = ans.size()-1;
        while(left <= right){
            int mid = left+ (right-left)/2;
            if(ans[mid] == target){
                return true;
            }else if(ans[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return false;
    }
};
