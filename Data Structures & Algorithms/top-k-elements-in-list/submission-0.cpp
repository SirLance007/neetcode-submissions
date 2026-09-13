class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i = 0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int, int>> freq;
        for(auto pair : mp){
            freq.push_back({pair.second , pair.first});
        }
        sort(freq.begin(),freq.end(),greater<>());
        vector<int> ans;
        for(int i = 0; i < k ; i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};
