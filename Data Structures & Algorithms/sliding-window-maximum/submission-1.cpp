class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        int left = 0;
        int right = 0;
        unordered_map<int , int> mp;
        while(right < n){
            mp[nums[right]]++;
            int maxi = INT_MIN;
            for(auto it : mp){
                maxi = max(maxi , it.first);
            }
            if(right - left + 1 == k){
                ans.push_back(maxi);
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};
