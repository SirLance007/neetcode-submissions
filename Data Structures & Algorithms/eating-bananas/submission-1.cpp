class Solution {
private:
    int solve(vector<int> &piles , int k){
        int total = 0;
        for(int i = 0; i < piles.size() ; i++){
            if(piles[i]%k == 0){
                total += piles[i]/k;
            }
            else{
                total += piles[i]/k+1;
            }
        }
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin() , piles.end());
        int ans = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            int val = solve(piles , mid);
            cout << val << endl;
            if(solve(piles , mid) <= h){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};
